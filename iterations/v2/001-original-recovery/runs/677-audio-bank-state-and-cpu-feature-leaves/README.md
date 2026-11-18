# Run677 audio bank state and CPU feature leaves (`00565b30`, `00565ad0`, `00590140`, `00574e50`, `00574e6b`, `00574e89`)

Bounded native x86-vs-C++ recovery proof for the 6-function audio bank state and CPU/feature probe leaf packet (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 248 code bytes total):
- `porsche::audio_bank_get_size_00565b30` (`00565b30..00565b52`, 35B, `__cdecl`, sha256 `297d8c891b6e9fd4ebef2db3520f38c0fe843da5dc68a71f469087e7dadc2ac6`): checks active flag `application_audio_device_state_006b48c0[0xdcu]` (`006b499c`), returning `-10` if zero, else indexes the 12-byte bank table pointer at `+0x144u` (`006b4a04`) and returns signed dword `[entry + 8]`.
- `porsche::audio_bank_copy_00565ad0` (`00565ad0..00565b20`, 81B, `__cdecl`, sha256 `c2e8154b16d4023e71d92a8b9a4021c9d867d7a62a24f2271abde91f21a74cbb`): checks active flag `[0xdcu]` (`-10` if zero), calls `00565b30(bank_index)`, propagates negative sizes without mutation, otherwise copies `byte_size` bytes from `table[bank_index].ptr` to `dst_buffer`, updates `table[bank_index].ptr = dst_buffer`, and returns `0`.
- `porsche::audio_bank_find_free_slot_00590140` (`00590140..00590168`, 41B, `__cdecl`, sha256 `222ec12d808a6793fc0860627e39148a68ed6ffd13739b3d9d5e85cedec334d3`): reads `u16` slot count at `+0x18u` (`006b48d8 & 0xffff`), scans the 12-byte table at `+0x144u` (`006b4a04`) for the first zero dword `+0x00`, and returns its index or `-9`.
- `porsche::cpu_check_cpuid_support_00574e50` (`00574e50..00574e6a`, 27B, `__cdecl`, sha256 `18e33bf91423f5dfb61fd2a98e186b00d3238bac0b972ae91502cd938f3d4e11`): toggles EFLAGS bit 21 (`0x00200000u`) via `__readeflags`/`__writeeflags`, restores original EFLAGS, and returns the raw bit delta.
- `porsche::cpu_query_cpuid_00574e6b` (`00574e6b..00574e88`, 30B, `__cdecl`, sha256 `94884ce50dbc7092c39645556b3790b037a2928ce21c7d92a5eb782b89ab9cf1`): queries `cpuid` for `leaf` and stores `EAX, EBX, EDX, ECX` into `out_regs[0..3]`.
- `porsche::cpu_check_div_flags_00574e89` (`00574e89..00574eaa`, 34B, `__cdecl`, sha256 `0d48bd62ae5b5922c48e5b19bf9752f1a4ac480194bb37e1d4db0b1712194b0e`): executes `xor eax, eax; sahf; mov eax, 5; mov ebx, 2; div bl; lahf; cmp ah, 2` via x86 inline `__asm`, returning `1` when `AH == 2` else `0`.

Owned `.data` / `.rdata` and reused canonical symbols:
- Owned `.data`: none.
- Owned `.rdata`: none.
- Reused canonical symbol: `porsche::application_audio_device_state_006b48c0` (`006b48c0`, declared in `iterations/v2/001-original-recovery/source/include/porsche/application_audio_device.hpp`, defined in `iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_audio_device.cpp`), indexed via `data() + 0x18u` (`006b48d8`), `[0xdcu]` (`006b499c`), and `data() + 0x144u` (`006b4a04`).

## Verification

- Attempt `001` passed `/Od` and `/O2` (76 cases) and failed `wrong-565b30-stride` with `native-fault c0000005` (`* 8u` read non-pointer slot field `+8`); preserved intact under `local/experiments/v2-audio-bank-cpu-leaves-677/001/`.
- Attempt `002` passed `/Od` and `/O2` (76 cases) and failed `wrong-574e89-cmp-value` (`cmp ah, 0` matched `0` on the host CPU because `sahf; div bl; lahf` yielded `AH == 0x12`); preserved intact under `local/experiments/v2-audio-bank-cpu-leaves-677/002/`.
- Attempt `003` (`local/experiments/v2-audio-bank-cpu-leaves-677/003/receipt.json`, sha256 `8fa4b42264186bb4ae927f31dd2754d058f1c2667ec3ff42ff8a852d4de439a6`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `audio_bank_cpu_leaves_677.cpp`, 76 cases across inactive/active bank size queries, negative/zero/unaligned/aligned bank copies, `u16` slot scans with high-word garbage, EFLAGS ID-bit toggle across clean/dirty seeds, single-core-pinned CPUID leaves `0/1/2/3/0x80000000/0x80000001`, and `sahf/div/lahf` probe; 17/17 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/677-audio-bank-state-and-cpu-feature-leaves/native-config.json --attempt 003`

## Boundaries

Bounded test domain (`PARTIAL`): covers controlled `application_audio_device_state_006b48c0` and 16-slot bank table arenas plus single-core-pinned host x86 execution of the CPU probes. Unmapped/null table or bank pointers, out-of-range `bank_index`, overlapping copy buffers, post-call volatile arithmetic EFLAGS/EAX return of void `00574e6b`, CPUID subleaf-sensitive `ECX != 0` leaves beyond `0/1/2/3/0x80000000/0x80000001`, non-CPUID/Cyrix legacy CPUs, and production CMake/registry integration remain open.
