# Run745 render depth conversion frontier

Proof-only recovery of reachable `render_shape_row_converter_00534b90`
(`00534b90..00534d35`, 422B) from `Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
It is intentionally excluded from the game graph.

## Original evidence and reachability

- Binary-index query: `00534b90`, `00534d40`, `00571330`, their callers,
  callees, and data references. Run741 `00571630` reaches both `00534b90` and
  `00534d40`; `00571330` is only a child of `00534d40`, not a current linker name.
- REA `001` preserved the initial `00571330` dossier. Expanded attempt `002`
  failed at launch with `spawn EPERM`. Attempt `003` passed the manifest audit
  for `00534b90` (422B), `00534d40` (857B), and `00571330` (107B):
  `local/experiments/v2-render-depthconv-745-rea/003/receipt.json` and
  `validation.json`.
- Registry/body-range audit found no canonical entries or manual supplement
  overlaps for these three bodies. Accepted neighbors end at `00571320` and
  begin at `00571520`.

## Native result

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/745-render-depthconv/native-config.json --attempt 002
```

`local/experiments/v2-render-depthconv-745/002/receipt.json` is PASS:

- `/Od` and `/O2`: 768 cases each (1,536 original-x86 comparisons total),
  exact EAX/ESP/nonvolatile checks, exhaustive 16 valid shape aliases x 16
  target aliases x three direct-mode values;
- exact 256B `005de2fc`, 256B `005de3fc`, and 64B `005de4fc` original data;
- call order, mapped type, callback VA token, palette pointer/scratch mutation,
  and controlled canonical callee transport compared;
- 6/6 material mutations detected.

Native attempt `001` is preserved as a pre-compilation include-pin failure;
attempt `002` removes those transitive includes without changing the algorithm.

## Boundary and next dependency

This is `PARTIAL`, proof-only C++. The callback tables contain 28 unique
original VAs. Eighteen remain unrecovered (`005700d0`, `005700f0`, `00570150`,
`00570190`, `005701b0`, `005702f0`, `005703a0`, `005703f0`, `00570470`,
`005705a0`, `00570650`, `00570690`, `00570700`, `00570720`, `00570750`,
`005708a0`, `00570a00`, `00570a80`). The proof compares their raw 32-bit VA
tokens; it does not pretend they are host-callable pointers. Canonical ownership
for `005de2f8` / `006bda20`, invalid-index and fault behavior, concurrency, live
rendering, startup, and gameplay remain open. Do not add this source to CMake or
the registry until the reachable callback domain is bound to native providers.

`00534d40` remains deferred. Its exact next composition step is the compressed
shape child: recover/bind `00571470` (19B), then compare `00571330` with accepted
heap/copy and `00571520` providers before admitting it into a `00534d40` fixture.
No `00534d40`, `00571330`, or `00571470` source is claimed here.
