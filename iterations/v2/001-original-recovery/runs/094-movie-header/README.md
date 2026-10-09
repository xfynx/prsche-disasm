# Run 094 — movie header initialization slice

This run recovers a bounded slice of original `004dc850` in `Porsche.exe`
SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The function body is 3151 bytes (`004dc850..004dd49e`), but the recovered
slice stops at the first renderer call `004dc180`; `004dc850` is therefore
reported as partial.

The binary-index query used `research/binary-index/README.md` and the
`Porsche.exe-ddd748fdbe6d` `functions.jsonl`, `calls.jsonl`, and
`references.jsonl` entries for `004dc850`, its callers `004dd600`/`004dd4a0`,
and renderer callsite `004dc9d9`. The supporting instruction and caller
evidence is in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`
and `decompiled.c`.

The direct original call `004dd600 -> 004dc850` is guarded by file-open success
for `searts.av_mad`. A second direct caller, `004dd4a0 -> 004dc850`, is guarded
by successful open of `sinPC.av_mad`. The startup caller `004b6a50` reaches
`004dd600` only while FE setup is enabled (`0065b298 != 0`), setup has not
already run in that loop (`bVar11 == 0`), and `0065743c == 0`. These are
originally observed skip conditions; no additional skip behavior is added.

At entry, `004dc850` creates a 1 MiB `Stream_Buffer`, opens the movie stream,
and scans chunks. The first accepted tags are `MAD`, `MADe`, and `MADk`
(`0x6d44414d`, `0x6544414d`, `0x6b44414d`). For the accepted chunk, the body
reads frame period at `+0x0c`, signed width at `+0x10`, and signed height at
`+0x12`. It writes those values to `0065e268`, `0065e280`, and `0065e3e8`,
resets `0065e3e4` and `0065ba5c`, sets `0065e28c` to one, then calls
`004dc180(x,y,width,height,6,arg3,arg4,arg5)`. The two centering branches and
signed divide-by-two behavior match the x86 instructions and are compared at
that call boundary.

The stream setup/read services (`00531ca0`, `0056aff0`, `0056b5b0`, `0056b230`,
`0056b690`, `0056c540`) are explicit fixture boundaries that select one valid
first MAD-family header. `004dc180` is also a typed renderer boundary. This run
does not recover stream parsing, rendering, frame timing/playback, audio,
keyboard polling, shutdown, or the remaining body. Those paths are not replaced
with success implementations.

The differential verifier tests all three tags, all three mode values,
positive/negative dimensions, odd and negative display dimensions, frame-period
values, and forwarded caller arguments. The original-x86 execution stops at
`004dc180` and fails on any unexpected call boundary.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/094-movie-header `
  -B local/builds/v2/001-original-recovery/movie-header-094 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/movie-header-094 --config Release
py -3 scripts/research/verify-v2-movie-header.py `
  --report-dir iterations/v2/001-original-recovery/runs/094-movie-header
```
