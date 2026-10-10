"""Cross-check Run102 unresolved C++ symbols against recovered bodies and index entries."""
from __future__ import annotations

import hashlib
import json
import re
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
BASELINE = ROOT / "iterations/v2/001-original-recovery/runs/102-original-game-link/link-report.json"
CURRENT_LINK = ROOT / "iterations/v2/001-original-recovery/runs/098-startup-integration/original-game-link/link-report.json"
REGISTRY = ROOT / "iterations/v2/001-original-recovery/source/recovered/functions.json"
INDEX = ROOT / "research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d"
DISASM = ROOT / "research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm"


def read_json(path: Path):
    return json.loads(path.read_text(encoding="utf-8"))


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> None:
    baseline = read_json(BASELINE)
    current_link = read_json(CURRENT_LINK)
    functions = read_json(REGISTRY)["functions"]
    registry_by_va = defaultdict(list)
    for entry in functions:
        registry_by_va[entry.get("entry_va", "").lower()].append(entry)
    index_functions = {
        entry.get("entry_va", "").lower(): entry
        for entry in (json.loads(line) for line in (INDEX / "functions.jsonl").read_text(encoding="utf-8").splitlines())
    }
    index_calls = [json.loads(line) for line in (INDEX / "calls.jsonl").read_text(encoding="utf-8").splitlines()]

    groups = defaultdict(list)
    for item in baseline["unresolved_frontier"]:
        match = re.search(r"_([0-9a-fA-F]{8})@porsche@@", item["symbol"])
        if match:
            groups[match.group(1).lower()].append(item)

    duplicate_groups = []
    for va, entries in sorted(groups.items()):
        if len(entries) < 2:
            continue
        indexed = index_functions.get(va)
        xrefs = [call for call in index_calls if call.get("to_va", "").lower() == va]
        callers = Counter(call.get("from_function", "<unresolved>") for call in xrefs)
        duplicate_groups.append({
            "va": va,
            "unresolved_symbol_count": len(entries),
            "symbols": [entry["symbol"] for entry in entries],
            "decorated_abi_encodings": sorted({entry["symbol"].split("@porsche@@", 1)[1] for entry in entries}),
            "original_index_entry": indexed,
            "original_direct_call_xref_count": len(xrefs),
            "top_indexed_callers": [{"va": va, "count": count} for va, count in callers.most_common(8)],
            "recovery_registry_entries": registry_by_va.get(va, []),
        })

    registry_hits = []
    no_registry = []
    non_entry = []
    for va, entries in sorted(groups.items()):
        if registry_by_va.get(va):
            registry_hits.append({"va": va, "symbols": [item["symbol"] for item in entries],
                                  "registry": registry_by_va[va]})
        elif va not in index_functions:
            non_entry.append({"va": va, "symbols": [item["symbol"] for item in entries]})
        else:
            no_registry.append({"va": va, "symbol_count": len(entries),
                                "original_entry": index_functions[va].get("name"),
                                "body_bytes": index_functions[va].get("body_bytes")})

    xrefs_557370 = [call for call in index_calls if call.get("to_va", "").lower() == "00557370"]
    callers_557370 = [
        {"call_va": call.get("from_va"), "caller_va": call.get("from_function"), "type": call.get("type")}
        for call in xrefs_557370
    ]
    function_5a0fbf = index_functions.get("005a0fbf")
    xrefs_5a0fbf = [call for call in index_calls if call.get("to_va", "").lower() == "005a0fbf"]
    function_5a246e = index_functions.get("005a246e")
    xrefs_5a246e = [call for call in index_calls if call.get("to_va", "").lower() == "005a246e"]
    baseline_names = {item["symbol"] for item in baseline["unresolved_frontier"]}
    current_names = {item["symbol"] for item in current_link["unresolved_frontier"]}

    highest_callers = sorted(baseline["reachable_caller_counts"].items(), key=lambda pair: (-pair[1], pair[0]))[:16]
    evidence_paths = [
        BASELINE,
        REGISTRY,
        INDEX / "functions.jsonl",
        INDEX / "calls.jsonl",
        INDEX / "references.jsonl",
        DISASM,
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_shutdown.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/include/porsche/window_shutdown.hpp",
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/frame_pump.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/include/porsche/frame_pump.hpp",
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/engine_service_427a60.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/include/porsche/engine_service_427a60.hpp",
        ROOT / "iterations/v2/001-original-recovery/source/platform/recovered_links.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/recovered/sources.cmake",
        ROOT / "iterations/v2/001-original-recovery/source/include/porsche/startup_sequence.hpp",
        ROOT / "iterations/v2/001-original-recovery/source/include/porsche/splash_progress.hpp",
        ROOT / "iterations/v2/001-original-recovery/runs/101-frame-pump/verification.json",
        ROOT / "iterations/v2/001-original-recovery/runs/103-engine-service/verification.json",
        CURRENT_LINK,
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/resource_paths.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/include/porsche/resource_paths.hpp",
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/input_state.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/include/porsche/input_state.hpp",
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/movie_header.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/include/porsche/movie_header.hpp",
        ROOT / "iterations/v2/001-original-recovery/runs/090-native-window-integration/window-shutdown/verification.json",
        RUN / "audit.py",
        RUN / "README.md",
    ]

    report = {
        "schema": 1,
        "scope": "Read-only audit of the Run102 captured link frontier; Run098 retry is deliberately separate.",
        "baseline": {
            "report": BASELINE.relative_to(ROOT).as_posix(),
            "report_sha256": sha256(BASELINE),
            "original_module": "Porsche.exe",
            "original_sha256": "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39",
            "unresolved_symbols": baseline["unresolved_symbol_count"],
            "unresolved_references": baseline["unresolved_reference_count"],
            "va_named_symbol_count": baseline["unresolved_counts_by_category"].get("va_named_original_callable", 0),
            "semantic_boundary_count": baseline["unresolved_counts_by_category"].get("semantic_service_or_vtable_boundary", 0),
            "high_reference_callers": [{"caller": name, "references": count} for name, count in highest_callers],
        },
        "cross_reference_counts": {
            "unique_va_suffixes": len(groups),
            "duplicate_va_groups": len(duplicate_groups),
            "va_suffixes_matching_recovery_registry": len(registry_hits),
            "va_suffixes_with_index_function_but_no_recovery_registry_entry": len(no_registry),
            "va_suffixes_without_index_function_entry": len(non_entry),
        },
        "current_098_crosscheck": {
            "report": CURRENT_LINK.relative_to(ROOT).as_posix(),
            "report_sha256": sha256(CURRENT_LINK),
            "status": current_link["status"],
            "unresolved_symbols": current_link["unresolved_symbol_count"],
            "baseline_symbols_absent_now": sorted(baseline_names - current_names),
            "new_symbols_not_in_baseline": sorted(current_names - baseline_names),
            "evidence_limit": "A disappeared linker name shows the current link object resolves it; it does not prove full game behavior or close its callees.",
        },
        "proven_recovered_body_bridge_candidates": [
            {
                "baseline_unresolved_symbol": "?startup_sequence_call_00427a60@porsche@@YAXXZ",
                "native_type": "void __cdecl startup_sequence_call_00427a60(void)",
                "canonical_recovered_body": "void __cdecl engine_service_00427a60(void)",
                "adapter_source": "iterations/v2/001-original-recovery/source/platform/recovered_links.cpp",
                "body_source": "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/engine_service_427a60.cpp",
                "registry_status": "native-differential-verified at original entry 00427a60 (Run103)",
                "original_index_xref": "004b67d1 -> 00427a60, the startup sequence's single indexed incoming call",
                "abi_evidence": "Both names are global cdecl void(void); Run103 records no incoming parameters, caller-owned cleanup 0x2c for its five cdecl callees, and matched x86/native call order and stack restoration.",
                "current_098_link": "Resolved after the adapter was added; its own formatter/file/resource callees remain unresolved.",
            },
            {
                "baseline_unresolved_symbols": [
                    "?startup_sequence_call_004b0d70@porsche@@YAXXZ",
                    "?splash_progress_frame_begin_004b0d70@porsche@@YAXXZ",
                ],
                "native_type": "void __cdecl(void)",
                "canonical_recovered_body": "void __cdecl frame_pump_004b0d70(void)",
                "adapter_source": "iterations/v2/001-original-recovery/source/platform/recovered_links.cpp",
                "body_source": "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/frame_pump.cpp",
                "registry_status": "native-differential-verified at original entry 004b0d70 (Run101)",
                "original_index_evidence": "The 318-byte original function entry has indexed callers from 004b67b0 and 004a4a70; Run101 compares its complete state, ordered boundaries and x86 stack restoration.",
                "current_098_link": "Both alternate spellings disappeared from the current unresolved set after the exact no-argument cdecl adapters were added.",
            },
            {
            "unresolved_symbol": "?render_depth_failure_00557370@porsche@@YAXXZ",
            "native_type": "void __cdecl render_depth_failure_00557370(void)",
            "canonical_recovered_body": "void __cdecl window_shutdown_process_exit_00557370(void)",
            "canonical_body_source": "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_shutdown.cpp",
            "registry_status": "native-differential-verified at original entry 00557370",
            "original_index_xrefs": callers_557370,
            "abi_and_body_evidence": [
                "Both C++ declarations are cdecl void() with no stack arguments.",
                "Original index records the render caller at 004678a5 -> 00557370; original body at 00557370 is PUSH 0; CALL 005a246e.",
                "Run090 verification records 00557370 as a full function and 005a246e as the terminal boundary.",
            ],
            "limitation": "This alias can map the already recovered 00557370 body, but its terminal 005a246e boundary still needs one non-returning production implementation; no game-link success follows from this alias alone.",
            "current_098_link": "Still unresolved; this exact bridge has not yet been added.",
            },
        ],
        "same_va_but_not_recovered_body_bridges": [
            {
                "va": "0059d650",
                "link_symbol": "resource_invalid_module_path_0059d650",
                "existing_entry": "resource_paths_0059d650(void) -> int32",
                "classification": "internal branch placeholder, not a distinct function entry",
                "evidence": "Index/function registry show 0059d650 is the resource_paths entry; original ASM at 0059d687 branches to 0059d6c9 within that body. Current source invents a same-entry call only for slash-not-found. Forwarding would recurse; recover the branch.",
            },
            {
                "va": "00532e10",
                "link_symbols": ["input_unrecovered_mode_00532e10", "input_negative_index_00532e10", "input_unmapped_index_00532e10"],
                "existing_entry": "fe_input_getstate_00532e10(uint32 index, uint32 mode) -> void*",
                "classification": "unrecovered intra-function branches, not function entries",
                "evidence": "Registry marks 00532e10 partial and lists invalid-mode/negative/unmapped branches. Original ASM has one entry and an internal jump table; the link symbols are source-side recording boundaries. Do not forward them back to entry (recursion).",
            },
            {
                "va": "00534480",
                "link_symbols": ["render_display_texture_bind_00534480(void*)", "splash_progress_bind_texture_00534480(uint32)"],
                "existing_entry": "00534480 partial window_shutdown consumer",
                "classification": "real entry, but its observed null-descriptor branch is the only recovered path",
                "evidence": "Registry and Run090 verify 00534480 only through the null-input path from 00534550; registry lists non-null setup as unrecovered. Original callers at 00467ca9 and 004a4b98 push live texture values. Return/parameter spellings conflict; recover entry ABI and non-null behavior before bridging.",
            },
            {
                "va": "004dc850",
                "link_symbol": "game_setup_movie_004dc850(void*, uint32*, uint32, uint32, uint32)",
                "existing_entry": "movie_header_prepare_004dc850 partial MAD-header helper",
                "classification": "partial internal branch, explicitly not the original entry ABI",
                "evidence": "Registry boundary says only the accepted MAD header through renderer 004dc180 is recovered and not a replacement for original function ABI; ASM entry 004dc850 starts the much larger stream/playback function.",
            },
        ],
        "unimplemented_original_entry_alias_families": [
            {
                "va": "005a0fbf",
                "symbols": [item["symbol"] for item in groups.get("005a0fbf", [])],
                "original_index_entry": function_5a0fbf,
                "direct_call_xref_count": len(xrefs_5a0fbf),
                "candidate_abi": "int __cdecl format_output_005a0fbf(char* destination, const char* format, ...)",
                "evidence": "Original ASM uses EBP+8 as destination, EBP+12 as format, EBP+16 as the first variadic slot; forwards its varargs list and returns callee EAX; plain RET gives caller cleanup. Eleven source spellings currently disagree in fixed arity and/or parameter spelling.",
                "classification": "one known original entry with an unrecovered native body/ABI-normalization task, not eleven distinct missing original functions",
                "next_trace": "Confirm format pointer and formatter target semantics at 005a4371/005a4259, then implement one exact varargs entry and rebind consumers.",
            },
            {
                "va": "005a246e",
                "symbols": [item["symbol"] for item in groups.get("005a246e", [])],
                "original_index_entry": function_5a246e,
                "direct_call_xref_count": len(xrefs_5a246e),
                "candidate_abi": "void __cdecl terminal_exit_005a246e(uint32_t code)",
                "evidence": "All three source aliases encode void cdecl(DWORD). Original entry reads stack[+4], pushes three arguments, calls 005a2490, cleans 12 bytes, then RET; original index marks the function noreturn. Current native code keeps it as an unresolved typed boundary.",
                "classification": "ABI-equivalent aliases to one unrecovered terminal body; canonicalizing names alone does not implement it",
                "next_trace": "Recover 005a2490/CRT termination contract; use one non-returning production owner and route the three declarations through it.",
            },
        ],
        "duplicate_va_groups": duplicate_groups,
        "other_registry_va_matches": registry_hits,
        "evidence_sha256": {path.relative_to(ROOT).as_posix(): sha256(path) for path in evidence_paths},
        "conclusion": "Three bridge groups cover four baseline symbols with matching recovered bodies. Three symbols in the 00427a60/004b0d70 groups are resolved in the current Run098 link; the 00557370 alias remains unresolved and its terminal exit callee is still open. Other registry collisions are partial or internal-branch placeholders. Several repeated VAs represent one original code entry or indirect data slot but lack a recovered native implementation; they are ABI-normalization/recovery work, not safe aliases. The game remains unlinked and unverified.",
    }
    (RUN / "report.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "baseline_status": baseline["status"],
        "unresolved": baseline["unresolved_symbol_count"],
        "unique_va_suffixes": len(groups),
        "duplicate_va_groups": len(duplicate_groups),
        "registry_hits": len(registry_hits),
        "report": str(RUN / "report.json"),
    }))


if __name__ == "__main__":
    main()
