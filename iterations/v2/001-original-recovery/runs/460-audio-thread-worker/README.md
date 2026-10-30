# Run460: omitted original audio thread worker

Native001 PASS first attempt:29 cases/261 observed events each at `/Od` and
`/O2` (58 cases/522 events total), with11 detected mutations. Main output hashes
are identical. Source/header/config/fixture and supplemental inputs are frozen.

One original87B stdcall1 worker0058f880..0058f8d6 is recovered. The main index
has no covering function; supplemental `audio-thread-460.jsonl` was written
before C++ implementation from the SHA-checked PE using Capstone5.0.7. Its28
instructions,30 CFG edges, both RET4 exits and0058e4b6 CreateThread argument
reference establish the complete extent/transport. `original-listing.asm` and
`original-evidence.json` retain the bytes, body SHA, queries and import identity.
No generated index or old run is changed; no REA session or game build is run.

The worker checks the volatile455 requested byte initially. On nonzero it
caches the real Sleep IAT once, then repeatedly loads/calls before-callback,
calls unrecovered0058f8e0 for effects, loads/calls after-callback, sleeps with
the zero-extended canonical device byte+0x21 and reloads requested. It always
clears455 running and returns0. Callback/mixer changes to requested do not
skip the remainder of the current body. Cached Sleep is an actual SDK IAT
data alias, not another stored pointer or wrapper identity.

New storage is one8B loader-zero block006b4a3c..006b4a43 with volatile before/
after views. It is disjoint from the canonical device span ending006b4a3b.
Complete456 source/header closure plus pending458 (427 paths) has no prior
callback owner;455 flags and the canonical434 device block are reused.
Raw original defaults/no-overlapping-relocations are checked before resets.
The main index references and complete absolute-address listing show callback
reads only. A producer/registration API has not been located; no producer
semantics or actual callback implementation is inferred. The proved used
transport is no arguments and ignored return (cdecl0/stdcall0 stack-equivalent).

The shared native fixture compares the whole device backing, flags, callback
cells, own IAT state and every callback/mixer/Sleep event. Before hooks it
asserts alias address equality and actual GetProcAddress(KERNEL32.Sleep)
identity. Own IAT swaps during before/mixer/after/Sleep distinguish cached
identity from a reload; protection and the original target are restored.
Direct synchronous stdcall1 probes check argument cleanup and nonvolatile
registers. No host thread is launched and no real Sleep or mixer is invoked.

Actual mixer0058f8e0, callback producers/implementations,455 parent composition,
live threads/scheduler/device behavior, faults/concurrency and full game remain
open. Root owns integration/build acceptance. All new proof inputs are UTF-8 LF.

Mutations detect the wrong initial predicate, reloaded Sleep instead of its
cached identity, cached before-callback, early after-callback capture, missing/
reordered mixer effects, signed/wrong-offset delay, wrong loop predicate,
missing running clear and nonzero return. Event bounds make nontermination
controls finite. Actual `/Od`/`/O2` COFF defines only the worker, callback block/
views and ordinary inline/compiler helpers; canonical flags/state/Sleep and
mixer remain references. `coff-ownership.json` retains actual symbols;
`import-binding.json` checks the alias directives and linked KERNEL32.Sleep
imports. `ownership.json` pins all427 preimplementation source/header paths;
they remain unchanged at closeout.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/460-audio-thread-worker/native-config.json --attempt 001
```

Receipt:`local/experiments/v2-audio-thread-worker-460/001/receipt.json`.
