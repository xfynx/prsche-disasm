"""Create a standalone source snapshot; never overwrite an iteration."""
import argparse
import re
import shutil
from pathlib import Path

SKIP = {'target', '__pycache__', '.git', 'local', '.venv', 'node_modules', 'runs'}


def create_iteration(root, source_name, name):
    if not re.fullmatch(r'\d{3}-[a-z0-9]+(?:-[a-z0-9]+)*', name):
        raise ValueError('Name must be NNN-lowercase-name')
    base = (root / 'iterations').resolve()
    source = (base / source_name).resolve(strict=True)
    if source.parent != base or not source.is_dir():
        raise ValueError('Source must be an iteration directory')
    destination = base / name
    if destination.exists():
        raise FileExistsError(f'Refusing to overwrite {destination}')
    if int(name[:3]) <= int(source.name[:3]):
        raise ValueError('New iteration number must exceed parent number')
    if any(p.is_symlink() or p.is_junction() for p in source.rglob('*')):
        raise ValueError('Iteration must not contain filesystem links')
    shutil.copytree(source, destination,
                    ignore=lambda folder, names: [n for n in names if n in SKIP or n.endswith('.pyc')])
    (destination / 'README.md').write_text(
        f'# {name}\n\nСтатус: в работе.\n\nПолный снимок `{source.name}`.\n'
        f'Планируемый тег: `iteration-{name[:3]}`.\n\n'
        'Цель, команды и критерии готовности необходимо актуализировать перед работой.\n',
        encoding='utf-8')
    runs_dir = destination / 'runs'
    runs_dir.mkdir(exist_ok=True)
    (runs_dir / 'README.md').write_text(
        '# Viewer runs\n\n'
        'Здесь хранятся воспроизводимые визуальные запуски текущей итерации. '
        'Предыдущие запуски остаются в своих завершённых снимках.\n\n'
        'Каждый запуск получает отдельную папку `NNN-краткое-описание/` с `README.md` и снимками.\n',
        encoding='utf-8')
    print(destination)
    return destination


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--from', dest='source', required=True)
    parser.add_argument('--name', required=True)
    args = parser.parse_args()
    create_iteration(Path(__file__).resolve().parents[1], args.source, args.name)


if __name__ == '__main__':
    main()
