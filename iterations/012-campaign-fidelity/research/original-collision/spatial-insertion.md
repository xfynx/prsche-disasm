# Original spatial child constructor; insertion still open

2026-10-05. `Porsche.exe` SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries for `0x484ae0` and `0x483bd0` with `--disassemble --limit 2000`
are preserved in [spatial-insertion-source.jsonl](spatial-insertion-source.jsonl).
The indexed function extents are `0x484ae0..0x4850be` (1503 bytes) and
`0x483bd0..0x483c98` (201 bytes); raw instruction coverage was exported intact.

`0x483bd0` constructs a child in supplied memory, with no allocation calls:
increment the four-bit level, double the fourteen-bit X/Z coordinates, then
add quadrant bits, all wrapping within their original fields. Selectors 0/1
increment Z; selectors 1/3 increment X. All other selectors take the same
branch as 2. It clears children at +4,+8,+0xc,+0x10 and records at +0x14;
EAX returns the destination pointer.

[replay-spatial-insertion.py](../../../../scripts/research/replay-spatial-insertion.py)
currently executes this **constructor only**, on 32 parent words and eight
selectors each. All 256 original-x86 outputs match `SpatialNode::child`:
packed value, five cleared pointers, and returned destination. Inputs cover
coordinate/level overflow, random words, and nonstandard selectors. Initial
destination slots contain nonzero sentinels; no instruction/call is replaced.

`0x484ae0` is a different, recursive insertion operation, not restored here.
Its entry calls `0x484320`; its branches call actual object vtable +4/+8
callbacks, recursively invoke itself, allocate nodes through `0x4211d0`, and
append record vectors through `0x59ef90` / `0x505810`. Those paths need their
own contracts and replay. The exported source is not claimed as a port.

Next owner: coordinator. Trace `0x484320` and type-1 quad/triangle vtable
+4/+8 consumers first; prepare original constructors and fully preallocated
nodes/vectors for bounded recursive insertion replay without call stubs.
If an allocation branch is required, establish its state rather than skip it.
Then restore insertion and compare node/record ordering before runtime binding.
The earlier executor reached its usage limit after exporting source; the
export was retained and the constructor was completed by the coordinator.
