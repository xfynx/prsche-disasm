# Run437: original audio stop and shutdown integration

Build001 compiles230 C++ translation units across8 projects. Three old linker names
close and four real children appear:185 unresolved names/192 references, no game EXE.
This integrates3 original bodies/417B and a void caller facade, not another body.

- [435](../435-audio-stop-voice/README.md):00565d60/0058a8b0,194B;27,530 native cases,
  13 detected mutations. Original stop composes raw434 lock/lookup/iteration children;
  production uses their unchanged canonical implementations. Separate006b489c is
  loader-zero storage with no previous owner in the resolved403-file closure.
- [436](../436-audio-channel-shutdown/README.md):005659f0,223B;320 native cases,
  17 detected mutations. Canonical signed body plus one-call void facade satisfy
  both existing consumers. Count signedness, callback reloads and captured-header
  ordering are preserved without new device storage.

Shared audit PASS:27,850 cases across `/Od` and `/O2`,30 mutations,571 source pins
and316 unique canonical COFF providers. No fixture providers enter the game graph.
Frozen native proofs were reused; integration built/audited once. The resolved
shared manifest includes its delta; reading its historical base alone is incorrect.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/437-audio-stop-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/437-audio-stop-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/437-audio-stop-integration/acceptance.json
```

Configure/build receipts and full logs are under `local/experiments/v2-audio-stop-game-437`.
Build ran outside the sandbox that previously stopped MSBuild before compilation.
`build-001.json`, `acceptance.json` and `validation.json` record the shared result.

00590070/00565990/00597010/00589c00 remain unresolved controlled proof endpoints.
Native436 controls00565d60 independently; actual combined shutdown/stop execution
is not claimed. Parent435 tests valid channel0/negative outcomes; positive return
follows inspected original/source, without a separate native case. Live callback/
device/lock behavior, invalid-memory/fault domains, concurrency, full startup and
gameplay remain open;403/411 remain PARTIAL. Next trace startup allocation0058aae0
and pool helpers0058aa60/0058ac30 against the original index and registry.
