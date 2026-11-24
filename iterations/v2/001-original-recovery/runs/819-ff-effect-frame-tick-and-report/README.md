# Run819: FF effect frame tick and startup report adapter

Recovers `ff_effect_frame_tick_004123e0` and its 10 direct FF effect helpers (`3,546B`, 4B `.bss` `005e9540`, `004123e0` supplemented in `original-index-supplement.json`) plus `startup_sequence_report_005a177b` (`005d1400` 26B, `005d6e3c` 36B `.data`).
Native comparison `local/experiments/v2-ff-effect-frame-tick-819/008/receipt.json` PASS (`8` cases / `78` events per `/Od` and `/O2`, `12/12` mutations killed).
REA `local/experiments/v2-ff-effect-frame-tick-819-rea/001/receipt.json` + `validation.json` PASS (`10` dossiers, `0` repeated equal).
