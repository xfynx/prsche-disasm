# Run126 — connected event/thread and startup service integration

Original Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

Root integrates123 event lifecycle,127 thread wait,128 original startup audio
setup and direct startup OS adapters, and130 connected event-stop/wait proof.
The worker review fixed first-null termination at0053c127 and adds three
original-x86 cases (21 total). The 130 oracle executes real0053c170→0055fa10
with controlled API effects, including self-thread and detached registration.
The 127 predicate executes original0055f980/0055f9b0 in its oracle; C++ reuses
canonical record/table/lock owners and retains their post-unlock serial read.

Two supplementary entries are indexed:0053c0f0 and0053c170. The latter shares
its87bytes with automatic0053c1d0 and adds no instruction coverage. Module,
contiguous ASM, literal callback/tail-jump bytes and terminal RETs are guarded
by index-v2-event-lifecycle.py and event-index.json (35 manual entries).

Run128 closes app_main's exact MessageBoxA and CreateDirectoryA imports and
connects004a6840 audio setup; unknown device callees remain typed boundaries.
Root pinned original call bytes/import IAT and found the existing app_main
swap-file error text had been truncated. It now includes the full original
005d6e9c text. No original-function count is added for platform OS adapters.

Startup context review exposed incorrect two-DWORD storage in old app_main;
original004b6a50 allocates0x188 stack bytes with a0x180-byte context and calls
004d1a90/004d3420/004d1ba0 with context in ECX. Run129 corrects this
caller/context closure and restores the ctor/dtor bodies; no guessed adapter to the huge004d3420 body is added.

Acceptance reports and current real game-link frontier will be recorded here.
A common build, controlled x86 oracles and native OS fixtures do not establish
full game startup, real timer scheduling, WM_CLOSE or gameplay fidelity.
See docs/recovery-validation-backlog.md; those checks remain open.

Common commands (repository root):

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1 *> local/reports/v2-common-build-126.log
py -3 scripts/research/verify-v2-event-lifecycle.py --probe local/builds/v2/001-original-recovery/bin/Release/event_lifecycle_probe.exe --report-dir iterations/v2/001-original-recovery/runs/126-event-integration/event-lifecycle
py -3 scripts/research/verify-v2-thread-wait.py --probe local/builds/v2/001-original-recovery/bin/Release/thread_wait_probe.exe --report-dir iterations/v2/001-original-recovery/runs/126-event-integration/thread-wait
py -3 scripts/research/verify-v2-application-services.py --probe local/builds/v2/001-original-recovery/bin/Release/application_services_probe.exe --report-dir iterations/v2/001-original-recovery/runs/126-event-integration/application-services
py -3 scripts/research/verify-v2-event-thread-integration.py --probe local/builds/v2/001-original-recovery/bin/Release/event_thread_integration_probe.exe --report-dir iterations/v2/001-original-recovery/runs/126-event-integration/event-thread-integration
```

Run129 adds four original context cases and fifteen app_main cases that execute
the recovered ctor/dtor; exact caller ECX/stack arguments, sparse writes and
canaries are compared. The full game-setup parser and context vtable remain open.

Acceptance2026-10-11: common ALL_BUILD passed113 projects/213 TUs,98 comparison/alias
probes,4 native OS and3 nonGUI link fixtures. All7 native/link executions passed.
24 fresh original-x86 reports cover4813 comparisons plus4 component-proven
composed timer/formatter cases. Registry252 full+6 partial;35 manual index entries.
Real game-link has0 compile errors,250 unresolved symbols/269 references (121:245/264).
This increase exposes audio/base-context consumers newly reached through recovered
startup bodies; it is not hidden by stubs. No game EXE exists.131 and124/132 remain
isolated/unaccepted. All end-to-end backlog items stay open.
