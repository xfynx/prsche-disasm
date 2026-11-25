# Run842: Application replay save closure

Recovers `application_sim_boundary_00413fd0` (`00413fd0..0041405d` 142B replay snapshot save + `.data` literals `005cc68c` 11B, `005cc678` 19B), `resource_save_0059e170` (`0059e170..0059e1af` 64B), `file_save_00562460` (`00562460..005624a6` 71B), and `file_save_callback_00562390` (`00562390..00562451` 194B + `.rdata` literals `005bcd00` 20B, `005bceb0` 40B, `005bce8c` 36B; 0 new unresolved symbols).
Native comparison `local/experiments/v2-application-replay-save-842/004/receipt.json` PASS (5 cases / variant `/Od` & `/O2`, 6/6 mutations killed).
REA `local/experiments/v2-application-replay-save-842-rea/001/receipt.json` + `validation.json` PASS (5 dossiers, 0 repeated equal).
