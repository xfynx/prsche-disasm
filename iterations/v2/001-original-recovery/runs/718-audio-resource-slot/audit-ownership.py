"""Search the actual accepted compiler roots and recursive local header closure."""
import json
import pathlib
import re

root = pathlib.Path(__file__).resolve().parents[5]
run = pathlib.Path(__file__).resolve().parent
baseline = root/'iterations/v2/001-original-recovery/runs/714-audio-group-decode-integration'
build = json.loads((baseline/'build-001.json').read_text())
config = json.loads((baseline/'build-config.json').read_text())
include = [root/p for p in config['source_include_dirs']]
include.append(root/'iterations/v2/001-original-recovery/source/include')
pending = [root/p for p in build['compiled_source_roots']]
seen = set()
while pending:
    p = pending.pop().resolve()
    if p in seen:
        continue
    seen.add(p)
    for name in re.findall(r'^\s*#\s*include\s*["<]([^">]+)[">]', p.read_text(encoding='utf-8'), re.M):
        found = next((v for v in [p.parent/name]+[d/name for d in include] if v.is_file()), None)
        if found:
            pending.append(found)
hits = {n: [] for n in ['audio_resource_map_count_006b48a0','audio_resource_map_006b48a4']}
for p in seen:
    text = p.read_text(encoding='utf-8')
    for n in hits:
        if re.search(r'\b(?:std::uint32_t|U|unsigned(?:\s+int)?)\s+'+n+r'\s*=\s*0\s*;', text):
            hits[n].append(p.relative_to(root).as_posix())
assert all(len(v)==1 and '452-audio-record-resources' in v[0] for v in hits.values()), hits
e = json.loads((run/'evidence.json').read_text())
e['accepted_closure']['source_header_files_searched'] = len(seen)
e['accepted_closure']['search_method'] = '414 actual compiled_source_roots plus recursively resolved local include closure using accepted build include_dirs. The source pin manifest is a delta and is not treated as the full closure.'
e['accepted_closure']['canonical_definitions'] = hits
registry = json.loads((root/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text(encoding='utf-8'))['functions']
index = {f['entry_va']:f for f in map(json.loads,(root/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text(encoding='utf-8').splitlines())}
overlaps = []
for f in registry:
    if f['module'] != 'Porsche.exe':
        continue
    ranges = f.get('body_ranges', []) + index.get(f['entry_va'], {}).get('ranges', [])
    for lo, hi in ranges:
        if int(lo,16)<=0x58f7db and int(hi,16)>=0x58f7a0:
            overlaps.append({'entry_va':f['entry_va'],'range':[lo,hi]})
assert not overlaps, overlaps
e['ownership_overlap'] = {'registry_entries':len(registry),'main_index_and_registry_body_ranges':overlaps,'supplement_search':'No 0058f7/0058f2/0058a9 spans occur in any original-index-supplement.json. Full supplement hashes are pinned in scope-evidence.json.'}
(run/'evidence.json').write_text(json.dumps(e,indent=2)+'\n',encoding='utf-8',newline='\n')
print('canonical definitions:',hits,'closure files:',len(seen),'overlaps:',overlaps)
