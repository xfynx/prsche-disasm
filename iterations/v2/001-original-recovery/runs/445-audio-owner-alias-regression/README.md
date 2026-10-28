# Run445: canonical audio owner alias regression

Native001 PASS:1,392 cases across `/Od` and `/O2`,9 detected mutations. This reuses
Run441's immutable fixture and14-body stop/cleanup/pool oracle with the corrected
canonical device TU. Zero new original bodies or physical storage; no new runner.

Run442 found an old005656d0 counterexample: descriptor=canonical+4, inactive,
seed1/case83323. Original005656e8 reads descriptor+74 before005656eb stores+78.
The previous C++ order reversed those operations. The owner now captures+74
after the forward copy and before either store; the earlier+78 capture is retained.
442's caller/parent alias proof validates that correction.445 refreshes the
otherwise unchanged stop chain because its actual owner TU input hash changed.
Old accepted/failing receipts and Run441 inputs are preserved.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/445-audio-owner-alias-regression/native-config.json --attempt 001
```

Receipt: `local/experiments/v2-audio-owner-alias-regression-445/001/receipt.json`.
`evidence.json` records original instructions and old/current owner hashes.
Run444 owns shared build/audit and registry integration. Run441's bounded scene
domain still applies; this does not establish full shutdown/startup or live devices.
