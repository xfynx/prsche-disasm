# Run 814: Scene Stage Entry Register & Page Protect (`005af040`, `0044d380` Cluster)
Closes `810`/`812` frontiers `application_page_protect_005af040` (65B) and `scene_stage_entry_register_0044d380` (406B) + 5 helpers (`0044d520`, `0044d550`, `00536120`, `005365a0`, `00423840`; 793B total, 0B data/bss), reuses `646`/`650`/`742`/`774`/`791`/`536`, 1 typed frontier (`0044db70` 223B).
- REA: `local/experiments/v2-scene-814-rea/001/receipt.json` + `rea/validation.json` (7 dossiers).
- Native: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/814-scene-stage-entry-register/native-config.json --attempt 003` -> `local/experiments/v2-scene-stage-entry-register-814/003/receipt.json` PASS (33 cases/variant `/Od` & `/O2`, 10/10 mutations killed).
