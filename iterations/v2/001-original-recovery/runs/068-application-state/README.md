# Run 068: application BSS arena layout

This run establishes the candidate arena at `0x006573e8`, size `0x3e24`
(15,908 bytes, 3,977 aligned 32-bit words), with exclusive end
`0x0065b20c`. The original `app_main_004b6a50` pushes size `0x3e24`, fill
value zero, and target `0x006573e8` before calling `0x0053c290` at
`0x004b6ab3..0x004b6abe`. The binary index identifies `0x0053c290` as a
77-byte function; its assembly dispatches to scalar `0x005b0980`, MMX
`0x005b0a40`, or SSE `0x005b0b00` according to `0x005deb18/0x005deb1c`.
All three paths write the same requested span. Nonzero values repeat the full
little-endian dword in aligned cells, with the low word/byte for tails; this
is not byte-repeated `memset` behavior.

The PE `.data` section has virtual range `0x005cb000..0x006c1538`, backed by
file bytes only through `0x005e7000`. The candidate span is wholly inside its
zero-fill tail. The probe confirms it starts zero in the mapped PE image, then
executes the original x86 fill function with surrounding canaries. The
exclusive end is exactly `0x0065b20c`, where `argv_0065b20c[32]` begins; all
128 bytes of that pointer array remain unchanged. `fe_enabled_0065b298` is
outside the cleared span, 0x8c bytes after its end.

`layout.json` lists all 133 known or directly addressed field starts with VA,
offset, observed access width, best supported type, owner, extent, and overlap
status. It groups the 60 source-typed/named fields and 73 original-x86 address
references whose field owner/type remain opaque. Unassigned gaps stay opaque.
The known groups include FE-table globals in `fe_tables.inc` from
`0x006573e8` through `0x00657440`, plus entries at `0x00657494`, `0x00657840`,
`0x00657a24..0x00657a34`, `0x00657c74..0x00657c80`, and
`0x0065807c..0x00658088`; application-main state; and render selector,
dimensions, mode, and render-mode settings. It records exact storage aliases:
`global_006573e8`/`FEGAME_TYPE`, and the render width/height reference names at
`0x00657a48`/`0x00657a4c`.

The proposed storage is one `std::array<uint32_t,3977>`. `word(VA)` returns a
reference to an actual word element; `byte(VA)` and `characters(VA)` expose its
object representation through unsigned-char/char access, so aliases share one
storage object without union punning or duplicate globals. The isolated source
is a layout candidate only; common field owners and build wiring are untouched
pending integration review.

The `0x00657a84` value is only evidenced as a NUL-terminated string start. The
binary shows a first-byte test and a scan to NUL, but no capacity. Its length
therefore remains unknown and its possible overlap with later field addresses
is marked in `layout.json`. `0x00657a60` is a dword (`CMP dword ptr` at
`0x004b6b68`); `0x00657a64` and `0x00657e34` are byte accesses.

The differential verifier runs 12 cases through the original x86 dispatch
paths and the standalone native C++ candidate. It compares every arena byte,
checks the prefix/suffix and argv canaries, covers nonzero dword patterns, and
exercises partial/unaligned scalar fills. The candidate uses an explicit loop;
it does not call a host `memset`.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/068-application-state `
  -B local/builds/v2/001-original-recovery/application-state-068 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/application-state-068 --config Release
py -3 scripts/research/verify-v2-application-state.py
```
