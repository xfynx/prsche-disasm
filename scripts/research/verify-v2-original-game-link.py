"""Run and classify the real Run102 Win32 game-image link attempt."""
import argparse
import hashlib
import json
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/102-original-game-link'
TARGET = 'porsche_original_game_link'
DEFAULT_BUILD = ROOT / 'local/builds/v2/original-game-link-102'
DEFAULT_LOG = ROOT / 'local/reports/v2-original-game-link-102-msbuild.log'

from v2_source_dependencies import source_hashes
from v2_build_graph import compiled_sources


def source_closure(build_dir):
    iteration = ROOT / 'iterations/v2/001-original-recovery'
    source = iteration / 'source'
    recovered = source / 'recovered'
    # The excluded game target is absent from ALL_BUILD. Find its explicit
    # project, then follow only that target's actual ProjectReference graph.
    entries = list(Path(build_dir).resolve().rglob(TARGET + '.vcxproj'))
    if len(entries) != 1:
        raise RuntimeError(f'Ambiguous/missing game-link project: {entries}')
    compiled = [ROOT / p for p in compiled_sources(entries[0].parent, TARGET)]
    if RUN / 'host-entry.cpp' not in compiled:
        raise RuntimeError('Actual game-link graph omits the canonical host entry')
    dependencies = [
        ROOT / 'iterations/v2/001-original-recovery/CMakeLists.txt',
        recovered / 'sources.cmake',
        RUN / 'CMakeLists.txt',
        ROOT / 'iterations/v2/001-original-recovery/runs/055-native-platform/CMakeLists.txt',
        ROOT / 'iterations/v2/001-original-recovery/runs/057-native-thread-chain/CMakeLists.txt',
        ROOT / 'iterations/v2/001-original-recovery/runs/070-native-window-bindings/CMakeLists.txt',
        ROOT / 'iterations/v2/001-original-recovery/runs/075-recovered-links/CMakeLists.txt',
        ROOT / 'scripts/research/v2_source_dependencies.py',
        ROOT / 'scripts/research/v2_build_graph.py',
        ROOT / 'scripts/research/verify-v2-original-game-link.py',
        RUN / 'README.md',
    ]
    return source_hashes(dependencies, compiled_sources=compiled), compiled


def classify(symbol):
    value = symbol.strip().strip('"')
    upper = value.upper()
    if value.startswith('__imp_') or value.startswith('_imp__'):
        return 'windows_or_external_import'
    if any(token in upper for token in (
        '__CXX', '__SECURITY', '_EXCEPT_HANDLER', '__STD_', 'MSVCP', 'VCRUNTIME', 'UCRTBASE')):
        return 'msvc_or_c_runtime'
    if value.startswith('?'):
        decorated_name = value[1:].split('@', 1)[0]
        if re.search(r'_0[0-9a-fA-F]{7}$', decorated_name):
            return 'va_named_original_callable'
        return 'semantic_service_or_vtable_boundary'
    return 'recovered_or_platform_c_callable'


def parse_diagnostics(log):
    unresolved = []
    linker = []
    linker_summaries = []
    compiler = []
    for line in log.splitlines():
        if re.search(r'error LNK1120:', line):
            # LNK1120 repeats the unresolved-symbol total after LNK2001/2019;
            # keep it as evidence without counting it as an unrelated error.
            linker_summaries.append(line.strip())
            continue
        match = re.search(r'error LNK(2001|2019):', line)
        if match:
            code = match.group(1)
            english = re.search(
                r'unresolved external symbol\s+(.+?)(?:,\s*referenced in function\s+(.+?))?\s*$',
                line, re.IGNORECASE)
            if english:
                symbol = english.group(1).strip()
                caller = english.group(2)
            else:
                # The active MSVC locale localizes the diagnostic text. The
                # quoted decorated names remain locale independent.
                decorated = re.findall(r'\((\?[^()]+)\)', line)
                symbol = decorated[0] if decorated else None
                caller = decorated[1] if len(decorated) > 1 else None
            if not symbol:
                linker.append(line.strip())
                continue
            prefix = line.split(': error LNK', 1)[0].strip() if ': error LNK' in line else ''
            unresolved.append({
                'code': 'LNK' + code,
                'symbol': symbol.strip().strip('"'),
                'category': classify(symbol),
                'referencing_object': prefix,
                'referenced_in_function': caller.strip().strip('"') if caller else None,
            })
        elif re.search(r'\berror LNK\d+:', line):
            linker.append(line.strip())
        elif re.search(r'\berror C\d+:', line):
            compiler.append(line.strip())
    grouped = {}
    for item in unresolved:
        entry = grouped.setdefault(item['symbol'], {
            'symbol': item['symbol'],
            'category': item['category'],
            'references': [],
        })
        reference = {
            'code': item['code'],
            'object': item['referencing_object'],
            'caller': item['referenced_in_function'],
        }
        if reference not in entry['references']:
            entry['references'].append(reference)
    return list(grouped.values()), linker, linker_summaries, compiler


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--build-dir', type=Path, default=DEFAULT_BUILD)
    parser.add_argument('--report', type=Path, default=RUN / 'link-report.json')
    parser.add_argument('--log', type=Path, default=DEFAULT_LOG)
    args = parser.parse_args()

    command = ['cmake', '--build', str(args.build_dir), '--target', TARGET,
               '--config', 'Release']
    result = subprocess.run(command, cwd=ROOT, text=True,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                            check=False)
    log = result.stdout or ''
    args.log.parent.mkdir(parents=True, exist_ok=True)
    args.log.write_text(log, encoding='utf-8')
    unresolved, linker_diagnostics, linker_summaries, compiler_errors = parse_diagnostics(log)
    reported_match = re.search(r'error LNK1120:.*?:\s*(\d+)\s*\[', log)
    reported_unresolved_count = int(reported_match.group(1)) if reported_match else None
    category_counts = {}
    family_counts = {}
    caller_counts = {}
    for item in unresolved:
        category_counts[item['category']] = category_counts.get(item['category'], 0) + 1
        prefix_match = re.match(r'\?([^@]+)@porsche@@', item['symbol'])
        family = (prefix_match.group(1).split('_', 1)[0] if prefix_match else 'other')
        family_counts[family] = family_counts.get(family, 0) + 1
        for ref in item['references']:
            caller = ref['caller'] or '<no caller in LNK diagnostic>'
            caller_counts[caller] = caller_counts.get(caller, 0) + 1
    binary = args.build_dir / 'bin/Release/porsche_original_game_link.exe'
    if result.returncode == 0 and binary.is_file():
        status = 'linked_unexecuted'
    elif unresolved:
        status = 'link_failed_unresolved_frontier'
    elif compiler_errors:
        status = 'compile_failed_before_link'
    elif linker_diagnostics:
        status = 'link_failed_other'
    else:
        status = 'build_failed_before_link_or_target_missing'

    hashes, compiled = source_closure(args.build_dir)
    report = {
        'schema': 1,
        'target': TARGET,
        'status': status,
        'game_executable_executed': False,
        'build_command': command,
        'build_exit_code': result.returncode,
        'entry_chain': [
            'WinMain@16 (Win32 host entry)',
            'porsche::win_main_004b6710 (stdcall, original recovered body)',
            'porsche::app_main_004b6a50 (cdecl, original recovered body)',
        ],
        'linked_common_targets': [
            'porsche_original', 'porsche_recovered_links', 'porsche_window_links',
            'win32_window_bindings', 'porsche_platform_win32',
        ],
        'compiled_source_count': len(compiled),
        'unresolved_frontier': unresolved,
        'unresolved_symbol_count': len(unresolved),
        'unresolved_reference_count': sum(len(item['references']) for item in unresolved),
        'linker_reported_unresolved_count': reported_unresolved_count,
        'unresolved_counts_by_category': category_counts,
        'unresolved_counts_by_symbol_family': family_counts,
        'reachable_caller_counts': caller_counts,
        'other_linker_diagnostics': linker_diagnostics,
        'linker_summary_diagnostics': linker_summaries,
        'compiler_errors': compiler_errors,
        'linker_diagnostic_count': sum(len(item['references']) for item in unresolved) + len(linker_diagnostics),
        'raw_log': args.log.relative_to(ROOT).as_posix() if args.log.is_relative_to(ROOT) else str(args.log),
        'raw_log_sha256': hashlib.sha256(args.log.read_bytes()).hexdigest(),
        'linked_binary': binary.relative_to(ROOT).as_posix() if binary.is_relative_to(ROOT) and binary.exists() else None,
        'source_sha256': hashes,
        'game_playability_verified': False,
    }
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({
        'status': status,
        'linker_unresolved_symbols': len(unresolved),
        'linker_unresolved_references': sum(len(item['references']) for item in unresolved),
        'other_linker_diagnostics': len(linker_diagnostics),
        'linker_summary_diagnostics': len(linker_summaries),
        'compiler_errors': len(compiler_errors),
        'report': str(args.report),
        'raw_log': str(args.log),
    }))


if __name__ == '__main__':
    main()
