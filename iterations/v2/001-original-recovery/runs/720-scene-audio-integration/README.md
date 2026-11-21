# Run720 shared scene and audio build

The Win32 build compiles 419 C++ translation units across eight projects. Three
unresolved symbols close: the audio reload entry and the two scene resets. The
link now reports 103 unresolved names / 110 references, with no executable.
The new symbols are DirectSound slot selection `0058f5b0` and creation `0058e500`.

The shared audit passes with 1,035 source pins, 274,526 comparisons summed over
`/Od` and `/O2`, and 58 detected mutations. REA attempt 002 independently
matches the index and raw PE for all six entries (856 bytes). Its first attempt
stopped when the sandbox denied child-process creation.

| Native proof | New entries | Cases per optimization | Controls |
| --- | --- | ---: | ---: |
| 715/006 | `00599610` | 128 | 13 |
| 716/011 | `0043ed00`, `00455f60` | 10 | 12 |
| 717/004 | `0058f220` | 216 | 12 |
| 718/002 | `0058f7a0` | 557 | 8 |
| 719/001 | `0058a970` | 136,352 | 13 |

The registry now has 1,173 entries. The reload loop stays **partial** for signed
initial counts 1..4. The original reserves four pointer slots. Oversized counts,
uninitialized slots and invalid allocations remain outside this proof.

The two scene functions each carry the high byte of incoming ECX into the holder
and restore ECX on return. Attempt 010 exposed the stale `/Od` output register
in the earlier implementation. Attempt 011 compares the restored register on
every exit. The production caller still needs its preceding `004552b0` provider.

The only newly owned game state is the pair of loader-zero scene roots, eight
bytes total. The audio iterator object also contains MSVC's four-byte weak
`__Avx2WmemEnabledWeakValue` COMDAT. The audio tables, map, device and heap
storage all reuse existing providers.

From the repository root, PowerShell resolves this batch's config as follows.
Use a fresh three-digit attempt for a subsequent configure/build and point its
acceptance config at that build.

```powershell
$run = 'iterations/v2/001-original-recovery/runs/720-scene-audio-integration'
py -3 scripts/research/build-v2-game-batch.py --config "$run/build-config.json" --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config "$run/build-config.json" --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config "$run/acceptance.json"
```
