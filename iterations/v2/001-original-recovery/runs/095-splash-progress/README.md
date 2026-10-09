# Run 095 - splash and progress consumer

This run recovers the bounded `Porsche.exe` function `004a4a70` (2,424 bytes;
SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
The original-first index query is `query-binary-index.py --binary Porsche.exe
--address 0x4a4a70 --limit 100 --disassemble`. It records direct callers
`00414db0`, `00468fb0`, `0048cdf0`, `004b67b0`, and `004b6a50`. The body handles
splash/loading phases, progress updates, and explicit disable; it is not a full
front-end or game bootstrap.

The C++ consumer follows the indexed phase gates, raw FSH table walks and tile
geometry, FE format selection, network predicates and lock order, player-card
fields, progress text, and frame presentation order. Phase zero enables the
consumer and creates the 640 x 480 texture once using the raw-backed
`005dead0` DWORD (original value zero) and flags `0x10`. Phase ten clears the
enable byte and returns. The arena at `006573e8..0065b20b` uses the existing
`ApplicationStateArena`. Owners in this unit are `00655a24` (`uint32` texture),
`00655a28` (`uint8` enable), `005dead0` (`uint32` format), and `0065b350`
(`const char*` pointer cell, original BSS value null). The `0065b334` loader root
and texture dimensions `005deac8/005deacc` reuse their existing shared owners.

The phase progress offset uses the binary32 `12.4` constant and x87 conversion
boundary `005a0f98`; the verifier initializes x87 state to architectural reset
control word `0x037f` and matches the resulting truncation. The visible-player
path reads the selection fields at offsets `+4/+8/+0xC`, resolves the sprite,
then computes a 32-bit wrapping `player_value * 54`, interprets that product as
signed, and divides by 10 toward zero. It draws the original remaining/progress
text values and positions. `004903f0` is an explicit-object
C bridge in native code. The original call proof remains ECX=`this`, one
16-bit key at `[ESP+4]`, and callee `ret 4`.

Asset lookup/formatting, FSH draw/flip, resource counters, player lookup, lock,
frame/driver work, and four THRASH imports are typed recorder boundaries. They
preserve observed arguments and ordering, but do not implement asset or
renderer effects. The THRASH imports are stdcall as shown by decorated names
`_THRASH_window@4`, `_THRASH_clearwindow@0`, `_THRASH_sync@4`, and
`_THRASH_pageflip@0`; the original callers do not clean those arguments.

The differential verifier runs original x86 under Unicorn against the isolated
MSVC x86 C++ probe. All 35 cases currently match touched state and ordered
boundary calls across phases 0 through 10, negative values, texture reuse,
format selection, asset-exists branches, network guards, wait-pump ordering,
mirror/reverse flags, player visibility/selection, and signed progress overflow
edges. Resource memory and
callbacks are deterministic fixtures. This proves the consumer against those
contracts; it does not prove real asset loading, rendered pixels, complete FE
startup, or a playable game. Source dependency hashes and the per-case trace
are in `verification.json`.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/095-splash-progress `
  -B local/builds/v2/001-original-recovery/splash-progress-095 `
  -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/splash-progress-095 --config Release
py -3 scripts/research/verify-v2-splash-progress.py `
  --probe local/builds/v2/001-original-recovery/splash-progress-095/bin/Release/splash_progress_probe.exe `
  --report iterations/v2/001-original-recovery/runs/095-splash-progress/verification.json
```
