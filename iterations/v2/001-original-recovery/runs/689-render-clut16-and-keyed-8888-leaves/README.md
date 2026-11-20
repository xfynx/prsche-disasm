# Run689 keyed 8888 clut leaves + getclut16ptr dispatcher

Recovered `00570780` (148B, `render_palette_5551_to_8888_key_00570780`), `00570820`
(128B, `render_palette_565_to_8888_key_00570820`) and `00534830` (419B,
`render_clut16_from_resource_00534830`, the `getclut16ptr` dispatcher) in
`render_clut16_689.cpp/.hpp`. All three were unowned in the registry (no
`functions.json` entry, no `body_ranges` overlap); batch-owned new cells:
4B `.data` color key `006a6420` (`render_palette_color_key_006a6420`, reads at
`005705b3/0057079f/00570829`, no indexed writer - writer remains a boundary),
23B `.rdata` string `005bb3e4` (`\\real\\cmn\\depthconv.c`) and 43B `.rdata`
message `005bb428`. Reused via typed declarations: `00537fb0` (runs 536/537),
`00570420`/`00570490`/`00572f30`/`00572f5b` (683), `00570260`/`005704c0` (685),
`00571160`/`00570ff0` (686), `render_pixel_palette_006b4b20[256]` (380),
diagnostic transport `005deb74`/`005deb78`/`005debf0` (shared_runtime_globals +
files.hpp). Evidence: disassembly + raw PE bytes (body sha256 in
`native-config.json`/`scope-evidence.json`), instruction-chain simulation for
the leaves' SAR alpha composition, E8/absolute reference census for the
dispatcher (005704c0 x4, 00570490 x2, 00570420 x2, 00570260, 00570ff0, 00571160,
00537fb0; absolutes 005deb74/78, 005debf0, 005bb3e4/5bb428, 006b4b20 each x1).

Native proof `attempt 005` PASS on the shared runner
(`verify-v2-native-batch.py --config .../689-render-clut16-and-keyed-8888-leaves/native-config.json`):
original x86 bodies from the pinned PE in RWX slots vs the C++ production TU at
`/Od` and `/O2`, 472 measured cases per variant (leaves: 6 keys x 11 counts x 4
buffer aliasing modes; dispatcher: 8 counts x 11 types incl. 0x29 early return,
unsupported 0x21/0x00/0xff diagnostic path, high-header masking, null-lookup
default-palette path), plus FPU/EBX/ESI/EDI/EBP/ESP ABI checks, return pointer,
palette/descriptor byte compares and diagnostic file/line state. 30 material
mutations all detected (`expected_exit` 1 with `divergence` marker; a crash-only
count mutation was dropped, see attempt 004). `00537fb0` and the diagnostic
handler are controlled endpoints (bounded transport only); leaf providers are
the accepted production TUs compiled into the test graph.

Unlocks next: `005346d0` (`getclutptr`, needs only this batch's two leaves plus
already-owned 00570260/00570920/00570990/00570ff0/00571160), then `00562810` and
`00563440` (both call `005346d0` and `00534830`). Unowned-string neighbor
`getclutptr - UNSUPPORTED CLUT TYPE 0x%x\n` near `005bb3f9` will be needed by
`005346d0`. Boundaries: `006a6420` writer unrecovered; dispatcher `scratch[0x400]`
overflow for signed count > 256 on the 0x24/0x22/0x2e paths preserves original
unchecked behavior; no live device/asset acceptance. Attempts 001-004 are
preserved failed/partial runs (message string length fix and link/mutation
repairs landed in 003-005).
