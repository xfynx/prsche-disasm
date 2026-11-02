"""Bounded local 3DNow feasibility probe; no production or native acceptance."""
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
OUT = ROOT / 'local/experiments/v2-3dnow-oracle-feasibility-497/001'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
import unicorn
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32
from unicorn import x86_const as x
import capstone

SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
CODE, DATA = 0x100000, 0x200000


def main():
    assert not OUT.exists(), 'Preserve attempts; choose a new output number'
    raw = (ROOT / 'local/game/Porsche.exe').read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    pe = struct.unpack_from('<I', raw, 0x3c)[0]
    table = pe + 24 + struct.unpack_from('<H', raw, pe + 20)[0]
    sections = [struct.unpack_from('<IIII', raw, table + 40*i + 8)
                for i in range(struct.unpack_from('<H', raw, pe + 6)[0])]

    def original(va, size):
        for _, rva, rsize, offset in sections:
            if rva <= va - 0x400000 < rva + rsize:
                start = offset + va - 0x400000 - rva
                return raw[start:start+size]
        raise ValueError(hex(va))

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    bodies = []
    for va, size in [(0x59bc40, 159), (0x59bb90, 163)]:
        body = original(va, size)
        bodies.append(dict(va=f'{va:08x}', bytes=size, sha256=hashlib.sha256(body).hexdigest(),
            instructions=[dict(va=f'{i.address:08x}', raw=i.bytes.hex(),
                               mnemonic=i.mnemonic, operands=i.op_str)
                          for i in md.disasm(body, va)]))
    models = [(name, getattr(x, name)) for name in dir(x)
              if name.startswith('UC_CPU_X86_') and name != 'UC_CPU_X86_ENDING']
    specs = [
        ('PFMUL', 0x59bc6a, '0f0fc8b4', (1.5, -2.0), (2.0, 3.0), (3.0, -6.0)),
        ('PFADD', 0x59bc73, '0f0fca9e', (1.5, -2.0), (2.0, 3.0), (3.5, 1.0)),
        ('PI2FD', 0x59bbb4, '0f0fc90d', (-32768, 32767), None, (-32768.0, 32767.0)),
        ('FEMMS', 0x59bcdb, '0f0e', None, None, None),
    ]
    results = []
    # Default is an explicit control, Athlon is the target; Phenom checks another
    # already-installed AMD model without modifying the emulator or opcodes.
    for name, model in [('default', None), ('ATHLON', x.UC_CPU_X86_ATHLON),
                        ('PHENOM', x.UC_CPU_X86_PHENOM)]:
        for operation, va, expected_raw, lhs, rhs, answer in specs:
            opcode = original(va, len(bytes.fromhex(expected_raw)))
            assert opcode.hex() == expected_raw
            uc = Uc(UC_ARCH_X86, UC_MODE_32)
            if model is not None:
                uc.ctl_set_cpu_model(model)
            selected = uc.ctl_get_cpu_model()
            uc.mem_map(CODE, 0x1000)
            uc.mem_map(DATA, 0x1000)
            # Harness-only MOVQ loads/stores. The target arithmetic/reset bytes
            # themselves are copied unchanged from the pinned PE.
            load1 = bytes.fromhex('0f6f0d') + struct.pack('<I', DATA)
            load0 = bytes.fromhex('0f6f05') + struct.pack('<I', DATA+8)
            load2 = bytes.fromhex('0f6f15') + struct.pack('<I', DATA+8)
            store1 = bytes.fromhex('0f7f0d') + struct.pack('<I', DATA+16)
            if operation == 'FEMMS':
                prefix, suffix = load1, b''
                uc.mem_write(DATA, bytes.fromhex('000000000000f03f'))
            else:
                prefix = load1 + (load0 if operation == 'PFMUL' else load2 if rhs else b'')
                suffix = store1
                uc.mem_write(DATA, struct.pack('<2i' if operation == 'PI2FD' else '<2f', *lhs))
                if rhs:
                    uc.mem_write(DATA+8, struct.pack('<2f', *rhs))
            uc.mem_write(DATA+16, b'\xcc'*8)
            uc.mem_write(CODE, prefix + opcode + suffix)
            # Create a nonempty x87 state before the MMX load/reset probe.
            uc.reg_write(x.UC_X86_REG_FPCW, 0x37f)
            uc.reg_write(x.UC_X86_REG_FPSW, 0x1800)
            uc.reg_write(x.UC_X86_REG_FPTAG, 0x3fff)
            before = dict(fptag=uc.reg_read(x.UC_X86_REG_FPTAG),
                          fpsw=uc.reg_read(x.UC_X86_REG_FPSW))
            row = dict(model=name, model_id=selected, instruction=operation,
                       original_va=f'{va:08x}', raw=opcode.hex(), before=before)
            try:
                uc.emu_start(CODE, CODE+len(prefix))
                row['at_target'] = dict(fptag=uc.reg_read(x.UC_X86_REG_FPTAG),
                                       fpsw=uc.reg_read(x.UC_X86_REG_FPSW))
                uc.emu_start(CODE+len(prefix), CODE+len(prefix)+len(opcode)+len(suffix))
                row['status'] = 'executed'
            except UcError as exc:
                row.update(status='unsupported', error=str(exc), errno=exc.errno,
                           eip=f'{uc.reg_read(x.UC_X86_REG_EIP):08x}')
            row['after'] = dict(fptag=uc.reg_read(x.UC_X86_REG_FPTAG),
                                fpsw=uc.reg_read(x.UC_X86_REG_FPSW))
            row['output_hex'] = bytes(uc.mem_read(DATA+16, 8)).hex()
            if answer:
                row['expected_hex'] = struct.pack('<2f', *answer).hex()
                row['matches'] = row['status'] == 'executed' and row['output_hex'] == row['expected_hex']
            else:
                row['matches'] = row['status'] == 'executed' and row['after']['fptag'] == 0xffff
            results.append(row)
    report = dict(schema=1, kind='bounded-3dnow-emulator-feasibility',
        original_sha256=SHA, unicorn_python_version=unicorn.__version__,
        unicorn_core_version=unicorn.uc_version(), unicorn_module=unicorn.__file__,
        capstone_version=capstone.__version__, python_version=sys.version,
        api='Uc(UC_ARCH_X86, UC_MODE_32); ctl_set_cpu_model before initialization',
        available_models=dict(models), original_bodies=bodies, probes=results,
        probe_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        boundaries=['Only tiny exact-instruction known-input probes, no original full-function compare',
                    'Emulated execution is not native-hardware or gameplay acceptance',
                    'No approximation, production provider, install or emulator patch'])
    OUT.mkdir(parents=True)
    (OUT/'result.json').write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8', newline='\n')
    print(json.dumps(dict(unicorn=unicorn.__version__, probes=len(results),
                         matches=sum(row['matches'] for row in results),
                         status=[(row['model'], row['instruction'], row['status'], row['matches'])
                                 for row in results])))


if __name__ == '__main__':
    main()
