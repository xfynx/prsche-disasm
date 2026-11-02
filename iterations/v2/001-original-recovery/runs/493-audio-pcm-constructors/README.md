# Run493: PCM constructors and callbacks

Native001 PASS, frozen:9 original C++ bodies711B/0 new state bytes.
`/Od` and `/O2` each pass68,750 cases/718 events; all13 material mutations
are detected. Total137,500 cases/1,436 events,387 pinned inputs. No failed
native attempt or production-source revision was required.

Bodies:597c10(47B),59cc30(46B),59cb50(76B),597b60(163B),59cba0(138B),
597b50(8B),59a520(115B),589710(38B),589740(80B). Addresses are hexadecimal VAs.
Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

Constructors use the proved cdecl2(object, mutable params) contract. Stream
construction captures params[5] before the bank lookup and reloads the low
byte of params[4] afterward. The callbacks use I32 cdecl5; direct decoder calls
use cdecl3. Used EAX returns and cdecl preserved registers/stack are compared.
Raw operands/call targets are checked before transport into the native slab.
The short omitted597b50 body has complete raw bytes, RET and callback assignment
provenance in `original-index-supplement.json`; the main generated index stays
unchanged. Indexed assembly/raw PE suffice; the unchanged469 cache contains
no dossier for these newly discovered descendants, so no REA session repeated.

The accepted487 source/header closure was checked across264 TUs/471 files,
including run-owned sources, with zero missing quoted includes or registered
indexed-body overlaps. Reuse486's PCM8 lookup/selected decoder and434's channel
view into the canonical application audio arena. No duplicate state or guessed
guards. All nine bodies are ordinary C++ without ASM or intrinsic kernels.
The unchanged492 S16 decoder and434 zero-fill body execute in the native graph.

The fixture checks mutable object/parameter aliases, early/late stream reads,
lookup-side channel-pointer mutation,65,536 signed ownerword patterns, member
selection, terminal/equal-limit/inclusive-loop behavior, decoder state changes,
raw PCM8 table/data overlap and zero/small-negative padded prefixes, actual
constructor/callback sequences, x87 PC/RC/depth and ABI. Initial lookup zero is
asserted before reset; unchanged486 scalar/434 arena initializer proof is reused.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/493-audio-pcm-constructors/native-config.json --attempt 1
```

Receipt: `local/experiments/v2-audio-pcm-constructors-493/001/receipt.json`.
Attempt001 and passed source/config/fixture inputs are immutable.

Two real typed providers remain unresolved:59c130(60B), I32 cdecl1(signed
channel owner) bank-index lookup, and59ca50(245B), I32 cdecl5 stream callback.
They are controlled fixture endpoints only; no production stub is introduced.
Do not enlarge this passed batch. Their bodies and full producer/stream scene
composition are the next trace. Unsafe huge negative-count clear, inaccessible
memory/unmasked faults, full channel allocation, concurrency and live audio/game
acceptance remain open. Coordinator owns registry/build/integration/docs/commit.
