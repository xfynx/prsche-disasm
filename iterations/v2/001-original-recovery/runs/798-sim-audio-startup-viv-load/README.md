# Run798 — sim_audio_startup_viv_load (`004affd0`, `005665b0`)
- Recovered `?startup_sequence_call_004affd0@porsche@@YAXXZ` (`004affd0..004b04cd`, 1278B) + `big_find_entry_005665b0` (`005665b0..005666e4`, 309B; 1587B code, 202B `.data`, 14B `.bss`, 0 new unresolved game symbols) in `sim_audio_startup_viv_load_798.cpp`/`.hpp`.
- Native differential + mutations PASS: `local/experiments/v2-sim-audio-startup-viv-load-798/007/receipt.json` (`/Od` & `/O2`: 7 cases, 40 events; 11/11 mutations killed).
- REA + validation PASS: `local/experiments/v2-sim-audio-startup-viv-load-798-rea/001/receipt.json`, `validation.json` (`dossiers: 2, repeated_equal: 0`).
