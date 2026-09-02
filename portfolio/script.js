/**
 * PORTFOLIO ARCHITECTURE - VANILLA JS
 * Modular functions for Projects, Cursor, 3D, and GSAP Animations.
 */

// 1. DATA: CENTRALIZED PROJECT CONFIGURATION
const projectsData = [
    {
        id: "01",
        title: "AI-POWERED E-COMMERCE<br>CUSTOMER INTELLIGENCE",
        description: "An end-to-end machine learning system that segments e-commerce customers using purchasing behavior and predicts customer segments for marketing and retention strategies.",
        stack: ["PYTHON", "PANDAS", "SCIKIT-LEARN", "MACHINE LEARNING", "RFM ANALYTICS"],
        image: "assets/project-01.jpg"
    },
    {
        id: "02",
        title: "NEXUS LOGISTICS",
        description: "Real-time logistics and fleet intelligence platform architected for high-frequency geolocation updates.",
        stack: ["LARAVEL", "VUE", "REDIS", "WEBSOCKETS", "MYSQL"],
        image: "assets/project-02.jpg"
    },
    {
        id: "03",
        title: "AETHER FINANCIAL",
        description: "Secure, transactional banking operations system with strict ACID compliance and automated ledger auditing.",
        stack: ["JAVA", "SPRING BOOT", "POSTGRESQL", "DOCKER", "AWS"],
        image: "assets/project-03.jpg"
    },
    {
        id: "04",
        title: "OMNI CONNECT",
        description: "High-scale hybrid consumer mobile ecosystem featuring low-latency messaging and API load balancing.",
        stack: ["NODE.JS", "REACT NATIVE", "GRAPHQL", "KAFKA"],
        image: "assets/project-04.jpg"
    }
];

// Placeholder fallback for project images
const placeholderImage = "data:image/svg+xml;charset=UTF-8,%3Csvg xmlns='http://www.w3.org/2000/svg' width='1200' height='800' background='%23eeeeee'%3E%3Crect width='100%25' height='100%25' fill='%23eeeeee'/%3E%3Ctext x='50%25' y='50%25' dominant-baseline='middle' text-anchor='middle' font-family='sans-serif' font-size='24' fill='%23999'%3EPROJECT IMAGE PLACEHOLDER%3C/text%3E%3C/svg%3E";

// 2. RENDER PROJECTS
function renderProjects() {
    const container = document.getElementById("work-container");
    if (!container) return;

    let html = "";
    projectsData.forEach(p => {
        const stackHtml = p.stack.map(tech => `<span class="meta">${tech}</span>`).join("");
        
        html += `
        <div class="project-wrap">
            <div class="project-info">
                <span class="meta">${p.id}</span>
                <div>
                    <h3 class="project-title">${p.title}</h3>
                    <p class="project-desc">${p.description}</p>
                </div>
                <div class="project-tech">
                    ${stackHtml}
                </div>
            </div>
            <div class="project-image-container" data-cursor="view">
                <img src="${p.image}" alt="${p.title.replace('<br>',' ')}" onerror="this.src='${placeholderImage}'" class="project-img">
            </div>
        </div>
        `;
    });
    
    container.innerHTML = html;
}

// 3. CUSTOM CURSOR
function initCursor() {
    // Respect reduced motion / touch devices
    if (window.matchMedia("(hover: none) and (pointer: coarse)").matches) return;

    const cursor = document.getElementById("cursor");
    if (!cursor) return;

    let mouseX = 0, mouseY = 0;
    let cursorX = 0, cursorY = 0;

    // Follow mouse
    window.addEventListener("mousemove", (e) => {
        mouseX = e.clientX;
        mouseY = e.clientY;
    });

    // Smooth lerp function
    const render = () => {
        cursorX += (mouseX - cursorX) * 0.2;
        cursorY += (mouseY - cursorY) * 0.2;
        cursor.style.transform = `translate(${cursorX}px, ${cursorY}px)`;
        requestAnimationFrame(render);
    };
    requestAnimationFrame(render);

    // Hover states logic
    const applyHover = () => {
        document.querySelectorAll("[data-hover]").forEach(el => {
            el.addEventListener("mouseenter", () => cursor.classList.add("hover"));
            el.addEventListener("mouseleave", () => cursor.classList.remove("hover"));
        });

        document.querySelectorAll("[data-cursor='view']").forEach(el => {
            el.addEventListener("mouseenter", () => cursor.classList.add("view"));
            el.addEventListener("mouseleave", () => cursor.classList.remove("view"));
        });
    };

    // Apply initially and after projects load
    applyHover();
    setTimeout(applyHover, 500); 
}

// 4. THREE.JS 3D BACKGROUND (Minimal Wireframe)
function initThreeJS() {
    // Respect reduced motion
    if (window.matchMedia("(prefers-reduced-motion: reduce)").matches) return;

    const canvas = document.getElementById("webgl-canvas");
    if (!canvas) return;

    const scene = new THREE.Scene();
    const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
    const renderer = new THREE.WebGLRenderer({ canvas: canvas, alpha: true, antialias: true });
    
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));

    // Abstract geometric wireframe structure
    const geometry = new THREE.IcosahedronGeometry(10, 1);
    const material = new THREE.MeshBasicMaterial({ 
        color: 0x000000, 
        wireframe: true,
        transparent: true,
        opacity: 0.03 // Extremely subtle
    });
    
    const wireframe = new THREE.Mesh(geometry, material);
    scene.add(wireframe);
    
    camera.position.z = 25;

    // Subtle mouse interaction
    let mouseX = 0;
    let mouseY = 0;
    
    window.addEventListener("mousemove", (e) => {
        mouseX = (e.clientX / window.innerWidth) * 2 - 1;
        mouseY = -(e.clientY / window.innerHeight) * 2 + 1;
    });

    const animate = () => {
        requestAnimationFrame(animate);
        
        // Slow constant rotation
        wireframe.rotation.x += 0.001;
        wireframe.rotation.y += 0.002;
        
        // React to mouse
        wireframe.rotation.x += mouseY * 0.01;
        wireframe.rotation.y += mouseX * 0.01;
        
        renderer.render(scene, camera);
    };
    
    animate();

    // Handle Resize
    window.addEventListener("resize", () => {
        camera.aspect = window.innerWidth / window.innerHeight;
        camera.updateProjectionMatrix();
        renderer.setSize(window.innerWidth, window.innerHeight);
    });
}

// 5. GSAP SCROLL ANIMATIONS
function initGSAP() {
    // Ensure GSAP and ScrollTrigger are loaded
    if (typeof gsap === "undefined" || typeof ScrollTrigger === "undefined") return;
    
    gsap.registerPlugin(ScrollTrigger);

    // Initial Page Load Animation
    const tl = gsap.timeline();
    tl.fromTo(".load-anim", 
        { y: 50, opacity: 0, clipPath: "polygon(0 0, 100% 0, 100% 0, 0 0)" },
        { y: 0, opacity: 1, clipPath: "polygon(0 0, 100% 0, 100% 100%, 0% 100%)", duration: 1.2, stagger: 0.2, ease: "power4.out" }
    );

    // Editorial Statement Reveal
    gsap.to(".editorial-text .word", {
        scrollTrigger: {
            trigger: ".editorial",
            start: "top 75%",
        },
        y: 0,
        duration: 1,
        stagger: 0.05,
        ease: "power3.out"
    });

    // Project Parallax & Reveal
    const projects = document.querySelectorAll(".project-wrap");
    projects.forEach(project => {
        const img = project.querySelector("img");
        
        // Image Parallax
        gsap.to(img, {
            yPercent: 15,
            ease: "none",
            scrollTrigger: {
                trigger: project,
                start: "top bottom",
                end: "bottom top",
                scrub: true
            }
        });

        // Project Fade In
        gsap.fromTo(project, 
            { opacity: 0, y: 50 },
            { 
                opacity: 1, y: 0, 
                duration: 1, ease: "power2.out",
                scrollTrigger: {
                    trigger: project,
                    start: "top 85%"
                }
            }
        );
    });

    // Systems Thinking Flow Animation
    const flowItems = document.querySelectorAll(".flow-item, .flow-arrow");
    gsap.to(flowItems, {
        opacity: 1,
        stagger: 0.1,
        scrollTrigger: {
            trigger: ".systems",
            start: "top 60%"
        }
    });

    // Statistics Counter
    const statNumbers = document.querySelectorAll(".stat-number");
    statNumbers.forEach(stat => {
        const target = parseInt(stat.getAttribute("data-target"));
        const suffix = stat.getAttribute("data-suffix") || "";
        
        gsap.to(stat, {
            innerHTML: target,
            duration: 2,
            snap: { innerHTML: 1 },
            ease: "power2.out",
            scrollTrigger: {
                trigger: ".stats",
                start: "top 80%"
            },
            onUpdate: function() {
                stat.innerHTML = Math.round(this.targets()[0].innerHTML) + suffix;
            }
        });
    });
}

// 6. INITIALIZATION
document.addEventListener("DOMContentLoaded", () => {
    renderProjects();
    initCursor();
    initThreeJS();
    
    // Give DOM a tiny moment to render structure before binding GSAP
    setTimeout(initGSAP, 100);
});