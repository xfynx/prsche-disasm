# Run 783: Sim & Audio Teardown / Registration Leaves (`004a4760`, `004ae470`, `004b04d0`, `004ad4d0`, `005610e0`)

## Scope
Recovers five additive sim/audio teardown and registration functions, closing four unresolved `Run691` frontier boundaries (`004a4760`, `004ae470`, `004b04d0`, `004ad4d0`) plus `audio_device_register_callback_005610e0` with zero new unresolved game symbols (5 functions, 203 code bytes total, 1 byte `.bss` at `00656ab0`):

1. `application_sim_boundary_004a4760` (`004a4760..004a477e`, 31 bytes, `sha256: 476ea9048eabfd1f90aaaa01c039b316d6b6ffcd457de8a71758f615a5dc8dcd`)
2. `application_sim_boundary_004ae470` (`004ae470..004ae4c8`, 89 bytes, `sha256: 02a5743de6d5b886d83f4c38d8891ef1bc3d4cc72fc47b5b55b2fe139b32dd77`)
3. `application_sim_boundary_004b04d0` (`004b04d0..004b04dc`, 13 bytes, `sha256: 3bfa59a6c602f6ec073d35a5599b03ef6872461d7f24d0dc01f698275de31dbc`)
4. `application_sim_boundary_004ad4d0` (`004ad4d0..004ad4ed`, 30 bytes, `sha256: 232e2142a120314b22bf10861432701cee51f221f0b51b9bcc67263047cf0142`)
5. `audio_device_register_callback_005610e0` (`005610e0..00561107`, 40 bytes, `sha256: 913902718ff1a2c1415748323aa5f987e439274d69064c72591cbe95c57aca37`)

Owned `.bss` byte (1 byte):
- `sim_audio_callback_registered_00656ab0` (`00656ab0`, 1 byte `.bss` one-shot guard in the gap noted by `Run478`)

Reused canonical symbols:
- `startup_clock_initialized_00655a04` (`00655a04`, `Run598`)
- `network_lifecycle_remove_callback_00560180` (`00560180`, `network_lifecycle.cpp`)
- `audio_resource_query_root_00656ab4` (`00656ab4`, `Run478`)
- `application_audio_device_state_006b48c0` (`006b48c0`, reads/writes `+0xdc` / `006b499c`, `+0xe0` / `006b49a0`, and `+0xf0` / `006b49b0`)

## Files
- `iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/sim_audio_teardown_leaves_783.hpp`
- `iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/sim_audio_teardown_leaves_783.cpp`
- `iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/scope-evidence.json`
- `iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/native-config.json`
- `iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/native-fixture.cpp.in`
- `iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/rea-queries.json`
- `iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/validation.json`

## Verification
- **REA Evidence**:
  - `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/rea-queries.json --attempt 001` -> `local/experiments/v2-sim-audio-783-rea/001/receipt.json` (`status: completed`, 5 dossiers)
  - `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/rea-queries.json --attempt 001` -> `{"passed": true, "dossiers": 5, "repeated_equal": 0}` (`validation.json`)
- **Native Original x86 vs C++ Comparison**:
  - `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/783-sim-audio-teardown-leaves/native-config.json --attempt 001`
  - Receipt: `local/experiments/v2-sim-audio-teardown-leaves-783/001/receipt.json` (`"status": "PASS"`)
  - `/Od` and `/O2`: `sim_audio_teardown_leaves_original_x86_vs_cpp=PASS cases=14 events=1` (0 failed cases, ABI + FPU/MXCSR + `.bss` + device state + arena bit-exact)
  - Material mutations: `12/12` detected (`exit_code: 1`)

## Explicit Bounds
- `004a4760` and `004ad4d0` forward literal original callback addresses (`0x004a45d0`, `0x004ac290`) into canonical `network_lifecycle_remove_callback_00560180` / `audio_device_register_callback_005610e0`.
- `005610e0` assumes callback registration count stays within canonical `audio_device_state_006b48c0` `+0xf0` callback table capacity (8 slots).
- `004ae470` assumes valid `root+0xe8` buffer space for matched indices.
