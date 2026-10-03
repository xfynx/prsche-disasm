"""Summarize the current static and Ghidra binary indexes by content hash."""
from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path


def read_jsonl(path):
    with path.open(encoding="utf-8") as stream:
        for line in stream:
            if line.strip():
                yield json.loads(line)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--static", type=Path, default=Path("research/binary-index/static"))
    parser.add_argument("--ghidra", type=Path, default=Path("research/binary-index/ghidra"))
    parser.add_argument("--output", type=Path, default=Path("research/binary-index/coverage.json"))
    args = parser.parse_args()

    static_rows = list(read_jsonl(args.static / "binaries.jsonl"))
    static_summary = json.loads((args.static / "summary.json").read_text(encoding="utf-8"))
    failures = {row.get("path", row["file"]): row for row in static_summary.get("failures", [])}
    for row in failures.values():
        if row.get("sha256") and not any(x.get("sha256") == row["sha256"] for x in static_rows):
            static_rows.append(row)

    ghidra_by_hash = {}
    ghidra_dirs = {}
    for metadata_path in sorted(args.ghidra.glob("*/metadata.json")):
        metadata = json.loads(metadata_path.read_text(encoding="utf-8"))
        digest = metadata.get("sha256")
        if digest:
            ghidra_by_hash[digest] = metadata
            ghidra_dirs[digest] = metadata_path.parent.name

    rows_by_hash = defaultdict(list)
    per_binary = []
    for static in static_rows:
        digest = static.get("sha256")
        if not digest:
            continue
        rows_by_hash[digest].append(static.get("path", static.get("file")))
        ghidra = ghidra_by_hash.get(digest)
        failure = failures.get(static.get("path", static.get("file")))
        if failure:
            status = "static-failure"
        elif not ghidra:
            status = "missing"
        elif ghidra.get("analysis_timed_out") is True:
            status = "timeout"
        elif not all((args.ghidra / ghidra_dirs[digest] / name).exists()
                     for name in ("functions.jsonl", "calls.jsonl", "references.jsonl")):
            status = "partial"
        else:
            status = "indexed"
        unresolved = None
        if ghidra:
            unresolved = ghidra.get("unresolved_calls")
        per_binary.append({
            "path": static.get("path", static.get("file")), "sha256": digest,
            "aliases": rows_by_hash[digest], "status": status,
            "static": {key: static.get(key) for key in
                        ("size", "candidate_function_count", "call_count", "string_count", "resource_count")},
            "ghidra": ({key: ghidra.get(key) for key in
                        ("functions", "calls", "references", "strings", "symbols", "instructions", "unresolved_calls")}
                       if ghidra else None),
            # Cached export metadata does not prove that analysis completed.
            "analysis_timed_out": (None if ghidra and ghidra.get("export_mode") == "cached-analysis"
                                    else (ghidra.get("analysis_timed_out") if ghidra else None)),
            "analysis_timeout_flag": ghidra.get("analysis_timed_out") if ghidra else None,
            "analysis_completion": ("unknown-cached-export" if ghidra and ghidra.get("export_mode") == "cached-analysis"
                                     else ("reported" if ghidra else None)),
            "ghidra_metadata": (str(Path("research/binary-index/ghidra") /
                                    ghidra_dirs[digest] / "metadata.json") if ghidra else None),
            "unresolved_target_refs": None,
        })

    # Calls use Ghidra function entry VAs. Count targets absent from that
    # binary's function table; these may be external/indirect and are retained
    # as navigation facts rather than treated as analysis failures.
    for row in per_binary:
        digest = row["sha256"]
        if digest not in ghidra_dirs: continue
        folder = args.ghidra / ghidra_dirs[digest]
        function_vas = {item.get("entry_va") for item in read_jsonl(folder / "functions.jsonl")}
        unresolved = 0
        for call in read_jsonl(folder / "calls.jsonl"):
            target = call.get("to_function")
            if target and target not in function_vas:
                unresolved += 1
        row["unresolved_target_refs"] = unresolved

    valid_hashes = set(rows_by_hash)
    stale = []
    for digest, folder in ghidra_dirs.items():
        if digest not in valid_hashes:
            stale.append({"directory": folder, "sha256": digest})
    unique = []
    for digest, aliases in rows_by_hash.items():
        matching = next(item for item in per_binary if item["sha256"] == digest)
        unique.append(matching)
    counts = {"total_paths": len(per_binary), "unique_hashes": len(unique),
              "indexed_paths": sum(item["status"] == "indexed" for item in per_binary),
              "missing_paths": sum(item["status"] == "missing" for item in per_binary),
              "partial_paths": sum(item["status"] == "partial" for item in per_binary),
              "timeout_paths": sum(item["status"] == "timeout" for item in per_binary),
              "static_failure_paths": sum(item["status"] == "static-failure" for item in per_binary),
              "unresolved_target_paths": sum((item["unresolved_target_refs"] or 0) > 0 for item in per_binary)}
    totals = {}
    for key in ("candidate_function_count", "call_count", "string_count", "resource_count"):
        totals[key] = sum((item["static"].get(key) or 0) for item in unique)
    for key in ("functions", "calls", "references", "strings", "symbols", "instructions", "unresolved_calls"):
        totals["ghidra_" + key] = sum((item["ghidra"] or {}).get(key, 0) for item in unique)

    result = {"schema": 1, "source": {"static": str(args.static), "ghidra": str(args.ghidra)},
              "counts": counts, "deduplicated_totals_by_hash": totals,
              "duplicate_aliases": {digest: aliases for digest, aliases in rows_by_hash.items() if len(aliases) > 1},
              "static_failures": list(failures.values()), "stale_ghidra_outputs_excluded": stale,
              "binaries": per_binary}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(json.dumps({"counts": counts, "stale_excluded": len(stale)}, ensure_ascii=False))


if __name__ == "__main__":
    main()
