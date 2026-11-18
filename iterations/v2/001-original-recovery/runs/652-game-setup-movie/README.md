# Run 652 startup movie & rooted resource path (`00472860`, `0059e440`, `004dd4a0`)

Bounded native x86-vs-C++ recovery packet for `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::context_string_insert_00472860` (`00472860..004729a0`, 321B, `__thiscall`, `ret 8`, sha256 `02f61f97c2890efc7718fb14a84d2849a7fdd8d1dae6db9b59537fe634908e86`): inserts `[first, last)` into a 12-byte context string `[begin, current, end]`, growing via `004211d0` and releasing old buffers (`>0x100` via `0059ecd0`, `<=0x100` via small-block pool freelist bucket `(bytes - 1) >> 3`).
- `porsche::game_setup_resource_open_0059e440` / `game_setup_resource_open_result_0059e440` (`0059e440..0059e64d`, 526B, `__cdecl`, `ret 0`, `AL=bool`, sha256 `5f5568a434e3d03d610a096d78f2811bd5c184c992f79d2519d3f0ddcaa42b91`): resolves unrooted or primary/fallback rooted paths via `file_exists_00561b80`, falling back to `missing_file_006afbe4(path, -2)` and `file_null_name_005e8e50` (`""`) into the 12-byte string object (`context_move_005a1a40` or `00472860`).
- `porsche::game_setup_movie_004dd4a0` (`004dd4a0..004dd5f4`, 341B, `__cdecl`, `ret 0`, sha256 `ceab0a5696de70e73b6fadb044d62a656a47468f76e9f9dcefab668c0028dd02`): formats `%sporsche.fsh` (`005d999c`) and opens via `resource_open_quiet_0059d9b0(..., 0)`, formats `%sinPC-av.mad` (`005d998c`), wraps `movie_service` (`00536080`/`00536050`), and when `0059dc30` succeeds, initializes/loads `movie`, runs 3 render-frame passes (`006bd9b0..006bd978`), invokes `004dc850`, and releases `movie.begin` via `0059ecd0` (`>0x100`) or small-block pool freelist (`<=0x100`).

## Index, Ownership & Canonical Headers

- Owned `.data` format strings (each referenced only by `004dd4a0` in `references.jsonl`):
  - `game_setup_movie_mad_fmt_005d998c` (`005d998c..005d9999`, 14B `"%sinPC-av.mad\0"`, sha256 `6166617283015610aefb4485e5a1a2082d551729fc120098e3424dd83080494f`)
  - `game_setup_porsche_fsh_fmt_005d999c` (`005d999c..005d99a9`, 14B `"%sporsche.fsh\0"`, sha256 `e2ccf2d2fa61bc2ccfc01a9c72aacfc07439d6ee344112c5aa7f5bcc37277694`)
- Reused canonical symbols/headers: `porsche/game_setup.hpp`, `porsche/files.hpp` (+ `file_null_name_005e8e50` defined in `files.cpp`), `porsche/formatter_entry.hpp`, `porsche/context_move.hpp`, `porsche/context_effects.hpp`, `porsche/application_context_base.hpp`, `porsche/heap.hpp`, and `startup_sequence_resource_table_649.hpp`.
- Disassembly verified stack-argument detail at `004dd4ed`: the 4th argument pushed at `004dd4e1` (`lea eax, [esp + 0x34]`) resolves to `mad_path` (`orig_esp + 0x20`), matching sibling `004dd600`.

## Verification

- Attempt `001`: failed at `case=20` (`kEvObjInit` compared unnormalized stack address of local `movie`); preserved immutable under `local/experiments/v2-game-setup-movie-652/001`.
- Attempt `002`: `/Od` and `/O2` passed (`cases=26`), but `wrong-472860-empty-range-check` crashed (`0xC0000005`) on `0xffffffff` length underflow instead of exiting `1` on `divergence`; preserved immutable under `local/experiments/v2-game-setup-movie-652/002`.
- Attempt `003`: **PASS** (`local/experiments/v2-game-setup-movie-652/003/receipt.json`, sha256 `861b1546831a5fcea38e27853c9e8af3baf915424eccb6ae0cc0627ff7acd995`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/652-game-setup-movie/native-config.json --attempt 003`
  - `/Od` and `/O2` compiled cleanly (`/W4`) and passed `game_setup_movie_original_x86_vs_cpp=PASS cases=26`.
  - All `11` material mutations exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `00472860`, `0059e440`, `004dd4a0`, and owned `.data` strings `005d998c`/`005d999c` using bounded paths, controlled arenas, and deterministic callee stubs; unrecovered callees (`00560030`, `0059dc30`, `00403520`, `004dc850`, IAT render callbacks), arbitrary unmapped/null pointers and faults, and production CMake/registry integration remain open.
