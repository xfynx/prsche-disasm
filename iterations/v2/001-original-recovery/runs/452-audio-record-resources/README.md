# Run452: original audio record resource removal

Four complete original bodies/210B:005996d0,0058f820,0058f7e0,0058f290.
Native001 passes at `/Od` and `/O2`:67 branch-driven cases,11 observed COM
events per variant, ABI/default-state checks and10 detected mutations.
The passed production source/header, fixture and native config are frozen.
Run453 owns shared integration and acceptance with the decoder Run451.

The canonical remover is cdecl(record)->int32 zero. Run448's existing
void(record,scratch) symbol is retained as a forwarding facade, with zero added
original-body count. The four real original bodies execute together in the
oracle; the C++ chain uses the four corresponding production providers.
The scratch argument is untouched. Lookup returns the first exact8B row using
the unsigned low16 count; erase clears only that row's key. Missing map, missing
key, zero handle, duplicate/zero keys and count0/32768/65535 are covered.

The new canonical globals are the DWORD count006b48a0, pointer006b48a4 and
6144B slot table006ad7b8..006aefb7. Allocator0058f5b0 starts at row1 and scans
255 usable rows with24B stride to exclusive006aefb8;0058f220 and0058e500 prove
the packed row fields and COM object+4. Start0058fdb0 sets low16 count256 and
allocates0x800 map bytes conditionally;0058fe80 frees the map.0058ebe0 is traced
without inventing a blanket slot initialization: all new storage lies entirely
in the raw PE's loader-zero .data tail, with no relocation targets. Production
defaults are compared directly to the original virtual bytes before fixture resets.

Canonical DS device006ad760 is reused from Run443. Controlled stdcall Release
observes key-erasure before the call and slot-flag clearing after the call.
Callback mutations change object/handle/map/count/device/record and slot flags;
full maps, all6144 slot bytes, record and scratch are compared afterwards.
Release uses uint32 address arithmetic with no index or null-object guard.
Mapped slot0/255 and a wrapped uint32 index aliasing row1 are exercised.

Ownership evidence checks all624 accepted function ranges for entry/interior
overlap, with none found.450 baseline manifest plus source_delta covers417 unique
source/header paths, pinned in original-evidence.json; no existing provider is
found. The broader source/run scan finds only Run179 extern declarations for
006ad7b8/006ad7d0. New regions are disjoint from the existing443 cells and device
backing006b48b0..006b4a3b. Actual COFF has eight exports in each optimization
variant:four original providers,one facade,three data cells; DS device is undefined
here and defined by the reused443 source. REA453 attempt001 supplies the four
dossiers; the full indexed assembly fixes ABI ambiguity in the truncated older
local005996d0 listing. Sources were UTF-8 LF before native proof.

Controlled COM transport does not establish live DirectSound behavior. Invalid
or unmapped memory, concurrent access, actual subscriber behavior, real448 parent
composition and whole-game acceptance remain outside this standalone packet.
No registry, old run, game resource or game build was changed by this worker.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/452-audio-record-resources/native-config.json --attempt 001
```

Receipt:`local/experiments/v2-audio-record-resources-452/001/receipt.json`.
Original VA/SHA/data/ownership evidence:`original-evidence.json` and
`original-listing.asm`; actual object symbols:`coff-ownership.json`.
