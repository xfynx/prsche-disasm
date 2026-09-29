# Scenario trigger predicate: bounded EXE findings

2026-09-28; read-only nfs5.exe audit, followed by Run 005 implementation.
EXE SHA-256 c318af393d4c2b7071a820ca3d69e956bbd94769b6e5c2e3e49f498ecbc94906.
Addresses are virtual, code file offset = VA - 0x400000.

## Progress dispatch and source fields

`0x4161c6..0x4161e9` finds the current trigger using car+0xb58 and
`0x46d2e0`, then calls predicate `0x4704e0`. Lookup uses getter `0x46edf0`
(signed word trigger+0xd4), not display names. The v5 parser argument list
at `0x46e569..0x46e5e3` maps this field to parameter 7.
On predicate success, type getter `0x46af50` selects:

- type 1: `0x4161fb..0x416226` calls trigger action, sets state+0xb50=2,
  copies timing globals into result fields; completion path.
- type 0: `0x41625c..0x41627b` increments current sequence, calls trigger
  action `0x470460`, then arrow selection `0x4703d0`.

State gates and the earlier shortcut at `0x416170..0x4161b9` have not been
fully interpreted. This is not proof of all win/fail conditions.

## Predicate 0x4704e0

1. Calls geometry predicate `0x4706c0`; false immediately rejects.
2. Vector trigger+0xc8 (second vector on final SCN line): zero bypasses
   this constraint; otherwise dot with car+0x37c must be strictly >0.5.
3. Vector trigger+0xbc (first vector): zero bypasses; otherwise dot with
   normalized car+0x33c must be strictly >0.5. If that car vector is zero,
   the predicate substitutes (0,1,0) before the dot.
4. Requires car scalar+0x35c+0.1 > trigger+0x90 and
   trigger+0x94+0.1 > car scalar+0x35c. SCN v5 p5/p6 map to these bounds.
   Producer subsequently traced below: max(|vx|,|vz|)+0.25*min(|vx|,|vz|).

`0x532910 -> 0x56e8d1` is a three-component dot product. Float constants:
0 at 0x5b23f8, 0.5 at 0x5b23f0, 0.1 at 0x5b2604.
`0x46e620..0x46e65e` proves final-line first/second vector mapping.
All 0M01 waypoint/End vectors are zero: inferring a travel direction from
successive centers adds a restriction absent from these source predicates.
That inferred restriction has now been removed from the runtime.

## Shape 1 geometry

`0x4706c8` switches on trigger+0x80 (v5 p1). Shape 1 copies source endpoints
from trigger+0xa4/+0xb0. It tests two pairs of current vehicle points:
car+0x7f8 to car+0xa44, then car+0x8bc to car+0x980. These are not previous
and current vehicle positions.

First-pair endpoint heights must be within the inclusive ±3.5 band of
trigger endpoint A.y (`0x4707b2..0x470810`, constant 0x5b38ec). The code
then zeroes Y for XZ intersection and calls `0x489cc0`. On failure it tests
the second pair without a new height test (`0x470852..0x470919`).

Bounded worker evidence recovered before its quota interruption:

- `0x489cc0` tests two finite XZ segments, both parameters inclusive [0,1];
  zero denominator returns false, including collinear segments.
- Writer `0x499946..0x499a4d` builds four current points. With car.position P,
  basis vectors U=car+0x370, F=car+0x37c, R=car+0x364:
  C=P-car.scalar(+0x3ac)*U, L=0.7*scalar(+0x3b0)*F,
  W=0.9*scalar(+0x3a8)*R. Points are C+L-W, C+L+W, C-L-W, C-L+W.
- car resource+0x518 activates sequential in-place pair expansion:
  starting endpoints A,B become (3A-2B, 2B-A). It is not a symmetric scale.
- `0x4450f0` virtual+0x10 returns bounds, `0x445104` subtracts them and
  `0x445122` multiplies by 0.5 into car+0x3a8 (three dimensions).
  `0x445140..0x44517c` additionally scales these by 0.4 when +0x518 is set.

Worker could not finish its artifact after a usage-limit error; preserve these
specific addresses/formulas as its delivered findings, not as executed port
tests. Before implementation inspect the bounding-resource getter and pair
expansion to establish the source units/model-origin contract. Current runtime
mesh scaling and SIM-derived dimensions are not proven substitutes.

## Next implementation boundary

Run 005 replaces point-sweep/rectangle/inferred-direction rules with the
recovered shape-1 predicate and explicit vehicle-point inputs. Type-based end
handling, zero-vector bypass and strict thresholds are used. CPU tests cover
both headings, stationary overlap, side miss, endpoint/collinear cases, height,
speed metric, asymmetric expansion and reset.

## Coordinator follow-up and remaining adapter boundary

`0x49be99..0x49bf02` reads velocity X from car+0x33c and Z from +0x344,
takes absolute values, selects the larger and adds the smaller times float
0.25 at 0x5b2468. Result is stored at car+0x35c. Same arithmetic appears at
`0x4a0316..0x4a0354`. No km/h conversion or signed forward projection appears
in this producer. Runtime uses its physics velocity components in this formula.

The coordinator rechecked the half-bounds calculation at `0x4450d5..0x445182`
and point builder `0x499946..0x499a4d`. The virtual bounds getter's chosen object
is still unresolved: flag 0x10 at car+0x52c selects object-list offsets 0 or 0x10.
It is therefore not yet proved equal to the aggregate visible-mesh bounds.

Current adapter explicitly uses the loaded rendered car bounds: asset loader
`mesh_position` divides raw vertices by five; driving render multiplies them
by five, so half-extents are `(scene.max-scene.min)*2.5`. Basis, position and
velocity come from the current sim body. This connects source-model geometry
to the predicate but **does not prove original selected-bounds/model-origin or
contact equivalence**. No generic hardcoded vehicle dimensions are substituted.
No model bounds means mission route configuration is unsupported. Resource
flag +0x518 is not recovered in the loader; normal player adapter uses false,
while the flagged predicate branch is tested independently.

Remaining next step: trace the bounds object's virtual+0x10 and its origin,
plus original contact/height correction; compare actual original telemetry.
Complete mission timing, penalties and reward eligibility remain separate.
