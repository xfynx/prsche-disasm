import init, { create_viewer } from "./package/viewer_impl.js";

const canvas = document.querySelector("#viewport");
const folderInput = document.querySelector("#folderInput");
const fileInput = document.querySelector("#fileInput");
const carInput = document.querySelector("#carInput");
const carOptions = document.querySelector("#carOptions");
const loadButton = document.querySelector("#loadButton");
const resetButton = document.querySelector("#resetButton");
const statusLine = document.querySelector("#status");
const summary = document.querySelector("#summary");

let viewer = null;
let selectedFiles = [];
let dragging = false;
let lastPointer = null;
let needsFrame = true;

function setStatus(text) {
  statusLine.textContent = text;
}

function queueFrame() {
  needsFrame = true;
}

function selectedName(file) {
  return file.webkitRelativePath || file.name;
}

function rememberFiles(files) {
  selectedFiles = Array.from(files || []);
  const names = new Set(selectedFiles.map(file => selectedName(file).split(/[\\/]/).pop().toLowerCase()));
  const cars = [...names].filter(name => name.endsWith(".crp") && names.has(name.slice(0, -4) + ".tpg"))
    .map(name => name.slice(0, -4)).sort();
  carOptions.replaceChildren(...cars.map(car => {
    const option = document.createElement("option");
    option.value = car;
    return option;
  }));
  if (cars.length && !cars.includes(carInput.value.trim().toLowerCase())) carInput.value = cars[0];
  const count = selectedFiles.length;
  setStatus(count ? `Выбрано файлов: ${count}. Моделей: ${cars.length}.` : "Файлы не выбраны.");
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
    const names = [];
    const bytes = [];
    const car = carInput.value.trim().toLowerCase() || "356a";
    for (const file of selectedFiles) {
      const basename = selectedName(file).split(/[\\/]/).pop().toLowerCase();
      if (![`${car}.crp`, `${car}.tpg`, `${car}.clr`].includes(basename) && !basename.endsWith(".fsh")) continue;
      names.push(selectedName(file));
      bytes.push(new Uint8Array(await file.arrayBuffer()));
    }
    const text = viewer.load(names, bytes, car);
    summary.textContent = text;
    setStatus("Модель загружена.");
    queueFrame();
  } catch (error) {
    setStatus(error instanceof Error ? error.message : String(error));
  } finally {
    loadButton.disabled = false;
  }
});

resetButton.addEventListener("click", () => {
  if (viewer) {
    viewer.reset_camera();
    queueFrame();
  }
});

canvas.addEventListener("pointerdown", (event) => {
  dragging = true;
  lastPointer = { x: event.clientX, y: event.clientY };
  canvas.setPointerCapture(event.pointerId);
});

canvas.addEventListener("pointerup", (event) => {
  dragging = false;
  lastPointer = null;
  canvas.releasePointerCapture(event.pointerId);
});

canvas.addEventListener("pointercancel", () => {
  dragging = false;
  lastPointer = null;
});

canvas.addEventListener("pointermove", (event) => {
  if (!dragging || !viewer || !lastPointer) {
    return;
  }
  const dx = event.clientX - lastPointer.x;
  const dy = event.clientY - lastPointer.y;
  lastPointer = { x: event.clientX, y: event.clientY };
  viewer.orbit(dx, dy);
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
  if (event.code === "KeyR" && viewer) {
    viewer.reset_camera();
    queueFrame();
  }
  if (event.code === "KeyC" && viewer) {
    viewer.cycle_paint_color();
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
