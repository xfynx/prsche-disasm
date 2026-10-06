// node verify-original-support.cjs <playwright directory> <output directory>
const {chromium} = require(process.argv[2]);
const fs = require('node:fs');
const path = require('node:path');
const assert = require('node:assert/strict');
const {spawn,spawnSync} = require('node:child_process');

(async () => {
  const root = path.resolve(__dirname,'../../..');
  const output = path.resolve(process.argv[3]);
  fs.mkdirSync(output,{recursive:true});
  const ready = path.join(output,'owned-server.json');
  const python = spawnSync('py',['-3','-c','import sys; print(sys.executable)'],{encoding:'utf8',windowsHide:true});
  assert.equal(python.status,0);
  const server = spawn(python.stdout.trim(),[path.join(root,'scripts/serve-web.py'),'--iteration','012-campaign-fidelity','--port','0','--ready-file',ready],{cwd:root,windowsHide:true,stdio:'ignore'});
  let browser;
  const samples = [], errors = [];
  try {
    for(let attempt=0;!fs.existsSync(ready);attempt++) {
      if(server.exitCode!==null||attempt>100) throw new Error('Test server failed');
      await new Promise(resolve=>setTimeout(resolve,100));
    }
    const info = JSON.parse(fs.readFileSync(ready,'utf8'));
    assert.equal(info.pid,server.pid);
    browser = await chromium.launch({channel:'chromium',headless:true});
    const page = await browser.newPage({viewport:{width:1280,height:800}});
    await page.route('**/main.js',async route=> {
      const response = await route.fetch();
      await route.fulfill({response,body:(await response.text())+'\nglobalThis.supportState=()=>({support:Array.from(viewer.get_original_support_state()),edges:viewer.get_original_scene_object_count(),physics:Array.from(viewer.get_car_physics_state()),pose:Array.from(viewer.get_car_pose()),speed:viewer.get_car_speed(),phase:viewer.get_race_phase(),sim:viewer.is_sim_mode()});'});
    });
    page.on('pageerror',error=>errors.push(String(error)));
    page.on('console',message=>{if(message.type()==='error') errors.push(message.text());});
    await page.goto(`http://127.0.0.1:${info.port}/`);
    await page.waitForFunction(()=>document.querySelector('#status').textContent.includes('"skidpad" загружен'),null,{timeout:90000});
    for(const track of ['skidpad','alps','canyon']) {
      await page.locator('#quickRaceBtn').click();
      await page.locator('#quickRaceTrack').selectOption(track);
      await page.locator('#quickRaceCar').selectOption('boxster_986');
      await page.locator('#quickRaceLaps').selectOption('1');
      await page.locator('#quickRaceOpponents').selectOption('0');
      await page.locator('#quickRaceStartBtn').click();
      await page.waitForFunction(()=>document.querySelector('#quickRaceModal').hidden&&document.querySelector('#status').textContent.startsWith('Quick Race:'),null,{timeout:90000});
      await page.waitForFunction(()=>supportState().phase===2,null,{timeout:20000});
      await page.waitForTimeout(500);
      const before = await page.evaluate(()=>supportState());
      assert.equal(before.sim,true);
      assert.equal(before.support[0],1,`${track}: original backend not active`);
      assert.ok(before.edges>0,`${track}: original EDG objects absent from live tree`);
      assert.ok(before.support[1]>0&&before.support[2]>1,`${track}: no original polygons/tree`);
      assert.ok(before.support.slice(3).every(index=>index>=0),`${track}: wheel support cache misses`);
      assert.ok([0,1,2,3].some(i=>before.physics[6+i*5]===1),`${track}: no wheel load`);
      await page.keyboard.down('w');
      await page.waitForTimeout(2000);
      await page.keyboard.up('w');
      const after = await page.evaluate(()=>supportState());
      assert.ok(after.pose.every(Number.isFinite),`${track}: nonfinite pose`);
      assert.ok(Math.hypot(after.pose[0]-before.pose[0],after.pose[2]-before.pose[2])>1,`${track}: car did not move`);
      assert.ok(Math.abs(after.pose[1]-before.pose[1])<10,`${track}: lost deck`);
      samples.push({track,before,after});
      await page.screenshot({path:path.join(output,`web-${track}-support.png`),fullPage:true});
      await page.keyboard.press('Escape');
    }
    assert.deepEqual(errors,[]);
    fs.writeFileSync(path.join(output,'browser-support.json'),JSON.stringify({browser:browser.version(),samples,errors},null,2));
    console.log(JSON.stringify({tracks:samples.map(s=>s.track),errors}));
  } catch(error) {
    fs.writeFileSync(path.join(output,'browser-support-failure.json'),JSON.stringify({samples,errors,error:String(error)},null,2));
    throw error;
  } finally {
    if(browser) await browser.close();
    server.kill();
    if(fs.existsSync(ready)) fs.unlinkSync(ready);
  }
})().catch(error=>{console.error(error);process.exitCode=1;});
