// Usage: node verify-browser.cjs <playwright-core directory> <URL> <output directory>
const { chromium } = require(process.argv[2]);
const fs = require('node:fs');
const path = require('node:path');
const assert = require('node:assert/strict');
const { spawn, spawnSync } = require('node:child_process');

(async () => {
  const output = path.resolve(process.argv[4]);
  fs.mkdirSync(output, { recursive: true });
  let server;
  let ready;
  let url = process.argv[3];
  if (url === 'auto') {
    const root = path.resolve(__dirname, '../../..');
    const python = spawnSync('py', ['-3', '-c', 'import sys; print(sys.executable)'], { encoding: 'utf8', windowsHide: true });
    if (python.status !== 0) throw new Error(python.stderr || 'Python discovery failed');
    ready = path.join(output, `server-ready-${Date.now()}.json`);
    server = spawn(python.stdout.trim(), [path.join(root, 'scripts/serve-web.py'), '--iteration', '011-factory-driver', '--port', '0', '--ready-file', ready], { cwd: root, windowsHide: true, stdio: 'ignore' });
    try {
      for (let attempt = 0; !fs.existsSync(ready); attempt++) {
        if (server.exitCode !== null || attempt > 100) throw new Error('Owned test server failed');
        await new Promise(resolve => setTimeout(resolve, 100));
      }
      const info = JSON.parse(fs.readFileSync(ready, 'utf8'));
      assert.equal(info.pid, server.pid);
      url = `http://127.0.0.1:${info.port}/`;
    } catch (error) { server.kill(); throw error; }
  }
  let browser;
  try {
  // Full Chromium: headless shell exposes no adapter here.
  browser = await chromium.launch({ channel: 'chromium', headless: false });
  const page = await browser.newPage({ viewport: { width: 1280, height: 800 } });
  // Harness-only access to read-only telemetry; no test global in shipped main.js.
  await page.route('**/main.js', async route => {
    const response = await route.fetch();
    await route.fulfill({ response, body: (await response.text()) + '\n globalThis.readDriveTestState = () => ({ pose: Array.from(viewer.get_car_pose()), sim: viewer.is_sim_mode(), phase: viewer.get_race_phase() });' });
  });
  const errors = [];
  const checks = [];
  page.on('pageerror', error => errors.push(String(error)));
  page.on('console', message => {
    if (message.type() === 'error') errors.push(message.text());
  });
  const screenshot = name => page.screenshot({ path: path.join(output, name), fullPage: true });
  const loaded = name => page.waitForFunction(name => {
    const status = document.querySelector('#status').textContent;
    return status.includes(`"${name}" загружен`) && !document.querySelector('#targetSelect').disabled;
  }, name, { timeout: 60000 });
  try {
    await page.goto(url);
    console.log('page loaded; waiting for skidpad');
    await loaded('skidpad');
    checks.push('skidpad boot');
    console.log('skidpad loaded');
    assert.equal(await page.locator('#hud').isVisible(), false);
    assert.equal(await page.locator('#summary').isVisible(), false);
    await screenshot('web-menu.png');
    await page.locator('#tourButton').click();
    assert.equal(await page.locator('#menu').isVisible(), false);
    assert.equal(await page.locator('#hud').isVisible(), true);
    const waitForStart = () => page.waitForFunction(() => [0, 2].includes(readDriveTestState().phase), null, { timeout: 15000 });
    for (const mode of ['sim', 'arcade']) {
      if (mode === 'arcade') await page.keyboard.press('m');
      assert.equal(await page.evaluate(() => readDriveTestState().sim), mode === 'sim');
      for (const [key, sign, label] of [['a', -1, 'left'], ['ArrowRight', 1, 'right']]) {
        await page.keyboard.press('r');
        await waitForStart();
        await page.keyboard.down('w');
        await page.waitForTimeout(1200);
        const before = await page.evaluate(() => readDriveTestState().pose);
        await page.keyboard.down(key);
        await page.waitForTimeout(400);
        await page.keyboard.up(key);
        await page.keyboard.up('w');
        const after = await page.evaluate(() => readDriveTestState().pose);
        const headingRight = after[3] * -before[5] + after[5] * before[3];
        assert.ok(headingRight * sign > 0.001, `${mode} ${label}: headingRight=${headingRight}`);
        checks.push(`${mode} ${label} headingRight=${headingRight.toFixed(4)}`);
        await screenshot(`web-${mode}-${label}.png`);
      }
    }
    await page.keyboard.press('r');
    await waitForStart();
    await page.keyboard.down('w');
    await page.waitForTimeout(1800);
    await page.keyboard.down('d');
    await page.waitForTimeout(350);
    await page.keyboard.up('d');
    await page.keyboard.up('w');
    const speed = Number(await page.locator('#speedValue').textContent());
    assert.ok(speed > 5, `driving speed ${speed}`);
    checks.push(`drive + simultaneous throttle/steer; speed=${speed}`);
    await screenshot('web-drive.png');
    await page.keyboard.press('h');
    assert.equal(await page.locator('#hud').isVisible(), false);
    await screenshot('web-hidden-hud.png');
    await page.keyboard.press('Escape');
    assert.equal(await page.locator('#menu').isVisible(), true);
    checks.push('Esc restores menu; H hides HUD');
    await page.locator('#targetSelect').selectOption('alps');
    await loaded('alps');
    await page.locator('#detailsButton').click();
    assert.equal(await page.locator('#summary').isVisible(), true);
    await screenshot('web-alps.png');
    await page.locator('#detailsButton').click();
    await page.locator('#modeSelect').selectOption('car');
    await page.waitForFunction(() => !document.querySelector('#targetSelect').disabled);
    await page.locator('#targetSelect').selectOption('356a');
    await loaded('356a');
    assert.equal(await page.locator('#hud').isVisible(), false);
    await page.keyboard.press('Escape');
    await screenshot('web-car.png');
    await page.keyboard.press('Escape');
    checks.push('alps/car catalog switch; diagnostic panel');
    await page.locator('#modeSelect').selectOption('track');
    await page.waitForFunction(() => !document.querySelector('#targetSelect').disabled);
    await page.locator('#targetSelect').selectOption('skidpad');
    await loaded('skidpad');
    await page.locator('#tourButton').click();
    // Losing focus must release keys; return to the canvas without a new keydown.
    await page.keyboard.down('w');
    await page.waitForTimeout(400);
    const other = await browser.newPage();
    await other.bringToFront();
    await other.waitForTimeout(200);
    await page.bringToFront();
    await page.keyboard.up('w');
    await page.keyboard.press('h');
    const before = Number(await page.locator('#speedValue').textContent());
    await page.waitForTimeout(500);
    const after = Number(await page.locator('#speedValue').textContent());
    assert.ok(after <= before + 1, `focus release coast ${before} -> ${after}`);
    checks.push(`focus release ${before} -> ${after}`);
    await other.close();
    assert.deepEqual(errors, []);
    fs.writeFileSync(path.join(output, 'browser-check.json'), JSON.stringify({ browser: browser.version(), iteration: '009-game-shell', checks, errors }, null, 2));
    console.log(JSON.stringify({ checks, errors }));
  } catch (error) {
    await screenshot('web-failure.png').catch(() => {});
    fs.writeFileSync(path.join(output, 'browser-failure.json'), JSON.stringify({ checks, errors, error: String(error), status: await page.locator('#status').textContent().catch(() => '') }, null, 2));
    throw error;
  } finally {
    await browser.close();
  }
  } finally {
    if (server) server.kill();
    if (ready && fs.existsSync(ready)) {
      try { fs.unlinkSync(ready); } catch {}
    }
  }
})().catch(error => { console.error(error); process.exitCode = 1; });
