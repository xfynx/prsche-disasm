# Run 885 — `scene_flare_ctor_0045d800`
Recovers `scene_flare_ctor_0045d800` (777B) and 19 closed setup, config, cursor, sky, and trig helpers (20 functions, 4,819B, 0 new `.bss` cells), leaving the four multi-KB flare effect builders (`00459b50`, `0045adf0`, `0045b5a0`, `0045bf80`) as typed opaque boundaries.
- Sources: [scene_flare_ctor_885.hpp](scene_flare_ctor_885.hpp), [scene_flare_ctor_885.cpp](scene_flare_ctor_885.cpp)
- Proof: native [011/receipt.json](../../../../local/experiments/v2-scene-flare-ctor-885/011/receipt.json) PASS (`/Od` & `/O2`, 31 cases, 12/12 mutations); REA [validation.json](rea/validation.json) PASS (20 dossiers)
