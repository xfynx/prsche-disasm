# Run722: DirectSound slot allocation and buffer creation

Full originals `0058f5b0..0058f5cd` (30B) and `0058e500..0058e648` (329B),
359 new code bytes, zero owned data. The canonical Run717 cdecl0/cdecl1 signatures
are retained. Run443 owns device006ad760; Run452 owns all256x24B slots006ad7b8.
Both actual owner TUs and actual Run717 configure source are linked into proof.
Full raw PE disassembly/hashes, indexed calls and reused Ghidra provenance are
in scope-evidence.json. Registry1167 has no candidate entry/body overlap.

Allocator skips slot0, examines rows1..255 and returns the first zero DWORD,
or0 when all are occupied. Buffer create saves source/count, builds the exact
18 meaningful WAVEFORMATEX bytes and zeroed36B descriptor(flags0x480b0), calls
CreateSoundBuffer, then Lock/copy/Unlock through original vtable offsets0xc,
0x2c/0x4c. The original uses bits16 when row+17 is8, otherwise bits=slot argument.
A failed Lock still returns slot; nonzero Create or Unlock returns0. The copier
reloads signed format/flag bytes and start/end after Lock; Unlock reloads the
current row+4 object after the copier. These unusual details follow raw assembly.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/722-audio-slot-create/native-config.json --attempt 001
```

PASS001:1,405 cases at each /Od and /O2;18/18 material /O2 controls detected.
Receipt: `local/experiments/v2-audio-slot-create-722/001/receipt.json`.
Before any resets, actual owner device/table bytes match raw PE file-backed or
loader-zero bytes. Native checks compare complete table and output bytes,
ordered COM/copy arguments, meaningful descriptor/wave bytes, used results,
ESP and callee-saved registers. Five allocator cases,1,344 direct-create cases
and56 actual717+722 composition cases cover all-full/first/last slots, source0,
signed end guards, rate zero-extension, signed format/flag extension, positive
and negative COM failures, failed Lock continuation, callback row/object changes
and reloaded versus cached inputs. Original code relocation is limited to
canonical data and proved call boundaries; no synthetic RET body stands in for
a recovered body.

CreateSoundBuffer/Lock/Unlock use controlled stdcall endpoints; copy0058e310
is an unresolved cdecl7 provider with ignored return. Real DirectSound and the
copy algorithm remain open, together with unbounded/invalid positive slots,
callback output alias/failure contracts outside the stated domain, faults,
concurrency, CMake/registry integration and full startup. No shared graph
integration is claimed by this packet.
