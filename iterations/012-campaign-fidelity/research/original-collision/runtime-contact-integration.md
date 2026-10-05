# Live support/contact integration contract (Run 018 trace)

2026-10-05. Original module `Porsche.exe`, SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
All addresses are VA. Navigation started in
`research/binary-index/README.md`; queries used
`py -3 scripts/research/query-binary-index.py --binary Porsche.exe --address
<VA> --disassemble --limit 1200` for `0x474060`, `0x473240`, `0x474320`,
`0x474420`, `0x4745f0`, `0x495020`, `0x499a70`, `0x49b090`, `0x532880`,
`0x56e8f5`. Source-verified raw ranges used
`py -3 scripts/research/inspect-pe-range.py --binary Porsche.exe --address
<VA> --size <N>` for vtables `0x5b4880/0x5b48b0` and callbacks
`0x485b50/0x485f90/0x485b10/0x486030`. Existing focused exports and
replays: `support-tree-source.jsonl`, `support-source.jsonl`,
`vehicle-0x495020.jsonl`, Run 013 and Run 017. The query index is navigation;
the instructions and differential runs establish the bounded behavior below.

## Exact original vehicle consumers

`0x499a70` is the direct four-wheel support consumer. At `0x499b15` its index
starts at zero; `0x499b26` sets owner to `car+0x7bc`. For each point at
`[esp+0xd0+index]`, `0x499b2c..0x499b61` copies it to owner `+0x30`, pushes
point and literal `1`, and `0x499b64` calls `0x474060`. `0x499b6b` calls
`0x474420`, returning owner `+0x0c` cached normal. `0x499b84..0x499ba7`
copies owner `+0x24` flags to per-wheel `+0x88`, with a special nibble `1/10`
remap to `2` gated by global `0x6573f8`. `0x499bb8` invokes `0x494480`;
its nonzero result takes an alternate height branch at `0x499bc4..0x499c32`.
The zero-result branch calls `0x4745f0` for polygon point at `0x499c3b`
and computes the plane height at `0x499c42..0x499c7b`:

```
height = base.y - ((query.x-base.x)*normal.x +
                   (query.z-base.z)*normal.z) / normal.y
```

It then calls `0x499730` and adds its result before storing the wheel-side
height. This extra term, the `0x494480` branch, later spring/contact force
law, and wheel-owner lifecycle are not restored by the plane adapter. The
loop continues until byte offset `0x30` (`0x499f05..0x499f10`): four points
at 12-byte increments. Original callback data feeds later wheel state;
injecting its height into the current spring formula is a staged integration,
not proof of original suspension dynamics.

The separate body/edge path is `0x4980d0` calls `0x495020` at
`0x498114/0x498120/0x49816d/0x498179`, and `0x495020` builds eight body
candidate points from `car+0x330`, velocity `+0x33c`, basis `+0x364/+0x370/
+0x37c`, extents `+0x3a8/+0x3ac/+0x3b0`, calls `0x474060` at
`0x495275/0x495303/0x49538f`, and may call `0x4740d0` for type-2 EDG at
`0x4953ee/0x495410`. Accepted EDG geometry calls `0x494000` at `0x4954ff`.
The exact eight-point order and prepared response are in
`angular-response.md` and `response.md`. The current
`physics::original_contact::respond_prepared_contact` takes a fully prepared
car state/normal/correction. Current `VehicleSimulation` does not supply
original `+0xd58`, `+0x490/+0x4a8`, `+0x52c`, point groups `+0x7f8`, or
the original acceptance and correction state. Calling this kernel from the
current chassis or wheel hit would manufacture those fields.

## Owner, cache, normal, and point

`0x474060` checks owner `+0x28` cached polygon. If nonnull and its virtual
`+0x0c` XZ containment accepts the point, caller flag `1` jumps to return
without a new tree query (`0x474069..0x474082`). Otherwise it calls
`0x473240` at `0x474087`, updates owner `+0x28`, clears owner byte `+2`,
copies selected polygon word `+0x0a` into owner `+0x24` (zero on miss), sets
owner byte `+0x0a` to zero on hit or one on miss, and writes changed byte `+9`.
The spatial node cache at owner `+0x2c` belongs to `0x473240`, not `+0x28`.
That function may retain a cached node when its inclusive bounds accept the
query, then scans ordered leaf records of type `1`, low nibble of polygon word
`+0x0a` nonzero, XZ containment true, selecting strictly least
`abs(center.y-query.y)`; equal distances preserve first record. The full
cached tree is in `physics::original_support_tree` and `spatial-query.md`.

`0x474420` calls `0x474320` and returns owner `+0x0c`. When a polygon is
present, `0x474320` calls polygon vtable slot `+0x14` to fill this normal;
`0x4745f0` calls vtable slot `+0x18` with vertex index zero to return the
source plane point (`0x5b4880+0x18` is `0x485b10` for quad;
`0x5b48b0+0x18` is `0x486030` for triangle). The raw slot `+0x14`
targets are `0x485b50` quad and `0x485f90` triangle. For triangle vertices
`v0,v1,v2`, they set `a=v1-v0`, `b=v0-v2`; for quad vertices `v0..v3`,
`a=((v2-v3)+(v1-v0))*0.5`, `b=((v0-v3)+(v1-v2))*0.5`, with f32 stores.
Virtual callback uses cross(a,b) for polygon orientation byte `+8` nonzero,
otherwise cross(b,a), then normalizes. A Y result at least float bits
`0x3f7ff972` is set to those bits. `0x532880/0x56e8f5` establish cross
component order. These callbacks are distinct from the constructor
`0x489f90` plane used for quad splitting.

`physics/original_support_owner.rs` implements this bounded point/plane
contract with separate polygon and node caches. It rejects zero/nonfinite
normal Y or nonfinite plane height, for which a finite portable hit cannot
be supplied. Such cases and x87 precision beyond the saved fixture corpus
are outside its exactness claim. The original divide has no equivalent
portable failure return.

The bounded differential run is
`py -3 scripts/research/replay-support-owner.py --run-dir
iterations/012-campaign-fidelity/runs/018-original-support-runtime`.
It executes unchanged `0x484ae0` insertion, `0x474060` and its cached
`0x473240` query, `0x474420/0x474320` and both original polygon normal
callbacks, `0x4745f0` point callback, and the original wheel plane arithmetic
slice `0x499c40..0x499c7b`. The existing harness supplies a bounded heap
arena; only imported Win32 critical-section services are modeled for one
thread. `owner-replay.json` and `owner-fixtures.tsv` contain ten cases:
stacked deck cache retain/refresh/miss, sloped triangle and reversed winding,
twisted quad and reversed winding. Rust
`cargo test --locked --manifest-path iterations/012-campaign-fidelity/Cargo.toml
--target-dir local/builds/012-campaign-fidelity/.cargo-target -p nfs-assets
--test original_support_owner` matches selected polygon, cached node,
normal, source point and plane height across all ten. Tolerance for computed
normal/height is `2e-6`; source point equality is exact. This checks a
bounded synthetic corpus, not a real track or full wheel solver.

## Live 012 mapping and limits

`track_loader.rs:to_scene_coordinates` converts source `[x,y,z]` to render
`[x,y,-z]`. Original vertices and queries must remain in source axes through
`SupportTree`, owner selection and plane arithmetic. Convert only at the
`RoadSurface` boundary: point `z -> -z`, hit normal `z -> -z`, height unchanged.
No length or time multiplier was inferred from this sign flip.

Current `VehicleSimulation::step` (`vehicle.rs:286`) clamps frame `dt`, splits
it into substeps, calls `suspension.update_surface_contact` first, then its
own powertrain/tire forces, integrates the rigid body, and resolves chassis
corners. The live suspension uses `RoadSurface::suspension_ray` along the
rotated local down axis (`suspension.rs:197`), with its own reach, 0.49
penetration, spring/damper and antiroll law. It does **not** call
`RoadSurface::query`. `RoadSurface::query` is used by `chassis.rs:89` and
renderer/AI/spawn queries, and currently chooses RD-name filtered source
triangles by plane-height distance and max-step/drop limits. Source type-1
selection uses polygon-center Y and cached history instead; it does not
take these limits. A current wheel mount is not automatically the original
`0x499b2c` query point. The helper offers source-backed polygon selection
and plane data, while the live adapter must state which current point and
ray acceptance it uses. Any retained spring/chassis forces remain the
preexisting reconstructed solver.

`SupportTree` currently holds type-1 polygons only. The original scene tree
also holds type-2 EDG objects, because `0x4740d0` traverses the same
`[0x628960]+0x24` root and filters record byte `2`, while `0x473240`
filters byte `1`. Mixed entries can change split topology and cached-leaf
history even if the support selector ignores type-2 records. Special and
alternate objects plus the full resource loader are separate boundaries.
For exact full-scene equality, replay a mixed-type tree and original
`0x499a70` inputs/outputs on one real track.

Cadence: `integration-cadence.md` proves `0x49b8e0` orientation callback is
registered to queue `[0x606acc]` and dispatched on each `0x414ff0` step,
guarded by car bytes `+0x7f/+0x7d`; its angular components are multiplied by
`1/64` turns per callback. The nominal 128 Hz timer/derived 64 Hz counters
do not prove a constant wall-clock callback frequency. Separately,
`0x49f160` adds `car+0xd38` times `1/32` or `1/48` into `+0x38c` depending
on `[car+0x558]+0x518`. Current rigid-body angular velocity is radians/s;
no exact conversion or timestep bridge to original `+0x38c` is established.

Concrete next original replay for full wheel integration: execute
`0x499a70` across one captured car/track wheel-state transition, including
`0x494480`, `0x499730`, material/owner flags and the later force updates;
compare input point, selected polygon and node cache, normal, plane Y,
extra height, and final wheel force/output. Until those match, keep the
unrecovered force law explicit in runtime diagnostics and iteration status.
