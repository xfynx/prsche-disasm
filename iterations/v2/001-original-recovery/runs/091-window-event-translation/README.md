# Run 091 — window event translation

This run recovers original function `00560080` (192 bytes, `00560080..0056013f`)
from `Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. The
binary-index call edge is `0053aaaf -> 00560080`; the dequeue body passes its
stored payload and type. Its pre-cleanup stack read at `0056008a` resolves to
the first argument (payload); the second argument is unused. The translator
calls `0055feb0(6)` before inspecting payload and reads the returned input-state bytes at offsets `3c`, `bc`, `21`, `a1`,
`2e`, and `3a`.

`0055feb0` is a separate 164-byte input/device-state routine. Its selector-6
path reaches `0056fce0`/`0056fdb0` and obtains device state in shared storage;
the translator treats this as a typed provider boundary, so the fixture supplies
an explicit non-null 0xbd-byte state snapshot. The provider semantics and
DirectInput closure are not claimed as recovered here.

The body selects one of five 0x5b-byte tables at original `.data` addresses
`005de128`, `005de1de`, `005de183`, `005de239`, or `005de294`. Those exact bytes
are copied into the translation source. State fields at `005de020` and the
existing `window_create_state_005de024` control table selection and the
`payload == 0x3a` toggle. When the `005de020` flag is set and snapshot byte `21` or
`a1` is nonzero, payload 1 reaches terminal exit `005a246e(0)`; the verifier traps
at that exit boundary. `005de024` uses its existing production owner; this run
owns only the previously undeclared `005de020` scalar.

The verifier compares original x86 against native C++ across every payload table index
0..0x5a except the special toggle index, alternate selector bytes, precedence,
the signed-byte-to-word mapping, the terminal exit path, and ignored payload
variation. Indexes outside the original 91-byte tables and a null provider
pointer are outside the bounded input contract.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/091-window-event-translation `
  -B local/builds/v2/001-original-recovery/window-event-translation-091 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/001-original-recovery/window-event-translation-091 --config Release
py -3 scripts/research/verify-v2-window-event-translation.py `
  --report-dir iterations/v2/001-original-recovery/runs/091-window-event-translation
```
