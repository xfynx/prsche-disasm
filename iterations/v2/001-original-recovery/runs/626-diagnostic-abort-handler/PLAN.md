# Run626 diagnostic abort handler

## Goal and criteria
- Recover original `00565340` (`00565340..005654bc`, 381B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) with full x86 varargs forwarding across `file_diagnostic_00565340`, `render_loader_report_00565340`, and `window_scheduler_diagnostic_00565340`.
- Own 24B of loader-zero `.data` (`006a5c24`, `005deb6c`, `005deb84`, `005deb8c`, `005deb90`, `005deb94`) and 51B of `.rdata` strings (`005bd4c4`, `005bd4cc`, `005bd4dc`, `005d0b1c`), reusing canonical headers without duplicate declarations.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Cached REA (`local/experiments/v2-frontier-469-rea/001/function-00565340.json`, `ev_21b72858f43682a361c355e63b793e0e549ec242ff1694e495c608739b85c373`) and PE bytes confirm the 381-byte body, all 30 relocations (22 absolute, 8 relative `E8`), and 51B `.rdata` strings.
- Reentrancy guard (`006a5c24`), optional varargs formatting via `005a299e`, filter hook (`005deb94`, clearing `006a5c24` on `0` return), file/line vs `"Abort Message"` title selection, `005deb8c`/`005deb90` callbacks, `ShowCursor(1)`, `MessageBoxA(0, msg, title, 0x11011)`, texture diagnostic logging (`005deb80 && 005deb6c`), `heap_leave_005322c0`, `0055f780`/`005a246e(0)`, and `ExitProcess(0)` match original x86 identically.
- Attempt `002` (`local/experiments/v2-diagnostic-abort-handler-626/002/receipt.json`) passed 27 cases (216 events) at `/Od` and `/O2` with zero `/W4` warnings and detected all 4 mutation controls (`wrong-reentrancy-guard`, `wrong-filter-clear`, `wrong-messagebox-flags`, `wrong-lock-cleanup-guard`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00565340`, 24B `.data`, and 51B `.rdata`.
- Buffer overflow beyond `message[512]` / `title[128]`, non-returning process termination, and production integration remain open.
