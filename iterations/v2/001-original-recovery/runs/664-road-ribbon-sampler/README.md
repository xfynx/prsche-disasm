# Run664 startup road-ribbon sampler (`00532860`, `00434aa0`, `00434a90`)

Bounded native x86-vs-C++ recovery proof for the startup road-ribbon sampler packet closing `startup_sequence_call_00434a90` (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 772 code bytes total):
- `porsche::math_angle_turns_00532860` (`00532860..00532870`, 17B, `__cdecl`, sha256 `4e0586f70f4a2247b95a31480910ec7d32a86f17dafa234c11c874ed017ddb2b`): computes `atan2(y, x) * 0.1591549515724182` via x87 `fpatan` and `.rdata` double `0x005bb2c8` (`0x3fc45f3080000000`).
- `porsche::road_ribbon_sample_00434aa0` (`00434aa0..00434d8d`, 750B, `__cdecl`, sha256 `b8ba12d0818aa3394ddbefd51c88ee1085783070df58c3b4433754b57c8d4812`): walks `0x50`-byte road slices at `*(void**)track_road_data_00628bc0 + 0x0c` (`+0x04..+0x0c` vec3), accumulates wrapped turn deltas (`delta > 0.5f ? |1.0f - delta| : |delta|`) using the unrounded x87 angle difference against `float32` `prev_angle`, scales `step = total_accum * 0.005f` (`0x3ba3d70a`), emits up to 200 `{x, y, z, 1.0f}` entries into `road_ribbon_points_0060fde0` (`0060fde0..00610a5f`), and tail-fills remaining slots with `slice[n - 1]`.
- `porsche::startup_sequence_call_00434a90` (`00434a90..00434a94`, 5B thunk `jmp 0x00434aa0`, sha256 `ec7d2aa54ab353ae3e298f2752ca2bce4eae1ebdb8c1ddeefde03cd044576859`): canonical entry from `porsche/startup_sequence.hpp`.

Owned `.data` / `.rdata`:
- `porsche::road_ribbon_points_0060fde0[200]` (`0060fde0..00610a5f`, 3,200B loader-zero `.data` BSS, referenced solely by `00434aa0` in `references.jsonl`).
- `porsche::track_road_data_00628bc0` (`00628bc0..00628bc3`, 4B loader-zero `.data` BSS, 123 refs in `references.jsonl`, zero prior owner in `source/`).
- `0x005bb2c8` (`0x3fc45f3080000000`, 8B `.rdata` double, sha256 `f80f97092bf00df7c7b8a26d602f88eb627f3a7d0d13db5ad8c197f810b15799`, referenced solely by `0053286a`); shared `.rdata` scalars `0.5f` (`005b23f0`), `1.0f` (`005b24a8`), and `0.005f` (`005b3284`) are reused as constants without exclusive ownership claims.

## Verification

- Attempt `005` (`local/experiments/v2-road-ribbon-sampler-664/005/receipt.json`, sha256 `cd2b71a8c7bd367dcb7126b63a16e82beef424df518f3071159b830255e986b5`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `road_ribbon_sampler_664.cpp`, 37 cases: 22 direct `00532860` bit-exact float comparisons + 15 direct `00434aa0` and end-to-end `00434a90` ribbon-buffer comparisons across `n=1..250`, 13/13 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/664-road-ribbon-sampler/native-config.json --attempt 005`

## Boundaries

Bounded test domain (`PARTIAL`): covers controlled `track_road_data_00628bc0` arenas (`n=1..250`, straight lines, wrap-around across `+/-0.5` turns, `0.25 < delta <= 0.5` turns, spiral/S-curve accumulation, and 200-slot cap) and direct `(y, x)` inputs with bit-exact IEEE comparison and clean x87 stack checks. Null/faulting `track_road_data_00628bc0`, `n <= 0`, and production CMake/registry integration remain open.
