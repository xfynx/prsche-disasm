# Run 099 — `0056a490` pointer cleanup

This run restores the 41-byte no-argument function `0056a490..0056a4b8` from
Porsche.exe SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Run 097's ordered startup body calls it at `004b67c2`.

The indexed references show this function as the only reader or writer of
`006af114`, `006af118`, and `006af11c`. Its instructions load `006af114`; if
nonzero, they call the recovered `free_00531f90` and clear the first two
DWORDs. The final DWORD is cleared unconditionally. Therefore a null pointer
preserves the prior `006af118` value. The neutral native names do not assign a
larger subsystem meaning to these three cells.

PE metadata places the addresses in the `.data` virtual extent but beyond its
raw-data extent: `.data` starts at RVA `0x1cb000`, has virtual size `0xf65f8`
and raw size `0x1c000`. The three cells therefore begin in zero-filled BSS;
the new owner initializes them to zero. No other indexed reference or existing
source owner was found.

The original-x86 comparison checks null and non-null pointer branches, unusual
free return values, all three post-call words, the pointer passed to free,
saved ESI, and the restored entry stack. `free_00531f90` is intercepted as an
explicit fixture boundary; the production source directly calls its existing
recovered implementation.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/099-startup-service `
  -B local/builds/v2/startup-service-099 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/startup-service-099 --config Release
py -3 scripts/research/verify-v2-startup-service-56a490.py `
  --report-dir iterations/v2/001-original-recovery/runs/099-startup-service
```
