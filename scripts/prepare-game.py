"""Copy the installed game once; verify every byte via SHA-256. Stdlib only."""
import argparse
import hashlib
import json
import shutil
from pathlib import Path


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--source', type=Path, required=True)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    source = args.source.resolve(strict=True)
    target = root / 'local' / 'game'
    target.parent.mkdir(parents=True, exist_ok=True)
    if target.exists():
        raise SystemExit('Destination exists; refusing to overwrite the baseline.')
    if source == target or source in target.parents or target in source.parents:
        raise SystemExit('Source and destination must be separate trees.')
    files = sorted(source.rglob('*'))
    if any(path.is_symlink() or path.is_junction() for path in files):
        raise SystemExit('Links/junctions in source are not supported.')
    shutil.copytree(source, target)
    manifest = []
    for path in files:
        if not path.is_file():
            continue
        relative = path.relative_to(source)
        copy = target / relative
        sha256 = digest(path)
        if copy.stat().st_size != path.stat().st_size or digest(copy) != sha256:
            raise SystemExit(f'Copy verification failed: {relative}')
        manifest.append({'path': relative.as_posix(), 'size': path.stat().st_size,
                         'sha256': sha256})
    report = root / 'docs' / 'game-manifest.json'
    report.write_text(json.dumps({'source': str(source), 'files': manifest},
                                ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(f'Verified {len(manifest)} files, {sum(x["size"] for x in manifest)} bytes')


if __name__ == '__main__':
    main()
