"""Run048: compare window cleanup and centering against original x86."""
import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path
from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]; RUN=ROOT/'iterations/v2/001-original-recovery/runs/048-window-position'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
STACK,EXIT=0x3108000,0x3200000
CONFIG_NAME,INSTANCE=0x3103000,0x4444
SPI,UNREG,REMOVE,IDLE,TIMED,METRICS=0x3210000,0x3210010,0x53a8e0,0x55f740,0x5366e0,0x3210020
GETCLIENT,GETLONG,ADJUST,SETPOS,CLIENTSCREEN=0x3210030,0x3210040,0x3210050,0x3210060,0x3210070
RECT,WORK,POINTA,POINTB=0x3104000,0x3104020,0x3104040,0x3104050
def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def word(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]
def cases():
 c=[]
 for hwnd in (0,1):
  for refs in (0,1,2):
   for s1,s2 in ((0,0),(1,0),(0,2),(0x1234,0x5678)):
    if hwnd:
     for cycles in (1,2,4):c.append((0,hwnd,refs,s1,s2,cycles,1366,768,640,480))
    else:c.append((0,hwnd,refs,s1,s2,0,1366,768,640,480))
 c += [(1,0,0,0,0,0,1366,768,640,480),(1,0,0,0,0,0,0,0,1,1),
       (1,0,0,0,0,0,1920,1080,1920,1080),(1,0,0,0,0,0,800,600,1024,768),
       (1,0,0,0,0,0,1,1,-1,-1),(1,0,0,0,0,0,320,200,1024,200)]
 c += [(2,0,0,0,0,0,x,y,w,h) for x,y,w,h in
       ((0,0,640,480),(100,120,800,600),(0,120,800,600),(100,0,800,600),
        (1920,1080,1920,1080),(-1,-1,640,480),(100,120,0,600),(100,120,800,0))]
 c += [(3,0,0,0,0,0,x,y,800,600) for x,y in ((0,0),(20,30),(-100,80),(1920,1080))]
 return c
def original(module,data,c):
 mode,has_hwnd,refs,s1,s2,cycles,mx,my,w,h=c
 u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
 for sec in module['sections']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
 u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3210000,0x10000);u.mem_write(EXIT,b'\xc3'*0x1000)
 u.mem_write(CONFIG_NAME,b'DLL\0');put(u,0x69e5a8,CONFIG_NAME);put(u,0x6b7794,INSTANCE)
 put(u,0x6b7bf8,0x1234 if has_hwnd else 0);put(u,0x69e594,refs);put(u,0x69e57c,s1);put(u,0x69e580,s2)
 calls={'spi':0,'remove':0,'unreg':0,'idle':0,'timed':0,'metrics':0,'rect':0,'style':0,'adjust':0,'setpos':0,'screen':0};args=[0]*5;actions=[0,0];uis=[0,0];posargs=[0]*5
 provenance={'entry_esp':None,'lea_esp':None,'rect_pointer':None,'rect_words':None}
 put(u,0x5b2314,SPI);put(u,0x5b22b4,UNREG);put(u,0x5b22c4,METRICS)
 put(u,0x5b22f0,GETCLIENT);put(u,0x5b22b8,GETLONG);put(u,0x5b22bc,ADJUST);put(u,0x5b22b0,SETPOS);put(u,0x5b231c,CLIENTSCREEN)
 put(u,0x69e5b0,1 if mode==3 else 0);put(u,0x6bda00,mx if mode==3 else 0);put(u,0x6bda04,my if mode==3 else 0)
 for i,v in enumerate((0,0,640,480)):put(u,RECT+i*4,v)
 for i,v in enumerate((0,0,1920,1080)):put(u,WORK+i*4,v)
 for i,v in enumerate((0,0,640,480)):put(u,POINTA+i*4,v)
 for i,v in enumerate((0,0,640,480)):put(u,POINTB+i*4,v)
 def hook(m,address,_size,_):
  if address not in (SPI,UNREG,REMOVE,IDLE,TIMED,METRICS,GETCLIENT,GETLONG,ADJUST,SETPOS,CLIENTSCREEN):return
  sp=m.reg_read(UC_X86_REG_ESP);ret=word(m,sp);cleanup=0;value=0
  if address==SPI:
   if word(m,sp+4)==0x30:
    ptr=word(m,sp+12)
    for i,v in enumerate((0,0,1920,1080)):put(m,ptr+i*4,v)
    value=1
   else:
    if calls['spi']<2:actions[calls['spi']]=word(m,sp+4);uis[calls['spi']]=word(m,sp+8)
    calls['spi']+=1
   cleanup=16
  elif address==UNREG:calls['unreg']+=1;cleanup=8;value=1
  elif address==REMOVE:calls['remove']+=1
  elif address==IDLE:
   calls['idle']+=1
   if cycles and calls['idle']>=cycles:put(m,0x6b7bf8,0)
  elif address==TIMED:calls['timed']+=1
  elif address==METRICS:calls['metrics']+=1;value=my if word(m,sp+4)==1 else mx;cleanup=4
  elif address==GETCLIENT:
   calls['rect']+=1;ptr=word(m,sp+8)
   for i,v in enumerate((0,0,640,480)):put(m,ptr+i*4,v)
   value=1;cleanup=8
  elif address==GETLONG:
   calls['style']+=1;value=0x20 if word(m,sp+8)==0xffffffec else 0x10;cleanup=8
  elif address==ADJUST:
   calls['adjust']+=1;ptr=word(m,sp+4)
   provenance['rect_pointer']=ptr
   provenance['rect_words']=tuple(word(m,ptr+i*4) for i in range(4))
   assert provenance['entry_esp'] is not None and ptr==provenance['entry_esp']-0x20, (hex(ptr),provenance)
   assert provenance['rect_words'][0:2]==(0,0), provenance
   for i,d in enumerate((-8,-31,8,8)):put(m,ptr+i*4,word(m,ptr+i*4)+d)
   value=1;cleanup=16
  elif address==SETPOS:
   calls['setpos']+=1;posargs[:]=[word(m,sp+12+i*4) for i in range(5)];cleanup=28;value=1
  elif address==CLIENTSCREEN:
   calls['screen']+=1;ptr=word(m,sp+8);put(m,ptr,word(m,ptr)+100);put(m,ptr+4,word(m,ptr+4)+200);cleanup=8;value=1
  m.reg_write(UC_X86_REG_EAX,value);m.reg_write(UC_X86_REG_ESP,sp+4+cleanup);m.reg_write(UC_X86_REG_EIP,ret)
 def stack_proof(m,address,_size,_):
  if address==0x53bd40:provenance['entry_esp']=m.reg_read(UC_X86_REG_ESP)
  elif address==0x53bda8:
   provenance['lea_esp']=m.reg_read(UC_X86_REG_ESP)
   assert provenance['entry_esp'] is not None
   assert provenance['lea_esp']+0x14==provenance['entry_esp']-0x20, provenance
 u.hook_add(UC_HOOK_CODE,hook);u.hook_add(UC_HOOK_CODE,stack_proof)
 entry=0x53bcb0 if mode==0 else 0x53bec0 if mode==1 else 0x53bd40
 callargs=[] if mode==0 else [w,h] if mode==1 else [0,0,w,h] if mode==3 else [mx,my,w,h]
 for i,v in enumerate([EXIT]+callargs):put(u,STACK+i*4,v)
 u.reg_write(UC_X86_REG_ESP,STACK);u.emu_start(entry,EXIT,count=200000)
 return (word(u,0x69e594),int(bool(word(u,0x6b7bf8))),calls['spi'],calls['remove'],calls['unreg'],calls['idle'],calls['timed'],calls['metrics'],0,*actions,*uis,*args,calls['rect'],calls['style'],calls['adjust'],calls['setpos'],calls['screen'],*posargs,word(u,0x6b7c08),word(u,0x6b7c0c),word(u,0x6b77b4),word(u,0x6b77b8))
def main():
 p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/window-position-048/bin/Release/window_position_probe.exe');p.add_argument('--report',type=Path,default=RUN/'verification.json');a=p.parse_args()
 module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
 data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
 inputs=cases();proc=subprocess.run([str(a.probe)],input=''.join(' '.join(map(str,x))+'\n' for x in inputs),text=True,capture_output=True,check=True);lines=proc.stdout.splitlines();assert len(lines)==len(inputs)
 outputs=[]
 for c,line in zip(inputs,lines):
  actual=tuple(int(v,0) for v in line.split());expected=original(module,data,c)
  if actual!=expected:raise RuntimeError(f'{c}: expected={expected} actual={actual}')
  outputs.append({'input':c,'output':actual})
 deps=['iterations/v2/001-original-recovery/'+x for x in ('source/include/porsche/window_position.hpp','source/recovered/Porsche.exe/window_position.cpp','source/recovered/window_position_probe.cpp','runs/048-window-position/CMakeLists.txt','runs/048-window-position/README.md')]+['scripts/research/verify-v2-window-position.py']
 report={'schema':1,'sha256':SHA,'function_vas':['0053bcb0','0053bd40','0053bec0','0053a8e0','005366e0','0055f740'],'full_function_vas':['0053bcb0','0053bd40','0053bec0'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'boundaries':'USER32 SystemParametersInfoA, UnregisterClassA, GetSystemMetrics, GetClientRect, GetWindowLongA, AdjustWindowRectEx, SetWindowPos and ClientToScreen; game helpers 0053a8e0,0055f740,005366e0. Unicorn hook runs at callee entry and applies RET cleanup as return-address pop plus declared argument bytes. A live stack assertion at 0053bda8 and the AdjustWindowRectEx boundary proves its RECT pointer equals entry ESP-0x20, initialized by PUSH -0x14/PUSH hwnd then MOV [ESP+14..20] at 0053bd81..bd95.','stack_provenance_assertions':'entry-to-bda8 ESP offsets and AdjustWindowRectEx RECT address/initialized leading words checked for all relevant cases.','source_sha256':{x:hashlib.sha256((ROOT/x).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps},'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'fixtures':outputs}
 report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_position.cpp', 'iterations/v2/001-original-recovery/source/recovered/window_position_probe.cpp'])
 a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8');print(json.dumps({'cases':len(inputs),'full_function_vas':report['full_function_vas'],'partial_function_vas':report['partial_function_vas'],'native_cpp_equal_original_x86':True}))
if __name__=='__main__':main()
