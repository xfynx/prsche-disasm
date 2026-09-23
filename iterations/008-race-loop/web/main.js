import init, { create_viewer } from "./package/viewer_impl.js";

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
      setStatus("Гонка перезапущена / старт на решётке.");
      queueFrame();
    }
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
        countdownBanner.hidden = false;
        const remaining = viewer.get_countdown_remaining();
        if (countdownText) {
          countdownText.classList.remove("go");
          if (remaining > 2.0) countdownText.textContent = "3";
          else if (remaining > 1.0) countdownText.textContent = "2";
          else countdownText.textContent = "1";
        }
      } else if (phase === 2 && lastPhase === 1) {
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
        if (resultsSubtitle) resultsSubtitle.textContent = `Позиция: P${pos} из ${total}`;
        if (resultsLapTime) resultsLapTime.textContent = formatRaceTime(viewer.get_current_lap_time());
        if (resultsBestTime) resultsBestTime.textContent = formatRaceTime(viewer.get_best_lap_time());
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
