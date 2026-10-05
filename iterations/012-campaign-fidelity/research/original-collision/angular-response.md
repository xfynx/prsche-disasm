# Optional response and contact geometry

2026-10-05, Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Source: saved full indexed `vehicle-0x493f10.jsonl` / `vehicle-0x495020.jsonl`,
helper decoding in response-helpers.txt, plus the commands below for constants.

## Callback 0x493f10

Arguments: car, incoming scalar s, normal. Always clear car+0x434 at 0x493f1f.
If s >= 15 AND old car+0xd60 >= 20, return without changing car+0x38c.
Constants at 0x5b243c and 0x5b2470 are respectively float 15 and 20.
Otherwise:

```
a = dot(normal, car vector +0x4a8)
b = dot(normal, car vector +0x490)
m = 0.25 * min(abs(a), abs(b))
if a < 0:
    result = -m if b < 0 else m
else:
    result = 0.5 * (-m if b > 0 else m)
car+0x38c = result
```

This assignment replaces the previous value; it is not an added impulse.
The gate uses the old projection because the caller refreshes velocity/projections
only afterward. The independent [field-consumer trace](angular-field.md) proves
this is Y angular state, applied as field/64 turns per orientation update;
wall-clock cadence remains open. No torque interpretation is inferred here.
The original code uses scalar x87 intermediates and explicit float stores.

```
py -3 scripts/research/inspect-pe-range.py --binary Porsche.exe --address 0x5b243c --size 4 --words
py -3 scripts/research/inspect-pe-range.py --binary Porsche.exe --address 0x5b2470 --size 4 --words
```

The extended response replay executes 0x493f10 as part of 0x494000, with no stub.
468 inputs/outputs and the Rust regression are recorded in
[Run 012](../../runs/012-original-contact-kernel/README.md).
Finite synthetic inputs and 2e-6 tolerance establish a bounded match; full x87
80-bit equivalence, all live state invariants and complete physics are not claimed.

## Candidate points and signed edge normal

The replay also executes original 0x495020..0x495262 to extract eight candidate
points. Let p be car+0x330, R/U/F its vectors +0x364/+0x370/+0x37c, and w/h/l
its scalars +0x3a8/+0x3ac/+0x3b0. Observed construction, in order:

```
p - U*h + F*l - R*w
p - U*h + F*l + R*w
p - U*h - F*l - R*w
p - U*h - F*l + R*w
p + U*h + F*(l/2) - R*w
p + U*h + F*(l/2) + R*w
p + U*h - F*(l/2) - R*w
p + U*h - F*(l/2) + R*w
```

Actual operations round vector-helper results to float. The code separately
computes velocity * 0.03125, used by a later fallback query, not added to these
eight points. The physical provenance of w/h/l still needs its initialization.

After selecting endpoints A/B, execution of 0x49542d..0x4954f0 confirms:
delta = B-A; normal = normalize((-delta.z, 0, delta.x)). Zero normal is not
normalized. Its sign is not flipped toward the point or velocity in this region.
The point is projected onto the infinite XZ line by 0x489f10 (no parameter clamp);
displacement X/Z = (projection - point) * float(1.01), Y = 0. The separate
0x494000 preparation can suppress correction, or multiply it by float(1.05).
Reversing endpoints reverses normal but retains projected displacement.

Three basis orientations and twelve nondegenerate edge/point combinations,
including points beyond endpoints and reversed edges, match original instructions.
Degenerate edges and live scene selection are outside these fixtures.

## Remaining selection contract

Static trace at 0x49527a..0x4952d9: for a point with a type-1 support whose state
has a nonzero low nibble, compute plane Y at the point XZ. If its absolute
difference from car position Y is <= float 4 (0x5b2404), skip this candidate.
Otherwise query support at car position; if it fails this same test, retry at
car position minus velocity*0.03125. Then type-2 edge intersection query runs.
The support object helpers return plane point/normal; loader/material validity
and live alternate levels still require end-to-end fixtures. Do not replace this
with a nearest-edge test or discard endpoint order when integrating.
