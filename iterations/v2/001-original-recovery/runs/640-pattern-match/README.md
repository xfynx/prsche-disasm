# Run 640 audio transition pattern match (`004a5f90`, `.data 005d13bc..005d13c1`)

Bounded native x86-vs-C++ recovery packet for `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::audio_transition_pattern_match_004a5f90` (`004a5f90..004a615f`, 464B, `__cdecl(const char* text, char* pattern)` returning `uint32_t` `0`/`1` in `EAX`, sha256 `bc99ca1e282d5d849ebe969349677c81b6ef5aa6e3a944edcb1ded76574ba704`).
- `porsche::audio_transition_pattern_ops_005d13bc` (`.data 005d13bc..005d13c1`, 6B, `"&|!~^\0"`, sha256 `9b6e68213136ceab5942d4ec4775516d593edfb37cc8fd61b20a6b1931844e53`).

## Index, Ownership & Canonical Headers

- `calls.jsonl`: `4` `UNCONDITIONAL_CALL` sites across `2` functions (`004ade20` at `004ade58`, `004adec8`; `004ae4d0` at `004ae54d`, `004ae5e5`), plus `11` internal self-recursive calls and `4` calls to canonical helpers.
- `references.jsonl`: only `004a5f90` reads `005d13bc..005d13c1`; neither `004a5f90` nor `005d13bc` had a prior owner in `iterations/v2/001-original-recovery/`.
- Reused canonical headers:
  - `iterations/v2/001-original-recovery/source/include/porsche/formatter_text.hpp` (`formatter_text_find_last_005a2870`, `formatter_text_digit_005a2c52`)
  - `iterations/v2/001-original-recovery/source/include/porsche/formatter_float_helpers.hpp` (`formatter_float_lower_005a2248`)
- COFF section summary (`o2-0.obj`): `6` bytes `.data`, `0` bytes `.rdata`.

## Verification

- Attempt `001`: **PASS** (`local/experiments/v2-audio-transition-pattern-match-640/001/receipt.json`)
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/640-pattern-match/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with zero warnings and passed `audio_transition_pattern_match_original_x86_vs_cpp=PASS cases=78`.
  - All `9` material mutations (`wrong-last-op-comparison`, `wrong-and-operator-logic`, `wrong-or-operator-logic`, `wrong-tilde-split-restore`, `wrong-xor-eval-order`, `wrong-star-zero-char-skip`, `wrong-digit-signed-cast`, `wrong-lower-call-order`, `wrong-leaf-tilde-negation`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `004a5f90` and `.data` `005d13bc..005d13c1` across 78 test cases using writable 64B test buffers and deterministic C-locale boundary stubs for `formatter_text_find_last_005a2870`, `formatter_text_digit_005a2c52`, and `formatter_float_lower_005a2248`. Callers (`004ae4d0`, `004ade20`), non-C locale CRT behavior, read-only `pattern` memory faults, and production CMake/registry integration remain open.
