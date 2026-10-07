"""Record indexed startup callsites and unresolved dependencies without guessing types."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ITERATION = ROOT / 'iterations/v2/001-original-recovery'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'


def main():
    index = ROOT / f'research/binary-index/ghidra/Porsche.exe-{SHA[:12]}'
    functions = {r['entry_va']: r for r in map(json.loads, (index/'functions.jsonl')
                 .read_text(encoding='utf8').splitlines())}
    calls = list(map(json.loads, (index/'calls.jsonl').read_text(encoding='utf8').splitlines()))
    recovered = {r['entry_va']: r for r in json.loads(
        (ITERATION/'source/recovered/functions.json').read_text(encoding='utf8'))['functions']
        if r['sha256'] == SHA}
    roots = {'005a2d1a': 'PE/CRT entry', '004b6710': 'WinMain argument dispatch',
             '004b6a50': 'application startup and main control loop',
             '004b6660': 'FE_Data_Stream: fe.txt plus command-line inputs'}
    stages = []
    for entry, role in roots.items():
        outgoing = [r for r in calls if r.get('from_function') == entry]
        stages.append({'entry_va': entry, 'role': role, 'ranges': functions[entry]['ranges'],
                       'incoming': [r for r in calls if r.get('to_function') == entry],
                       'outgoing': outgoing,
                       'dependencies': sorted({r['to_function'] for r in outgoing if r.get('to_function')}),
                       'recovery': {k: recovered[entry][k] for k in ('status', 'source', 'verification_report')}
                                   if entry in recovered else {'status': 'unrecovered'}})
    # Direct/static discovery only: indirect targets and undecoded code remain.
    reached, pending = set(), ['005a2d1a']
    graph = {}
    for call in calls:
        graph.setdefault(call.get('from_function'), set()).add(call.get('to_function'))
    while pending:
        entry = pending.pop()
        if entry in reached or entry not in functions:
            continue
        reached.add(entry)
        pending.extend(t for t in graph.get(entry, ()) if t in functions and t not in reached)
    report = {'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
              'query': 'entry 0x5a2d1a -> 0x4b6710 -> 0x4b6a50 -> 0x4b6660, indexed callers/callees',
              'index': str(index.relative_to(ROOT)).replace('\\', '/'),
              'stages': stages, 'statically_reachable_functions': len(reached),
              'total_analyzed_functions': len(functions), 'reachable_entries': sorted(reached),
              'complete_reachability': False,
              'next_bundle': ['0059e040', '00533de0', '00533bf0', '00533da0',
                              '00533c20', '00568b90', '00568ae0', '00568b10'],
              'next_proof': 'Trace grouped file handles, completion/status callbacks and disk/archive backends; recover FE open/read/size/close services, then verify FE with original heap and IO together.',
              'unrecovered': ['CRT initialization/termination', 'app_main 004b6a50',
                              'heap OS/CRT/optimized-copy callees and startup binding',
                              'FE file/locale services and callback effects', 'render/audio/input initialization',
                              'main-loop global state and indirect calls']}
    target = ITERATION / 'reference/startup.json'
    target.write_text(json.dumps(report, indent=2) + '\n', encoding='utf8', newline='\n')
    print(json.dumps({'stages': len(stages), 'statically_reachable_functions': len(reached),
                      'complete_reachability': False}))


if __name__ == '__main__':
    main()
