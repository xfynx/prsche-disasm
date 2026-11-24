# Run815: Heap slot scanner & canonical `005a177b` report ABI bindings

Recovers standalone `application_heap_slot_00569a70` (`00569a70..00569a8b`, `28B`, `0` callees, closes `Run546` symbol via `porsche/heap.hpp` without duplicating `application_heap_init.cpp`) in `heap_slot_815.{cpp,hpp}` and binds canonical `005a177b` ABI aliases (`render_display_texture_report_005a177b` `3x`, `scene_texture_alloc_report_005a177b` `2x` -> `formatter_stdio_printf_005a177b`, `65B`) via `bindings.cmake`/`bindings.json`.
Native diff `local/experiments/v2-heap-slot-and-report-abi-815/001/receipt.json` **PASS** (`10` cases/variant `/Od` & `/O2`, `6/6` mutations killed); REA `local/experiments/v2-render-input-815-rea/001/receipt.json` + `validation.json` **PASS** (`2` dossiers).
