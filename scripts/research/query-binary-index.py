"""Search original binary indexes before implementing behavior (JSON lines output)."""
from __future__ import annotations
import argparse
import hashlib
import json
import re
from pathlib import Path


def rows(path):
    if path.exists():
        with path.open(encoding="utf-8-sig") as stream:
            for line in stream:
                if line.strip():
                    yield json.loads(line)


def address(value):
    if value is None:
        return None
    try:
        return int(value, 16)
    except ValueError:
        return None


def contains(function, value):
    return any(address(lo) <= value <= address(hi) for lo, hi in function["ranges"])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path("research/binary-index"))
    parser.add_argument("--game", type=Path, default=Path("local/game"))
    parser.add_argument("--binary", required=True, help="Filename or relative path, case insensitive")
    selector = parser.add_mutually_exclusive_group(required=True)
    selector.add_argument("--text", help="Regex over strings, function names and symbols")
    selector.add_argument("--address", type=lambda s: int(s, 16), help="Original VA, e.g. 0x49c922")
    parser.add_argument("--limit", type=int, default=15, help="Maximum matched records and references per match")
    parser.add_argument("--disassemble", action="store_true", help="With --address, decode indexed function ranges using Capstone")
    args = parser.parse_args()
    if args.limit < 1:
        parser.error("--limit must be positive")
    if args.disassemble and args.address is None:
        parser.error("--disassemble requires --address")
    pattern = re.compile(args.text, re.IGNORECASE) if args.text else None
    modules = [m for m in rows(args.root / "static/binaries.jsonl")
               if args.binary.lower() in (m["file"].lower(), m["path"].lower())]
    if not modules:
        parser.error("Binary absent from static inventory; generate/check coverage first")
    for module in modules:
        live = args.game / module["path"]
        if args.disassemble and not live.exists():
            parser.error(f"Disassembly requires the original binary: {live}")
        if live.exists() and hashlib.sha256(live.read_bytes()).hexdigest() != module["sha256"]:
            parser.error(f"Stale index for {module['path']}; binary hash changed, regenerate first")
        folder = args.root / "ghidra" / (module["file"] + "-" + module["sha256"][:12])
        metadata = folder / "metadata.json"
        print(json.dumps({"module": module["path"], "sha256": module["sha256"],
                          "ghidra_index": str(folder) if metadata.exists() else None}))
        if not metadata.exists() and args.address is not None:
            print(json.dumps({"note": "No analyzed function index for this binary; inspect coverage before inferring behavior"}))
        if metadata.exists():
            functions = list(rows(folder / "functions.jsonl"))
            names = {f["entry_va"]: f["name"] for f in functions}
            hits = []
            if args.address is not None:
                hits = [{"kind": "function", **f} for f in functions if contains(f, args.address)]
                if not hits:
                    hits = [{"kind": "address", "va": f"{args.address:08x}"}]
            else:
                for kind, filename, field in [("function", "functions.jsonl", "name"),
                                               ("string", "strings.jsonl", "value"),
                                               ("symbol", "symbols.jsonl", "name")]:
                    hits.extend({"kind": kind, **r} for r in rows(folder / filename)
                                if pattern.search(r.get(field, "")))
            hits = hits[:args.limit]
            references = list(rows(folder / "references.jsonl"))
            for hit in hits:
                target = hit.get("entry_va", hit.get("va"))
                related = []
                for ref in references:
                    direct = ref["to_va"] == target or ref["from_va"] == target
                    call = hit["kind"] == "function" and "CALL" in ref["type"] and (
                        ref.get("from_function") == target or ref.get("to_function") == target)
                    if direct or call:
                        related.append({**ref, "from_name": names.get(ref.get("from_function")),
                                        "to_name": names.get(ref.get("to_function"))})
                print(json.dumps({**hit, "references": related[:args.limit],
                                  "reference_count": len(related)}, ensure_ascii=False))
                if args.disassemble and hit["kind"] == "function":
                    try:
                        import capstone
                    except ImportError:
                        parser.error("Capstone is required for --disassemble")
                    data = live.read_bytes()
                    base = address(module["image_base"])
                    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
                    decoded = []
                    for lo, hi in hit["ranges"]:
                        start, end = address(lo), address(hi)
                        for section in module["sections"]:
                            rva = start - base
                            if section["rva"] <= rva < section["rva"] + section["raw_size"]:
                                offset = section["raw_offset"] + rva - section["rva"]
                                size = min(end-start+1, section["raw_size"]-(rva-section["rva"]))
                                decoded.extend({"va": f"{i.address:08x}", "instruction": f"{i.mnemonic} {i.op_str}"}
                                               for i in decoder.disasm(data[offset:offset+size], start))
                                break
                    print(json.dumps({"kind": "disassembly", "function": target,
                                      "instructions": decoded[:args.limit], "decoded_count": len(decoded)}))
            if not hits:
                print(json.dumps({"note": "No analyzed match; checking raw strings below"}))
        # Also expose raw strings not recognized as Ghidra data, clearly separated.
        if pattern:
            count = 0
            for r in rows(args.root / "static/strings.jsonl"):
                if r["path"] == module["path"] and pattern.search(r["value"]):
                    print(json.dumps({"kind": "raw_string", **r}, ensure_ascii=False))
                    count += 1
                    if count >= args.limit:
                        break
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
