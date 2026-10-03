"""Build a bounded, read-only PE inventory for the game binaries.

This is a static index, not a decompiler. Function records found by byte
patterns are explicitly marked ``candidate``. Existing Ghidra analysis is
reported only when the corresponding headless log says that analysis and save
completed; it is not used to label every candidate as verified.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
from pathlib import Path

try:
    import capstone
except ImportError:
    capstone = None

PE_EXTENSIONS = {".exe", ".dll", ".ocx", ".asi"}
ASCII_RE = re.compile(rb"[ -~]{4,}")
UTF16_RE = re.compile(rb"(?:[ -~]\x00){4,}")
PROLOGUES = (b"\x55\x8b\xec", b"\x55\x89\xe5", b"\x53\x56\x57\x8b", b"\x56\x8b\xf1\x57")


def u16(data, off): return struct.unpack_from("<H", data, off)[0]
def u32(data, off): return struct.unpack_from("<I", data, off)[0]


def parse_pe(path: Path):
    data = path.read_bytes()
    if len(data) < 0x40 or data[:2] != b"MZ":
        raise ValueError("missing MZ header")
    pe = u32(data, 0x3c)
    if data[pe:pe + 2] == b"NE":
        raise ValueError("NE (16-bit Windows): not covered by PE analysis")
    if data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("missing PE signature")
    coff = pe + 4
    nsec, opt_size = u16(data, coff + 2), u16(data, coff + 16)
    opt = coff + 20
    magic = u16(data, opt)
    if magic != 0x10B:
        raise ValueError(f"unsupported optional-header magic 0x{magic:x}")
    image_base, entry_rva = u32(data, opt + 28), u32(data, opt + 16)
    ndata = u32(data, opt + 92)
    dd = opt + 96
    dirs = [(u32(data, dd + i * 8), u32(data, dd + i * 8 + 4)) for i in range(ndata)]
    sec_start = opt + opt_size
    sections = []
    for i in range(nsec):
        off = sec_start + i * 40
        name = data[off:off + 8].rstrip(b"\0").decode("ascii", "replace")
        sections.append({"name": name, "rva": u32(data, off + 12), "vsize": u32(data, off + 8),
                         "raw_size": u32(data, off + 16), "raw_offset": u32(data, off + 20),
                         "characteristics": f"{u32(data, off + 36):08x}"})

    def file_offset(rva):
        for s in sections:
            size = max(s["vsize"], s["raw_size"])
            if s["rva"] <= rva < s["rva"] + size:
                return s["raw_offset"] + rva - s["rva"]
        if rva < (sections[0]["rva"] if sections else 0):
            return rva
        return None

    def rva_for_file_offset(offset):
        for s in sections:
            if s["raw_offset"] <= offset < s["raw_offset"] + s["raw_size"]:
                return s["rva"] + offset - s["raw_offset"]
        return None

    def cstr(off):
        if off is None or off >= len(data): return ""
        end = data.find(b"\0", off)
        return data[off:end if end >= 0 else len(data)].decode("ascii", "replace")

    imports, import_rows = [], []
    imp_rva = dirs[1][0] if len(dirs) > 1 else 0
    imp = file_offset(imp_rva) if imp_rva else None
    while imp is not None and imp + 20 <= len(data) and any(data[imp:imp + 20]):
        original, _, _, name_rva, first = struct.unpack_from("<5I", data, imp)
        dll = cstr(file_offset(name_rva))
        symbols = []
        thunk = file_offset(original or first)
        while thunk is not None and thunk + 4 <= len(data) and u32(data, thunk):
            value = u32(data, thunk)
            if value & 0x80000000:
                symbol = f"ordinal:{value & 0xffff}"
            else:
                symbol = cstr(file_offset(value) + 2 if file_offset(value) is not None else None)
            symbols.append(symbol)
            import_rows.append({"dll": dll, "symbol": symbol,
                                "iat_rva": f"0x{(first + (thunk - file_offset(first))):x}" if file_offset(first) is not None else None})
            thunk += 4
        imports.append({"dll": dll, "symbols": symbols})
        imp += 20

    exports = []
    exp_rva = dirs[0][0] if dirs else 0
    exp = file_offset(exp_rva) if exp_rva else None
    if exp is not None and exp + 40 <= len(data):
        _, _, _, _, _, base, n_funcs, n_names, funcs_rva, names_rva, ords_rva = struct.unpack_from("<IIHHIIIIIII", data, exp)
        funcs, names, ords = file_offset(funcs_rva), file_offset(names_rva), file_offset(ords_rva)
        named = {}
        if names is not None and ords is not None:
            for i in range(min(n_names, 100000)):
                no = file_offset(u32(data, names + i * 4))
                if no is not None: named[u16(data, ords + i * 2)] = cstr(no)
        if funcs is not None:
            for ordinal in range(min(n_funcs, 100000)):
                frva = u32(data, funcs + ordinal * 4)
                forwarder = bool(exp_rva <= frva < exp_rva + (dirs[0][1] if dirs else 0))
                exports.append({"name": named.get(ordinal), "ordinal": base + ordinal,
                                "rva": f"0x{frva:x}", "forwarder": forwarder,
                                "target": cstr(file_offset(frva)) if forwarder else None})

    functions, calls = [], []
    decoded = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32) if capstone else None
    for s in sections:
        if not (int(s["characteristics"], 16) & 0x20): continue
        blob = data[s["raw_offset"]:s["raw_offset"] + s["raw_size"]]
        starts = set()
        if decoded:
            decoded.detail = True
            for insn in decoded.disasm(blob, s["rva"]):
                starts.add(insn.address - s["rva"])
                if insn.bytes[:1] == b"\xe8" and len(insn.bytes) == 5:
                    target = insn.address + 5 + struct.unpack_from("<i", insn.bytes, 1)[0]
                    calls.append((insn.address, target, "decoded-rel32-call", "decoded"))
        for pro in PROLOGUES:
            for local in range(0, max(0, len(blob) - len(pro) + 1)):
                if blob.startswith(pro, local) and (not decoded or local in starts):
                    functions.append((s["rva"] + local, "prologue", "candidate"))
        if not decoded:
            for local in range(0, max(0, len(blob) - 5)):
                if blob[local] == 0xE8:
                    target = s["rva"] + local + 5 + struct.unpack_from("<i", blob, local + 1)[0]
                    calls.append((s["rva"] + local, target, "byte-pattern-call", "unverified"))
    # Deduplicate pattern hits and retain callers for each discovered target.
    functions = sorted(set(functions))
    caller_counts = {}
    for _, target, *_ in calls: caller_counts[target] = caller_counts.get(target, 0) + 1
    string_rows = []
    for match in ASCII_RE.finditer(data):
        string_rows.append((match.start(), rva_for_file_offset(match.start()), match.group().decode("ascii", "replace"), "ascii"))
    for match in UTF16_RE.finditer(data):
        try: value = match.group().decode("utf-16le", "replace")
        except UnicodeDecodeError: continue
        string_rows.append((match.start(), rva_for_file_offset(match.start()), value, "utf16le"))
    string_rows = sorted({row for row in string_rows}, key=lambda x: x[0])
    resources = []
    if len(dirs) > 2 and dirs[2][0]:
        resources.append({"kind": "resource-directory", "rva": f"0x{dirs[2][0]:x}", "size": dirs[2][1]})
    summary = {"file": path.name, "size": len(data), "sha256": hashlib.sha256(data).hexdigest(),
               "machine": f"{u16(data, coff):04x}", "entry_rva": f"0x{entry_rva:x}",
               "image_base": f"0x{image_base:x}", "sections": sections,
               "imports": imports, "exports": exports, "candidate_function_count": len(functions),
               "call_count": len(calls), "string_count": len(string_rows), "resource_count": len(resources)}
    return data, summary, functions, calls, string_rows, resources, import_rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--game", type=Path, default=Path("local/game"))
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    rows = []; all_functions = []; all_calls = []; all_strings = []; all_resources = []; all_imports = []; failures = []
    for path in sorted(args.game.rglob("*")):
        if not path.is_file() or path.suffix.lower() not in PE_EXTENSIONS: continue
        rel = path.relative_to(args.game).as_posix()
        try:
            _, summary, functions, calls, strings, resources, imports = parse_pe(path)
            summary["path"] = rel
        except Exception as exc:
            failures.append({"file": path.name, "path": rel,
                             "sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
                             "size": path.stat().st_size, "error": str(exc)})
            continue
        rows.append(summary)
        all_functions += [{"path": rel, "rva": f"0x{rva:x}", "va": f"0x{int(summary['image_base'], 16) + rva:x}", "source": source, "confidence": confidence,
                           "caller_count": sum(1 for _, target, *_ in calls if target == rva)} for rva, source, confidence in functions]
        all_calls += [{"path": rel, "instruction_rva": f"0x{caller:x}", "target_rva": f"0x{target:x}", "kind": kind, "confidence": confidence} for caller, target, kind, confidence in calls]
        all_strings += [{"path": rel, "offset": f"0x{off:x}", "rva": (f"0x{rva:x}" if rva is not None else None), "va": (f"0x{int(summary['image_base'], 16) + rva:x}" if rva is not None else None), "encoding": enc, "value": value} for off, rva, value, enc in strings]
        all_resources += [{"path": rel, **resource} for resource in resources]
        all_imports += [{"path": rel, **row} for row in imports]
    def write_jsonl(name, values):
        (args.out / name).write_text("".join(json.dumps(v, ensure_ascii=False) + "\n" for v in values), encoding="utf-8")
    write_jsonl("binaries.jsonl", rows); write_jsonl("functions.jsonl", all_functions); write_jsonl("calls.jsonl", all_calls)
    write_jsonl("strings.jsonl", all_strings); write_jsonl("resources.jsonl", all_resources); write_jsonl("imports.jsonl", all_imports)
    summary = {"schema": 1, "mode": "static-candidates", "binary_count": len(rows), "failure_count": len(failures),
               "totals": {"candidate_functions": len(all_functions), "calls": len(all_calls), "strings": len(all_strings),
                          "resources": len(all_resources), "imports": len(all_imports)}, "failures": failures}
    summary["capstone"] = bool(capstone)
    (args.out / "summary.json").write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(summary, ensure_ascii=False))
    return 1 if failures else 0


if __name__ == "__main__": raise SystemExit(main())
