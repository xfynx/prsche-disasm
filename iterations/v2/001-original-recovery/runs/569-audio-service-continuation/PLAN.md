# Run569: stream service continuation

Goal: trace and recover a bounded portion of original `00567550`, the actual
child of Run564 `00567720`, without duplicating Run568's `0056b540` work. The
accepted baseline is Run567 (`829b441`); current index identifies 267 bytes and
children `00566d60`, `0056b690`, `0056c040`, `005896d0`, `005896f0`.

Frozen at coordinator request while workspace changes are sorted. This is a
trace-only checkpoint, not recovered code or native acceptance. Ownership is
historical until reassigned. The indexed
body is fully pinned in `scope-evidence.json`: original SHA256
`b9eeaa6a11b9823aee36d503f54fdf85d06b29c71c5f18d423f6f98b4a64e76c`.
Run567 census covers 778 pins/316 roots/575 closure files: no registered body
overlap; its only two source hits are the accepted Run564 external declaration
and forwarding call. Canonical device `006b48c0`, lookup `00566d60`, and lock
`005896d0`/`005896f0` owners already exist. The `0056b690`/`0056c040` children
still need ownership/ABI and bounded transport analysis. No implementation or
native proof exists. `scope.py` is the reproducible read-only census.

Next after coordinator resumes: inspect raw caller/child ABI and state aliases,
reuse Run561's canonical slot/lock fixture and compare the five-argument body
against original x86 with controlled true external codec endpoints; classify any
unproved child/stack domains as partial. Preserve Run564/565/567 frozen inputs.
No shared graph, registry, root docs or commits here.
