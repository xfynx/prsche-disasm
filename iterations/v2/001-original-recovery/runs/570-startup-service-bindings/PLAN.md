# Run570: reachable startup service bindings

Goal: recover original `00536080` and `00534540` with their four actual linker
names and existing canonical `00555330`/`00534480` providers. Baseline Run567;
no shared graph or registry edits here. Both bodies are indexed (27B/12B).

Status: frozen native001 and shared read-only audit PASS for `00536080` only;
one partial original body, two transport bindings and one loader-zero byte.
The 48-byte descriptor at `005de680`
overlaps existing `window_shutdown_state_005de6ac` in its final DWORD; Run521's
existing split view covers a different descriptor at `005de650`. A contiguous
copy would change identity/aliasing, so `00534540` stays deferred until an exact
canonical view/provider is proved. Run571 shared integration audit now passes.

`scope-evidence.json` pins Run567's 778 pins/316 roots/575 closure files, original
27B body and startup/game-setup caller bytes. Both callers load ECX from the
same `[0069ed0c]+4` cell, then call with no stack argument; the cdecl binding is
only a typed transport adapter. New byte `0069dd1e` is in the PE loader-zero tail,
adjacent to the accepted pointer at `0069dd18` and byte at `0069dd1d`.

Native001 uses real accepted Run543 child and a controlled platform callback
with late receiver/flag mutation. Both bindings pass at Od/O2; 360 scenes,
720 adapter comparisons and four mutations. See README and ready.json for exact
partial bounds. Inputs are frozen; Run571 closes both ABI names without promoting
the partial original. Do not enlarge passed scope. A later packet must prove an alias-safe view
for `00534540` and independently trace its descriptor producers.
