"""Bounded static ownership and original-PE census for Run579; never executes the game."""
from pathlib import Path
import hashlib, importlib.util, json, re, struct, sys

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / 'scripts/research'))
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader

spec = importlib.util.spec_from_file_location('native', ROOT / 'scripts/research/verify-v2-native-batch.py')
native = importlib.util.module_from_spec(spec)
spec.loader.exec_module(native)
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
build_path = ROOT / 'iterations/v2/001-original-recovery/runs/578-texture-transfer-integration/build-001.json'
cfg_path = build_path.with_name('build-config.json')
build, cfg = json.loads(build_path.read_bytes()), json.loads(cfg_path.read_bytes())
_, pins = ManifestReader(ROOT).resolve(build, 'source', 'crlf-to-lf', 'crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS = tuple(ROOT / p for p in cfg['source_include_dirs'])
closure = dep.source_hashes(build['compiled_source_roots'])
index = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
rows = {r['entry_va']: r for r in map(json.loads, (index / 'functions.jsonl').read_text().splitlines())}
targets = ['00554310', '00554530']
targets_data = ['005dedcc', '005def98', '005defe0', '005df0a8', '005df15c', '005df0cc', '006a3a28', '006a3a38', '006a3a54', '005df2c8']
candidate_intervals = [(int('005dedcc',16),int('005def98',16),'preference_payload'),
  (int('005defe0',16),int('005df0a8',16),'palette_payload'),
  (int('005def98',16),int('005defe0',16),'preference_pointer_table'),
  (int('005df0a8',16),int('005df0cc',16),'palette_pointer_table'),
  (int('006a3a28',16),int('006a3a2c',16),'preference_bss_pointer'),
  (int('006a3a38',16),int('006a3a3c',16),'palette_bss_pointer')]
candidate_intervals += [(int('005df15c',16)+20*i,int('005df160',16)+20*i,f'format_flag_{i}') for i in range(18)]
candidate_intervals += [(int('005df0cc',16)+16*i,int('005df0d0',16)+16*i,f'palette_flag_{i}') for i in range(9)]
raw = (ROOT / 'local/game/Porsche.exe').read_bytes()
assert hashlib.sha256(raw).hexdigest() == 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
registry_path = ROOT / 'iterations/v2/001-original-recovery/source/recovered/functions.json'
registry = json.loads(registry_path.read_bytes())
selected = {va: rows[va] for va in targets}
collisions = []
for f in registry['functions']:
    if f.get('module') != 'Porsche.exe' or 'entry_va' not in f:
        continue
    rr = rows.get(f['entry_va'], {}).get('ranges', [[f['entry_va'], f['entry_va']]])
    for va, row in selected.items():
        if any(int(a, 16) <= int(y, 16) and int(b, 16) >= int(x, 16)
               for a, b in rr for x, y in row['ranges']):
            collisions.append({'target': va, 'entry': f['entry_va'], 'status': f.get('status')})

def pe_map(va, size):
    pe = struct.unpack_from('<I', raw, 0x3c)[0]
    base = struct.unpack_from('<I', raw, pe + 52)[0]
    nsec, opt = struct.unpack_from('<HH', raw, pe + 6)
    opt = struct.unpack_from('<H', raw, pe + 20)[0]
    rva = int(va, 16) - base
    for i in range(nsec):
        at = pe + 24 + opt + i * 40
        vs, srva, rs, ro = struct.unpack_from('<IIII', raw, at + 8)
        if srva <= rva and rva + size <= srva + max(vs, rs):
            off = ro + (rva - srva)
            if rva - srva + size <= rs:
                return {'file_offset': off, 'raw': raw[off:off + size].hex(), 'section': raw[at:at+8].rstrip(b'\0').decode(errors='replace')}
            return {'file_offset': None, 'raw': None, 'section': raw[at:at+8].rstrip(b'\0').decode(errors='replace'), 'loader_zero': True}
    return {'file_offset': None, 'raw': None, 'unmapped': True}

refs = [r for r in map(json.loads, (index / 'references.jsonl').read_text().splitlines())
        if any(r.get('to_va', '').lower() == va.lower() for va in targets_data)]
calls = [r for r in map(json.loads, (index / 'calls.jsonl').read_text().splitlines())
         if r.get('from_function') in targets or r.get('to_function') in targets]
ownership = []
addr_pat = re.compile(r'(?<![0-9a-fA-F])([0-9a-fA-F]{8})(?![0-9a-fA-F])')
source_candidate_refs=[]; source_va_declarations=[]
source_decl_pat=re.compile(r'\b([A-Za-z_]\w*)_([0-9a-fA-F]{8})\s*(?:\[\s*(\d+)\s*\])?')
flag_addresses = [f'{0x005df15c+20*i:08x}' for i in range(18)] + [f'{0x005df0cc+16*i:08x}' for i in range(9)]
for name in closure:
    if Path(name).suffix not in ('.cpp', '.hpp', '.h', '.inc'):
        continue
    for no, line in enumerate((ROOT / name).read_text(encoding='utf-8-sig').splitlines(), 1):
        if any(x.lower() in line.lower() for x in targets + targets_data + flag_addresses + ['005df16c']):
            ownership.append({'file': name, 'line': no, 'text': line.strip()})
        for token in addr_pat.findall(line):
            address=int(token,16)
            if any(lo<=address<hi for lo,hi,_ in candidate_intervals):
                source_candidate_refs.append({'file':name,'line':no,'address':token.lower(),'text':line.strip()})
        for match in source_decl_pat.finditer(line):
            sym,addr,count=match.groups(); address=int(addr,16)
            if any(lo-0x100<=address<hi for lo,hi,_ in candidate_intervals):
                source_va_declarations.append({'file':name,'line':no,'symbol':f'{sym}_{addr.lower()}','start':addr.lower(),
                  'array_count':int(count) if count else None,'text':line.strip()})

pointer_tables = []
all_pointees = []
for start, end in [('005def98', '005defe0'), ('005df0a8', '005df0cc')]:
    begin, stop = int(start, 16), int(end, 16)
    b = pe_map(start, stop - begin)
    vals = []
    if b.get('raw'):
        data = bytes.fromhex(b['raw'])
        for i in range(0, len(data), 4):
            ptr = struct.unpack_from('<I', data, i)[0]
            item = {'slot': f'{begin+i:08x}', 'raw_word': f'{ptr:08x}', 'null': ptr == 0}
            if ptr:
                item['pointee_first16'] = pe_map(f'{ptr:08x}', 16)
            vals.append(item)
    pointer_tables.append({'span': f'{start}..{end}', 'end_exclusive': True, 'bytes': stop-begin, 'mapping': b, 'words': vals})
    cap = int('005def98' if start == '005def98' else '005df0a8', 16)
    for item in vals:
        ptr = int(item['raw_word'], 16)
        if item['null'] or ptr >= 0x006a0000:
            continue
        words, terminated = [], False
        va = ptr
        while va + 4 <= cap:
            mapped = pe_map(f'{va:08x}', 4)
            if not mapped.get('raw'):
                break
            value = struct.unpack('<I', bytes.fromhex(mapped['raw']))[0]
            words.append({'va': f'{va:08x}', 'value': f'{value:08x}'})
            va += 4
            if value == 0:
                terminated = True
                break
        all_pointees.append({'pointer_slot': item['slot'], 'start': f'{ptr:08x}',
          'scan_stop_exclusive': f'{va:08x}', 'bytes_read_inclusive_zero': len(words)*4,
          'words': words, 'terminated_at_first_zero': terminated,
          'safety_cap_exclusive': f'{cap:08x}', 'research_only_scan': True})

# Build byte-precise candidate intervals for index-reference/write and overlap audits.
all_refs = list(map(json.loads, (index / 'references.jsonl').read_text().splitlines()))
interval_refs = []
for lo, hi, label in candidate_intervals:
    hits = [r for r in all_refs if re.fullmatch(r'[0-9a-fA-F]{8}', r.get('to_va',''))
            and lo <= int(r['to_va'],16) < hi]
    interval_refs.append({'candidate': label, 'interval': [f'{lo:08x}', f'{hi:08x}'], 'references': hits})

def interval_union(intervals, outer):
    merged=[]
    for a,b in sorted((max(a,outer[0]),min(b,outer[1])) for a,b in intervals if a<outer[1] and b>outer[0]):
        if merged and a<=merged[-1][1]: merged[-1][1]=max(merged[-1][1],b)
        else: merged.append([a,b])
    holes=[]; cursor=outer[0]
    for a,b in merged:
        if cursor<a: holes.append([cursor,a])
        cursor=max(cursor,b)
    if cursor<outer[1]: holes.append([cursor,outer[1]])
    return {'merged_intervals':[[f'{a:08x}',f'{b:08x}'] for a,b in merged],
      'covered_bytes':sum(b-a for a,b in merged),'holes':[[f'{a:08x}',f'{b:08x}',b-a] for a,b in holes]}

payload_unions={}
for name,lo,hi in [('preference_payload',0x005dedcc,0x005def98),('palette_payload',0x005defe0,0x005df0a8)]:
    spans=[(int(x['start'],16),int(x['scan_stop_exclusive'],16)) for x in all_pointees
      if lo<=int(x['start'],16)<hi and x['bytes_read_inclusive_zero']]
    payload_unions[name]={'payload_bytes':hi-lo,'scan_intervals':[[f'{a:08x}',f'{b:08x}'] for a,b in sorted(spans)],
      'first_zero_read_union':interval_union(spans,(lo,hi))}

old_scope=json.loads((ROOT/'iterations/v2/001-original-recovery/runs/546-render-resource-allocation/scope-evidence.json').read_bytes())
body=next(x for x in old_scope['functions'] if x['va']=='00554310')
indexed_load_instructions=[x for x in body['instructions'] if re.search(r'5df15c|5df0a8|5df0cc|6a3a28|6a3a38',x)]
indexed_load_instructions += [x for x in body['instructions'] if x.startswith(tuple(f'{va} ' for va in ('00554498','0055449c','005544a0','005544a4','005544a6','005544a8','005544aa','005544af','005544b2','005544b5','005544b6','005544b8','005544ba','005544bc','005544be')))]
reused_sparse_bits=[(0x005df16c+20*i,0x005df170+20*i) for i in range(14)]
format_flags=[(0x005df15c+20*i,0x005df160+20*i) for i in range(18)]
flag_owner_overlap=[{'flag':f'{a:08x}..{b:08x}','Run546_bit':f'{c:08x}..{d:08x}','overlap':a<d and c<b}
  for (a,b),(c,d) in zip(format_flags[:14],reused_sparse_bits)]
function_data_overlaps=[]
for lo,hi,label in candidate_intervals:
    for f in registry['functions']:
        if f.get('module')!='Porsche.exe' or 'entry_va' not in f: continue
        rr=rows.get(f['entry_va'],{}).get('ranges',[[f['entry_va'],f['entry_va']]])
        if any(lo<=int(y,16)+1 and int(x,16)<hi for x,y in rr):
            function_data_overlaps.append({'candidate':label,'function':f['entry_va']})

pe = struct.unpack_from('<I', raw, 0x3c)[0]
opt = pe + 24
magic = struct.unpack_from('<H', raw, opt)[0]
dd_at = opt + (96 if magic == 0x10b else 112)
rel_rva, rel_size = struct.unpack_from('<II', raw, dd_at + 5*8)
base = struct.unpack_from('<I', raw, opt + 28)[0]
reloc_entries = []
if rel_rva and rel_size:
    # Map RVA through section table and walk IMAGE_BASE_RELOCATION blocks.
    def rva_offset(rva):
        nsec = struct.unpack_from('<H', raw, pe + 6)[0]
        optsz = struct.unpack_from('<H', raw, pe + 20)[0]
        for si in range(nsec):
            at = pe + 24 + optsz + si*40
            vs,srva,rs,ro = struct.unpack_from('<IIII', raw, at+8)
            if srva <= rva < srva + max(vs,rs): return ro + rva-srva
        return None
    cursor, endrel = rva_offset(rel_rva), rva_offset(rel_rva)+rel_size
    while cursor is not None and cursor + 8 <= endrel:
        page, blocksize = struct.unpack_from('<II', raw, cursor)
        if blocksize < 8 or cursor + blocksize > endrel: break
        for q in range(cursor+8, cursor+blocksize, 2):
            ent = struct.unpack_from('<H', raw, q)[0]
            kind, off = ent >> 12, ent & 0xfff
            if kind:
                reloc_entries.append({'va': f'{base+page+off:08x}', 'type': kind})
        cursor += blocksize
reloc_by_va = {x['va']:x['type'] for x in reloc_entries}
pointer_initializers = []
for start,end in [('005def98','005defe0'),('005df0a8','005df0cc')]:
    blob=bytes.fromhex(pe_map(start,int(end,16)-int(start,16))['raw'])
    for off in range(0,len(blob),4):
        slot=f'{int(start,16)+off:08x}'; value=struct.unpack_from('<I',blob,off)[0]
        is_format=start=='005def98'
        payload_base=0x005dedcc if is_format else 0x005defe0
        payload_name='render_texture_format_preferences_005dedcc' if is_format else 'render_texture_palette_preferences_005defe0'
        payload_limit=115 if is_format else 50
        empty_va=0x006a3a28 if is_format else 0x006a3a38
        if value==0: binding='nullptr'
        elif value==empty_va: binding='&render_texture_empty_format_006a3a28' if is_format else '&render_texture_empty_palette_006a3a38'
        else:
            assert value>=payload_base and (value-payload_base)%4==0 and (value-payload_base)//4<payload_limit
            ix=(value-payload_base)//4
            assert payload_base+ix*4==value
            binding=payload_name if ix==0 else f'{payload_name}+{ix}'
        pointer_initializers.append({'slot':slot,'raw_initializer':f'{value:08x}',
          'relocation_type':reloc_by_va.get(slot),'relocation_target':f'{value:08x}' if slot in reloc_by_va else None,
          'host_binding_expression':binding})
non_null_pointer_initializers=[x for x in pointer_initializers if x['raw_initializer']!='00000000']
pointer_relocation_audit={'non_null_initializer_count':len(non_null_pointer_initializers),
  'HIGHLOW_type3_count':sum(x['relocation_type']==3 for x in non_null_pointer_initializers),
  'non_null_slots_missing_relocation':[x['slot'] for x in non_null_pointer_initializers if x['relocation_type'] is None],
  'null_slots':[x['slot'] for x in pointer_initializers if x['raw_initializer']=='00000000'],
  'all_targets_match_raw_words':all(x['relocation_target']==x['raw_initializer'] for x in non_null_pointer_initializers if x['relocation_type']==3)}

record_bytes = []
for start, count, stride in [('005df15c', 18, 20), ('005df0cc', 9, 16)]:
    record_bytes.append({'base': start, 'count_hypothesis': count, 'stride': stride,
                         'raw_bytes': pe_map(start, count*stride),
                         'records': [{'va': f'{int(start,16)+i*stride:08x}', 'bytes': pe_map(f'{int(start,16)+i*stride:08x}', stride)} for i in range(count)]})

payloads_raw=[]
for name,start,count in [('format_preferences','005dedcc',115),('palette_preferences','005defe0',50)]:
    data=pe_map(start,count*4)
    blob=bytes.fromhex(data['raw'])
    words=[f'{struct.unpack_from("<I",blob,i*4)[0]:08x}' for i in range(count)]
    payloads_raw.append({'name':name,'start':start,'dword_count':count,'bytes':count*4,'raw_hex':data['raw'],'initializer_words':words})
flag_words=[]
for name,start,count,stride in [('format_flags','005df15c',18,20),('palette_flags','005df0cc',9,16)]:
    values=[]
    for i in range(count):
        va=f'{int(start,16)+i*stride:08x}'; m=pe_map(va,4)
        values.append({'index':i,'va':va,'raw_hex':m['raw'],'value':f'{struct.unpack("<I",bytes.fromhex(m["raw"]))[0]:08x}'})
    flag_words.append({'name':name,'count':count,'stride':stride,'fields':values})

result = {
  'scope': 'static census only; no implementation or acceptance claim',
  'provenance': {'original': 'local/game/Porsche.exe', 'sha256': hashlib.sha256(raw).hexdigest(),
    'index': 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d',
    'build': build_path.relative_to(ROOT).as_posix(), 'build_sha256': sha(build_path),
    'registry_sha256': sha(registry_path), 'effective_source_pins': len(pins), 'compiled_roots': len(build['compiled_source_roots']),
    'transitive_closure_files': len(closure)},
  'functions': [{'va': va, 'body_bytes': rows[va]['body_bytes'], 'ranges': rows[va]['ranges'],
     'raw': pe_map(va, rows[va]['body_bytes'])} for va in targets],
  'registry_overlaps': collisions,
  'calls': calls, 'data_references': refs, 'interval_references': interval_refs,
  'source_closure_hits': ownership, 'indexed_load_instructions': indexed_load_instructions,
  'source_address_references_inside_candidate_intervals':source_candidate_refs,
  'nearby_address_suffixed_source_declarations':source_va_declarations,
  'first_zero_read_union_and_holes': payload_unions,
  'format_flag_vs_Run546_sparse_bit_fields': flag_owner_overlap,
  'candidate_overlaps_with_registered_function_bodies': function_data_overlaps,
  'source_owner_audit': {'full_build578_source_closure_scanned_for_all_8_digit_VAs_and_nearby_VA_suffixed_declarations':True,
    'covering_aggregate_owner_found':False,
    'existing_owner':'Run546 render_texture_format_bits_005df16c is separately represented as sparse DWORDs at +16 of each stride20 location; there is no overlap with proposed flags at +0. Run577 owners 006a3a54 and 005df2c8 are distinct addresses.',
    'candidate_intervals_unowned_before_Run579':True},
  'pointer_tables': pointer_tables, 'pointer_initializers_and_relocations': pointer_initializers,
  'pointer_relocation_audit':pointer_relocation_audit,
  'pointee_first_zero_scans': all_pointees, 'record_spans': record_bytes,
  'full_payload_initializers':payloads_raw,'sparse_flag_initializers':flag_words,
  'comparator_access': {'preference_and_palette_flags_are_direct_memory_loads':True,
    'pointer_list_reads_continue_until_first_zero':True,
    'matched_item_adds_current_rank_then_continues':True,
    'evidence_instructions':['005544a4 cmp eax, edi','005544a8 add ebx, ecx','005544af mov eax, dword ptr [edx + 4]','005544b2 add edx, 4','005544b5 inc ecx','005544b6 test eax, eax','005544b8 jne 0x5544a0'],
    'direct_indexed_stores_to_candidate_fields_in_54310':False,
    'dynamic_writes_to_the_pointed_BSS_objects_proven':False},
  'candidate_data_spans': [{'va': va, 'bytes': 4, 'mapping': pe_map(va, 4)} for va in targets_data],
  'known_reuse': {'006a3a54': 'accepted Run577 loader-zero driver-info pointer owner',
    '005df2c8': 'accepted Run577 initialized function-pointer owner; raw value 00554310; host binding to comparator',
    '005df16c': 'accepted Run546 14-element sparse DWORD owner; elements 20 bytes apart in original storage, do not cover with cloned contiguous record'},
  'proposed_owner_names': {'005dedcc':'render_texture_format_preferences_005dedcc[115]',
    '005defe0':'render_texture_palette_preferences_005defe0[50]',
    '005def98':'render_texture_format_preference_table_005def98[18]',
    '005df0a8':'render_texture_palette_preference_table_005df0a8[9]',
    '005df15c':'render_texture_format_flags_005df15c[18]',
    '005df0cc':'render_texture_palette_flags_005df0cc[9]',
    '006a3a28':'render_texture_empty_format_006a3a28',
    '006a3a38':'render_texture_empty_palette_006a3a38'},
  'candidate_interval_summary': [{'name': n, 'start': f'{a:08x}', 'end_exclusive': f'{b:08x}', 'bytes': b-a} for a,b,n in candidate_intervals],
  'data_bounds': {
    'pointer_arrays': {'005def98': '72-byte initialized pointer table, 18 slots; one null slot at 005defc0. Non-null initialized pointers in slots 1..9 and 11..17 point into 005dedcc..005def98; slot0 points to BSS 006a3a28.',
      '005df0a8': '36-byte initialized pointer table, nine slots; slot0 points to BSS 006a3a38; slots1..6 and8 point into 005defe0..005df0a8; slot7 at 005df0c4 is null.'},
    'bss_pointees': {'006a3a28': 'loader-zero 4-byte pointer target; other bytes of object unknown',
      '006a3a38': 'loader-zero 4-byte pointer target; other bytes of object unknown'},
    'record_views': {'005df15c': '18 candidate first DWORD flags at stride20, admitted indices 0..17 only; fixed-stride span ends at 005df2c4 before the separate canonical preferred-bytes owner. Sparse Run546 bits are separate +16 fields at proved indices; remaining record fields are unknown.',
      '005df0cc': 'nine candidate first DWORD flags at stride16, admitted indices 0..8 only; span ends at 005df15c. Aggregate record meaning and other fields are not inferred.',
      'unknown_extent': True},
    'terminators': 'Comparator walk is bounded by first zero DWORD in each nonnull pointed list. Scans above are limited to the containing initialized data cap and are research-only.'}
}
(RUN / 'data-evidence.json').write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8', newline='\n')

# Emit the recovered writable PE data owners from the same pinned bytes.
owner_decls = [
  ('render_texture_format_preferences_005dedcc','std::uint32_t','[115]'),
  ('render_texture_palette_preferences_005defe0','std::uint32_t','[50]'),
  ('render_texture_format_preference_table_005def98','std::uint32_t*','[18]'),
  ('render_texture_palette_preference_table_005df0a8','std::uint32_t*','[9]'),
  ('render_texture_format_flags_005df15c','std::uint32_t','[18]'),
  ('render_texture_palette_flags_005df0cc','std::uint32_t','[9]'),
  ('render_texture_empty_format_006a3a28','std::uint32_t',''),
  ('render_texture_empty_palette_006a3a38','std::uint32_t','')]
header = '#pragma once\n#include <cstdint>\n\nnamespace porsche {\n'
for name,typ,suffix in owner_decls: header += f'extern {typ} {name}{suffix};\n'
header += '}\n'

def dword_array(name, vals, comment):
    lines=[f'// {comment}',f'std::uint32_t {name}[{len(vals)}] = {{']
    for i in range(0,len(vals),6):
        lines.append('    '+', '.join(f'0x{int(v,16):08x}u' for v in vals[i:i+6])+(',' if i+6<len(vals) else ''))
    lines.append('};')
    return '\n'.join(lines)

cpp=['#include "format_preferences_579.hpp"','', '#include <cstddef>','',
  'namespace porsche {','static_assert(sizeof(void*) == 4, "original pointer tables require Win32");','']
cpp.append(dword_array('render_texture_format_preferences_005dedcc',payloads_raw[0]['initializer_words'],'Original writable .data payload 005dedcc..005def97 (460 bytes).'))
cpp.append('')
cpp.append(dword_array('render_texture_palette_preferences_005defe0',payloads_raw[1]['initializer_words'],'Original writable .data payload 005defe0..005df0a7 (200 bytes).'))
cpp.append('')
for table_name, start, end, payload_va, payload_name, payload_count, empty_name in [
  ('render_texture_format_preference_table_005def98','005def98','005defe0',0x005dedcc,
   'render_texture_format_preferences_005dedcc',115,'render_texture_empty_format_006a3a28'),
  ('render_texture_palette_preference_table_005df0a8','005df0a8','005df0cc',0x005defe0,
   'render_texture_palette_preferences_005defe0',50,'render_texture_empty_palette_006a3a38')]:
    table_blob=bytes.fromhex(pe_map(start,int(end,16)-int(start,16))['raw'])
    vals=[struct.unpack_from('<I',table_blob,i)[0] for i in range(0,len(table_blob),4)]
    expr=[]
    for v in vals:
        if v==0:
            expr.append('nullptr')
        elif v==int('006a3a28' if 'format_' in table_name else '006a3a38',16):
            expr.append('&'+empty_name)
        else:
            offset=v-payload_va
            assert offset>=0 and offset%4==0 and offset//4<payload_count
            assert payload_va+offset==v
            expr.append(payload_name if offset==0 else f'{payload_name}+{offset//4}')
    cpp.append(f'// Original relocation table {start} ({len(vals)} entries), preserving null entries and target offsets.')
    cpp.append(f'std::uint32_t* {table_name}[{len(vals)}] = {{\n    '+',\n    '.join(expr)+'\n};')
    cpp.append('')
for name, start, count, stride in [('render_texture_format_flags_005df15c','005df15c',18,20),('render_texture_palette_flags_005df0cc','005df0cc',9,16)]:
    vals=[f'{struct.unpack("<I",bytes.fromhex(pe_map(f"{int(start,16)+i*stride:08x}",4)["raw"]))[0]:08x}' for i in range(count)]
    cpp.append(dword_array(name,vals,f'Original writable first-DWORD field values at {start}+{stride}*i; bounded indices 0..{count-1}.'))
    cpp.append('')
cpp += ['std::uint32_t render_texture_empty_format_006a3a28 = 0u;',
        'std::uint32_t render_texture_empty_palette_006a3a38 = 0u;', '', '}']
(RUN/'format_preferences_579.hpp').write_text(header,encoding='utf-8',newline='\n')
(RUN/'format_preferences_579.cpp').write_text('\n'.join(cpp)+'\n',encoding='utf-8',newline='\n')

print(json.dumps({'closure_files': len(closure), 'pins': len(pins), 'collisions': collisions,
  'function_bytes': {x: rows[x]['body_bytes'] for x in targets}, 'call_count': len(calls),
  'reference_count': len(refs), 'source_hits': len(ownership),
  'tables': [(x['span'], len(x['words'])) for x in pointer_tables]}))
