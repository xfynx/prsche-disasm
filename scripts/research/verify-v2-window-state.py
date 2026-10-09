"""Verify the shared original window configuration aliases and joint worker use."""
import hashlib, json, subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/039-window-state'
PROBE=ROOT/'local/builds/v2/window-state-039/bin/Release/window_state_probe.exe'

def main():
    output=subprocess.run([str(PROBE)],text=True,capture_output=True,check=True,timeout=10)
    observed=json.loads(output.stdout.strip())
    if not all(observed.values()):raise RuntimeError(f'Window state alias fixture failed: {observed}')
    files=['iterations/v2/001-original-recovery/source/include/porsche/window_state.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/window_create.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/window_worker.hpp',
      'iterations/v2/001-original-recovery/source/include/porsche/window_procedure.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_create.cpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_worker.cpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_state.cpp',
      'iterations/v2/001-original-recovery/source/recovered/window_state_probe.cpp',
      'iterations/v2/001-original-recovery/runs/039-window-state/CMakeLists.txt',
      'iterations/v2/001-original-recovery/runs/039-window-state/README.md',
      'scripts/research/verify-v2-window-state.py']
    report={'schema':1,'original_sha256':'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39',
      'configuration_base':'006b77a0','layout_size':'0x478','confirmed_fields':{
       'width_006b77b4':'0x014','height_006b77b8':'0x018','hwnd_006b7bf8':'0x458',
       'fullscreen_006b7c01':'0x461','pos_x_006b7c08':'0x468','pos_y_006b7c0c':'0x46c',
       'running_006b7c14':'0x474'},'unknown_bytes':'All gaps remain opaque byte arrays.',
      'joint_fixture':observed,'native_cpp_x86':True,'game_launch_verified':False,
      'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in files},
      'probe_sha256':hashlib.sha256(PROBE.read_bytes()).hexdigest()}
    (RUN/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'joint_fixture':observed,'native_cpp_x86':True}))
if __name__=='__main__':main()
