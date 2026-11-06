"""Read-only native I386 COFF-to-PE retention certificate; never runs LINK or PE.

The probe's COFF helper cannot be imported: its module immediately links.
This bounded reader therefore parses the same native COFF records directly.
"""
from pathlib import Path
import collections
import hashlib
import json
import re
import struct


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def coff(path):
    path = Path(path)
    data = path.read_bytes()
    machine, count, _, table, nsym, optional, _ = struct.unpack_from('<HHIIIHH', data)
    require(machine == 0x14c and optional == 0, 'not native I386 COFF: ' + str(path))
    strings = table + nsym * 18
    symbols, index = {}, 0
    while index < nsym:
        pos = table + index * 18
        raw, value, section, kind, storage, aux = struct.unpack_from('<8sIhHBB', data, pos)
        start = strings + struct.unpack_from('<I', raw, 4)[0] if raw[:4] == bytes(4) else None
        name = (data[start:data.index(0, start)] if start is not None else raw.rstrip(b'\0')).decode()
        require(index + aux < nsym, 'truncated auxiliary record')
        symbols[index] = dict(name=name, value=value, section=section, kind=kind,
                              storage=storage, aux=data[pos + 18:pos + 18 * (aux + 1)])
        index += aux + 1
    sections = []
    for number in range(1, count + 1):
        raw, _, _, size, start, rel, _, nr, _, flags = struct.unpack_from('<8sIIIIIIHHI', data, 20 + 40 * (number - 1))
        require(not flags & 0x1000000, 'extended relocation count unsupported')
        require(not start or start + size <= len(data), 'truncated section')
        relocations = [struct.unpack_from('<IIH', data, rel + 10 * j) for j in range(nr)]
        require(all(target in symbols for _, target, _ in relocations), 'invalid relocation symbol')
        sections.append(dict(number=number, name=raw.rstrip(b'\0').decode(), flags=flags,
                             data=data[start:start + size] if start else bytes(size), relocations=relocations))
    return dict(path=path, symbols=symbols, sections=sections)


def check_retention(image_path, map_path, object_paths, *, link_command=None, compile_commands=None):
    """Return fresh byte/provenance evidence; raises ValueError on ambiguity/failure.

    Optional command receipts enable bounded non-rewriting condition checks.
    They are evidence supplied by the caller, not commands executed here.
    """
    image_path, map_path = Path(image_path), Path(map_path)
    objects = [coff(p) for p in object_paths]
    require(len({o['path'].name for o in objects}) == len(objects), 'ambiguous object basenames')
    command_flags = [str(a).upper() for a in (link_command or [])]
    if link_command:
        allowed = {'/NOLOGO', '/MACHINE:X86', '/SUBSYSTEM:CONSOLE', '/NODEFAULTLIB', '/OPT:REF',
                   '/OPT:NOICF', '/FORCE:UNRESOLVED', '/FIXED', '/DYNAMICBASE:NO', '/INCREMENTAL:NO'}
        require(all(a in allowed or a.startswith(('/ENTRY:', '/BASE:', '/OUT:', '/MAP:', '/EXPORT:'))
                    or str(original).lower().endswith('.obj')
                    for a, original in zip(command_flags[1:], link_command[1:])), 'unsupported link option/input')
        require(all(flag in command_flags for flag in ('/MACHINE:X86', '/OPT:REF', '/OPT:NOICF', '/FIXED', '/NODEFAULTLIB')), 'missing link conditions')
        require(not any(a.startswith(('/LTCG', '/INCREMENTAL:YES', '/OPT:ICF', '/OPT:NOREF', '@')) for a in command_flags), 'unsupported rewriting/link option')
        actual = {Path(a).resolve() for a in link_command if str(a).lower().endswith('.obj')}
        require(actual == {o['path'].resolve() for o in objects}, 'link object closure mismatch')
        require(not any(str(a).lower().endswith('.lib') for a in link_command), 'explicit libraries unsupported')
    for command in compile_commands or []:
        require(not any(str(a).upper().startswith(('/GL', '/LTCG', '@')) for a in command), 'non-native compile option')
    directives = []
    for ob in objects:
        for section in ob['sections']:
            if section['name'] == '.drectve':
                directive = section['data'].decode().strip()
                tokens = re.findall(r'/[^\s]+', directive)
                require(all(t.lower().startswith(('/failifmismatch:', '/defaultlib:', '/alternatename:')) for t in tokens), 'unsupported object directive')
                directives.append(dict(object=str(ob['path']), text=directive))
    image = image_path.read_bytes()
    pe = struct.unpack_from('<I', image, 60)[0]
    require(image[pe:pe + 4] == b'PE\0\0', 'invalid PE signature')
    machine, count, _, _, _, optional, _ = struct.unpack_from('<HHIIIHH', image, pe + 4)
    require(machine == 0x14c and struct.unpack_from('<H', image, pe + 24)[0] == 0x10b, 'not I386 PE32')
    base = struct.unpack_from('<I', image, pe + 52)[0]
    mapped, code = [], []
    for i in range(count):
        name, size, rva, rawsize, start, _, _, _, _, flags = struct.unpack_from('<8sIIIIIIHHI', image, pe + 24 + optional + i * 40)
        require(start + rawsize <= len(image), 'truncated PE section')
        payload = image[start:start + rawsize] + bytes(max(0, size - rawsize))
        mapped.append((name.rstrip(b'\0').decode(), payload))
        if flags & 0x20000000 or flags & 0x20:
            code.append((name, base + rva, payload[:size]))
    require(len(code) == 1 and code[0][0].rstrip(b'\0') == b'.text', 'unsupported executable section layout')
    _, text_va, text = code[0]
    addresses = collections.defaultdict(set)
    map_text = map_path.read_text()
    require('Publics by Value' in map_text and 'Static symbols' in map_text, 'incomplete MAP sections')
    for line in map_text.splitlines():
        match = re.match(r'\s+[0-9A-Fa-f]{4}:[0-9A-Fa-f]{8}\s+(\S+)\s+([0-9A-Fa-f]{8})\s+(?:f\s+)?(\S+)\s*$', line)
        if match:
            addresses[match[1]].add((int(match[2], 16), match[3]))
    covered, retained, omitted, private, unresolved_sources = [False] * len(text), [], [], [], []
    providers = {s['name'] for ob in objects for s in ob['symbols'].values() if s['storage'] == 2 and s['section'] > 0}
    unresolved = {s['name'] for ob in objects for s in ob['symbols'].values() if s['storage'] == 2 and s['section'] == 0 and s['value'] == 0} - providers
    relocation_count = 0
    for ob in objects:
        path, symbols = ob['path'], ob['symbols']
        for section in ob['sections']:
            number, raw, relocations = section['number'], section['data'], section['relocations']
            row = dict(object=str(path), section=number, bytes=len(raw))
            definitions = [s for s in symbols.values() if s['section'] == number]
            incoming = [dict(offset=at, kind=kind, target=symbols[ix]['name']) for at, ix, kind in relocations if symbols[ix]['name'] in unresolved]
            candidates = {address - s['value'] for s in definitions for address, owner in addresses[s['name']] if owner == path.name}
            if incoming:
                require(section['flags'] & 0x1000 and section['flags'] & 0x20, 'unresolved source is not code COMDAT')
                require(not candidates, 'unresolved source has mapped definition')
                keys = [s for s in definitions if s['value'] == 0 and s['kind'] & 0x20 and s['storage'] in (2, 3)]
                require(len(keys) == 1, 'ambiguous unresolved source key')
                require(not addresses[keys[0]['name']], 'unresolved key present in MAP')
                selections = [s['aux'][14] for s in definitions if s['storage'] == 3 and len(s['aux']) == 18 and s['kind'] == 0]
                require(selections == [1], 'unsupported unresolved COMDAT selection')
                unresolved_sources.append(dict(**row, key=keys[0]['name'], storage=keys[0]['storage'], relocations=incoming))
                if keys[0]['storage'] == 3:
                    mask = [True] * len(raw)
                    for at, _, kind in relocations:
                        require(kind in (6, 20) and at + 4 <= len(raw), 'unsupported masked relocation')
                        mask[at:at + 4] = [False] * 4
                    require(any(mask), 'empty invariant mask')
                    hits = []
                    for name, payload in [('entire-file', image), *mapped]:
                        hits.extend((name, offset) for offset in range(len(payload) - len(raw) + 1) if all(not keep or payload[offset + j] == raw[j] for j, keep in enumerate(mask)))
                    require(not hits, 'private source has possible surviving bytes')
                    private.append(dict(**row, raw_hex=raw.hex(), mask_hex=bytes(255 if k else 0 for k in mask).hex(), matches=hits))
            if not section['flags'] & 0x20 or not raw:
                continue
            require(len(candidates) <= 1, 'ambiguous section placement')
            if not candidates:
                omitted.append(row)
                continue
            va = candidates.pop()
            expected = bytearray(raw)
            for at, ix, kind in relocations:
                symbol = symbols[ix]
                targets = {a for a, owner in addresses[symbol['name']] if symbol['storage'] == 2 or owner == path.name}
                require(len(targets) == 1 and kind in (6, 20) and at + 4 <= len(raw), 'unsupported/ambiguous retained relocation')
                value = targets.pop() + struct.unpack_from('<I', raw, at)[0] - (va + at + 4 if kind == 20 else 0)
                struct.pack_into('<I', expected, at, value & 0xffffffff)
                relocation_count += 1
            offset = va - text_va
            require(0 <= offset and offset + len(raw) <= len(text), 'section outside executable text')
            require(not any(covered[offset:offset + len(raw)]), 'overlapping retained contributions')
            require(text[offset:offset + len(raw)] == expected, 'relocated COFF bytes differ from PE')
            covered[offset:offset + len(raw)] = [True] * len(raw)
            retained.append(dict(**row, va=va))
    padding = [i for i, present in enumerate(covered) if not present]
    require(all(text[i] == 0xcc for i in padding), 'unaccounted executable bytes')
    inputs = [image_path, map_path, *(o['path'] for o in objects)]
    if link_command:
        inputs.append(Path(link_command[0]))
    return dict(schema=1, status='PASS', kind='read-only-coff-retention-certificate', executed=False,
                input_sha256={str(p): sha(p) for p in inputs}, link_command=link_command, compile_commands=compile_commands,
                command_conditions_checked=bool(link_command and compile_commands), directives=directives,
                text_bytes=len(text), retained_bytes=sum(covered), padding_bytes=len(padding), padding_value=204,
                retained_relocations=relocation_count, retained=retained, omitted_code=omitted,
                unresolved_symbols=sorted(unresolved), unresolved_source_sections=unresolved_sources,
                unresolved_relocations=sum(len(r['relocations']) for r in unresolved_sources), private_absence=private,
                boundary='No intact relocated private section survives; no algorithm/runtime or general linker-conformance acceptance.')


def strict_image_gate(image_path, map_path, object_sources, executions, work, primary, auxiliary):
    """541 comparison-only contract: fresh receipts and every executable byte.

    object_sources maps the exact renamed link input to its compiled source.
    No PE is executed here. All outputs/dependencies are pinned by the adapter.
    """
    image_path, work = Path(image_path), Path(work)
    objects = [Path(p) for p in object_sources]
    links = [row for row in executions if row['name'].startswith('link-')
             and any(str(a).upper() == '/OUT:' + str(image_path).upper() for a in row['command'])]
    require(len(links) == 1 and links[0]['exit_code'] == 0, 'missing successful exact link receipt')
    command = links[0]['command']
    flags = [str(a).upper() for a in command]
    require(all(flags.count(flag) == 1 for flag in ['/OPT:REF', '/OPT:NOICF', '/INCREMENTAL:NO',
            '/FORCE:UNRESOLVED', '/FIXED', '/NODEFAULTLIB']), 'missing/repeated strict link flags')
    require(collections.Counter(Path(a).resolve() for a in command if str(a).lower().endswith('.obj'))
            == collections.Counter(p.resolve() for p in objects), 'object multiset mismatch')
    compiles = []
    closure = []
    for obj, source in object_sources.items():
        obj, source = Path(obj), Path(source)
        matches = [row for row in executions if row['name'].startswith('compile-')
                   and '/FO' + str(obj.parent).upper() + '\\' in [str(a).upper() for a in row['command']]
                   and source.resolve() in [Path(a).resolve() for a in row['command'] if str(a).lower().endswith('.cpp')]]
        require(len(matches) == 1 and matches[0]['exit_code'] == 0, 'ambiguous/failed source compile')
        row = matches[0]
        require(sha(work / (row['name'] + '.log')) == row['log_sha256'], 'compile log changed')
        require('/FO' + str(obj.parent).upper() + '\\' in [str(a).upper() for a in row['command']], 'compile output directory mismatch')
        dep = obj.parent / 'dependencies' / (source.name + '.json')
        receipt = json.loads(dep.read_text(encoding='utf-8-sig'))['Data']
        require(Path(receipt['Source']).resolve() == source.resolve(), 'source dependency mismatch')
        require(obj.is_file() and source.is_file(), 'missing object/source')
        closure.append(dict(object=str(obj), object_sha256=sha(obj), source=str(source), source_sha256=sha(source),
                            compile=row['name'], dependency=str(dep), dependency_sha256=sha(dep)))
        if row['command'] not in compiles: compiles.append(row['command'])
    require(sha(work / (links[0]['name'] + '.log')) == links[0]['log_sha256'], 'link log changed')
    result = check_retention(image_path, map_path, objects, link_command=command, compile_commands=compiles)
    obj = coff(primary)
    defs = [s for s in obj['symbols'].values() if s['name'] == auxiliary and s['storage'] == 2 and s['section'] > 0]
    require(len(defs) == 1 and defs[0]['value'] == 0, 'auxiliary definition mismatch')
    section = obj['sections'][defs[0]['section'] - 1]
    selections = [s['aux'][14] for s in obj['symbols'].values() if s['section'] == section['number']
                  and s['storage'] == 3 and len(s['aux']) == 18 and s['kind'] == 0]
    require(section['flags'] & 0x1000 and section['data'] == bytes(4) and not section['relocations']
            and selections == [2], 'auxiliary must be exactzero4B ANY COMDAT')
    result.update(strict_gate=True, object_compile_closure=closure,
                  auxiliary=dict(symbol=auxiliary, object=str(primary), section=section['number'], bytes=4,
                                 raw_hex='00000000', selection=2),
                  explicit_incremental_no=True)
    return result


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe-report', type=Path, required=True)
    parser.add_argument('--executions', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[2]
    probe = json.loads(args.probe_report.read_text())
    for path, expected in probe['inputs_sha256'].items():
        require(sha(root / path) == expected, 'stale probe input: ' + path)
    executions = json.loads(args.executions.read_text())
    compiles = [r['command'] for r in executions if r['name'].startswith('compile-') and r['exit_code'] == 0]
    directory = args.probe_report.parent
    result = check_retention(directory / 'link-only-image.exe', directory / 'link-only-image.map',
                             [root / r['object'] for r in probe['objects']], link_command=probe['command'], compile_commands=compiles)
    result['input_sha256'].update({str(p): sha(p) for p in (Path(__file__), args.probe_report, args.executions)})
    args.out.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps({k: result[k] for k in ('status', 'text_bytes', 'retained_bytes', 'padding_bytes', 'retained_relocations', 'unresolved_relocations', 'command_conditions_checked', 'executed')}))
