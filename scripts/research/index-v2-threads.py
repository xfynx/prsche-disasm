"""Emit bounded evidence for the original Porsche thread helper cluster."""
from __future__ import annotations

import hashlib
import json
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MODULE = ROOT / "local/game/Porsche.exe"
SHA = "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39"
BASE = 0x400000
FUNCTIONS = [0x55F2B0, 0x55F320, 0x55F3B0, 0x55F4F0, 0x55F560,
             0x55F5F0, 0x55F730, 0x55F780, 0x55F7E0, 0x55F8B0]
IMPORT_NAMES = ["CreateThread", "SetThreadPriority", "GetLastError", "CreateEventA",
                "SetEvent", "WaitForMultipleObjectsEx", "ResetEvent"]


def layout(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    coff, opt = pe + 4, pe + 24
    nsec = struct.unpack_from("<H", data, coff + 2)[0]
    opt_size = struct.unpack_from("<H", data, coff + 16)[0]
    sections = []
    for i in range(nsec):
        off = opt + opt_size + i * 40
        sections.append((struct.unpack_from("<I", data, off + 12)[0],
                         struct.unpack_from("<I", data, off + 8)[0],
                         struct.unpack_from("<I", data, off + 16)[0],
                         struct.unpack_from("<I", data, off + 20)[0]))
    return sections


def file_offset(sections, va):
    rva = va - BASE
    for section_rva, virtual_size, raw_size, raw_offset in sections:
        if section_rva <= rva < section_rva + max(virtual_size, raw_size):
            delta = rva - section_rva
            if delta >= raw_size:
                raise ValueError(f"VA is BSS-only: 0x{va:08x}")
            return raw_offset + delta
    raise ValueError(f"VA not backed by PE section: 0x{va:08x}")


def main():
    data = MODULE.read_bytes()
    assert hashlib.sha256(data).hexdigest() == SHA
    sections = layout(data)
    asm_path = ROOT / "research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm"
    asm = asm_path.read_text(encoding="utf-8")
    calls = {}
    for line in asm.splitlines():
        match = re.match(r"^(?P<site>[0-9a-f]{8})\s+\S+.*?CALL 0x(?P<target>[0-9a-f]{8})$", line, re.I)
        if match:
            target = int(match.group("target"), 16)
            if target in FUNCTIONS:
                calls.setdefault(f"{target:08x}", []).append(f"{int(match.group('site'), 16):08x}")
        match = re.match(r"^(?P<site>[0-9a-f]{8})\s+\S+.*?PUSH 0x(?P<target>[0-9a-f]{6,8})$", line, re.I)
        if match:
            target = int(match.group("target"), 16)
            if target in FUNCTIONS:
                calls.setdefault(f"{target:08x}", []).append(
                    f"{int(match.group('site'), 16):08x} (PUSH callback target)")
    function_rows = []
    for va in FUNCTIONS:
        # Bounds come from the original listing; the trampoline is the one
        # supplementary entry absent from functions.jsonl.
        end = {0x55F2B0: 0x55F312, 0x55F320: 0x55F3A2, 0x55F3B0: 0x55F414,
               0x55F4F0: 0x55F552, 0x55F560: 0x55F5EF, 0x55F5F0: 0x55F6C7,
               0x55F730: 0x55F736, 0x55F780: 0x55F7D0, 0x55F7E0: 0x55F7E7,
               0x55F8B0: 0x55F95B}[va]
        off = file_offset(sections, va)
        body = data[off:off + end - va + 1]
        function_rows.append({"entry_va": f"0x{va:08x}", "end_va": f"0x{end:08x}",
                              "file_offset": f"0x{off:x}", "body_bytes": len(body),
                              "body_sha256": hashlib.sha256(body).hexdigest(),
                              "callsite_targets": calls.get(f"{va:08x}", [])})
    imports = [json.loads(line) for line in (ROOT / "research/binary-index/static/imports.jsonl").read_text().splitlines()]
    iat = {row["symbol"]: row for row in imports if row["path"] == "Porsche.exe" and row["symbol"] in IMPORT_NAMES}
    table_va = 0x55F95C
    table_off = file_offset(sections, table_va)
    table = data[table_off:table_off + 28]
    globals_vas = [0x6A57D0, 0x6A57D4, 0x6A57D8, 0x6A57DC, 0x6A57E0, 0x6A57E4, 0x6A57E8, 0x6A57EC]
    globals_rows = []
    for va in globals_vas:
        try:
            word, storage = struct.unpack_from("<I", data, file_offset(sections, va))[0], "raw"
        except ValueError:
            word, storage = 0, "BSS-zero"
        globals_rows.append({"va": f"0x{va:08x}", "initial_word": word, "storage": storage})
    report = {"schema": 1, "module_sha256": SHA, "function_evidence": function_rows,
              "iat_crosscheck": [{"symbol": name, "iat_rva": iat[name]["iat_rva"],
                                   "iat_va": f"0x{BASE + int(iat[name]['iat_rva'], 16):08x}"} for name in IMPORT_NAMES],
              "global_fields": globals_rows, "serial_initial": {"va": "0x005df6a0", "word": 1},
              "thread_priority_table": {"va": "0x0055f95c", "file_offset": f"0x{table_off:x}",
                  "raw_bytes": table.hex(), "targets": [f"0x{x:08x}" for x in struct.unpack("<7I", table)]},
              "semantic_boundary": "Only instruction operands, call targets and imported names are recorded; labels and global meanings remain unresolved."}
    out = ROOT / "iterations/v2/001-original-recovery/runs/010-file-threads/thread-index.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"functions": len(function_rows), "iat_names": len(iat), "output": str(out)}))


if __name__ == "__main__":
    main()
