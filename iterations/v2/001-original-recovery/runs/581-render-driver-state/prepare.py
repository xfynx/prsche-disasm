"""Prepare the Run581 shared native original-x86 comparison inputs."""
from pathlib import Path
import hashlib
import importlib.util
import json

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
scope = json.loads((RUN / "scope-evidence.json").read_bytes())
base = json.loads((RUN.parent / "572-startup-service-lifecycle" / "native-config.json").read_bytes())
native_spec = importlib.util.spec_from_file_location(
    "native_batch", ROOT / "scripts/research/verify-v2-native-batch.py")
native = importlib.util.module_from_spec(native_spec)
native_spec.loader.exec_module(native)
pe = ROOT / "local/game/Porsche.exe"
raw = pe.read_bytes()
assert hashlib.sha256(raw).hexdigest() == scope["provenance"]["module_sha256"]

bodies = []
for va, token in (("00538af0", "@BODY_00538AF0@"),
                  ("00537850", "@BODY_00537850@"),
                  ("005405c0", "@BODY_005405C0@"),
                  ("00540550", "@BODY_00540550@"),
                  ("00540590", "@BODY_00540590@")):
    row = scope["bodies"][va]
    body = bytes.fromhex(row["raw_hex"])
    assert hashlib.sha256(body).hexdigest() == row["sha256"]
    bodies.append(dict(va=va, bytes=len(body), sha256=row["sha256"], token=token))
packet_va = 0x5ded30
packet = native.pe_at(raw, packet_va, 72)
bodies.append(dict(va=f"{packet_va:08x}", bytes=len(packet),
                   sha256=hashlib.sha256(packet).hexdigest(),
                   token="@RAW_STATE_PACKET@", kind="original-data-witness"))

run_rel = RUN.relative_to(ROOT).as_posix()
src = run_rel + "/render_driver_state_581.cpp"
no_op = "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/startup_service_516950.cpp"
fixture = run_rel + "/native-fixture.cpp.in"
headers = [run_rel + "/scope-evidence.json", run_rel + "/original-index-supplement.json",
           run_rel + "/scope-inspect.py", run_rel + "/prepare.py",
           run_rel + "/render_driver_state_581.hpp"]
cfg = dict(base)
cfg.update(run=581, experiment="local/experiments/v2-render-driver-state-581",
           sources=[src, no_op], fixture=fixture,
           include_dirs=[run_rel, "iterations/v2/001-original-recovery/runs/523-render-resource-buffer",
                         "iterations/v2/001-original-recovery/source/include"],
           headers=headers, original_bodies=bodies,
           pass_marker="render_driver_state_original_x86_vs_cpp=PASS",
           timeout_seconds=180)
cfg["extra_libraries"] = list(dict.fromkeys([*cfg.get("extra_libraries", []), "uuid.lib"]))
cfg["mutations"] = [
    dict(name="omit-rejected-state-rollback", source=src,
         old="(void)render_buffer_state_00540480(key, previous);",
         new="/* omitted original rejected-state rollback */",
         expected_exit=1, failure_marker="divergence"),
    dict(name="omit-final-callback", source=src,
         old="for (U i = 0; i != 6; ++i)", new="for (U i = 0; i != 5; ++i)",
         expected_exit=1, failure_marker="divergence"),
    dict(name="invert-movie-enabled-branch", source=src,
         old="if (enabled == 1)", new="if (enabled == 0)",
         expected_exit=1, failure_marker="divergence"),
    dict(name="remove-550-special-branch", source=src,
         old="if (value == 0xffffffffu)", new="if (value != 0xffffffffu)",
         expected_exit=1, failure_marker="divergence")]
(RUN / "native-config.json").write_text(json.dumps(cfg, indent=2) + "\n",
                                        encoding="utf-8", newline="\n")
print("Prepared Run581 native config: five raw bodies, one 72-byte data witness, four controls")
