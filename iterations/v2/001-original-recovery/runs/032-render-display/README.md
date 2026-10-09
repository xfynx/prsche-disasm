# Run032 — display constructor `0x4677e0`

Source is `Porsche.exe`, SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The indexed function record is `004677e0..00467ec0`, 1761 body bytes.
Index queries used `functions.jsonl`, `calls.jsonl`, and `references.jsonl`
for `004677e0`, `00467913`, `0046792c`, and the vtable words at `005bc3f0` /
`005bc41c`; the full instructions were read from the matching v2 disassembly.
Run026's existing prefix source and proof were left unchanged.

The C++ translation now covers the complete `0x4677e0..0x467ebe` body,
including the `RET 0x10`: object prefix, desktop-depth/error path, driver
construction/start, display-mode update, resource and surface setup, THRASH
state/window operations, 8x8 texture setup, 128-pixel readback/format loop,
driver present, and final state restore/init calls. The original Unicorn x86
fixture compares object/resource/driver bytes, globals, and ordered dependency
calls. It has 180 prefix cases and 24 full-entry cases, for 204/204 total.
`_THRASH_window@4` is observed twice through slot `0x6bd9b0`.

The original engine/OS calls remain typed recording boundaries. In particular,
the driver vslot startup is a boundary; its route is supported separately by
the constructor vtables (`0x556a90`/`0x557100`), slot +4 targets
`0x556b10`/`0x557180`, `0x556bb0`, selector `0x575640`, and Run028's verified
loader `0x574fa0`. The selected DLL and real Win32 binding are still caller /
platform inputs. The probe validates constructor data flow, not an actual
window, graphics backend, draw, or game launch.

The vtable startup route is confirmed from the binary: the driver constructors
write vptr `0x5bc3f0` (`0x556a90`) or `0x5bc41c` (`0x557100`). Their slot +4
targets are respectively `0x556b10` and `0x57180`. `0x556b10` calls
`0x556bb0` at `0x556b36`; `0x556bb0` calls selector `0x575640` at `0x556c0a`.
Selector `0x575640` calls the verified loader `0x574fa0` at `0x57569b`.
The selected library name remains caller data, as Run028 establishes. The
later display-constructor body calls `_THRASH_window@4` through slot
`0x6bd9b0` at `0x467c7a` and `0x467d2b`; both calls are included in all 24
full-entry differential cases. Requested-width/height symbols at
`0x657a48/0x657a4c` alias the canonical `render_width_00657a48` and
`render_height_00657a4c` globals from `render_startup.hpp`. The refreshed proof
hashes every compiled translation unit, its relevant headers, the CMake
fixture, and the verifier.

## Verification

MSVC 19.44, Win32 Release:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/032-render-display -B local/builds/v2/render-display-032 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/render-display-032 --config Release --target render_display_probe
py -3 scripts/research/verify-v2-render-display.py
```

204/204 cases matched original x86, including depths below 8, both driver-start
results, mode-update branches, and all eight mode-format values in the full
constructor fixture. `verification.json` pins source/probe hashes and
`source-functions.jsonl` pins the complete original body hash. The next exact
consumer is the startup selector at `0x575640` and its already-verified loader
boundary, integrated with the root-owned Win32 binding.
