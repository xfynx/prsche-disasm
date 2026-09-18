"""Inventory PE32 headers/imports without executing the original game."""
import hashlib
import json
import struct
from pathlib import Path


def inspect(path):
    data = path.read_bytes()
    u16 = lambda offset: struct.unpack_from('<H', data, offset)[0]
    u32 = lambda offset: struct.unpack_from('<I', data, offset)[0]
    pe = u32(0x3c)
    if data[pe:pe+4] != b'PE\0\0' or u16(pe+24) != 0x10b:
        raise ValueError(f'{path}: expected PE32')
    sections = []
    start = pe + 24 + u16(pe+20)
    for i in range(u16(pe+6)):
        offset = start + 40*i
        sections.append({'name': data[offset:offset+8].rstrip(b'\0').decode('ascii', 'replace'),
                         'virtual_size': u32(offset+8), 'rva': u32(offset+12),
                         'raw_size': u32(offset+16), 'raw_offset': u32(offset+20)})

    def file_offset(rva):
        for section in sections:
            if section['rva'] <= rva < section['rva'] + section['raw_size']:
                return section['raw_offset'] + rva - section['rva']
        if rva < u32(pe+24+60):
            return rva
        raise ValueError(f'{path.name}: RVA {rva:x} has no raw mapping')

    def cstr(offset):
        end = data.index(b'\0', offset)
        return data[offset:end].decode('ascii', 'replace')

    imports = []
    import_rva = u32(pe+24+104)
    if import_rva:
        offset = file_offset(import_rva)
        while any(data[offset:offset+20]):
            original_thunk, _, _, name, first_thunk = struct.unpack_from('<5I', data, offset)
            dll = cstr(file_offset(name))
            symbols = []
            thunk = file_offset(original_thunk or first_thunk)
            while u32(thunk):
                value = u32(thunk)
                symbols.append(f'ordinal:{value & 0xffff}' if value & 0x80000000
                               else cstr(file_offset(value)+2))
                thunk += 4
            imports.append({'dll': dll, 'symbols': symbols})
            offset += 20
    return {'file': path.name, 'size': len(data), 'sha256': hashlib.sha256(data).hexdigest(),
            'machine': f'{u16(pe+4):04x}', 'entry_rva': f'{u32(pe+24+16):08x}',
            'image_base': f'{u32(pe+24+28):08x}', 'sections': sections, 'imports': imports}


if __name__ == '__main__':
    root = Path(__file__).resolve().parents[1]
    names = ['Porsche.exe', 'nfs5.exe', 'gimme.dll', 'nfs5.dll', 'dinput.dll', 'SilentPatchNFS90s.asi']
    result = [inspect(root/'local/game'/name) for name in names]
    (root/'docs/pe-inventory.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    for module in result:
        print(module['file'], module['machine'], 'entry RVA', module['entry_rva'],
              'imports', ', '.join(x['dll'] for x in module['imports']))
