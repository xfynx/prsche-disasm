"""Generate the common-build proof from the actual ALL_BUILD MSBuild graph."""
import argparse
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
sys.path.insert(0, str(ROOT / 'scripts/research'))
from v2_build_graph import cmake_inputs, compiled_sources, projects
from v2_source_dependencies import source_hashes

ITERATION = ROOT / 'iterations/v2/001-original-recovery'
RUN = ITERATION / 'runs/098-startup-integration'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build-root', type=Path, required=True,
                        help='Common CMake build directory containing ALL_BUILD.vcxproj')
    parser.add_argument('--exit-code', type=int, required=True,
                        help='Exit code from the completed common build command')
    parser.add_argument('--parallel-jobs', type=int, default=4)
    parser.add_argument('--command', required=True,
                        help='Exact reproducible common-build command')
    parser.add_argument('--log', type=Path,
                        help='Optional captured build log to pin in the report')
    parser.add_argument('--output', type=Path, default=RUN/'compile-link-proof.json')
    args = parser.parse_args()

    build_root = (args.build_root if args.build_root.is_absolute()
                  else ROOT / args.build_root).resolve()
    output = (args.output if args.output.is_absolute() else ROOT / args.output).resolve()
    graph_projects = projects(build_root, 'ALL_BUILD')
    sources = compiled_sources(build_root, 'ALL_BUILD')
    if not graph_projects or not sources:
        raise RuntimeError('ALL_BUILD graph produced no projects or compiled sources')
    if args.exit_code != 0:
        raise RuntimeError(f'common build exit code is {args.exit_code}; refusing a success proof')

    command_inputs = [
        ROOT/'scripts/build-v2.ps1',
        ROOT/'scripts/research/v2_build_graph.py',
        ROOT/'scripts/research/v2_source_dependencies.py',
        ROOT/'iterations/v2/001-original-recovery/runs/098-startup-integration/generate_compile_link_proof.py',
        *(ROOT/path for path in cmake_inputs()),
    ]
    hashes = source_hashes(command_inputs, compiled_sources=sources)
    report = {
        'schema': 1,
        'kind': 'common MSVC Win32 compile and link proof, not complete game or runtime equivalence',
        'architecture': 'x86/Win32',
        'command': args.command,
        'build_target': 'ALL_BUILD',
        'parallel_jobs': args.parallel_jobs,
        'exit_code': args.exit_code,
        'build_root': build_root.relative_to(ROOT).as_posix(),
        'graph_entry': 'ALL_BUILD.vcxproj',
        'graph_project_count': len(graph_projects),
        'compiled_source_count': len(sources),
        'source_sha256': hashes,
        'source_hash_rule': 'SHA-256; source bytes normalize CRLF to LF; quoted include closure is pinned',
    }
    if args.log:
        log = args.log if args.log.is_absolute() else ROOT / args.log
        report['build_log'] = (log.resolve().relative_to(ROOT).as_posix()
                               if log.resolve().is_relative_to(ROOT) else str(log.resolve()))
        report['build_log_sha256'] = hashlib.sha256(log.read_bytes()).hexdigest()
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps({'build_target': 'ALL_BUILD', 'projects': len(graph_projects),
                      'compiled_source_count': len(sources),
                      'source_sha256_count': len(hashes), 'exit_code': args.exit_code,
                      'report': output.relative_to(ROOT).as_posix()
                      if output.is_relative_to(ROOT) else str(output)}))


if __name__ == '__main__':
    main()
