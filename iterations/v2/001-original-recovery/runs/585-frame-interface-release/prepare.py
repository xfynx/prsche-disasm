"""Prepare the scratch Run585 native config from pinned scope evidence."""
from pathlib import Path
import json

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
REL = RUN.relative_to(ROOT).as_posix()
evidence = json.loads((RUN / "scope-evidence.json").read_bytes())
base = json.loads((RUN.parent / "583-render-driver-x87" / "native-config.json").read_bytes())
config = dict(base)
config.update(
    run=585,
    experiment="local/experiments/v2-frame-interface-release-585",
    sources=[REL + "/frame_interface_release_585.cpp"],
    fixture=REL + "/native-fixture.cpp.in",
    include_dirs=list(dict.fromkeys([REL, *base["include_dirs"]])),
    headers=[REL + "/scope-evidence.json", REL + "/scope-inspect.py",
             REL + "/preflight.json", REL + "/prepare.py",
             REL + "/frame_interface_release_585.cpp",
             REL + "/frame_interface_release_585.hpp",
             REL + "/native-fixture.cpp.in"],
    original_bodies=[dict(va="005693e0", bytes=53,
                          sha256=evidence["body"]["sha256"], token="@BODY_005693E0@")],
    pass_marker="frame_interface_release_original_x86_vs_cpp=PASS",
    timeout_seconds=180,
)
config["mutations"] = [
    dict(name="omit-first-slot-clear", source=REL + "/frame_interface_release_585.cpp",
         old="mov frame_interface_first_006a5ca8, esi", new="nop",
         expected_exit=1, failure_marker="divergence"),
    dict(name="skip-second-slot-reload", source=REL + "/frame_interface_release_585.cpp",
         old="mov eax, frame_interface_second_006a5ca4", new="mov eax, frame_interface_first_006a5ca8",
         expected_exit=1, failure_marker="divergence"),
    dict(name="omit-second-slot-clear", source=REL + "/frame_interface_release_585.cpp",
         old="mov frame_interface_second_006a5ca4, esi", new="nop",
         expected_exit=1, failure_marker="divergence"),
    dict(name="omit-final-flag-clear", source=REL + "/frame_interface_release_585.cpp",
         old="mov frame_interface_final_flag_006a5ca0, esi", new="nop",
         expected_exit=1, failure_marker="divergence"),
]
(RUN / "native-config.json").write_text(json.dumps(config, indent=2) + "\n",
                                         encoding="utf-8", newline="\n")
print(json.dumps({"run": 585, "function": "005693e0", "body_bytes": 53,
                  "body_sha256": evidence["body"]["sha256"],
                  "cases": 8, "mutation_controls": len(config["mutations"])}))
