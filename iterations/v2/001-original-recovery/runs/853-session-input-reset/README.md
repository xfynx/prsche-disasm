# Run853 session input reset

Recovered the two direct services called by `00414eb0`:

- `004066d0..00406709` walks the signed active-player count, releases each
  non-null extension through vtable slot 1 with argument `1`, clears visited
  slots, and calls canonical `00516950`.
- `00412150..00412189` gates on FF enabled, copies player zero into `+0x0c`,
  writes `1` at `+0x12c`, clears `+0x10`/`+0x14`, then calls canonical
  `00533320` with the signed slot index.

Original evidence is Porsche.exe SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39` and the
binary index ranges above (58 bytes each). Existing canonical owners are reused
for the FF block, player table, input ABI and `00516950`; this run owns only the
new reset functions and the two state cells at `005e8b58`/`005e6774`.

## Native proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/853-session-input-reset/native-config.json --attempt 006
```

Receipt: `local/experiments/v2-session-input-reset-853/006/receipt.json`.
Both `/Od` and `/O2` report
`session_input_reset_original_x86_vs_cpp=PASS` over 96 FF and 200 player-state
cases (316 comparisons per optimization: 96 FF and 220 player-state), including signed counts, mutable
callback state, null slots and high-bit FF values. Three material mutations
(enable guard, FF state write, release argument) all failed closed with exit 10.

## Limits

The shared game build and startup remain coordinator-owned; no executable or
gameplay acceptance is claimed here. The remaining direct `00414eb0` services
and their player-table ownership are outside this run.
