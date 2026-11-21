import hashlib,json,pathlib,subprocess
root=pathlib.Path(__file__).resolve().parents[5]
run=pathlib.Path(__file__).resolve().parent
out=root/'local/experiments/v2-canonical-abi-bindings-723-audit'
out.mkdir(parents=True,exist_ok=True)
tool=root/'local/tools/BuildTools/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x86/dumpbin.exe'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
aliases=json.loads((run/'bindings.json').read_text())
objects={
'application_sim_teardown_691':list(aliases)[0],
'application_view_lifecycle_693':list(aliases)[1],
'audio_period_callback_probe_697':list(aliases.values())[0],
'entry_fe_scene_leaves_702':list(aliases.values())[1]}
coff=[]
for name,symbol in objects.items():
 p=root/'local/builds/v2/a720/entry-289/porsche_game_entry_bridges.dir/Release'/f'{name}.obj'
 result=subprocess.run([str(tool),'/symbols',str(p)],capture_output=True,check=True)
 text=result.stdout.decode('utf-8',errors='replace')
 (out/(name+'-symbols.txt')).write_bytes(result.stdout)
 matched=[line.strip() for line in text.splitlines() if symbol in line]
 assert len(matched)==1,(name,matched)
 if name.endswith(('691','693')):assert 'UNDEF' in matched[0]
 else:assert 'UNDEF' not in matched[0]
 coff.append({'path':p.relative_to(root).as_posix(),'sha256':sha(p),'symbol':symbol,'line':matched[0]})
proofs=[]
for tag,attempt,cases,affected in [('audio','003',1280,1024),('scene','002',58,6)]:
 p=root/f'local/experiments/v2-canonical-abi-bindings-723-{tag}/{attempt}/receipt.json'
 r=json.loads(p.read_text())
 assert r['status']=='PASS'
 assert all(sha(root/q)==h for q,h in r['inputs_sha256'].items())
 proofs.append({'tag':tag,'receipt':p.relative_to(root).as_posix(),'sha256':sha(p),'variants':['/Od','/O2'],'regression_cases_per_variant':cases,'binding_cases_per_variant':affected,'material_controls':len(r['mutation_controls']),'input_pins':len(r['inputs_sha256']),'output_pins':len(r['outputs_sha256']),'address_identity':'Legacy symbol address equals actual canonical provider address before any scenarios'})
listing=(root/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm').read_text(encoding='utf-8').splitlines()
snippets=[]
for needle in ['00469097  ','004a8d98  ']:
 i=next(i for i,line in enumerate(listing) if line.startswith(needle))
 snippets+=listing[i-8:i+10]+['']
(run/'original-callsite-listing.asm').write_text('\n'.join(snippets),encoding='utf-8',newline='\n')
reg=json.loads((root/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text(encoding='utf-8'))['functions']
owners=[f for f in reg if f['module']=='Porsche.exe' and f['entry_va'] in ['004521c0','004a6c90']]
assert len(owners)==2
e={'schema':1,'run':723,'classification':'Two ABI linker aliases; zero new original functions, bytes, cells or game TUs','aliases':aliases,'expected_closed_names':list(aliases),'expected_new_names':[],'canonical_provider_objects':{list(aliases)[0]:'audio_period_callback_probe_697.obj',list(aliases)[1]:'entry_fe_scene_leaves_702.obj'},'coff':coff,'canonical_owners':owners,'proof':proofs,
'callsite_evidence':{'004a8cd0':'CALL004a6c90 at004a8d98, original pushes kind3 and path; caller cleans8B and never consumes EAX. Run691 typed kind int32 and canonical697 uint32 use identical32-bit stack bits.','00468fb0':'Original tail JMP004521c0 at00469097. Accepted Run693 startup_sequence_call_00468fb0 is void and explicitly discards scene_transfer_enter return. Canonical702 is cdecl void; raw EAX is unclaimed and untouched by the alias. No wrapper return is manufactured.'},
'cmake':'include bindings.cmake after the accepted baseline. It adds two /alternatename options to porsche_original_game_link. No target_sources, include directories, registry functions or production native-callers.cpp.',
'attempts':{'audio001':'Preserved link failure: combined fixture caller TU referenced both old symbols while only audio canonical provider was linked.','audio002_scene001':'Passed before explicit runtime legacy/canonical address-identity assertion was added.','audio003_scene002':'Final PASS with address identity, original-vs-canonical through legacy caller and material callsite controls.'},
'boundary':'Only existing Run691/693 ABI contracts are bound. Scene return remains unspecified; future consumers of its pointer return require a new contract. Canonical body acceptance is reused, these are regression cases rather than new recoveries. Callee stubs are fixture-only inherited controlled endpoints. Full caller composition, live resources/audio/scenes/startup remain open.'}
(run/'evidence.json').write_text(json.dumps(e,indent=2)+'\n',encoding='utf-8',newline='\n')
print('Run723 audit PASS:',len(coff),'actual game COFF symbols,',len(proofs),'native receipts; zero pin drift')
