# Run531: stage and mutable-record provenance

Research only; no implementation or native acceptance. Original Porsche.exe SHA
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Raw complete bodies, indexed callers/absolute references and independent raw
E8/pointer occurrence census are saved alongside this report. All candidate E8
counts agree with the corresponding indexed direct-call counts for these targets.
This is bounded static evidence, not proof against arbitrary pointer aliases.

535a90/104B is cdecl2 and forwards a full DWORD result from canonical stdcall2
setstate slot27. With69dd1c zero it passes both inputs unchanged. Otherwise it
uses signed `(int32_t)key >>16` for the physical offset `56*stage`; it reads
5de6e8+offset, then5de6f0+offset only if the first word is not1. API key output
uses `(key&0xf0000)|0xd`. Its read index must not be replaced by that four-bit
output mask. Arbitrary keys imply stage -32768..32767 and possible DWORD starts
41e6e8..79e6b8; only stage0/1 words lie in the existing112B owner. No guard,
clamp, duplicate broad arena or inferred stage0/1 contract is proposed.

The absolute reference census finds these record writers:

- 5359a0/186B, raw initializer pointer at5cb754: writes the missing first-block
  keys0xb/8/0x41/0x42 and all second-block keys0x10005/7/c/b/8/41/42 plus values.
  It reads scalar5de6b4, raw bits3e800000; parent CRT invocation remains unproved.
- 536000/77B, thiscall2/RET8: writes seven value DWORDs at
  5de6c0+56*stage+8*i, retaining actual compare/write/callback order.
  Its only direct caller536ab5 pushes stage0.
- 536240/342B, thiscall2/RET8: performs the same seven-value updates for each
  nonnull node argument, taking signed stage from node+1c. No range check exists.
- 536470/150B, thiscall1/RET4: copies seven state DWORDs into node+38, then
  updates the fixed stage0 or stage1 value block if that node is active.

535b00 and5363a0 only read these records. Indexed dynamic value stores always
address0mod8; record keys are4mod8. That arithmetic separates those particular
stores from key DWORDs, but proves neither safe stage ranges nor absence of
other aliases. Stage2 stores can overwrite live callback slots1/3/5.

Node+1c is assigned unchanged flags by535bc0/365B,535d80/336B and535ed0/224B;
536120/84B copies it. Factories536180 and5361e0 forward their flags arguments.
Direct constructor calls are4232a4,44dac2,4d6a76,4d7361 and460a99 (plus the
factories). Four nonfactory paths push flags0.44dac2 passes local mip flags OR
caller flags:44da10 loads caller argument5 when6197a8 is nonzero; its local
44d7e0 helper produces only the low count bits.44da10 has callers44d3df and
460caa; the latter pushes0, while44d3df forwards44d380 argument7. Therefore
the original producer domain remains unproved. Next bounded trace:44d380
argument7 producers, including their calls through material/cache consumers,
and actual resource-factory slot4/8 inputs. No stage-domain claim follows from
initial keys, callee RET arity or the four constant-zero constructor paths.

69dd1c has exactly three indexed absolute references:535a90 reads it and
535b50 writes it after setstate41/42 results. Existing adjacent69dd1d remains
owned by render_mode.cpp. Resource constructors/table move to separate Run533;
they do not resolve the stage producer boundary.

```powershell
py -3 local/trace-render-stage-531.py
```

No production, frozen527, shared build, registry or root-document edits.
