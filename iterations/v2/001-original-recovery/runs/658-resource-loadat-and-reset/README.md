# Run 658 resource loadat & audio query root reset (`00561e90`, `00561e40`, `00561f20`, `0059db50`, `00566880`, `004adf50`)

Bounded native x86-vs-C++ recovery proof for 6 functions (748 code bytes total) in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::file_loadat_callback_00561e90` (`00561e90..00561f19`, 138B, `__cdecl`, `ret 0`, sha256 `7ca7f775c932f6c153640bd2cd52b234958c6dd86ec4b0890f8c8b217dbdd1f4`): clamps signed `max_bytes <= 0` to `0x7fffffff`, opens via `file_open_00533b90(path, 1, group, &handle)`, reads/closes on `group - 1`, or on failure with `callback_diagnostic_flag != 0` sets `005deb74` (`"\\real\\cmn\\hlsfile.c"`) / `005deb78` (`0x12f`) and invokes two-arg `diagnostic_handler_005debf0` (`005bcd90`, `path`).
- `porsche::file_loadat_00561e40` (`00561e40..00561e86`, 71B, `__cdecl`, `ret 0`, sha256 `aabda080980c22a82b4a309a185fef6d894ff093bdce36165f8b483309195efa`): absent from main `functions.jsonl`; supplemented in `original-index-supplement.json`; populates `ResourceAtomicContext{path, buffer, max_bytes, 1}`, reads `resource_leaf_group_005df770`, queries `file_device_name_00568e90(path)`, and calls `resource_leaf_atomic_dispatch_00568d50`.
- `porsche::file_loadat_quiet_00561f20` (`00561f20..00561f66`, 71B, `__cdecl`, `ret 0`, sha256 `fa8708eb9e90634df511894fc5ace3819c98bd2c7f0b7e40a8960e5edbafeef3`): quiet sibling of `00561e40` (`callback_diagnostic_flag = 0`).
- `porsche::resource_loadat_quiet_0059db50` (`0059db50..0059dc29`, 218B, `__cdecl`, `ret 0`, sha256 `bde9e10a7399e913993f2e26c5c2b3ccb24e607e3665f3af35ff52a9104ad045`; excluding two `0x90` padding bytes at `0059dc2a..0059dc2b`): rooted/unrooted `file_loadat_quiet_00561f20` wrapper invoking `missing_file_006afbe4(name, -2)` when rooted lookups fail.
- `porsche::audio_resource_data_offset_00566880` (`00566880..005668bd`, 62B, `__cdecl`, `ret 0`, sha256 `137d8c1f4e90ba77f75aa5d4e39d1c970088cf385cb9622c2752019e0ae241da`): reads `BE16(source + 4)` when `audio_resource_kind_00566520(source) == 1`, `BE32(source + 8)` when `== 2`, else `0`.
- `porsche::audio_resource_query_root_reset_004adf50` (`004adf50..004ae00b`, 188B, `__cdecl`, `ret 0`, sha256 `212628c50f9779d1b031a184e95b6837508be890b68093a0aab8dee324637b41`): zeroes `+0x88, +0x6c, +0x78, +0x7c, +0x04, +0x00, +0x20, +0x08, +0x10, +0x18, +0x28, +0x14, +0x1c, +0x80` and `+0x170, +0x18c, +0x174, +0x178, +0x17c, +0x180, +0x188` (`+0x168 + {0x08, 0x24, 0x0c, 0x10, 0x14, 0x18, 0x20}`), and sets `+0x70 = -1` and `+0x0c = -1` on `audio_resource_query_root_00656ab4`.

## Index, Ownership & Canonical Headers

- Owned `.rdata` (38 bytes, zero `.data` globals):
  - `file_loadat_open_err_005bcd90[38]` (`005bcd90..005bcdb5`, sha256 `2ce0ea9178fb463baa82459cfe7e359c45548d79c347400f3b52bf36ced45d62`, `"FILE_loadat - unable to open file %s\n"`, single reference at `00561ef1`).
- Reused `.rdata`/`.data` strings (not owned here): `"\\real\\cmn\\hlsfile.c"` (`005bcd00`, 20B) and `"%s%s"` (`005cc588`, 5B).
- Reused headers: `porsche/files.hpp`, `porsche/fe_stream.hpp`, `porsche/formatter_entry.hpp`, `porsche/resource_dispatch.hpp`, `porsche/resource_leaf.hpp`, `porsche/shared_runtime_globals.hpp`, `../478-audio-resource-controls/audio_resource_controls_478.hpp`, `../537-render-resource-descriptor-cleanup/render_resource_descriptor_537.hpp`.
- Unrecovered child declared in `resource_loadat_658.hpp`: `std::uint32_t __cdecl audio_resource_kind_00566520(std::uint32_t source);`.

## Verification

- Attempt `001`: compile error (missing `<initializer_list>` for braced list in `004adf50` tail loop); preserved immutable under `local/experiments/v2-resource-loadat-reset-658/001`.
- Attempt `002`: runtime divergence in `od-native` (`case=44`) because `normalize_ptr` did not normalize the stack-local `ResourceAtomicContext` address passed via `&opaque_context` into `file_open_00533b90`; preserved immutable under `local/experiments/v2-resource-loadat-reset-658/002`.
- Attempt `003`: **PASS** (`local/experiments/v2-resource-loadat-reset-658/003/receipt.json`, sha256 `9668d6675dfc4e15f970b9f45e63f041a494b7313e84d64baee83ffc82100e4e`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/658-resource-loadat-and-reset/native-config.json --attempt 003`
  - `/Od` and `/O2` compiled with 0 `/W4` warnings and passed `resource_loadat_and_reset_original_x86_vs_cpp=PASS cases=98`.
  - All `17/17` material mutations exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `00561e90`, `00561e40`, `00561f20`, `0059db50`, `00566880`, `004adf50`, and owned `.rdata` `005bcd90[38]` using `<260B` paths, controlled arenas, and deterministic callee stubs; unrecovered child `audio_resource_kind_00566520`, filesystem/stream/BE-reader boundaries, null `audio_resource_query_root_00656ab4` fault behavior, and production CMake/registry integration remain open.
