# Run724 shared audio slot build and ABI bindings

On the Run720 baseline, the game compiles 420 translation units across eight
projects. Four names close and the audio copier `0058e310` opens. The linker
reports 100 unresolved names and 107 references. No game executable linked.

- Run722/001 adds 359 original bytes at `0058f5b0` and `0058e500`. It reuses
  the Run443 device and Run452 slot storage. DirectSound creation, locking and
  unlocking were compared through controlled endpoints, including Run717 as
  the actual caller. Live DirectSound and the copier remain open.
- Run723 audio/003 and scene/002 bind the two existing callers of `004a6c90`
  and `004521c0` to their canonical providers. The checked scene call discards
  EAX. Both aliases introduce zero production bodies or data cells.

The shared audit passed 5,486 original-x86 comparisons across both compiler
optimizations, 20 mutation controls and 1,039 source pins. The registry has
1,175 entries. REA session 001 checks the two new bodies, the canonical alias
targets and eight related current or prospective dependencies.

```powershell
$run = 'iterations/v2/001-original-recovery/runs/724-audio-slot-and-abi-integration'
py -3 scripts/research/build-v2-game-batch.py --config "$run/build-config.json" --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config "$run/build-config.json" --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config "$run/acceptance.json"
```
