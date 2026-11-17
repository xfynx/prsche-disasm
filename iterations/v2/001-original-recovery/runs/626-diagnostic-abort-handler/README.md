# Run626 diagnostic abort handler (`00565340`)

Bounded native x86-vs-C++ recovery proof for `00565340` (`00565340..005654bc`, 381B, sha256 `33d1703a90eedbf8824059487bb2a994f3450a56a838fd58ac036a0e11e24672`), exporting all three canonical aliases via `__declspec(naked)` `jmp diagnostic_report_varargs_00565340`:
- `porsche::file_diagnostic_00565340`
- `porsche::render_loader_report_00565340`
- `porsche::window_scheduler_diagnostic_00565340`

Owned loader-zero `.data` globals (24B total):
- `diagnostic_abort_active_006a5c24` (`0x006a5c24`)
- `diagnostic_abort_finish_005deb6c` (`0x005deb6c`)
- `diagnostic_abort_has_location_005deb84` (`0x005deb84`)
- `diagnostic_abort_cleanup_005deb8c` (`0x005deb8c`)
- `diagnostic_abort_hook_005deb90` (`0x005deb90`)
- `diagnostic_abort_filter_005deb94` (`0x005deb94`)

Owned read-only `.rdata` strings (51B total):
- `diagnostic_indent_fmt_005bd4c4[5]` (`0x005bd4c4`)
- `diagnostic_abort_title_005bd4cc[14]` (`0x005bd4cc`)
- `diagnostic_abort_file_line_fmt_005bd4dc[30]` (`0x005bd4dc`)
- `diagnostic_newline_005d0b1c[2]` (`0x005d0b1c`)

## Verification

- Attempt `002` (`local/experiments/v2-diagnostic-abort-handler-626/002/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/626-diagnostic-abort-handler/native-config.json --attempt 002`
  - `/Od` and `/O2` compiled with zero warnings (`/W4`) and printed `diagnostic_abort_handler_original_x86_vs_cpp=PASS cases=27 events=216`, comparing relocated original x86 against all 3 exported aliases and indirect C++ varargs forwarding.
  - Mutation controls (`wrong-reentrancy-guard`, `wrong-filter-clear`, `wrong-messagebox-flags`, `wrong-lock-cleanup-guard`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage/providers for `shared_runtime_word_005deb74`, `shared_runtime_word_005deb78`, `texture_create_errors_005deb80`, and returning callee/IAT mocks (`application_instance_exit_005a246e`, `exit_shutdown_exit_process`). Buffer overflow beyond `message[512]` / `title[128]`, actual process termination, and production CMake/registry integration remain open.
