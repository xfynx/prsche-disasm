// DOM-state regression tests; these do not replace a browser/GPU visual run.
import assert from "node:assert/strict";
import { readFileSync } from "node:fs";
import vm from "node:vm";

class Element {
  constructor() {
    this.listeners = new Map();
    this.attributes = new Map();
    this.classes = new Set();
    this.classList = {
      toggle: (name, enabled) => enabled ? this.classes.add(name) : this.classes.delete(name),
      add: (name) => this.classes.add(name),
      remove: (name) => this.classes.delete(name),
    };
    this.style = {};
    this.hidden = true;
    this.value = "track";
    this.children = [];
  }
  addEventListener(type, callback) { this.listeners.set(type, callback); }
  setAttribute(name, value) { this.attributes.set(name, value); }
  focus() { focused = this; }
  dispatch(type, event = {}) { this.listeners.get(type)?.(event); }
  replaceChildren(...children) { this.children = children; }
  appendChild(child) { this.children.push(child); }
}
class Input extends Element {}
class Textarea extends Element {}
class Select extends Element {}
const elements = new Map();
let focused;
const element = (id) => {
  if (!elements.has(id)) elements.set(id, new Element());
  return elements.get(id);
};
const document = new Element();
document.body = new Element();
document.querySelector = element;
document.querySelectorAll = () => [];
document.createElement = () => new Element();
const window = new Element();
const context = vm.createContext({
  document, window, console,
  HTMLInputElement: Input, HTMLTextAreaElement: Textarea, HTMLSelectElement: Select,
});
const source = readFileSync(new URL("main.js", import.meta.url), "utf8")
  .replace(/^import .*;\r?\n/, "")
  .replace(/\bboot\(\);\s*$/, "");
vm.runInContext(source + `\n globalThis.testApi = {
  setViewer: value => viewer = value,
  activeKeys, syncTourButton, updateNavigation,
  primeMotion: () => { velForward = 3; velRight = 2; velZoom = 1; },
  motion: () => [velForward, velRight, velZoom],
};`, context);
let driving = false;
let lastControls;
context.testApi.setViewer({
  is_drive_mode: () => driving,
  has_car: () => true,
  toggle_camera_mode: () => driving = !driving,
  update_car: (...args) => lastControls = args,
  get_car_speed: () => 0,
  get_car_gear: () => 0,
  get_car_rpm: () => 0,
});
context.testApi.syncTourButton();
assert.equal(element("#hud").hidden, true, "HUD hidden before driving");
element("#tourButton").dispatch("click");
assert.equal(driving, true);
assert.equal(document.body.classes.has("menu-hidden"), true);
assert.equal(element("#hud").hidden, false);
assert.equal(focused, element("#viewport"));
// Exercise actual keyboard listeners and navigation, including both key layouts.
const key = (type, code) => window.dispatch(type, {
  code, target: new Element(), repeat: false, preventDefault() {},
});
for (const [gas, left, right] of [["KeyW", "KeyA", "KeyD"], ["ArrowUp", "ArrowLeft", "ArrowRight"]]) {
  for (const [turn, sign] of [[left, -1], [right, 1]]) {
    key("keydown", gas);
    key("keydown", turn);
    context.testApi.updateNavigation(1 / 60);
    assert.deepEqual(Array.from(lastControls), [1 / 60, 1, sign, false]);
    key("keyup", gas);
    key("keyup", turn);
    context.testApi.updateNavigation(1 / 60);
    assert.deepEqual(Array.from(lastControls), [1 / 60, 0, 0, false]);
  }
}
for (const reverse of ["KeyS", "ArrowDown"]) {
  key("keydown", reverse);
  key("keydown", "KeyA");
  key("keydown", "KeyD");
  key("keydown", "Space");
  context.testApi.updateNavigation(1 / 60);
  assert.deepEqual(Array.from(lastControls), [1 / 60, -1, 0, true]);
  window.dispatch("blur");
  context.testApi.updateNavigation(1 / 60);
  assert.deepEqual(Array.from(lastControls), [1 / 60, 0, 0, false]);
}
window.dispatch("keydown", { code: "KeyH", target: new Element(), repeat: false });
assert.equal(element("#hud").hidden, true);
window.dispatch("keydown", { code: "Escape", target: new Element(), repeat: false, preventDefault() {} });
assert.equal(document.body.classes.has("menu-hidden"), false);
assert.equal(element("#menuButton").attributes.get("aria-expanded"), "true");
window.dispatch("keydown", { code: "KeyW", target: new Select(), repeat: false });
assert.equal(context.testApi.activeKeys.size, 0, "selectors must not drive");
window.dispatch("keydown", { code: "KeyW", target: new Element(), repeat: false });
assert.equal(context.testApi.activeKeys.has("KeyW"), true);
context.testApi.primeMotion();
window.dispatch("blur");
assert.equal(context.testApi.activeKeys.size, 0);
assert.deepEqual(Array.from(context.testApi.motion()), [0, 0, 0]);
element("#detailsButton").dispatch("click");
assert.equal(element("#summary").hidden, false);
element("#detailsButton").dispatch("click");
assert.equal(element("#summary").hidden, true);
element("#tourButton").dispatch("click");
assert.equal(driving, false);
assert.equal(document.body.classes.has("menu-hidden"), false);
assert.equal(element("#hud").hidden, true);

// 009 Shell UI & Modals regression checks
element("#soundBtn").dispatch("click");
assert.equal(element("#soundBtn").classes.has("active"), true, "Sound button toggles active");
element("#soundBtn").dispatch("click");
assert.equal(element("#soundBtn").classes.has("active"), false, "Sound button toggles off");

element("#careerEvolutionBtn").dispatch("click");
assert.equal(element("#eventBriefingModal").hidden, false, "Evolution briefing opens");
element("#briefingCancelBtn").dispatch("click");
assert.equal(element("#eventBriefingModal").hidden, true, "Evolution briefing cancels");

element("#careerFactoryBtn").dispatch("click");
assert.equal(element("#factoryMissionsModal").hidden, false, "Factory missions ladder opens");
element("#factoryModalCloseBtn").dispatch("click");
assert.equal(element("#factoryMissionsModal").hidden, true, "Factory missions ladder closes");

element("#profileBtn").dispatch("click");
assert.equal(element("#profileModal").hidden, false, "Profile modal opens");
element("#profileModalCloseBtn").dispatch("click");
assert.equal(element("#profileModal").hidden, true, "Profile modal closes");

// 010 Dealership & Parts Tuning Shop checks
element("#dealershipBtn").dispatch("click");
assert.equal(element("#dealershipModal").hidden, false, "Dealership modal opens");
element("#dealershipCloseBtn").dispatch("click");
assert.equal(element("#dealershipModal").hidden, true, "Dealership modal closes");

element("#partsShopBtn").dispatch("click");
assert.equal(element("#partsShopModal").hidden, false, "Parts shop modal opens");
element("#partsShopCloseBtn").dispatch("click");
assert.equal(element("#partsShopModal").hidden, true, "Parts shop modal closes");

// Input field typing isolation
window.dispatch("keydown", { code: "KeyW", target: new Input(), repeat: false });
assert.equal(context.testApi.activeKeys.size, 0, "Inputs must not capture drive keys");

console.log("UI state: drive/menu/HUD/focus/selector/diagnostics/shell/modals checks passed");

