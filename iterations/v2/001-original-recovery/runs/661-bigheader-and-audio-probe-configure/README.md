# Run 661 bigheader loader & audio probe configure (`00568b50`, `00533d70`, `00562100`, `00562300`, `0059df70`, `004ae100`)

Bounded native x86-vs-C++ recovery proof for 6 functions (1,294 code bytes total) in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::request_read_offset_00568b50` (`00568b50..00568b8f`, 64B, `__cdecl`, `ret 0`, sha256 `cf01d07415baaa842e3d0bf657b791673f6e65a7f017c1452bbc21637acea309`): resolves device via `handle_device_005925d0(handle)`, allocates type-3 `FileOperation` via `operation_allocate_005682a0(3, static_cast<uint8_t>(group), context, dev)`, sets `op->handle`, `op->offset`, `op->count`, `op->buffer`, and queues via `operation_queue_00568200(op)`.
- `porsche::file_read_offset_00533d70` (`00533d70..00533d96`, 39B, `__cdecl`, `ret 0`, sha256 `eccb1917f614a14e57520bfa2d091ea95a29c5aa503e845545ee78646404d142`): forwards `(handle, offset, buffer, size, group, request_read_offset_00568b50)` to `file_chunks_00533c20`.
- `porsche::file_load_bigheader_callback_00562100` (`00562100..005622f2`, 499B, `__cdecl`, `ret 0`, sha256 `f271a2837f34805934438e0b5aa4046c42ea24ceb5bd1d4c24794c3ec141ac00`): absent from main `functions.jsonl`; supplemented in `original-index-supplement.json`; opens via `file_open_00533b90(path, 1, group, &handle)`, allocates/reads `0xa90` bytes via `read_00533bf0(..., group - 1)`, checks `audio_resource_kind_00566520`, queries `audio_resource_size_00566560`, grows via `allocate_00531ca0` + `heap_copy_dispatch_005323e0` + `free_00531f90` + `read_00533bf0(handle, 0xa90, dst + 0xa90, total_size - 0xa90, group - 1)` when `total_size > 0xa90`, closes on `group - 1`, and logs 2-arg `diagnostic_handler_005debf0` (`005bcd00`, lines `0x21d`/`0x215`/`0x1f0`/`0x208`) when `callback_diagnostic_flag != 0`.
- `porsche::file_load_bigheader_quiet_00562300` (`00562300..0056233e`, 63B, `__cdecl`, `ret 0`, sha256 `8e7d66f6a0c965ffc80d66fc1f840d7a71b345f8f06dd9aabb4cfbc9470c1b4d`): quiet wrapper dispatching `file_load_bigheader_callback_00562100` through `resource_leaf_atomic_dispatch_00568d50` (`callback_diagnostic_flag = 0`).
- `porsche::resource_load_bigheader_quiet_0059df70` (`0059df70..0059e03d`, 206B, `__cdecl`, `ret 0`, sha256 `4ee6eec6f583d51b2884372fc0e5ab5d7888eed678eeb3e72b91c10cd3bd08d2`): rooted/unrooted `file_load_bigheader_quiet_00562300` wrapper invoking `missing_file_006afbe4(name, -2)` when rooted lookups fail.
- `porsche::application_audio_probe_configure_004ae100` (`004ae100..004ae2a6`, 423B, `__cdecl`, `ret 0`, sha256 `1e5b5515b4e6dc31474edd890cf3864714f9c5f27aada5f4057e8a2ecca18f0d`): allocates `0x1b4` `"Music Globals"` into `audio_resource_query_root_00656ab4` when null, resets via `004adf50`, estimates stream buffer with signed `first / 1024` (`cdq; and edx, 0x3ff; add eax, edx; sar eax, 10`), allocates `"Music Buffer"` into `root + 0x6c`, configures transition via `004ae010`, resolves `"%szzz%s.viv"` via `00403520`/`0059e440` into `root + 0xa8`, loads bigheader via `0059df70` into `root + 0x88`, stores `00566880(hdr)` into `root + 4` when non-null, and releases the temporary string buffer via `0059ecd0` (`> 0x100`) or `005e4fe8 + 0x28` freelist (`<= 0x100`).

## Index, Ownership & Canonical Headers

- Owned `.data` BSS (4B): `audio_probe_viv_prefix_0065b314` (`0065b314`, `nullptr`).
- Owned `.data` strings (39B): `audio_probe_viv_fmt_005d1bf0[12]` (`"%szzz%s.viv"`), `audio_probe_buffer_name_005d1bfc[13]` (`"Music Buffer"`), `audio_probe_globals_name_005d1c0c[14]` (`"Music Globals"`).
- Owned `.rdata` strings (161B): `file_load_bigheader_open_err_005bcde4[45]`, `file_load_bigheader_mem_err_005bce14[59]`, `file_load_bigheader_hdr_err_005bce50[57]`.
- Unrecovered child declared in `bigheader_audio_configure_661.hpp`: `std::uint32_t __cdecl audio_resource_size_00566560(std::uint32_t source);`.

## Verification

- Attempt `001`, `002`: `od-native` exited `0xC0000005` (`3221225477`) due to fixture harness `invoke_cdecl*` clobbering `ebp` before `[ebp]` stack-argument access and nulling `local_str.begin` before `004ae100`'s copy; preserved immutable under `local/experiments/v2-bigheader-audio-configure-661/{001,002}`.
- Attempt `003`: **PASS** (`local/experiments/v2-bigheader-audio-configure-661/003/receipt.json`, sha256 `97a384e0cace1acdac59f910924c01821fb646dd2ca2400ed58a1148f2eec6a2`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/661-bigheader-and-audio-probe-configure/native-config.json --attempt 003`
  - `/Od` and `/O2` compiled with 0 `/W4` warnings and passed `bigheader_audio_configure_original_x86_vs_cpp=PASS cases=35`.
  - All `20/20` material mutations exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `00568b50`, `00533d70`, `00562100`, `00562300`, `0059df70`, `004ae100`, owned `.rdata`/`.data` strings, and `0065b314` using `<260B` paths, controlled arenas, and deterministic callee stubs; unrecovered child `audio_resource_size_00566560`, filesystem/stream/transition/allocator boundaries, and production CMake/registry integration remain open.
