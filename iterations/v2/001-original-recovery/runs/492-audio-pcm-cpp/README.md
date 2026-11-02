# Run492: PCM algorithms in C++

Native001 PASS, frozen:4 original algorithms520B plus4B readonly bias.
`/Od` and `/O2` each pass104,351 cases/1,020 events;12 adapted mutations are
detected. Total208,702 cases/2,040 events. No prior492 failure or input revision.
This is the production-provider candidate;490 remains frozen unintegrated
original-x86 research/oracle material.

Public residual/block loops, signed/unsigned count tests, pointer arithmetic,
alignment branches, alias ordering and chaining/saturation are ordinary C++.
The SSE provider uses intrinsics. There are no naked functions or whole-function
ASM bodies. Frozen486's legacy `_x87_0059baf0` name still identifies actual SSE.

Small private x87 primitives retain original rounding and stack state. The
four-lane accumulation primitive has21 FP operations: four live80-bit products,
all additions before stores and the exact FXCH/store permutation. The eight-lane
S16 primitive has17 FP operations to preserve load-before-store and masked x87
stack overflow. Neither contains branches, loops or count/address-step logic.
The C++ scalar loop explicitly balances the private live ST0 gain entry; no
foreign call occurs while it is live. Bias conversion uses the original x87
FLOAT32 store boundary. No float/double approximation replaces these operations.

Actual475/479 and597b96/597bd4/59cae1/59cbd9 consumer instructions reload ECX,
return, or use other state after provider calls. They do not consume the kernels'
incidental preservation of incoming volatile ECX. The fixture therefore checks
the real cdecl preserved registers and used EAX returns; no ABI wrapper was added.

Original addresses:0059ba70(125B),0059baf0(159B),0059b9f0(114B),0059a350(122B).
Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Readonly005c1800 is raw0000404b /12582912.0F. Its sole production ownership moves
to492;490 has no game/registry provider. No initializer0059a3d0 is duplicated.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/492-audio-pcm-cpp/native-config.json --attempt 1
```

Receipt: `local/experiments/v2-audio-pcm-cpp-492/001/receipt.json`.
The490 raw bodies and cases are reused: all source/destination alignments,
residual/block/overlap scenes,65,536 S16 patterns, NaNs/subnormals/infinities,
saturation neighbors, callback state/return mutations, x87 PC/RC/depth and SSE
MXCSR rounding/FTZ/DAZ/sticky flags. Zero/small-negative padded prefixes retain
original behavior. Nonpositive unaligned SSE, unmasked faults, whole producer/
selector composition, concurrency and live audio/game acceptance remain open.
The two typed3DNow providers remain unresolved because this host lacks an oracle;
no fallback or approximate provider is introduced. No passed490/486 input changes.
