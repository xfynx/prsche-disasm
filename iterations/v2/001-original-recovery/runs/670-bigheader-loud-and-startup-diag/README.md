# Run 670 loud bigheader loader & startup diagnostic format (`005620c0`, `0059dea0`, `0059fd90`)

Bounded native x86-vs-C++ recovery proof for 3 functions (315 code bytes total) in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::file_load_bigheader_005620c0` (`005620c0..005620fe`, 63B, `__cdecl`, `ret 0`, sha256 `8f8e118a09d1f2fffd633b330884fe60ff834d28487eafe2816a19eacd7c890a`): exact loud sibling of `file_load_bigheader_quiet_00562300` (`runs/661-bigheader-and-audio-probe-configure`); populates `ResourceAtomicContext` with `callback_diagnostic_flag = 1`, snapshots `resource_leaf_group_005df770` before `file_device_name_00568e90(path)`, and dispatches `file_load_bigheader_callback_00562100` via `resource_leaf_atomic_dispatch_00568d50`.
- `porsche::resource_load_bigheader_0059dea0` (`0059dea0..0059df6d`, 206B, `__cdecl`, `ret 0`, sha256 `fdf31c1b28a61512ef3c56a0127a4db29b5f0bd7d20d9ae6844041f839e95592`): exact loud sibling of `resource_load_bigheader_quiet_0059df70` (`runs/661-bigheader-and-audio-probe-configure`); resolves `file_root_006af168` / `file_fallback_006af26c` / `file_roots_enabled_006af370` with `formatter_entry_005a0fbf` (`"%s%s"` at `005cc588`) and `file_exists_00561b80`, invokes `missing_file_006afbe4(name, -2)` on miss, and delegates to `file_load_bigheader_005620c0`.
- `porsche::startup_diagnostic_format_0059fd90` (`0059fd90..0059fdbd`, 46B, `__cdecl`, `ret 0`, sha256 `a077315c01ba62bba2ac4d329b691c06a83c6aff261d4e5041144febacfa99b0`): formats varargs into a 1024-byte stack buffer via `application_diagnostic_mono_vsprintf_005a299e` and passes the same buffer (`[esp + 0x0c]` after the 3-DWORD call args) to `startup_diagnostic_sink_0059fc20`.

## Index, Ownership & Canonical Headers

- Zero new `.data`/`.rdata` ownership (`"%s%s"` at `005cc588` is a shared read-only literal).
- Reuses canonical headers: `porsche/files.hpp`, `porsche/formatter_entry.hpp`, `porsche/resource_dispatch.hpp`, `porsche/resource_leaf.hpp`, `runs/353-diagnostic-mono/diagnostic_mono.hpp` (`005a299e`), `runs/390-diagnostic-terminal/diagnostic_terminal.hpp` (`0059fc20`), and `runs/661-bigheader-and-audio-probe-configure/bigheader_audio_configure_661.hpp` (`00562100`).

## Verification

- Attempt `001`: **PASS** (`local/experiments/v2-bigheader-loud-startup-diag-670/001/receipt.json`, sha256 `8618688a85d44065de1ab6bf6d6dedafbf462526ce8f8c324e749a5c51deb318`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/670-bigheader-loud-and-startup-diag/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with 0 `/W4` warnings and passed `bigheader_loud_startup_diag_original_x86_vs_cpp=PASS cases=27`.
  - All `12/12` material mutations exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `005620c0`, `0059dea0`, and `0059fd90` using `<260B` paths, `<=1023B` formatted diagnostic buffers, controlled deterministic callee stubs, and canonical bindings; production CMake/registry integration and live caller/callee composition remain open.
