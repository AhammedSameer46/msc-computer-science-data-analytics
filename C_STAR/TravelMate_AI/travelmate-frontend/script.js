const chatEl = document.getElementById("chat");
const form = document.getElementById("composer");
const input = document.getElementById("input");

let sessionId = null;

async function initSession() {
  try {
    const res = await fetch("/api/session", { method: "POST" });
    const data = await res.json();
    sessionId = data.session_id;
  } catch (err) {
    addError("Couldn't reach the server. Is app.py running?");
  }
}

function scrollToBottom() {
  window.scrollTo({ top: document.body.scrollHeight, behavior: "smooth" });
}

function addBubble(text, who) {
  const row = document.createElement("div");
  row.className = `msg msg-${who}`;
  const bubble = document.createElement("div");
  bubble.className = "bubble";
  bubble.textContent = text;
  row.appendChild(bubble);
  chatEl.appendChild(row);
  scrollToBottom();
  return row;
}

function addTyping() {
  const row = document.createElement("div");
  row.className = "msg msg-bot typing";
  row.innerHTML = `<div class="bubble"><span class="dot"></span><span class="dot"></span><span class="dot"></span></div>`;
  chatEl.appendChild(row);
  scrollToBottom();
  return row;
}

function addError(text) {
  const p = document.createElement("div");
  p.className = "error-note";
  p.textContent = text;
  chatEl.appendChild(p);
  scrollToBottom();
}

function row(label, value) {
  return `<div class="row"><span class="label">${label}</span><span>${value}</span></div>`;
}

function renderCard(card) {
  const wrap = document.createElement("div");
  wrap.className = "msg msg-bot";

  const ticket = document.createElement("div");
  ticket.className = "ticket";

  let mainHtml = "";
  let kindLabel = "";

  switch (card.kind) {
    case "weather":
      kindLabel = "Weather";
      mainHtml = `
        <div class="ticket-eyebrow">Conditions</div>
        <div class="ticket-city">${card.city}</div>
        <div class="ticket-rows">
          ${row("Temp", card.temperature)}
          ${row("Sky", card.condition)}
          ${row("Humidity", card.humidity)}
        </div>`;
      break;
    case "flight":
      kindLabel = "Flight";
      mainHtml = `
        <div class="ticket-eyebrow">Boarding pass</div>
        <div class="ticket-city">${card.city}</div>
        <div class="ticket-rows">
          ${row("Airline", card.airline)}
          ${row("Fare", card.price)}
          ${row("Duration", card.duration)}
        </div>`;
      break;
    case "hotels":
      kindLabel = "Hotels";
      mainHtml = `
        <div class="ticket-eyebrow">Stays</div>
        <div class="ticket-city">${card.city}</div>
        <div class="ticket-rows">
          ${card.hotels
            .map((h) => row(h.name, `⭐ ${h.rating} · ${h.price}`))
            .join("")}
        </div>`;
      break;
    case "attractions":
      kindLabel = "Sights";
      mainHtml = `
        <div class="ticket-eyebrow">Do & see</div>
        <div class="ticket-city">${card.city}</div>
        <ul class="ticket-list">
          ${card.attractions.map((a) => `<li>${a}</li>`).join("")}
        </ul>`;
      break;
    default:
      kindLabel = "Info";
      mainHtml = `<div class="ticket-city">${card.city || ""}</div>`;
  }

  ticket.innerHTML = `
    <div class="ticket-main">${mainHtml}</div>
    <div class="ticket-stub">
      <div class="ticket-code">${card.code || "—"}</div>
      <div class="ticket-kind">${kindLabel}</div>
    </div>
  `;

  wrap.appendChild(ticket);
  chatEl.appendChild(wrap);
  scrollToBottom();
}

async function sendMessage(text) {
  addBubble(text, "user");
  const typingRow = addTyping();

  try {
    const res = await fetch("/api/chat", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ session_id: sessionId, message: text }),
    });
    const data = await res.json();
    typingRow.remove();

    if (data.error) {
      addError(data.error);
      return;
    }

    (data.cards || []).forEach(renderCard);
    if (data.reply) addBubble(data.reply, "bot");
  } catch (err) {
    typingRow.remove();
    addError("Something went wrong reaching TravelMate AI.");
  }
}

form.addEventListener("submit", (e) => {
  e.preventDefault();
  const text = input.value.trim();
  if (!text) return;
  input.value = "";
  sendMessage(text);
});

initSession();
