# Run030 — integrated startup source checkpoint

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Accepted Run022–027: 12 additional complete C++ consumers and one display prefix.
Totals: 115 full, 3 partial; 23 native MSVC x86 probes compile in the common build.
No game EXE/window yet. Queries/VAs/unknown callees are in each run README.

New original x86 versus native cases: services17, paths48, heap48, renderer26,
objects32, scheduler35, window64. Native core vtable dispatch is exercised, with
normalization only for pointer identity. Window PE initializers are also checked.
Platform and unrecovered game callees remain explicit recording boundaries.

Build: `powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1`.
New proof scripts: `verify-v2-startup-services.py`, `verify-v2-resource-paths.py`,
`verify-v2-application-heap.py`, `verify-v2-render-startup.py`,
`verify-v2-render-objects.py`, `verify-v2-window-runtime.py` under scripts/research.
Invoke each with `py -3 scripts/research/<name>` after the common build.
Fresh regressions use `--report-dir` under this run: input-state→input-regression,
fe-callbacks→fe-callbacks-regression, disk-open→disk-open-regression,
input-buffer→input-buffer-regression. Earlier reports stay unchanged.

Audit: `py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification`.
Next: original allocator59ef90, THRASH loader574fa0, RegisterClass53ac20 and real
window configuration/thread caller53b8d0; then native startup linking and launch.
Actual rendering, complete game behavior, visual acceptance and byte matches
remain unverified. Automatic pseudo-C is not recovered compilable C++.
