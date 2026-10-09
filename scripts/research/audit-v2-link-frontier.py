"""Inventory unresolved COFF names without supplying fake game implementations."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[2]
ITER = ROOT / 'iterations/v2/001-original-recovery'


def symbols(path, dumpbin):
    output = subprocess.run([dumpbin, '/symbols', str(path)], capture_output=True,
                            check=True).stdout.decode('utf-8', errors='replace')
    defined, referenced, labels = Counter(), set(), {}
    for line in output.splitlines():
        if 'External' not in line or ' | ' not in line:
            continue
        prefix, tail = line.split(' | ', 1)
        symbol, _, label = tail.partition(' (')
        labels[symbol] = label.removesuffix(')')
        if 'UNDEF' in prefix:
            referenced.add(symbol)
        else:
            defined[symbol] += 1
    if not defined:
        raise RuntimeError(f'No COFF definitions parsed: {path}')
    return defined, referenced, labels


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    dumpbin = shutil.which('dumpbin')
    if not dumpbin:
        raise RuntimeError('Dot-source scripts/tool-env.ps1 before this command')
    paths = [ROOT / 'local/builds/v2/001-original-recovery/Release/porsche_original.lib',
             ROOT / 'local/builds/v2/001-original-recovery/native-thread/platform/Release/porsche_platform_win32.lib']
    definitions, references, labels = Counter(), set(), {}
    inputs = []
    for path in paths:
        defined, referenced, names = symbols(path, dumpbin)
        definitions.update(defined)
        references.update(referenced)
        labels.update(names)
        inputs.append({'path': path.relative_to(ROOT).as_posix(),
                       'sha256': hashlib.sha256(path.read_bytes()).hexdigest()})
    registry = json.loads((ITER / 'source/recovered/functions.json').read_text())
    known = {f['entry_va']: f['status'] for f in registry['functions']}
    rows = []
    for symbol in sorted(references - definitions.keys()):
        match = re.search(r'_([0-9a-f]{8})@', symbol)
        va = match.group(1) if match else None
        label = labels[symbol]
        if '@porsche@@' not in symbol:
            kind = 'compiler-or-system-link-dependency'
        elif '(' not in label:
            kind = 'unbound-data'
        elif va in known:
            kind = 'known-original-address-needs-adapter-review'
        elif va:
            kind = 'addressed-consumer-not-in-recovered-registry'
        else:
            kind = 'named-platform-or-service-boundary'
        rows.append({'symbol': symbol, 'declaration': label, 'original_va': va,
                     'category': kind})
    duplicates = {s: n for s, n in definitions.items()
                  if n > 1 and '@porsche@@' in s}
    result = {'schema': 1, 'kind': 'COFF link frontier, not a game link attempt',
              'inputs': inputs, 'defined_symbols': len(definitions),
              'undefined_symbols': len(rows), 'duplicate_project_definitions': duplicates,
              'categories': dict(Counter(r['category'] for r in rows)), 'undefined': rows,
              'limitations': ['A shared original VA does not prove ABI-compatible adapters.',
                              'Platform/CRT import libraries are not resolved by this inventory.',
                              'Unresolved names are not a count of missing original algorithms.']}
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({k: result[k] for k in
                      ('defined_symbols', 'undefined_symbols', 'categories', 'duplicate_project_definitions')}))
    if duplicates:
        raise SystemExit('Review duplicate project definitions before a joint link')


if __name__ == '__main__':
    main()
