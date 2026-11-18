# Run 644 render/startup text leaves (`0053c640`, `00556370`, `005563b0`, `00554930`, `00555640`)

Bounded native x86-vs-C++ recovery proof for five `unrec=[]` leaf helpers (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 262 code bytes total):
- `porsche::shape_find_entry_0053c640` (`0053c640..0053c67e`, 63B, `__cdecl(const void* shape, const void* tag) -> void*`, sha256 `1fe0282d153ec649985395c4268d00a03d7ebe04dabe7b74e2bb9590c6fb8e44`).
- `porsche::render_memmove_00556370` (`00556370..005563ac`, 61B, `__cdecl(void* dst, const void* src, uint32_t size) -> void`, sha256 `c12c9c9d5915787318e64cf669a9a5b456953b75f535ac11a77f08ad6fb4e98d`).
- `porsche::render_copy_bytes_005563b0` (`005563b0..005563c7`, 24B, `__cdecl(const void* src, void* dst, uint32_t size) -> void`, sha256 `47751c5602ae077354ba167ccdadd22adc369c89e36e1eff2f3b3118dc4e7301`).
- `porsche::render_texture_format_16bit_mode_00554930` (`00554930..00554942`, 19B, `__cdecl(int32_t mode_flag) -> void`, sha256 `f0371c0f73abddc0371be14aa211249c37993dcaeebf13c0bed76aada43ee513`).
- `porsche::render_texture_slot_bind_00555640` (`00555640..0055569e`, 95B, `__cdecl(int32_t stage_index, uint32_t value, uint32_t width, uint32_t height, uint32_t format_a, uint32_t format_b, uint32_t flags) -> void`, sha256 `02dadddf4d21375ee725664664ec7593c9ecccb5abb039d48c5fe2f05941ab8b`).

## Ownership & Canonical Headers

- Zero new `.data`/`.rdata`/`.bss` globals owned by Run 644:
  - `005dedf4` (4B `.data`, initial `0x00000002`, sha256 `26b25d457597a7b0463f9620f666dd10aa2c4373a505967c7c8d70922a2d6ece`) is `render_texture_format_preferences_005dedcc[10]` in `iterations/v2/001-original-recovery/runs/579-texture-format-comparator/format_preferences_579.cpp` (`format_preferences_579.hpp`).
  - `006a3410` is offset `+0x18` inside `render_texture_slots_006a33f8[32*48]` (BSS `006a33f8..006a39f7`) in `iterations/v2/001-original-recovery/runs/537-render-resource-descriptor-cleanup/render_resource_descriptor_537.cpp` (`render_resource_descriptor_537.hpp`).
- Reused canonical callee headers:
  - `iterations/v2/001-original-recovery/runs/611-splash-sprite-horizflip/splash_sprite_horizflip_611.hpp` (`render_buffer_read_word_0056e2a8`)
  - `iterations/v2/001-original-recovery/source/include/porsche/heap.hpp` (`heap_copy_dispatch_005323e0`)
  - `iterations/v2/001-original-recovery/runs/577-render-texture-transfer/texture_children_577.hpp` (`render_texture_select_00554820`)
  - `iterations/v2/001-original-recovery/runs/546-render-resource-allocation/render_resource_allocation_546.hpp` (`render_texture_slot_00554bd0`)
- Required `include_dirs`: `runs/644-render-startup-text-leaves`, `runs/611-splash-sprite-horizflip`, `runs/579-texture-format-comparator`, `runs/577-render-texture-transfer`, `runs/546-render-resource-allocation`, `runs/537-render-resource-descriptor-cleanup`, `runs/536-render-resource-nodes`, `runs/533-render-resource-factories`, and `source/include`.

## Verification

- Attempt `001` (`local/experiments/v2-render-startup-text-leaves-644/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/644-render-startup-text-leaves/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with zero warnings and passed `render_startup_text_leaves_original_x86_vs_cpp=PASS cases=45 events=64` (against real linked `format_preferences_579.cpp` and raw PE `005dedf4` check).
  - All 10 material mutations (`wrong-shape-scan-direction`, `wrong-shape-key-bytes`, `wrong-memmove-end-inclusive`, `wrong-memmove-start-inclusive`, `wrong-copy-bytes-arg-order`, `wrong-16bit-mode-values`, `wrong-slot-bind-power-of-two`, `wrong-slot-bind-stage-upper-bound`, `wrong-slot-bind-stride`, `wrong-slot-bind-field-base`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof using real `render_texture_format_preferences_005dedcc`, zero-initialized `render_texture_slots_006a33f8`, controlled callee stubs (`0056e2a8`, `005323e0`, `00554820`, `00554bd0`), and a 4 KiB mapped arena. Unmapped/null pointers, 32-bit address wraparound edges, discarded `EAX` in `00554930` callers, real callee integration, callers (`00452590`, `0044e010`, `0044df10`, `0044de60`, `00443760`, `0047c6f0`, `0047c880`, `004b6560`, `004d6b10`, `0058259c`), and production CMake/registry integration remain open.
