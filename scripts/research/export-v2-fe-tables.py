#!/usr/bin/env python3
"""Export literal FE tables from the verified original Porsche.exe image."""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
IMAGE = ROOT / "local/game/Porsche.exe"
SHA = "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39"
DEFAULT_OUTPUT = ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/fe_tables.inc"
DEFAULT_PROVENANCE = ROOT / "iterations/v2/001-original-recovery/runs/003-fe-stream/tables.json"
BASE = 0x400000


def u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def sections(data: bytes):
    pe = u32(data, 0x3C)
    count = struct.unpack_from("<H", data, pe + 6)[0]
    optional = struct.unpack_from("<H", data, pe + 20)[0]
    section = pe + 24 + optional
    result = []
    for index in range(count):
        off = section + index * 40
        name = data[off : off + 8].rstrip(b"\0").decode("ascii", "replace")
        virtual_size, virtual_address, raw_size, raw_offset = struct.unpack_from("<IIII", data, off + 8)
        result.append({"name": name, "va": BASE + virtual_address, "virtual_size": virtual_size, "raw_size": raw_size, "raw_offset": raw_offset})
    return result


def make_reader(data: bytes):
    secs = sections(data)

    def offset(va: int) -> int:
        for section in secs:
            if section["va"] <= va < section["va"] + max(section["virtual_size"], section["raw_size"]):
                relative = va - section["va"]
                if relative >= section["raw_size"]:
                    raise ValueError(f"VA 0x{va:08x} is zero-filled or outside raw bytes")
                return section["raw_offset"] + relative
        raise ValueError(f"VA 0x{va:08x} is outside PE sections")

    def word(va: int) -> int:
        return u32(data, offset(va))

    def text(va: int) -> str:
        start = offset(va)
        end = data.find(b"\0", start)
        if end < 0 or end - start > 256:
            raise ValueError(f"unterminated FE string at 0x{va:08x}")
        return data[start:end].decode("ascii")

    return secs, offset, word, text


def c_string(value: str) -> str:
    return json.dumps(value, ensure_ascii=True)


def export(output: Path, provenance: Path) -> dict:
    image = IMAGE.read_bytes()
    actual = hashlib.sha256(image).hexdigest()
    if actual != SHA:
        raise RuntimeError(f"Porsche.exe SHA mismatch: expected {SHA}, got {actual}")
    secs, offset, word, text = make_reader(image)

    definitions = []
    for index in range(100000):
        va = 0x5D1E40 + index * 12
        opcode, target, name = word(va), word(va + 4), word(va + 8)
        definitions.append({"va": va, "opcode": opcode, "target": target, "name_va": name, "name": text(name) if name else None})
        if opcode == 0:
            break
    else:
        raise RuntimeError("definition table has no opcode-zero terminator")

    values = []
    for index in range(100000):
        va = 0x5D63A0 + index * 8
        name, value = word(va), word(va + 4)
        values.append({"va": va, "name_va": name, "value": value, "name": text(name) if name else None})
        if name == 0:
            break
    else:
        raise RuntimeError("value table has no null-name terminator")

    actions = []
    for index in range(100000):
        va = 0x5CC5C8 + index * 12
        name, prepare, callback = word(va), word(va + 4), word(va + 8)
        actions.append({"va": va, "name_va": name, "prepare_va": prepare, "callback_va": callback, "name": text(name) if name else None})
        if name == 0:
            break
    else:
        raise RuntimeError("action table has no null-name terminator")

    car_names = []
    for index in range(100000):
        va = 0x5D61E8 + index * 7
        raw = image[offset(va) : offset(va) + 7]
        if len(raw) != 7:
            raise RuntimeError("short car-name entry")
        car_names.append(raw)
        if raw.rstrip(b"\0") == b"BAD!":
            break
    else:
        raise RuntimeError("car-name table has no BAD! sentinel")

    targets = sorted({row["target"] for row in definitions if row["target"]})
    target_words = {}
    for target in targets:
        if target == 0x65B298:
            continue
        try:
            target_words[target] = word(target)
        except ValueError:
            # PE sections may have zero-filled tails (BSS); preserve that exact
            # original word as zero rather than inventing an initializer.
            section = next((s for s in secs if s['va'] <= target and target + 4 <= s['va'] + s['virtual_size']), None)
            if section is None or target < section['va'] + section['raw_size']:
                raise RuntimeError(f'Global 0x{target:08x} is not a proven zero-filled PE tail')
            target_words[target] = 0
    callbacks = sorted({row["callback_va"] for row in actions if row["callback_va"]})
    lines = ["// Generated from Porsche.exe; automatic literal export, not validated recovered behavior.", f"// Original SHA256: {SHA}", "// Tables preserve original words and sentinels; names are data only.", ""]
    for target in targets:
        if target == 0x65B298:
            lines.append("extern std::uint32_t fe_enabled_0065b298;")
        else:
            lines.append(f"std::uint32_t global_{target:08x} = 0x{target_words[target]:08x}u;")
    for callback in callbacks:
        lines.append(f"extern void __cdecl callback_{callback:08x}(std::int32_t);")
    lines.append("")
    lines.append("FeDefinition fe_definitions_005d1e40[] = {")
    for row in definitions:
        target = "nullptr" if not row["target"] else ("&fe_enabled_0065b298" if row["target"] == 0x65B298 else f"&global_{row['target']:08x}")
        name = "nullptr" if not row["name"] else c_string(row["name"])
        lines.append(f"    {{{row['opcode']}, {target}, {name}}}, // VA 0x{row['va']:08x}")
    lines.append("};\n")
    lines.append("FeValue fe_values_005d63a0[] = {")
    for row in values:
        name = "nullptr" if not row["name"] else c_string(row["name"])
        lines.append(f"    {{{name}, 0x{row['value']:08x}u}}, // VA 0x{row['va']:08x}")
    lines.append("};\n")
    lines.append("FeAction fe_actions_005cc5c8[] = {")
    for row in actions:
        name = "nullptr" if not row["name"] else c_string(row["name"])
        callback = "nullptr" if not row["callback_va"] else f"callback_{row['callback_va']:08x}"
        lines.append(f"    {{{name}, 0x{row['prepare_va']:08x}u, {callback}}}, // VA 0x{row['va']:08x}")
    lines.append("};\n")
    lines.append("char fe_car_names_005d61e8[][7] = {")
    for raw in car_names:
        lines.append(f"    {{{', '.join(f'0x{x:02x}' for x in raw)}}},")
    lines.append("};\n")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("\n".join(lines), encoding="utf-8", newline="\n")
    provenance.parent.mkdir(parents=True, exist_ok=True)
    provenance.write_text(json.dumps({"schema": 1, "module": "Porsche.exe", "sha256": SHA, "image_base": "0x00400000", "sections": secs, "tables": {"definitions": {"va": "0x005d1e40", "stride": 12, "count": len(definitions), "rows": definitions, "terminator": "opcode == 0 (included)"}, "values": {"va": "0x005d63a0", "stride": 8, "count": len(values), "rows": values, "terminator": "name == 0 (included)"}, "actions": {"va": "0x005cc5c8", "stride": 12, "count": len(actions), "rows": actions, "terminator": "name == 0 (included)"}, "car_names": {"va": "0x005d61e8", "stride": 7, "count": len(car_names), "terminator": "BAD! (included)"}}, "globals": len(targets), "callbacks": len(callbacks)}, ensure_ascii=True, sort_keys=True, indent=2) + "\n", encoding="utf-8", newline="\n")
    return {"definitions": len(definitions), "values": len(values), "actions": len(actions), "car_names": len(car_names), "globals": len(targets), "callbacks": len(callbacks)}


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument("--provenance", type=Path, default=DEFAULT_PROVENANCE)
    args = parser.parse_args()
    try:
        print(json.dumps(export(args.output, args.provenance), sort_keys=True))
        return 0
    except (OSError, RuntimeError, ValueError, struct.error) as error:
        print(f"export-v2-fe-tables: error: {error}")
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
