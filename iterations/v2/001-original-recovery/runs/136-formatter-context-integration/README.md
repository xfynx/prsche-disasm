# Run136 - formatter and startup context integration

Accepted common-build checkpoint after126 (482f28d), original Porsche.exe
SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

The actual108 formatter wrapper now uses the canonical32-byte descriptor and
calls124 parser,119 emit helpers and132 cleanup. Root review restored the
lead-byte table consumer, zero alternate-hex prefix suppression and wide-string
padding; cleanup now rereads callback-mutated flags/base and preserves opaque
uninitialized descriptor bytes.134 compares both the actual production entry
and a state-observation adapter, including a real parser-to-write-to-cleanup
case.137 supplies real integer divide/remainder/strlen bodies through native
links;138 owns initial CRT storage and native aliases (8 ranges/5057 bytes and
10 original PE pointer relocations). Private callbacks never provide production
file, float, allocation or audio behavior.

133 restores the audio query/apply/create bodies; review fixed the mutable
SNDAUTHOR pointer cell, overlapping descriptor copy and return ABI.135 adds six
full base/member constructor/range bodies with exact ECX/stack layout, byte
writes, callback reloads and36-byte by-value range arguments. Partial00525ec0
is compiled only in a separate private fixture TU: its null-allocation EAX
contract is unproved and remains unresolved in the production library.131 audio
initialization also stays isolated because its signed mode domain is unproved.
No guessed clamp or normalized partial effect enters the common game library.

Acceptance:267 full +6 registered partial functions; MSVC Win32 ALL_BUILD
passes120 projects/230 unique TUs,105 comparison/alias targets,4 native OS and3
link fixtures. All7 native/link executables pass.25 fresh original-x86 reports
cover4952 comparisons plus4 component-proven timer/formatter cases. Initial
storage comparisons are reported separately, not as recovered functions.
The actual game-link attempt has0 compiler errors and259 unresolved symbols/
278 references (126:250/269): new connected bodies expose further dependencies.
There is no new game EXE and no complete startup/menu/gameplay acceptance.
See acceptance.json, compile-link-proof.json, original-game-link/link-report.json
and docs/recovery-validation-backlog.md; all end-to-end obligations stay open.

Reproduce from repository root:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1 *> local/reports/v2-common-build-136.log
py -3 scripts/research/verify-v2-formatter-integration.py --probe local/builds/v2/001-original-recovery/bin/Release/formatter_integration_probe.exe --report-dir iterations/v2/001-original-recovery/runs/136-formatter-context-integration/formatter-integration
py -3 scripts/research/verify-v2-application-context-base.py --probe local/builds/v2/001-original-recovery/bin/Release/application_context_base_probe.exe --report-dir iterations/v2/001-original-recovery/runs/136-formatter-context-integration/application-context-base
py -3 scripts/research/verify-v2-formatter-runtime-storage.py --probe local/builds/v2/001-original-recovery/bin/Release/formatter_runtime_storage_probe.exe --report-dir iterations/v2/001-original-recovery/runs/136-formatter-context-integration/formatter-runtime-storage
py -3 scripts/research/verify-v2-native-fixtures.py --report-root iterations/v2/001-original-recovery/runs/136-formatter-context-integration
. ./scripts/tool-env.ps1
py -3 scripts/research/verify-v2-original-game-link.py --build-dir local/builds/v2/original-game-link-098 --report iterations/v2/001-original-recovery/runs/136-formatter-context-integration/original-game-link/link-report.json --log local/reports/v2-original-game-link-136.log
```

Historical committed reports must not be overwritten; use a fresh run for later
checks. Full source/verifier hashes and exact individual cases are in reports.
Next: trace base-context allocator/list/range effects, signed audio-mode writer
004a6a00, formatter fatal005abee8 to005a2e22, CRT callback writer005a0f5d and
lowio initialization005a953e. Full game-setup004d3420 and backend graphs remain.
