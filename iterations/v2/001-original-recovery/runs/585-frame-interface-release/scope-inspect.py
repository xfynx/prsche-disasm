"""Bounded 582-closure, registry, PE and binary-index census for Run585."""
from pathlib import Path
import hashlib
import importlib.util
import json
import sys

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
ORIGINAL = ROOT / "local/game/Porsche.exe"
BUILD_RUN = ROOT / "iterations/v2/001-original-recovery/runs/582-driver-state-integration"
INTEGRATION_RUN = ROOT / "iterations/v2/001-original-recovery/runs/584-driver-x87-integration"
BASE = 0x400000
BODY = 0x5693E0
BODY_SIZE = 53
DATA_START = 0x6A5CA0
DATA_SIZE = 12


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load_module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def pe_sections(pe):
    nt = int.from_bytes(pe[0x3C:0x40], "little")
    count = int.from_bytes(pe[nt + 6:nt + 8], "little")
    optional_size = int.from_bytes(pe[nt + 20:nt + 22], "little")
    optional = nt + 24
    image_base = int.from_bytes(pe[optional + 28:optional + 32], "little")
    section_table = optional + optional_size
    out = []
    for index in range(count):
        off = section_table + index * 40
        name = pe[off:off + 8].split(b"\0", 1)[0].decode("ascii")
        virtual_size = int.from_bytes(pe[off + 8:off + 12], "little")
        virtual_address = int.from_bytes(pe[off + 12:off + 16], "little")
        raw_size = int.from_bytes(pe[off + 16:off + 20], "little")
        raw_pointer = int.from_bytes(pe[off + 20:off + 24], "little")
        characteristics = int.from_bytes(pe[off + 36:off + 40], "little")
        out.append(dict(name=name, virtual_address=virtual_address,
                        virtual_size=virtual_size, raw_size=raw_size,
                        raw_pointer=raw_pointer, characteristics=characteristics))
    return image_base, out


def index_rows(index_dir, name):
    return [json.loads(line) for line in (index_dir / name).read_text(encoding="utf-8").splitlines()]


def address(value):
    try:
        return int(value, 16)
    except (TypeError, ValueError):
        return None


def main():
    pe = ORIGINAL.read_bytes()
    expected_sha = "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39"
    assert sha(pe) == expected_sha
    native = load_module("run585_native", ROOT / "scripts/research/verify-v2-native-batch.py")
    sys.path.insert(0, str(ROOT / "local/tools/python-unicorn"))
    import capstone

    build = json.loads((BUILD_RUN / "build-001.json").read_bytes())
    build_config = json.loads((BUILD_RUN / "build-config.json").read_bytes())
    build_hashes = load_module("run585_dependencies", ROOT / "scripts/research/v2_source_dependencies.py")
    build_hashes.EXTRA_INCLUDE_DIRS = tuple(ROOT / item for item in build_config["source_include_dirs"])
    integration = json.loads((INTEGRATION_RUN / "acceptance.json").read_bytes())
    closure_roots = list(build["compiled_source_roots"]) + integration["added_sources"]
    closure = build_hashes.source_hashes([ROOT / item for item in closure_roots])
    registry_path = ROOT / "iterations/v2/001-original-recovery/source/recovered/functions.json"
    registry_bytes = registry_path.read_bytes()
    registry = json.loads(registry_bytes)
    index_dir = ROOT / "research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d"
    metadata = json.loads((index_dir / "metadata.json").read_bytes())
    functions = index_rows(index_dir, "functions.jsonl")
    calls = index_rows(index_dir, "calls.jsonl")
    references = index_rows(index_dir, "references.jsonl")
    unresolved = index_rows(index_dir, "unresolved-calls.jsonl")

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    body = native.pe_at(pe, BODY, BODY_SIZE)
    instructions = list(md.disasm(body, BODY))
    assert sum(len(item.bytes) for item in instructions) == BODY_SIZE
    fn_row = next(item for item in functions if item["entry_va"] == f"{BODY:08x}")
    assert fn_row["body_bytes"] == BODY_SIZE
    assert [int(fn_row["ranges"][0][0], 16), int(fn_row["ranges"][0][1], 16)] == [BODY, BODY + BODY_SIZE - 1]

    call_rows = [item for item in calls if item.get("to_va", "").lower() == f"{BODY:08x}"]
    call_contexts = []
    for call in call_rows:
        owner = next(item for item in functions if item["entry_va"] == call["from_function"])
        full = []
        for first, last in owner["ranges"]:
            start, end = int(first, 16), int(last, 16)
            full.extend(md.disasm(native.pe_at(pe, start, end - start + 1), start))
        position = next(i for i, ins in enumerate(full) if ins.address == int(call["from_va"], 16))
        call_contexts.append(dict(call=call, function=owner["name"],
                                  range=owner["ranges"][0],
                                  context=[dict(va=f"{ins.address:08x}", bytes=ins.bytes.hex(),
                                                mnemonic=ins.mnemonic, operands=ins.op_str)
                                           for ins in full[max(0, position - 2):position + 7]]))

    target_end = BODY + BODY_SIZE
    registry_overlaps = []
    registry_neighbors = []
    for function in registry.get("functions", []):
        for first, last in function.get("body_ranges", []):
            lo, hi = int(first, 16), int(last, 16) + 1
            if lo < target_end and BODY < hi:
                registry_overlaps.append(dict(entry_va=function.get("entry_va"),
                                              source=function.get("source"), body_range=[first, last]))
            elif hi <= BODY:
                registry_neighbors.append((BODY - hi, dict(entry_va=function.get("entry_va"),
                                                           source=function.get("source"),
                                                           body_range=[first, last], side="preceding")))
            elif lo >= target_end:
                registry_neighbors.append((lo - target_end, dict(entry_va=function.get("entry_va"),
                                                                 source=function.get("source"),
                                                                 body_range=[first, last], side="following")))

    index_neighbors = [item for item in functions
                       if abs(int(item["ranges"][0][0], 16) - BODY) <= 0x100]
    data_references = [item for item in references
                       if DATA_START <= (address(item.get("to_va")) or 0) < DATA_START + DATA_SIZE]
    adjacent_references = [item for item in references
                           if 0x6A5C80 <= (address(item.get("to_va")) or 0) < 0x6A5CC0]
    indexed_body_by_entry = {item["entry_va"]: item for item in functions}
    instruction_by_va = {}
    for entry, function in indexed_body_by_entry.items():
        if not function.get("ranges"):
            continue
        for first, last in function["ranges"]:
            start, end = int(first, 16), int(last, 16)
            for instruction in md.disasm(native.pe_at(pe, start, end - start + 1), start):
                instruction_by_va[f"{instruction.address:08x}"] = instruction
    for reference in data_references:
        instruction = instruction_by_va.get(reference["from_va"].lower())
        reference["instruction"] = (dict(bytes=instruction.bytes.hex(), mnemonic=instruction.mnemonic,
                                         operands=instruction.op_str) if instruction else None)
    target_unresolved_calls = [item for item in unresolved
                               if item.get("function", "").lower() == f"{BODY:08x}"]

    image_base, sections = pe_sections(pe)
    rva = DATA_START - image_base
    section = next(item for item in sections
                   if item["virtual_address"] <= rva and
                   rva + DATA_SIZE <= item["virtual_address"] + item["virtual_size"])
    delta = rva - section["virtual_address"]
    assert section["name"] == ".data" and section["characteristics"] & 0x80000000
    assert delta >= section["raw_size"]
    try:
        native.pe_at(pe, DATA_START, DATA_SIZE)
        file_backed = True
    except ValueError:
        file_backed = False
    assert not file_backed

    source_hits = []
    needles = ("005693e0", "5693e0", "006a5ca0", "006a5ca4", "006a5ca8",
               "6a5ca0", "6a5ca4", "6a5ca8")
    for rel_path in closure:
        path = ROOT / rel_path
        if path.suffix.lower() not in (".cpp", ".hpp", ".h", ".inc"):
            continue
        content = path.read_text(encoding="utf-8", errors="replace").lower()
        hits = [needle for needle in needles if needle in content]
        if hits:
            source_hits.append(dict(path=rel_path, tokens=hits))

    nearest_registry = []
    for side in ("preceding", "following"):
        nearest_registry.extend(row for _, row in sorted(
            (item for item in registry_neighbors if item[1]["side"] == side))[:3])

    data_range_owner_rows = []
    for function in registry.get("functions", []):
        for key, value in function.items():
            if key.lower().endswith(("data_ranges", "owned_data", "data_spans")):
                data_range_owner_rows.append(dict(entry_va=function.get("entry_va"), key=key, value=value))

    result = dict(
        scope="Run585 original static census only; no new data owner/source implementation",
        provenance=dict(original="local/game/Porsche.exe", original_sha256=sha(pe),
                        build="iterations/v2/001-original-recovery/runs/582-driver-state-integration/build-001.json",
                        build_sha256=sha((BUILD_RUN / "build-001.json").read_bytes()),
                        build_config_sha256=sha((BUILD_RUN / "build-config.json").read_bytes()),
                        run584_acceptance_sha256=sha((INTEGRATION_RUN / "acceptance.json").read_bytes()),
                        compiled_source_roots=len(build["compiled_source_roots"]),
                        run584_added_sources=integration["added_sources"],
                        source_closure_roots=len(closure_roots),
                        transitive_source_header_closure_files=len(closure),
                        registry="iterations/v2/001-original-recovery/source/recovered/functions.json",
                        registry_functions=len(registry["functions"]), registry_sha256=sha(registry_bytes),
                        index="research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d",
                        index_metadata=metadata),
        body=dict(va=f"{BODY:08x}", bytes=BODY_SIZE, end_exclusive=f"{target_end:08x}",
                  sha256=sha(body), raw_hex=body.hex(), index_row=fn_row,
                  instructions=[dict(va=f"{ins.address:08x}", bytes=ins.bytes.hex(),
                                     mnemonic=ins.mnemonic, operands=ins.op_str)
                                for ins in instructions],
                  return_sites=[dict(va=f"{ins.address:08x}", bytes=ins.bytes.hex())
                                for ins in instructions if ins.mnemonic.startswith("ret")],
                  raw_eax_semantics="Final EAX is the second slot's release result if called; otherwise it is zero from the second pointer load. The 004b0d70 caller ignores EAX; other caller contexts are listed below."),
        data=dict(va=f"{DATA_START:08x}", bytes=DATA_SIZE,
                  proposed_bounded_fields=[dict(va="006a5ca0", width=4, raw_name="DAT_006a5ca0"),
                                           dict(va="006a5ca4", width=4, raw_name="DAT_006a5ca4"),
                                           dict(va="006a5ca8", width=4, raw_name="DAT_006a5ca8")],
                  section=section, section_delta=f"0x{delta:x}",
                  file_backed=False, raw_file_bytes=None,
                  loader_zero_basis="The full 12-byte span lies inside writable .data VirtualSize and wholly beyond .data SizeOfRawData; PE file-backed mapping rejects this VA span, so the loader supplies zero-filled virtual tail.",
                  raw_index_references=data_references,
                  adjacent_6a5c80_6a5cc0_references=adjacent_references),
        consumers=dict(direct_call_count=len(call_rows), direct_calls=call_contexts,
                       target_body_unresolved_calls=target_unresolved_calls,
                       all_index_data_references_within_span=len(data_references)),
        ownership=dict(source_hits=source_hits,
                       source_hit_interpretation="Only existing frame_pump.hpp declaration and frame_pump.cpp caller contain target function VA. No source file in the complete 582 source/header closure mentions the proposed data addresses.",
                       registry_entry_exists=any(item.get("entry_va", "").lower() == f"{BODY:08x}"
                                                 for item in registry["functions"]),
                       registry_body_overlaps=registry_overlaps,
                       nearest_registry_body_ranges=nearest_registry,
                       nearby_index_functions=index_neighbors,
                       registry_data_range_fields=data_range_owner_rows),
    )
    (RUN / "scope-evidence.json").write_text(json.dumps(result, indent=2) + "\n",
                                               encoding="utf-8", newline="\n")
    print(f"Run585 static scope: roots={len(build['compiled_source_roots'])}, closure={len(closure)}, registry={len(registry['functions'])}, callers={len(call_rows)}, data_refs={len(data_references)}")
    print(f"body={BODY_SIZE}B sha256={sha(body)}; data=[{DATA_START:08x},{DATA_START+DATA_SIZE:08x}) loaderzero={not file_backed}; registry overlaps={len(registry_overlaps)}; source_hits={len(source_hits)}")


if __name__ == "__main__":
    main()
