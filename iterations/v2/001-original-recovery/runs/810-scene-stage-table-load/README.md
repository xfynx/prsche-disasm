# Run 810: Scene Stage Table Load (`0044d270` Cluster)
Closes `805` child `scene_stage_table_load_0044d270` (`0044d270..0044d314`, 165B) + 5 helpers (`00537f30`, `00537f60`, `0059f880`, `0059f8a0`, `0059fb90`; 344B total, 0B data/bss), reuses `0059ed90`, 3 typed frontiers (`0059f8f0`, `0044d380`, `005af040`).
- REA: `local/experiments/v2-scene-810-rea/001/receipt.json` + `rea/validation.json` (6 dossiers).
- Native: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/810-scene-stage-table-load/native-config.json --attempt 003` -> `local/experiments/v2-scene-stage-table-load-810/003/receipt.json` PASS (39 cases/variant `/Od` & `/O2`, 10/10 mutations killed).
