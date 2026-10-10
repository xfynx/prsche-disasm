# Run 122: auxiliary event signal

This run recovers `Porsche.exe` function `0053c270` (17 bytes,
`0053c270..0053c280`) from original SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The indexed body loads `0069e5dc`, returns without a call when it is null, and
otherwise passes the handle to canonical `0055fb30`; its return is ignored.
The routine has no arguments, uses cdecl, and returns with `RET`.

Index references show the cell is owned by a neighboring worker lifecycle:
anonymous body `0053c0f0` writes the event returned from `0055fb20` at
`0053c0f5`, reads it at `0053c104`/`0053c14f`, and clears it at `0053c15d`;
cleanup `0053c1d0` also reads it at `0053c179`. The cell at `0069e5dc` lies in
the `.data` virtual tail beyond raw section bytes, so it starts zero-filled.
There is no existing C++ owner or alias in the recovered source. This packet
defines exactly that one pointer cell and does not claim to recover the worker,
its wait loop, callback table, or cleanup lifecycle.

The probe compares null and two non-null handles against the original x86 body.
`0055fb30` is a typed fixture boundary: it records the called handle and
returns a controlled value, which `0053c270` ignores. The verifier checks the
function range and bytes, all indexed cell references, the caller edge to
`0055fb30`, PE zero-fill placement, stack/callee-saved behavior, state
preservation, and ordered signal calls.

```powershell
cmake -S iterations/v2/001-original-recovery/runs/122-auxiliary-wait `
  -B local/builds/v2/auxiliary-wait-122 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/auxiliary-wait-122 --config Release
py -3 scripts/research/verify-v2-auxiliary-wait.py `
  --probe local/builds/v2/auxiliary-wait-122/bin/Release/auxiliary_wait_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/122-auxiliary-wait
```
