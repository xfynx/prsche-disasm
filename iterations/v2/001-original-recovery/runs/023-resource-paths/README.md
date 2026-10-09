# Run 023 — startup resource path consumer

Original: Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: `004b6aae` in Porsche.exe Ghidra `calls.jsonl` reaches
`0059d650`; Win32 GetModuleFileNameA/GetDriveTypeA, CRT formatter
`005a0fbf`, and file-exists `00561b80` are its indexed callees. Source
instructions are in v2 `disassembly.asm` at `0059d650..0059d81c`.

With a valid NUL-terminated module path containing a backslash, the function
sets 0x6af370 to 1, takes the basename after the last backslash and truncates
the local directory there. It clears the first byte of 0x6af168, scans
`d:` through `z:` until the first GetDriveTypeA result 5, formats and checks
that drive plus the executable basename, and copies the drive to 0x6af26c.
The file-exists result does not control that branch. The subsequent code
clears 0x6af26c, checks `d:` once more, then clears 0x6af26c again and checks
the module directory plus `fe.txt`. The final file-exists result is returned.
These peculiar branches follow the original instructions and patch NOPs at
0x59d784–0x59d78c; they are not a proposed CD detection policy.

The new C++ unit reuses the existing 260-byte file globals declared in
`files.hpp`. The standalone fixture defines them and records typed Win32,
CRT format and file-exists endpoints. Unknown Win32 outputs, missing
backslashes, truncation and overlong formatted paths remain outside the
accepted fixture; there is no guessed fallback behavior for those cases.

Verification:

    py -3 scripts/research/verify-v2-resource-paths.py

All 48 valid cases match original x86 for native return, all 521 global bytes,
and endpoint call order/arguments. `verification.json` records original SHA
and source/build/probe SHA. This is a unit proof, not a game launch.

Next startup step: bind 0x59d650 into `004b6a50` immediately after the
preceding platform calls, then compare the FE `fe.txt` request and file-root
consumer state with the original under the same mocked OS/disk inputs.
