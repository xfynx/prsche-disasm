# Run 581: renderer driver state callbacks

## Scope and completion gate

Recover five bodies from original `Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`:
`00538af0` (41B), `00537850` (21B), `005405c0` (48B), `00540550` (49B),
and `00540590` (41B). Canonical state ownership is exactly the mutable 72-byte
packet `[005ded30,005ded78)`: twelve pair words followed by six callback words.
The `00540500` callback remains an unresolved host boundary. Reuse accepted
`00540480`, the `00516950` RET no-op, and existing `0069ed0c` global.

Complete-source closure and registry review are captured in `scope-evidence.json`.
The two unindexed raw bodies and all return paths are in
`original-index-supplement.json`. Adjacent consumers `00540660` and `00537890`
are recorded only and are deferred until a reachable parent requires them.

## Confirmed facts and scope limits

- `00538af0` has no stack arguments; its body uses neither incoming ECX nor
  EDX. It reads each pair and callback-table slot during its six-iteration loop.
- `00537850` takes ECX plus one stack DWORD, writes `[ECX+8]`, calls
  `00540480(4,value)`, and returns with `ret 4`.
- `00540550` and `00540590` are cdecl2 and have only plain `ret` exits.
- `00540590` follows the original service pointer chain only when its second
  argument equals one. The chain is seeded in the bounded fixture domain.
- `00540500` is not stubbed or implemented. No broad x87 behavior is included.
- No full global domain, device behavior, concurrency, or adjacent consumer
  semantics are claimed.

## Work and next action

- [x] Extract raw bytes, instruction boundaries, hashes, and all RET paths.
- [x] Check complete Run578 closure, registry, and 72-byte data ownership.
- [x] Add the five source definitions and canonical packet owner.
- [x] Prepare one original-x86 versus C++ fixture with ABI, late-callback
  mutation/reload, final state, and call-order controls. The 359/523 calls are
  controlled native boundaries in this fixture; production ownership remains
  supplied by accepted runs and will be checked at integration.
- [x] Scratch compile and link preflight succeeded. No fixture execution or
  numbered native attempt was performed.
- [x] Root reviewed source, fixture, config, bounds, and the ordinary-user
  launch behavior before shared native proof.
- [x] Shared attempt 005 passed in `/Od` and `/O2`, with 11 paired comparison
  scenes in each mode and all four configured mutation controls detected.
- [x] Preserve failed/aborted attempts 001–004; do not reuse their directories.
- [x] Root integration582 and production owner/COFF audit pass.

Exact command: `py -3 scripts/research/verify-v2-native-batch.py --config
iterations/v2/001-original-recovery/runs/581-render-driver-state/native-config.json
--attempt 5`. Receipt: `local/experiments/v2-render-driver-state-581/005/receipt.json`.
This is bounded native fidelity only; live device, startup, and gameplay
composition remain outside this batch.
