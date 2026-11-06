"""Bounded541 scene/multiobject adapter around frozen498's Athlon machinery."""
from pathlib import Path
import argparse,hashlib,importlib.util,json,os,struct,subprocess,sys,time
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts/research'),str(ROOT/'local/tools/python-unicorn')]
def load(name,path):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
pilot=load('pilot498for541',ROOT/'iterations/v2/001-original-recovery/runs/498-audio-pcm-3dnow-cpp/compare.py')
native,coff,unicorn,capstone=pilot.native,pilot.coff,pilot.unicorn,pilot.capstone
UcError=pilot.UcError;x=pilot.x;dependency_paths=pilot.dependency_paths
image_info,exports,fpstate=pilot.image_info,pilot.exports,pilot.fpstate
ARENA,STACK,SP,HARNESS,EXIT=pilot.ARENA,pilot.STACK,pilot.SP,pilot.HARNESS,pilot.EXIT
FPREGS,GPRS,GPR_SEED=pilot.FPREGS,pilot.GPRS,pilot.GPR_SEED
digest=pilot.digest;sha=pilot.sha;relative=pilot.relative;save=pilot.save
CFG=json.loads((RUN/'config.json').read_text(encoding='utf-8'))
retention=load('coff_retention541',RUN/'coff_retention.py')
CERTIFIED_IMAGES={}

def gate_image(image,map_path,object_sources,executions,work,primary):
 result=retention.strict_image_gate(image,map_path,object_sources,executions,work,primary,CFG['candidate_auxiliary_symbols'][0])
 raw=Path(image).read_bytes();info=image_info(raw)
 assert info['directories'][1]==info['directories'][5]==(0,0),'imports/base relocations forbidden'
 assert set(exports(raw,info))==set(CFG['exports']),'exact exports'
 CERTIFIED_IMAGES[digest(raw)]=result
 return result

def validate_original_data(raw):
 info=image_info(raw);rows=[]
 for row in CFG['original_data']:
  va=int(row['va'],16);rva=va-info['base'];end=rva+row['bytes']
  section=next(s for s in info['sections'] if s[1]<=rva and end<=s[1]+s[0])
  vsize,base,rsize,offset=section
  if row['kind']=='file-backed':
   data=native.pe_at(raw,va,row['bytes']);assert end<=base+rsize
  else:
   assert row['kind']=='loader-zero' and rva>=base+rsize,('not PE virtual zero tail',row,section)
   data=bytes(row['bytes'])
  assert digest(data)==row['sha256'];rows.append(dict(**row,section=list(section)))
 return rows

class Machine(pilot.Machine):
 def __init__(self,raw,entrypoints,model,bounds=None):
  self.original=bounds is not None;self.symbols=dict(entrypoints)
  if self.original:assert digest(raw)==CFG['original_sha256'],'original raw hash'
  else:assert digest(raw) in CERTIFIED_IMAGES,'strict code/object gate required before Machine construction'
  if self.original:self.symbols.update({k:int(v,16) for k,v in CFG['original_symbols'].items()})
  super().__init__(raw,self.symbols,model,bounds)
  if not self.original:self.allowed=[(r['va'],r['va']+r['bytes']) for r in CERTIFIED_IMAGES[digest(raw)]['retained']]
  self.regions=[('arena',ARENA,0x8000),('window',self.symbols['window'],80),('lut',self.symbols['lut'],1024)]
  assert self.symbols['tail']==self.symbols['lut']+832,'canonical832B tail adjacency'
  assert digest(bytes(self.uc.mem_read(self.symbols['window'],80)))==CFG['original_data'][0]['sha256'],'raw80B window'
  assert bytes(self.uc.mem_read(self.symbols['lut'],1024))==bytes(1024),'production loaderzero LUT/tail'
  self.initial_window=bytes(self.uc.mem_read(self.symbols['window'],80))
  self.uc.mem_write(HARNESS,b'\xdb\xe3');self.uc.emu_start(HARNESS,HARNESS+2,count=8)
  for name,value in GPR_SEED.items():self.uc.reg_write(GPRS[name],value)
  self.uc.mem_write(SP,struct.pack('<I',EXIT));self.uc.emu_start(self.symbols['initialize'],EXIT,count=30000)
  assert self.uc.reg_read(x.UC_X86_REG_EIP)==EXIT,'canonical initializer returned'
  assert bytes(self.uc.mem_read(self.symbols['window'],80))==self.initial_window
  self.initial_table=bytes(self.uc.mem_read(self.symbols['lut'],1024));assert self.initial_table[832:]==bytes(192)
  self.initialization=dict(window_sha256=digest(self.initial_window),lut_sha256=digest(self.initial_table[:832]),tail_sha256=digest(self.initial_table[832:]),adjacency=True)

 def token(self,value):
  for index,(_,base,size) in enumerate(self.regions,1):
   if base<=value<=base+size:return index*0x10000000+value-base
  if self.scratch and self.scratch-8<=value<=self.scratch+112:return 0x40000008+value-self.scratch
  for index,name in enumerate(CFG['exports']):
   if value==self.symbols[name]:return 0xf0000000+index
  return value

 def region(self,address,size):
  for index,(_,base,length) in enumerate(self.regions,1):
   if base<=address and address+size<=base+length:return index*0x10000000+address-base
  if self.scratch and self.scratch-8<=address and address+size<=self.scratch+112:return 0x40000008+address-self.scratch
  return None

 def normalized(self,base,data):
  data=bytearray(data)
  for field in self.pointer_fields:
   if base<=field and field+4<=base+len(data):
    value=struct.unpack_from('<I',data,field-base)[0];struct.pack_into('<I',data,field-base,self.token(value))
  return bytes(data)

 def memory_state(self):
  return [digest(self.normalized(base,bytes(self.uc.mem_read(base,size)))) for _,base,size in self.regions]

 def boundary(self,phase,state,output):
  record=[phase,self.normalized(state,bytes(self.uc.mem_read(state,20))).hex(),self.memory_state(),fpstate(self.uc)]
  if phase=='exit' and STACK<=output<STACK+0x10000:record.append(digest(bytes(self.uc.mem_read(output,112))))
  self.boundaries.update(json.dumps(record,separators=(',',':')).encode()+b'\n');self.boundary_count+=1

 def code(self,uc,address,size,user):
  if not self.active:
   assert any(a<=address and address+size<=b for a,b in self.allowed) or HARNESS<=address<HARNESS+0x1000,('unexpected initialization/seed code',hex(address))
   return
  assert any(a<=address<b for a,b in self.allowed),('unexpected code',hex(address))
  if self.pending_return and address==self.pending_return:
   state,output=self.kernel_state,self.kernel_output
   if self.prefix_check:assert bytes(uc.mem_read(output-8,8))==self.prefix_before,'3DNow unexpectedly wrote history prefix'
   self.boundary('exit',state,output);self.pending_return=0;self.in_kernel=False
  if address==self.symbols['decode']:
   self.pending_return=struct.unpack('<I',uc.mem_read(uc.reg_read(x.UC_X86_REG_ESP),4))[0]
   state=struct.unpack('<I',uc.mem_read(uc.reg_read(x.UC_X86_REG_ESP)+4,4))[0];output=struct.unpack('<I',uc.mem_read(state+16,4))[0]
   self.kernel_state,self.kernel_output=state,output
   if STACK<=output<STACK+0x10000:self.scratch=output
   self.prefix_check=not (output-8<state+20 and state<output)
   self.prefix_before=bytes(uc.mem_read(output-8,8));self.in_kernel=True;self.boundary('entry',state,output)
  if address in self.pf:
   self.fp_events.update(json.dumps([self.pf[address],fpstate(uc)],separators=(',',':')).encode()+b'\n');self.fp_count+=1

 def memory(self,uc,access,address,size,value,user):
  if not self.active or not self.in_kernel:return
  location=self.region(address,size)
  if location is None:
   # Stack arguments/private integer transport are not game data accesses.
   assert not (ARENA<=address<ARENA+pilot.ARENA_SIZE),('arena escape',hex(address),size)
   return
  kind=1 if access==unicorn.UC_MEM_WRITE else 0
  payload=(value&((1<<(size*8))-1)).to_bytes(size,'little') if kind else bytes(uc.mem_read(address,size))
  if size==4 and address in self.pointer_fields:payload=struct.pack('<I',self.token(int.from_bytes(payload,'little')))
  self.events.update(struct.pack('<BII',kind,location,size)+payload);self.event_count+=1

 def run(self,case):
  uc=self.uc;self.active=False;self.in_kernel=False;self.pending_return=0;self.scratch=0
  uc.mem_write(ARENA,b'\x39\xa7\xd3\x65'*(0x8000//4));uc.mem_write(STACK,b'\xa5'*0x10000)
  uc.mem_write(self.symbols['window'],self.initial_window);uc.mem_write(self.symbols['lut'],self.initial_table)
  if 'special' in case:
   values=pilot.SPECIAL
   uc.mem_write(self.symbols['window'],struct.pack('<20I',*[values[(i+case['special'])%len(values)] for i in range(20)]))
   uc.mem_write(self.symbols['lut'],struct.pack('<256I',*[values[(i*3+case['special'])%len(values)] for i in range(256)]))
  state=ARENA+0x100+case.get('sta',0);source=ARENA+0x1000+case.get('sa',0);destination=ARENA+0x4000+case.get('da',0)
  if case.get('state_alias'):state=self.symbols[case['state_alias']]+case.get('state_offset',0)
  if case.get('input_alias'):source=self.symbols[case['input_alias']]+case.get('input_offset',0)
  else:
   payload=bytearray((i*13+7)&255 for i in range(128))
   for i in range(8):payload[i*15]=case.get('header',0)
   uc.mem_write(source,bytes(payload))
  alias=case.get('output_alias')
  if alias=='input':destination=source+case.get('delta',0)
  elif alias=='state':destination=state+case.get('delta',4)
  elif alias:destination=self.symbols[alias]+case.get('delta',0)
  h1=case.get('h1',0x3e123456);h2=case.get('h2',0xbe654321)
  self.pointer_fields={state+12,state+16}
  if case['kernel']=='decode':
   uc.mem_write(state,struct.pack('<5I',case['count']&0xffffffff,h1,h2,source,destination));args=[state]
  else:
   obj=ARENA+0x200;state=obj+12;self.pointer_fields={obj+4,obj+0x18,obj+0x1c,obj+0x20,obj+0x38}
   words={4:self.symbols[case['kernel']],0xc:0,0x10:h1,0x14:h2,0x18:source,0x1c:destination,0x20:source,0x24:168,0x28:case.get('position',0),0x2c:case.get('start',29),0x30:case.get('end',83),0x34:case.get('carry',0),0x38:self.symbols['decode'],0x3c:h1,0x40:h2}
   for offset,value in words.items():uc.mem_write(obj+offset,struct.pack('<I',value))
   uc.mem_write(obj+0xa,b'\x83\xff');uc.mem_write(obj+0x4c,struct.pack('<55I',*[0x3e000001+i*0x10001 for i in range(55)]))
   args=[obj,case['count']&0xffffffff,ARENA+0x800,destination,0xffffff83]
  self.events,self.fp_events,self.boundaries=hashlib.sha256(),hashlib.sha256(),hashlib.sha256();self.event_count=self.fp_count=self.boundary_count=0
  for i,reg in enumerate(FPREGS):uc.reg_write(reg,(0x8000000000000000+(case.get('mmx',0)*0x123456789abcdef+i),0x3fff))
  cw,depth,sticky,mxcsr=case.get('cw',0x37f),case.get('depth',0),case.get('sticky',0),case.get('mxcsr',0x1f80)
  seed=b'\xdb\xe3'+b'\xd9\x2d'+struct.pack('<I',HARNESS+0x100)+b'\xd9\xe8'*depth
  uc.mem_write(HARNESS,seed);uc.mem_write(HARNESS+0x100,struct.pack('<H',cw));uc.emu_start(HARNESS,HARNESS+len(seed),count=32)
  uc.reg_write(x.UC_X86_REG_FPSW,uc.reg_read(x.UC_X86_REG_FPSW)|sticky);uc.reg_write(x.UC_X86_REG_MXCSR,mxcsr);seeded=fpstate(uc)
  assert seeded[0]==cw and seeded[1]>>11&7==((-depth)&7)
  stack=struct.pack('<'+'I'*(len(args)+1),EXIT,*args);uc.mem_write(SP,stack)
  for name,value in GPR_SEED.items():uc.reg_write(GPRS[name],value)
  uc.reg_write(x.UC_X86_REG_EFLAGS,0x202);self.active=True
  try:
   uc.emu_start(self.symbols[case['kernel']],EXIT,count=200000);assert uc.reg_read(x.UC_X86_REG_EIP)==EXIT,'instruction budget/invalid return'
   if self.pending_return and uc.reg_read(x.UC_X86_REG_EIP)==self.pending_return:
    if self.prefix_check:assert bytes(uc.mem_read(self.kernel_output-8,8))==self.prefix_before,'3DNow unexpectedly wrote history prefix'
    self.boundary('exit',self.kernel_state,self.kernel_output);self.pending_return=0
  finally:self.active=False
  regs={name:uc.reg_read(GPRS[name]) for name in ['ebx','ebp','esi','edi','esp']}
  assert regs=={**{name:GPR_SEED[name] for name in ['ebx','ebp','esi','edi']},'esp':SP+4},('cdecl ABI',regs)
  assert bytes(uc.mem_read(SP,4))==stack[:4] and bytes(uc.mem_read(SP+len(stack),32))==b'\xa5'*32 and bytes(uc.mem_read(STACK,32))==b'\xa5'*32
  result=dict(memory=self.memory_state(),events=self.events.hexdigest(),event_count=self.event_count,fp_events=self.fp_events.hexdigest(),fp_event_count=self.fp_count,initial_fp=seeded,final_fp=fpstate(uc),preserved=regs,boundaries=self.boundaries.hexdigest(),boundary_count=self.boundary_count)
  if case['kernel']!='decode':result['used_result']=uc.reg_read(x.UC_X86_REG_EAX)
  return result

def cases():
 rows=[]
 def add(group,kernel='decode',**kw):rows.append(dict(name=f'{group}-{kernel}-{len(rows):04d}',kernel=kernel,group=group,**kw))
 for count in [0,-1,-2,-28,*range(1,58)]:add('count',count=count)
 for header in range(256):
  for count in [1,29,56]:add('headers',count=count,header=header)
 for sa in range(16):
  for da in range(16):add('align',count=29,sa=sa,da=da,sta=(sa+da)&3)
 for offset in [-17,-8,-4,-1,0,1,2,4,8,17]:
  for count in [1,28,29,56]:add('alias',count=count,output_alias='input',delta=offset,header=0x23)
 for name,offsets in [('lut',[0,16,448,832]),('window',[0,16,48])]:
  for offset in offsets:add('alias',count=29,input_alias=name,input_offset=offset)
 # Offset832 has only the independently proved192B virtual tail; one112B
 # block fits. Two blocks would write32B of unproved adjacent original state.
 for offset in [0,16,448,832]:add('alias',count=1 if offset==832 else 29,output_alias='lut',delta=offset)
 for name,offset in [('window',0),('window',48),('lut',448)]:add('alias',count=29,state_alias=name,state_offset=offset,header=0x23)
 for offset in [4,8,12,16]:add('alias',count=1,output_alias='state',delta=offset)
 for i,value in enumerate(pilot.SPECIAL):add('special',count=29,special=i,h1=value,h2=pilot.SPECIAL[(i*3+1)%len(pilot.SPECIAL)],header=(i*13)&255)
 for cw in [0x7f,0x27f,0x37f]:
  for rc in range(4):
   for depth in [0,1,3,6,7]:add('fpstate',count=29,cw=cw|(rc<<10),depth=depth,sticky=0x25,mmx=(rc+depth)&1,header=0x23)
 for mx in [0x1f80,0x3f80,0x5f80,0x7f80,0x9f80,0x1fc0,0x9fc0,0x1fbf]:add('mxcsr',count=29,mxcsr=mx,depth=3,mmx=1,header=0xf1)
 for kernel in ['loop','continue']:
  for start in [0,1,27,28,29,55]:
   for count in [1,29,57,112]:add('composition',kernel,count=count,start=start,position=0 if kernel=='loop' else 56,end=83,header=0x23)
 return rows

difference=pilot.difference

def main():
 parser=argparse.ArgumentParser();parser.add_argument('--attempt',type=int,required=True);args=parser.parse_args()
 cfg=CFG;out=ROOT/cfg['experiment']/f'{args.attempt:03d}';assert args.attempt>0 and not out.exists(),'immutable attempt exists';out.mkdir(parents=True)
 started=time.monotonic();pins={}
 def pin(path):
  key=relative(path);value=sha(path)
  assert key not in pins or pins[key]==value,('input drift before repin',key)
  pins[key]=value;return Path(path)
 def guard():
  for path,expected in pins.items():assert sha(ROOT/path if not Path(path).is_absolute() else path)==expected,('input drift',path)
 vc=ROOT/'local/tools/BuildTools/VC/Tools/MSVC/14.44.35207';cl=vc/'bin/Hostx64/x86/cl.exe';link=cl.parent/'link.exe'
 for path in [cl,link,cl.parent/'c1xx.dll',cl.parent/'c2.dll',__file__,RUN/'coff_retention.py',RUN/'config.json',RUN/cfg['source'],RUN/cfg['header'],ROOT/cfg['original_pe'],ROOT/'iterations/v2/001-original-recovery/runs/498-audio-pcm-3dnow-cpp/compare.py',ROOT/'scripts/research/verify-v2-native-batch.py',ROOT/'scripts/research/experiment-v2-thiscall-leaves-187.py',ROOT/'scripts/research/experiment-v2-thiscall-186.py',ROOT/'scripts/research/audio_recovery_provenance.py',RUN/'scope-evidence.json',Path(sys.executable)]:pin(path)
 for package in [unicorn,capstone]:
  for path in Path(package.__file__).parent.rglob('*'):
   if path.is_file() and path.suffix in ['.py','.dll','.so']:pin(path)
 inputs=out/'inputs';inputs.mkdir()
 for filename in [cfg['source'],cfg['header'],'compare.py','coff_retention.py','config.json']:(inputs/filename).write_bytes((RUN/filename).read_bytes())
 for item in cfg['support_sources']:
  path=pin(ROOT/item['source']);target=inputs/'support'/item['source'];target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(path.read_bytes())
 raw=(ROOT/cfg['original_pe']).read_bytes();assert digest(raw)==cfg['original_sha256']
 for body in cfg['original_bodies']:assert digest(native.pe_at(raw,int(body['va'],16),body['bytes']))==body['sha256']
 save(out/'original-state.json',validate_original_data(raw))
 variants={'baseline':(RUN/cfg['source']).read_text()}
 for mutation in cfg['mutations']:
  source=variants['baseline'];assert source.count(mutation['from'])==mutation['count'],mutation['name'];variants[mutation['name']]=source.replace(mutation['from'],mutation['to'])
 sources=out/'sources';sources.mkdir()
 for name,source in variants.items():path=sources/(name+'.cpp');path.write_text(source,encoding='utf-8',newline='\n');pin(path)
 entry=sources/'image_entry.cpp';entry.write_text('extern "C" void __cdecl image_entry_541(){}\n',encoding='utf-8',newline='\n');pin(entry)
 executions=[]
 def execute(name,command):
  guard();start=time.monotonic();proc=subprocess.run(list(map(str,command)),cwd=out,env={**os.environ,'VSLANG':'1033','CL':'','_CL_':'','LINK':'','_LINK_':'','INCLUDE':'','LIB':''},capture_output=True,timeout=120)
  log=out/(name+'.log');log.write_bytes((proc.stdout+proc.stderr).replace(b'\r\n',b'\n'));executions.append(dict(name=name,command=list(map(str,command)),exit_code=proc.returncode,seconds=time.monotonic()-start,log_sha256=sha(log)));save(out/'executions.json',executions)
  assert proc.returncode==0,(name,log.read_text(errors='replace')[-4000:])
 images={};coffs={};certificates={}
 for optimization in ['Od','O2']:
  opt=out/optimization;opt.mkdir();deps=opt/'dependencies';deps.mkdir()
  sdk=Path('C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0')
  includes=[*(ROOT/p for p in cfg['include_dirs']),vc/'include',ROOT/'iterations/v2/001-original-recovery/source/include',*[sdk/name for name in ['ucrt','shared','um']]]
  common=[cl,'/nologo','/c','/TP','/std:c++17','/'+optimization,'/Oi','/Gy','/GS-','/GR-','/Zl','/W4','/utf-8','/arch:IA32','/MP6',*(part for inc in includes for part in ['/I',inc]),'/sourceDependencies',str(deps)+os.sep,'/Fo'+str(opt)+os.sep]
  execute('compile-support-'+optimization,[*common,*[ROOT/i['source'] for i in cfg['support_sources']],entry])
  for path in dependency_paths(opt):pin(path)
  # Stable object stems are independent of source basenames.
  support=[];support_records={}
  for item in cfg['support_sources']:
   obj=opt/(Path(item['source']).stem+'.obj');target=opt/('support-'+item['object_stem']+'.obj');obj.rename(target);support.append(target);support_records[item['object_stem']]=dict(**coff.coff_symbols(target),sha256=sha(target))
  images[optimization]={};coffs[optimization]={'support_objects':support_records};certificates[optimization]={}
  def link_variant(name):
   obj=opt/(name+'.obj');details=coff.coff_symbols(obj)
   assert set(details['defined_external_symbols'])==set(cfg['candidate_exports'].values())|set(cfg.get('candidate_auxiliary_symbols',[])),details
   assert set(details['undefined_external_symbols'])==set(cfg['expected_candidate_undefined']),details
   coffs[optimization][name]=dict(**details,sha256=sha(obj));exe=opt/(name+'.exe')
   execute('link-'+optimization+'-'+name,[link,'/nologo','/MACHINE:X86','/SUBSYSTEM:CONSOLE','/ENTRY:image_entry_541','/NODEFAULTLIB','/OPT:REF','/OPT:NOICF','/INCREMENTAL:NO','/FORCE:UNRESOLVED','/FIXED','/DYNAMICBASE:NO','/BASE:0x10000000','/OUT:'+str(exe),'/MAP:'+str(exe.with_suffix('.map')),*[f'/EXPORT:{export}={symbol}'+(',DATA' if export in cfg['data_exports'] else '') for export,symbol in cfg['exports'].items()],obj,*support,opt/'image_entry.obj'])
   object_sources={obj:sources/(name+'.cpp'),**{p:ROOT/item['source'] for p,item in zip(support,cfg['support_sources'])},opt/'image_entry.obj':entry}
   certificates[optimization][name]=gate_image(exe,exe.with_suffix('.map'),object_sources,executions,out,obj)
   save(out/'retention.json',certificates)
   image=exe.read_bytes();info=image_info(image);assert info['directories'][1]==info['directories'][5]==(0,0),'imports/relocations';images[optimization][name]=(image,exports(image,info))
  execute('compile-baseline-'+optimization,[*common,sources/'baseline.cpp'])
  for path in dependency_paths(opt):pin(path)
  link_variant('baseline')
  print(json.dumps(dict(stage='canonical-link-probe',optimization=optimization,status='PASS',support_objects=len(support))),flush=True)
  execute('compile-mutations-'+optimization,[*common,*[sources/(name+'.cpp') for name in variants if name!='baseline']])
  for path in dependency_paths(opt):pin(path)
  for name in variants:
   if name!='baseline':link_variant(name)
  for path in dependency_paths(opt):pin(path)
 save(out/'coff.json',coffs);guard();scenes=cases();save(out/'cases.json',scenes)
 originals={r['name']:int(r['va'],16) for r in cfg['original_bodies']};bounds=[(int(r['va'],16),int(r['va'],16)+r['bytes']) for r in cfg['original_bodies']]
 oracle=Machine(raw,originals,cfg['cpu_model'],bounds);candidates={opt:Machine(*images[opt]['baseline'],cfg['cpu_model']) for opt in images}
 assert all(m.initialization==oracle.initialization for m in candidates.values()),'canonical initializer state mismatch'
 save(out/'initialization.json',oracle.initialization);records=[];cached={};counts=dict(cases=0,events=0,fp_events=0)
 for index,case in enumerate(scenes):
  expected=oracle.run(case)
  for opt,machine in candidates.items():
   actual=machine.run(case);changed=difference(expected,actual)
   if changed:save(out/'failure.json',dict(case=case,optimization=opt,differences=changed,expected=expected,actual=actual));raise AssertionError(('comparison mismatch',index,opt,case['name'],changed))
  if case['group'] in ['count','alias']:cached[case['name']]=expected
  records.append(dict(case=case['name'],**expected));counts['cases']+=1;counts['events']+=expected['event_count'];counts['fp_events']+=expected['fp_event_count']
  if index%100==0:print(json.dumps(dict(stage='compare',completed=index+1,total=len(scenes))),flush=True)
 save(out/'comparisons.json',records);mutation_records=[]
 for opt in images:
  for mutation in cfg['mutations']:
   machine=Machine(*images[opt][mutation['name']],cfg['cpu_model']);detected=None
   for case in scenes:
    if case['group'] not in ['count','alias']:continue
    try:changed=difference(cached[case['name']],machine.run(case))
    except (UcError,AssertionError) as error:changed=[str(error)]
    if changed:detected=dict(optimization=opt,mutation=mutation['name'],case=case['name'],differences=changed);break
   assert detected,('undetected mutation',opt,mutation['name']);mutation_records.append(detected)
 save(out/'mutations.json',mutation_records);guard();outputs={relative(p):sha(p) for p in out.rglob('*') if p.is_file()}
 receipt=dict(schema=1,status='PASS',kind='emulated-original-vs-emulated-compiled-cpp',original_sha256=cfg['original_sha256'],cpu_model=cfg['cpu_model'],unicorn_version=unicorn.__version__,unicorn_core_version=unicorn.uc_version(),case_counts_per_optimization=counts,optimizations=['Od','O2'],mutations_detected=len(mutation_records),variants_per_optimization=len(variants),original_body_bytes=201,contiguous_raw_span_bytes=201,new_state_bytes=0,input_sha256=pins,output_sha256=outputs,elapsed_seconds=time.monotonic()-started,boundaries=['PinnedUnicornAthlon11 on both sides, not physicalAMD/native hardware acceptance','Actualcanonical512data and534/538composition; boundedmappedscenes/maskedFP only','Externalstackaliases/invalidtails/extremecounts/faults/concurrency/fullproducer/live/startup/gameplay remain open'])
 save(out/'receipt.json',receipt)
 for filename in ['receipt.json','coff.json']:(RUN/('validation.json' if filename=='receipt.json' else filename)).write_bytes((out/filename).read_bytes())
 print(json.dumps(dict(status='PASS',**counts,mutations=len(mutation_records),seconds=time.monotonic()-started)),flush=True)

if __name__=='__main__':main()
