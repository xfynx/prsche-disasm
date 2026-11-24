# Run828: CRT signal table, exit filter callback, and diagnostic closers

Recovers `exit_shutdown_static_callback_005ac147` (13B `.text` + 4B `.bss` `006afed0`, supplemented in `original-index-supplement.json`), `formatter_crt_signal_table_005e5ec8` (120B `.data`), and the three `diagnostic_handler_005debf0` call-site adapters `application_memory_diagnostic` (56B `.data` `005e4ffc`), `window_register_diagnostic`, and `timer_diagnostic_boundary` (0 new unresolved symbols).
Native comparison `local/experiments/v2-crt-exit-diag-828/001/receipt.json` PASS (`5` cases / `18` events per `/Od` and `/O2`, `6/6` mutations killed).
REA `local/experiments/v2-crt-exit-diag-828-rea/001/receipt.json` + `validation.json` PASS (`5` dossiers, `0` repeated equal).
