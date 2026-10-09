"""Verify the 0x6573e8 FE arena and original 0053c290 fill dispatch."""
import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/068-application-state'
SOURCE=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
BASE,LENGTH,ARGV=0x006573e8,0x3e24,0x0065b20c
IMAGE,IMAGE_BYTES=0x00400000,0x00300000
STACK,EXIT=0x0200f000,0x02200000
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
CASES=[(d,v,0,LENGTH) for d in (0,1,2) for v in (0,0x1234567b)] + [
    (0,0x89abcdef,1,7),(0,0x89abcdef,2,5),(0,0x89abcdef,3,9),
    (0,0x89abcdef,4,3),(0,0x89abcdef,0,LENGTH-3),(0,0x89abcdef,0,0)]
TARGETS={0:0x005b0980,1:0x005b0a40,2:0x005b0b00}
sys.path.insert(0,str(ROOT/'scripts/research'))
from v2_source_dependencies import source_hashes
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP,UC_X86_REG_ESP

def pe_section(binary,name):
    pe=struct.unpack_from('<I',binary,0x3c)[0]
    section_count=struct.unpack_from('<H',binary,pe+6)[0]
    optional_size=struct.unpack_from('<H',binary,pe+20)[0]
    image_base=struct.unpack_from('<I',binary,pe+24+28)[0]
    table=pe+24+optional_size
    for i in range(section_count):
        off=table+i*40
        section_name=binary[off:off+8].split(b'\0',1)[0].decode('ascii')
        virtual_size,rva,raw_size,raw_offset=struct.unpack_from('<IIII',binary,off+8)
        if section_name==name:
            return {'image_base':image_base,'va':image_base+rva,'virtual_size':virtual_size,
                    'raw_size':raw_size,'raw_offset':raw_offset,'rva':rva}
    raise RuntimeError(f'PE section not found: {name}')

def load_image(uc,module,binary):
    uc.mem_map(IMAGE,IMAGE_BYTES)
    for sec in module['sections']:
        if sec['raw_size']:
            uc.mem_write(IMAGE+sec['rva'],binary[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])

def original_case(module,binary,dispatch,value,offset,count):
    uc=Uc(UC_ARCH_X86,UC_MODE_32)
    load_image(uc,module,binary)
    uc.mem_map(0x02000000,0x10000)
    uc.mem_map(EXIT,0x1000)
    initial=uc.mem_read(BASE,LENGTH)
    if initial!=b'\0'*LENGTH:raise AssertionError('emulated PE zero-fill span was not initially zero')
    # Canary prefix, exact candidate span, then argv[32] and a suffix.
    start=BASE-32
    end=ARGV+128+32
    uc.mem_write(start,b'\x6d'*32)
    seed=bytes((i*37+11)&0xff for i in range(LENGTH))
    uc.mem_write(BASE,seed)
    uc.mem_write(ARGV,b'\x6d'*128+b'\x6d'*32)
    uc.mem_write(BASE,struct.pack('<I',0x11223344))
    uc.mem_write(BASE+1,b'\x55')
    uc.mem_write(0x00657a38,b'ABCD\0')
    uc.mem_write(0x00657a84,b'TEST\0')
    uc.mem_write(0x00657a60,struct.pack('<I',0x10203040))
    uc.mem_write(0x00657a64,b'\x7f')
    uc.mem_write(0x00657e34,b'\xa3')
    uc.mem_write(0x005deb1c,struct.pack('<I',1 if dispatch==2 else 0))
    uc.mem_write(0x005deb18,struct.pack('<I',1 if dispatch==1 else 0))
    argv_seed=bytes((i*7+3)&0xff for i in range(128))
    uc.mem_write(ARGV,argv_seed)
    calls=[]
    def hook(machine,addr,size,_):
        if addr==EXIT:
            machine.emu_stop();return
        if addr in TARGETS.values():calls.append(addr)
    uc.hook_add(UC_HOOK_CODE,hook)
    target=BASE+offset
    uc.mem_write(STACK,struct.pack('<IIII',EXIT,target,value,count))
    uc.reg_write(UC_X86_REG_ESP,STACK)
    try:
        uc.emu_start(0x0053c290,EXIT+1,count=500000)
    except Exception as exc:
        raise RuntimeError(f'original fill failed at {uc.reg_read(UC_X86_REG_EIP):08x}, calls={calls}') from exc
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:
        raise RuntimeError(f'original fill did not return; pc={uc.reg_read(UC_X86_REG_EIP):08x}')
    expected_target=TARGETS[dispatch]
    if calls!=[expected_target]:raise AssertionError(f'dispatch {dispatch}: expected {expected_target:08x}, got {[f"{x:08x}" for x in calls]}')
    arena=bytes(uc.mem_read(BASE,LENGTH))
    prefix=bytes(uc.mem_read(start,32))
    argv_after=bytes(uc.mem_read(ARGV,128))
    suffix=bytes(uc.mem_read(ARGV+128,32))
    if dispatch in (0,1,2) and value==0 and offset==0 and count==LENGTH and arena!=b'\0'*LENGTH:
        raise AssertionError(f'original clear differs at dispatch {dispatch}')
    if offset==0 and count==LENGTH and value!=0:
        expected=bytes((value>>(8*(i&3)))&0xff for i in range(LENGTH))
        if arena!=expected:raise AssertionError(f'original dword-pattern fill differs at dispatch {dispatch}')
    if prefix!=b'\x6d'*32:raise AssertionError('original fill changed pre-span bytes')
    if argv_after!=argv_seed:raise AssertionError('original fill changed argv[32] immediately after span')
    if suffix!=b'\x6d'*32:raise AssertionError('original fill changed post-argv bytes')
    return {'target':f'{expected_target:08x}','arena_hex':arena.hex(),
            'prefix_unchanged':True,'argv_unchanged':True,'suffix_unchanged':True,
            'initial_bss_zero':True}

def direct_addresses(asm_text):
    rows={}
    for line in asm_text.splitlines():
        match=re.search(r'\b(?:[0-9a-fA-F]{8})\s+[0-9a-fA-F]+\s+(.*)',line)
        if not match:continue
        ins=match.group(1)
        for found in re.finditer(r'\[([^\]]*)\]',ins):
            address=re.search(r'0x([0-9a-fA-F]{8})',found.group(1))
            if not address:continue
            va=int(address.group(1),16)
            if not BASE<=va<ARGV:continue
            prefix=ins[:found.start()]
            width=None
            typed=re.search(r'\b(byte|word|dword|qword|xmmword) ptr\s*$',prefix)
            if typed:width={'byte':1,'word':2,'dword':4,'qword':8,'xmmword':16}[typed.group(1)]
            else:
                before=prefix.rsplit(',',1)[-1].strip().upper()
                after=ins[found.end():]
                reg=re.search(r'\b(?:MOV|CMP|TEST|AND|OR|XOR|ADD|SUB|LEA|FILD|FSTP)\s+([A-Z]+)',ins)
                if reg:
                    r=reg.group(1)
                    if r in ('AL','BL','CL','DL','AH','BH','CH','DH'):width=1
                    elif r in ('AX','BX','CX','DX','SI','DI','BP','SP'):width=2
                    elif r.startswith('XMM'):width=16
                    elif r in ('EAX','EBX','ECX','EDX','ESI','EDI','EBP','ESP'):width=4
                if width is None and ('float ptr' in ins or 'dword ptr' in ins):width=4
            entry=rows.setdefault(va,{'va':f'{va:08x}','offset':f'0x{va-BASE:04x}','observed_widths':set(),'assembly_examples':[],'reference_kind':'absolute memory operand'})
            if width is not None:entry['observed_widths'].add(width)
            if len(entry['assembly_examples'])<2:entry['assembly_examples'].append(ins)
    return rows

def layout_report(asm_text):
    rows=direct_addresses(asm_text)
    # Recovered source-level aliases/owners proven by current source declarations.
    known={
      0x006573e8:('uint32_t','global_006573e8; FE table item FEGAME_TYPE, also main mode'),
      0x006573ec:('uint32_t','global_006573ec; FE table item RACE_TYPE'),
      0x006573f0:('uint32_t','global_006573f0; FE table item NUM_LAPS'),
      0x006573f4:('uint32_t','global_006573f4; FE table item SKILL'),
      0x006573f8:('uint32_t','global_006573f8; FE table item RALLY'),
      0x006573fc:('uint32_t','global_006573fc; FE table item HEAVY'),
      0x00657400:('uint32_t','global_00657400; FE table item DERBY'),
      0x00657404:('uint32_t','global_00657404; FE table item COMM_MODE'),
      0x00657408:('uint32_t','global_00657408; FE table item COMMSPOSITIONAL'),
      0x0065740c:('uint32_t','global_0065740c; FE table item NOCOLLISION'),
      0x00657410:('float32 observed','DAT_00657410; no recovered owner'),
      0x00657414:('uint32_t','global_00657414; FE table item COPS'),
      0x00657418:('uint32_t','global_00657418; FE table item TRAFFIC_DENSITY'),
      0x0065741c:('uint32_t','DAT_0065741c; no recovered owner'),
      0x00657420:('uint32_t','global_00657420; FE table item CATCHUP_LOGIC'),
      0x00657424:('uint32_t','DAT_00657424 / application main mode A'),
      0x00657428:('uint32_t','DAT_00657428 / application main mode B'),
      0x0065742c:('uint32_t','global_0065742c; FE table item MIRROR'),
      0x00657430:('uint32_t','global_00657430; FE table item REVERSE'),
      0x00657434:('uint32_t','global_00657434; FE table item MEASUREMENT'),
      0x00657438:('uint32_t','global_00657438; FE table item SGGE'),
      0x0065743c:('uint32_t','global_0065743c; FE table item NOINTROMOVIES / main'),
      0x00657440:('uint32_t','global_00657440; FE table item NOLOADINGSCREEN'),
      0x00657494:('uint32_t','global_00657494; FE table item LINEAR_TRACK'),
      0x00657498:('uint32_t observed','DAT_00657498; no recovered owner'),
      0x006574b8:('uint32_t observed','DAT_006574b8; no recovered owner'),
      0x006577d8:('uint32_t','application main global_006577d8'),
      0x006577dc:('uint32_t','application main global_006577dc'),
      0x00657840:('uint32_t','global_00657840; FE table item SPEECHNUMLOCATIONS'),
      0x00657a24:('uint32_t','global_00657a24; FE table item WEATHER'),
      0x00657a28:('uint32_t','global_00657a28; FE table item FOG'),
      0x00657a2c:('uint32_t','global_00657a2c; FE table item DAMAGE'),
      0x00657a30:('uint32_t','global_00657a30; FE table item TIME'),
      0x00657a34:('uint32_t','global_00657a34; FE table item RAND_SEED'),
      0x00657a38:('char[16]','render_startup.cpp render_selector_00657a38'),
      0x00657a48:('uint32_t','render_startup.cpp render_width; render_display.cpp requested_width is reference alias'),
      0x00657a4c:('uint32_t','render_startup.cpp render_height; render_display.cpp requested_height is reference alias'),
      0x00657a50:('uint32_t','render_display.cpp requested mode'),
      0x00657a58:('uint32_t','render_startup.cpp selected display'),
      0x00657a60:('uint32_t observed','DAT_00657a60; 004b6b68 compares dword; prior app header used wrong byte type'),
      0x00657a64:('uint8_t','application main global; ASM compares byte at 004b6bac'),
      0x00657a84:('char* NUL-terminated view; bound unknown','application main config string; no capacity proven'),
      0x00657aa4:('uint32_t observed','DAT_00657aa4; no recovered owner'),
      0x00657c74:('uint32_t','global_00657c74; FE table item DISPATCH_SPEECH'),
      0x00657c78:('uint32_t','global_00657c78; FE table item REVERSE_CALL'),
      0x00657c7c:('uint32_t','global_00657c7c; FE table item LANGUAGE_SPEECH'),
      0x00657c80:('uint32_t','global_00657c80; FE table item SCENENUMBER'),
      0x00657d5c:('int32_t','render_mode.cpp render_mode_setting_00657d5c'),
      0x00657d60:('int32_t','render_mode.cpp render_mode_setting_00657d60'),
      0x00657d68:('int32_t','render_mode.cpp render_mode_setting_00657d68'),
      0x00657d6c:('int32_t','render_mode.cpp render_mode_setting_00657d6c'),
      0x00657d70:('int32_t','render_mode.cpp render_mode_setting_00657d70'),
      0x00657d78:('int32_t','render_mode.cpp render_mode_setting_00657d78'),
      0x00657d80:('int32_t','render_mode.cpp render_mode_setting_00657d80'),
      0x00657da4:('uint32_t','render_settings.cpp render_settings_registry_flag_00657da4'),
      0x00657e34:('uint8_t','application main flag at 00415292 and other byte accesses'),
      0x0065807c:('uint32_t','global_0065807c; FE table item NUMSMACKABLES'),
      0x00658080:('uint32_t','global_00658080; FE table item NUMCARS'),
      0x00658084:('uint32_t','global_00658084; FE table item NUMPLAYERRACECARS'),
      0x00658088:('uint32_t','global_00658088; FE table item NUMOPPONENTRACECARS'),
    }
    source_literal_addresses=set()
    for line in asm_text.splitlines():
        if '[' in line:continue
        for h in re.findall(r'0x([0-9a-fA-F]{8})',line):
            va=int(h,16)
            if BASE<=va<ARGV:source_literal_addresses.add(va)
    for va in known:
        rows.setdefault(va,{'va':f'{va:08x}','offset':f'0x{va-BASE:04x}','observed_widths':set(),
          'assembly_examples':[],'reference_kind':'source-level recovered field'})
    fields=[]
    for va,row in sorted(rows.items()):
        type_owner=known.get(va)
        type_text=type_owner[0] if type_owner else 'opaque; type/owner unresolved'
        if not type_owner and row['observed_widths']=={1}:
            type_text='opaque; exact 1-byte access, semantic field/owner unresolved'
        owner_text=type_owner[1] if type_owner else 'opaque BSS address referenced by original x86'
        owner_text=owner_text.replace('; FE table item','; fe_tables.inc item')
        if 'char[16]' in type_text:extent=16
        elif type_text.startswith(('uint8_t','char*')):extent=None if type_text.startswith('char*') else 1
        elif type_text.startswith(('uint32_t','int32_t','float32')):extent=4
        else:extent=max(row['observed_widths'],default=None)
        if va==0x006573e8:overlap='same dword also named FEGAME_TYPE in FE table'
        elif va==0x00657a48:overlap='same dword also exposed as render_display_requested_width reference'
        elif va==0x00657a4c:overlap='same dword also exposed as render_display_requested_height reference'
        elif va==0x00657a84:overlap='string extent unknown; may overlap later addresses including 00657aa4'
        else:overlap='none proven' if extent is not None else 'extent unknown'
        fields.append({**row,'observed_widths':sorted(row['observed_widths']),
          'type':type_text,'owner':owner_text,
          'extent_bytes':extent,'overlap':overlap})
    aliases=[
      {'va':'00657a48','names':['render_width_00657a48','render_display_requested_width_00657a48'],
       'relationship':'same storage; latter is a C++ reference to former'},
      {'va':'00657a4c','names':['render_height_00657a4c','render_display_requested_height_00657a4c'],
       'relationship':'same storage; latter is a C++ reference to former'},
      {'va':'006573e8','names':['global_006573e8','FEGAME_TYPE'],
       'relationship':'same dword; FE table label and main mode access'}]
    gaps=[];cursor=BASE
    for va,row in sorted(rows.items()):
        extent=next((f['extent_bytes'] for f in fields if int(f['va'],16)==va),None)
        if va>cursor:gaps.append({'start':f'{cursor:08x}','end_exclusive':f'{va:08x}','classification':'opaque/unmapped; no typed field span assigned'})
        width=extent or max(row['observed_widths'],default=1)
        cursor=max(cursor,va+width)
    if cursor<ARGV:gaps.append({'start':f'{cursor:08x}','end_exclusive':f'{ARGV:08x}','classification':'opaque/unmapped; no direct absolute operand at its first byte'})
    return {'base_va':f'{BASE:08x}','length':f'0x{LENGTH:x}','end_exclusive':f'{ARGV:08x}',
      'fields':fields,'known_aliases':aliases,'opaque_gaps':gaps,
      'address_literals_used_as_pointers':sorted(f'{x:08x}' for x in source_literal_addresses),
      'adjacent_excluded_object':{'va':f'{ARGV:08x}','type':'char*[32]','owner':'startup.cpp argv_0065b20c','offset_from_arena_end':0,
        'relation':'begins exactly at exclusive end; not cleared'}}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/application-state-068/bin/Release/application_state_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=RUN)
    args=parser.parse_args()
    args.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines() if json.loads(x)['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(binary).hexdigest()!=SHA:raise RuntimeError('original SHA mismatch')
    data=pe_section(binary,'.data')
    arena_end=BASE+LENGTH
    if not (data['va']+data['raw_size']<=BASE and arena_end<=data['va']+data['virtual_size']):
        raise AssertionError(f'arena is not entirely in PE .data zero-fill tail: {data}')
    if arena_end!=ARGV:raise AssertionError('argv VA is not exactly adjacent to arena end')
    asm_text=SOURCE.read_text(encoding='utf-8')
    layout=layout_report(asm_text)
    (args.report_dir/'layout.json').write_text(json.dumps(layout,indent=2)+'\n',encoding='utf8',newline='\n')
    probe=args.probe
    native_out=subprocess.run([str(probe)],input=''.join(f'{d} {v} {o} {n}\n' for d,v,o,n in CASES),text=True,capture_output=True,check=True,timeout=30)
    native=[json.loads(x) for x in native_out.stdout.splitlines()]
    if len(native)!=len(CASES):raise AssertionError('native case count mismatch')
    results=[]
    for (dispatch,value,offset,count),actual in zip(CASES,native):
        expected=original_case(module,binary,dispatch,value,offset,count)
        if not actual['alias_ok'] or not actual['guards_ok']:
            raise AssertionError(f'native alias/guard assertion failed for {dispatch}')
        if actual['bytes_hex']!=expected['arena_hex']:
            raise AssertionError(f'native bytes differ from original x86 for dispatch {dispatch}')
        results.append({'dispatch':dispatch,'value':f'0x{value:08x}','offset':offset,'count':count,
          'original_callee':expected['target'],'full_span_equal':True,
          'prefix_argv_suffix_unchanged':True,'initial_bss_zero':expected['initial_bss_zero']})
    source_paths=['iterations/v2/001-original-recovery/source/include/porsche/application_state.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_state.cpp',
      'iterations/v2/001-original-recovery/source/recovered/application_state_probe.cpp',
      'iterations/v2/001-original-recovery/runs/068-application-state/CMakeLists.txt',
      'scripts/research/verify-v2-application-state.py']
    report={'schema':1,'module':'Porsche.exe','sha256':SHA,'original_function':'0053c290..0053c2dc',
      'fill_callees':['005b0980','005b0a40','005b0b00'],'span':{'start_va':f'{BASE:08x}','bytes':f'0x{LENGTH:x}',
        'end_exclusive':f'{arena_end:08x}','word_count':LENGTH//4},
      'pe_data_section':{**data,'zero_fill_start_va':f'{data["va"]+data["raw_size"]:08x}',
        'virtual_end_exclusive_va':f'{data["va"]+data["virtual_size"]:08x}'},
      'span_in_zero_fill_tail':True,'argv_adjacent_not_cleared':True,
      'direct_original_x86_addresses':len(layout['fields']),'known_typed_or_named_fields':sum(not x['type'].startswith('opaque') for x in layout['fields']),
      'opaque_address_fields':sum(x['type'].startswith('opaque') for x in layout['fields']),
      'cases':results,'native_full_bytes_equal_original_x86':True,
      'source_sha256':source_hashes(source_paths,compiled_sources=[
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_state.cpp',
        'iterations/v2/001-original-recovery/source/recovered/application_state_probe.cpp']),
      'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest()}
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
    print(json.dumps({'span':report['span'],'dispatches':len(CASES),'native_full_bytes_equal_original_x86':True,
      'direct_original_x86_addresses':report['direct_original_x86_addresses'],
      'known_typed_or_named_fields':report['known_typed_or_named_fields'],'opaque_address_fields':report['opaque_address_fields']}))

if __name__=='__main__':main()
