"""Verify unified FE/render/main aliases and the production arena fill adapter."""
import argparse
import hashlib
import importlib.util
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / "iterations/v2/001-original-recovery/runs/074-application-arena"
SHA = "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39"
BASE, LENGTH = 0x006573E8, 0x3E24
PROBE = ROOT / "local/builds/v2/001-original-recovery/application-arena-074/bin/Release/application_arena_probe.exe"

sys.path.insert(0, str(ROOT / "scripts/research"))
from v2_source_dependencies import source_hashes

spec = importlib.util.spec_from_file_location(
    "verify_application_state", ROOT / "scripts/research/verify-v2-application-state.py")
state_verifier = importlib.util.module_from_spec(spec)
spec.loader.exec_module(state_verifier)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--probe", type=Path, default=PROBE)
    parser.add_argument("--report-dir", type=Path, default=RUN)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(json.loads(line) for line in
        (ROOT / "research/binary-index/static/binaries.jsonl").read_text(encoding="utf-8").splitlines()
        if json.loads(line)["file"] == "Porsche.exe")
    binary = (ROOT / "local/game" / module["path"]).read_bytes()
    if hashlib.sha256(binary).hexdigest() != SHA:
        raise AssertionError("original executable SHA mismatch")

    output = subprocess.run([str(args.probe)], capture_output=True, text=True,
        check=True, timeout=30)
    native = json.loads(output.stdout)
    for key in ("fe_arena_owner_ok", "fe_fegame_target_ok", "fe_racetype_target_ok",
                "main_renderer_aliases_ok", "byte_word_views_ok",
                "signed_word_alias_ok", "string_views_ok", "zero_after_fill",
                "argv_fixture_unchanged", "unknown_span_rejected"):
        if native.get(key) is not True:
            raise AssertionError(f"native arena invariant failed: {key}={native.get(key)!r}")
    if native["span_bytes"] != LENGTH or native["end_exclusive"] != "0065b20c":
        raise AssertionError("native arena span does not match the recovered interval")

    # The original x86 execution guards the exact machine-address span, argv
    # at its adjacent original VA, and both surrounding canary ranges.
    original = state_verifier.original_case(module, binary, 0, 0, 0, LENGTH)
    if bytes.fromhex(native["arena_hex"]) != bytes.fromhex(original["arena_hex"]):
        raise AssertionError("native shared arena bytes differ from original x86 fill")

    compiled = [
        "iterations/v2/001-original-recovery/source/recovered/application_arena_probe.cpp",
        "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_state.cpp",
        "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_globals.cpp",
    ]
    paths = [*compiled,
        "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/fe_tables.inc",
        "scripts/research/export-v2-fe-tables.py",
        "scripts/research/verify-v2-application-state.py",
        "scripts/research/verify-v2-application-arena.py",
        "iterations/v2/001-original-recovery/runs/074-application-arena/CMakeLists.txt",
    ]
    report = {
        "schema": 1,
        "module": "Porsche.exe",
        "sha256": SHA,
        "arena": {"base_va": f"{BASE:08x}", "bytes": f"0x{LENGTH:x}",
                  "end_exclusive": f"{BASE + LENGTH:08x}", "backing": "3977 uint32_t words"},
        "aliases": {
            "fe_table_targets_bound_to_arena": True,
            "application_and_renderer_share_width_height_mode": True,
            "byte_views_share_word_object_representation": True,
            "signed_renderer_words_share_unsigned_backing": True,
            "string_views_have_no_invented_capacity": True,
        },
        "fill": {
            "adapter": "application_main_fill_fe_arena_0053c290",
            "supported_target": f"{BASE:08x}",
            "supported_bytes": f"0x{LENGTH:x}",
            "unsupported_spans_rejected": True,
            "native_full_bytes_equal_original_x86": True,
            "original_prefix_argv_suffix_canaries_unchanged": True,
        },
        "layout_constraints": {
            "argv_va": "0065b20c",
            "argv_outside_arena": True,
            "opaque_gaps_unaliased": True,
            "config_string_va": "00657a84",
            "config_string_extent": None,
        },
        "native_probe": {k: v for k, v in native.items() if k != "arena_hex"},
        "source_sha256": source_hashes(paths, compiled_sources=compiled),
    }
    report["probe_sha256"] = hashlib.sha256(args.probe.read_bytes()).hexdigest()
    (args.report_dir / "verification.json").write_text(json.dumps(report, indent=2) + "\n",
        encoding="utf-8", newline="\n")
    print(json.dumps({"span": report["arena"], "aliases": report["aliases"],
        "native_full_bytes_equal_original_x86": True,
        "original_prefix_argv_suffix_canaries_unchanged": True,
        "report": str(args.report_dir / "verification.json")}, sort_keys=True))


if __name__ == "__main__":
    main()
