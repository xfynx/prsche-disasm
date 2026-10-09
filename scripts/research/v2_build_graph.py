"""Read the actual MSBuild target graph; unrelated standalone builds are excluded."""
from pathlib import Path
import re
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[2]
ITERATION = ROOT / 'iterations/v2/001-original-recovery'

def projects(build_root, target='ALL_BUILD'):
    entry = Path(build_root).resolve() / (target + '.vcxproj')
    if not entry.is_file():
        candidates = list(Path(build_root).resolve().rglob(target + '.vcxproj'))
        if len(candidates) != 1:
            raise RuntimeError(f'Ambiguous/missing MSBuild entry: {target}: {candidates}')
        entry = candidates[0]
    visited = set()
    def walk(path):
        path = path.resolve()
        if path in visited:
            return
        visited.add(path)
        for element in ET.parse(path).iter():
            if element.tag.endswith('}ProjectReference') and element.get('Include'):
                walk(path.parent / element.get('Include'))
    walk(entry)
    return sorted(visited)

def compiled_sources(build_root, target='ALL_BUILD'):
    result = set()
    for project in projects(build_root, target):
        for element in ET.parse(project).iter():
            if element.tag.endswith('}ClCompile') and element.get('Include'):
                path = Path(element.get('Include')).resolve()
                if path.is_file() and path.is_relative_to(ITERATION):
                    result.add(path.relative_to(ROOT).as_posix())
    return sorted(result)

def cmake_inputs():
    main = ITERATION / 'CMakeLists.txt'
    result = {main, ITERATION / 'source/recovered/sources.cmake'}
    for subdirectory in re.findall(r'add_subdirectory\(\s*([^\s)]+)', main.read_text(encoding='utf8')):
        path = ITERATION / subdirectory / 'CMakeLists.txt'
        if not path.is_file():
            raise RuntimeError(f'Missing common-build CMake input: {path}')
        result.add(path)
    return sorted(path.relative_to(ROOT).as_posix() for path in result)
