# Run 096 — original input snapshots

This run recovers `0055feb0` (`0055feb0..0055ff53`, 164 bytes) from `Porsche.exe`
SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The index entries in `research/binary-index/README.md` and
`research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/{functions,calls,references}.jsonl`
were followed into `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`
and `decompiled.c`. Its concrete callers use selector 6 at `004cd5e2` and
`00560085`; selector 2 and invalid selectors are preserved as explicit branches
of the provider API.

The function returns a pointer or null. Selector 2 first checks the existing
`startup_direct_input_006a5b14` owner, then calls recovered
`input_caps_0056fdb0(device=006a5b18, output=006a57f0)` and returns `006a57f0`
only when that call returns zero. Selector 6 uses
`input_poll_read_0056fce0(device=006a5b18, destination=006a5a14, size=0x100)`;
a nonzero result causes `heap_fill_0053c290(006a5a14, 0, 0x100)`. It returns
`006a5a10`, four bytes before the acquired state bytes. If the direct-input
pointer is null, both valid selectors return null and do not fabricate a state
snapshot.

The new storage owner is one 0x324-byte layout for `006a57f0..006a5b13`:
capabilities at `+0`, a four-byte gap, then the `006a5a10` return view at
`+0x220` with the 0x100-byte state at `+0x224`. The pre-existing startup input
pointer owners at `006a5b14/18` and recovered state/capability wrappers are
reused. No separate pointer or overlapping array owner is introduced.

Other selector values set the shared diagnostic file to
`\\real\\patch3\\pc\\key.c`, line `0x1bb`, then call the variadic format
boundary `"[KEY] - Invalid getstate (%d)\n"` and return null. That diagnostic
function remains injectable and the production path terminates if it has not
been bound. The capabilities success parser at `0056fdf9` is also kept as an
explicit boundary; the isolated fixture controls its return value without
claiming its parsing algorithm. DirectInput vtable entries use the existing
typed stdcall ABI. The verifier also rejects any unexpected original address.

The 13 differential cases cover null/present DirectInput, selectors 2/6 and
invalid values, GetCapabilities failure and the success-parser boundary,
poll/get-state success and failure, both DirectInput-lost codes, acquire/retry
ordering, cleared bytes, full snapshot contents, return pointer offsets, and
diagnostic file/line/format.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/096-input-snapshot `
  -B local/builds/v2/001-original-recovery/input-snapshot-096 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/input-snapshot-096 --config Release
py -3 scripts/research/verify-v2-input-snapshot.py `
  --probe local/builds/v2/001-original-recovery/input-snapshot-096/bin/Release/input_snapshot_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/096-input-snapshot
```
