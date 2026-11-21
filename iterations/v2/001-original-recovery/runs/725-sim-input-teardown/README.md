# Run725: simulation input teardown

Run725 adds three full original bodies and no data owners:

- `application_sim_boundary_00412cd0` (`00412cd0`, 22 B): tests the enabled
  word at `005e940c`; when nonzero, forwards the signed index at `005e9410` to
  the accepted Run676 `input_slot_stop_ff_00533480` provider.
- `application_sim_boundary_00412e60` (`00412e60`, 5 B): tail-jumps to
  `input_shutdown_00532d30`.
- `input_shutdown_00532d30` (`00532d30`, 93 B): calls the cleanup boundary,
  then for each signed-count slot unacquires at vtable `+0x20`, releases at
  `+8`, and clears the slot device. It then unacquires and clears the root.

Source: `sim_input_teardown_725.cpp`. Original PE SHA-256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Exact
body bytes and disassembly are recorded in `scope-evidence.json`. The shared
state remains owned by Runs 695, 683, 494 and `source/recovered/Porsche.exe/`;
the test fixture supplies isolated storage and controlled COM/cleanup endpoints.
The cleanup body at `00533050` remains outside this packet.

## Native proof

Attempt 001 is retained as a failed broad-link attempt: it compiled unrelated
translation units and ended with 16 unresolved names. Attempt 002 is retained;
it exposed one missing test-only `fe_input_devices_005e8e60` definition.
Attempt 003 passed with the source set narrowed to Run725 plus the accepted
Run676 provider. The attempt receipt is
`local/experiments/v2-sim-input-teardown-725/003/receipt.json`.

- `/Od` and `/O2`: 4,050 original-x86/native comparisons each; ABI and
  production initial-state checks pass.
- Ten mutations all fail differentially: gate, index, thunk, cleanup, loop
  count, device unacquire, device reload, slot clear, root guard and root clear.
- The fixture compares call traces and full bounded state, including 32 input
  slots, semantic frame-control cells and the `0x134` force-feedback state.

The bounded domain is signed input count `-1, 0, 1, 3, 32`, controlled vtable
callbacks and effect-cleanup behavior. It does not establish live DirectInput,
count-above-32, fault, concurrency or full-game startup behavior. Run676's
existing 32-slot partial boundary remains in force.

Reproduce the passing proof with:

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/725-sim-input-teardown/native-config.json --attempt 4
```

Attempts are immutable; use the next unused attempt number.
