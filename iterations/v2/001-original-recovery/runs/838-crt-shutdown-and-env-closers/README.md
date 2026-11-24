# Run838: CRT shutdown and diagnostic environment lookup closers

Recovers `exit_shutdown_static_callback_005a36d6` (`005a36d6..005a36e9` + `_flushall`/`__flsall`/`_fflush_nolock`/`_commit`/`_fcloseall`/`fclose`/`_fclose_lk`/`__freebuf`/`_close`/`_close_lk` + `.bss` `_nstream`/`__piob`) and `application_diagnostic_environment_inner_005a3071` (`005a3071` + `__mbtow_environ`/`__crtsetenv`/`findenv`/`copy_environ`/`_strdup`/`_mbschr`/`__mbsnbicoll`/`__crtCompareStringA` + `.bss` env/compare state, 0 new unresolved symbols).
Native comparison `local/experiments/v2-crt-shutdown-env-838/002/receipt.json` PASS (7 cases / variant `/Od` & `/O2`, 9/9 mutations killed).
REA `local/experiments/v2-crt-shutdown-env-838-rea/001/receipt.json` + `validation.json` PASS (12 dossiers, 0 repeated equal).
