#!/usr/bin/env python3
"""Build a deterministic, address-level catalog of the v2 recovery corpus.

The catalog is navigation metadata only.  Decompiler output remains in the
research corpus; --extract copies one cited pseudo-C function for inspection.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
REFERENCE = ROOT / "iterations/v2/001-original-recovery/reference/binaries.json"
CORPUS = ROOT / "research/v2/binaries"
STATIC = ROOT / "research/binary-index/static"
CATALOG = ROOT / "iterations/v2/001-original-recovery/source/catalog"
RECOVERED = ROOT / "iterations/v2/001-original-recovery/source/recovered/functions.json"


def read_json(path: Path):
    with path.open(encoding="utf-8") as stream:
        return json.load(stream)


def read_jsonl(path: Path):
    with path.open(encoding="utf-8") as stream:
        return [json.loads(line) for line in stream if line.strip()]


def fail(message: str) -> None:
    raise RuntimeError(message)


def va_int(value: str) -> int:
    if ":" in value:
        segment, offset = value.split(":", 1)
        return (int(segment, 16) << 4) + int(offset, 16)
    return int(value, 16)


def pseudo_spans(data: bytes) -> dict[str, tuple[int, int]]:
    markers = list(re.finditer(rb'/\* VA ([0-9a-fA-F:]+) \*/', data))
    spans = {}
    for i, marker in enumerate(markers):
        va = marker.group(1).decode().lower()
        if va in spans:
            fail(f"duplicate pseudo-C VA {va}")
        spans[va] = (marker.start(), markers[i+1].start() if i+1 < len(markers) else len(data))
    return spans


def load_sources_manifest() -> dict[tuple[str, str], str]:
    if not RECOVERED.exists():
        return {}
    raw = read_json(RECOVERED)
    entries = raw.get("functions", raw) if isinstance(raw, dict) else raw
    result = {}
    for entry in entries:
        if not isinstance(entry, dict):
            continue
        module = entry.get("module") or entry.get("module_path")
        address = entry.get("va") or entry.get("entry_va")
        status = entry.get("recovered_status") or entry.get("status")
        if module and address and status:
            result[(entry.get("sha256", module), address.lower())] = status
    return result


def load_static_index() -> tuple[dict[str, list], dict[str, list], dict[str, dict]]:
    imports = {}
    calls = {}
    binaries = {}
    for row in read_jsonl(STATIC / "imports.jsonl"):
        imports.setdefault(row.get("path"), []).append(row)
    for row in read_jsonl(STATIC / "calls.jsonl"):
        calls.setdefault(row.get("path"), []).append(row)
    for row in read_jsonl(STATIC / "binaries.jsonl"):
        binaries[row.get("path")] = row
    return imports, calls, binaries


def module_info(entry: dict, recovered: dict, index: tuple[dict, dict, dict]) -> tuple[dict, list[dict]]:
    imports, calls, binaries = index
    source_sha = entry["sha256"]
    module_path = entry["paths"][0]
    corpus = ROOT / entry["export_directory"]
    functions_path = corpus / "functions.jsonl"
    status_path = corpus / "decompile-status.jsonl"
    decompiled_path = corpus / "decompiled.c"
    if not functions_path.exists() or not status_path.exists():
        fail(f"missing corpus function/status file for {module_path}")
    functions = read_jsonl(functions_path)
    statuses = {row["entry_va"].lower(): row for row in read_jsonl(status_path)}
    if len(statuses) != len(read_jsonl(status_path)):
        fail(f"duplicate decompile status address in {module_path}")
    if len({row["entry_va"].lower() for row in functions}) != len(functions):
        fail(f"duplicate function address in {module_path}")
    if set(statuses) != {row["entry_va"].lower() for row in functions}:
        fail(f"function/status address mismatch in {module_path}")
    pseudo = decompiled_path.read_bytes() if decompiled_path.exists() else b""
    pseudo_by_va = pseudo_spans(pseudo)
    if set(pseudo_by_va) != {va for va, s in statuses.items() if s['status'] == 'automatic-pseudo-c'}:
        fail(f"pseudo-C/status coverage mismatch in {module_path}")
    records = []
    counts = {}
    for function in sorted(functions, key=lambda row: va_int(row["entry_va"])):
        address = function["entry_va"]
        status = statuses[address.lower()]
        span = pseudo_by_va.get(address.lower())
        warning = status.get("message", "")
        record = {
            "module": module_path,
            "source_sha256": source_sha,
            "va": address,
            "name": function["name"],
            "signature": function.get("signature", ""),
            "body_ranges": function.get("ranges", []),
            "body_bytes": function.get("body_bytes", 0),
            "pseudo_c": {"offset": span[0], "length": span[1] - span[0]} if span else None,
            "status": status.get("status", "unknown"),
            "warnings": [warning] if warning else [],
            "warning_count": len(re.findall(rb'/\* WARNING:|// WARNING:', pseudo[span[0]:span[1]])) if span else 0,
            "recovered_status": recovered.get((source_sha, address.lower()), "unrecovered"),
        }
        records.append(record)
        counts[record["status"]] = counts.get(record["status"], 0) + 1
    indexed_binary = binaries.get(module_path, {})
    summary = {
        "module": module_path,
        "source_sha256": source_sha,
        "format": entry.get("format"),
        "corpus": {
            "directory": entry["export_directory"],
            "functions": "functions.jsonl",
            "decompile_status": "decompile-status.jsonl",
            "decompiled_c": "decompiled.c",
            "asm": "disassembly.asm",
            "data": "defined-data.jsonl",
            "gaps": "unclassified-executable.jsonl",
        },
        "function_count": len(records),
        "pseudo_c_sha256": hashlib.sha256(pseudo).hexdigest(),
        "warning_functions": sum(bool(r["warning_count"]) for r in records),
        "status_counts": dict(sorted(counts.items())),
        "imports": indexed_binary.get("imports", imports.get(module_path, [])),
        "calls": {
            "path": f"research/binary-index/ghidra/{corpus.name}/calls.jsonl" if (ROOT/f"research/binary-index/ghidra/{corpus.name}/calls.jsonl").exists() else None,
            "count": (entry.get("original_analysis") or {}).get("calls"),
        },
        "calls_status": "missing (NE has no old static call index)" if entry.get("format") == "NE" else "indexed",
        "indexed_binary": {key: indexed_binary[key] for key in ("candidate_function_count", "call_count", "string_count", "resource_count") if key in indexed_binary},
        "gaps_summary": {
            "unclassified_executable_bytes": entry.get("listing", {}).get("unclassified_executable_bytes"),
            "decompile_failures": entry.get("automatic_decompilation", {}).get("failed"),
        },
    }
    return summary, records


def write_catalog() -> int:
    reference = read_json(REFERENCE)
    recovered = load_sources_manifest()
    index = load_static_index()
    summaries = []
    total = 0
    for entry in sorted(reference["binaries"], key=lambda row: row["paths"][0]):
        summary, records = module_info(entry, recovered, index)
        module_name = Path(summary["module"]).name
        directory = CATALOG / f"{module_name}-{summary['source_sha256'][:12]}"
        directory.mkdir(parents=True, exist_ok=True)
        with (directory / "functions.jsonl").open("w", encoding="utf-8", newline="\n") as stream:
            for record in records:
                stream.write(json.dumps(record, ensure_ascii=False, sort_keys=True, separators=(",", ":")) + "\n")
        summary["catalog"] = str((directory / "functions.jsonl").relative_to(ROOT)).replace("\\", "/")
        summaries.append(summary)
        total += len(records)
    if total != reference['counts']['analyzed_functions']:
        fail('catalog function count differs from inventory')
    if sum(s['warning_functions'] for s in summaries) != reference['counts']['pseudo_c_warning_functions']:
        fail('catalog warning count differs from inventory')
    with (CATALOG / "modules.json").open("w", encoding="utf-8", newline="\n") as stream:
        json.dump({"schema": 1, "modules": summaries, "function_count": total}, stream, ensure_ascii=False, sort_keys=True, indent=2)
        stream.write("\n")
    return len(summaries)


def extract(module: str, address: str, output: Path) -> None:
    reference = read_json(REFERENCE)
    matches = [row for row in reference['binaries'] if module.lower() in
               [Path(row['paths'][0]).name.lower()] + [p.lower() for p in row['paths']]]
    entry = matches[0] if len(matches) == 1 else None
    if not entry:
        fail(f"unknown module: {module}")
    corpus = ROOT / entry["export_directory"]
    records = read_jsonl(CATALOG / f"{Path(module).name}-{entry['sha256'][:12]}" / "functions.jsonl")
    matches = [row for row in records if va_int(row["va"]) == va_int(address)]
    if len(matches) != 1:
        fail(f"address is not unique in catalog: {module} {address}")
    record = matches[0]
    if not record["pseudo_c"]:
        fail(f"no pseudo-C span is available for {module} {address}")
    source = (corpus / "decompiled.c").read_bytes()
    summary = next(m for m in read_json(CATALOG/'modules.json')['modules'] if m['source_sha256'] == entry['sha256'])
    if hashlib.sha256(source).hexdigest() != summary['pseudo_c_sha256']:
        fail('stale pseudo-C offsets; regenerate catalog')
    if output.resolve().is_relative_to((ROOT/'local/game').resolve()):
        fail('local/game is read-only')
    binary_candidates = [ROOT / "local/game" / path for path in entry["paths"]]
    binary_candidates.extend(ROOT / "local/game" / Path(path).name for path in entry["paths"])
    binary = next((path for path in binary_candidates if path.exists()), None)
    if binary is None:
        fail(f"original binary is unavailable for SHA verification: {module}")
    actual_sha = hashlib.sha256(binary.read_bytes()).hexdigest()
    if actual_sha != entry["sha256"]:
        fail(f"source SHA mismatch for {module}: expected {entry['sha256']}, got {actual_sha}")
    span = record["pseudo_c"]
    output.parent.mkdir(parents=True, exist_ok=True)
    with output.open("wb") as stream:
        header = f"/* UNVALIDATED AUTOMATIC PSEUDO-C; not a build source. Original {module} SHA256 {entry['sha256']} VA {record['va']} */\n"
        stream.write(header.encode() + source[span["offset"] : span["offset"] + span["length"]])
    print(json.dumps({"module": module, "source_sha256": entry["sha256"], "va": address, "output": str(output), "validated": False}, sort_keys=True))


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--extract", metavar="MODULE")
    parser.add_argument("--address", help="entry VA for --extract")
    parser.add_argument("--output", type=Path, help="output file for --extract")
    args = parser.parse_args()
    try:
        if args.extract:
            if not args.address or not args.output:
                parser.error("--extract requires --address and --output")
            extract(args.extract, args.address, args.output)
        else:
            count = write_catalog()
            print(f"catalogued {count} modules under {CATALOG.relative_to(ROOT)}")
        return 0
    except (OSError, KeyError, RuntimeError, ValueError) as error:
        print(f"structure-v2: error: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
