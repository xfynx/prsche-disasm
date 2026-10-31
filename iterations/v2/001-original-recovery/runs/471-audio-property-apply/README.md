# Run471: original property application

Porsche.exe0058e780..0058ea87,776B, no direct original children. Canonical443
GUID/interface/availability and462 settings are reused; two readonly scalar
DWORDs add8B, with no owner in the470 full compiler closure. The004-byte value
at005c169c is33800001, not33800000; exact raw bytes are retained.

Native003 passes7,164 cases/18,440 events across/Od+/O2;15 mutations detected.
Modes-3..130, signed extremes, absent/positive/negative availability, optional
sentinels, all nonzero HRESULT early exits, interface/vtable swaps and callback
writes compare settings, returns, ordered7-argument COM calls and preserved ABI.
x87PC/RC/depth/CW/SW/tag/80-bit registers and float payloads also compare. Raw GUID
and scalar bytes are asserted before resets. The COM endpoint only transports
and records the defined calls; it does not simulate a real sound driver.

Settings retain all three original arguments even for unavailable/disabled
modes. Local parameters survive callback writes to global settings; each later
call reloads the current interface and vtable. Modes0/1 disable optional3/4,
mode2 selects preset1 with mix1, signed100..120 select10. Positive HRESULTs also
fail. No range/null guards or replacement coefficients were added.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/471-audio-property-apply/native-config.json --attempt 003
```

001/002 stopped at fixture linking: unused functions in the real application
state owner required fail-closed bindings. Their input copies are preserved in
`local/experiments/v2-audio-property-apply-471/failed-inputs/`. No native algorithm
divergence occurred. Those unexecuted fixture bindings are absent from the game.
003 inputs are frozen. Actual COM/live audio/full462 composition, unmapped/null
interfaces, unmasked floating faults and full startup/display/gameplay remain open.
REA465002 is reused; no new analysis session or runner was added.
