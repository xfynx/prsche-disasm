# Run696 getclutptr dispatcher (005346d0)

Recovered `005346d0` (352B, `render_getclutptr_from_resource_005346d0`) in
`getclutptr_696.cpp/.hpp`. Unowned in the registry: no `functions.json` entry and
no `body_ranges` overlap (nearest owned bodies are `005345e0..00534629` and
Run689's `00534830..005349d2`). New batch-owned cell: 41B `.rdata` message
`005bb3fc` (`render_getclutptr_message_005bb3fc`, raw bytes
`676574...7825780a00`, `"getclutptr - UNSUPPORTED CLUT TYPE 0x%x\n\0"`).

Reused via typed declarations (not redefined): `render_clut16_from_resource_00534830`,
`render_clut16_file_005bb3e4`, `render_palette_color_key_006a6420` (689);
`render_palette_5551_to_8888_key_00570780` / `565_to_8888_key_00570820` (689);
`render_palette_swap_rb555_00570260` (685); `a555/a565/vga6/rgb24` leaves (686);
`render_resource_node_palette_00537fb0` (536/537);
`render_pixel_palette_006b4b20[256]` (380); diagnostic transport
`005deb74/005deb78/005debf0` (shared headers).

Evidence: disassembly `005346d0..0053482f` (lines 389334-389455), raw PE body
sha256 `2290080f477c0adae8a9361eed4bf4754b621d67289fb7e046380b3c8f6b5dc7`,
decompiled `FUN_005346d0` branch/arg agreement. E8 census: `00537fb0` x1,
`00571160` x1, `00570820` x1, `00570780` x2, `00570990`/`00570920`/`00570ff0`/
`00570260` x1 each; absolutes `005deb74`/`005deb78`/`005debf0`/`005bb3fc`/
`005bb3e4`/`006b4b20` x1 each. Note the 0x24/0x22 leaves take `(count,src,dst)`
while the keyed/alpha leaves take `(dst,src,count)`.

Native proof `attempt 002` PASS on the shared runner:

```
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/696-getclutptr-dispatcher/native-config.json --attempt 002
```

Receipt: `local/experiments/v2-getclutptr-dispatcher-696/002/receipt.json`.
Original x86 body in an RWX slot vs the C++ production TU at `/Od` and `/O2`;
104 measured cases per variant (9 signed-int16 counts x 11 clut types incl.
0x2a early return and unsupported-type diagnostic path, 3 high-header masking
cases, 2 null-lookup cases) plus ESP/EBP/EBX/ESI/EDI ABI, FPU state, used return
pointer, lookup/diagnostic event order and full palette/descriptor byte compares.
14 material mutations all detected. 227 pins / 82 receipts. `00537fb0` and
`005debf0` are controlled endpoints (bounded transport only); leaf providers are
the accepted production TUs compiled into the test graph. Synthetic callsite
setup and RET are harness code.

Attempt 001 is preserved: base variants passed but the `count-dword` mutation
crashed (AV) instead of producing a bounded divergence; replaced with a bounded
off-by-one count control for the passing attempt. No hypothesis was re-tried.

Unlocks next: `00562810` and `00563440` (both call `005346d0` and `00534830`).
Boundaries: `006a6420` writer unrecovered; counts bounded to <=256 and the signed
int16 header domain (larger original unchecked overflow not exercised); original
0x200 scratch is uninitialized outside the 0x23 path and never read there;
real `005350e0` depth-conversion consumer, live device/asset and gameplay remain open.
