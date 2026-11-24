# Run 801: Scene Texture Descriptor Shrink (`005557d0`, `00574c70`)
Closes `799` child `scene_texture_descriptor_shrink_005557d0` (`005557d0..0055596e`, 415B) + `scene_texture_shape_create_00574c70` (`00574c70..00574e40`, 465B); 880B code, 0B data/bss, reuses `374`/`375`/core runtime (0 new unresolved symbols).
- REA: `local/experiments/v2-scene-801-rea/001/receipt.json` + `rea/validation.json` (2 dossiers).
- Native: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/801-scene-texture-descriptor-shrink/native-config.json --attempt 004` -> `local/experiments/v2-scene-texture-descriptor-shrink-801/004/receipt.json` PASS (76 cases/variant `/Od` & `/O2`, 10/10 mutations killed).
