"""Generate the Run579 comparator oracle from the accepted Run577 harness."""
from pathlib import Path
import hashlib
import importlib.util
import json
import re
import sys

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
PREV = RUN.parent / "577-render-texture-transfer"
EXP = ROOT / "local/experiments/v2-texture-format-comparator-579"
EXP.mkdir(parents=True, exist_ok=True)

spec = importlib.util.spec_from_file_location("native", ROOT / "scripts/research/verify-v2-native-batch.py")
native = importlib.util.module_from_spec(spec)
spec.loader.exec_module(native)
cfg = json.loads((PREV / "native-config.json").read_bytes())
raw = (ROOT / cfg["original_pe"]).read_bytes()
assert hashlib.sha256(raw).hexdigest() == cfg["original_sha256"]

def data_token(va, size, name):
    blob = native.pe_at(raw, va, size)
    token = "@" + name + "@"
    cfg["original_bodies"].append({
        "va": f"{va:08x}", "bytes": size,
        "sha256": hashlib.sha256(blob).hexdigest(), "token": token,
        "kind": "original-data-witness"
    })
    return token

body_rows = {x["va"]: x for x in json.loads((RUN / "data-evidence.json").read_bytes())["functions"]}
body_rows = {k.lower(): v for k, v in body_rows.items()}
bodies = []
for va in (0x554310, 0x554530):
    row = body_rows[f"{va:08x}"]
    blob = bytes.fromhex(row["raw"]["raw"])
    assert len(blob) == row["body_bytes"] and hashlib.sha256(blob).hexdigest()
    token = f"@BODY_{va:08X}@"
    cfg["original_bodies"].append({
        "va": f"{va:08x}", "bytes": len(blob),
        "sha256": hashlib.sha256(blob).hexdigest(), "token": token
    })
    bodies.append((va, blob))

mdspec = importlib.util.spec_from_file_location("capstone", ROOT / "local/tools/python-unicorn/capstone/__init__.py")
sys.path.insert(0, str(ROOT / "local/tools/python-unicorn"))
import capstone
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
calls = {0x554530: "code[6]"}
absolute = {
    0x5def98: "render_texture_format_preference_table_005def98",
    0x5df15c: "packed_format_flags",
    0x5df0a8: "render_texture_palette_preference_table_005df0a8",
    0x5df0cc: "packed_palette_flags",
    0x6a3a54: "&render_texture_driver_info_006a3a54",
    0x6bd984: "&raw_get_import",
    0x6bd97c: "&raw_set_import",
}
chunks, patches = [], []
for slot, (va, blob) in enumerate(bodies, start=5):
    chunks.append(f"const B body_{va:08x}[]={{@BODY_{va:08X}@}};code[{slot}]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[{slot}]!=nullptr,\"raw comparator allocation\");memcpy(code[{slot}],body_{va:08x},sizeof body_{va:08x});")
    for ins in md.disasm(blob, va):
        off = ins.address - va
        op = ins.op_str
        if ins.mnemonic == "call" and op.startswith("0x"):
            target = int(op, 16)
            dest = calls[target]
            patches.append(f"require(word(code[{slot}],{off+1})==0x{int.from_bytes(ins.bytes[1:], 'little'):08x},\"raw comparator call\");put(code[{slot}],{off+1},ptr({dest})-ptr(code[{slot}]+{off+5}));")
        for addr, dest in absolute.items():
            if not re.search(r"\b" + hex(addr) + r"\b", op):
                continue
            needle = addr.to_bytes(4, "little")
            assert ins.bytes.count(needle) == 1, (hex(va), ins.address, hex(addr))
            at = off + ins.bytes.index(needle)
            patches.append(f"require(word(code[{slot}],{at})==0x{addr:08x},\"raw comparator data\");put(code[{slot}],{at},ptr({dest}));")

fixture = (PREV / "native-fixture.cpp.in").read_text(encoding="utf-8")
fixture = fixture.replace('#include "texture_children_577.hpp"', '#include "texture_children_577.hpp"\n#include "render_format_comparator_579.hpp"\n#include "format_preferences_579.hpp"\n#include "porsche/render_settings.hpp"')
fixture = fixture.replace("static B* code[5]", "static B* code[7]")
fixture = fixture.replace("static Arena arena;static B raw_format_table[280];", "static Arena arena;static B raw_format_table[280];static B packed_format_flags[360],packed_palette_flags[144];static U raw_get_import,raw_set_import,state_value,state_sets,state_gets,comparator_mutation;")
fixture = fixture.replace("allocator_calls;};", "allocator_calls,state_value,state_sets,state_gets;};")
fixture = fixture.replace("s.allocator_calls=allocator_calls;", "s.allocator_calls=allocator_calls;s.state_value=state_value;s.state_sets=state_sets;s.state_gets=state_gets;")
fixture = fixture.replace("s.comparator=ptr(reinterpret_cast<const void*>(render_texture_comparator_005df2c8));", "s.comparator=ptr(reinterpret_cast<const void*>(render_texture_comparator_005df2c8));if(s.comparator==ptr(code[5])||s.comparator==ptr(reinterpret_cast<const void*>(&render_texture_compare_00554310)))s.comparator=0x00554310u;")

# Replace the earlier mock comparator with a separate test-only callback. The
# actual selector continues to use that mock in the unchanged Run577 scenarios.
def remove_function(text, signature):
    start = text.index(signature)
    brace = text.index("{", start)
    depth, end = 1, brace + 1
    while depth:
        depth += (text[end] == "{") - (text[end] == "}")
        end += 1
    return text[:start] + text[end:]

fixture = remove_function(fixture, "std::int32_t __cdecl render_texture_compare_00554310(U fmt")
fixture = remove_function(fixture, "void __stdcall window_shutdown_display_callback_006bd9b0(U)")
fixture = fixture.replace("render_texture_comparator_005df2c8=render_texture_compare_00554310;", "render_texture_comparator_005df2c8=comparator_stub;")
fixture = fixture.replace("static void transfer_init(){", "static void comparator_init();\nstatic void comparator_run();\nstatic std::int32_t __cdecl comparator_stub(U fmt,U pal,U type,U p){event(0x554310,{fmt,pal,type,p});++selector_calls;if((transfer_flags&2)&&selector_calls==1)render_texture_driver_info_006a3a54=reinterpret_cast<U*>(arena.info[1]);return (transfer_flags&1)?-7:static_cast<std::int32_t>(type*10u+p);}\nstatic void transfer_init(){")
fixture = fixture.replace("transfer_init();precision=2;", "comparator_init();transfer_init();precision=2;")
fixture = fixture.replace("__asm fninit\n printf(\"render_texture_transfer_original_x86_vs_cpp=PASS", "comparator_run();\n __asm fninit\n printf(\"render_texture_transfer_original_x86_vs_cpp=PASS")
fixture = fixture.replace('printf("render_texture_transfer_original_x86_vs_cpp=PASS cases=%u events=%u\\n",cases,events_total);return 0;', 'printf("render_texture_transfer_original_x86_vs_cpp=PASS cases=%u events=%u\\n",cases,events_total);printf("render_texture_format_comparator_original_x86_vs_cpp=PASS cases=%u events=%u\\n",comparator_cases_579,comparator_events_579);return 0;')
fixture = fixture.replace("@BODY_00555780@", "@BODY_00555780@")

frag = (RUN / "fixture-comparator.inc").read_text(encoding="utf-8")
frag = frag.replace("@RAW_COMPARATOR_BODIES@", "\n".join(chunks)).replace("@RAW_COMPARATOR_PATCHES@", "\n".join(patches))
frag = frag.replace("@RAW_FORMAT_PAYLOAD@", data_token(0x5dedcc, 460, "RAW_FORMAT_PAYLOAD"))
frag = frag.replace("@RAW_PALETTE_PAYLOAD@", data_token(0x5defe0, 200, "RAW_PALETTE_PAYLOAD"))
frag = frag.replace("@RAW_FORMAT_POINTERS@", data_token(0x5def98, 72, "RAW_FORMAT_POINTERS"))
frag = frag.replace("@RAW_PALETTE_POINTERS@", data_token(0x5df0a8, 36, "RAW_PALETTE_POINTERS"))
frag = frag.replace("@RAW_FORMAT_FLAGS@", data_token(0x5df15c, 360, "RAW_FORMAT_FLAGS"))
frag = frag.replace("@RAW_PALETTE_FLAGS@", data_token(0x5df0cc, 144, "RAW_PALETTE_FLAGS"))
marker = "static void transfer_init(){"
fixture = fixture.replace(marker, frag + "\n" + marker)
fixture = fixture.replace("@BODY_00554310@", "@BODY_00554310@").replace("@BODY_00554530@", "@BODY_00554530@")
(RUN / "native-fixture.cpp.in").write_text(fixture, encoding="utf-8", newline="\n")

cfg.update(run=579, experiment="local/experiments/v2-texture-format-comparator-579",
           fixture=(RUN / "native-fixture.cpp.in").relative_to(ROOT).as_posix(),
           pass_marker="render_texture_format_comparator_original_x86_vs_cpp=PASS", timeout_seconds=300)
cfg["sources"] = [
    (RUN / "render_format_comparator_579.cpp").relative_to(ROOT).as_posix(),
    (RUN / "format_preferences_579.cpp").relative_to(ROOT).as_posix(),
    "iterations/v2/001-original-recovery/runs/359-render-settings-bindings/render_settings_binding.cpp",
    *cfg["sources"]
]
cfg["include_dirs"] = list(dict.fromkeys([(RUN).relative_to(ROOT).as_posix(), *cfg["include_dirs"]]))
cfg["headers"] = [
    (RUN / "PLAN.md").relative_to(ROOT).as_posix(),
    (RUN / "data-evidence.json").relative_to(ROOT).as_posix(),
    (RUN / "data-scope.py").relative_to(ROOT).as_posix(),
    (RUN / "render_format_comparator_579.cpp").relative_to(ROOT).as_posix(),
    (RUN / "render_format_comparator_579.hpp").relative_to(ROOT).as_posix(),
    (RUN / "format_preferences_579.cpp").relative_to(ROOT).as_posix(),
    (RUN / "format_preferences_579.hpp").relative_to(ROOT).as_posix(),
    (RUN / "prepare.py").relative_to(ROOT).as_posix(),
    (RUN / "fixture-comparator.inc").relative_to(ROOT).as_posix(),
    *cfg["headers"]
]
data_witnesses = [x for x in cfg["original_bodies"] if x.get("kind") == "original-data-witness" and x.get("va") in {"005dedcc", "005defe0", "005def98", "005df0a8", "005df15c", "005df0cc"}]
cfg["original_bodies"] = [x for x in cfg["original_bodies"] if x.get("va") in {"00554960", "00554d70", "00554820", "005556b0", "00555780", "005df16c", "005df2c8"}] + data_witnesses
for va, blob in bodies:
    cfg["original_bodies"].append({"va": f"{va:08x}", "bytes": len(blob), "sha256": hashlib.sha256(blob).hexdigest(), "token": f"@BODY_{va:08X}@"})
source = (RUN / "render_format_comparator_579.cpp").relative_to(ROOT).as_posix()
cfg["mutations"] = [
    {"name":"missing-preference-penalty", "source":source, "old":"return found ? score : score + 20u;", "new":"return found ? score : score;", "expected_exit":1, "failure_marker":"divergence"},
    {"name":"duplicate-preference-accumulation", "source":source, "old":"score += rank;", "new":"score = rank;", "expected_exit":1, "failure_marker":"divergence"},
    {"name":"source-bit8-gate", "source":source, "old":"(source & 0x100u) == 0", "new":"(source & 0x100u) != 0", "expected_exit":1, "failure_marker":"divergence"},
    {"name":"quality-capability-penalty", "source":source, "old":"if ((capability(0x30, destination) & 1u) != 1u)\n        score += 20;", "new":"if (false)\n        score += 20;", "expected_exit":1, "failure_marker":"divergence"},
    {"name":"indexed-early-reject", "source":source, "old":"if (input_palette == 0 || (destination_indexed && destination_palette == 0))\n            return 10000;", "new":"if (input_palette == 0 || (destination_indexed && destination_palette == 0))\n            return 0;", "expected_exit":1, "failure_marker":"divergence"},
    {"name":"stateprobe-restore-old-value", "source":source, "old":"(void)render_settings_set_state_006bd97c(10, previous);", "new":"(void)render_settings_set_state_006bd97c(10, 0);", "expected_exit":1, "failure_marker":"divergence"},
    {"name":"stateprobe-first-set-eax", "source":source, "old":"return result;", "new":"return previous;", "expected_exit":1, "failure_marker":"divergence"}
]
for item in cfg["mutations"]:
    assert (ROOT / item["source"]).read_text(encoding="utf-8").count(item["old"]) == 1, item["name"]
(RUN / "native-config.json").write_text(json.dumps(cfg, indent=2) + "\n", encoding="utf-8", newline="\n")
print("Run579 fixture generated: original comparator/state probe, PE table witnesses, shared controls retained")
