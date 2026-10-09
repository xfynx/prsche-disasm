# Run047 — FE stream application in main `0x4b6a50`

Original: `Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '004b6660|004b6a50|004b5ee0|004b60d0|004b4b80|004b4cd0|00531ca0|00531f90|00569640|0059e040|00533de0|00533bf0|00533da0' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d -g '*.jsonl'`. `0x4b6660` is the complete FE stream builder already recovered in `fe_stream.cpp` and verified in Run003. Main `0x4b6a50` calls it at `0x4b6ad3`, applies records at `0x4b6ae4`, obtains each record's word length at `0x4b6aea`, advances at `0x4b6aef`, and releases the stream at `0x4b6afa`.

`application_fe_apply_release_004b6ad8` extracts that exact consumer loop and calls the existing recovered `fe_apply_004b4b80`, `fe_record_words_004b4cd0`, and heap `free_00531f90` implementations. `fe_build_004b6660` remains the actual source for parsing `fe.txt`, nested imports, and command-line overrides; its file and allocation interfaces are resolved by the existing recovered files/heap sources in the full library. The native probe records those typed file/heap services and callback effects. Its filesystem is an in-memory fixture, so this does not claim a live disk/VFS or main-thread launch.

The differential verifier enters original x86 at the main callsite `0x4b6ad3`, executes the original `CALL 0x4b6660`, then runs the original inline consumer through the free call at `0x4b6afa`. It compares packed stream words, record lengths, FE global/action state, file buffers, and boundary order; the original fixture also asserts the expected x86 stack delta at this partial boundary. It covers 64 stream/application cases, including the SHA-pinned real `local/game/fe.txt` (`3b00d768c85bb26100a27adfd419b6c32fd1572e6ef5d7d29da2a9b4f250a8ec`) and synthetic format fixtures inherited from Run003. OS/VFS/heap backend calls and FE input callbacks stay explicit test boundaries.

Coverage is complete for `0x4b6660`, `0x4b4b80`, and `0x4b4cd0`; `0x4b6a50` is explicitly partial, covering only `0x4b6ad3..0x4b6afe`. The later main setup, second FE pass at `0x4b6c1c`, and renderer calls (`0x467470` / `0x467fc0`) remain outside this slice.

Reproduce with Win32 MSVC:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/047-application-fe -B local/builds/v2/001-original-recovery/application-fe-047 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/application-fe-047 --config Release --target application_fe_probe
py -3 scripts/research/verify-v2-application-fe.py
```

`verification.json` records the original module/source hashes, explicit partial coverage, and per-case output hashes. This is a recovered FE-to-main consumer slice, not full `0x4b6a50`, renderer initialization, live VFS, or game launch.
