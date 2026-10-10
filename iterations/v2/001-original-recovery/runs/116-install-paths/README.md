# Run 116 — install path producer and cleanup

Source: `Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index entries identify `004b6ff0..004b7062` (115 bytes),
`004b7070..004b7080` (17 bytes), and `00556640..00556647` (8 bytes).
The startup caller `004a5410` reaches the producer. It opens the literal
`install.txt` with mode 0, stores the returned blob at `0065b29c`, and obtains
the payload length from the DWORD at `blob-12` through `00556640`.

The producer clears exactly 60 DWORD cells at `0065b2a0`, computes the 32-bit
end pointer `blob + length - 2`, then walks from the blob start. Each row skips
three prefix bytes and stores the resulting pointer. It scans to CR or LF,
nulls the first delimiter when it lies before the end pointer, skips adjacent
CR/LF separators, and resumes only while the cursor remains below the end.
There is no clamp in the recovered loop. The producer does not reset EAX after
its initial `XOR`; the returned value is the final low-byte scan value. That
register value can depend on the byte following the declared blob in the
resource allocation, and the `004a5410` startup caller ignores it. The fixture
compares EAX with matching zero-filled surrounding memory and does not claim a
universal return value for arbitrary allocator padding. Cleanup calls
`00531f90` only when the blob pointer is nonnull and does not clear that cell.

The read-only `local/game/install.txt` is 1,226 bytes with SHA-256
`30e603756352a84c00d6d6b85a37e8dd19a375b544b318be88a1081a56bf1aae`.
Its real bytes produce 49 path entries; the final blank CRLF is outside the
loop's `length-2` limit. The verifier also compares LF-only, mixed CR/LF and
blank separators, the empty two-byte case, standalone metadata reads, and
null/non-null cleanup. Resource open and free are typed recording boundaries;
archive and heap internals remain outside this run. Runs above 60 entries and
unterminated data are not claimed. Existing startup-root and display-name
owners are left unchanged for integration.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/116-install-paths `
  -B local/builds/v2/001-original-recovery/install-paths-116 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/install-paths-116 --config Release
py -3 scripts/research/verify-v2-install-paths.py --report-dir `
  iterations/v2/001-original-recovery/runs/116-install-paths
```
