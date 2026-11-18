# Run 668 startup replay load (`004146f0`, `00413cf0`)

Bounded native x86-vs-C++ recovery proof for 2 functions (704 code bytes total) in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::replay_load_004146f0` (`004146f0..0041480b`, 284B, `__cdecl`, `ret 0`, sha256 `e780f9a0607e0cbf6fa4eebd43f2f1578b9b410acd1f71708d64582055982cf4`): formats `<root><replay_filename_00699f34>` via `formatter_entry_005a0fbf`, opens via `open_0059e040(path, 1, 0x64, &handle)`, or falls back to `<root>replay.rpl` after logging `"loading default replay.rpl!!!\n"`, else logs `"No Replay file found!!!!\n"` and sets `global_005e99f4 = 0`; when `handle != nullptr`, reads `size_00533de0(handle, 0x64)` bytes into `replay_snapshot_005e9a20` via `read_00533bf0(handle, 0, replay_snapshot_005e9a20, size, 0x64)`, closes via `close_00533da0(handle, 0x64)`, and prints `"%s File Loaded\n"` or `"replay.rpl File Loaded\n"` via `formatter_stdio_printf_005a177b`.
- `porsche::startup_sequence_call_00413cf0` (`00413cf0..00413e93`, 420B, `__cdecl`, `ret 0`, sha256 `1ece6f8692fa7e940c3b1acdeb21fff576f0847f06823b9ee184e7bf69dc5346`, closes frontier symbol in `porsche/startup_sequence.hpp`): copies `00657424 -> global_005e99f4` and `0065741c -> replay_mode_flag_00606858`. When `mode == 2`, saves `00657c84` (`0x36` dwords = 216B) and 14 display/mode/state words (`00657a48`, `00657a4c`, `00657a50`, `00657d5c`, `00657d60`, `00657d68`, `00657d6c`, `00657d70`, `00657d78`, `00657d7c`, `00657d80`, `00657d88`, `00657d9c`, `00657db4`) from `application_state_006573e8`, calls `replay_load_004146f0()`, clears `replay_state_005e99fc = 0`, copies `0xf89` dwords (`0x3e24` bytes) from `replay_snapshot_005e9a20` into `application_state_006573e8`, restores all saved fields, and copies `replay_tail_word_005ed844 -> replay_saved_word_00606a80` and reloaded `0065741c -> replay_mode_flag_00606858`; when `mode != 2`, copies `application_state_006573e8` (`0x3e24` bytes) into `replay_snapshot_005e9a20`.

## Index, Ownership & Canonical Headers

- Reused canonical owners: `application_state_006573e8` (`porsche/application_state.hpp`), `global_005e99f4` (`porsche/application_main.hpp`), `engine_service_root_0065b360` (`porsche/engine_service_427a60.hpp`), `formatter_entry_005a0fbf` (`porsche/formatter_entry.hpp`), `open_0059e040` / `size_00533de0` / `read_00533bf0` / `close_00533da0` (`porsche/fe_stream.hpp`), `formatter_stdio_printf_005a177b` (`porsche/formatter_stdio.hpp`), `startup_sequence_call_00413cf0` (`porsche/startup_sequence.hpp`).
- Owned BSS globals (16052 bytes, zero prior owners): `replay_state_005e99fc` (4B), `replay_snapshot_005e9a20` (`0x3e24`B = 15908B), `replay_tail_word_005ed844` (4B), `replay_saved_word_00606a80` (4B), `replay_mode_flag_00606858` (4B), `replay_filename_00699f34` (128B).
- Owned read-only strings in PE `.data` (97 bytes, single ref each in `004146f0`): `005cc698` (16B), `005cc6a8` (24B), `005cc6c0` (26B), `005cc6dc` (31B). Shared literals `005cc588` (`"%s%s"`, 78 refs) and `005cc68c` (`"replay.rpl"`, 2 refs) are reused, not owned.

## Verification

- Attempt `001`: **PASS** (`local/experiments/v2-startup-replay-load-668/001/receipt.json`, sha256 `8a7927b076a880864109d6d96b3fd1bdedf60fb3880222fd198f42ec25df14ef`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/668-startup-replay-load/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with 0 `/W4` warnings and passed `startup_replay_load_original_x86_vs_cpp=PASS cases=11`.
  - All `18/18` material mutations were detected (`exit_code=1` on `divergence`).

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `004146f0` and `00413cf0` using bounded formatted paths (`<80B` stack buffer), bounded read sizes (`<= 0x3e24` bytes into `replay_snapshot_005e9a20` without spanning into the contiguous PE `0x1ce28`-byte replay buffer `005ed844..00606847` used by unrecovered `00413fd0`/`00414660`), deterministic `005a0fbf`/`0059e040`/`00533de0`/`00533bf0`/`00533da0`/`005a177b` stubs, and production CMake/registry integration remaining open.
