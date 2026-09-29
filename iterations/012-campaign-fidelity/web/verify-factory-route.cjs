// Real keyboard route probe. No pose, time limit, physics or profile mutations.
// node verify-factory-route.cjs <playwright> <output>
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
  const ready = path.join(output, `route-server-${Date.now()}.json`);
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
    page.on('pageerror', e => errors.push(String(e)));
    await page.route('**/main.js', async route => {
      const response = await route.fetch();
      await route.fulfill({ response, body: (await response.text()) + `
globalThis.routeState = () => ({pose: Array.from(viewer.get_car_pose()), speed: viewer.get_car_speed(),
  physics: Array.from(viewer.get_car_physics_state()),
  gates: viewer.get_mission_passed_gates(), elapsed: viewer.get_mission_elapsed_time(),
  reached: viewer.get_mission_goal_reached(), timedOut: viewer.get_mission_timed_out(),
  cones: viewer.get_cone_hits(), profile: JSON.stringify(currentProfile),
  resultVisible: !document.querySelector('#raceResultsModal').hidden});
` });
    });
    await page.goto(`http://127.0.0.1:${info.port}/`);
    await page.waitForFunction(() => document.querySelector('#status').textContent.includes('"skidpad" загружен') && !document.querySelector('#targetSelect').disabled, null, { timeout: 60000 });
    await page.locator('#careerFactoryBtn').click();
    await page.locator('#factoryMissionsGrid .cup-card:first-child button').click();
    await page.locator('#briefingStartBtn').click();
    await page.waitForFunction(() => document.querySelector('#status').textContent.includes('Карьерный заезд начат:'), null, { timeout: 30000 });
    const trace = [];
    let state = await page.evaluate(() => routeState());
    const before = state.profile;
    const targets = [[0,-112],[-18,-63],[0,-9],[-23,74],[12,62],[-6.8,-148]];
    const held = new Set();
    let previousGate = -1;
    while (!state.reached && !state.timedOut && state.elapsed < 35 && trace.length < 650) {
      const [x,z] = targets[Math.min(state.gates, 5)];
      const dx=x-state.pose[0], dz=z-state.pose[2];
      const error=Math.atan2(state.pose[5]*dx-state.pose[3]*dz, state.pose[3]*dx+state.pose[5]*dz);
      const targetSpeed = Math.abs(error)>0.8 ? 28 : Math.abs(error)>0.35 ? 48 : 78;
      const keys = new Set([state.speed>targetSpeed+5 ? 's' : 'w']);
      if (error>0.06) keys.add('a');
      else if (error< -0.06) keys.add('d');
      for (const key of held) if (!keys.has(key)) { await page.keyboard.up(key); held.delete(key); }
      for (const key of keys) if (!held.has(key)) { await page.keyboard.down(key); held.add(key); }
      trace.push({ ...state, profile: undefined, error, target: [x,z], keys: [...keys] });
      if (state.gates !== previousGate) {
        console.log(JSON.stringify({gates:state.gates,elapsed:state.elapsed,pose:state.pose,speed:state.speed}));
        previousGate=state.gates;
      }
      await page.waitForTimeout(80);
      state=await page.evaluate(() => routeState());
    }
    for (const key of held) await page.keyboard.up(key);
    await page.waitForTimeout(250);
    state=await page.evaluate(() => routeState());
    await page.screenshot({path:path.join(output,'route-result.png')});
    fs.writeFileSync(path.join(output,'route-check.json'), JSON.stringify({state,before,errors,trace},null,2));
    console.log(JSON.stringify({gates:state.gates,elapsed:state.elapsed,reached:state.reached,timedOut:state.timedOut,cones:state.cones,errors}));
    if (!state.reached || errors.length) process.exitCode=1;
  } finally {
    if(browser) await browser.close();
    server.kill();
    if(fs.existsSync(ready)) fs.unlinkSync(ready);
  }
})().catch(e => { console.error(e); process.exitCode=1; });
