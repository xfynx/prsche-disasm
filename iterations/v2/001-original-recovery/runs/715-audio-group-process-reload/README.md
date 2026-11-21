# Run715: audio group process/reload (Run713 typed child)

The unowned 182-byte typed child `00599610` newly exposed by integrated Run713/714
is recovered as a full original body. The declaration matches the accepted Run713
caller byte for byte (no owned cell is redefined):

```cpp
std::int32_t __cdecl audio_group_process_reload_00599610(void* record,
    const void* ctx, void* scratch);
```

`00599610..005996c5` builds a stack table of `ctx+offset` pointers from the DWORDs
at `record+0x68` (count = signed `record[3]`), zeroes its incoming argument slot once,
calls `0058a970` in a reload loop, and on `worker&1 && record[3]==1` allocates through
`0058f7a0`, passes six zero-extended record fields to `0058f220`, stores the result at
`allocator+4` and erases the key via canonical `0058f7e0` when the result is zero.
EAX is always 8. Body SHA-256
`3bda549f88cb3a64f663162733618edf91e71169e84d075364ce57b3b6e38f53`.

## Evidence

Raw PE `.text` bytes and module SHA pinned; caller is accepted `00590a80` (CALL rel at
offset 0x4e). Five rel32 calls (`0058a970` x2, `0058f7a0`, `0058f220`, `0058f7e0`)
are relocated from immutable PE bytes. `functions.json` (1167 entries) and all 17
`original-index-supplement.json` files have no owner or overlapping `body_ranges`;
the next owned body `005996d0` (Run452) starts 11 bytes after this RET. `0058f7e0`
is the canonical Run452 provider (declaration only); `0058a970`/`0058f7a0`/`0058f220`
stay unowned. No absolute data references, so zero new cells. Full detail in
`scope-evidence.json` and `evidence.json`.

## Proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/715-audio-group-process-reload/native-config.json --attempt 006
```

Receipt PASS: `local/experiments/v2-audio-group-process-reload-715/006/receipt.json`.
128 measured cases at both `/Od` and `/O2`; 13/13 material mutation controls detected;
186 input pins, 185 output pins. Attempts 001 (missing evidence file), 002 (missing
`<initializer_list>`), 003 (word overwritten at +0x54), 004 (no early-exit case) and
005 (high-bit word coincided with early exit) are preserved as failed fixture inputs;
no semantic divergence was ever observed.

## Boundaries

Signed `record[3]` 1..4, early exit, 2..4 worker calls, worker-bit/count-reload
branches, zero/nonzero configure returns and word/byte zero-extension are covered.
Real callee interiors, counts outside the original's unguarded table range,
uninitialized pointer-table cells, faults, concurrency, live devices, full game
integration and CMake/registry acceptance remain open. No graph integration is
claimed by this batch.
