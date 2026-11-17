# Run625 application audio probe init

## Goal and criteria
- Recover original `004a66b0` (`application_audio_probe_initialize_004a66b0`, 398B) and its owned 128B `.rdata` mode table `005b4ac0..005b4b3f` (`application_audio_mode_data_005b4ac0`) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse canonical declarations in `porsche/application_services.hpp`, `porsche/application_audio_init.hpp`, `porsche/application_audio_device.hpp`, `porsche/application_state.hpp`, and `porsche/file_events.hpp`, without throwing C++ exceptions and without redefining `application_audio_device_configured_00655d40` or `application_audio_post_setup_004ab470`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes (`a9ac30a2e2c2ddb8191cf4198eaf8c3932d6f3f4f2bbc5e7238cf3ce3b297e91` for `004a66b0..004a683d`, `1971f9131f19a90589aa38b61716f75b521469ab8ef7799874f5de89f991ef01` for `005b4ac0..005b4b3f`), and cached REA (`local/experiments/v2-audio-device-mix-465-rea/002/receipt.json`: `function-004a66b0.json`, `ev_6391ab9f852aaa4c29d9f527ce09747a1dd4ae9a9e9f40d1231d50b41eda0081`) confirm the 398B body, `__cdecl` 0-arg `uint8_t` (AL) signature, 16 `ABS32` relocations, and 6 `REL32` calls.
- Disassembly of `004a66b0..004a683d` confirms that `004a680b: jl 0x004a66db` jumps to the `AL=0` return epilogue (`pop esi; xor al, al; pop ebx; add esp, 0x7c; ret`) without retrying `00565680` and without clearing `00655d40`, whereas `004a66cf: jge 0x004a66e3` clears `00655d40 = 0` on `query_config < 0` before falling through to `0x004a66db`.
- `004a681e..004a6826` (`mov eax, [0x5deb48]; cdq; sub eax, edx; sar eax, 1`) computes signed truncating division `rate / 2` for `0053c380`.
- Attempt `001` (`local/experiments/v2-application-audio-probe-init-625/001/receipt.json`) passed 249 cases (1241 events) at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-create-failure-guard`, `wrong-mode-three-cutoff`, `wrong-interval-rounding`, `wrong-max-rate-clamp`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `004a66b0` and `005b4ac0`.
- Mode values `< -8`, out-of-bounds descriptor format counts (`0x0b + count > 0x7c`), and production integration remain open.
