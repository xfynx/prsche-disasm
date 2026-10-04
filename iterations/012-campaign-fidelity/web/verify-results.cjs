// Synthetic terminal-state fixture for the result UI. This is not a playthrough or fidelity acceptance.
// node verify-results.cjs <playwright-package-path> <output-directory>
const { chromium } = require(process.argv[2]);
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const { spawn, spawnSync } = require('node:child_process');

const root = path.resolve(__dirname, '../../..');
const output = path.resolve(process.argv[3]);
fs.mkdirSync(output, { recursive: true });

const fixture = `
// Harness only: preserve the real viewer and WASM shell; replace terminal getters for one result.
globalThis.resultFixture = (() => {
  let original = null;
  let phase = 0;
  let frames = 0;
  return {
    enable(nextPhase) {
      if (original) throw new Error('fixture already enabled');
      original = viewer;
      phase = nextPhase;
      frames = 0;
      viewer = new Proxy(original, { get(target, key) {
        if (key === 'get_race_phase') return () => { frames++; return phase; };
        if (key === 'get_mission_goal_supported') return () => true;
        if (key === 'get_mission_goal_reached') return () => phase === 4;
        if (key === 'get_mission_elapsed_time') return () => 12;
        if (key === 'get_cone_hits') return () => 0;
        if (key === 'get_player_position') return () => 1;
        const value = Reflect.get(target, key, target);
        return typeof value === 'function' ? value.bind(target) : value;
      }});
      queueFrame();
    },
    disable() { if (original) { viewer = original; original = null; queueFrame(); } },
    frames() { return frames; },
    state() { return {
      phase: viewer?.get_race_phase?.(),
      simName: viewer?.get_car_sim_name?.(),
      mass: viewer?.get_car_sim_mass?.(),
      completed: [...(currentProfile?.factory_driver?.completed_missions || [])],
      current: currentProfile?.factory_driver?.current_mission_code,
      resultOpen: !raceResultsModal.hidden,
      ladderOpen: !document.querySelector('#factoryMissionsModal').hidden,
      briefingOpen: !document.querySelector('#eventBriefingModal').hidden,
      active: activeCareerEvent?.id || null,
      status: document.querySelector('#status').textContent,
    }; }
  };
})();
`;

async function waitFrames(page, count) {
  const start = await page.evaluate(() => resultFixture.frames());
  await page.waitForFunction(n => resultFixture.frames() >= n, start + count, { timeout: 10000 });
}

async function startFactory(page, index) {
  await page.locator('#factoryMissionsGrid .cup-card').nth(index).locator('button').click();
  await page.locator('#eventBriefingModal').waitFor({ state: 'visible' });
  await page.locator('#briefingStartBtn').click();
  await page.waitForFunction(() => document.querySelector('#eventBriefingModal').hidden
    && document.querySelector('#status').textContent.startsWith('Карьерный заезд начат:')
    && resultFixture.state().phase > 0, null, { timeout: 60000 });
}

(async () => {
  const python = spawnSync('py', ['-3', '-c', 'import sys; print(sys.executable)'], { encoding: 'utf8', windowsHide: true });
  if (python.status !== 0) throw new Error(python.error || python.stderr || 'Python discovery failed');
  const ready = path.join(output, `results-server-${Date.now()}.json`);
  const server = spawn(python.stdout.trim(), [path.join(root, 'scripts/serve-web.py'), '--iteration', '012-campaign-fidelity', '--port', '0', '--ready-file', ready], { cwd: root, windowsHide: true, stdio: 'ignore' });
  let browser;
  let page;
  const errors = [];
  const evidence = { fixture: 'synthetic phase 4/5 and mission getters; real WASM shell evaluator, profile storage and UI clicks', checks: [] };
  try {
    for (let i = 0; !fs.existsSync(ready); i++) {
      if (server.exitCode !== null || i > 100) throw new Error('Owned server did not start');
      await new Promise(resolve => setTimeout(resolve, 100));
    }
    const info = JSON.parse(fs.readFileSync(ready, 'utf8'));
    assert.equal(info.pid, server.pid);
    browser = await chromium.launch({ channel: 'chromium', headless: true });
    const context = await browser.newContext({ viewport: { width: 1280, height: 800 } });
    page = await context.newPage();
    page.on('pageerror', error => errors.push(String(error)));
    await page.route('**/main.js', async route => {
      const response = await route.fetch();
      await route.fulfill({ response, body: (await response.text()) + fixture });
    });
    const url = `http://127.0.0.1:${info.port}/`;
    await page.goto(url);
    await page.waitForFunction(() => globalThis.resultFixture && document.querySelector('#status').textContent.includes('"skidpad" загружен') && !document.querySelector('#targetSelect').disabled, null, { timeout: 60000 });
    await page.locator('#careerFactoryBtn').click();
    assert.equal(await page.locator('#factoryMissionsGrid .cup-card').nth(0).locator('button').isEnabled(), true);
    assert.equal(await page.locator('#factoryMissionsGrid .cup-card').nth(1).locator('button').isEnabled(), false);
    await startFactory(page, 0);
    await page.evaluate(() => resultFixture.enable(4));
    await page.locator('#raceResultsModal').waitFor({ state: 'visible' });
    await page.waitForFunction(() => resultFixture.state().completed.includes('0M01'));
    const passed = await page.evaluate(() => resultFixture.state());
    assert.equal(passed.current, '1m01', 'WASM completion unlocks the next Factory mission');
    evidence.checks.push({ name: '0M01 completion', state: passed });
    await page.locator('#raceContinueBtn').click();
    await page.waitForFunction(() => resultFixture.state().ladderOpen);
    await waitFrames(page, 30);
    assert.equal(await page.locator('#raceResultsModal').isVisible(), false, 'result stays dismissed across terminal frames');
    const next = page.locator('#factoryMissionsGrid .cup-card').nth(1);
    assert.equal(await next.locator('button').isEnabled(), true, 'refreshed ladder unlocks 1m01');
    await next.locator('button').click();
    await page.locator('#eventBriefingModal').waitFor({ state: 'visible' });
    await waitFrames(page, 15);
    assert.equal(await page.locator('#raceResultsModal').isVisible(), false, 'briefing has no ghost result');
    evidence.checks.push({ name: 'continue and next briefing', state: await page.evaluate(() => resultFixture.state()) });
    await page.evaluate(() => resultFixture.disable());
    await page.locator('#briefingStartBtn').click();
    await page.waitForFunction(() => [1, 2].includes(resultFixture.state().phase)
      && document.querySelector('#eventBriefingModal').hidden
      && document.querySelector('#status').textContent.startsWith('Карьерный заезд начат: Задание 2:'),
      null, { timeout: 60000 });
    assert.equal(await page.locator('#raceResultsModal').isVisible(), false);
    const started = await page.evaluate(() => resultFixture.state());
    const sourceSim = fs.readFileSync(path.join(root, 'local/game/GameData/Simulation/CarData/boxster25.sim'));
    assert.equal(started.mass, sourceSim.readFloatLE(0x40), 'next mission uses the source Boxster25 SIM');
    evidence.checks.push({ name: 'next real mission started', state: started });
    await page.reload();
    await page.waitForFunction(() => globalThis.resultFixture && document.querySelector('#status').textContent.includes('"skidpad" загружен') && !document.querySelector('#targetSelect').disabled, null, { timeout: 60000 });
    await page.locator('#careerFactoryBtn').click();
    assert.equal(await page.locator('#factoryMissionsGrid .cup-card').nth(1).locator('button').isEnabled(), true, 'progress survives reload');
    const persisted = await page.evaluate(() => resultFixture.state());
    assert.ok(persisted.completed.includes('0M01'));
    assert.equal(persisted.current, '1m01');
    evidence.checks.push({ name: 'same-origin reload', state: persisted });
    await page.screenshot({ path: path.join(output, 'ladder-after-reload.png') });
    await startFactory(page, 0);
    await page.evaluate(() => resultFixture.enable(5));
    await page.locator('#raceResultsModal').waitFor({ state: 'visible' });
    const failed = await page.evaluate(() => resultFixture.state());
    assert.deepEqual(failed.completed, persisted.completed, 'failed retry does not add completion');
    assert.equal(failed.current, persisted.current, 'failed retry does not change unlocked mission');
    await page.locator('#raceContinueBtn').click();
    await page.waitForFunction(() => resultFixture.state().ladderOpen);
    await waitFrames(page, 30);
    assert.equal(await page.locator('#raceResultsModal').isVisible(), false, 'failed result stays dismissed');
    await page.locator('#factoryMissionsGrid .cup-card').first().locator('button').click();
    await page.locator('#eventBriefingModal').waitFor({ state: 'visible' });
    await waitFrames(page, 15);
    assert.equal(await page.locator('#raceResultsModal').isVisible(), false, 'retry briefing has no ghost result');
    await page.evaluate(() => resultFixture.disable());
    evidence.checks.push({ name: 'phase 5 dismiss and retry briefing', state: failed });
    assert.deepEqual(errors, [], 'no browser page errors');
    console.log('Synthetic result regression passed: WASM completion, Continue latch, next mission, reload');
  } catch (error) {
    evidence.failure = String(error);
    if (page) {
      evidence.failureState = await page.evaluate(() => globalThis.resultFixture?.state());
      await page.screenshot({ path: path.join(output, 'failure.png') });
    }
    throw error;
  } finally {
    evidence.errors = errors;
    fs.writeFileSync(path.join(output, 'result-check.json'), JSON.stringify(evidence, null, 2));
    if (browser) await browser.close();
    server.kill();
    if (fs.existsSync(ready)) fs.unlinkSync(ready);
  }
})().catch(error => { console.error(error); process.exitCode = 1; });
