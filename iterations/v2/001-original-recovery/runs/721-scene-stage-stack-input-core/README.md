# Run721 scene-stage stack-input core

Recovered `Porsche.exe` `004552b0..004553e6` (311B) as an explicit-input research core. **PARTIAL, off graph:** the normal production `scene_stage_reset_004552b0()` remains unresolved.

The original passes four never-written local stack bytes (`entryESP-0x24..-0x21`) to two tree constructors. Their real bodies copy byte1/byte3 into holder+8. These are real unspecified stack inputs, unlike Run716's saved entry ECX. `scope-evidence.json` pins original module/body SHA, exact instructions, child ABIs and the boundary. The core accepts a four-byte image explicitly; it does not locate bytes in the recovered compiler frame or invent zero values.

The algorithm retains nested8/12/12B allocation branches, the load call through root+4 even after first12B failure, the final76B allocation and used constructor return, both root writes, all256x32B matrix records and outputECX=0 on every normal path. Candidate research storage is00627df0/4B,006221d8/4B and00624de8..00626de7/8192B. Ownership review found zero registry/index/body_ranges overlap and zero address hits outside this run across all source/run C++ and headers. The original cells/matrix are loader-zero; production candidate defaults are checked before fixture reset.

Verification:

- `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/721-scene-stage-stack-input-core/native-config.json --attempt 001`
- PASS33 cases at each `/Od` and `/O2` (66 measured comparisons); seven material mutations detected. Zero production/core/chain warnings. Receipt: `local/experiments/v2-scene-stage-stack-input-core-721/001/receipt.json`; its SHA and exact current pins are in `evidence.json`.
- Original311B and unchanged716 raw bodies are module/body SHA checked before relocation. Synthetic CALL/CALL/CALL/RET and seeded original scratch-stack bytes are harness code. Controlled children inspect pointer adjacency and byte arguments, mutate referenced storage, return alternate constructor pointers, and record ordered effects.
- Four explicit opaque byte images, allocation failure masks and free-list refill cover all allocation branches. Comparison checks full8192B matrix, poisoned allocation bytes, roots, heap events and outputECX0. `compiled-chain-fixture.cpp` is compiled at both optimizations and calls the core then the two unchanged716 no-arg leaves. Release COFF emits CALL core/ADD ESP4/CALL43ed00/JMP455f60; ECX0 reaches both leaves without reseeding. COFF artifacts are beside the receipt.

This closes the research question about deterministic outgoingECX, not the production parent. Four children remain real frontiers:00455830,00455570,004558b0,0059f070. The first and third are bounded tree constructors with explicit byte-pointer input;00455570 loads external configuration into a tree. The next useful packet is the constructor pair, while provenance/transport of the parent stack image remains explicit. Do not put this research core, candidate storage or compiled test chain on the game graph. No accepted run, registry, shared manifest, plan or `local/game` was edited.
