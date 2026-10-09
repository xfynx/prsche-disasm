"""Run045: compare selected original message callbacks with native x86 C++."""
import argparse, hashlib, json, struct, subprocess, sys
from pathlib import Path
from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/045-window-messages'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_ECX
STACK,EXIT,CONFIG,OUT=0x3108000,0x3200000,0x3101000,0x3102000
GETRECT,CLIENTSCREEN,FOREGROUND,BEGINPAINT,ENDPAINT=0x3210000,0x3210010,0x3210020,0x3210030,0x3210040
PUMP,DISPATCH,ENQUEUE,MOUSE=0x5322b0,0x5322c0,0x3210070,0x3210080
ENTRIES={1:0x53b360,2:0x53b3d0,3:0x53b6b0,4:0x53b710,5:0x53b770,6:0x53b7d0}
KEYMAP=bytes.fromhex('0102030405060708090a0b0c002b0e0f10111213141516171819291a1c1e1f2021222324252692281b2c2d2e2f303132333435003900d1c9d2d3c8cbcdd0c7cf4a46c7c8c937cb4ccd4ecfd0d100d200d300575800000000000000000000000000003b3c3d3e3f4041424344000000002a3a00381d0000000000000000000000')
def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def word(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]
def cases():
    out=[]
    for mode in (1,2,3,4,5,6):
      for fullscreen in (0,1):
       for match in (0,1):
        for count in (0,1,4,40):
         for notify in (0,1):
          for wparam in (0x00010041,0x02030002,0x00100010,0x00360000):
           translation=KEYMAP[(0x89abcdef>>16)&0x7f] if mode==3 else 0xff
           out.append((mode,fullscreen,match,wparam,0x89abcdef,count,translation,notify))
    # Explicit chars count clamp, translated shift/scancode special cases, button masks.
    out += [(2,0,1,0x03410005,0x10203040,3,0xff,0),(3,0,1,0x00000000,0x002a0000,32,KEYMAP[0x2a],0),
            (3,0,1,0x00000000,0x00360000,32,KEYMAP[0x36],0),(4,0,1,0x00010013,0xfffe0002,32,0xff,0),
            (5,0,1,0x00020012,0x00030004,32,0xff,0)]
    return out
def original(module,data,case):
    mode,fullscreen,match,wp,lp,capacity,translated,notify=case
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for sec in module['sections']:u.mem_write(0x400000+sec['rva'],data[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(0x3210000,0x10000);u.mem_write(EXIT,b'\xc3'*0x1000)
    conf=bytearray(0x478);struct.pack_into('<I',conf,0x458,0x1234);conf[0x461]=fullscreen
    u.mem_write(CONFIG,bytes(conf));put(u,0x6b7bf8,0x1234);put(u,0x69e560,capacity)
    u.mem_write(0x5de028,b'\x7f'*256)
    put(u,0x69e5a0,0x5df934);put(u,0x5df9b8,0x5654d0 if notify else 0);put(u,0x6a5c2c,0)
    put(u,0x6a57d8,0x3333);put(u,OUT,0x77777777)
    key=(lp>>16)&0x7f; trans=bytes(u.mem_read(0x5df934+key,1))[0]
    calls={'getrect':0,'screen':0,'foreground':0,'begin':0,'end':0,'pump':0,'dispatch':0,'enqueue':0,'mouse':0}
    last=[0,0,0,0]
    imports={0x5b22f0:GETRECT,0x5b231c:CLIENTSCREEN,0x5b2300:FOREGROUND,0x5b22e8:BEGINPAINT,0x5b22ec:ENDPAINT}
    for a,v in imports.items():put(u,a,v)
    def hook(m,address,_size,_):
      if address not in (GETRECT,CLIENTSCREEN,FOREGROUND,BEGINPAINT,ENDPAINT,PUMP,DISPATCH,ENQUEUE,MOUSE,0x53a9e0,0x5728b0):return
      sp=m.reg_read(UC_X86_REG_ESP);ret=word(m,sp);cleanup=0;retval=0
      if address in (GETRECT,CLIENTSCREEN):
        calls['getrect' if address==GETRECT else 'screen']+=1;h=word(m,sp+4);r=word(m,sp+8)
        if address==GETRECT:
          m.mem_write(r,struct.pack('<iiii',11,13,411,313));retval=1
        else:
          left,top=struct.unpack('<ii',m.mem_read(r,8));m.mem_write(r,struct.pack('<ii',left+101,top+103));retval=1
        cleanup=8
      elif address==FOREGROUND:calls['foreground']+=1;retval=1;cleanup=4
      elif address in (BEGINPAINT,ENDPAINT):calls['begin' if address==BEGINPAINT else 'end']+=1;cleanup=8
      elif address in (PUMP,DISPATCH):calls['pump' if address==PUMP else 'dispatch']+=1
      elif address==0x53a9e0:
        calls['enqueue']+=1;last[:3]=[word(m,sp+4),word(m,sp+8)&0xff,word(m,sp+12)&0xff]
      elif address==0x5728b0:
        calls['mouse']+=1;last[:4]=[word(m,sp+4),word(m,sp+8),word(m,sp+12),word(m,sp+16)]
      m.reg_write(UC_X86_REG_EAX,retval);m.reg_write(UC_X86_REG_ESP,sp+4+cleanup);m.reg_write(UC_X86_REG_EIP,ret)
    u.hook_add(UC_HOOK_CODE,hook)
    args=[CONFIG,0x1234 if match else 0x5678,0x100,wp,lp,OUT]
    for i,v in enumerate([EXIT]+args):put(u,STACK+i*4,v)
    u.reg_write(UC_X86_REG_ESP,STACK)
    try:u.emu_start(ENTRIES[mode],EXIT,count=100000)
    except Exception as exc:raise RuntimeError(f'original {case} eip={u.reg_read(UC_X86_REG_EIP):08x} eax={u.reg_read(UC_X86_REG_EAX):08x} ecx={u.reg_read(UC_X86_REG_ECX):08x} esp={u.reg_read(UC_X86_REG_ESP):08x}') from exc
    out_value=word(u,OUT);posx=struct.unpack('<i',u.mem_read(CONFIG+0x468,4))[0];posy=struct.unpack('<i',u.mem_read(CONFIG+0x46c,4))[0]
    state=bytes(u.mem_read(0x5de028+trans,1))[0]
    resize=word(u,0x6a5c2c)
    return (u.reg_read(UC_X86_REG_EAX),out_value,posx,posy,calls['getrect'],calls['screen'],resize,calls['enqueue'],calls['mouse'],calls['begin'],calls['end'],calls['pump'],calls['dispatch'],state,*last)
def parse(line):return tuple(int(v,0) for v in line.split())
def main():
 p=argparse.ArgumentParser();p.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/window-messages-045/bin/Release/window_messages_probe.exe');p.add_argument('--report',type=Path,default=RUN/'verification.json');a=p.parse_args()
 module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
 data=(ROOT/'local/game'/module['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==SHA
 inputs=cases();proc=subprocess.run([str(a.probe)],input=''.join(' '.join(map(str,x))+'\n' for x in inputs),text=True,capture_output=True,check=True)
 lines=proc.stdout.splitlines();assert len(lines)==len(inputs),(len(lines),len(inputs));outputs=[]
 for case,line in zip(inputs,lines):
  actual=parse(line);expected=original(module,data,case)
  if actual!=expected:raise RuntimeError(f'{case}: expected={expected} actual={actual}')
  outputs.append({'input':case,'output':actual})
 deps=['iterations/v2/001-original-recovery/'+x for x in ('source/include/porsche/window_messages.hpp','source/recovered/Porsche.exe/window_messages.cpp','source/recovered/window_messages_probe.cpp','runs/045-window-messages/CMakeLists.txt','runs/045-window-messages/README.md')]+['scripts/research/verify-v2-window-messages.py']
 report={'schema':1,'sha256':SHA,'function_vas':['0053b360','0053b3d0','0053b6b0','0053b710','0053b770','0053b7d0','0053a9e0','005728b0'],'full_function_vas':['0053b360','0053b3d0','0053b6b0','0053b710','0053b770','0053b7d0'],'partial_function_vas':[],'cases':len(inputs),'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,'boundaries':'GetClientRect, ClientToScreen, BeginPaint, EndPaint and SetForegroundWindow are controlled Win32 boundaries; 0053a9e0, 005728b0, 005322b0/005322c0 are typed game boundaries.','source_sha256':{x:hashlib.sha256((ROOT/x).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for x in deps},'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'fixtures':outputs}
 report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_messages.cpp', 'iterations/v2/001-original-recovery/source/recovered/window_messages_probe.cpp'])
 a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8');print(json.dumps({'cases':len(inputs),'function_vas':report['function_vas'],'native_cpp_equal_original_x86':True}))
if __name__=='__main__':main()
