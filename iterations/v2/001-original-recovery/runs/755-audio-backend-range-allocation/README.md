# Run755: audio backend range selection and allocation frontier

## Proven

Recovered `audio_backend_candidate_range_0058a4b0` (`0058a4b0..0058a4ef`, 64B,
SHA-256 `3136561158365ce3858f75d92a1f009b30e690d12cedfbe28aa359942f74025d`).
The original reads `candidate` as an 8-bit AL value. Mask `0x04` takes precedence:
it writes `first=0` and zero-extends byte `[006b48dd]` to `last`. Otherwise mask
`0x10` writes that byte as `first` and sign-extends word `[006b49a4]` to `last`.
With neither bit set, it leaves both output words untouched. These state bytes
are offsets `0x1d` and `0xe4` of canonical
`application_audio_device_state_006b48c0` (Run443/source owner).

Native `/Od` and `/O2` differential PASS: 327,680 cases in each mode. Coverage
crosses every candidate low byte with all 256 voice-limit byte values and five
signed-word boundary values, comparing both output words including untouched
sentinels. Both calls check ESP, EBP, EBX, ESI and EDI. All three mutation
controls detected: mask precedence, signed word extension and unsupported-mask
output preservation. The runner patches only
the three absolute data operands to fixture-owned byte-equivalent globals.
Frozen receipt: `local/experiments/v2-audio-backend-range-allocation-755/003/receipt.json`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/755-audio-backend-range-allocation/native-config.json --attempt 003
```

Attempts001 and002 are retained. Attempt001's first mutation correctly
diverged but the harness did not flush its failure line, so the runner rejected
its marker. Attempt002 fixes that; attempt003 adds explicit ABI checks. No
shared integration or registry/CMake changes.

## Open: `005898f0` voice allocation

Run751 REA002 already pinned `005898f0..00589bf2` (771B, SHA-256
`339fbcaa839f7fa4cf676eb1305faea97b9bb646ded691960f0d9cbe790670fc`). The
current binary index lists callers `005612a0` and `00590420`; the allocator
calls `005898b0` twice per selection pass and `00565d60` when reusing an active
voice. It reads/writes shared generation `[006ad74c]`, selection list
`[006b48a8..ae]`, voice records rooted at `[006b4a00]` with stride `0x70`, and
reads `[006b49a8]`. Its assembly and pseudocode are in
`local/experiments/v2-audio-751-rea/002/function-005898f0.json`.

No allocator body is claimed. The index and Run751 dossier do not establish the
canonical owner and full layout/lifetime of the selection list, the exact
eligibility semantics of `005898b0`, or a native oracle for the release side
effect through `00565d60`. Next: obtain REA dossiers for both callees and all
data owners/consumers, reconcile the `0x70` record storage with Runs434/751,
then build the allocator-only original-x86 fixture and material mutations.
Do not promote the parent’s Run751 scripted allocator boundary to evidence for
the real allocator.

## Bounds

This proof covers only the range setter with mapped, readable state and valid
output pointers. It does not claim device enumeration, voice allocation,
backend release, concurrent state changes, full voice start or game playback.
