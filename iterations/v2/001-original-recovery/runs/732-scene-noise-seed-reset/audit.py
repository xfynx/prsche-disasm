"""Run732 immutable native-input, original-range, REA, and COFF ownership audit."""
from pathlib import Path
import hashlib
import json
import subprocess

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent


def sha(p: Path) -> str:
    return hashlib.sha256(p.read_bytes()).hexdigest()


def rel(p: Path) -> str:
    return p.relative_to(ROOT).as_posix()


def main() -> None:
    receipt = ROOT / 'local/experiments/v2-scene-noise-seed-reset-732/003/receipt.json'
    proof = json.loads(receipt.read_text(encoding='utf-8'))
    assert proof['status'] == 'PASS'
    for key in ('inputs_sha256', 'outputs_sha256'):
        for p, h in proof[key].items():
            assert sha(ROOT / p) == h, (key, p)

    rea_receipt = ROOT / 'local/experiments/v2-scene-noise-seed-reset-732/rea/001/receipt.json'
    rea_validation = RUN / 'rea/validation.json'
    rea_val = json.loads(rea_validation.read_text(encoding='utf-8'))
    assert rea_val['passed'] is True
    assert rea_val['receipt_sha256'] == sha(rea_receipt)

    index_path = ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl'
    index = {
        x['entry_va']: x
        for x in map(json.loads, index_path.read_text(encoding='utf-8').splitlines())
    }
    registry = json.loads(
        (ROOT / 'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text(
            encoding='utf-8'
        )
    )['functions']
    new_ranges = [(0x0044F240, 0x0044F2ED), (0x00538110, 0x00538150)]
    overlaps = []
    for item in registry:
        if item['module'] != 'Porsche.exe':
            continue
        ranges = item.get(
            'body_ranges',
            index.get(item['entry_va'], {}).get('ranges', [[item['entry_va'], item['entry_va']]]),
        )
        for a, b in ranges:
            if any(int(a, 16) <= d and c <= int(b, 16) for c, d in new_ranges):
                overlaps.append(item['entry_va'])
    assert not overlaps, overlaps

    dump = ROOT / 'local/tools/BuildTools/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x86/dumpbin.exe'
    coff_dir = receipt.parent.parent / 'coff-003'
    coff_dir.mkdir(parents=True, exist_ok=True)
    coff = {}
    for name in ('od-1', 'o2-1'):
        for flag, suffix in (('/DISASM', 'disasm'), ('/HEADERS', 'headers')):
            p = coff_dir / f'{name}-{suffix}.txt'
            if not p.exists():
                p.write_bytes(
                    subprocess.check_output([str(dump), flag, str(receipt.parent / f'{name}.obj')])
                )
            coff[rel(p)] = sha(p)

    listing = ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    lines = []
    for line in listing.read_text(encoding='utf-8', errors='replace').splitlines():
        try:
            va = int(line.split(' ')[0], 16)
        except ValueError:
            continue
        if any(a <= va <= b for a, b in new_ranges):
            lines.append(line)
    out_asm = RUN / 'original-listing.asm'
    out_asm.write_text('\n'.join(lines) + '\n', encoding='utf-8', newline='\n')
    assert lines and lines[0].startswith('0044f240') and lines[-1].startswith('00538150')

    rea_dossiers = {
        rel(rea_receipt.parent / name): sha(rea_receipt.parent / name)
        for name in (
            'function-0044f240.json',
            'function-00538110.json',
            'function-0044f2f0.json',
            'receipt.json',
        )
    }

    data = dict(
        run=732,
        status='PASS',
        receipt=rel(receipt),
        receipt_sha256=sha(receipt),
        rea_validation=rel(rea_validation),
        rea_validation_sha256=sha(rea_validation),
        rea_dossier_pins=rea_dossiers,
        cases_per_optimization=68,
        material_controls=10,
        body_bytes=239,
        body_overlap=overlaps,
        newly_owned_rdata_bytes=4,
        newly_owned_data_bytes=4,
        newly_owned_bss_bytes=9260,
        true_frontier=[],
        source_pins={
            p: h
            for p, h in proof['inputs_sha256'].items()
            if '/runs/' in p and not p.startswith('local/')
        },
        coff_pins=coff,
        original_listing_sha256=sha(out_asm),
        boundary=(
            'Exact x86/x87 differential equivalence for 0044f240 (174B) and 00538110 (65B) '
            'composed with canonical Run638 00538040 (193B) and Run511 005b23f0 across 68 '
            'cases per optimization (/Od and /O2, 136 measured comparisons) and 10 material '
            'mutations. Lattice noise evaluator 0044f2f0 and outer 00538110 callers '
            '(00428940, 004e3160, 004f7db0) remain separate unrecovered functions.'
        ),
    )
    (RUN / 'evidence.json').write_text(
        json.dumps(data, indent=2) + '\n', encoding='utf-8', newline='\n'
    )
    print('Run732 provenance/ownership/REA/COFF audit PASS')


if __name__ == '__main__':
    main()
