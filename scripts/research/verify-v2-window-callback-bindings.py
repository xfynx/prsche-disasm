from v2_source_dependencies import source_hashes
"""Verify original window_init callback registrations are relocated to native pointers."""
import argparse,hashlib,json,re,subprocess,sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/064-window-callback-bindings'
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
ASM=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
FUNC=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl'
VA_LINE=re.compile(r'^(?P<va>[0-9a-fA-F]{8})\s+\S+\s+(?P<text>.*)$')
PUSH=re.compile(r'PUSH\s+(?:0x(?P<hex>[0-9a-fA-F]+)|(?P<dec>-?\d+))')

def original_registrations():
    rows=[];pending=[];lines=ASM.read_text(encoding='utf8').splitlines()
    for line in lines:
        m=VA_LINE.match(line)
        if not m:continue
        va=int(m['va'],16);text=m['text']
        if not 0x53ad35<=va<0x53aecf:continue
        p=PUSH.search(text)
        if p:
            value=int(p['hex'],16) if p['hex'] is not None else int(p['dec'],10)
            pending.append(value&0xffffffff)
        if 'CALL 0x0053a800' in text:
            if len(pending)<2:raise RuntimeError(f'missing callback arguments at {va:08x}')
            rows.append((pending[-1],pending[-2]));pending.clear()
    return rows

def source_registrations():
    path=ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_init.cpp'
    pairs=re.findall(r'\{\s*(0x[0-9a-fA-F]+|\d+)\s*,\s*(0x[0-9a-fA-F]+)\s*\}',path.read_text(encoding='utf8'))
    return [(int(a,0),int(b,16)) for a,b in pairs]

def function_abis(addresses):
    asm_lines=[]
    for line in ASM.read_text(encoding='utf8').splitlines():
        m=re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]+)\s+(.*)$',line)
        if m:asm_lines.append((int(m[1],16),m[2],m[3]))
    # Ghidra did not create function records for this registration block. Bound
    # each callback by the next original callback/helper entry and inspect its
    # final instruction directly in the complete disassembly.
    stops=set(addresses)|{0x0053b150,0x0053b530,0x0053b8d0}
    result={}
    for address in sorted(addresses):
        following=next((x for x in sorted(stops) if x>address),None)
        if following is None:raise RuntimeError(f'no end boundary for {address:08x}')
        body=[entry for entry in asm_lines if address<=entry[0]<following]
        if not body or body[-1][2]!='RET 0x18':
            raise RuntimeError(f'{address:08x} does not end at its next original boundary with RET 0x18: {body[-1:]!r}')
        end=body[-1][0]+len(body[-1][1])//2
        result[f'{address:08x}']={'range':[f'{address:08x}',f'{end:08x}'],
            'abi':'stdcall six arguments; RET 18','native_decl':'WindowHandler',
            'evidence':'final instruction before next bounded original entry'}
    return result

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/run064-window-callback-bindings/bin/Release/window_callback_bindings_probe.exe')
    ap.add_argument('--report',type=Path,default=RUN/'verification.json');args=ap.parse_args()
    binary=ROOT/'local/game/Porsche.exe'
    if hashlib.sha256(binary.read_bytes()).hexdigest()!=SHA:raise SystemExit('immutable original SHA mismatch')
    rows=original_registrations()
    if len(rows)!=27:raise SystemExit(f'expected 27 original registrations, found {len(rows)}')
    if source_registrations()!=rows:raise SystemExit('window_init source registration table differs from original ASM')
    pairs=[value for row in rows for value in row]
    run=subprocess.run([str(args.probe)],input=str(len(rows))+'\n'+'\n'.join(map(str,pairs))+'\n',
        text=True,capture_output=True,check=True)
    parsed=[line.split() for line in run.stdout.splitlines()]
    head=next(x for x in parsed if x[0]=='R')
    if head!=['R','1','0','27']:raise SystemExit(f'relocation table failed: {head}')
    entries=[x for x in parsed if x[0]=='E'];maps=[x for x in parsed if x[0]=='M']
    count=int(next(x[1] for x in parsed if x[0]=='B'))
    if len(entries)!=27 or count!=16 or len(maps)!=16:raise SystemExit('callback mapping counts do not match expected 27/16')
    actual=[(int(x[1]),int(x[2]),int(x[3])) for x in entries]
    by_va={int(x[1]):int(x[2]) for x in maps}
    if len(by_va)!=16 or len(set(by_va.values()))!=16 or 0 in by_va.values():
        raise SystemExit('native callback pointers are null, duplicated, or missing')
    for i,(message,guest) in enumerate(rows):
        emsg,eva,native=actual[i]
        if (emsg,eva)!=(message,guest):raise SystemExit(f'row {i} changed: {actual[i]} vs {(message,guest)}')
        if guest not in by_va or native!=by_va[guest]:raise SystemExit(f'unresolved or inconsistent callback {guest:08x}')
        if native==guest:raise SystemExit(f'raw guest VA retained as callable pointer: {guest:08x}')
    unique={va for _,va in rows}
    if set(by_va)!=unique:raise SystemExit('relocation registry differs from the 16 unique original callbacks')
    if any(x[0]=='U' and x[1]!='0' for x in parsed):raise SystemExit('unknown VA did not return unresolved/null')
    test=next(x for x in parsed if x[0]=='T')
    if test!=['T','0',str(0x53ffff),'1','0','0']:raise SystemExit(f'unknown/capacity handling failed: {test}')
    abis=function_abis(unique)
    report={'source_binary':'local/game/Porsche.exe','sha256':SHA,
      'original_registration_consumer':'0053ac20 / 0053ad35..0053aecf',
      'registration_count':len(rows),'unique_callback_count':len(unique),
      'registrations':[{'message':f'0x{m:04x}','original_va':f'{va:08x}',
        'native_pointer':f'{ptr:08x}'} for (m,va),(_,_,ptr) in zip(rows,actual)],
      'full_function_abis':abis,'unresolved_callback_vas':[],
      'unknown_va_test':'0x0053ffff resolves to nullptr; failed table conversion writes no output entries',
      'source_window_init_matches_original_asm':True,'result':'pass'}
    prod=ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_callback_bindings.cpp'
    header=ROOT/'iterations/v2/001-original-recovery/source/include/porsche/window_callback_bindings.hpp'
    report['production_source_sha256']=hashlib.sha256(prod.read_bytes()).hexdigest()
    report['header_sha256']=hashlib.sha256(header.read_bytes()).hexdigest()
    report['probe_sha256']=hashlib.sha256(args.probe.resolve().read_bytes()).hexdigest()
    report['schema']=1
    report['source_sha256']=source_hashes(['scripts/research/verify-v2-window-callback-bindings.py','iterations/v2/001-original-recovery/runs/064-window-callback-bindings/CMakeLists.txt'],compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_callback_bindings.cpp','iterations/v2/001-original-recovery/source/recovered/window_callback_bindings_probe.cpp'])
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(report,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'registrations':len(rows),'unique_callbacks':len(unique),'unresolved':0,'result':'pass'},indent=2))
if __name__=='__main__':main()
