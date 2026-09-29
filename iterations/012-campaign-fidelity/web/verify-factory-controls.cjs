// Focused input regression: node verify-factory-controls.cjs <playwright> <output>
const { chromium } = require(process.argv[2]);
const fs = require('node:fs');
const path = require('node:path');
const { spawn, spawnSync } = require('node:child_process');
const assert = require('node:assert/strict');

(async () => {
  const root = path.resolve(__dirname, '../../..');
  const output = path.resolve(process.argv[3]);
  fs.mkdirSync(output, { recursive: true });
  const python = spawnSync('py', ['-3', '-c', 'import sys; print(sys.executable)'], { encoding: 'utf8', windowsHide: true });
  if (python.status !== 0) throw new Error(python.error || python.stderr || 'Python discovery failed');
  const ready = path.join(output, `factory-server-${Date.now()}.json`);
  const server = spawn(python.stdout.trim(), [path.join(root, 'scripts/serve-web.py'), '--iteration', '012-campaign-fidelity', '--port', '0', '--ready-file', ready], { cwd: root, windowsHide: true, stdio: 'ignore' });
  let browser;
  try {
    for (let i = 0; !fs.existsSync(ready); i++) {
      if (server.exitCode !== null || i > 100) throw new Error('Owned server did not start');
      await new Promise(resolve => setTimeout(resolve, 100));
    }
    const info = JSON.parse(fs.readFileSync(ready, 'utf8'));
    assert.equal(info.pid, server.pid);
    browser = await chromium.launch({ channel: 'chromium', headless: true });
    const page = await browser.newPage({ viewport: { width: 1280, height: 800 } });
    const errors = [];
    page.on('pageerror', error => errors.push(String(error)));
    await page.route('**/main.js', async route => {
      const response = await route.fetch();
      await route.fulfill({ response, body: (await response.text()) + `
globalThis.installFactoryProbe = () => {
  let lastInput = null;
  const update = viewer.update_car.bind(viewer);
  viewer.update_car = (...args) => { lastInput = args; return update(...args); };
  globalThis.readFactoryState = () => ({
    time: performance.now(), focus: document.hasFocus(), hidden: document.hidden,
    activeElement: document.activeElement?.id, keys: [...activeKeys], menuVisible,
    input: lastInput, speed: viewer.get_car_speed(), gear: viewer.get_car_gear(),
    pose: Array.from(viewer.get_car_pose()), physics: Array.from(viewer.get_car_physics_state()), phase: viewer.get_race_phase(),
    elapsed: viewer.get_mission_elapsed_time(), reached: viewer.get_mission_goal_reached(),
    timedOut: viewer.get_mission_timed_out()
  });
  globalThis.factoryTrace = [];
  globalThis.factoryTimer = setInterval(() => factoryTrace.push(readFactoryState()), 100);
};
` });
    });
    await page.goto(`http://127.0.0.1:${info.port}/`);
    await page.waitForFunction(() => document.querySelector('#status').textContent.includes('"skidpad" загружен') && !document.querySelector('#targetSelect').disabled, null, { timeout: 60000 });
    await page.evaluate(() => installFactoryProbe());
    await page.locator('#careerFactoryBtn').click();
    await page.locator('#factoryMissionsGrid .cup-card:first-child button').click();
    await page.locator('#briefingStartBtn').click();
    await page.waitForFunction(() => document.querySelector('#status').textContent.includes('Карьерный заезд начат:'), null, { timeout: 30000 });
    const results = [];
    for (let attempt = 1; attempt <= 8; attempt++) {
      await page.keyboard.press('r');
      await page.evaluate(() => { factoryTrace.length = 0; });
      let error;
      let stage = 'forward';
      try {
        await page.keyboard.down('w');
        await page.waitForFunction(() => readFactoryState().speed > 15, null, { timeout: 12000 });
        await page.keyboard.up('w');
        stage = 'reverse';
        await page.keyboard.down('s');
        await page.waitForFunction(() => readFactoryState().gear < 0 && readFactoryState().speed < -3, null, { timeout: 12000 });
        await page.keyboard.up('s');
        stage = 'return-forward';
        await page.keyboard.down('w');
        await page.waitForFunction(() => readFactoryState().gear > 0 && readFactoryState().speed > 3, null, { timeout: 12000 });
      } catch (failure) { error = String(failure); }
      const trace = await page.evaluate(() => factoryTrace);
      const state = await page.evaluate(() => readFactoryState());
      await page.keyboard.up('w');
      await page.keyboard.up('s');
      fs.writeFileSync(path.join(output, `factory-trace-${attempt}.json`), JSON.stringify({ stage, error, state, trace }, null, 2));
      if (error) await page.screenshot({ path: path.join(output, `factory-failure-${attempt}.png`) });
      if (attempt === 8) await page.screenshot({ path: path.join(output, 'factory-controls-final.png') });
      results.push({ attempt, stage, error, state });
      console.log(JSON.stringify({ attempt, stage, passed: !error, keys: state.keys, input: state.input, speed: state.speed, elapsed: state.elapsed, focus: state.focus }));
    }
    await page.evaluate(() => clearInterval(factoryTimer));
    fs.writeFileSync(path.join(output, 'factory-check.json'), JSON.stringify({ browser: browser.version(), results, errors }, null, 2));
    if (errors.length || results.some(result => result.error)) process.exitCode = 1;
  } finally {
    if (browser) await browser.close();
    server.kill();
    if (fs.existsSync(ready)) fs.unlinkSync(ready);
  }
})().catch(error => { console.error(error); process.exitCode = 1; });
