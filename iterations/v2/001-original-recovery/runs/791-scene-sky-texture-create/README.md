# Run 791: Scene Sky Texture Create (`0044da10` Cluster)
Closes Run786 child `scene_sky_texture_create_0044da10` (`0044da10..0044db1f`, 272B) plus leaves `00536460` (11B), `00554950` (16B), `00555630` (1B); 300B code + 64B `.data` (`005ce52c`, `005ce54c`), reuses `00619790`, `005def98`, `0044dfe0`, `0059ef90`, `00535bc0`, `00531f90`, 1 typed frontier (`0044d7e0` 434B).
- REA: `local/experiments/v2-scene-791-rea/001/receipt.json` + `rea/validation.json` (4 dossiers).
- Native: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/791-scene-sky-texture-create/native-config.json --attempt 003` -> `local/experiments/v2-scene-sky-texture-create-791/003/receipt.json` PASS (31 cases/variant `/Od` & `/O2`, 10/10 mutations killed).
