# Run 655 network sync barrier & key-poll (`0055ff60`, `0048d350`, `0048cdf0`)

Bounded native x86-vs-C++ recovery packet for `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::startup_input_poll_key_0055ff60` (`0055ff60..0055ff6e`, 15B, `__cdecl`, `ret 0`, `std::uint32_t`, sha256 `2b72e8c048c139988bc25eacbd3d880e89a0d8ec84c99253b88c68c07b6e07ec`): reads `startup_input_key_callback_005df6a4`; if non-null invokes it as `std::uint32_t(__cdecl*)()` and returns its result, else returns `0u`.
- `porsche::application_network_message_short_0048d350` (`0048d350..0048d36d`, 30B, `__thiscall` -> C++ `__fastcall`, `ret 0x10`, sha256 `6a9b14ab513d288903b7b8df3c4b3c7352829b4b98ef9cb5361531551da45acf`): forwards `(receiver, nullptr, message, first, second, 0u, fourth)` to `application_network_message_0048c870`.
- `porsche::network_sync_barrier_0048cdf0` (`0048cdf0..0048d343`, 1364B, `__thiscall` -> C++ `bool __fastcall`, `ret 0`, sha256 `fd96f64dc0628b4c3a516b5f43f62dae9461837645d6bb4e4dcf32b7d77afb64`) plus canonical `__cdecl` frontier adapters `application_main_function_0048cdf0()` (`porsche/application_main.hpp`) and `startup_sequence_call_0048cdf0()` (`porsche/startup_sequence.hpp`): executes the 4-phase network sync barrier (`Wait to go high1\n`, `Wait to go high2\n`, `Wait to go low1\n`, `Wait to go low2\n`) sending `0xbd` packets (`seq_id` / `seq_id + 8`), polling `004a4a70(-1)`, `0055ff60()`, `0055f740(1)`, `005366e0(0)` against bitmask `[self+0xe5]` in `[self+0xe6]`/`[self+0xe7]`, and preserving the exact per-phase abort paths (`0048da60` in phases 1–2, `0048d350` inside lock in phase 3, and `0048c870` inside lock in phase 4).

## Index, Ownership & Canonical Headers

- Owned `.data` strings (each referenced only by `0048cdf0` in `references.jsonl`, zero prior owners):
  - `network_sync_abort_str_005d0738` (`005d0738..005d073e`, 7B `"Abort\n\0"`, sha256 `af9efbb5932d2cddac21c460b2c5415a7056177cc3020e268f9fc247e996699d`)
  - `network_sync_wait_low2_str_005d0740` (`005d0740..005d0750`, 17B `"Wait to go low2\n\0"`, sha256 `3391b1f05aa1303be9a1200e33e0df90f8543d7a1a3c0fe4edcdb8e3b5b56b77`)
  - `network_sync_wait_low1_str_005d0754` (`005d0754..005d0764`, 17B `"Wait to go low1\n\0"`, sha256 `167b523aa872b2c046d4a31f61e805355997e2527cf4cfdfc91b94e96a96404e`)
  - `network_sync_wait_high2_str_005d0768` (`005d0768..005d0779`, 18B `"Wait to go high2\n\0"`, sha256 `4ba2cf767d7386f60564d7a50b2abd2f305dea4ca15bd7cc178c1a46a48c851e`)
  - `network_sync_wait_high1_str_005d077c` (`005d077c..005d078d`, 18B `"Wait to go high1\n\0"`, sha256 `759a8aa6847057d9deb35bb2669c9f989f0bfe668af2c68502e10831084c695d`)
- Reused canonical symbols/headers: `porsche/startup_services.hpp` (`startup_network_00628c70`), `porsche/startup_input.hpp` (`startup_input_key_callback_005df6a4`), `porsche/network_services.hpp` (`application_network_message_0048c870`, `network_services_action_0048da60`), `porsche/startup_sequence.hpp` (`splash_progress_004a4a70`, `startup_sequence_call_0048cdf0`), `porsche/application_main.hpp` (`application_main_function_0048cdf0`), `../549-render-diagnostic/render_diagnostic_549.hpp` (`render_texture_diagnostic_0055ec50`), `porsche/file_wait.hpp` (`file_sleep_0055f740`), `porsche/window_runtime.hpp` (`timed_callbacks_005366e0`), and `porsche/heap.hpp` (`heap_enter_005322b0`, `heap_leave_005322c0`).

## Verification

- Attempt `001`: failed at `case=21` (`divergence event capacity`, `active_self` was hardcoded to `self_arena` instead of `net_arena` when `use_distinct_self == false`); preserved immutable under `local/experiments/v2-network-sync-barrier-655/001`.
- Attempt `002`: **PASS** (`local/experiments/v2-network-sync-barrier-655/002/receipt.json`, sha256 `8947af4218bce66177c5b365d6f014d809b2e62b6ee6f36de272577773890a31`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/655-network-sync-barrier/native-config.json --attempt 002`
  - `/Od` and `/O2` compiled cleanly (`/W4`) and passed `network_sync_barrier_original_x86_vs_cpp=PASS cases=23`.
  - All `13` material `wrong-*` mutations exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `0055ff60`, `0048d350`, `0048cdf0`, frontier wrappers `application_main_function_0048cdf0` / `startup_sequence_call_0048cdf0`, and owned `.data` strings `005d0738..005d078d` using controlled arenas and deterministic callee stubs; live network transport, live DirectInput key callback producer, arbitrary unmapped pointers/faults, and production CMake/registry integration remain open.
