"""Differentially check the connected formatter wrapper/parser/helper/cleanup path."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
BASE, MEM, EXIT = 0x400000, 0x2200000, 0x220f000
FMT, DESC, RAW, OUT, TEXT, COUNT, BANK = (MEM+x for x in (0x1000,0x2000,0x3000,0x4000,0x5000,0x6000,0x7000))
ENTRY, EMIT = 0x5a0fbf, 0x5a4ab2
TRACKED_VAS={0x5a0fbf,0x5a4371,0x5a4ab2,0x5a4ae7,0x5a4b18,0x5a4b50,0x5a4b5d,0x5a4259,0x5abf35,0x5a67b0,0x5a6820,0x5a6730}
TAIL = bytes(range(0xa0,0xb0))
CASES = [
    ('literal','plain text',[]), ('signed_width','%+06d',[0xffffffd6]),
    ('hex_alt','%#x',[0x1234]), ('star_width_precision','%*.*x',[8,4,0x2a]),
    ('string_precision','%.3s',[TEXT]), ('count_store','abc%nX',[COUNT]),
    ('unsigned_word','%u',[0xffffffff]), ('int64_signed','%I64d',[0xffffffd6,0xffffffff]),
    ('unknown_conversion','%qZ',[]), ('literal_high_byte','\xe9',[]),
]


def read_va(image, module, va, size):
    rva=va-int(module['image_base'],16)
    s=next(s for s in module['sections'] if s['rva']<=rva and rva+size<=s['rva']+s['raw_size'])
    off=s['raw_offset']+rva-s['rva']
    return image[off:off+size]


def signed(v): return struct.unpack('<i',struct.pack('<I',v&0xffffffff))[0]


def run_original(module,image,case,cleanup=False,parser_cleanup=False):
    sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX,UC_X86_REG_EBP,UC_X86_REG_EBX,
        UC_X86_REG_EDI,UC_X86_REG_EIP,UC_X86_REG_ESI,UC_X86_REG_ESP)
    uc=Uc(UC_ARCH_X86,UC_MODE_32); uc.mem_map(BASE,0x300000)
    for s in module['sections']:
        if s['raw_size']: uc.mem_write(BASE+s['rva'],image[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(MEM,0x10000)
    regs={'eax':UC_X86_REG_EAX,'ebx':UC_X86_REG_EBX,'esi':UC_X86_REG_ESI,
          'edi':UC_X86_REG_EDI,'ebp':UC_X86_REG_EBP,'esp':UC_X86_REG_ESP}
    seeds={'eax':0xa1a2a3a4,'ebx':0xb1b2b3b4,'esi':0xe1e2e3e4,'edi':0xf1f2f3f4,'ebp':0x1718191a}
    for k,v in seeds.items(): uc.reg_write(regs[k],v)
    trace={'events':[],'write_calls':0,'write_file':0,'write_length':0,'write_bytes':'',
           'prepare_calls':0,'prepare_file':0,'prepare_flags':0,'aux_calls':0,'function_vas':[]}
    write_return=1

    if cleanup:
        name='emit_cleanup_connected'; output=bytes([0xcc])*16
        uc.mem_write(OUT,output); uc.mem_write(BANK,b'\0'*(32*36))
        uc.mem_write(0x6c01dc,struct.pack('<I',BANK)); uc.mem_write(0x6c01e0,struct.pack('<I',BANK))
        uc.mem_write(0x6c02e0,struct.pack('<I',32))
        tail=struct.pack('<4I',5,0x14151617,8,0x1c1d1e1f)
        uc.mem_write(DESC,struct.pack('<4I',OUT,0,OUT,2)+tail)
        uc.mem_write(COUNT,struct.pack('<I',0))
        sp=MEM+0xe000-16; uc.mem_write(sp,struct.pack('<4I',EXIT,ord('K'),DESC,COUNT)); start=EMIT
    elif parser_cleanup:
        name='parser_cleanup_connected'; output=bytes([0xcc])*8
        uc.mem_write(OUT,output); uc.mem_write(FMT,b'AB\0'); uc.mem_write(RAW,b'\0'*4)
        uc.mem_write(BANK,b'\0'*(32*36)); uc.mem_write(0x6c01dc,struct.pack('<I',BANK))
        uc.mem_write(0x6c01e0,struct.pack('<I',BANK)); uc.mem_write(0x6c02e0,struct.pack('<I',32))
        tail=struct.pack('<4I',5,0x14151617,8,0x1c1d1e1f)
        uc.mem_write(DESC,struct.pack('<4I',OUT,1,OUT,2)+tail)
        sp=MEM+0xe000-16; uc.mem_write(sp,struct.pack('<4I',EXIT,DESC,FMT,RAW)); start=0x5a4371
    else:
        name,fmt,words=case
        uc.mem_write(FMT,fmt.encode('latin-1')+b'\0'); uc.mem_write(OUT,b'\xcc'*128)
        if name=='count_store': uc.mem_write(COUNT,struct.pack('<I',0x12345678))
        else: uc.mem_write(COUNT,struct.pack('<I',0x12345678))
        uc.mem_write(TEXT,b'abcdef\0')
        words=list(words)
        if name=='string_precision': words[0]=TEXT
        if name=='count_store': words[0]=COUNT
        uc.mem_write(BANK,b'\0'*(32*36)); uc.mem_write(0x6c01dc,struct.pack('<I',BANK))
        uc.mem_write(0x6c01e0,struct.pack('<I',BANK)); uc.mem_write(0x6c02e0,struct.pack('<I',32))
        sp=MEM+0xe000
        # The original wrapper reserves 32 bytes and writes only the prefix.
        # Seed the tail bytes before entry to model the existing stack slot.
        local_desc=sp-0x24; uc.mem_write(local_desc+16,TAIL)
        uc.mem_write(FMT,fmt.encode('latin-1')+b'\0')
        uc.mem_write(sp,struct.pack('<3I',EXIT,OUT,FMT)+struct.pack('<'+'I'*max(1,len(words)),*(words or [0])))
        start=ENTRY
    uc.reg_write(regs['esp'],sp)

    def finish(m,ret):
        s=m.reg_read(UC_X86_REG_ESP); dest=struct.unpack('<I',m.mem_read(s,4))[0]
        m.reg_write(UC_X86_REG_EAX,ret); m.reg_write(UC_X86_REG_ESP,s+4); m.reg_write(UC_X86_REG_EIP,dest)

    def hook(m,addr,_size,_data):
        if addr in TRACKED_VAS and f'{addr:08x}' not in trace['function_vas']:
            trace['function_vas'].append(f'{addr:08x}')
        if addr==EXIT: m.emu_stop(); return
        s=m.reg_read(UC_X86_REG_ESP)
        if addr==0x5a9e49:
            _,fid,ptr,length=struct.unpack('<4I',m.mem_read(s,16))
            trace.update(write_calls=trace['write_calls']+1,write_file=fid,write_length=length,
                         write_bytes=bytes(m.mem_read(ptr,min(length,16))).hex())
            trace['events'].append(2); finish(m,write_return); return
        if addr==0x5a9ab8:
            trace['aux_calls']+=1; trace['events'].append(3); finish(m,0); return
        if addr==0x5abef1:
            _,d=struct.unpack('<2I',m.mem_read(s,8))
            flags=struct.unpack('<I',m.mem_read(d+12,4))[0]
            fid=struct.unpack('<I',m.mem_read(d+16,4))[0]
            trace.update(prepare_calls=trace['prepare_calls']+1,prepare_file=fid,prepare_flags=flags)
            trace['events'].append(1); finish(m,0); return
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(start,0,count=300000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT: raise AssertionError(f'{name}: original did not return (EIP={uc.reg_read(UC_X86_REG_EIP):08x})')
    desc=DESC if (cleanup or parser_cleanup) else sp-0x24
    db=bytes(uc.mem_read(desc,32)); cur,rem,base,flags=struct.unpack('<4I',db[:16])
    if cleanup:
        count=struct.unpack('<i',uc.mem_read(COUNT,4))[0]
        result={'case':name,'count':count,'eax_is_count_pointer':uc.reg_read(UC_X86_REG_EAX)==COUNT,
                'remaining':signed(rem),'flags':flags,'cursor_offset':signed(cur-OUT),'base_offset':signed(base-OUT),
                'tail':db[16:].hex(),**trace}
    elif parser_cleanup:
        result={'case':name,'result':signed(uc.reg_read(UC_X86_REG_EAX)),
                'remaining':signed(rem),'flags':flags,'cursor_offset':signed(cur-OUT),
                'base_offset':signed(base-OUT),'output':bytes(uc.mem_read(OUT,4)).hex(),
                'tail':db[16:].hex(),**trace}
    else:
        used=0
        while used<128 and uc.mem_read(OUT+used,1)[0]!=0: used+=1
        stored=struct.unpack('<i',uc.mem_read(COUNT,4))[0]
        result={'case':name,'result':signed(uc.reg_read(UC_X86_REG_EAX)),'used':used,
                'remaining':signed(rem),'flags':flags,'cursor_offset':signed(cur-OUT),'base_offset':signed(base-OUT),
                'output':bytes(uc.mem_read(OUT,used+1)).hex(),'stored':stored,'tail':db[16:].hex(),**trace}
    result['caller_stack_ok']=uc.reg_read(UC_X86_REG_ESP)==sp+4
    result['callee_saved_ok']=[uc.reg_read(regs[k]) for k in ('ebx','esi','edi','ebp')]==[seeds[k] for k in ('ebx','esi','edi','ebp')]
    return result


def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--probe',type=Path,required=True); ap.add_argument('--report-dir',type=Path,required=True); a=ap.parse_args()
    a.report_dir.mkdir(parents=True,exist_ok=True)
    index=ROOT/'research/binary-index/static/binaries.jsonl'
    module=next(json.loads(x) for x in index.read_text(encoding='utf-8').splitlines() if json.loads(x)['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA: raise AssertionError('Porsche.exe SHA mismatch')
    original=[run_original(module,image,c) for c in CASES]
    original.append(run_original(module,image,None,cleanup=True))
    original.append(run_original(module,image,None,parser_cleanup=True))
    native=[json.loads(x) for x in subprocess.run([str(a.probe)],text=True,capture_output=True,check=True).stdout.splitlines()]
    if len(original)!=len(native): raise AssertionError('connected formatter case count differs')
    keys=('case','result','used','remaining','flags','cursor_offset','base_offset','output','stored','tail',
          'events','write_calls','write_file','write_length','write_bytes','prepare_calls','prepare_file','prepare_flags','aux_calls')
    for o,n in zip(original[:-1],native[:-1]):
        for k in keys:
            if o.get(k)!=n.get(k): raise AssertionError(f'{o["case"]} {k}: original={o.get(k)!r}, native={n.get(k)!r}')
        for original_key,native_key in (('result','actual_result'),('used','actual_used'),('output','actual_output'),('stored','actual_stored')):
            if o.get(original_key)!=n.get(native_key):
                raise AssertionError(f'{o["case"]} actual entry {native_key}: original={o.get(original_key)!r}, native={n.get(native_key)!r}')
        if not o['caller_stack_ok'] or not o['callee_saved_ok']: raise AssertionError(f'{o["case"]}: x86 ABI mismatch')
    o,n=original[-2],native[-2]
    for k in ('case','count','eax_is_count_pointer','remaining','flags','cursor_offset','base_offset','tail','events','write_calls','write_file','write_length','write_bytes','prepare_calls','prepare_file','prepare_flags','aux_calls'):
        if o.get(k)!=n.get(k): raise AssertionError(f'cleanup bridge {k}: original={o.get(k)!r}, native={n.get(k)!r}')
    if not o['caller_stack_ok'] or not o['callee_saved_ok']: raise AssertionError('cleanup bridge x86 ABI mismatch')
    o,n=original[-1],native[-1]
    for k in ('case','result','remaining','flags','cursor_offset','base_offset','output','tail','events','write_calls','write_file','write_length','write_bytes','prepare_calls','prepare_file','prepare_flags','aux_calls'):
        if o.get(k)!=n.get(k): raise AssertionError(f'parser/cleanup bridge {k}: original={o.get(k)!r}, native={n.get(k)!r}')
    if not o['caller_stack_ok'] or not o['callee_saved_ok']: raise AssertionError('parser/cleanup bridge x86 ABI mismatch')

    idxdir=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
    funcs={json.loads(x)['entry_va']:json.loads(x) for x in (idxdir/'functions.jsonl').read_text().splitlines()}
    executed_vas=sorted({va for case in original for va in case['function_vas']})
    body_hashes={}
    for va in executed_vas:
        size=funcs.get(va,{}).get('body_bytes')
        if not size: raise AssertionError(f'executed function missing from index: {va}')
        body_hashes[va]={'bytes':size,'sha256':hashlib.sha256(read_va(image,module,int(va,16),size)).hexdigest()}
    asm=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    src='iterations/v2/001-original-recovery/source/'
    run='iterations/v2/001-original-recovery/runs/134-formatter-integration/'
    files=[src+'include/porsche/formatter_entry.hpp',src+'include/porsche/formatter_original.hpp',src+'include/porsche/formatter_parser.hpp',src+'include/porsche/formatter_cleanup.hpp',
      src+'recovered/Porsche.exe/formatter_entry.cpp',src+'recovered/Porsche.exe/formatter_parser_entry_bridge.cpp',
      src+'recovered/Porsche.exe/formatter_original.cpp',src+'recovered/Porsche.exe/formatter_parser.cpp',src+'recovered/Porsche.exe/formatter_cleanup.cpp',
      run+'CMakeLists.txt',run+'README.md',run+'formatter_entry32_adapter.cpp',run+'formatter_integration_probe.cpp',
      'scripts/research/verify-v2-formatter-integration.py']
    compiled=[run+'formatter_entry32_adapter.cpp',run+'formatter_integration_probe.cpp',src+'recovered/Porsche.exe/formatter_entry.cpp',
      src+'recovered/Porsche.exe/formatter_parser_entry_bridge.cpp',src+'recovered/Porsche.exe/formatter_original.cpp',
      src+'recovered/Porsche.exe/formatter_parser.cpp',src+'recovered/Porsche.exe/formatter_cleanup.cpp',src+'recovered/Porsche.exe/formatter_runtime.cpp',src+'platform/formatter_runtime_links.cpp']
    report={'schema':1,'module':'Porsche.exe','sha256':SHA,'module_sha256':SHA,'cases':len(original),'case_results':original,
      'original_body_hashes':body_hashes,'connected_native_translation_units':compiled,
      'entry_vas':['005a0fbf'],'function_vas':executed_vas,'native_cpp_equal_original_x86':True,
      'full_native_source_units':['formatter_entry.cpp(108 body)','formatter_parser_entry_bridge.cpp(108→124 typed binding)',
        'formatter_original.cpp(119 helpers)','formatter_parser.cpp(124 body)','formatter_cleanup.cpp(132 body)','formatter_runtime.cpp(137 integer/string leaves)'],
      'entry_adapter':'A test-only 32-byte adapter preserves explicit opaque-tail evidence; each bounded entry case also calls the actual linked formatter_entry_raw_005a0fbf source and compares its output/result/state with the original x86 entry.',
      'descriptor':{'bytes':32,'prefix_offsets':{'cursor':0,'remaining':4,'base':8,'flags':12},'opaque_tail_offsets':[16,20,24,28],
        'wrapper_behavior':'original 005a0fbf reserves 32 bytes but writes only the prefix; fixture seeds stack tail bytes before entry, native adapter receives the same explicit bytes; no tail zero-init',
        'cleanup_read':'original loads +0x10 before flags; native proposed source snapshots opaque bytes but only decodes file_id after the early flag exit'},
      'open_boundaries':{'005a9e49':'file write recorder; backend effects unresolved','005a9ab8':'auxiliary file operation recorder; external effects unresolved',
        '005abef1':'descriptor prepare/allocation recorder; allocator effects unresolved','float/wide callbacks':'not exercised by integrated cases; remain typed external contracts',
        'stream aliases':'fixture aliases point at test descriptors; canonical production owners at 005e5508/005e5528 remain unbound'},
      'source_sha256':source_hashes([ROOT/p for p in files],compiled_sources=[ROOT/p for p in compiled]),
      'disassembly_sha256':hashlib.sha256(asm.read_bytes()).hexdigest(),
      'functions_index_sha256':hashlib.sha256((idxdir/'functions.jsonl').read_bytes()).hexdigest(),
      'game_launch_verified':False}
    (a.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'cases':len(original),'all_connected_body_cases_match':True,'game_launch_verified':False}))

if __name__=='__main__': main()
