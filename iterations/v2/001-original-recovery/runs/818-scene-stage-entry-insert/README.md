# Run 818: Scene Stage Entry RB-Tree Insert (`0044db70` Cluster)
Closes `814`/`816` child `scene_stage_entry_insert_0044db70` (223B) + `0044b800` (43B) + `0044de20` (35B) + `004314c0` (430B); 731B code, 0B data/bss, reuses `004211d0` (0 new unresolved symbols).
- REA: `local/experiments/v2-scene-818-rea/001/receipt.json` + `rea/validation.json` (4 dossiers).
- Native: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/818-scene-stage-entry-insert/native-config.json --attempt 001` -> `local/experiments/v2-scene-stage-entry-insert-818/001/receipt.json` PASS (`30` cases/variant `/Od` & `/O2`, `10/10` mutations killed).
