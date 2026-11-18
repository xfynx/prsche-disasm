# Run 643 audio transition finish (`004ae4d0` + `004ae8c0`, `.data 005d1c1c`, `.data 0065b928`)

Bounded native x86-vs-C++ recovery packet for `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::application_audio_transition_finish_004ae4d0` and naked `jmp` alias `porsche::frame_services_boundary_004ae4d0` (`004ae4d0..004ae8b2`, 995B, `__cdecl(uint32_t, uint32_t)`, sha256 `27ecec51cc35cf224f517e0118bfddb570c61d1da214b9043441c67db1bdb8f8`).
- `porsche::frame_services_boundary_004ae8c0` (`004ae8c0..004ae985`, 198B, `__cdecl(uint32_t shifted_product)`, sha256 `57f95780bf516b9675752b33690814dcdab2e2cb2ed37ea1dd85dd3afcc1c306`).
- `porsche::audio_transition_wildcard_fmt_005d1c1c` (`.data 005d1c1c..005d1c20`, 5B, `"*-%s\0"`, sha256 `b36afdab285bc9e84db530a17a7aabae6776c3ce10adb4b928efdac585135d1e`).
- `porsche::audio_transition_word_0065b928` (`.data 0065b928..0065b92b`, 4B loader-zero `uint32_t`).

## Ownership & Canonical Headers

- Only `004ae4d0` reads `005d1c1c` in `references.jsonl`; zero prior owner existed for `005d1c1c` or `0065b928` in compiled recovery sources (`application_context_core_candidate.cpp` is uncompiled research only).
- Reused canonical headers (`include_dirs`):
  - `iterations/v2/001-original-recovery/source/include` (`porsche/application_audio_lifecycle.hpp`, `porsche/frame_services.hpp`, `porsche/application_state.hpp` for `application_state_006573e8.word(0x00657a5cu)`, `porsche/formatter_entry.hpp` for `formatter_entry_raw_005a0fbf`, `porsche/object_update.hpp` for `platform_get_tick_count`)
  - `runs/478-audio-resource-controls`, `runs/607-frame-audio-stream-ramp`, `runs/637-audio-stream-channel-status`, `runs/638-render-seed-prng`, `runs/640-pattern-match`, plus transitive include dirs `runs/561-audio-stream-creation`, `runs/434-audio-canonical-bindings`, `runs/443-audio-device-capabilities`, `runs/435-audio-stop-voice`, `runs/438-audio-pool-allocator`
  - Run564 canonical link targets `audio_resource_locate_005666f0` and `audio_service_stream_start_00567720` (`audio_callback_resource_564.obj`)
- COFF (`o2-0.obj`): `5` bytes `.data`, `8` bytes `.bss`, `0` bytes `.rdata`; exports `?application_audio_transition_finish_004ae4d0@porsche@@YAXII@Z`, `?frame_services_boundary_004ae4d0@porsche@@YAXII@Z`, `?frame_services_boundary_004ae8c0@porsche@@YAXI@Z`, `?audio_transition_wildcard_fmt_005d1c1c@porsche@@3PADA`, and `?audio_transition_word_0065b928@porsche@@3IA`.

## Verification

- Attempt `001`: failed `mutation-wrong-abs32-sign-mask-native` (test sum `-240` was divisible by `4`); preserved immutable.
- Attempt `002`: **PASS** (`local/experiments/v2-audio-transition-finish-643/002/receipt.json`)
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/643-audio-transition-finish/native-config.json --attempt 002`
  - `/Od` and `/O2` compiled with zero warnings on `audio_transition_finish_643.cpp` and passed `audio_transition_finish_original_x86_vs_cpp=PASS cases=46`.
  - All `10` material mutations exited `1` on `divergence`: `wrong-mode1-cur-count-guard`, `wrong-fallback-strlen-limit`, `wrong-0065b928-override-value`, `wrong-abs32-sign-mask`, `wrong-entry-sign-extension`, `wrong-crossfade-ramp-ms`, `wrong-tail-zero-offset`, `wrong-4ae8c0-pending-state-guard`, `wrong-4ae8c0-start-vol-divisor`, `wrong-4ae8c0-zero-old-vol-trigger`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `004ae4d0` (both entry aliases) and `004ae8c0` using a controlled `0x200`B root buffer, writable pattern buffers, and deterministic callee stubs. Non-int32-overflowing division domains, EAX discard by `void` callers, real audio/resource/formatter/PRNG/tick providers, unrecovered callers, and production CMake/registry integration remain open.
