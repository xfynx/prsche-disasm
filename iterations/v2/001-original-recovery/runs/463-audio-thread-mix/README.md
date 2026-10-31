# Run463: original audio thread mix wrapper and mixer

Native002 passes `/Od` and `/O2`:104 cases/842 events in total and13 detected
mutations. The coordinator rechecked every native input after the worker reached
its quota; no passed production input changed.

Two original bodies/723B:0058f8e0 wrapper15B and0058f8f0 mixer708B. The wrapper
calls accepted434 enter, calls the real mixer and tail-jumps to434 leave.
The fixture uses those same real accepted lock providers on both sides; their
unchanged original proof is reused. Controlled platform endpoints observe the
canonical24B CS address and lock order without running a host critical section.
No new state is defined in463. Shared buffers/stream/guard come from462;
443 DS device/hardware,442 summary and the canonical device block are reused.

The mixer retains its original0x2c allocation above four saved registers.
Status is at frame+1c, shared Lock length+20 and the four-pointer array+2c..3b.
Unwritten locals are not cleared. Native events compare the entire allocated
44B backing at observable boundaries, with exact host-pointer relations and
no pointer normalization. A reused synthetic callsite supplies the opaque
stack seed. Once the mixer returns its private expired frame is not read.

GetStatus HRESULT is ignored; GetCurrentPosition uses `(self,NULL,&state.raw[2])`
and every nonzero HRESULT exits. Lock/Unlock HRESULTs are ignored, including
retained output cells. Signed guard comparison, position masks, wrap arithmetic,
two ring segments, reloads across COM/children, captured ring/end values and
channel layouts follow raw assembly. Channel counts are bounded0..4, with a
nonzero interleaved divisor. Unwritten output values are transported only to
controlled endpoints, which do not dereference unknown pointers.

Three lower bodies remain explicit typed production dependencies:
0058fcd0 void cdecl0 refresh effects,0058fbc0 void cdecl2(pointer-array,count)
render effects and0058f6c0 void cdecl0 optional voice effects. The fixture
supplies controlled observers/mutations for these boundaries; no replacement
algorithm is linked into game production. Real DS init, worker460 composition,
actual lower-body behavior, device/scheduler, faults/divide faults/concurrency
and full game acceptance remain outside this packet. Root465 owns shared REA,
integration/build and registry; no worker REA or game build is run.

Native001 stopped at the original-phase position-argument guard: raw PUSH order
proved the write-cursor output is the third logical argument. Both new C++ and
fixture had initially assumed the play-cursor output. Exact001 inputs are
archived under its `inputs`; no frozen accepted source was changed.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/463-audio-thread-mix/native-config.json --attempt 002
```

Receipt:`local/experiments/v2-audio-thread-mix-463/002/receipt.json`.
