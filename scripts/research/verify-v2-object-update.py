"""Compare original 005588a0 state, clock branches, and call order to x86 C++."""
import argparse,hashlib,json,struct,subprocess,sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/092-object-update'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
from v2_source_dependencies import source_hashes

STACK,EXIT,BOUNDARY=0x3108000,0x3200000,0x3210000
CLOCK=BOUNDARY+0x10; CONFIG,OBJECT_A,OBJECT_B,VTABLE=0x3400000,0x3500000,0x3501000,0x3502000
LOCK=0x2222000
def case(name,mode,tick,anchor,maximum,diagnostic,elapsed,obj,aux,flag):
    state=CONFIG if mode=='alt' else 0x6b77a0
    return dict(name=name,mode=mode,state=state,arg=0 if mode=='null' else state,
        tick=tick,anchor=anchor,maximum=maximum,diagnostic=diagnostic,
        elapsed=elapsed,obj_code=obj,aux=aux,flag=flag)

# Independent dimensions are varied deliberately: early bypass, caller storage,
# fallback, input flags, both object identities, signed compare boundaries, and
# modular GetTickCount subtraction receive distinct evidence cases.
CASES=[
 case('bypass_alt_zero','alt',0,0,0,0,0,0,0,0),
 case('bypass_alt_flags','alt',0xffffffff,0x12345678,0x87654321,0xffffffff,0xa5a5a5a5,0,0x11112222,0xff),
 case('bypass_alt_byte80','alt',77,70,7,0x80000000,0xabcdef01,0,0,0x80),
 case('bypass_global_nonnull','global',500,100,33,0x13579bdf,0xdeadbeef,0,0xffffffff,1),
 case('bypass_null_fallback','null',123,456,789,0xffffffff,0x01020304,0,0x76543210,0x7f),
 case('equal_positive','alt',20,10,10,1,2,1,0x13572468,1),
 case('greater_positive','alt',30,10,10,0,0,1,0x13572468,0),
 case('less_positive','alt',10,10,1,0xffffffff,0xffffffff,2,0xffffffff,0xff),
 case('equal_zero','alt',40,40,0,0x80000000,0x77777777,2,0,0x80),
 case('positive_delta_from_zero','alt',1,0,0,7,8,1,0x00000001,1),
 case('forward_wrap_small_delta','alt',0x10,0xfffffff0,0x20,0,0xffffffff,1,0x24681357,0),
 case('forward_wrap_exceeds','alt',0x20,0xfffffff0,0x2f,0x12345678,0x77777777,2,0xabcdef01,0x7f),
 case('backward_wrap_negative','alt',0x10,0x20,0,0,0x10101010,1,0x11111111,0),
 case('backward_wrap_more_negative','alt',0,0x80000000,0x7fffffff,0xffffffff,0xffffffff,2,0x22222222,1),
 case('full_tick_wrap_one','alt',0,0xffffffff,0,1,2,1,0,0),
 case('delta_wrap_zero','alt',0xffffffff,0xffffffff,0,2,3,2,0x33333333,1),
 case('signed_delta_min','alt',0x80000000,0,0x7fffffff,3,4,1,0x44444444,0x80),
 case('signed_delta_min_plus','alt',0x80000001,0,0x80000000,4,5,2,0x55555555,0x7f),
 case('threshold_signed_min_equal','alt',0x80000000,0,0x80000000,5,6,1,0x66666666,0xff),
 case('threshold_negative_gt','alt',15,10,0xfffffff0,6,7,2,0x77777777,1),
 case('threshold_minus_one_less','alt',0xfffffffe,0,0xffffffff,7,8,1,0x88888888,0),
 case('threshold_positive_max_equal','alt',0x7fffffff,0,0x7fffffff,8,9,2,0x99999999,1),
 case('threshold_positive_max_less','alt',0x7ffffffe,0,0x7fffffff,9,10,1,0xaaaaaaaa,0x80),
 case('global_nonnull_object_a','global',50,40,10,0xabcdef01,0xdeadbeef,1,0x01020304,0x7f),
 case('global_nonnull_object_b','global',50,40,10,0xabcdef02,0xdeadbeee,2,0x05060708,0x80),
 case('null_global_object_a','null',50,40,10,0xffffffff,0x12345678,1,0x87654321,0xff),
 case('null_global_object_b','null',50,40,10,0,0x87654321,2,0x12345678,1),
 case('object_zero_aux','alt',100,99,0,0xfeedface,0x11111111,1,0,0),
 case('object_flag_high','alt',101,99,1,0x80000000,0x22222222,2,0xffffffff,0xff),
 case('object_flag_low','alt',102,99,4,0x7fffffff,0x33333333,1,0x80000000,0),
 case('null_global_no_handle_flag','null',0x10203040,0x10203040,0,0xfffffffe,0xeeeeeeee,0,0x55555555,0xfe),
]

def put(u,a,v):u.mem_write(a,struct.pack('<I',v&0xffffffff))
def byte(u,a,v):u.mem_write(a,bytes((v&255,)))
def word(u,a):return struct.unpack('<I',u.mem_read(a,4))[0]
def original(module,image,case):
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x400000,0x300000)
    for section in module['sections']:
        if section['raw_size']:u.mem_write(0x400000+section['rva'],image[section['raw_offset']:section['raw_offset']+section['raw_size']])
    u.mem_map(0x3100000,0x10000);u.mem_map(EXIT,0x1000);u.mem_map(BOUNDARY,0x1000)
    u.mem_map(CONFIG,0x1000);u.mem_map(0x3500000,0x3000)
    put(u,OBJECT_A,VTABLE);put(u,OBJECT_B,VTABLE);put(u,VTABLE+0x80,BOUNDARY)
    obj={0:0,1:OBJECT_A,2:OBJECT_B}[case['obj_code']]
    put(u,case['state']+0x43c,obj);put(u,case['state']+0x440,case['aux']);byte(u,case['state']+0x444,case['flag'])
    put(u,0x6a3afc,case['elapsed']);put(u,0x6a3b00,case['maximum']);put(u,0x6a3b04,case['anchor']);put(u,0x5deb58,case['diagnostic']);put(u,0x6a57d8,LOCK)
    put(u,0x5b2080,CLOCK)
    trace=[]
    def hook(m,address,_size,_):
        if address not in (BOUNDARY,CLOCK,0x5322c0):return
        sp=m.reg_read(UC_X86_REG_ESP)
        if address==BOUNDARY:
            obj,arg=word(m,sp+4),word(m,sp+8);trace.append('method80:'+('a' if obj==OBJECT_A else 'b' if obj==OBJECT_B else str(obj))+':'+str(arg));cleanup=12
        elif address==CLOCK:trace.append('clock:'+str(case['tick']));m.reg_write(UC_X86_REG_EAX,case['tick']);cleanup=4
        else:trace.append('leave:lock' if word(m,sp+4)==LOCK else 'leave:other');cleanup=4
        m.reg_write(UC_X86_REG_ESP,sp+cleanup);m.reg_write(UC_X86_REG_EIP,word(m,sp))
    u.hook_add(UC_HOOK_CODE,hook)
    put(u,STACK,EXIT);put(u,STACK+4,case['arg']);u.reg_write(UC_X86_REG_ESP,STACK)
    u.emu_start(0x5588a0,EXIT,count=20000)
    obj=word(u,case['state']+0x43c);names={OBJECT_A:'a',OBJECT_B:'b'}
    fields=[names.get(obj,str(obj)),word(u,case['state']+0x440),u.mem_read(case['state']+0x444,1)[0],word(u,0x6a3afc),word(u,0x6a3b00),word(u,0x6a3b04),word(u,0x5deb58)]
    return {'fields':fields,'calls':trace}

def parse(line):
    p=line.split();count=int(p[8]);return {'fields':[p[1],*[int(x) for x in p[2:8]]],'calls':p[9:9+count]}

def native_input(case):
    return ' '.join(str(case[key]) for key in ('name','mode','tick','anchor','maximum','diagnostic','elapsed','obj_code','aux','flag'))+'\n'

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/object-update-092/bin/Release/object_update_probe.exe');ap.add_argument('--report',type=Path,default=RUN/'verification.json');args=ap.parse_args()
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA:raise RuntimeError('original Porsche.exe SHA mismatch')
    run=subprocess.run([str(args.probe)],input=''.join(native_input(case) for case in CASES),text=True,capture_output=True,check=True,timeout=10)
    actual={line.split()[0]:parse(line) for line in run.stdout.splitlines()}
    outputs=[]
    for case in CASES:
        name=case['name']
        expected=original(module,image,case)
        if actual.get(name)!=expected:raise RuntimeError(f'{name}: original={expected}, native={actual.get(name)}')
        outputs.append({'case':name,'output':expected})
    dependencies=['iterations/v2/001-original-recovery/source/include/porsche/object_update.hpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/object_update.cpp','iterations/v2/001-original-recovery/source/recovered/object_update_probe.cpp','iterations/v2/001-original-recovery/runs/092-object-update/CMakeLists.txt','iterations/v2/001-original-recovery/runs/092-object-update/README.md','scripts/research/verify-v2-object-update.py']
    report={'schema':1,'sha256':SHA,'full_function_vas':['005588a0'],'partial_function_vas':[],'original_sha256':SHA,'function_vas':['005588a0'],'function_va':'005588a0','body_bytes':118,'caller_va':'00558c9d','cases':outputs,'native_cpp_equal_original_x86':True,'abi':'005588a0 cdecl(void*); GetTickCount typed stdcall(void); vtable +0x80 stdcall(void*,uint32_t); lock leave cdecl(void*)','canonical_global_owners':{'006a3afc':'object_update_word_006a3afc','006a3b00':'object_update_word_006a3b00','006a3b04':'object_update_word_006a3b04','005deb58':'object_update_word_005deb58','006a57d8':'existing thread_start_lock_006a57d8'},'boundaries':'GetTickCount is replaced only by a typed recording fixture boundary; vtable +0x80 remains an explicit no-effect recorder. Values at 006a3afc/006a3b00/006a3b04 are zero-filled BSS; 005deb58 is raw-backed at file offset 0x1deb58 and contains zero. The function only reads 006a3b04. A zero +43c handle bypasses vtable, clock, and lock-leave, but still clears 005deb58.','source_sha256':source_hashes(dependencies,compiled_sources=dependencies[:3]),'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),'game_launch_verified':False}
    args.report.parent.mkdir(parents=True,exist_ok=True);args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'cases':len(outputs),'matched':True,'report':str(args.report)}))
if __name__=='__main__':main()
