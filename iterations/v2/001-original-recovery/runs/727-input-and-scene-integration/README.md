# Run727 input teardown and scene startup

The shared Win32 build compiles 423 translation units across eight projects.
Four reachable names close and seven child calls open, leaving 103 unresolved
names / 110 references. The game executable is still unlinked.

- Run725/003 recovers the two simulation teardown calls and DirectInput
  shutdown (120 original bytes). The next cleanup entry is `00533050`.
- Run721/001 and Run726/004 recover the blur setup, two mode helpers, and
  the following scene reset (634 original bytes). The sole indexed call to
  `004552b0` follows `00451490`. On that path the preceding tree lookup
  writes zero to the exact four stack bytes consumed by the constructors.
  Both lookup exits were checked. The binding carries those four bytes into
  the explicit-input core and returns ECX zero to the two Run716 leaves.
  The registry keeps `004552b0` partial for this caller.

Original-x86 comparisons passed 8,312 cases across both optimizations and
detected 24 mutations. The shared audit verified 1,046 source pins. Six scene
children remain: `00468240`, `004685e0`, `00455830`, `00455570`, `004558b0`,
and `0059f070`. The scene core owns 8,200 bytes of original loader-zero
storage; the blur setup owns another 48. Registry total: 1,182 entries.

```powershell
$run = 'iterations/v2/001-original-recovery/runs/727-input-and-scene-integration'
py -3 scripts/research/build-v2-game-batch.py --config "$run/build-config.json" --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config "$run/build-config.json" --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config "$run/acceptance.json"
```
