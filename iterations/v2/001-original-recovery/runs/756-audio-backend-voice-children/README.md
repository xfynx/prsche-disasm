# Run 756: audio voice backend child trace

Status: **research only; no recovered source or native acceptance**.

This packet traces Run751's two controlled endpoints, `00589f40` and `005897c0`,
to decide whether they can be proved as a bounded backend packet without
inventing device behavior. The immutable original is `local/game/Porsche.exe`,
SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Run751's actual reachable caller is `005612a0`; it consumes signed EAX from
`005897c0` and invokes `00589f40` on voice-start paths.

## Static observations

- `00589f40` is a complete 150-byte body (`00589f40..00589fd5`). It indexes a
  0x70-byte voice row from `006b4a00`, conditionally computes cached pitch from
  row offsets `+0x66/+0x68`, `+0x58/+0x3f`, `+0x64`, `+0x60/+0x4b`, and writes
  the derived product at `+0x6e`. It calls `00589e80`.
- `00589e80` is a complete 178-byte body (`00589e80..00589f31`), with no direct
  calls. Its integer reduction uses `0x1b4e81b5`; final byte lookups use tables
  at `005e1d3c` and `005e1e3c`. No accepted owner/source for those table bytes
  was found in the active source closure or canonical audio packets inspected.
- `005897c0` is a complete 235-byte body (`005897c0..005898aa`). It reads and
  updates a channel row via `006b489c`, reads the 0x70-byte voice row through
  `006b4a00`, reads a WORD table at `006b4a14`, then forwards nine arguments to
  `00589fe0` and propagates that child's signed EAX.
- `00589fe0` is a 1,229-byte body (`00589fe0..0058a4ac`), with 14 resolved direct callees and three
  unresolved call outcomes. REA identifies six computed call sites whose
  targets remain unknown. It initializes backend callback/function-pointer
  fields and calls downstream audio helpers, so a controlled stub would prove
  only transport, not voice-start behavior.

Run434 owns the canonical device-state block containing `006b489c` and
`006b4a00`; Run434 defines the named channel record but not the complete voice
row used here. Run558's state views are explicitly blocked/unaccepted research,
so they cannot be reused as accepted state ownership. The `00589e80` lookup data
also lacks an accepted owner. These are concrete closure blockers for a native
differential proof of pitch recomputation. The much larger `00589fe0` callback
graph and its unresolved indirect targets block a semantic proof of backend
start without adding many unrelated providers.

## Evidence and disposition

`rea-evidence.json` is the exported REA Evidence bundle (11 records, 887,779
bytes) against the hash above. It includes complete dossiers for both targets
and the traced children. The binary index's `functions.jsonl`, `calls.jsonl`,
`references.jsonl` and raw module identity agree on entry/body ranges and the
direct edges. REA analysis reports `00589f40`: 51 instructions, ten blocks,
one direct callee; `005897c0`: 84 instructions, 14 blocks, one direct callee.

No native executable, original-x86 comparison, mutation run, source candidate,
registry entry or CMake ownership was created. Both endpoints remain controlled
boundaries as in Run751. A next bounded packet should first establish ownership
and raw bytes for the two lookup tables and exact voice-row layout; backend
start additionally requires narrowing `00589fe0` to a finite producer path and
proving or explicitly retaining its callback dependencies.
