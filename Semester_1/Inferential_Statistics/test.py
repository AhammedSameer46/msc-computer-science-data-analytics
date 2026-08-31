import pygame
import sys
import random
import math
from pygame.math import Vector2

# --- CONFIGURATION ---
WIDTH, HEIGHT = 1024, 768
FPS = 144

# Colors
BG_COLOR = (12, 12, 20)
PLAYER_COLOR = (0, 255, 200)
ENEMY_COLOR = (255, 50, 80)
BULLET_COLOR = (255, 255, 0)
PARTICLE_COLORS = [(255, 150, 0), (255, 50, 50), (200, 200, 200)]

class Camera:
    """Handles screen shake and rendering offsets."""
    def __init__(self):
        self.offset = Vector2(0, 0)
        self.shake_time = 0
        self.intensity = 0

    def shake(self, duration: float, intensity: float):
        self.shake_time = duration
        self.intensity = intensity

    def update(self, dt: float):
        if self.shake_time > 0:
            self.shake_time -= dt
            self.offset = Vector2(
                random.uniform(-self.intensity, self.intensity),
                random.uniform(-self.intensity, self.intensity)
            )
        else:
            self.offset = Vector2(0, 0)

class Particle:
    """Fading, shrinking particle for explosion VFX."""
    def __init__(self, pos: Vector2, color: tuple):
        self.pos = Vector2(pos)
        angle = random.uniform(0, math.pi * 2)
        speed = random.uniform(50, 300)
        self.vel = Vector2(math.cos(angle), math.sin(angle)) * speed
        self.color = color
        self.lifetime = random.uniform(0.2, 0.6)
        self.radius = random.uniform(2, 5)

    def update(self, dt: float) -> bool:
        self.pos += self.vel * dt
        self.lifetime -= dt
        self.radius = max(0, self.radius - (dt * 5))
        return self.lifetime <= 0

    def draw(self, surface: pygame.Surface, offset: Vector2):
        if self.radius > 0:
            pygame.draw.circle(surface, self.color, self.pos + offset, int(self.radius))

class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.original_image = pygame.Surface((30, 30), pygame.SRCALPHA)
        pygame.draw.polygon(self.original_image, PLAYER_COLOR, [(15, 0), (0, 30), (15, 24), (30, 30)])
        self.image = self.original_image
        self.rect = self.image.get_rect(center=(WIDTH // 2, HEIGHT // 2))
        
        self.pos = Vector2(self.rect.center)
        self.vel = Vector2(0, 0)
        self.speed = 400
        self.friction = 8
        self.shoot_cooldown = 0

    def update(self, dt: float, mouse_pos: tuple):
        # Input handling & Movement
        keys = pygame.key.get_pressed()
        dir_vec = Vector2(0, 0)
        if keys[pygame.K_w]: dir_vec.y -= 1
        if keys[pygame.K_s]: dir_vec.y += 1
        if keys[pygame.K_a]: dir_vec.x -= 1
        if keys[pygame.K_d]: dir_vec.x += 1

        if dir_vec.length_squared() > 0:
            dir_vec = dir_vec.normalize()
        
        # Apply velocity and friction
        self.vel += dir_vec * self.speed * dt
        self.vel -= self.vel * self.friction * dt
        self.pos += self.vel * dt
        
        # Screen bounds
        self.pos.x = max(15, min(WIDTH - 15, self.pos.x))
        self.pos.y = max(15, min(HEIGHT - 15, self.pos.y))

        # Rotation towards mouse
        mouse_vec = Vector2(mouse_pos)
        direction = mouse_vec - self.pos
        angle = math.degrees(math.atan2(-direction.y, direction.x)) - 90
        
        self.image = pygame.transform.rotate(self.original_image, angle)
        self.rect = self.image.get_rect(center=self.pos)
        self.shoot_cooldown = max(0, self.shoot_cooldown - dt)

class Bullet(pygame.sprite.Sprite):
    def __init__(self, pos: Vector2, target: tuple):
        super().__init__()
        self.image = pygame.Surface((6, 15), pygame.SRCALPHA)
        self.image.fill(BULLET_COLOR)
        self.rect = self.image.get_rect(center=pos)
        self.pos = Vector2(pos)
        
        direction = Vector2(target) - self.pos
        self.vel = direction.normalize() * 1200 if direction.length_squared() > 0 else Vector2(0, -1200)
        
        # Rotate bullet to face travel direction
        angle = math.degrees(math.atan2(-self.vel.y, self.vel.x)) - 90
        self.image = pygame.transform.rotate(self.image, angle)
        self.rect = self.image.get_rect(center=self.pos)

    def update(self, dt: float):
        self.pos += self.vel * dt
        self.rect.center = self.pos
        if not (0 <= self.pos.x <= WIDTH and 0 <= self.pos.y <= HEIGHT):
            self.kill()

class Enemy(pygame.sprite.Sprite):
    def __init__(self, target: Player):
        super().__init__()
        self.image = pygame.Surface((25, 25), pygame.SRCALPHA)
        pygame.draw.circle(self.image, ENEMY_COLOR, (12, 12), 12)
        
        # Spawn outside screen
        edge = random.choice(['top', 'bottom', 'left', 'right'])
        if edge == 'top': self.pos = Vector2(random.randint(0, WIDTH), -30)
        elif edge == 'bottom': self.pos = Vector2(random.randint(0, WIDTH), HEIGHT + 30)
        elif edge == 'left': self.pos = Vector2(-30, random.randint(0, HEIGHT))
        else: self.pos = Vector2(WIDTH + 30, random.randint(0, HEIGHT))

        self.rect = self.image.get_rect(center=self.pos)
        self.target = target
        self.speed = random.uniform(100, 250)

    def update(self, dt: float):
        direction = self.target.pos - self.pos
        if direction.length_squared() > 0:
            self.pos += direction.normalize() * self.speed * dt
        self.rect.center = self.pos

class Game:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((WIDTH, HEIGHT))
        pygame.display.set_caption("Master Level Pygame - Twin Stick Shooter")
        self.clock = pygame.time.Clock()
        self.font = pygame.font.SysFont("Arial", 36, bold=True)
        self.reset_game()

    def reset_game(self):
        self.state = "PLAY"
        self.camera = Camera()
        self.player = Player()
        self.all_sprites = pygame.sprite.Group(self.player)
        self.bullets = pygame.sprite.Group()
        self.enemies = pygame.sprite.Group()
        self.particles = []
        self.score = 0
        self.enemy_spawn_timer = 0
        self.spawn_rate = 1.0

    def spawn_particles(self, pos: Vector2, count: int):
        for _ in range(count):
            self.particles.append(Particle(pos, random.choice(PARTICLE_COLORS)))

    def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                if self.state == "GAME_OVER":
                    self.reset_game()

        # Continuous shooting
        if self.state == "PLAY" and pygame.mouse.get_pressed()[0] and self.player.shoot_cooldown <= 0:
            bullet = Bullet(self.player.pos, pygame.mouse.get_pos())
            self.all_sprites.add(bullet)
            self.bullets.add(bullet)
            self.player.shoot_cooldown = 0.1 # 100ms firing rate
            self.camera.shake(0.05, 3) # Micro-shake on shoot

    def update(self, dt: float):
        if self.state != "PLAY":
            return

        self.camera.update(dt)
        self.player.update(dt, pygame.mouse.get_pos())
        self.bullets.update(dt)
        self.enemies.update(dt)

        # Particle lifecycle
        self.particles = [p for p in self.particles if not p.update(dt)]

        # Enemy Spawning (accelerates over time)
        self.enemy_spawn_timer -= dt
        if self.enemy_spawn_timer <= 0:
            enemy = Enemy(self.player)
            self.all_sprites.add(enemy)
            self.enemies.add(enemy)
            self.spawn_rate = max(0.2, self.spawn_rate - 0.02)
            self.enemy_spawn_timer = self.spawn_rate

        # Collisions: Bullet hits Enemy
        hits = pygame.sprite.groupcollide(self.enemies, self.bullets, True, True)
        for enemy in hits:
            self.score += 10
            self.spawn_particles(enemy.pos, 15)
            self.camera.shake(0.15, 8)

        # Collisions: Enemy hits Player
        if pygame.sprite.spritecollideany(self.player, self.enemies):
            self.spawn_particles(self.player.pos, 50)
            self.camera.shake(0.4, 20)
            self.player.kill()
            self.state = "GAME_OVER"

    def draw(self):
        self.screen.fill(BG_COLOR)
        
        # Draw Sprites with Camera Offset
        for sprite in self.all_sprites:
            rect = sprite.rect.copy()
            rect.centerx += int(self.camera.offset.x)
            centery = rect.centery + int(self.camera.offset.y)
            rect.centery = centery
            self.screen.blit(sprite.image, rect)

        # Draw Particles
        for particle in self.particles:
            particle.draw(self.screen, self.camera.offset)

        # UI
        if self.state == "PLAY":
            score_surf = self.font.render(f"SCORE: {self.score}", True, WHITE)
            self.screen.blit(score_surf, (20, 20))
        elif self.state == "GAME_OVER":
            go_surf = self.font.render("GAME OVER - CLICK TO RESTART", True, (255, 100, 100))
            rect = go_surf.get_rect(center=(WIDTH // 2, HEIGHT // 2))
            self.screen.blit(go_surf, rect)

        pygame.display.flip()

    def run(self):
        while True:
            # Framerate independence calculation
            dt = self.clock.tick(FPS) / 1000.0
            self.handle_events()
            self.update(dt)
            self.draw()

if __name__ == "__main__":
    Game().run()