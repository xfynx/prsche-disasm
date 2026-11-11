from pathlib import Path
import ast,hashlib,importlib.util,json,re,sys
root=Path(__file__).resolve().parents[5];run=Path(__file__).resolve().parent
sys.path.insert(0,str(root/'scripts/research'))
spec=importlib.util.spec_from_file_location('native',root/'scripts/research/verify-v2-native-batch.py');n=importlib.util.module_from_spec(spec);spec.loader.exec_module(n)
raw=(root/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
scope=json.loads((run/'scope-evidence.json').read_bytes());closure=scope['closure_hashes'];data=[];hits=[];near=[]
source=(run/'audio_callback_resource_564.cpp').read_text(encoding='utf-8')
for va,size,expected,symbol in [(0x5bd54c,21,b'\\real\\cmn\\locatbig.c\0','audio_resource_file_005bd54c'),(0x5bd524,39,b'BIG_locateentry: ENTRY "%s" NOT FOUND\n\0','audio_resource_missing_name_005bd524'),(0x5bd4fc,38,b'BIG_locateentry: ENTRY #%d NOT FOUND\n\0','audio_resource_missing_index_005bd4fc')]:
    b=n.pe_at(raw,va,size);assert b==expected
    match=re.search(r'\b'+symbol+r'\[\]="((?:[^"\\]|\\.)*)";',source);assert match
    actual=ast.literal_eval('"'+match.group(1)+'"').encode('ascii')+b'\0';assert actual==b
    data.append({'va':f'{va:08x}','bytes':size,'sha256':sha(b),'raw_hex':b.hex(),'candidate_symbol':symbol,'candidate_literal_matches':True})
for name in closure:
    if Path(name).suffix.lower() not in ('.h','.hpp','.cpp','.inc'):continue
    for line,text in enumerate((root/name).read_text(encoding='utf-8').splitlines(),1):
        for m in re.findall(r'(?<![0-9a-fA-F])[0-9a-fA-F]{8}(?![0-9a-fA-F])',text):
            v=int(m,16)
            if any(start<=v<start+size for start,size in [(0x5bd54c,21),(0x5bd524,39),(0x5bd4fc,38)]):hits.append({'file':name,'line':line,'text':text.strip()})
            if 0x5bd4bc<=v<0x5bd5a1:near.append({'file':name,'line':line,'text':text.strip()})
        if 'BIG_locateentry:' in text or 'locatbig.c' in text.lower():hits.append({'file':name,'line':line,'text':text.strip()})
result={'module_sha256':sha(raw),'baseline':'Run563 attempt 002','closure_files':len(closure),'witnesses':data,'exact_literal_hits':hits,'nearby_candidates':near,'boundary':'Literal/source census is navigation; overlapping named spans require independent review.'}
(run/'string-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print('strings',[(x['va'],x['bytes'],x['sha256']) for x in data],'hits',len(hits),'near',len(near))
