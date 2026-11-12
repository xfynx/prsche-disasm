# Run572: reachable startup service lifecycle

Goal: recover original `00536050`/46B and `005360a0`/43B, including proven
canonical byte/state and actual `00555330` invalidation. Their real children
`005550e0`/434B and `00555440`/76B are separately traced; do not invent their
behavior or duplicate Run570 state. Run571 is integrating Run570 independently.

Status: three-body candidate `00536050`/`005360a0`/`00555440` drafted; none is
accepted. The original mode byte `005de6b8` is file-backed with initial value1,
next to Run527's array at `005de6bc`; Run570 owns the distinct `0069dd1e` byte.
Cached Run469 REA dossiers and index/raw callsites show `00536050` receives ECX
and RET0, while `005360a0` receives ECX plus a stack DWORD and RET4; existing
cdecl names need adapters. The 434B `005550e0` remains an exact typed external
boundary; `00555440` reuses existing callback binding `006bd954` and leaves its
real `005554b0` child unresolved. Fixture will compare actual 543 invalidation,
late flag/pending mutations, typed endpoints and original return/ABI domains.
Next: finish native fixture and proof, then recheck actual accepted Run571
closure before readiness. No guessed descriptor view or wide-FP promotion.
Only Run572/local artifacts are owned here; no shared graph/registry edits.

2026-11-12 handoff: worker hit usage limits; no active assignment or native
acceptance. Latest accepted graph is Run573, so recensus that closure on resumption.
