#!/usr/bin/env python3
"""List production global definitions whose symbol suffix encodes one VA."""
import collections
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "iterations/v2/001-original-recovery/source"
VA_NAME = re.compile(r"\b([A-Za-z_]\w*?_(0[0-9a-fA-F]{7}))\b\s*(?P<array>\[[^\]\n]*\])?\s*(?:\{\s*\})?\s*(?==|;|,)")


def scrub(line):
    line = re.sub(r"//.*", "", line)
    return re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', '""', line)


def scan():
    groups = collections.defaultdict(list)
    for path in sorted(SOURCE.rglob("*")):
        if path.suffix not in (".cpp", ".inc") or "probe" in path.name.lower():
            continue
        stack = []
        for number, raw in enumerate(path.read_text(encoding="utf-8-sig").splitlines(), 1):
            line = scrub(raw)
            if all(scope == "namespace" for scope in stack):
                # Split simple comma-separated declarators so names in an
                # initializer (e.g. a reference target) are not mistaken for
                # another definition on the left-hand side.
                base_type = None
                for index, segment in enumerate(line.split(",")):
                    lhs = segment.split("=", 1)[0]
                    matches = list(VA_NAME.finditer(lhs + (";" if ";" not in lhs else "")))
                    if not matches:
                        continue
                    declaration = lhs[:matches[0].start()] if index == 0 else (base_type or "")
                    if index == 0:
                        base_type = declaration
                    if "(" in declaration or ")" in declaration or re.match(r"^\s*extern\b", declaration):
                        continue
                    kind = "reference" if "&" in declaration else "owner"
                    value_type = declaration.strip()
                    for match in matches:
                        name, va = match.group(1), match.group(2).lower()
                        groups[va].append({
                            "name": name,
                            "kind": kind,
                            "declaration": value_type + (match.group("array") or ""),
                            "file": path.relative_to(ROOT).as_posix(),
                            "line": number,
                        })
            for position, char in enumerate(line):
                if char == "{":
                    before = line[:position]
                    namespace = re.search(r"\bnamespace(?:\s+[A-Za-z_]\w*)?\s*$", before)
                    stack.append("namespace" if namespace else "block")
                elif char == "}" and stack:
                    stack.pop()
    return groups


def main():
    output = []
    for va, symbols in sorted(scan().items()):
        names = {symbol["name"] for symbol in symbols}
        if len(names) < 2:
            continue
        output.append({"original_va": "0x" + va, "symbols": symbols})
    print(json.dumps(output, indent=2))


if __name__ == "__main__":
    main()
