# Run 665 resource path-device & file-exists leaf chain (`005916a0`, `00591760`, `00568e90`, `00568260`, `00533f00`, `00561b80`)

Bounded native x86-vs-C++ recovery proof for 6 functions (296 code bytes total) in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`), reusing canonical `formatter_search_character_005a2780` (`source/recovered/Porsche.exe/formatter_search.cpp`):
- `porsche::disk_path_drive_letter_005916a0` (`005916a0..0059170e`, 111B, `__cdecl`, `ret 0`, sha256 `1664d1ed6fbdfabe2bf76b9dbc96d52f5b44ac985acc2d9fb284a6074782c6c7`): calls canonical `formatter_search_character_005a2780(path, 0x7c)` returning `0` if non-null, substitutes shared `"."` (`0x005cd1f4`) if `path == nullptr`, invokes `platform_disk_get_full_path_name` (`[0x005b221c]` `GetFullPathNameA`, 261B buffer) then `platform_disk_char_upper` (`[0x005b2290]` `CharUpperA`), and returns `buffer[0]` in `AL` if `static_cast<std::int32_t>(len) > 1 && buffer[1] == ':'`, else `0`.
- `porsche::disk_path_device_00591760` (`00591760..0059177a`, 27B, `__cdecl`, `ret 0`, sha256 `acc20270b66ebca0881f491c3365e644e9f3a7f429fc621c9fa698bab4cc6dc9`, canonical decl in `porsche/disk_open.hpp`): calls `disk_path_drive_letter_005916a0(path)`, masks `letter & 0xffu`, and returns `static_cast<std::uint8_t>(letter - 0x40u)` if non-zero, else `0`.
- `porsche::file_device_name_00568e90` (`00568e90..00568eb2`, 35B, `__cdecl`, `ret 0`, sha256 `39a3707f51099fd1ae5546253fe56fe0e6093bca1924cbd53d624f09bdfe6c0b`, canonical decl in `porsche/files.hpp`): returns `0` if `formatter_search_character_005a2780(path, 0x7c) != nullptr`, else `static_cast<std::uint32_t>(disk_path_device_00591760(path))`.
- `porsche::request_exists_00568260` (`00568260..00568292`, 51B, `__cdecl`, `ret 0`, sha256 `2d76d7cc139123d46257f30dd104c963b506628f1d4f182ee34b0d28b20f2510`): resolves `device = file_device_name_00568e90(path)`, allocates `op = operation_allocate_005682a0(6, static_cast<std::uint8_t>(group), context, device)`, sets name via `operation_name_005684e0(op, path)`, and returns `operation_queue_00568200(op)`.
- `porsche::file_exists_sync_00533f00` (`00533f00..00533f33`, 52B, `__cdecl`, `ret 0`, sha256 `aef1dd8cf8d1da9b8dc07ad127c846b1a4b6ea91bf42a4c002d6ae12a4366dc0`): calls `id = request_exists_00568260(path, group, nullptr)`, returns `0` if `id == 0`, else waits via `file_wait_00567f70(id)` and returns `static_cast<std::int32_t>(operation_complete_00567df0(id))`.
- `porsche::file_exists_00561b80` (`00561b80..00561b93`, 20B, `__cdecl`, `ret 0`, sha256 `6c38d1ce8539e936a15a3d0b914a4bcb912fa03129e780dbc5991568018c2812`, canonical decl in `porsche/files.hpp`): forwards `file_exists_sync_00533f00(path, resource_leaf_group_005df770)`.

## Index, Ownership & Canonical Headers

- Zero owned `.data` or `.rdata` globals (`005cd1f4` `"."` has 10 references in `references.jsonl` and is reused, not owned here; `formatter_search_character_005a2780` is already owned in `formatter_search.cpp`).
- Reused headers: `porsche/formatter_search.hpp`, `porsche/disk_open.hpp`, `porsche/files.hpp`, `porsche/resource_leaf.hpp`.
- Canonical definitions provided by `file_exists_path_device_665.cpp`: `disk_path_device_00591760`, `file_device_name_00568e90`, `file_exists_00561b80` (plus `disk_path_drive_letter_005916a0`, `request_exists_00568260`, `file_exists_sync_00533f00`, and `platform_disk_get_full_path_name` / `platform_disk_char_upper`).

## Verification

- Attempt `001` (`local/experiments/v2-file-exists-path-device-665/001`, preserved): `wrong-drive-len-gt1` failed to diverge cleanly.
- Attempt `002` (`local/experiments/v2-file-exists-path-device-665/002`, preserved): `formatter_search_character_005a2780` collided with canonical `formatter_search.cpp` (`LNK2005`) during `Run666` shared build `001`.
- Attempt `003` (`local/experiments/v2-file-exists-path-device-665/003`, preserved): linking `formatter_search.cpp` required fixture stubs for unrelated `005ae3c0` symbols.
- Attempt `004` (`local/experiments/v2-file-exists-path-device-665/004`, preserved): PASS before `scope-evidence.json` boundary text alignment.
- Attempt `005`: **PASS** (`local/experiments/v2-file-exists-path-device-665/005/receipt.json`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/665-file-exists-and-path-device/native-config.json --attempt 005`
  - `/Od` and `/O2` compiled with 0 `/W4` warnings and passed `file_exists_and_path_device_original_x86_vs_cpp=PASS cases=258` (`516` total across both optimization levels).
  - All `14/14` material mutations exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `005916a0`, `00591760`, `00568e90`, `00568260`, `00533f00`, and `00561b80` (reusing canonical `formatter_search_character_005a2780` from `formatter_search.cpp`) using non-null bounded NUL-terminated paths (`<260B`), deterministic Win32 `GetFullPathNameA`/`CharUpperA` facades, and deterministic operation/wait/completion stubs; `nullptr` input faults in `005a2780` (leaving `005916c5` `"."` fallback unreachable under real `005a2780`), live Win32 filesystem/locale behavior, null `operation_allocate_005682a0` dereference inside real `operation_name_005684e0`/`operation_queue_00568200`, and CMake/registry integration remain open.
