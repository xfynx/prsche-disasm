# Run602 render input route (`00586cd0`)

Bounded native x86-vs-C++ recovery proof for `porsche::render_input_dispatch_00586cd0`
(`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `00586cd0..00586d0e` (63 bytes, sha256 `4652d9a2bcf3728612a4d51f475b8136e751fc40648f5102352dfdbc9517db52`)
- Owned loader-zero `.data` arrays (`0x006ad440..0x006ad743`, 772 bytes total):
  - `render_input_handlers_006ad440[65]` (`0x006ad440..0x006ad543`, 260 bytes)
  - `render_input_low_map_006ad544[256]` (`0x006ad544..0x006ad643`, 256 bytes)
  - `render_input_high_map_006ad644[256]` (`0x006ad644..0x006ad743`, 256 bytes)

## Verification

- Attempt `001` (`local/experiments/v2-render-input-route-602/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/602-render-input-route/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `render_input_route_original_x86_vs_cpp=PASS cases=335 events=158`,
    comparing relocated original x86 against C++ across low events (`0..0xff`), high events
    (`0x100..0xffff`), out-of-range positive events (`>= 0x10000`), unmapped slot `0` returns,
    and slots `1..64` with `nullptr` and test handlers, checking `EAX`, ABI, state, and `FXSAVE`/MXCSR.
  - Mutation controls (`wrong-low-range-limit`, `wrong-high-range-limit`, `wrong-slot-zero-return`,
    `omit-handler-invoke`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain covers non-negative low events (`0..0xff`), high events (`0x100..0xffff`),
out-of-range positive events (`>= 0x10000`), unmapped slot `0` returns, and slots `1..64` with
`nullptr` and controlled test handlers. Negative signed events (`< 0`) out-of-bounds indices,
slot values `>= 65` out-of-bounds handler reads, external map/handler writers, malformed
pointers/faults, arbitrary aliases, and production CMake/registry integration remain open.
