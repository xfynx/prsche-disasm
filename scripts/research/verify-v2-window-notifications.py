"""Run087: full resize counter and bounded original keyboard-data consumer."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path
from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
BASE = 'iterations/v2/001-original-recovery/'
RUN = ROOT / BASE / 'runs/087-window-notifications'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESI, UC_X86_REG_ESP

STACK, EXIT = 0x3108000, 0x3200000

def put(u, address, value):
    u.mem_write(address, struct.pack('<I', value & 0xffffffff))

def word(u, address):
    return struct.unpack('<I', u.mem_read(address, 4))[0]

def original(module, image, case):
    scan, table, initial, enabled = case
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0x400000, 0x300000)
    for s in module['sections']:
        if s['raw_size']:
            u.mem_write(0x400000+s['rva'], image[s['raw_offset']:s['raw_offset']+s['raw_size']])
    u.mem_map(0x3100000, 0x10000)
    u.mem_map(EXIT, 0x1000)
    put(u, STACK, EXIT)
    put(u, 0x6a5c2c, initial)
    u.reg_write(UC_X86_REG_EAX, 0xabcdef01)
    u.reg_write(UC_X86_REG_ESP, STACK)
    u.emu_start(0x5654d0, EXIT, count=100)
    assert u.reg_read(UC_X86_REG_ESP) == STACK+4
    assert u.reg_read(UC_X86_REG_EAX) == 0xabcdef01
    put(u, 0x5df9b8, 0x5654d0 if enabled else 0)
    u.reg_write(UC_X86_REG_ESI, 0x6b77a0)
    u.reg_write(UC_X86_REG_ESP, STACK)
    # Original test/null branch and indirect CALL, stop before function epilogue.
    u.emu_start(0x53b3b1, 0x53b3c4, count=100)
    assert u.reg_read(UC_X86_REG_ESP) == STACK
    counter = word(u, 0x6a5c2c)
    put(u, 0x69e5a0, 0x5df934 if table else 0)
    u.reg_write(UC_X86_REG_ESI, scan << 16)
    u.emu_start(0x53b47f, 0x53b4a2, count=100)
    return word(u, 0x6bd9fc), counter, enabled

def main():
    p = argparse.ArgumentParser()
    p.add_argument('--probe', type=Path, default=ROOT/'local/builds/v2/001-original-recovery/window-notifications/bin/Release/window_notifications_probe.exe')
    p.add_argument('--report', type=Path, default=RUN/'verification.json')
    a = p.parse_args()
    module = next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    image = (ROOT/'local/game'/module['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA
    inputs = [(scan, table, 0, 1) for scan in range(128) for table in (0, 1)]
    inputs += [(scan, table, initial, enabled) for scan in (0, 127) for table in (0, 1) for initial in (0, 1, 0xfffffffe, 0xffffffff) for enabled in (0, 1)]
    process = subprocess.run([str(a.probe)], input=''.join(' '.join(map(str,c))+'\n' for c in inputs), text=True, capture_output=True, check=True)
    lines = process.stdout.splitlines()
    assert len(lines) == len(inputs)
    outputs = []
    for c, line in zip(inputs, lines):
        actual = tuple(map(int, line.split()))
        expected = original(module, image, c)
        assert actual == expected, (c, actual, expected)
        outputs.append({'input': c, 'output': actual})
    deps = [BASE+x for x in ('source/include/porsche/window_input_bindings.hpp', 'source/recovered/Porsche.exe/window_input_bindings.cpp', 'source/recovered/Porsche.exe/window_scan_translation.inc', 'source/recovered/window_notifications_probe.cpp', 'runs/087-window-notifications/CMakeLists.txt', 'runs/087-window-notifications/README.md')]
    deps.append('scripts/research/verify-v2-window-notifications.py')
    report = {'schema':1, 'sha256':SHA, 'function_vas':['005654d0'], 'full_function_vas':['005654d0'], 'partial_function_vas':[], 'cases':len(inputs), 'native_cpp_equal_original_x86':True, 'binary_matched':False, 'game_launch_verified':False,
              'consumer_slices':[['0053b3b1','0053b3c4'],['0053b47f','0053b4a2']],
              'boundaries':'Counter full body preserves EAX; native void function represents caller-discarded result. Key lookup checks all 128 caller-domain indices for null/default guest data table. No unknown pointer resolution or full keyboard-function claim.',
              'source_sha256':source_hashes(deps, compiled_sources=[BASE+'source/recovered/Porsche.exe/window_input_bindings.cpp', BASE+'source/recovered/window_notifications_probe.cpp']),
              'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(), 'fixtures':outputs}
    a.report.parent.mkdir(parents=True, exist_ok=True)
    a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(inputs),'full_function_vas':['005654d0'],'native_cpp_equal_original_x86':True}))

if __name__ == '__main__':
    main()
