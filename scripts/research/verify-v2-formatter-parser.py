"""Compare isolated native formatter parser cases to Porsche.exe x86 execution."""
import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
BASE, MEM, EXIT = 0x400000, 0x2200000, 0x220f000
FMT, DESC, RAW, OUT, TEXT, COUNT = (MEM + x for x in (0x1000,0x2000,0x3000,0x4000,0x5000,0x6000))
CALLBACK, POST_ALT, POST_G = (MEM+x for x in (0x8000,0x8010,0x8020))
WIDE=0x5abf5e
CTYPE=MEM+0x9000
CASES = [
    ('literal','plain text',[]), ('signed','%+06d',[0xffffffd6]),
    ('hex_alt','%#x',[0x1234]),
    ('hex_alt_zero','%#x',[0]),('upperhex_alt_zero','%#X',[0]),
    ('hex_alt_zero_precision','%#.0x',[0]),('pointer_alt_zero','%#p',[0]), ('oct_zero_alt','%#o',[0]),
    ('star_width_precision','%*.*x',[8,4,0x2a]),
    ('string_precision','%.3s',[TEXT]), ('null_string','%s',[0]),
    ('count_store','abc%nX',[COUNT]), ('float_boundary','%f',[0,0x3ff00000]),
    ('float_g_alt','%#.0g',[0,0x3ff00000]), ('unknown','%qZ',[]),
    ('literal_after_percent','%I?',[]),
    ('unsigned_high','%u',[0xffffffff]),('signed_min','%d',[0x80000000]),
    ('zero_precision','%.0d',[0]),('zero_left','%-06d',[12]),
    ('negative_width','%*d',[0xfffffffb,12]),('negative_precision','%.*d',[0xfffffffe,12]),
    ('upperhex_alt','%#X',[0xdeadbeef]),('pointer','%p',[0xdeadbeef]),
    ('int64_signed','%I64d',[0xffffffd6,0xffffffff]),('char','%c',[65]),
    ('wide_char','%C',[65]),('wide_string','%ls',[TEXT]),('percent','%%',[]),
    ('float_upper_e','%E',[0,0x3ff00000]),('float_upper_g','%G',[0,0x3ff00000]),
    ('float_g_trim','%g',[0,0x3ff00000]),('wide_upper_S','%S',[TEXT]),
    ('wide_zero_pad','%05ls',[TEXT]),('wide_left_pad','%-5ls',[TEXT]),
    ('counted_string','%Z',[MEM+0x7000]),('high_byte_literal','\xe9',[]),
    ('lead_initial_pair','\xe9%u',[0x1234]),
    ('lead_pair_enabled','\xe9%u',[0x1234]),('lead_pair_disabled','\xe9%u',[0x1234]),
    ('lead_terminal','\xe9',[]),('lead_zero_capacity','\xe9AB',[]),
    ('lead_one_capacity','\xe9AB',[]),
    ('width_int_min','%*d',[0x80000000,12]),('width_overflow','%2147483648d',[12]),
    ('precision_int_min','%.*d',[0x80000000,12]),('octal_precision_alt','%#.0o',[0]),
    ('octal_nonzero_alt','%#o',[8]),
    ('zero_char','%c',[0]),('wide_char_failure','%C',[0x80]),('long_char','%lc',[65]),
    ('count_store_short','abc%hnX',[COUNT]),('counted_null','%Z',[MEM+0x7000]),
    ('counted_wide','%wZ',[MEM+0x7000]),('string_star_negative','%.*s',[0xffffffff,TEXT]),
    ('signed_i','%i',[0xffffffd6]),('short_signed','%hd',[0xffffffff]),
    ('short_unsigned','%hu',[0xffffffff]),('int64_unsigned','%I64u',[0,1]),
    ('float_lower_e','%.2e',[0,0x3ff00000]),
    ('float_alt_zero','%#.0f',[0,0x3ff00000]),
    ('cleanup_abort','X',[]),
]


def read_va(image, module, va, size):
    rva=va-int(module['image_base'],16)
    s=next(s for s in module['sections'] if s['rva']<=rva and rva+size<=s['rva']+s['raw_size'])
    off=s['raw_offset']+rva-s['rva']
    return image[off:off+size]

def hash_words(words):
    value=1469598103934665603
    for word in words:
        for shift in (0,8,16,24):
            value^=(word>>shift)&0xff
            value=(value*1099511628211)&0xffffffffffffffff
    return f'{value:016x}'


def run_original(module,image,name,fmt,words):
    sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX,UC_X86_REG_EBP,UC_X86_REG_EBX,
        UC_X86_REG_ECX,UC_X86_REG_EDI,UC_X86_REG_EDX,UC_X86_REG_EIP,
        UC_X86_REG_ESI,UC_X86_REG_ESP)
    uc=Uc(UC_ARCH_X86,UC_MODE_32); uc.mem_map(BASE,0x300000)
    for s in module['sections']:
        if s['raw_size']: uc.mem_write(BASE+s['rva'],image[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(MEM,0x10000)
    uc.mem_write(FMT,fmt.encode('latin-1')+b'\0'); uc.mem_write(OUT,b'\xcc'*512)
    tail=bytes(range(0xa0,0xb0)); remaining=128
    if name in ('cleanup_abort','lead_zero_capacity'):remaining=0
    if name=='lead_one_capacity':remaining=1
    uc.mem_write(DESC,struct.pack('<4I',OUT,remaining,OUT,0x42)+tail)
    uc.mem_write(RAW,struct.pack('<'+'I'*max(1,len(words)),*(words or [0])))
    uc.mem_write(TEXT,b'abcdef\0' if name!='wide_string' else struct.pack('<3H',65,66,0)); uc.mem_write(COUNT,struct.pack('<I',0x12345678))
    if name in ('wide_upper_S','wide_zero_pad','wide_left_pad'):uc.mem_write(TEXT,struct.pack('<3H',65,66,0))
    if name=='counted_string':uc.mem_write(MEM+0x7000,struct.pack('<HHI',3,0,TEXT));uc.mem_write(TEXT,b'xyz\0')
    if name=='counted_null':uc.mem_write(MEM+0x7000,struct.pack('<HHI',3,0,0))
    if name=='counted_wide':uc.mem_write(MEM+0x7000,struct.pack('<HHI',4,0,TEXT));uc.mem_write(TEXT,struct.pack('<3H',65,66,0))
    if name.startswith('lead_') and name!='lead_initial_pair':
        table=bytearray(512)
        if name!='lead_pair_disabled':table[0xe9*2+1]=0x80
        uc.mem_write(CTYPE,bytes(table));uc.mem_write(0x5e52d0,struct.pack('<I',CTYPE))
    # Callback cells are installed as if 005a0f5d had initialized them.
    for va,target in ((0x5e5788,CALLBACK),(0x5e5794,POST_ALT),(0x5e578c,POST_G)):
        uc.mem_write(va,struct.pack('<I',target))
    regs={'eax':UC_X86_REG_EAX,'ebx':UC_X86_REG_EBX,'ecx':UC_X86_REG_ECX,'edx':UC_X86_REG_EDX,
          'esi':UC_X86_REG_ESI,'edi':UC_X86_REG_EDI,'ebp':UC_X86_REG_EBP,'esp':UC_X86_REG_ESP}
    seeds={'eax':0xa1a2a3a4,'ebx':0xb1b2b3b4,'ecx':0xc1c2c3c4,'edx':0xd1d2d3d4,
           'esi':0xe1e2e3e4,'edi':0xf1f2f3f4,'ebp':0x1718191a}
    for k,v in seeds.items():uc.reg_write(regs[k],v)
    caller_sp=MEM+0xe000; sp=caller_sp-16
    uc.mem_write(sp,struct.pack('<4I',EXIT,DESC,FMT,RAW)); uc.reg_write(regs['esp'],sp)
    traces={'float_calls':0,'float_low':0,'float_high':0,'float_conv':0,'float_precision':0,'float_mode':0,
            'post_alt':0,'post_g':0,'wide_calls':0,'wide_value':0,'cleanup_calls':0,'cleanup_character':0,'cleanup_descriptor_valid':False,
            'divide_calls':0,'divide_hash':'','remainder_calls':0,'remainder_hash':'','length_calls':0,'length_hash':''}
    div_trace=[];rem_trace=[];pending={};pending_len={};length_trace=[]
    def finish(m,ret,caller_cleanup=0):
        s=m.reg_read(UC_X86_REG_ESP); retaddr=struct.unpack('<I',m.mem_read(s,4))[0]
        m.reg_write(UC_X86_REG_EAX,ret); m.reg_write(UC_X86_REG_ESP,s+4+caller_cleanup); m.reg_write(UC_X86_REG_EIP,retaddr)
    def hook(m,addr,_size,_data):
        if addr==EXIT:m.emu_stop(); return
        if addr in pending:
            kind,a_lo,a_hi,b_lo,b_hi=pending.pop(addr)
            eax=m.reg_read(UC_X86_REG_EAX);edx=m.reg_read(UC_X86_REG_EDX)
            (div_trace if kind=='div' else rem_trace).append((a_lo,a_hi,b_lo,b_hi,eax,edx))
        if addr in pending_len:
            payload=pending_len.pop(addr);eax=m.reg_read(UC_X86_REG_EAX)
            length_trace.append((payload,eax))
        if addr in (0x5a67b0,0x5a6820):
            spx=m.reg_read(UC_X86_REG_ESP);ret,al,ah,bl,bh=struct.unpack('<5I',m.mem_read(spx,20))
            kind='div' if addr==0x5a67b0 else 'rem';pending[ret]=(kind,al,ah,bl,bh)
            if kind=='div':traces['divide_calls']+=1
            else:traces['remainder_calls']+=1
        if addr==0x5a6730:
            spx=m.reg_read(UC_X86_REG_ESP);ret,pointer=struct.unpack('<2I',m.mem_read(spx,8))
            data=bytearray();pos=pointer
            while len(data)<4096:
                byte=m.mem_read(pos,1)[0]
                if byte==0:break
                data.append(byte);pos+=1
            pending_len[ret]=bytes(data)
        sp0=m.reg_read(UC_X86_REG_ESP)
        if addr==0x5a4259:
            _,ch,dp=struct.unpack('<3I',m.mem_read(sp0,12)); traces['cleanup_calls']+=1; traces['cleanup_character']=ch;traces['cleanup_descriptor_valid']=dp==DESC;finish(m,0xffffffff); return
        if addr==CALLBACK:
            _,vp,dest,conv,prec,mode=struct.unpack('<6I',m.mem_read(sp0,24))
            lo,hi=struct.unpack('<2I',m.mem_read(vp,8)); traces.update(float_calls=traces['float_calls']+1,float_low=lo,float_high=hi,float_conv=conv,float_precision=prec,float_mode=mode)
            m.mem_write(dest,b'-1.25\0'); finish(m,0); return
        if addr==POST_ALT: traces['post_alt']+=1; finish(m,0); return
        if addr==POST_G: traces['post_g']+=1; finish(m,0); return
        if addr==WIDE:
            _,dest,ch=struct.unpack('<3I',m.mem_read(sp0,12)); traces['wide_calls']+=1; traces['wide_value']=ch&0xffff
            if (ch&0xffff)>0x7f:finish(m,0xffffffff)
            else:m.mem_write(dest,bytes([ch&0xff]));finish(m,1)
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(0x5a4371,0,count=200000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise AssertionError(f'{name}: parser did not return (EIP={uc.reg_read(UC_X86_REG_EIP):08x})')
    cur,remaining,base,flags=struct.unpack('<4I',uc.mem_read(DESC,16)); used=cur-OUT
    traces['divide_hash']=hash_words(w for x in div_trace for w in x)
    traces['remainder_hash']=hash_words(w for x in rem_trace for w in x)
    h=1469598103934665603
    for data,n in length_trace:
        for byte in data:h=((h^byte)*1099511628211)&0xffffffffffffffff
        for shift in (0,8,16,24):h=((h^((n>>shift)&0xff))*1099511628211)&0xffffffffffffffff
    traces['length_hash']=f'{h:016x}';traces['length_calls']=len(length_trace)
    res={'case':name,'result':struct.unpack('<i',uc.reg_read(UC_X86_REG_EAX).to_bytes(4,'little'))[0],
         'remaining':struct.unpack('<i',struct.pack('<I',remaining))[0],'used':used,'base_offset':base-OUT,'flags':flags,
         'bytes':bytes(uc.mem_read(OUT,used)).hex(),'stored':struct.unpack('<i',uc.mem_read(COUNT,4))[0],**traces,
         'tail':bytes(uc.mem_read(DESC+16,16)).hex(),'caller_stack':uc.reg_read(UC_X86_REG_ESP)==sp+4,
         'callee_saved':[uc.reg_read(regs[k]) for k in ('ebx','esi','edi','ebp')]==[seeds[k] for k in ('ebx','esi','edi','ebp')]}
    return res


def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--probe',type=Path,required=True); ap.add_argument('--report-dir',type=Path,required=True); a=ap.parse_args()
    a.report_dir.mkdir(parents=True,exist_ok=True)
    idx=ROOT/'research/binary-index/static/binaries.jsonl'; module=next(json.loads(x) for x in idx.read_text(encoding='utf-8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA:raise AssertionError('Porsche.exe SHA mismatch')
    orig=[run_original(module,image,*c) for c in CASES]
    native=[json.loads(x) for x in subprocess.run([str(a.probe)],text=True,capture_output=True,check=True).stdout.splitlines()]
    if len(orig)!=len(native):raise AssertionError('native/original parser case count differs')
    keys=('case','result','remaining','used','bytes','base_offset','flags','tail','stored','float_calls','float_low','float_high','float_conv','float_precision','float_mode','post_alt','post_g','wide_calls','wide_value',
          'cleanup_calls','cleanup_character','cleanup_descriptor_valid','divide_calls','divide_hash','remainder_calls','remainder_hash','length_calls','length_hash')
    for o,n in zip(orig,native):
        for k in keys:
            if o[k]!=n[k]:raise AssertionError(f'{o["case"]} {k}: original={o[k]!r} native={n[k]!r}')
        if not o['caller_stack'] or not o['callee_saved']:
            raise AssertionError(f'{o["case"]}: x86 caller stack/callee-saved ABI mismatch')
    all_functions=[json.loads(x) for x in (ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines()]
    by_va={x['entry_va']:x for x in all_functions}
    func=by_va['005a4371']
    for va,size in (('005a67b0',104),('005a6820',117),('005a6730',123),('005abf5e',None),('005abfb7',None)):
        if va not in by_va or (size is not None and by_va[va]['body_bytes']!=size):raise AssertionError(f'parser boundary index changed: {va}')
    callee_hashes={}
    for va in ('005a67b0','005a6820','005a6730','005abf5e','005abfb7'):
        entry=by_va[va]
        raw=read_va(image,module,int(va,16),entry['body_bytes'])
        callee_hashes[va]={'body_bytes':entry['body_bytes'],'body_sha256':hashlib.sha256(raw).hexdigest()}
    class_cell=read_va(image,module,0x5e52d0,4)
    class_table_ptr=struct.unpack('<I',class_cell)[0]
    if class_table_ptr!=0x5e52da:raise AssertionError(f'original ctype pointer-cell initializer changed: {class_table_ptr:08x}')
    class_table=read_va(image,module,class_table_ptr,512)
    if any(class_table[i*2+1]&0x80 for i in range(256)):
        raise AssertionError('initial original ctype table unexpectedly has lead-byte flags')
    body=read_va(image,module,0x5a4371,func['body_bytes'])
    indexdir=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
    calls=[json.loads(x) for x in (indexdir/'calls.jsonl').read_text().splitlines()]
    outgoing=[c for c in calls if c.get('from_function')=='005a4371']
    if len(outgoing)!=28:raise AssertionError(f'parser outgoing edge count changed: {len(outgoing)}')
    calls_by_target={va:[c for c in calls if c.get('to_va')==va] for va in ('005a67b0','005a6820','005a6730','005abf5e','005abfb7')}
    for va in ('005a67b0','005a6820','005a6730'):
        if not any(c.get('from_function')=='005a4371' for c in calls_by_target[va]):raise AssertionError(f'parser edge to {va} changed')
    if not any(c.get('from_function')=='005abf5e' for c in calls_by_target['005abfb7']):raise AssertionError('wide wrapper callee edge changed')
    source_parser=(ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/formatter_parser.cpp').read_text(encoding='utf-8')
    literal_table=bytes(int(x,16) for x in re.findall(r'0x([0-9a-fA-F]{2})',source_parser.split('constexpr std::uint8_t kTable[128] = {',1)[1].split('};',1)[0]))
    raw_table=read_va(image,module,0x5c19c8,128)
    if literal_table!=raw_table:raise AssertionError('native transition/class table differs from original raw bytes')
    ctype_match=re.search(r'constexpr std::uint8_t kInitialCtypeTable\[512\] = \{(.*?)\};',source_parser,re.S)
    if not ctype_match:raise AssertionError('canonical initial ctype table owner missing')
    literal_ctype=bytes(int(x,16) for x in re.findall(r'0x([0-9a-fA-F]{2})',ctype_match.group(1)))
    if literal_ctype!=class_table:raise AssertionError('canonical initial ctype table differs from original bytes')
    if 'formatter_ctype_table_005e52d0 = kInitialCtypeTable;' not in source_parser:
        raise AssertionError('canonical pointer-cell owner does not point at pinned initial bytes')
    dispatch=struct.unpack('<8I',read_va(image,module,0x5a4a92,32))
    asm=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    src='iterations/v2/001-original-recovery/source/'
    files=[src+'include/porsche/formatter_parser.hpp',src+'recovered/Porsche.exe/formatter_parser.cpp',src+'recovered/formatter_parser_probe.cpp',
           src+'include/porsche/formatter_original.hpp',src+'recovered/Porsche.exe/formatter_original.cpp',
           'iterations/v2/001-original-recovery/runs/124-formatter-parser/CMakeLists.txt',
           'iterations/v2/001-original-recovery/runs/124-formatter-parser/README.md','scripts/research/verify-v2-formatter-parser.py']
    report={'schema':1,'module':'Porsche.exe','sha256':SHA,'module_sha256':SHA,'parser_va':'005a4371','parser_bytes':func['body_bytes'],
      'parser_body_sha256':hashlib.sha256(body).hexdigest(),'parser_table_va':'005c19c8','table_bytes':raw_table.hex(),
      'table_sha256':hashlib.sha256(raw_table).hexdigest(),'cases':len(orig),'case_results':orig,
      'function_vas':['005a4371'],'full_function_vas':['005a4371'],'partial_function_vas':[],
      'dispatch_table_005a4a92':[hex(x) for x in dispatch],
      'character_class_table':{'pointer_cell_va':'005e52d0','initial_pointer':hex(class_table_ptr),'bytes_sha256':hashlib.sha256(class_table).hexdigest(),
        'lead_byte_flags_set':[i for i in range(256) if class_table[i*2+1]&0x80],
        'state0_branch':'005a4510-005a454f reads pointer cell each dispatch; tests table[unsigned_BL*2+1]&0x80, emits current signed byte, consumes and emits one following byte when set',
        'mutation_cases':['lead_initial_pair','lead_pair_enabled','lead_pair_disabled','lead_terminal','lead_zero_capacity','lead_one_capacity'],
        'native_projection':'canonical source retains all512 original bytes; mutable pointer fixtures test the consumer predicate0x80 at odd offsets; initial table has no such flags'},
      'native_cpp_equal_original_x86':True,'boundary_limitations':{'cleanup_005a4259':'typed cdecl boundary; one zero-capacity case verifies exact call arguments and -1 abort path; cleanup body/effects remain unrecovered',
      'float_callbacks':'callback cells are fixture-initialized to recorders; 005a0f5d initialization and floating conversion/output semantics remain unrecovered',
      'wide_encoder_005abf5e':'typed cdecl boundary; AX-sized character and output buffer are recorded; fixture encoding results are not claimed',
      'native_integration':'005e52d0 pointer cell and its exact initial table are owned here; other callback/null-string globals remain extern boundary bindings; the packet is still isolated and not wired into game entry',
      'crt_unsigned_division':'original 005a67b0/005a6820 bodies execute in Unicorn; native parser calls injected typed boundaries; input/result traces match for every parsed digit',
      'crt_strlen':'original 005a6730 body executes in Unicorn; native parser calls injected typed boundary; contents/length trace matches',
      'format_subset':f'{len(orig)} fixture cases exercise all eight transition states, supported conversion letters, mutable state-0 lead-byte table predicate, and listed edge inputs; finite cases do not prove every input combination'},
      'binary_index':{'functions_sha256':hashlib.sha256((indexdir/'functions.jsonl').read_bytes()).hexdigest(),'calls_sha256':hashlib.sha256((indexdir/'calls.jsonl').read_bytes()).hexdigest(),
      'callee_body_hashes':callee_hashes,
      'callee_call_sites':{va:[{'from':c['from_va'],'from_function':c['from_function'],'type':c['type']} for c in vals] for va,vals in calls_by_target.items()},
      'disassembly_sha256':hashlib.sha256(asm.read_bytes()).hexdigest(),'outgoing_edges':[{'from':x['from_va'],'to':x['to_va'],'type':x['type']} for x in outgoing]},
      'abi':{'parser':'cdecl(descriptor32*, format_bytes*, first_vararg_dword*); signed count returned in EAX; original advances its local stack copy of the raw argument pointer',
        'descriptor':'32 bytes; cursor/remaining/base/flags at +0/+4/+8/+0xc; opaque tail +0x10..+0x1f is preserved',
        'unsigned_divide_remainder':'stdcall(uint64 dividend,uint64 divisor), original helpers RET 0x10; traces compare all six input/result dwords per call',
        'strlen':'cdecl(const char*), original caller removes its argument; content bytes and EAX length are traced',
        'wide_encode':'cdecl(char* destination,uint32 stack_value); downstream 005abfb7 consumes the low WCHAR; high 16 bits are address-dependent and are not compared',
        'float_callback':'cdecl(double_words*,char*,conversion,precision,mode); recorder verifies callback order/arguments but supplies fixture text'},
      'source_sha256':source_hashes([ROOT/p for p in files],compiled_sources=[ROOT/(src+'recovered/formatter_parser_probe.cpp'),ROOT/(src+'recovered/Porsche.exe/formatter_parser.cpp'),ROOT/(src+'recovered/Porsche.exe/formatter_original.cpp')]),'compiled_translation_units':[src+'recovered/formatter_parser_probe.cpp',src+'recovered/Porsche.exe/formatter_parser.cpp',src+'recovered/Porsche.exe/formatter_original.cpp'],
      'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'game_launch_verified':False}
    (a.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'cases':len(orig),'parser_bytes':func['body_bytes'],'native_cpp_equal_original_x86':True,'formats_recovered':'tested subset only'}))

if __name__=='__main__':main()
