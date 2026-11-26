# Run851 session reset providers

The canonical Run400 source for `00414eb0` matches the original-x86 proof in
Run692 attempt 015. Run698 compiled Run692's FE source and reset data owners
while omitting the Run400 reset TU from its build list. The Run692 receipt SHA
is `b059cf96c831ab4a3db3f4b56e0f8f327e638ae4766a29b04a4bbbae643dcddd`.
All 322 input and 269 output pins still match. Its proof covers the reset
body with controlled child endpoints. The main caller is `004b6db4` in
`004b6a50`. The Run400 TU calls ten services in the order shown below.

## Original evidence and ownership

The Porsche.exe SHA-256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The Ghidra index query
`query-binary-index.py --binary Porsche.exe --address <VA> --disassemble --limit 150`
and the original PE bytes establish these inclusive body ranges. The registry
had no entry or body overlap for any of the ten services. The
[native config](native-config.json) pins the three new bodies and their
file-backed initial state. The symbols already declared in Run400 are
defined by [session_reset_851.cpp](session_reset_851.cpp).

- `00414eef → 004a4780..004a47cf` passes the unsigned word at
  `00657a34` to a cdecl caller-cleanup function. It sets `005d1028` to
  `0x3ade68b1`, `005d102c` to `0x075bcd15`, and `00655a10` to zero.
  It advances the state by `value % 500` steps using the low halfword
  of each 32-bit product. `00655a0c` receives the full final product
  when the loop runs and retains its previous contents for zero steps.
  `00403000` and `00407290` use these random-state cells.
- `00414efb → 0044fd00..0044fd4a` reloads the same argument word. This
  independent cdecl RNG has its own cells at `005ceae0` and `005ceae4`,
  starts from the same constants, and uses the shift/add form of
  `-13035 * state` modulo 65536. `00454860` reads and updates its state.
- `00414f08 → 004069d0..004069da` is a no-argument cdecl function that
  clears `005e67b0`. Indexed consumer `0049dd20` reads it at `0049e084`.

The seven scalar addresses have no prior owner in the source/header
closure. Both initialized random-state pairs hold `0xf874af01, 1` in the
original file. `005e67b0` is file-backed zero. The 4-byte cells
`00655a0c` and `00655a10` are loader-zero in the `.data` virtual tail
(`005cb000` base, `0x1c000` raw bytes, `0xf6538` virtual bytes).
Separate canonical owners supply the caller's other state: Run692's reset
cells, Run598's `005e99b8`, `startup_sequence.cpp`'s two sequence words,
and `application_state.cpp`'s word storage.

## Native proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/851-session-reset/native-config.json --attempt 002
```

Five blocks of 500 unsigned inputs each cover all step-count remainders,
including high-bit values and `UINT32_MAX`. The fixture compares all seven
cells and checks cdecl stack and nonvolatile registers after each call.
The original harness relocates only direct data operands into fixture state.
The production initial values are checked before applying sentinels.
Material mutations change the product width, zero-step preservation, divisor,
second multiplier, and reset value. Attempt 001 used the earlier case-count
label and is preserved. Attempt 002 passed 7,500 comparisons per optimization
and detected all five mutations. Its receipt is
`local/experiments/v2-session-reset-851/002/receipt.json`, SHA-256
`b7ffe20a59f5357c7e06f8d0d429443ba5b4f8aea64c19bda03911d8e3dbd1cf`.

## Remaining services

In call order, the other seven direct seams are:

- `00414f03 → 004030b0..004030cf` gates a call to `0040e3b0` with
  `005e66b0` and application word `00657414`. The child gets ECX from
  `005e752c` and returns with one stack argument popped.
- `00414f0d → 004066d0..00406709` uses the signed count `005e8b58`,
  rereads it after each virtual slot-1 invocation through the pointer
  table at `005e6774`, clears each visited non-null slot and calls
  canonical `00516950`. Establish the player count and pointer-table bounds.
- `00414f12 → 004110a0..00411122` copies the player object table into
  two additional tables, then calls `00410730` for two sets of players.
  Trace the two array extents and mutable count reloads around those calls.
- `00414f17 → 00406710..00406719` calls `0040b4b0` and tail-jumps to
  `00406520`. Trace both unresolved callees.
- `00414f1c → 004069e0..00406ae6` stores a mode predicate, traverses
  player objects with `0040ab00`, copies four cells, calls `00516950`,
  and zeros a set of standalone words. Establish the remaining cell and
  player array owners.
- `00414f21 → 004690a0..004690c9` calls `00479dd0`, `0045dd00`,
  `00459260`, and `00452680`. The last call uses the player table indexed by
  application word `0065741c`.
- `00414f26 → 00412150..00412189` is a candidate for the next batch.
  Bind the existing Run695 FF block (offsets `04`, `08`, `0c`, `10`,
  `14`, `12c`), Run831 player table and Run683 `00533320` pause entry.
  Compare the gated call's argument and pre-call writes to both.

The standalone comparison covers the three leaf bodies. The coordinator owns
the shared build, caller and leaf COFF checks, and startup acceptance.
