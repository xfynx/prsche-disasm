"""Generate the bounded Run583 native comparison config from checked PE evidence."""
from pathlib import Path
import hashlib, importlib.util, json

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
evidence = json.loads((RUN / "scope-evidence.json").read_bytes())
supplement = json.loads((RUN / "original-index-supplement.json").read_bytes())
base = json.loads((RUN.parent / "581-render-driver-state" / "native-config.json").read_bytes())
spec = importlib.util.spec_from_file_location("native", ROOT / "scripts/research/verify-v2-native-batch.py")
native = importlib.util.module_from_spec(spec); spec.loader.exec_module(native)
raw = (ROOT / "local/game/Porsche.exe").read_bytes()
assert hashlib.sha256(raw).hexdigest() == evidence["provenance"]["sha256"]
body = bytes.fromhex(evidence["bodies"]["00540500"]["raw_hex"])
assert len(body) == 71 and hashlib.sha256(body).hexdigest() == supplement["sha256"]
scale = native.pe_at(raw, 0x5b3e10, 4)
assert scale.hex() == "00000038"
run_rel = RUN.relative_to(ROOT).as_posix()
source = run_rel + "/render_driver_x87_583.cpp"
explicit_includes=[run_rel, "iterations/v2/001-original-recovery/runs/581-render-driver-state",
    "iterations/v2/001-original-recovery/runs/515-render-driver-constructors",
    "iterations/v2/001-original-recovery/runs/522-audio-stream-transform"]
current_build=json.loads((RUN.parent/"582-driver-state-integration"/"build-config.json").read_bytes())
include_dirs=list(dict.fromkeys([*explicit_includes,*current_build["source_include_dirs"]]))
config = dict(base)
config.update(run=583, experiment="local/experiments/v2-render-driver-x87-583",
    sources=[source],
    fixture=run_rel + "/native-fixture.cpp.in",
    include_dirs=include_dirs,
    headers=[run_rel + "/scope-evidence.json", run_rel + "/original-index-supplement.json",
        run_rel + "/scope-inspect.py", run_rel + "/prepare.py", run_rel + "/render_driver_x87_583.cpp",
        run_rel + "/render_driver_x87_583.hpp", run_rel + "/native-fixture.cpp.in"],
    original_bodies=[dict(va="00540500", bytes=71, sha256=supplement["sha256"], token="@BODY_00540500@"),
        dict(va="005b3e10", bytes=4, sha256=hashlib.sha256(scale).hexdigest(), token="@RAW_S16_SCALE@", kind="original-data-witness")],
    pass_marker="render_driver_x87_original_x86_vs_cpp=PASS", timeout_seconds=240)
config["mutations"] = [
    dict(name="wrapped-add-to-sub", source=source, old="add eax, ecx", new="sub eax, ecx", expected_exit=1, failure_marker="divergence"),
    dict(name="invert-context-branch", source=source, old="jz set_driver_state", new="jnz set_driver_state", expected_exit=1, failure_marker="divergence"),
    dict(name="omit-caller-slot-writeback", source=source, old="mov dword ptr [esp + 8], eax", new="nop", expected_exit=1, failure_marker="divergence"),
    dict(name="omit-original-fmul", source=source, old="fmul audio_stream_s16_scale_005b3e10", new="nop", expected_exit=1, failure_marker="divergence")]
(RUN / "native-config.json").write_text(json.dumps(config, indent=2) + "\n", encoding="utf-8", newline="\n")
print(json.dumps({"run": 583, "body_bytes": len(body), "body_sha256": supplement["sha256"], "scale_hex": scale.hex(), "controls": len(config["mutations"])}))
