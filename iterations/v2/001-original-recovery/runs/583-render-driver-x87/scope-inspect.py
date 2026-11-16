"""Bounded raw-PE and index evidence for Run583 callback 00540500."""
from pathlib import Path
import hashlib, importlib.util, json, struct

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location("native", ROOT / "scripts/research/verify-v2-native-batch.py")
native = importlib.util.module_from_spec(spec); spec.loader.exec_module(native)
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
md = Cs(CS_ARCH_X86, CS_MODE_32)
raw = (ROOT / "local/game/Porsche.exe").read_bytes()
sha = hashlib.sha256(raw).hexdigest()
assert sha == "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39"
index = ROOT / "research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d"
funcs = {x["entry_va"]: x for x in map(json.loads, (index / "functions.jsonl").read_text().splitlines())}
refs = list(map(json.loads, (index / "references.jsonl").read_text().splitlines()))
calls = list(map(json.loads, (index / "calls.jsonl").read_text().splitlines()))

def mapped(va, size):
    pe = struct.unpack_from("<I", raw, 0x3c)[0]
    nsec = struct.unpack_from("<H", raw, pe + 6)[0]
    opt = struct.unpack_from("<H", raw, pe + 20)[0]
    rva = va - struct.unpack_from("<I", raw, pe + 24 + 28)[0]
    for i in range(nsec):
        at = pe + 24 + opt + i * 40
        vs, srva, rs, ro = struct.unpack_from("<IIII", raw, at + 8)
        if srva <= rva and rva + size <= srva + max(vs, rs):
            pos = ro + rva - srva
            return raw[pos:pos + size], raw[at:at + 8].rstrip(b"\0").decode()
    raise ValueError(f"unmapped VA {va:08x}+{size}")

def mapped_state(va, size):
    pe = struct.unpack_from("<I", raw, 0x3c)[0]
    nsec = struct.unpack_from("<H", raw, pe + 6)[0]
    opt = struct.unpack_from("<H", raw, pe + 20)[0]
    rva = va - struct.unpack_from("<I", raw, pe + 24 + 28)[0]
    for i in range(nsec):
        at = pe + 24 + opt + i * 40
        vs, srva, rs, ro = struct.unpack_from("<IIII", raw, at + 8)
        if srva <= rva and rva + size <= srva + max(vs, rs):
            rel = rva - srva
            count = min(size, max(0, rs - rel))
            return {"section": raw[at:at + 8].rstrip(b"\0").decode(),
                    "loader_zero": count < size, "file_backed_bytes": count,
                    "raw_hex": raw[ro + rel:ro + rel + count].hex()}
    raise ValueError(f"unmapped VA {va:08x}+{size}")

def relocations():
    pe = struct.unpack_from("<I", raw, 0x3c)[0]; opt = pe + 24
    dd = opt + 96
    rel_rva, rel_size = struct.unpack_from("<II", raw, dd + 40)
    image_base = struct.unpack_from("<I", raw, opt + 28)[0]
    nsec = struct.unpack_from("<H", raw, pe + 6)[0]; optsz = struct.unpack_from("<H", raw, pe + 20)[0]
    def off(rva):
        for i in range(nsec):
            at = pe + 24 + optsz + i * 40
            vs, srva, rs, ro = struct.unpack_from("<IIII", raw, at + 8)
            if srva <= rva < srva + max(vs, rs): return ro + rva - srva
    cur = off(rel_rva); end = cur + rel_size; out=[]
    while cur + 8 <= end:
        page, block = struct.unpack_from("<II", raw, cur)
        if block < 8 or cur + block > end: break
        for p in range(cur + 8, cur + block, 2):
            ent = struct.unpack_from("<H", raw, p)[0]; kind, ofs = ent >> 12, ent & 0xfff
            if kind: out.append({"va": f"{image_base + page + ofs:08x}", "type": kind})
        cur += block
    return out

body, section = mapped(0x540500, 71)
ins = list(md.disasm(body, 0x540500))
assert sum(len(x.bytes) for x in ins) == 71
assert [x.address for x in ins if x.mnemonic == "ret"] == [0x540539, 0x540546]
cb, _ = mapped(0x5ded60, 24)
cbwords = struct.unpack("<6I", cb)
relmap = {r["va"]: r["type"] for r in relocations()}
callback_slots = [{"slot": f"{0x5ded60+i*4:08x}", "raw_target": f"{v:08x}",
                   "relocation_type": relmap.get(f"{0x5ded60+i*4:08x}")} for i, v in enumerate(cbwords)]
body_rows = {}
for va in (0x538af0, 0x540500):
    size = 41 if va == 0x538af0 else 71
    b, sec = mapped(va, size); decoded = list(md.disasm(b, va))
    row = funcs.get(f"{va:08x}")
    body_rows[f"{va:08x}"] = {"size": size, "section": sec, "sha256": hashlib.sha256(b).hexdigest(),
        "raw_hex": b.hex(), "index_status": "indexed" if row else "unindexed; raw PE supplement",
        "indexed_ranges": row.get("ranges") if row else None,
        "instructions": [{"va": f"{x.address:08x}", "bytes": x.bytes.hex(), "mnemonic": x.mnemonic, "operands": x.op_str} for x in decoded],
        "rets": [f"{x.address:08x}" for x in decoded if x.mnemonic == "ret"]}
table_refs = [r for r in refs if r.get("to_va", "").lower() in {f"{v:08x}" for v in range(0x5ded60, 0x5ded78, 4)}]
canonical_data = {f"{va:08x}": mapped_state(va, size) for va, size in
                 ((0x69ed0c, 4), (0x69e0d4, 4), (0x5b3e10, 4), (0x6bd910, 43 * 4))}
related_calls = [c for c in calls if c.get("from_function", "").lower() in ("00538af0", "00540500") or c.get("to_function", "").lower() in ("00538af0", "00540500")]
evidence = {"scope": "Run583 static evidence; no native acceptance claim", "provenance": {"pe": "local/game/Porsche.exe", "sha256": sha, "index": str(index.relative_to(ROOT)).replace("\\", "/")},
    "bodies": body_rows, "callback_table": {"va": "005ded60", "size": len(cb), "raw_hex": cb.hex(), "slots": callback_slots, "refs": table_refs},
    "canonical_data_initial_witnesses": canonical_data,
    "related_calls": related_calls}
(RUN / "scope-evidence.json").write_text(json.dumps(evidence, indent=2) + "\n", encoding="utf-8", newline="\n")
supp = {"target": "00540500", "status": "unindexed body bounded from verified raw PE; decoded independently with Capstone x86-32",
    "start_va": "00540500", "end_va_exclusive": "00540547", "body_bytes": 71,
    "sha256": body_rows["00540500"]["sha256"], "section": section, "instructions": body_rows["00540500"]["instructions"],
    "cfg": {"conditional_edges": [{"from": x["va"], "target": x["operands"].split()[-1]} for x in body_rows["00540500"]["instructions"] if x["mnemonic"].startswith("j") and x["mnemonic"] != "jmp"],
            "ret_sites": body_rows["00540500"]["rets"], "padding": {"start": "00540547", "end_exclusive": "00540550", "byte": "90"}},
    "relocations": [r for r in relocations() if 0x540500 <= int(r["va"], 16) < 0x540547],
    "callback_table": evidence["callback_table"], "canonical_data_initial_witnesses": canonical_data, "provenance": evidence["provenance"]}
(RUN / "original-index-supplement.json").write_text(json.dumps(supp, indent=2) + "\n", encoding="utf-8", newline="\n")
print(json.dumps({"sha256": sha, "body": {"bytes": len(body), "sha256": body_rows["00540500"]["sha256"], "rets": body_rows["00540500"]["rets"]},
                  "table": [(x["slot"], x["raw_target"], x["relocation_type"]) for x in callback_slots],
                  "refs": len(table_refs), "calls": len(related_calls)}))
