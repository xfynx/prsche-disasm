import init, { create_viewer } from "./package/viewer_impl.js";

const canvas = document.querySelector("#viewport");
const folderInput = document.querySelector("#folderInput");
const fileInput = document.querySelector("#fileInput");
const modeSelect = document.querySelector("#modeSelect");
const targetLabel = document.querySelector("#targetLabel");
const targetInput = document.querySelector("#targetInput");
const targetOptions = document.querySelector("#targetOptions");
const loadButton = document.querySelector("#loadButton");
const resetButton = document.querySelector("#resetButton");
const statusLine = document.querySelector("#status");
const summary = document.querySelector("#summary");

let viewer = null;
let selectedFiles = [];
let dragging = false;
let lastPointer = null;
let needsFrame = true;

let availableCars = [];
let availableTracks = [];

function setStatus(text) {
  statusLine.textContent = text;
}

function queueFrame() {
  needsFrame = true;
}

function selectedName(file) {
  return file.webkitRelativePath || file.name;
}

function updateOptions() {
  const isTrack = modeSelect.value === "track";
  targetLabel.textContent = isTrack ? "Трасса" : "Авто";
  const list = isTrack ? availableTracks : availableCars;
  targetOptions.replaceChildren(
    ...list.map(item => {
      const option = document.createElement("option");
      option.value = item;
      return option;
    })
  );
  if (list.length && !list.includes(targetInput.value.trim().toLowerCase())) {
    targetInput.value = list[0];
  } else if (!list.length) {
    targetInput.value = isTrack ? "skidpad" : "356a";
  }
}

modeSelect.addEventListener("change", () => {
  updateOptions();
  setStatus(`Режим: ${modeSelect.value === "track" ? "Трасса" : "Автомобиль"}.`);
});

function rememberFiles(files) {
  selectedFiles = Array.from(files || []);
  const basenames = new Set(
    selectedFiles.map(file => selectedName(file).split(/[\\/]/).pop().toLowerCase())
  );
  availableCars = [...basenames]
    .filter(name => name.endsWith(".crp") && basenames.has(name.slice(0, -4) + ".tpg"))
    .map(name => name.slice(0, -4))
    .sort();

  availableTracks = [...basenames]
    .filter(name => name.endsWith(".crp") && !basenames.has(name.slice(0, -4) + ".tpg"))
    .map(name => name.slice(0, -4))
    .sort();

  updateOptions();
  const count = selectedFiles.length;
  setStatus(
    count
      ? `Выбрано файлов: ${count}. Трасс: ${availableTracks.length}, Авто: ${availableCars.length}.`
      : "Файлы не выбраны."
  );
}

folderInput.addEventListener("change", () => rememberFiles(folderInput.files));
fileInput.addEventListener("change", () => rememberFiles(fileInput.files));

loadButton.addEventListener("click", async () => {
  if (!viewer) {
    setStatus("WebGPU еще не готов.");
    return;
  }
  if (selectedFiles.length === 0) {
    setStatus("Выберите папку игры или файлы.");
    return;
  }
  loadButton.disabled = true;
  setStatus("Чтение локальных файлов...");
  try {
    const isTrack = modeSelect.value === "track";
    const target = targetInput.value.trim().toLowerCase() || (isTrack ? "skidpad" : "356a");
    const names = [];
    const bytes = [];

    if (isTrack) {
      for (const file of selectedFiles) {
        const fullPath = selectedName(file).replace(/\\/g, "/").toLowerCase();
        // Skip sky directories to prevent duplicate texture archive clash
        if (fullPath.includes("/sky/") || fullPath.includes("/sky new/")) continue;
        const basename = fullPath.split("/").pop();
        if (
          ![`${target}.crp`, `${target}.fsh`, `${target}.env`, `${target}.edg`, `${target}.map`, `${target}.jnc`].includes(basename)
        ) {
          continue;
        }
        names.push(selectedName(file));
        bytes.push(new Uint8Array(await file.arrayBuffer()));
      }
      const text = viewer.load_track(names, bytes, target);
      summary.textContent = text;
      setStatus(`Трасса ${target} загружена.`);
    } else {
      for (const file of selectedFiles) {
        const basename = selectedName(file).split(/[\\/]/).pop().toLowerCase();
        if (![`${target}.crp`, `${target}.tpg`, `${target}.clr`].includes(basename) && !basename.endsWith(".fsh")) {
          continue;
        }
        names.push(selectedName(file));
        bytes.push(new Uint8Array(await file.arrayBuffer()));
      }
      const text = viewer.load(names, bytes, target);
      summary.textContent = text;
      setStatus(`Авто ${target} загружено.`);
    }
    queueFrame();
  } catch (error) {
    setStatus(error instanceof Error ? error.message : String(error));
  } finally {
    loadButton.disabled = false;
  }
});

let panMode = false;

canvas.addEventListener("contextmenu", (event) => {
  event.preventDefault();
});

resetButton.addEventListener("click", () => {
  if (viewer) {
    viewer.reset_camera();
    queueFrame();
  }
});

canvas.addEventListener("pointerdown", (event) => {
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

window.addEventListener("keydown", (event) => {
  if (event.target instanceof HTMLInputElement || event.target instanceof HTMLTextAreaElement) return;
  if (!viewer) return;
  const speedMult = event.shiftKey ? 3.0 : 1.0;
  if (event.code === "KeyR") {
    viewer.reset_camera();
    queueFrame();
  } else if (event.code === "KeyC") {
    viewer.cycle_paint_color();
    queueFrame();
  } else if (event.code === "KeyW" || event.code === "ArrowUp") {
    viewer.move_ground(speedMult, 0);
    queueFrame();
  } else if (event.code === "KeyS" || event.code === "ArrowDown") {
    viewer.move_ground(-speedMult, 0);
    queueFrame();
  } else if (event.code === "KeyA" || event.code === "ArrowLeft") {
    viewer.move_ground(0, -speedMult);
    queueFrame();
  } else if (event.code === "KeyD" || event.code === "ArrowRight") {
    viewer.move_ground(0, speedMult);
    queueFrame();
  } else if (event.code === "KeyQ" || event.code === "Minus" || event.code === "NumpadSubtract") {
    viewer.zoom(120 * speedMult);
    queueFrame();
  } else if (event.code === "KeyE" || event.code === "Equal" || event.code === "NumpadAdd") {
    viewer.zoom(-120 * speedMult);
    queueFrame();
  }
});

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

function animate() {
  resizeCanvas();
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
  if (!navigator.gpu) {
    setStatus("WebGPU недоступен. Нужен браузер с поддержкой WebGPU.");
    loadButton.disabled = true;
    return;
  }
  try {
    await init();
    resizeCanvas();
    viewer = await create_viewer(canvas);
    setStatus("WebGPU готов. Выберите локальные файлы игры.");
    animate();
  } catch (error) {
    setStatus(error instanceof Error ? error.message : String(error));
    loadButton.disabled = true;
  }
}

boot();
