# Run575: reachable texture scheduler

Owner: creation (Sol/high), this run and its local artifacts only. Baseline is
accepted Run574 (319 TUs, 130 unresolved names / 138 references). The original
game assets and passed run inputs are read-only; coordinator owns integration.

Goal: trace and recover reachable 005550e0 (indexed 434 bytes) with its real
return/transport ABI and original 32-entry local-array/count behavior. Inspect
cached Run469 REA before new analysis; query index/raw callers and 005552a0 /
00554f60 children, then census the complete 574 source/header closure and
registry before implementation. Reuse Run572 native scaffold and canonical
543/570/357 state/providers. The existing void-return linker facade must not
silently discard a consumed original return; trace actual callers.

Completion requires original-x86 versus compiled comparisons at Od/O2, actual
ABI/call order/state and material mutation controls. Keep local-array capacity,
callback reloads, faults/aliases, live drivers and unknown child semantics
explicitly bounded. No guards, inferred capacity or approximated behavior.
Actual producer and full game startup remain open.

Current: cached469 005550e0 dossier and raw index were inspected; `scope-evidence`
pins 574 build/registry census (319 roots, 581 source-header files, 787 pins;
no registered overlap for 005550e0, 005552a0, 00554f60). Exact 537 slot storage
and 543 count/dirty owners are reused. Scheduler/score and 00554f60 C++ recovery
exists; original 00554f60 uses stdcall5 creation slot006bd968 and stdcall3 upload
slot006bd940, with callback-mutated flags and node/table reloads. Its two messages
at005bc2ec/005bc33c are adjacent80+40-byte originals, retained as one 120-byte
span. Existing 540 canonical source-label owner is reused. Four indexed direct
scheduler callers overwrite EAX or call another function before observing it;
the original integer core remains available, with existing void facade partial.

Accepted bounded packet: 005550e0/434B, 005552a0/40B, 00554f60/212B are owned
here; independent Terra owns only texture_process_575.cpp/.hpp for 005554b0/275B,
00555040/150B and canonical zero callback006a3a50. Agreed shared function
`render_texture_notify_00555040(void*,void*)`; 00554f60 passes (node,null) and
does not consume its EAX. One shared native fixture/config covers both source files. Original caller/count/alias/live-driver domains stay partial;
no 32-slot guard or stale-state approximation. Reused 572 fixture preflight passed
404 cases / 1,449 events; six risk-specific mutation preflights detected material
changes. Raw original 120-byte adjacent message span and loader-zero callback
DWORD have independent 574 closure/PE witnesses in `message-ownership.json`.
Shared native attempt001 passed with ten controls and both compiler modes:
`py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/575-render-texture-scheduler/native-config.json --attempt 001`.
Read-only shared receipt audit also passed. The frozen handoff in README.md and
ready.json records 808 scenes / 1,032 comparisons / 2,898 events, five partial
entries, 120 readonly bytes and one 4-byte loader-zero owner. Run576 shared integration and current-closure audit pass. Actual producer, indirect
return/alias domains, live driver and full game startup remain open.
