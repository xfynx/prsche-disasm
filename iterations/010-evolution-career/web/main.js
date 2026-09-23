import init, { create_viewer, shell_profile_new, shell_profile_buy_356, shell_apply_event_result, shell_get_first_evolution_event, shell_get_first_factory_event, shell_get_dealership_catalog, shell_get_used_cars, shell_get_parts_catalog, shell_get_tournament_cups, shell_buy_car, shell_sell_car, shell_buy_part, shell_repair_car } from "./package/viewer_impl.js";

const KNOWN_TRACKS = [
  { id: "skidpad", name: "Skidpad (Полигон)" },
  { id: "alps", name: "Alps (Альпы)" },
  { id: "autobahn", name: "Autobahn (Автобан)" },
  { id: "canyon", name: "Canyon (Каньон)" },
  { id: "castle", name: "Schwarzwald (Замок)" },
  { id: "coastal", name: "Côte d'Azur (Лазурный берег)" },
  { id: "farmland", name: "Normandie (Нормандия)" },
  { id: "foothills", name: "Pyrenees (Пиренеи)" },
  { id: "forest", name: "Black Forest (Шварцвальд)" },
  { id: "industrial", name: "Zone Industrielle (Промзона)" },
  { id: "monaco1", name: "Monte Carlo 1 (Монте-Карло 1)" },
  { id: "monaco2", name: "Monte Carlo 2 (Монте-Карло 2)" },
  { id: "monaco3", name: "Monte Carlo 3 (Монте-Карло 3)" },
  { id: "monaco4", name: "Monte Carlo 4 (Монте-Карло 4)" },
  { id: "monaco5", name: "Monte Carlo 5 (Монте-Карло 5)" },
];

const KNOWN_CARS = [
  { id: "356_1", name: "356 \"No. 1\" Roadster (1948)" },
  { id: "356a", name: "356 A 1600 Coupe (1956)" },
  { id: "356b", name: "356 B 2000 GS Carrera 2 (1960)" },
  { id: "550", name: "550 A Spyder (1956)" },
  { id: "901", name: "911 Coupe (901) (1964)" },
  { id: "914", name: "914/4 (1970)" },
  { id: "928", name: "928 (1978)" },
  { id: "930", name: "911 Turbo 3.3 (930) (1978)" },
  { id: "935", name: "935/78 \"Moby Dick\" (1978)" },
  { id: "944", name: "944 (1982)" },
  { id: "959", name: "959 (1987)" },
  { id: "964", name: "911 Carrera 2 (964) (1989)" },
  { id: "993", name: "911 Carrera (993) (1995)" },
  { id: "996", name: "911 Carrera (996) (1998)" },
  { id: "boxster", name: "Boxster (986) (1997)" },
  { id: "gt1", name: "911 GT1 Straßenversion (1998)" },
  { id: "gt2", name: "911 GT2 (993) (1996)" },
  { id: "gt3", name: "911 GT3 (996) (1999)" },
  { id: "cop356", name: "Полиция: 356" },
  { id: "cop356_german", name: "Polizei: 356" },
  { id: "cop930", name: "Полиция: 930 Turbo" },
  { id: "cop930_german", name: "Polizei: 930" },
  { id: "cop993", name: "Полиция: 993" },
  { id: "cop993_german", name: "Polizei: 993" },
];

const canvas = document.querySelector("#viewport");
const folderInput = document.querySelector("#folderInput");
const fileInput = document.querySelector("#fileInput");
const sourceBadge = document.querySelector("#sourceBadge");
const resetSourceButton = document.querySelector("#resetSourceButton");
const modeSelect = document.querySelector("#modeSelect");
const targetLabel = document.querySelector("#targetLabel");
const targetSelect = document.querySelector("#targetSelect");
const topologyField = document.querySelector("#topologyField");
const topologyCheckbox = document.querySelector("#topologyCheckbox");
const tourButton = document.querySelector("#tourButton");
const cameraButton = document.querySelector("#cameraButton");
const paintButton = document.querySelector("#paintButton");
const hud = document.querySelector("#hud");
const speedValue = document.querySelector("#speedValue");
const gearValue = document.querySelector("#gearValue");
const rpmBar = document.querySelector("#rpmBar");
const loadButton = document.querySelector("#loadButton");
const resetButton = document.querySelector("#resetButton");
const statusLine = document.querySelector("#status");
const summary = document.querySelector("#summary");
const menuButton = document.querySelector("#menuButton");
const hudButton = document.querySelector("#hudButton");
const detailsButton = document.querySelector("#detailsButton");
const raceHudTop = document.querySelector("#raceHudTop");
const racePos = document.querySelector("#racePos");
const raceTotalPos = document.querySelector("#raceTotalPos");
const raceLap = document.querySelector("#raceLap");
const raceTotalLaps = document.querySelector("#raceTotalLaps");
const raceLapTime = document.querySelector("#raceLapTime");
const raceBestLap = document.querySelector("#raceBestLap");
const countdownBanner = document.querySelector("#countdownBanner");
const countdownText = document.querySelector("#countdownText");
const wrongWayBanner = document.querySelector("#wrongWayBanner");
const raceResultsModal = document.querySelector("#raceResultsModal");
const resultsSubtitle = document.querySelector("#resultsSubtitle");
const resultsLapTime = document.querySelector("#resultsLapTime");
const resultsBestTime = document.querySelector("#resultsBestTime");
const raceRestartBtn = document.querySelector("#raceRestartBtn");

let menuVisible = true;
let hudVisible = true;
let lastPhase = 0;

function formatRaceTime(secs) {
  if (!Number.isFinite(secs) || secs <= 0) return "--:--.-";
  const mins = Math.floor(secs / 60);
  const remainingSecs = (secs % 60).toFixed(1);
  return `${String(mins).padStart(2, "0")}:${remainingSecs.padStart(4, "0")}`;
}

if (raceRestartBtn) {
  raceRestartBtn.addEventListener("click", () => {
    if (viewer) {
      viewer.restart_race();
      if (raceResultsModal) raceResultsModal.hidden = true;
      eventFinishedHandled = false;
      setStatus("Гонка перезапущена / старт на решётке.");
      queueFrame();
    }
  });
}

// --- WebAudio Synthesizer (009 Sound) ---
class SoundManager {
  constructor() {
    this.ctx = null;
    this.enabled = false;
    this.engineOsc = null;
    this.engineFilter = null;
    this.engineGain = null;
    this.skidNoise = null;
    this.skidFilter = null;
    this.skidGain = null;
  }

  toggle() {
    this.enabled = !this.enabled;
    if (this.enabled) {
      this.init();
    } else {
      this.stop();
    }
    return this.enabled;
  }

  init() {
    if (!this.ctx && typeof window !== "undefined" && (window.AudioContext || window.webkitAudioContext)) {
      try {
        const AudioCtx = window.AudioContext || window.webkitAudioContext;
        this.ctx = new AudioCtx();
      } catch {}
    }
    if (this.ctx && this.ctx.state === "suspended") {
      this.ctx.resume().catch(() => {});
    }
    if (this.ctx && !this.engineOsc) {
      try {
        this.engineOsc = this.ctx.createOscillator();
        this.engineOsc.type = "sawtooth";
        this.engineOsc.frequency.setValueAtTime(65, this.ctx.currentTime);

        this.engineFilter = this.ctx.createBiquadFilter();
        this.engineFilter.type = "lowpass";
        this.engineFilter.frequency.setValueAtTime(450, this.ctx.currentTime);

        this.engineGain = this.ctx.createGain();
        this.engineGain.gain.setValueAtTime(0.04, this.ctx.currentTime);

        this.engineOsc.connect(this.engineFilter);
        this.engineFilter.connect(this.engineGain);
        this.engineGain.connect(this.ctx.destination);
        this.engineOsc.start();

        const bufferSize = this.ctx.sampleRate * 2;
        const noiseBuffer = this.ctx.createBuffer(1, bufferSize, this.ctx.sampleRate);
        const output = noiseBuffer.getChannelData(0);
        for (let i = 0; i < bufferSize; i++) {
          output[i] = Math.random() * 2 - 1;
        }
        this.skidNoise = this.ctx.createBufferSource();
        this.skidNoise.buffer = noiseBuffer;
        this.skidNoise.loop = true;

        this.skidFilter = this.ctx.createBiquadFilter();
        this.skidFilter.type = "bandpass";
        this.skidFilter.frequency.setValueAtTime(900, this.ctx.currentTime);
        this.skidFilter.Q.setValueAtTime(1.5, this.ctx.currentTime);

        this.skidGain = this.ctx.createGain();
        this.skidGain.gain.setValueAtTime(0.0, this.ctx.currentTime);

        this.skidNoise.connect(this.skidFilter);
        this.skidFilter.connect(this.skidGain);
        this.skidGain.connect(this.ctx.destination);
        this.skidNoise.start();
      } catch {}
    }
  }

  stop() {
    if (this.engineGain && this.ctx) {
      try { this.engineGain.gain.setValueAtTime(0.0, this.ctx.currentTime); } catch {}
    }
    if (this.skidGain && this.ctx) {
      try { this.skidGain.gain.setValueAtTime(0.0, this.ctx.currentTime); } catch {}
    }
  }

  update(rpm, speed, handbrake) {
    if (!this.enabled || !this.ctx || !this.engineOsc) return;
    try {
      const targetFreq = 55 + rpm * 225;
      this.engineOsc.frequency.setTargetAtTime(targetFreq, this.ctx.currentTime, 0.05);
      if (this.engineGain) {
        const gainVal = 0.02 + rpm * 0.05;
        this.engineGain.gain.setTargetAtTime(gainVal, this.ctx.currentTime, 0.05);
      }
      if (this.skidGain) {
        const isSkidding = handbrake || (Math.abs(speed) > 20 && rpm > 0.85);
        this.skidGain.gain.setTargetAtTime(isSkidding ? 0.08 : 0.0, this.ctx.currentTime, 0.05);
      }
    } catch {}
  }

  playCue(freq, durationMs) {
    if (!this.enabled || !this.ctx) return;
    try {
      if (this.ctx.state === "suspended") this.ctx.resume().catch(() => {});
      const osc = this.ctx.createOscillator();
      const gain = this.ctx.createGain();
      osc.type = "sine";
      osc.frequency.setValueAtTime(freq, this.ctx.currentTime);
      gain.gain.setValueAtTime(0.15, this.ctx.currentTime);
      gain.gain.exponentialRampToValueAtTime(0.001, this.ctx.currentTime + durationMs / 1000);
      osc.connect(gain);
      gain.connect(this.ctx.destination);
      osc.start();
      osc.stop(this.ctx.currentTime + durationMs / 1000);
    } catch {}
  }

  playPass() {
    this.playCue(523.25, 120);
    setTimeout(() => this.playCue(659.25, 120), 100);
    setTimeout(() => this.playCue(783.99, 250), 200);
  }

  playFail() {
    this.playCue(240, 150);
    setTimeout(() => this.playCue(180, 300), 120);
  }
}

const soundManager = new SoundManager();

// --- Profile Persistence and State ---
const storage = typeof localStorage !== "undefined" ? localStorage : {
  getItem: () => null,
  setItem: () => {},
  removeItem: () => {},
};

const PROFILE_KEY = "porsche_profile_009";
let currentProfile = null;
const RANK_NAMES = ["Applicant", "Junior Test Driver", "Test Driver", "Senior Test Driver", "Chief Test Driver"];

function loadStoredProfile() {
  try {
    const raw = storage.getItem(PROFILE_KEY);
    if (raw) {
      currentProfile = JSON.parse(raw);
    }
  } catch {}
  if (!currentProfile) {
    if (typeof shell_profile_new === "function") {
      try {
        const json = shell_profile_new("Driver");
        currentProfile = JSON.parse(json);
      } catch {}
    }
    if (!currentProfile) {
      currentProfile = {
        name: "Driver",
        credits: 11000,
        factory_rank: 0,
        garage: [],
        selected_car_index: 0,
        evolution_unlocked_epochs: [1],
        factory_completed_missions: [],
      };
    }
    saveProfile();
  }
  updateProfileUI();
}

function saveProfile() {
  if (currentProfile) {
    try {
      storage.setItem(PROFILE_KEY, JSON.stringify(currentProfile));
    } catch {}
  }
  updateProfileUI();
}

function updateProfileUI() {
  if (!currentProfile) return;
  const nameEl = document.querySelector("#profileNameDisplay");
  const credEl = document.querySelector("#profileCreditsDisplay");
  const rankEl = document.querySelector("#profileRankDisplay");
  const mName = document.querySelector("#profileNameInput");
  const mCred = document.querySelector("#modalCreditsDisplay");
  const mRank = document.querySelector("#modalRankDisplay");
  const gList = document.querySelector("#profileGarageList");
  const buyBtn = document.querySelector("#profileBuyCarBtn");

  const rankStr = RANK_NAMES[currentProfile.factory_rank] || `Rank ${currentProfile.factory_rank}`;
  const credStr = `${currentProfile.credits.toLocaleString()} CR`;

  if (nameEl) nameEl.textContent = currentProfile.name;
  if (credEl) credEl.textContent = currentProfile.credits.toLocaleString();
  if (rankEl) rankEl.textContent = rankStr;

  if (mName && typeof document.activeElement !== "undefined" && document.activeElement !== mName) {
    mName.value = currentProfile.name;
  }
  if (mCred) mCred.textContent = credStr;
  if (mRank) mRank.textContent = rankStr;

  const has356 = currentProfile.garage && currentProfile.garage.some(c => c.model_name && c.model_name.startsWith("356"));
  if (buyBtn) {
    if (has356) {
      buyBtn.disabled = true;
      buyBtn.textContent = "Куплено: '50 356 Ferdinand";
    } else {
      buyBtn.disabled = currentProfile.credits < 11000;
      buyBtn.textContent = "Купить '50 356 Coupé Ferdinand (11 000 CR)";
    }
  }

  if (gList) {
    gList.replaceChildren();
    if (!currentProfile.garage || currentProfile.garage.length === 0) {
      const emptyDiv = document.createElement("div");
      emptyDiv.className = "garage-empty";
      emptyDiv.textContent = "Гараж пуст. Купите авто в автосалоне.";
      gList.appendChild(emptyDiv);
    } else {
      currentProfile.garage.forEach((c, i) => {
        const item = document.createElement("div");
        item.className = "garage-item" + (i === currentProfile.selected_car_index ? " selected" : "");
        const info = document.createElement("span");
        const condPct = Math.round((c.condition !== undefined ? c.condition : 1.0) * 100);
        const mileageKm = Math.round(c.mileage_km || 0);
        info.innerHTML = `<b>${c.display_name || c.model_name}</b> &bull; ${mileageKm} км &bull; ${condPct}%`;

        const btnWrap = document.createElement("div");
        btnWrap.style.display = "flex";
        btnWrap.style.gap = "6px";

        if (i !== currentProfile.selected_car_index) {
          const selectBtn = document.createElement("button");
          selectBtn.type = "button";
          selectBtn.className = "btn-subtle";
          selectBtn.style.padding = "2px 6px";
          selectBtn.textContent = "Выбрать";
          selectBtn.onclick = () => {
            currentProfile.selected_car_index = i;
            saveProfile();
            updateProfileUI();
          };
          btnWrap.appendChild(selectBtn);
        }

        const sellBtn = document.createElement("button");
        sellBtn.type = "button";
        sellBtn.className = "btn-subtle";
        sellBtn.style.padding = "2px 6px";
        sellBtn.style.color = "#f87171";
        sellBtn.textContent = "Продать";
        sellBtn.disabled = currentProfile.garage.length <= 1;
        sellBtn.onclick = () => {
          if (typeof shell_sell_car === "function") {
            try {
              const res = shell_sell_car(JSON.stringify(currentProfile), i);
              currentProfile = JSON.parse(res);
              saveProfile();
              updateProfileUI();
              soundManager.playPass();
              setStatus("Автомобиль продан, средства зачислены на счёт.");
            } catch (err) {
              alert(`Ошибка продажи: ${err}`);
            }
          }
        };
        btnWrap.appendChild(sellBtn);

        item.appendChild(info);
        item.appendChild(btnWrap);
        gList.appendChild(item);
      });
    }
  }
}

// --- 010 Dealership & Tuning Shop State ---
let currentDealershipTab = "new";
let currentDealershipEra = "all";

function openDealership() {
  const modal = document.querySelector("#dealershipModal");
  if (!modal) return;
  modal.hidden = false;
  renderDealershipGrid();
}

function renderDealershipGrid() {
  const grid = document.querySelector("#dealershipGrid");
  if (!grid) return;
  grid.replaceChildren();

  let cars = [];
  if (currentDealershipTab === "new") {
    if (typeof shell_get_dealership_catalog === "function") {
      try { cars = JSON.parse(shell_get_dealership_catalog()); } catch {}
    }
  } else {
    if (typeof shell_get_used_cars === "function") {
      try { cars = JSON.parse(shell_get_used_cars()); } catch {}
    }
  }

  if (currentDealershipEra !== "all") {
    cars = cars.filter(c => c.era === currentDealershipEra);
  }

  if (cars.length === 0) {
    const empty = document.createElement("div");
    empty.style.color = "#888";
    empty.style.padding = "20px";
    empty.textContent = "Нет доступных автомобилей для выбранной категории.";
    grid.appendChild(empty);
    return;
  }

  cars.forEach(car => {
    const item = document.createElement("div");
    item.className = "market-item";
    
    const title = document.createElement("div");
    title.className = "market-item-title";
    title.textContent = car.display_name || car.model_name;

    const sub = document.createElement("div");
    sub.className = "market-item-sub";
    const mileageStr = car.mileage_km ? `${car.mileage_km.toLocaleString()} км` : "Новый (0 км)";
    const condPct = Math.round((car.condition || 1.0) * 100);
    sub.innerHTML = `Год: <b>${car.year}</b> &bull; Пробег: <b>${mileageStr}</b> &bull; Состояние: <b>${condPct}%</b>`;

    const gauge = document.createElement("div");
    gauge.className = "condition-gauge";
    const fill = document.createElement("div");
    fill.className = "condition-fill" + (condPct < 50 ? " danger" : condPct < 80 ? " warn" : "");
    fill.style.width = `${condPct}%`;
    gauge.appendChild(fill);

    const priceRow = document.createElement("div");
    priceRow.className = "market-item-price";
    const priceVal = document.createElement("span");
    priceVal.textContent = `${car.price.toLocaleString()} CR`;

    const buyBtn = document.createElement("button");
    buyBtn.type = "button";
    buyBtn.className = "market-buy-btn";
    buyBtn.textContent = "Купить";
    const canAfford = currentProfile && currentProfile.credits >= car.price;
    buyBtn.disabled = !canAfford;

    buyBtn.addEventListener("click", () => {
      if (typeof shell_buy_car === "function") {
        try {
          const res = shell_buy_car(JSON.stringify(currentProfile), car.id, currentDealershipTab === "used");
          currentProfile = JSON.parse(res);
          saveProfile();
          renderDealershipGrid();
          soundManager.playPass();
          setStatus(`Куплен ${car.display_name} за ${car.price.toLocaleString()} CR`);
        } catch (e) {
          alert(`Ошибка покупки: ${e}`);
        }
      }
    });

    priceRow.appendChild(priceVal);
    priceRow.appendChild(buyBtn);

    item.appendChild(title);
    item.appendChild(sub);
    item.appendChild(gauge);
    item.appendChild(priceRow);
    grid.appendChild(item);
  });
}

let currentTuningCategory = "all";

function openPartsShop() {
  const modal = document.querySelector("#partsShopModal");
  if (!modal) return;
  modal.hidden = false;
  renderPartsShop();
}

function renderPartsShop() {
  const grid = document.querySelector("#tuningPartsGrid");
  const carName = document.querySelector("#tuningCarName");
  const carMileage = document.querySelector("#tuningCarMileage");
  const carCondition = document.querySelector("#tuningCarCondition");
  const repairAllBtn = document.querySelector("#tuningRepairAllBtn");

  if (!currentProfile || !currentProfile.garage || currentProfile.garage.length === 0) {
    if (grid) {
      grid.replaceChildren();
      const empty = document.createElement("div");
      empty.textContent = "В гараже нет машин. Сначала купите авто в автосалоне.";
      grid.appendChild(empty);
    }
    return;
  }

  const selectedIdx = currentProfile.selected_car_index || 0;
  const activeCar = currentProfile.garage[selectedIdx] || currentProfile.garage[0];
  const carModel = activeCar.model_name || "356_1";
  const condPct = Math.round((activeCar.condition !== undefined ? activeCar.condition : 1.0) * 100);

  if (carName) carName.textContent = activeCar.display_name || activeCar.model_name;
  if (carMileage) carMileage.textContent = `${Math.round(activeCar.mileage_km || 0).toLocaleString()} км`;
  if (carCondition) carCondition.textContent = `${condPct}%`;

  if (repairAllBtn) {
    const isWorn = condPct < 99;
    const estimatedCost = Math.round((activeCar.base_price || 11000) * (1.0 - (activeCar.condition || 1.0)) * 0.4);
    repairAllBtn.textContent = isWorn ? `Ремонт узлов (${estimatedCost.toLocaleString()} CR)` : "Авто в идеале (0 CR)";
    repairAllBtn.disabled = !isWorn || currentProfile.credits < estimatedCost;
    repairAllBtn.onclick = () => {
      if (typeof shell_repair_car === "function") {
        try {
          const res = shell_repair_car(JSON.stringify(currentProfile), selectedIdx);
          currentProfile = JSON.parse(res);
          saveProfile();
          renderPartsShop();
          soundManager.playPass();
          setStatus("Автомобиль и все установленные узлы полностью отремонтированы!");
        } catch (e) {
          alert(`Ошибка ремонта: ${e}`);
        }
      }
    };
  }

  if (!grid) return;
  grid.replaceChildren();

  let parts = [];
  if (typeof shell_get_parts_catalog === "function") {
    try { parts = JSON.parse(shell_get_parts_catalog(carModel)); } catch {}
  }

  if (currentTuningCategory !== "all") {
    parts = parts.filter(p => p.category === currentTuningCategory);
  }

  parts.forEach(part => {
    const item = document.createElement("div");
    item.className = "market-item";

    const title = document.createElement("div");
    title.className = "market-item-title";
    title.textContent = part.name;

    const sub = document.createElement("div");
    sub.className = "market-item-sub";
    sub.innerHTML = `Категория: <b>${part.category_name || part.category}</b>`;

    const priceRow = document.createElement("div");
    priceRow.className = "market-item-price";
    const priceVal = document.createElement("span");
    priceVal.textContent = `${part.price.toLocaleString()} CR`;

    const installBtn = document.createElement("button");
    installBtn.type = "button";
    installBtn.className = "market-buy-btn";
    installBtn.textContent = "Установить";
    const canAfford = currentProfile.credits >= part.price;
    installBtn.disabled = !canAfford;

    installBtn.addEventListener("click", () => {
      if (typeof shell_buy_part === "function") {
        try {
          const res = shell_buy_part(JSON.stringify(currentProfile), selectedIdx, part.part_id);
          currentProfile = JSON.parse(res);
          saveProfile();
          renderPartsShop();
          soundManager.playPass();
          setStatus(`Установлена деталь: ${part.name}`);
        } catch (e) {
          alert(`Ошибка установки детали: ${e}`);
        }
      }
    });

    priceRow.appendChild(priceVal);
    priceRow.appendChild(installBtn);

    item.appendChild(title);
    item.appendChild(sub);
    item.appendChild(priceRow);
    grid.appendChild(item);
  });
}

let currentEvoEra = "classic";

function openEvolutionTournaments() {
  const modal = document.querySelector("#evolutionTournamentsModal");
  if (!modal) return;
  modal.hidden = false;
  renderEvolutionCups();
}

function renderEvolutionCups() {
  const grid = document.querySelector("#evolutionCupsGrid");
  if (!grid) return;
  grid.replaceChildren();

  let cups = [];
  if (typeof shell_get_tournament_cups === "function") {
    try { cups = JSON.parse(shell_get_tournament_cups(currentEvoEra)); } catch {}
  }

  if (cups.length === 0) {
    const empty = document.createElement("div");
    empty.style.color = "#888";
    empty.style.padding = "20px";
    empty.textContent = "Кубки для выбранной эпохи загружаются...";
    grid.appendChild(empty);
    return;
  }

  cups.forEach(cup => {
    const card = document.createElement("div");
    card.className = "cup-card";

    const title = document.createElement("div");
    title.className = "cup-title";
    title.textContent = cup.title;

    const desc = document.createElement("div");
    desc.className = "cup-desc";
    desc.textContent = cup.description;

    const legsList = document.createElement("div");
    legsList.className = "cup-legs";
    legsList.innerHTML = cup.legs.map((l, i) => `Этап ${i + 1}: <b>${l.track_display_name}</b> (${l.laps} круга)`).join("<br/>");

    const stats = document.createElement("div");
    stats.className = "cup-stats";
    stats.innerHTML = `<span>Взнос: <b>${cup.entry_fee.toLocaleString()} CR</b></span><span>Призовой фонд: <b style="color:#d3bd83">${cup.total_prize_purse.toLocaleString()} CR</b></span>`;

    const enterBtn = document.createElement("button");
    enterBtn.type = "button";
    enterBtn.className = "btn-primary";
    enterBtn.style.marginTop = "8px";
    enterBtn.textContent = "Участвовать в кубке";

    enterBtn.addEventListener("click", () => {
      const modal = document.querySelector("#evolutionTournamentsModal");
      if (modal) modal.hidden = true;
      const leg0 = cup.legs[0];
      const eventData = {
        id: `cup_${cup.id}`,
        title: cup.title,
        description: cup.description,
        track_name: leg0.track_id,
        track_display: leg0.track_display_name,
        laps: leg0.laps,
        opponents: 3,
        entry_fee: cup.entry_fee,
        first_prize: Math.round(cup.total_prize_purse * 0.5),
        goal_text: `1-е место (${leg0.laps} круга)`,
        trackId: leg0.track_id,
      };
      showBriefing(eventData);
    });

    card.appendChild(title);
    card.appendChild(desc);
    card.appendChild(legsList);
    card.appendChild(stats);
    card.appendChild(enterBtn);
    grid.appendChild(card);
  });
}

// --- Career Events & Briefing State ---
let activeCareerEvent = null;
let eventFinishedHandled = false;

function showBriefing(eventData) {
  activeCareerEvent = eventData;
  eventFinishedHandled = false;
  const modal = document.querySelector("#eventBriefingModal");
  if (!modal) return;
  const bTitle = document.querySelector("#briefingTitle");
  const bDesc = document.querySelector("#briefingDesc");
  const bTrackCar = document.querySelector("#briefingTrackCar");
  const bGoal = document.querySelector("#briefingGoal");
  const bReward = document.querySelector("#briefingReward");

  if (bTitle) bTitle.textContent = eventData.title;
  if (bDesc) bDesc.textContent = eventData.description;
  if (bTrackCar) bTrackCar.textContent = `${eventData.track} / ${eventData.car}`;
  if (bGoal) bGoal.textContent = eventData.goal;
  if (bReward) bReward.textContent = eventData.reward;
  modal.hidden = false;
}

// Wire up Toolbar & Career Buttons
const soundBtn = document.querySelector("#soundBtn");
if (soundBtn) {
  soundBtn.addEventListener("click", () => {
    const enabled = soundManager.toggle();
    soundBtn.classList.toggle("active", enabled);
    soundBtn.textContent = enabled ? "🔊 Звук: ВКЛ" : "🔇 Звук: ВЫКЛ";
  });
}

const profileBtn = document.querySelector("#profileBtn");
const profileModal = document.querySelector("#profileModal");
const profileModalCloseBtn = document.querySelector("#profileModalCloseBtn");
const profileNameInput = document.querySelector("#profileNameInput");
const profileBuyCarBtn = document.querySelector("#profileBuyCarBtn");
const profileExportBtn = document.querySelector("#profileExportBtn");
const profileImportInput = document.querySelector("#profileImportInput");
const profileResetBtn = document.querySelector("#profileResetBtn");

if (profileBtn && profileModal) {
  profileBtn.addEventListener("click", () => {
    updateProfileUI();
    profileModal.hidden = false;
  });
}
if (profileModalCloseBtn && profileModal) {
  profileModalCloseBtn.addEventListener("click", () => {
    profileModal.hidden = true;
  });
}
if (profileNameInput) {
  profileNameInput.addEventListener("input", (e) => {
    if (currentProfile) {
      currentProfile.name = e.target.value.trim() || "Driver";
      saveProfile();
    }
  });
}
if (profileBuyCarBtn) {
  profileBuyCarBtn.addEventListener("click", () => {
    if (!currentProfile) return;
    if (typeof shell_profile_buy_356 === "function") {
      try {
        const res = shell_profile_buy_356(JSON.stringify(currentProfile));
        currentProfile = JSON.parse(res);
        saveProfile();
        soundManager.playPass();
      } catch (err) {
        if (typeof alert === "function") alert(err);
      }
    } else {
      if (currentProfile.credits >= 11000) {
        currentProfile.credits -= 11000;
        currentProfile.garage.push({
          model_name: "356_1",
          sim_name: "356coupe11",
          color_index: 0,
          price_paid: 11000,
        });
        currentProfile.selected_car_index = currentProfile.garage.length - 1;
        saveProfile();
        soundManager.playPass();
      }
    }
    updateProfileUI();
  });
}
if (profileExportBtn) {
  profileExportBtn.addEventListener("click", () => {
    if (!currentProfile) return;
    if (typeof Blob !== "undefined" && typeof URL !== "undefined" && typeof URL.createObjectURL === "function") {
      const blob = new Blob([JSON.stringify(currentProfile, null, 2)], { type: "application/json" });
      const url = URL.createObjectURL(blob);
      const a = document.createElement("a");
      a.href = url;
      a.download = `porsche_profile_${currentProfile.name.toLowerCase().replace(/[^a-z0-9]/g, "_")}.json`;
      a.click();
      URL.revokeObjectURL(url);
    }
  });
}
if (profileImportInput) {
  profileImportInput.addEventListener("change", async (e) => {
    const file = e.target.files?.[0];
    if (!file) return;
    try {
      const text = await file.text();
      const parsed = JSON.parse(text);
      if (parsed && typeof parsed.name === "string" && typeof parsed.credits === "number") {
        currentProfile = parsed;
        saveProfile();
        soundManager.playPass();
        setStatus(`Профиль "${currentProfile.name}" успешно импортирован.`);
      }
    } catch (err) {
      if (typeof alert === "function") alert("Ошибка при импорте: " + err.message);
    }
  });
}
if (profileResetBtn) {
  profileResetBtn.addEventListener("click", () => {
    storage.removeItem(PROFILE_KEY);
    currentProfile = null;
    loadStoredProfile();
    setStatus("Профиль сброшен к начальному состоянию.");
  });
}

const careerEvolutionBtn = document.querySelector("#careerEvolutionBtn");
if (careerEvolutionBtn) {
  careerEvolutionBtn.addEventListener("click", () => {
    const evoInfo = {
      id: "356_CHALLENGE",
      title: "Evolution: 356 Challenge (Эра Classic)",
      description: "Первый турнир эры Classic. 2 этапа (Canyon и Monaco 1). Одержите победу над соперниками на классическом 356!",
      track: "Canyon",
      car: "356 Coupé (1950)",
      goal: "1-е место на этапе (4 участника)",
      reward: "4 500 CR",
      is_factory: false,
      trackId: "canyon",
    };
    if (typeof shell_get_first_evolution_event === "function") {
      try {
        const parsed = JSON.parse(shell_get_first_evolution_event());
        evoInfo.title = parsed.title;
        evoInfo.description = parsed.description;
        evoInfo.reward = `${parsed.first_prize.toLocaleString()} CR`;
        evoInfo.trackId = parsed.track_name.toLowerCase();
        evoInfo.track = parsed.track_name;
      } catch {}
    }
    showBriefing(evoInfo);
  });
}

const dealershipBtn = document.querySelector("#dealershipBtn");
if (dealershipBtn) {
  dealershipBtn.addEventListener("click", () => {
    openDealership();
  });
}

const dealershipCloseBtn = document.querySelector("#dealershipCloseBtn");
if (dealershipCloseBtn) {
  dealershipCloseBtn.addEventListener("click", () => {
    const modal = document.querySelector("#dealershipModal");
    if (modal) modal.hidden = true;
  });
}

const dealershipNewTab = document.querySelector("#dealershipNewTab");
const dealershipUsedTab = document.querySelector("#dealershipUsedTab");
if (dealershipNewTab && dealershipUsedTab) {
  dealershipNewTab.addEventListener("click", () => {
    currentDealershipTab = "new";
    dealershipNewTab.classList.add("active");
    dealershipUsedTab.classList.remove("active");
    renderDealershipGrid();
  });
  dealershipUsedTab.addEventListener("click", () => {
    currentDealershipTab = "used";
    dealershipUsedTab.classList.add("active");
    dealershipNewTab.classList.remove("active");
    renderDealershipGrid();
  });
}

const queryAll = (sel) => (typeof document !== "undefined" && typeof document.querySelectorAll === "function") ? Array.from(document.querySelectorAll(sel)) : [];

queryAll(".era-chip").forEach(chip => {
  chip.addEventListener("click", () => {
    queryAll(".era-chip").forEach(c => c.classList.remove("active"));
    chip.classList.add("active");
    currentDealershipEra = chip.dataset.era || "all";
    renderDealershipGrid();
  });
});

const partsShopBtn = document.querySelector("#partsShopBtn");
if (partsShopBtn) {
  partsShopBtn.addEventListener("click", () => {
    openPartsShop();
  });
}

const partsShopCloseBtn = document.querySelector("#partsShopCloseBtn");
if (partsShopCloseBtn) {
  partsShopCloseBtn.addEventListener("click", () => {
    const modal = document.querySelector("#partsShopModal");
    if (modal) modal.hidden = true;
  });
}

queryAll(".cat-chip").forEach(chip => {
  chip.addEventListener("click", () => {
    queryAll(".cat-chip").forEach(c => c.classList.remove("active"));
    chip.classList.add("active");
    currentTuningCategory = chip.dataset.cat || "all";
    renderPartsShop();
  });
});

const evolutionCloseBtn = document.querySelector("#evolutionCloseBtn");
if (evolutionCloseBtn) {
  evolutionCloseBtn.addEventListener("click", () => {
    const modal = document.querySelector("#evolutionTournamentsModal");
    if (modal) modal.hidden = true;
  });
}

queryAll(".evo-era-chip").forEach(chip => {
  chip.addEventListener("click", () => {
    queryAll(".evo-era-chip").forEach(c => c.classList.remove("active"));
    chip.classList.add("active");
    currentEvoEra = chip.dataset.era || "classic";
    renderEvolutionCups();
  });
});

const careerFactoryBtn = document.querySelector("#careerFactoryBtn");
if (careerFactoryBtn) {
  careerFactoryBtn.addEventListener("click", () => {
    const facInfo = {
      id: "0M01",
      title: "Factory Driver: 0M01 Applying Test",
      description: "Начальный отборочный тест на должность водителя-испытателя Porsche. Пройдите круг по полигону Skidpad на Porsche Boxster быстрее 32.0 секунд!",
      track: "Skidpad",
      car: "Boxster (986)",
      goal: "Время круга ≤ 32.0 сек",
      reward: "Приём в штат (Junior Test Driver)",
      is_factory: true,
      time_limit: 32.0,
      trackId: "skidpad",
      pass_msg: "Отличный заезд! Вы приняты водителем-испытателем Porsche!",
      fail_msg: "Время превышено. Вы не уложились в 32.0 секунды. Попробуйте снова!",
    };
    if (typeof shell_get_first_factory_event === "function") {
      try {
        const parsed = JSON.parse(shell_get_first_factory_event());
        facInfo.id = parsed.id;
        facInfo.title = parsed.title;
        facInfo.description = parsed.description;
        facInfo.time_limit = parsed.time_limit;
        facInfo.trackId = parsed.track_name.toLowerCase();
        facInfo.pass_msg = parsed.pass_message;
        facInfo.fail_msg = parsed.fail_message;
      } catch {}
    }
    showBriefing(facInfo);
  });
}

const briefingStartBtn = document.querySelector("#briefingStartBtn");
if (briefingStartBtn) {
  briefingStartBtn.addEventListener("click", async () => {
    const modal = document.querySelector("#eventBriefingModal");
    if (modal) modal.hidden = true;
    if (!activeCareerEvent) return;

    modeSelect.value = "track";
    updateOptions();
    targetSelect.value = activeCareerEvent.trackId;
    await loadTarget();

    if (viewer) {
      if (!viewer.is_drive_mode()) {
        viewer.toggle_camera_mode();
        setMenuVisible(false);
        syncTourButton();
      }
      viewer.restart_race();
      eventFinishedHandled = false;
      soundManager.playCue(880, 100);
      setStatus(`Карьерный заезд начат: ${activeCareerEvent.title}`);
    }
  });
}

const briefingCancelBtn = document.querySelector("#briefingCancelBtn");
if (briefingCancelBtn) {
  briefingCancelBtn.addEventListener("click", () => {
    const modal = document.querySelector("#eventBriefingModal");
    if (modal) modal.hidden = true;
    activeCareerEvent = null;
  });
}

const raceContinueBtn = document.querySelector("#raceContinueBtn");
if (raceContinueBtn) {
  raceContinueBtn.addEventListener("click", () => {
    if (raceResultsModal) raceResultsModal.hidden = true;
    activeCareerEvent = null;
    setMenuVisible(true);
  });
}

function setMenuVisible(visible) {
  menuVisible = visible;
  document.body.classList.toggle("menu-hidden", !visible);
  menuButton.setAttribute("aria-expanded", String(visible));
  clearNavigation();
  if (visible) menuButton.focus();
  else canvas.focus();
  queueFrame();
}

function toggleHud() {
  hudVisible = !hudVisible;
  hudButton.setAttribute("aria-pressed", String(hudVisible));
  syncTourButton();
}

menuButton.addEventListener("click", () => setMenuVisible(!menuVisible));
document.querySelector("#hideMenuButton").addEventListener("click", () => setMenuVisible(false));
hudButton.addEventListener("click", toggleHud);
detailsButton.addEventListener("click", () => {
  summary.hidden = !summary.hidden;
  detailsButton.setAttribute("aria-expanded", String(!summary.hidden));
});

let viewer = null;
let selectedFiles = [];
let localGameAvailable = false;
let localGameFiles = [];
let useCustomFiles = false;

let dragging = false;
let lastPointer = null;
let needsFrame = true;

let availableCars = [];
let availableTracks = [];
let loadGeneration = 0;

function setStatus(text) {
  statusLine.textContent = text;
}

function queueFrame() {
  needsFrame = true;
}

function selectedName(file) {
  return file.webkitRelativePath || file.name;
}

function updateSourceUI() {
  if (!sourceBadge) return;
  if (useCustomFiles && selectedFiles.length > 0) {
    sourceBadge.textContent = "Пользовательские файлы";
    sourceBadge.classList.add("custom");
    if (resetSourceButton && localGameAvailable) {
      resetSourceButton.style.display = "inline-flex";
    }
  } else if (localGameAvailable) {
    sourceBadge.textContent = "local/game";
    sourceBadge.classList.remove("custom");
    if (resetSourceButton) {
      resetSourceButton.style.display = "none";
    }
  } else {
    sourceBadge.textContent = "Файлы не выбраны";
    sourceBadge.classList.remove("custom");
    if (resetSourceButton) {
      resetSourceButton.style.display = "none";
    }
  }
}

function scanLocalGameCatalog() {
  const basenames = new Set(
    localGameFiles.map((p) => p.split(/[\\/]/).pop().toLowerCase())
  );
  availableCars = [...basenames]
    .filter((name) => name.endsWith(".crp") && basenames.has(name.slice(0, -4) + ".tpg"))
    .map((name) => name.slice(0, -4))
    .sort();

  availableTracks = [...basenames]
    .filter((name) => name.endsWith(".crp") && basenames.has(name.slice(0, -4) + ".fsh"))
    .map((name) => name.slice(0, -4))
    .sort();
}

async function checkLocalGame() {
  try {
    const res = await fetch("/api/game-files");
    if (!res.ok) return false;
    const files = await res.json();
    if (Array.isArray(files) && files.length > 0) {
      localGameFiles = files;
      localGameAvailable = true;
      if (!useCustomFiles) {
        scanLocalGameCatalog();
      }
      updateSourceUI();
      updateOptions();
      return true;
    }
  } catch {
    // Offline or server without /api/game-files
  }
  return false;
}

function updateOptions() {
  const isTrack = modeSelect.value === "track";
  targetLabel.textContent = isTrack ? "Трасса" : "Авто";
  if (topologyField) {
    topologyField.style.display = isTrack ? "inline-flex" : "none";
  }
  syncTourButton();

  const knownList = isTrack ? KNOWN_TRACKS : KNOWN_CARS;
  const availableSet = new Set(isTrack ? availableTracks : availableCars);
  const previousValue = targetSelect.value;

  targetSelect.replaceChildren();

  // If there are discovered items not in known list, collect them
  const knownIds = new Set(knownList.map((k) => k.id));
  const extraItems = [];
  for (const id of availableSet) {
    if (!knownIds.has(id)) {
      extraItems.push({ id, name: id });
    }
  }

  const combined = [...knownList, ...extraItems];
  const hasSource = (useCustomFiles && selectedFiles.length > 0) || localGameAvailable;

  for (const item of combined) {
    const opt = document.createElement("option");
    opt.value = item.id;
    const isAvail = availableSet.has(item.id);
    if (hasSource) {
      opt.textContent = isAvail ? item.name : `(нет файлов) ${item.name}`;
      opt.disabled = !isAvail;
    } else {
      opt.textContent = item.name;
    }
    targetSelect.appendChild(opt);
  }

  // Restore previous selection if still valid and enabled
  const options = Array.from(targetSelect.options);
  const matchingOption = options.find((o) => o.value === previousValue && !o.disabled);
  if (matchingOption) {
    targetSelect.value = matchingOption.value;
  } else {
    const firstEnabled = options.find((o) => !o.disabled);
    if (firstEnabled) {
      targetSelect.value = firstEnabled.value;
    } else if (options.length > 0) {
      targetSelect.selectedIndex = 0;
    }
  }
}

modeSelect.addEventListener("change", () => {
  updateOptions();
  setStatus(`Режим: ${modeSelect.value === "track" ? "Трасса" : "Автомобиль"}.`);
  const canLoad = (useCustomFiles && selectedFiles.length > 0) || localGameAvailable;
  if (canLoad && viewer) {
    loadTarget();
  }
});

targetSelect.addEventListener("change", () => {
  const canLoad = (useCustomFiles && selectedFiles.length > 0) || localGameAvailable;
  if (canLoad && viewer) {
    loadTarget();
  }
});

topologyCheckbox.addEventListener("change", () => {
  if (viewer) {
    viewer.set_show_topology(topologyCheckbox.checked);
    queueFrame();
    setStatus(`3D границы: ${topologyCheckbox.checked ? "включены" : "выключены"}.`);
  }
});

function rememberFiles(files) {
  selectedFiles = Array.from(files || []);
  if (selectedFiles.length > 0) {
    useCustomFiles = true;
    const basenames = new Set(
      selectedFiles.map((file) => selectedName(file).split(/[\\/]/).pop().toLowerCase())
    );
    availableCars = [...basenames]
      .filter((name) => name.endsWith(".crp") && basenames.has(name.slice(0, -4) + ".tpg"))
      .map((name) => name.slice(0, -4))
      .sort();

    availableTracks = [...basenames]
      .filter((name) => name.endsWith(".crp") && basenames.has(name.slice(0, -4) + ".fsh"))
      .map((name) => name.slice(0, -4))
      .sort();
  } else if (localGameAvailable) {
    useCustomFiles = false;
    scanLocalGameCatalog();
  }

  updateSourceUI();
  updateOptions();
  const count = selectedFiles.length;
  setStatus(
    count
      ? `Выбрано файлов вручную: ${count}. Трасс: ${availableTracks.length}, Авто: ${availableCars.length}.`
      : (localGameAvailable ? `Используются файлы из local/game (${availableTracks.length} трасс, ${availableCars.length} авто).` : "Файлы не выбраны.")
  );

  if (viewer && (availableTracks.length > 0 || availableCars.length > 0)) {
    loadTarget();
  }
}

folderInput.addEventListener("change", () => rememberFiles(folderInput.files));
fileInput.addEventListener("change", () => rememberFiles(fileInput.files));

if (resetSourceButton) {
  resetSourceButton.addEventListener("click", () => {
    useCustomFiles = false;
    selectedFiles = [];
    if (folderInput) folderInput.value = "";
    if (fileInput) fileInput.value = "";
    scanLocalGameCatalog();
    updateSourceUI();
    updateOptions();
    setStatus(`Возврат к local/game (${availableTracks.length} трасс, ${availableCars.length} авто).`);
    if (viewer) {
      loadTarget();
    }
  });
}

function findTrackFilesFromCatalog(target) {
  const matching = [];
  const targetLower = target.toLowerCase();
  for (const relPath of localGameFiles) {
    const fullPath = relPath.replace(/\\/g, "/").toLowerCase();
    const basename = fullPath.split("/").pop();
    const stem = basename.replace(/\.[^.]+$/, "");
    const ext = basename.split(".").pop();

    if (fullPath.includes("/sky/") && ext === "fsh" && stem === targetLower) {
      matching.push(relPath);
      continue;
    }
    if (fullPath.includes("/sky/") || fullPath.includes("/sky new/")) continue;

    if (
      ext === "scn" &&
      stem.startsWith(targetLower) &&
      !basename.includes("audio") &&
      !basename.includes("camera") &&
      !basename.includes("start")
    ) {
      matching.push(relPath);
      continue;
    }

    if (
      [
        `${targetLower}.crp`,
        `${targetLower}.fsh`,
        `${targetLower}.env`,
        `${targetLower}.edg`,
        `${targetLower}.map`,
        `${targetLower}.jnc`,
        `${targetLower}0.lsp`,
        `${targetLower}.lsp`,
      ].includes(basename)
    ) {
      matching.push(relPath);
    }
  }
  return matching;
}

function findCarFilesFromCatalog(target) {
  const matching = [];
  const targetLower = target.toLowerCase();
  const commonFsh = new Set([
    "intglass.fsh",
    "shadow.fsh",
    "cabrio.fsh",
    "carcmn.fsh",
    "price.fsh",
    "head.fsh",
    "suit.fsh",
  ]);

  for (const relPath of localGameFiles) {
    const fullPath = relPath.replace(/\\/g, "/").toLowerCase();
    const basename = fullPath.split("/").pop();
    const stem = basename.replace(/\.[^.]+$/, "");
    const ext = basename.split(".").pop();

    if (!fullPath.includes("carmodel")) continue;

    if (stem === targetLower && ["crp", "tpg", "clr"].includes(ext)) {
      matching.push(relPath);
      continue;
    }

    if (ext === "fsh") {
      if (
        stem.startsWith(targetLower) ||
        stem.startsWith("f" + targetLower) ||
        commonFsh.has(basename) ||
        stem.startsWith("eas") ||
        stem.startsWith("eden")
      ) {
        matching.push(relPath);
      }
    }
  }
  return matching;
}

async function fetchGameFiles(paths) {
  const fetchPromises = paths.map(async (relPath) => {
    const url = "/game/" + relPath.replace(/\\/g, "/");
    const resp = await fetch(url);
    if (!resp.ok) {
      throw new Error(`Не удалось загрузить ${relPath}: HTTP ${resp.status}`);
    }
    const buf = await resp.arrayBuffer();
    return {
      name: relPath.replace(/\\/g, "/"),
      data: new Uint8Array(buf),
    };
  });
  const results = await Promise.all(fetchPromises);
  const names = [];
  const bytes = [];
  for (const res of results) {
    names.push(res.name);
    bytes.push(res.data);
  }
  return { names, bytes };
}

async function loadTarget() {
  if (!viewer) {
    setStatus("WebGPU еще не готов.");
    return;
  }
  const isCustom = useCustomFiles && selectedFiles.length > 0;
  if (!isCustom && !localGameAvailable) {
    setStatus("Выберите папку игры или файлы.");
    return;
  }

  const isTrack = modeSelect.value === "track";
  const generation = ++loadGeneration;
  const customFiles = [...selectedFiles];
  clearNavigation();
  const target = targetSelect.value.trim().toLowerCase() || (isTrack ? "skidpad" : "356a");

  loadButton.disabled = true;
  targetSelect.disabled = true;
  const sourceText = isCustom ? "пользовательских файлов" : "local/game";
  setStatus(`Чтение файлов для ${isTrack ? "трассы" : "авто"} "${target}" из ${sourceText}...`);

  try {
    let names = [];
    let bytes = [];

    if (isCustom) {
      if (isTrack) {
        for (const file of customFiles) {
          const fullPath = selectedName(file).replace(/\\/g, "/").toLowerCase();
          const basename = fullPath.split("/").pop();
          const stem = basename.replace(/\.[^.]+$/, "");
          const ext = basename.split(".").pop();

          if (fullPath.includes("/sky/") && ext === "fsh" && stem === target) {
            names.push(selectedName(file));
            bytes.push(new Uint8Array(await file.arrayBuffer()));
            continue;
          }
          if (fullPath.includes("/sky/") || fullPath.includes("/sky new/")) continue;

          if (
            ext === "scn" &&
            stem.startsWith(target) &&
            !basename.includes("audio") &&
            !basename.includes("camera") &&
            !basename.includes("start")
          ) {
            names.push(selectedName(file));
            bytes.push(new Uint8Array(await file.arrayBuffer()));
            continue;
          }

          if (
            [
              `${target}.crp`,
              `${target}.fsh`,
              `${target}.env`,
              `${target}.edg`,
              `${target}.map`,
              `${target}.jnc`,
            ].includes(basename)
          ) {
            names.push(selectedName(file));
            bytes.push(new Uint8Array(await file.arrayBuffer()));
          }
        }
      } else {
        for (const file of customFiles) {
          const basename = selectedName(file).split(/[\\/]/).pop().toLowerCase();
          if (
            ![`${target}.crp`, `${target}.tpg`, `${target}.clr`].includes(basename) &&
            !basename.endsWith(".fsh")
          ) {
            continue;
          }
          names.push(selectedName(file));
          bytes.push(new Uint8Array(await file.arrayBuffer()));
        }
      }
    } else {
      const paths = isTrack
        ? findTrackFilesFromCatalog(target)
        : findCarFilesFromCatalog(target);

      if (paths.length === 0) {
        throw new Error(`Файлы для ${isTrack ? "трассы" : "авто"} "${target}" не найдены в local/game.`);
      }

      setStatus(`Загрузка ${paths.length} файлов для "${target}" по сети...`);
      const fetched = await fetchGameFiles(paths);
      names = fetched.names;
      bytes = fetched.bytes;
    }

    if (generation !== loadGeneration) return;
    if (names.length === 0) {
      throw new Error(`Файлы для ${isTrack ? "трассы" : "авто"} "${target}" не найдены.`);
    }

    if (isTrack) {
      const text = viewer.load_track(names, bytes, target);
      viewer.set_show_topology(topologyCheckbox.checked);
      summary.textContent = text;
      const hasTopo = viewer.has_topology();
      setStatus(`Трасса "${target}" загружена из ${sourceText}.${hasTopo ? " F — начать заезд. T — границы." : " Границы не найдены."}`);
    } else {
      const text = viewer.load(names, bytes, target);
      summary.textContent = text;
      setStatus(`Авто "${target}" загружено из ${sourceText}. Горячая клавиша C меняет цвет.`);
    }

    syncTourButton();
    queueFrame();
  } catch (error) {
    if (generation !== loadGeneration) return;
    setStatus(error instanceof Error ? error.message : String(error));
  } finally {
    if (generation === loadGeneration) {
      loadButton.disabled = false;
      targetSelect.disabled = false;
    }
  }
}

loadButton.addEventListener("click", () => loadTarget());

function syncTourButton() {
  if (!tourButton) return;
  const isTrack = modeSelect.value === "track";
  const hasCar = viewer ? viewer.has_car() : false;
  tourButton.style.display = isTrack ? "inline-flex" : "none";
  if (cameraButton) cameraButton.style.display = isTrack && hasCar ? "inline-flex" : "none";
  if (paintButton) paintButton.style.display = isTrack && hasCar ? "inline-flex" : "none";

  const isDrive = viewer ? viewer.is_drive_mode() : false;
  tourButton.classList.toggle("active", isDrive);
  tourButton.textContent = isDrive ? "Орбита (F)" : (hasCar ? "Заезд (F)" : "Прогон (F)");

  const isDriveAndCar = isDrive && hasCar;
  if (hud) {
    hud.hidden = !(isDriveAndCar && hudVisible);
  }
  const isRacingActive = isDriveAndCar && viewer && viewer.get_race_phase && viewer.get_race_phase() > 0;
  if (raceHudTop) {
    raceHudTop.hidden = !(isRacingActive && hudVisible);
  }
  if (!isDriveAndCar) {
    if (countdownBanner) countdownBanner.hidden = true;
    if (wrongWayBanner) wrongWayBanner.hidden = true;
    if (raceResultsModal) raceResultsModal.hidden = true;
  }
}

tourButton.addEventListener("click", () => {
  if (!viewer) return;
  const isDrive = viewer.toggle_camera_mode();
  setMenuVisible(!isDrive);
  syncTourButton();
  setStatus(
    isDrive
      ? (viewer.has_car()
          ? "Режим заезда на авто включён (F). W: газ, S: тормоз/назад, A/D: руль, Space: ручник, C: вид, R: сброс."
          : "Режим прогона включён (F). WASD: полёт вдоль границ, Мышь: обзор, Shift: ускорение.")
      : "Орбитальная камера."
  );
  queueFrame();
});

if (cameraButton) {
  cameraButton.addEventListener("click", () => {
    if (!viewer) return;
    if (viewer.is_drive_mode() && viewer.has_car()) {
      const mode = viewer.cycle_car_view();
      const names = ["Сзади (Chase)", "С капота (Bumper)", "Свободный (Free)"];
      setStatus(`Камера: ${names[mode] || mode}`);
      queueFrame();
    }
  });
}

if (paintButton) {
  paintButton.addEventListener("click", () => {
    if (!viewer) return;
    if (viewer.has_car()) {
      const idx = viewer.cycle_car_paint();
      const names = ["Guards Red", "Midnight Blue", "GT Silver", "Irish Green", "Speed Yellow", "Basalt Black"];
      setStatus(`Цвет авто: ${names[idx] || idx}`);
      queueFrame();
    }
  });
}

let panMode = false;

canvas.addEventListener("contextmenu", (event) => {
  event.preventDefault();
});

resetButton.addEventListener("click", () => {
  if (viewer) {
    if (viewer.is_drive_mode() && viewer.has_car()) {
      viewer.restart_race();
      if (raceResultsModal) raceResultsModal.hidden = true;
      setStatus("Гонка перезапущена / старт на решётке.");
    } else {
      viewer.reset_camera();
      setStatus("Камера сброшена.");
    }
    velForward = 0;
    velRight = 0;
    velZoom = 0;
    syncTourButton();
    queueFrame();
  }
});

canvas.addEventListener("pointerdown", (event) => {
  canvas.focus();
  dragging = true;
  panMode = event.button === 2 || event.button === 1 || event.shiftKey;
  lastPointer = { x: event.clientX, y: event.clientY };
  canvas.setPointerCapture(event.pointerId);
});

canvas.addEventListener("pointerup", (event) => {
  dragging = false;
  panMode = false;
  lastPointer = null;
  canvas.releasePointerCapture(event.pointerId);
});

canvas.addEventListener("pointercancel", () => {
  dragging = false;
  panMode = false;
  lastPointer = null;
});

canvas.addEventListener("pointermove", (event) => {
  if (!dragging || !viewer || !lastPointer) {
    return;
  }
  const dx = event.clientX - lastPointer.x;
  const dy = event.clientY - lastPointer.y;
  lastPointer = { x: event.clientX, y: event.clientY };
  if (panMode) {
    viewer.pan(dx, dy);
  } else {
    viewer.orbit(dx, dy);
  }
  queueFrame();
});

canvas.addEventListener(
  "wheel",
  (event) => {
    if (!viewer) {
      return;
    }
    event.preventDefault();
    viewer.zoom(event.deltaY);
    queueFrame();
  },
  { passive: false },
);

const activeKeys = new Set();
let lastTime = 0;
let velForward = 0;
let velRight = 0;
let velZoom = 0;

function isTyping(event) {
  return (
    event.target instanceof HTMLInputElement ||
    event.target instanceof HTMLTextAreaElement ||
    event.target instanceof HTMLSelectElement || event.target.isContentEditable
  );
}

window.addEventListener("keydown", (event) => {
  if (event.code === "Escape" && !event.repeat) {
    event.preventDefault();
    setMenuVisible(!menuVisible);
    return;
  }
  if (isTyping(event)) return;
  if (event.ctrlKey || event.altKey || event.metaKey) return;
  if (event.code === "KeyH" && !event.repeat) {
    toggleHud();
    return;
  }

  // Single-shot keys (ignore auto-repeat)
  if (event.code === "KeyR" && !event.repeat) {
    if (viewer) {
      if (viewer.is_drive_mode() && viewer.has_car()) {
        viewer.restart_race();
        if (raceResultsModal) raceResultsModal.hidden = true;
        setStatus("Гонка перезапущена / старт на решётке.");
      } else {
        viewer.reset_camera();
        setStatus("Камера сброшена.");
      }
      velForward = 0;
      velRight = 0;
      velZoom = 0;
      syncTourButton();
      queueFrame();
    }
    return;
  }
  if (event.code === "KeyT" && !event.repeat && modeSelect.value === "track") {
    topologyCheckbox.checked = !topologyCheckbox.checked;
    if (viewer) {
      viewer.set_show_topology(topologyCheckbox.checked);
      queueFrame();
    }
    setStatus(`3D границы: ${topologyCheckbox.checked ? "включены" : "выключены"}.`);
    return;
  }
  if (event.code === "KeyF" && !event.repeat && modeSelect.value === "track") {
    if (viewer) {
      const isDrive = viewer.toggle_camera_mode();
      setMenuVisible(!isDrive);
      syncTourButton();
      setStatus(
        isDrive
          ? (viewer.has_car()
              ? "Режим заезда на авто включён (F). W: газ, S: тормоз/назад, A/D: руль, Space: ручник, C: вид, R: сброс."
              : "Режим прогона включён (F). WASD: полёт вдоль границ, Мышь: обзор, Shift: ускорение.")
          : "Орбитальная камера."
      );
      queueFrame();
    }
    return;
  }
  if (event.code === "KeyM" && !event.repeat) {
    if (viewer) {
      const isSim = viewer.toggle_sim_mode();
      const badge = document.getElementById("physicsModeBadge");
      if (badge) {
        badge.textContent = isSim ? "M: 6 DOF Физика" : "M: Аркада";
      }
      setStatus(
        isSim
          ? "Физика: 6 DOF Реалистичная симуляция (.sim, 4 независимых колеса, подвеска)"
          : "Физика: Прототип Аркадной модели"
      );
      queueFrame();
    }
    return;
  }
  if (event.code === "KeyC" && !event.repeat) {
    if (viewer) {
      if (viewer.is_drive_mode() && viewer.has_car()) {
        const mode = viewer.cycle_car_view();
        const names = ["Сзади (Chase)", "С капота (Bumper)", "Свободный (Free)"];
        setStatus(`Вид камеры: ${names[mode] || mode}`);
      } else {
        viewer.cycle_paint_color();
      }
      queueFrame();
    }
    return;
  }
  if (event.code === "KeyP" && !event.repeat) {
    if (viewer) {
      if (viewer.has_car()) {
        const idx = viewer.cycle_car_paint();
        const names = ["Guards Red", "Midnight Blue", "GT Silver", "Irish Green", "Speed Yellow", "Basalt Black"];
        setStatus(`Цвет авто: ${names[idx] || idx}`);
      } else {
        viewer.cycle_paint_color();
      }
      queueFrame();
    }
    return;
  }

  // Prevent default page scroll on arrow keys or space
  if (["ArrowUp", "ArrowDown", "ArrowLeft", "ArrowRight", "Space"].includes(event.code)) {
    event.preventDefault();
  }

  activeKeys.add(event.code);
});

window.addEventListener("keyup", (event) => {
  activeKeys.delete(event.code);
});

function clearNavigation() {
  activeKeys.clear();
  velForward = 0;
  velRight = 0;
  velZoom = 0;
  lastTime = 0;
  dragging = false;
  lastPointer = null;
}
window.addEventListener("blur", clearNavigation);
document.addEventListener("visibilitychange", clearNavigation);
document.querySelector("#menu").addEventListener("focusin", clearNavigation);

function updateNavigation(dt) {
  if (!viewer) return;

  const isDriveCar = viewer.is_drive_mode() && viewer.has_car();
  if (isDriveCar) {
    let throttle = 0;
    if (activeKeys.has("KeyW") || activeKeys.has("ArrowUp")) throttle += 1.0;
    if (activeKeys.has("KeyS") || activeKeys.has("ArrowDown")) throttle -= 1.0;

    let steer = 0;
    if (activeKeys.has("KeyA") || activeKeys.has("ArrowLeft")) steer -= 1.0;
    if (activeKeys.has("KeyD") || activeKeys.has("ArrowRight")) steer += 1.0;

    const handbrake = activeKeys.has("Space");

    viewer.update_car(dt, throttle, steer, handbrake);

    // Update HUD display
    const speed = Math.round(viewer.get_car_speed());
    const gear = viewer.get_car_gear();
    const rpm = Math.max(0, Math.min(1, viewer.get_car_rpm()));

    soundManager.update(rpm, speed, handbrake);

    if (speedValue) speedValue.textContent = String(speed);
    if (gearValue) {
      gearValue.textContent = gear < 0 ? "R" : gear === 0 ? "N" : String(gear);
      gearValue.classList.toggle("reverse", gear < 0);
    }
    if (rpmBar) {
      rpmBar.style.width = `${Math.round(rpm * 100)}%`;
      if (rpm > 0.82) {
        rpmBar.style.background = "#ef4444";
      } else if (rpm > 0.65) {
        rpmBar.style.background = "#f59e0b";
      } else {
        rpmBar.style.background = "#d3bd83";
      }
    }

    // Update Race HUD
    const phase = viewer.get_race_phase ? viewer.get_race_phase() : 0;
    const isRacingActive = phase > 0;

    if (raceHudTop) {
      raceHudTop.hidden = !(hudVisible && isRacingActive);
      if (isRacingActive) {
        if (racePos) racePos.textContent = String(viewer.get_player_position());
        if (raceTotalPos) raceTotalPos.textContent = `/${viewer.get_total_participants()}`;
        if (raceLap) raceLap.textContent = String(viewer.get_current_lap());
        if (raceTotalLaps) raceTotalLaps.textContent = `/${viewer.get_total_laps()}`;
        if (raceLapTime) raceLapTime.textContent = formatRaceTime(viewer.get_current_lap_time());
        if (raceBestLap) {
          const best = viewer.get_best_lap_time();
          raceBestLap.textContent = `ЛУЧШИЙ ${formatRaceTime(best)}`;
        }
      }
    }

    // Countdown Banner
    if (countdownBanner) {
      if (phase === 1) {
        if (lastPhase !== 1) soundManager.playCue(440, 80);
        countdownBanner.hidden = false;
        const remaining = viewer.get_countdown_remaining();
        if (countdownText) {
          countdownText.classList.remove("go");
          if (remaining > 2.0) countdownText.textContent = "3";
          else if (remaining > 1.0) countdownText.textContent = "2";
          else countdownText.textContent = "1";
        }
      } else if (phase === 2 && lastPhase === 1) {
        soundManager.playCue(880, 150);
        countdownBanner.hidden = false;
        if (countdownText) {
          countdownText.classList.add("go");
          countdownText.textContent = "СТАРТ!";
        }
        setTimeout(() => {
          if (countdownBanner) countdownBanner.hidden = true;
        }, 1200);
      } else if (phase !== 1 && (lastPhase !== 1 || phase > 2)) {
        countdownBanner.hidden = true;
      }
    }
    lastPhase = phase;

    // Wrong Way Alert
    if (wrongWayBanner) {
      wrongWayBanner.hidden = !(phase === 2 && viewer.is_wrong_way());
    }

    // Race Finished / Results Modal
    if (raceResultsModal) {
      if ((phase === 4 || phase === 5) && raceResultsModal.hidden) {
        raceResultsModal.hidden = false;
        const pos = viewer.get_player_position();
        const total = viewer.get_total_participants();
        const lapTime = viewer.get_current_lap_time();
        const bestTime = viewer.get_best_lap_time();
        if (resultsSubtitle) resultsSubtitle.textContent = `Позиция: P${pos} из ${total}`;
        if (resultsLapTime) resultsLapTime.textContent = formatRaceTime(lapTime);
        if (resultsBestTime) resultsBestTime.textContent = formatRaceTime(bestTime);

        if (activeCareerEvent && !eventFinishedHandled) {
          eventFinishedHandled = true;
          let passed = false;
          if (activeCareerEvent.is_factory) {
            passed = lapTime > 0 && lapTime <= (activeCareerEvent.time_limit || 32.0);
          } else {
            passed = pos === 1;
          }

          if (passed) {
            soundManager.playPass();
          } else {
            soundManager.playFail();
          }

          const speechEl = document.querySelector("#resultsSpeech");
          const rewardBadge = document.querySelector("#resultsRewardBadge");

          if (activeCareerEvent.is_factory) {
            if (speechEl) {
              speechEl.style.display = "block";
              speechEl.textContent = passed ? activeCareerEvent.pass_msg : activeCareerEvent.fail_msg;
            }
            if (rewardBadge) {
              rewardBadge.textContent = passed ? "✓ ТЕСТ ПРОЙДЕН — ПОВЫШЕНИЕ ДО JUNIOR TEST DRIVER" : "✗ ТЕСТ НЕ ПРОЙДЕН — ВРЕМЯ ПРЕВЫШЕНО";
              rewardBadge.style.color = passed ? "#22c55e" : "#ef4444";
            }
          } else {
            if (speechEl) speechEl.style.display = "none";
            if (rewardBadge) {
              rewardBadge.textContent = passed ? "✓ 1-Е МЕСТО — НАГРАДА: +4 500 CR" : `ПОЗИЦИЯ P${pos} — ЗАЕЗД ЗАВЕРШЁН`;
              rewardBadge.style.color = passed ? "#22c55e" : "#d3bd83";
            }
          }

          if (typeof shell_apply_event_result === "function" && currentProfile) {
            try {
              const resJson = shell_apply_event_result(
                JSON.stringify(currentProfile),
                activeCareerEvent.id,
                lapTime,
                pos
              );
              currentProfile = JSON.parse(resJson);
              saveProfile();
            } catch (e) {
              console.error("WASM event result apply error:", e);
            }
          } else if (currentProfile) {
            if (activeCareerEvent.is_factory && passed) {
              if (currentProfile.factory_rank === 0) currentProfile.factory_rank = 1;
              if (!currentProfile.factory_completed_missions.includes("0M01")) {
                currentProfile.factory_completed_missions.push("0M01");
              }
            } else if (!activeCareerEvent.is_factory && passed) {
              currentProfile.credits += 4500;
            }
            saveProfile();
          }
        } else if (!activeCareerEvent && !eventFinishedHandled) {
          eventFinishedHandled = true;
          if (pos === 1) soundManager.playPass();
          else soundManager.playFail();
        }
      }
    }

    if (isRacingActive || Math.abs(speed) > 0.1 || throttle !== 0 || steer !== 0 || handbrake) {
      queueFrame();
    }
    return;
  }

  let inForward = 0;
  let inRight = 0;
  let inZoom = 0;

  if (activeKeys.has("KeyW") || activeKeys.has("ArrowUp")) inForward += 1;
  if (activeKeys.has("KeyS") || activeKeys.has("ArrowDown")) inForward -= 1;
  if (activeKeys.has("KeyA") || activeKeys.has("ArrowLeft")) inRight -= 1;
  if (activeKeys.has("KeyD") || activeKeys.has("ArrowRight")) inRight += 1;
  if (activeKeys.has("KeyQ") || activeKeys.has("Minus") || activeKeys.has("NumpadSubtract")) inZoom += 1;
  if (activeKeys.has("KeyE") || activeKeys.has("Equal") || activeKeys.has("NumpadAdd")) inZoom -= 1;

  // Normalize diagonal movement
  const len = Math.hypot(inForward, inRight);
  if (len > 0.001) {
    inForward /= len;
    inRight /= len;
  }

  const speedMult = activeKeys.has("ShiftLeft") || activeKeys.has("ShiftRight") ? 2.5 : 1.0;
  inForward *= speedMult;
  inRight *= speedMult;
  inZoom *= speedMult;

  // Exponential smooth damping (decay = 12.0 gives responsive yet smooth inertia)
  const decay = 12.0;
  const factor = 1.0 - Math.exp(-decay * dt);

  velForward += (inForward - velForward) * factor;
  velRight += (inRight - velRight) * factor;
  velZoom += (inZoom - velZoom) * factor;

  // Snap to 0 when near rest and no input
  if (Math.abs(velForward) < 0.0005 && inForward === 0) velForward = 0;
  if (Math.abs(velRight) < 0.0005 && inRight === 0) velRight = 0;
  if (Math.abs(velZoom) < 0.0005 && inZoom === 0) velZoom = 0;

  if (velForward !== 0 || velRight !== 0) {
    viewer.move_ground(velForward * dt * 2.5, velRight * dt * 2.5);
    needsFrame = true;
  }
  if (velZoom !== 0) {
    viewer.zoom(velZoom * dt * 450.0);
    needsFrame = true;
  }
}

function resizeCanvas() {
  const rect = canvas.getBoundingClientRect();
  const scale = window.devicePixelRatio || 1;
  const width = Math.max(1, Math.round(rect.width * scale));
  const height = Math.max(1, Math.round(rect.height * scale));
  if (canvas.width !== width || canvas.height !== height) {
    canvas.width = width;
    canvas.height = height;
    if (viewer) {
      viewer.resize(width, height);
    }
    queueFrame();
  }
}

function animate(now = 0) {
  resizeCanvas();

  if (document.hasFocus() && !document.hidden && lastTime > 0 && now > 0) {
    const dt = Math.min((now - lastTime) / 1000, 0.1);
    updateNavigation(dt);
  }
  lastTime = now;

  if (viewer && needsFrame) {
    try {
      viewer.render();
      needsFrame = false;
    } catch (error) {
      setStatus(error instanceof Error ? error.message : String(error));
    }
  }
  requestAnimationFrame(animate);
}

async function boot() {
  loadStoredProfile();
  updateOptions();
  if (!navigator.gpu) {
    setStatus("WebGPU недоступен. Нужен браузер с поддержкой WebGPU.");
    loadButton.disabled = true;
    return;
  }
  try {
    await init();
    resizeCanvas();
    viewer = await create_viewer(canvas);
    setStatus("WebGPU готов.");
    animate();

    const hasGame = await checkLocalGame();
    if (hasGame && !useCustomFiles) {
      await loadTarget();
    } else {
      setStatus("WebGPU готов. Выберите локальные файлы игры.");
    }
  } catch (error) {
    setStatus(error instanceof Error ? error.message : String(error));
    loadButton.disabled = true;
  }
}

boot();
