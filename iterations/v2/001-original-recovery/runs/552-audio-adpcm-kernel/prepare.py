"""Build the Run552 native fixture and config.

Embeds the six original bodies plus the accepted 0059a8c0/0059a800/00598a50
oracle bodies in an executable slab, relocates their relative calls, absolute
data operands and the 0059ad70 switch table to the canonical C++ owners, and
pins every input in native-config.json.
"""
import hashlib
import importlib.util
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
sys_path = ROOT / 'local/tools/python-unicorn'
import sys
sys.path[:0] = [str(ROOT / 'scripts/research'), str(sys_path)]
import capstone
import v2_source_dependencies as dependencies
from v2_shared_manifests import ManifestReader

spec = importlib.util.spec_from_file_location('n552', ROOT / 'scripts/research/verify-v2-native-batch.py')
n = importlib.util.module_from_spec(spec)
spec.loader.exec_module(n)
raw = (ROOT / 'local/game/Porsche.exe').read_bytes()
sha = lambda b: hashlib.sha256(b).hexdigest()
assert sha(raw) == 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'

BODIES = [
    ('0059a910', 706, 0x0000, 'DECODE'),
    ('0059abe0', 397, 0x0400, 'DEQUANT'),
    ('0059ad80', 58, 0x0600, 'SKIP'),
    ('0059adc0', 61, 0x0640, 'SMOOTH'),
    ('0059ae00', 1914, 0x0800, 'SYNTH'),
    ('0059b580', 176, 0x1000, 'WINDOW'),
    ('0059a8c0', 74, 0x1100, 'READBITS'),
    ('0059a800', 190, 0x1200, 'INIT'),
    ('00598a50', 31, 0x1300, 'COPY'),
]
off = {int(va, 16): position for va, _, position, _ in BODIES}
# Canonical C++ owners for every absolute data operand the six bodies read.
DATA = {
    0x5e34c4: 'ptr(audio_coded_scale_005e34c4)',
    0x5e3504: 'ptr(audio_coded_scale_005e34c4)+0x40',
    0x5e35c4: 'ptr(audio_coded_context_005e35c4)',
    0x5e37c8: 'ptr(audio_coded_level_005e37c8)',
    0x5e37cc: 'ptr(audio_coded_level_005e37c8)+4',
    0x5e37d0: 'ptr(audio_coded_level_005e37c8)+8',
    0x5b2468: 'ptr(&audio_coded_quarter_005b2468)',
    0x5b2778: 'ptr(audio_coded_gain_005b2778)',
    0x5c1808: 'ptr(audio_coded_window_005c1808)',
    0x5c180c: 'ptr(audio_coded_window_005c1808)+4',
    0x5c1810: 'ptr(audio_coded_window_005c1808)+8',
    0x5c1814: 'ptr(audio_coded_window_005c1808)+0xc',
    0x59ad70: 'ptr(switch_552)',
    # Accepted Run504 owners reused by the 0059a8c0/0059a800 oracle bodies.
    0x5e34a0: 'ptr(audio_adpcm_bit_masks_005e34a0)',
    0x5b2608: 'ptr(&audio_adpcm_scale_005b2608)',
    0x5b27b4: 'ptr(&audio_adpcm_factor_scale_005b27b4)',
    0x5c1804: 'ptr(&audio_adpcm_factor_bias_005c1804)',
}
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

chunks, patches, evidence = [], [], {}
for va, size, position, token in BODIES:
    start = int(va, 16)
    data = n.pe_at(raw, start, size)
    chunks.append(f'    static const B raw_{token}[]={{@{token}552@}};\n'
                  f'    std::memcpy(slab+{position:#06x},raw_{token},sizeof(raw_{token}));\n')
    calls, operands = [], []
    for ins in md.disasm(data, start):
        at = position + ins.address - start
        if ins.mnemonic == 'call' and ins.bytes[0] == 0xe8:
            target = int(ins.op_str, 16)
            assert target in off, (va, ins.address, ins.op_str)
            calls.append((at, ins.address, target, struct.unpack_from('<i', ins.bytes, 1)[0]))
        for operand in ins.operands:
            if operand.type != capstone.x86.X86_OP_MEM:
                continue
            disp = operand.mem.disp
            if 0x400000 <= disp < 0x800000:
                # Any image-space data reference must have a proven transport.
                assert disp in DATA, (va, ins.address, hex(disp), ins.mnemonic)
            if disp not in DATA:
                continue
            assert ins.bytes[-4:] == struct.pack('<I', disp), (va, ins.address, ins.bytes.hex())
            operands.append((at + len(ins.bytes) - 4, ins.address, disp))
    for at, address, target, operand in calls:
        patches.append(
            f'    require(rd(slab+{at + 1:#06x})==0x{operand & 0xffffffff:08x},"{va} call operand");\n'
            f'    wr(slab+{at + 1:#06x},ptr(slab+{off[target]:#06x})-ptr(slab+{at + 5:#06x}));\n')
    for at, address, disp in operands:
        patches.append(
            f'    require(rd(slab+{at:#06x})==0x{disp:08x},"{va} data operand");\n'
            f'    wr(slab+{at:#06x},{DATA[disp]});\n')
    evidence[va] = {'bytes': size, 'sha256': sha(data), 'slab_offset': position,
                    'calls': [hex(t) for _, _, t, _ in calls],
                    'operands': [hex(d) for _, _, d in operands]}

prelude = f'''#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "audio_coded_kernel_552.hpp"
#include "audio_coded_constructors_504.hpp"
#include "audio_stream_worker_stop_513.hpp"
#include <cstdio>
#include <cstring>
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;using namespace porsche;
static B* slab;
static U switch_552[4];
static void require(bool ok,const char* why){{
    if(!ok){{std::printf("divergence %s\\n",why);std::fflush(stdout);ExitProcess(1);}}
}}
static U ptr(const void* p){{return reinterpret_cast<U>(p);}}
static U rd(const void* p){{U x;std::memcpy(&x,p,4);return x;}}
static void wr(void* p,U x){{std::memcpy(p,&x,4);}}
// Dead dependencies of the accepted Run504/Run519 translation units linked for
// this proof. None of them is reachable from the six bodies under test.
namespace porsche {{
int __cdecl audio_pcm_channel_owner_00589710(U){{ExitProcess(90);return 0;}}
U __cdecl audio_pcm_channel_member_00589740(U){{ExitProcess(90);return 0;}}
I __cdecl audio_pcm_stream_find_0059c130(I){{ExitProcess(90);return 0;}}
I __cdecl audio_adpcm_process_00597e30(U,U,U,U,U){{ExitProcess(90);return 0;}}
I __cdecl audio_adpcm_stream_process_0059c1e0(U,U,U,U,U){{ExitProcess(90);return 0;}}
I __cdecl audio_nibble_process_00597c40(U,U,U,U,U){{ExitProcess(90);return 0;}}
I __cdecl audio_nibble_loop_process_0059c890(U,U,U,U,U){{ExitProcess(90);return 0;}}
I __cdecl audio_nibble_stream_process_0059c3c0(U,U,U,U,U){{ExitProcess(90);return 0;}}
I __cdecl audio_resampler_stream_process_0059b690(U,U,U,U,U){{ExitProcess(90);return 0;}}
void __cdecl audio_nibble_decode_x87_0059a5a0(U){{ExitProcess(90);}}
void __cdecl audio_nibble_decode_sse_0059a660(U){{ExitProcess(90);}}
void __cdecl audio_nibble_decode_3dnow_0059a730(U){{ExitProcess(90);}}
void __cdecl audio_stream_transform_00597660(U,U){{ExitProcess(90);}}
AudioStreamCapture513 audio_stream_capture_006aefb8;
unsigned char audio_stream_backend_format_006b4862;
unsigned int audio_stream_backend_buffer_006b4864;
}}
#define OFF_59A910 0x0000
#define OFF_59ABE0 0x0400
#define OFF_59AD80 0x0600
#define OFF_59ADC0 0x0640
#define OFF_59AE00 0x0800
#define OFF_59B580 0x1000
#define OFF_59A8C0 0x1100
#define OFF_59A800 0x1200
#define OFF_598A50 0x1300
static void setup_slab(){{
    slab=static_cast<B*>(VirtualAlloc(nullptr,0x4000,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));
    require(slab!=nullptr,"raw slab");
    switch_552[0]=ptr(slab+OFF_59ABE0+(0x59ad35-0x59abe0));
    switch_552[1]=ptr(slab+OFF_59ABE0+(0x59ad3f-0x59abe0));
    switch_552[2]=ptr(slab+OFF_59ABE0+(0x59ad35-0x59abe0));
    switch_552[3]=ptr(slab+OFF_59ABE0+(0x59ad47-0x59abe0));
{''.join(chunks)}{''.join(patches)}}}
#include "fixture-harness.inc"
'''
(RUN / 'native-fixture.cpp.in').write_text(prelude, encoding='utf-8', newline='\n')
(RUN / 'oracle-relocations.json').write_text(
    json.dumps({'original_sha256': sha(raw), 'bodies': evidence,
                'data_operands': {f'{k:08x}': v for k, v in DATA.items()}},
               indent=2) + '\n', encoding='utf-8', newline='\n')

base = RUN.parent / '551-diagnostic-codec-integration'
build = json.loads((base / 'build-001.json').read_bytes())
cfg551 = json.loads((base / 'build-config.json').read_bytes())
_, effective = ManifestReader(ROOT).resolve(build, 'source', 'crlf-to-lf', 'crlf-to-lf')
dependencies.EXTRA_INCLUDE_DIRS = tuple(ROOT / p for p in cfg551['source_include_dirs'])
closure = dependencies.source_hashes(build['compiled_source_roots'])

source = (RUN / 'audio_coded_kernel_552.cpp').relative_to(ROOT).as_posix()
config = {
    'run': 552,
    'experiment': 'local/experiments/v2-audio-adpcm-kernel-552',
    'fixture': (RUN / 'native-fixture.cpp.in').relative_to(ROOT).as_posix(),
    'pass_marker': 'audio_coded_kernel_original_x86_vs_cpp=PASS',
    'timeout_seconds': 180,
    'original_pe': 'local/game/Porsche.exe',
    'original_sha256': sha(raw),
    'sources': [
        source,
        (RUN.parent / '504-audio-coded-constructors/audio_coded_constructors_504.cpp').relative_to(ROOT).as_posix(),
        (RUN.parent / '519-audio-stream-capture-fill/audio_stream_capture_fill_519.cpp').relative_to(ROOT).as_posix(),
    ],
    'include_dirs': [(RUN).relative_to(ROOT).as_posix(), *cfg551['source_include_dirs']],
    'headers': [(RUN / name).relative_to(ROOT).as_posix() for name in
                ('scope-evidence.json', 'oracle-relocations.json', 'table-evidence.json',
                 'audio_coded_tables_552.inc', 'audio_coded_matrix_552.inc',
                 'fixture-harness.inc', 'prepare.py', 'extract.py', 'gen_tables.py')],
    'original_bodies': [{'va': va, 'bytes': size, 'sha256': sha(n.pe_at(raw, int(va, 16), size)),
                         'token': f'@{token}552@'} for va, size, _, token in BODIES],
}
text = (RUN / 'audio_coded_kernel_552.cpp').read_text(encoding='utf-8')
mutations = [
    ('skip-shift', 'payload>>=bits&31u;', 'payload>>=(bits+1u)&31u;'),
    ('skip-refill', 'if(static_cast<I>(remaining)<8){', 'if(static_cast<I>(remaining)<7){'),
    ('smooth-constant', 'table(audio_coded_window_005c1808,3)', 'table(audio_coded_window_005c1808,2)'),
    ('smooth-sign', 'sum=sum-(static_cast<double>(f[n-3])+static_cast<double>(f[n+3]))*mid;',
     'sum=sum+(static_cast<double>(f[n-3])+static_cast<double>(f[n+3]))*mid;'),
    ('context-shift', '(context<<8)+payload', '(context<<7)+payload'),
    ('level-limit', 'if(symbol>3){', 'if(symbol>4){'),
    ('zero-run-length', 'audio_adpcm_read_bits_0059a8c0(state,6)+7u',
     'audio_adpcm_read_bits_0059a8c0(state,6)+6u'),
    ('unary-base', 'I level=7;', 'I level=6;'),
    ('fallback-level', 'if(bits==1u){value=-2.0f;skip=2;}', 'if(bits==1u){value=-1.0f;skip=2;}'),
    ('window-sign', 'double acc=-(static_cast<double>(h[0])*static_cast<double>(q[11]));',
     'double acc=static_cast<double>(h[0])*static_cast<double>(q[11]);'),
    ('window-taps', 'for(U j=1;j<=11;++j){', 'for(U j=1;j<11;++j){'),
    ('tape-lag', 'const U base=counter-lag;', 'const U base=counter-lag+1u;'),
    ('scale-accumulate', '*cell=static_cast<float>(static_cast<double>(*cell)+static_cast<double>(d[i]));',
     '*cell=static_cast<float>(static_cast<double>(d[i]));'),
    ('synth-tail', 'pass==3u?0x21:1', '1'),
    ('matrix-count', 'out+=12;', 'out+=11;'),
]
for name, old, new in mutations:
    assert text.count(old) == 1, (name, text.count(old))
config['mutations'] = [dict(name=name, source=source, old=old, new=new, expected_exit=1,
                            failure_marker='divergence') for name, old, new in mutations]
(RUN / 'native-config.json').write_text(json.dumps(config, indent=2) + '\n', encoding='utf-8', newline='\n')
print('bodies', len(BODIES), 'patches', len(patches), 'mutations', len(mutations),
      'pins', len(effective), 'closure', len(closure))
