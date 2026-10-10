"""Pin original PE storage and indexed consumers, without claiming gameplay parity."""
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent))
from v2_source_dependencies import source_hashes

SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
CELLS = {'00606a88': 12, '00606874': 2, '005e99f4': 42}
SOURCE = 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_main_globals.cpp'


def main():
    image = (ROOT/'local/game/Porsche.exe').read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA
    pe = struct.unpack_from('<I', image, 0x3c)[0]
    assert image[pe:pe+4] == b'PE\0\0'
    count, opt_size = struct.unpack_from('<H', image, pe+6)[0], struct.unpack_from('<H', image, pe+20)[0]
    opt = pe+24
    assert struct.unpack_from('<H', image, opt)[0] == 0x10b
    image_base = struct.unpack_from('<I', image, opt+28)[0]
    sections = []
    for i in range(count):
        offset = opt+opt_size+40*i
        name = image[offset:offset+8].rstrip(b'\0').decode('ascii')
        virtual_size, rva, raw_size, raw_offset = struct.unpack_from('<IIII', image, offset+8)
        sections.append(dict(name=name, virtual_size=virtual_size, rva=rva, raw_size=raw_size, raw_offset=raw_offset))
    refs_path = ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl'
    refs = {va: [] for va in CELLS}
    for line in refs_path.read_text().splitlines():
        ref = json.loads(line)
        if ref['to_va'] in refs:
            refs[ref['to_va']].append(ref)
    listing_path = ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    wanted = {r['from_va'] for records in refs.values() for r in records}
    instructions = {}
    with listing_path.open() as listing:
        for line in listing:
            if line[:8] in wanted:
                instructions[line[:8]] = line.strip()
    cells = []
    for va, expected_count in CELLS.items():
        address = int(va, 16)
        section = next(s for s in sections if image_base+s['rva'] <= address and address+4 <= image_base+s['rva']+s['virtual_size'])
        assert section['name'] == '.data'
        assert address >= image_base+section['rva']+section['raw_size']
        assert len(refs[va]) == expected_count
        consumers = []
        for ref in refs[va]:
            instruction = instructions[ref['from_va']]
            assert '0x'+va in instruction.lower()
            # Confirm these direct consumers address a DWORD, including A1/A3 EAX forms.
            assert 'dword ptr' in instruction or 'MOV EAX,[' in instruction or '],EAX' in instruction
            encoded = bytes.fromhex(instruction.split()[1])
            rva = int(ref['from_va'], 16)-image_base
            code_section = next(s for s in sections if s['rva'] <= rva < s['rva']+s['raw_size'])
            offset = code_section['raw_offset']+rva-code_section['rva']
            assert image[offset:offset+len(encoded)] == encoded
            consumers.append(dict(reference=ref, instruction=instruction))
        cells.append(dict(va=va, bytes=4, initial_value=0, storage='PE zero-filled virtual .data tail', section=section, consumers=consumers))
    report = dict(schema=1, module='Porsche.exe', sha256=SHA, cells=cells,
                  original_storage_and_instruction_bytes_verified=True,
                  native_cpp_equal_original_x86=False, game_launch_verified=False,
                  source_sha256=source_hashes([ROOT/SOURCE, Path(__file__), ROOT/'iterations/v2/001-original-recovery/source/include/porsche/application_main.hpp', ROOT/'iterations/v2/001-original-recovery/runs/120-application-main-storage/README.md']),
                  evidence_sha256={str(p.relative_to(ROOT)).replace('\\','/'): hashlib.sha256(p.read_bytes()).hexdigest() for p in [refs_path, listing_path]},
                  limitations=['Storage-only recovery; no recovered-function count increase.', 'Startup and subsequent writers still require their own original/native checks.', 'No gameplay meaning inferred from cell names or values.'])
    output = ROOT/'iterations/v2/001-original-recovery/runs/120-application-main-storage/verification.json'
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes((json.dumps(report, indent=2)+'\n').encode())
    print(json.dumps(dict(cells=len(cells), indexed_consumers=sum(CELLS.values()), original_storage_and_instruction_bytes_verified=True)))


if __name__ == '__main__':
    main()
