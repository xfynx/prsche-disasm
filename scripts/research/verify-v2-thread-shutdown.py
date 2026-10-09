"""Compare recovered thread shutdown/table cleanup with original x86."""
import argparse, hashlib, json, subprocess, sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/054-thread-shutdown'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP

STACK=0x3108000;TABLE=0x3104000;TABLE_LOCK=0x3105000;START_LOCK=0x3105040;FREE_LOCK=0x3105080;EXIT=0x3200000
CLOSE,ENTER,LEAVE,DELETE,VFREE=0x3210000,0x3210010,0x3210020,0x3210030,0x3210040
GLOBALS={'main':0x6a57d0,'mainid':0x6a57d4,'start':0x6a57d8,'init':0x6a57dc,'exitreg':0x6a57e0,
         'entries':0x6a57e4,'capacity':0x6a57e8,'tablelock':0x6a57ec,'serial':0x5df6a0,'freehead':0x69cb04}
FREE_TAG=0x46524545

def put(u,a,v):u.mem_write(a,(v&0xffffffff).to_bytes(4,'little'))
def word(u,a):return int.from_bytes(u.mem_read(a,4),'little')
def ptr_id(p):
 if p==TABLE_LOCK:return 1
 if p==START_LOCK:return 2
 if p==FREE_LOCK:return 3
 if p==TABLE:return 10
 if p==0x3106000:return 99
 return p

def cases():
 patterns=[
  [(11,0x5000,101),(0,0x5001,102),(0,0,103),(22,0x5003,104),(33,0,105),(0,0x5005,106),(44,0x5006,107),(55,0x5007,108)],
  [(0,0x5100,1),(9,0x5101,2),(10,0,3),(0,0,4),(0,0x5104,5),(7,0x5105,6),(8,0,7),(9,0,8)],
  [(1,0,1),(2,0,2),(3,0,3),(4,0,4),(5,0,5),(6,0,6),(7,0,7),(8,0,8)],
 ]
 out=[]
 for mode,init,table,cap,main,start,tlock,free,records in [
  (0,0,1,4,1,1,1,0,patterns[0]), # shutdown no-op preserves every global
  (0,1,1,4,1,1,1,3,patterns[0]),
  (0,1,1,0,1,1,1,0,patterns[1]),
  (0,1,1,8,0,0,1,3,patterns[1]),
  (0,1,0,0,1,1,1,0,patterns[2]), # lock exists, no table
  (0,1,0,0xffffffff,1,1,1,2,patterns[2]), # signed-negative cap, no table
  (0,1,1,0xffffffff,1,1,1,3,patterns[0]),
  (0,1,1,0x80000000,1,1,1,0,patterns[1]),
  (0,1,1,0,0,0,1,0,patterns[0]),
  (0,1,1,3,1,0,1,0,patterns[1]),
  (0,1,1,5,1,1,0,0,patterns[0]), # missing table lock: no cleanup
  (0,1,1,6,1,1,1,9,patterns[0]),
  (1,0,1,4,1,1,1,0,patterns[0]), # direct table cleanup leaves shutdown-only state alone
  (1,1,1,4,1,1,1,3,patterns[1]),
  (1,1,1,0xffffffff,1,1,1,2,patterns[2]),
  (1,1,0,0xffffffff,1,1,1,0,patterns[0]),
  (1,1,1,2,1,0,0,3,patterns[1]),
 ]:
  out.append((mode,init,table,cap,main,start,tlock,free,records))
 return out

def original(module,data,c):
 mode,init,has_table,cap,has_main,has_start,has_tablelock,free_id,records=c
 u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
 for sec in module['sections']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
 u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3210000,0x1000);u.mem_write(EXIT,b'\xc3'*0x1000)
 lock_addrs={1:TABLE_LOCK,2:START_LOCK,3:FREE_LOCK,9:0x3106000}
 free_addr=lock_addrs.get(free_id,0)
 for addr in (TABLE_LOCK,START_LOCK,FREE_LOCK,0x3106000):u.mem_write(addr,b'\0'*32)
 lockptr={1:TABLE_LOCK if has_tablelock else 0,2:START_LOCK if has_start else 0,3:FREE_LOCK}.get
 put(u,GLOBALS['main'],0x1111 if has_main else 0);put(u,GLOBALS['mainid'],0x12345678)
 put(u,GLOBALS['start'],lockptr(2,0));put(u,GLOBALS['init'],init);put(u,GLOBALS['exitreg'],0x89abcdef)
 put(u,GLOBALS['entries'],TABLE if has_table else 0);put(u,GLOBALS['capacity'],cap)
 put(u,GLOBALS['tablelock'],lockptr(1,0));put(u,GLOBALS['serial'],0x76543210);put(u,GLOBALS['freehead'],free_addr)
 for i,entry in enumerate(records):
  for j,value in enumerate(entry):put(u,TABLE+i*12+j*4,value)
 for i,p in enumerate((CLOSE,ENTER,LEAVE,DELETE,VFREE)):
  put(u,(0x5b2164,0x5b2078,0x5b206c,0x5b2068,0x5b2148)[i],p)
 events=[]
 service={CLOSE:(3,4),ENTER:(1,4),LEAVE:(2,4),DELETE:(5,4),VFREE:(4,12)}
 def hook(m,address,_size,_):
  if address not in service:return
  code,cleanup=service[address];sp=m.reg_read(UC_X86_REG_ESP);ret=word(m,sp);arg=word(m,sp+4)
  if address==ENTER and mode==0:assert word(m,GLOBALS['init'])==0,'shutdown must clear initialized flag before lock entry/cleanup'
  if address in (ENTER,LEAVE,DELETE):arg=ptr_id(arg)
  elif address==VFREE:arg=ptr_id(arg)
  events.append((code,arg));m.reg_write(UC_X86_REG_EAX,1);m.reg_write(UC_X86_REG_ESP,sp+4+cleanup);m.reg_write(UC_X86_REG_EIP,ret)
 u.hook_add(UC_HOOK_CODE,hook)
 for i,v in enumerate((EXIT,)):put(u,STACK+i*4,v)
 u.reg_write(UC_X86_REG_ESP,STACK);u.emu_start(0x55f1c0 if mode==0 else 0x55f200,EXIT,count=200000)
 tableptr=word(u,GLOBALS['entries']);table_out=[]
 for i in range(8):table_out.extend(word(u,TABLE+i*12+j*4) for j in range(3))
 def lock_word(addr,off):return word(u,addr+off)
 return (word(u,GLOBALS['init']),word(u,GLOBALS['main']),word(u,GLOBALS['mainid']),word(u,GLOBALS['exitreg']),
  word(u,GLOBALS['serial']),int(bool(tableptr)),word(u,GLOBALS['capacity']),2 if word(u,GLOBALS['start']) else 0,
  1 if word(u,GLOBALS['tablelock']) else 0,ptr_id(word(u,GLOBALS['freehead'])),ptr_id(lock_word(TABLE_LOCK,24)),lock_word(TABLE_LOCK,28),
  ptr_id(lock_word(START_LOCK,24)),lock_word(START_LOCK,28),ptr_id(lock_word(FREE_LOCK,24)),lock_word(FREE_LOCK,28),
  len(events),*(v for pair in events for v in pair),*table_out)

def main():
 p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/thread-shutdown-054/bin/Release/thread_shutdown_probe.exe');p.add_argument('--report',type=Path,default=RUN/'verification.json');a=p.parse_args()
 module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
 data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
 inputs=cases();lines=[' '.join(map(str,(mode,init,table,cap,main_present,start,tl,free,len(records),*(v for row in records for v in row)))) for mode,init,table,cap,main_present,start,tl,free,records in inputs]
 proc=subprocess.run([str(a.probe)],input='\n'.join(lines)+'\n',text=True,capture_output=True,check=True);native=[tuple(map(int,line.split())) for line in proc.stdout.splitlines()];assert len(native)==len(inputs)
 fixtures=[]
 for c,actual in zip(inputs,native):
  expected=original(module,data,c)
  if actual!=expected:raise RuntimeError(f'input={c[:8]} expected={expected} actual={actual}')
  fixtures.append({'input':c[:8],'events':actual[17:17+actual[16]*2],'state_equal':True})
 deps=['iterations/v2/001-original-recovery/'+x for x in ('source/include/porsche/thread_shutdown.hpp','source/recovered/Porsche.exe/thread_shutdown.cpp','source/recovered/thread_shutdown_probe.cpp','source/include/porsche/file_threads.hpp','source/recovered/Porsche.exe/file_threads.cpp','source/recovered/Porsche.exe/file_pages.cpp','source/recovered/Porsche.exe/heap_locks.cpp','runs/054-thread-shutdown/CMakeLists.txt','runs/054-thread-shutdown/README.md')]+['scripts/research/verify-v2-thread-shutdown.py']
 report={'schema':1,'sha256':SHA,'function_vas':['0055f1c0','0055f200','0055f2b0','005322b0','005322c0','005322d0','0056e640'],'full_function_vas':['0055f1c0','0055f200'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'signed_loop_cases':sum(1 for c in inputs if c[3]&0x80000000),'boundaries':'Win32 CloseHandle, EnterCriticalSection, LeaveCriticalSection, DeleteCriticalSection, VirtualFree. Existing recovered 0055f2b0, 005322b0/c0/d0 and 0056e640 are linked into the native probe. The original-x86 side executes those game bodies and hooks only OS calls.','source_sha256':{x:hashlib.sha256((ROOT/x).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps},'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'fixtures':fixtures}
 report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/thread_shutdown.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/file_threads.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/file_pages.cpp', 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/heap_locks.cpp', 'iterations/v2/001-original-recovery/source/recovered/thread_shutdown_probe.cpp'])
 a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8');print(json.dumps({'cases':len(inputs),'full_function_vas':report['full_function_vas'],'signed_loop_cases':report['signed_loop_cases'],'native_cpp_equal_original_x86':True}))
if __name__=='__main__':main()
