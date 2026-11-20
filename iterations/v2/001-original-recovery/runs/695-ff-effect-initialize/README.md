# Run695: force-feedback effect initialization (`00411d20`)

Recovers the original 00411d20..00412020 body (769 bytes including the final
`C3`, raw-PE SHA-256 `803aba33930fa4caf35b47a41398bd6cade470407cc3452a20b49685cb921dd1`,
file offset `0x11d20` in the pinned `ddd748fd…` Porsche.exe) as
`porsche::ff_effect_initialize_00411d20`. It is the sole callee of the accepted
`startup_sequence_call_004121b0` (`CALL 00411d20` at `004121b1`); no other
caller exists in the binary. Subsystem: startup / force-feedback setup.

## What the body does

Zeroes 0x134 bytes of state at `005e9408`, fills the 32x8-byte result table at
`005e9420` with `-1`, then — if any input device is attached — scans slots
0..31 for the first (last-recorded) device with both capability bits in the
`+4` word that can be enabled for FF. If one is found, it builds four
`FeEffectParams` blocks (types 0, 3, 4, 9), calls the accepted `005334e0` four
times, stores the low 16-bit result into table words `+0/+2/+4/+6`, and applies
the configured gain via the accepted `005333a0`.

The direction word uses the original NEG/SBB/AND/ADD idiom:
`(caps0 & 0xff00) == 0x600` yields 90, otherwise 0. The device state is
re-fetched via `00532e10(slot, 2)` separately for each of the four effects.

## Ownership decisions

- `00411d20` had no `functions.json` entry and no `body_ranges` entry.
- All seven callees are already accepted providers. Typed declarations and
  `FeEffectParams` are reused from runs 676 / 683 / 688 / 400 and
  `porsche/input_state.hpp`. The 688 record array `0069cb10`, GUID blobs and
  pointer table are **not** redefined.
- The 0x134-byte state block `005e9408..005e953b` had no defining symbol.
  Run400 declares extern frontier names for `005e940c`, `005e9410` and
  `005e9420[4]` but allocates nothing; this run allocates the full block once
  (`frame_control_ff_state_005e9408`), including the earlier cells and the
  complete 32-entry table. Reconciling Run400's extern names to this single
  storage is an integration boundary.
- Five loader-zero BSS config cells (`00657bc8`, `00657be8`, `00657c08`,
  `00657c28`, `00657c48`) had "no recovered owner" in the run 068 layout;
  their observed 4-byte reads are owned here, with unindexed writers.

## Native proof

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/695-ff-effect-initialize/native-config.json --attempt 012
```

PASS receipt: `local/experiments/v2-ff-effect-initialize-695/012/receipt.json`.
14 scenarios x `/Od` + `/O2` = 28 measured original-vs-C++ comparisons; 19
material mutation controls all detected. Each case compares the full event
stream (call order, all callee arguments, the entire 0x4c-byte effect request
blocks), the complete 0x134-byte state block, cdecl ABI/callee-saved registers
and the FPU snapshot. Synthetic stack/register seeding and RET framing are
harness code only. The harness seeds both sides' stack with 0xcc so the opaque
type-source dwords the original leaves unwritten for types 0/3/4 are compared
honestly; `seed_opaque_params` models that explicit boundary. Raw PE body
bytes and config-cell loader-zero state are verified before relocation.

Earlier attempts `001`..`011` are preserved and superseded: compile/label
fixes, a corrected 769-byte body span (the first span omitted the trailing
`C3`), relocation-count corrections, the per-effect `00532e10` re-fetch, the
opaque type-source model, and in-bounds mutation values.

## Remaining boundaries

Controlled endpoints stand in for all callees — live DirectInput devices, COM
vtables and real effect objects are unproved. Writer/producer paths for the
five config cells are unindexed. Single-storage reconciliation with Run400's
state names, full startup/display and gameplay acceptance remain open. No
changes were made to the registry, CMake, shared manifests, plans or the
immutable original.
