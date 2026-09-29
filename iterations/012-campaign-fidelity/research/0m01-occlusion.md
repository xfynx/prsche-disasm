# 0M01 camera occlusion: resource identification (2026-09-26)

Read-only resource/code audit of Run 002 `web-factory-mission-drive.png`.
The follow-up below proves v4 scale percentages, now applied by the loader.
Camera/spawn and initial arrow activation are separate unresolved questions.
See [metadata follow-up](0m01-arrow-activation.md) for the recovered animdefs
triggerable flag and initial hiding path; runtime selection is not implemented yet.

## Identified object and placement

- `local/game/GameData/Track/skidpad_st1.scn:100–104`: final GEOM_ELEMENT,
  label `L A`, first parameter 1, FourCC integer 827806273 = little-endian `ARW1`.
  Source position `(-7.330852, 0, 150.211655)`; diagonal rotation
  `(0.999937, 0.999968, 0.999968)`. Remaining parameters are `0 0 -1 1 1 100`.
- It resolves to zero-based article **207**, Name `arrow`, in `skidpad.crp`.
  CRP SHA-256: `2e0ddaf3c0963ba93b9770a40519a4133e87906c5d2fce73fed8e8615a9cfa70`.
  FourCC is Base:0 +0x44. Decoded `vt:0` is at 0x5d620, 224 bytes / 14 vertices.
- Source local bounds: X `[-7.984290123, 7.986387253]`, Y `[0, 25.922691345]`,
  Z `[-0.000048, 0]`. These large dimensions exist in the source vertices;
  the SCN rotation is almost identity and does not enlarge them.
- Current renderer world bounds: X `[-15.314639113, 0.655032110]`,
  Y `[0, 25.921861819]`, Z `[-150.211655, -150.211607002]`.
  `pr:0` has 5 triangles, material 87 / texture `aro1` / `FullAmbMatState`;
  `pr:1` has 14 triangles, material 88 / texture `arob` / `NormMatState`.
  The large arrow silhouette and its placement identify the screenshot occluder.
- Article `tr:0` is identity plus translation
  `(0.001049, 12.961345673, -0.000024)`, not a small scale.
  Library-prop loading currently ignores this matrix. Applying it without recovering
  original local/pivot semantics would be another unproven change.

## Why the current camera is occluded

The current Start-based spawn is `(-6.844955, 0, -147.240662)`, facing +Z.
`porsche-viewer/src/arcade.rs:137–138` puts the initial chase eye 5.8 m behind
and 2 m above, with target 1.5 m ahead and 0.9 m above. The `L A` arrow is
2.970993 m behind Start, between this eye and the car. At the unraised reset
pose, eye = `(-6.844955, 2, -153.040662)` and target =
`(-6.844955, 0.9, -145.740662)`.

Numeric ray/triangle check: the eye-to-target ray intersects the arrow plane
2.829007 m ahead in Z, at local XY `(0.485927613, 1.573761634)`.
This is inside `pr:1` triangle 4 (zero-based), vertex IDs `[8,13,0]`,
barycentrics `(0.075393743, 0.312192157, 0.612414099)`.
This calculation uses the code's reset pose, not telemetry of the exact screenshot
frame; subsequent body settling/camera interpolation may move the ray.

## Confirmed implementation boundary

- `nfs-formats/src/scn.rs:150–166` preserves only the first two GEOM parameters
  (`flags`, FourCC); six remaining parameters are discarded.
- `nfs-assets/src/track_loader.rs:255–298` takes library-prop vertices without
  article `tr`; `:544–555` instantiates every matched GEOM without consulting
  its first parameter or remaining parameters.
- `porsche-viewer/src/renderer.rs:606–632` applies SCN rotation/translation;
  `:1254` draws every prop instance. This proves the current geometry path,
  not the original meaning of special arrow flags, scale, visibility, or staging.

## Exact next executable consumer

Audited `local/game/nfs5.exe` SHA-256:
`c318af393d4c2b7071a820ca3d69e956bbd94769b6e5c2e3e49f498ecbc94906`.

- `GEOM_ELEMENT` string VA `0x005cfb1c`, referenced by scene dispatch at
  `0x0046c32d`. Matching branch allocates 0xc4 bytes at `0x0046c35f`,
  calls constructor `0x0046a0d0` at `0x0046c372`, then invokes object
  vtable slot +4 at `0x0046c388` with the source stream and zero argument.
- Constructor installs vtable `0x005b4280` at `0x0046a0e1`.
  Slot +4 resolves to **`0x0046a2b0`**; this function checks its second argument
  against 1 at `0x0046a2be`. The dispatch supplies zero, selecting the read path
  at `0x0046a3dc`. Follow that branch to decode all GEOM parameters, then trace the field holding
  first parameter 1 and FourCC ARW1 into arrow placement/rendering.
- The other `GEOM_ELEMENT` xref at `0x0046a2cc` feeds formatting/output
  (`0x005a25f0`) inside the same serializer, not its read branch.
- `TRIGGER_ELEMENT` dispatch comparison begins `0x0046c3b3`, string
  `0x005cfb84`; trace its allocated object's parser and the Start consumer
  before changing spawn. Exact original car offset/chase-camera placement
  remains unproven.

Two hypotheses examined: (1) wrong object/placement: identified ARW1 `L A`
with a numeric occlusion; (2) accidental SCN scale enlargement: excluded,
because the source vertices are already large and the placement is unit scale.
Whether the original applies special arrow scaling/visibility or a different
spawn/camera requires the executable consumer above. No arbitrary offset or
geometry suppression was applied.

## Follow-up: GEOM parameters and trigger-controlled arrows

The reader's version switch at `0x46a402`, table `0x46a80c`, dispatches
versions 1..5 to `0x46a409`, `0x46a48c`, `0x46a524`, `0x46a5c0`,
`0x46a692`, respectively. `GEOM_ELEMENT 4` therefore means format version 4.

For version 4, the eight parameters map as follows (zero-based indexes):

- p0 -> object +0x78: category/type, later read as signed 16-bit by `0x46af40`.
  Value 1 gates trigger-controlled instance selection at `0x470415` / `0x470c9d`.
- p1 -> +0x7c: FourCC, getter `0x46af50`.
- p2 -> +0x80, p3 -> +0x84: preserved integer fields; behavioral meaning
  **not established** in this bounded audit. Constructor defaults both to zero.
- p4 -> +0x88: later copied as signed-width word (clone at `0x46a8b5`),
  constructor default -1. Behavioral meaning **not established**.
- p5 -> +0x8c, p6 -> +0x90: both constructor defaults 1. They gate transform
  manipulation: `0x46a9f2` requires p5==1 before projected position update;
  `0x46aa47` additionally requires p6==1 before orientation update;
  `0x46ab50–62` requires both before an alternate rotation path.
  Calling them runtime visibility flags would be unsupported; these callers
  appear to be editing/manipulation machinery, whose activation is not traced.
- p7 -> uniform **scale percentage**. `%d` parsing at `0x46a63f` writes a
  stack integer, then `0x46a644` explicitly sign-extends its low 16 bits;
  `fild` converts that to float and stores XYZ at +0x94/+0x98/+0x9c.
  `0x46a7b6/0x46a7cb/0x46a7db` multiply by float 0.01 at `0x005b3ca0`;
  the resulting diagonal matrix combines with source rotation via `0x532470`
  and is stored at +0xa0. `0x46d238` retrieves that matrix via `0x46b020`
  before instance insertion `0x483260` -> `0x482ea0`.

Recovered pseudocode (field names deliberately neutral where semantics unknown):

```c
// version 4, 0x46a5c0..0x46a7e9
scan_position_and_rotation(file, obj + 8, obj + 0x14);
scan_8_ints(file, &p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7);
obj.type = (int16_t)p0; obj.fourcc = p1;
obj.field80=p2; obj.field84=p3; obj.field88=(int16_t)p4;
obj.field8c=p5; obj.field90=p6;
obj.scale_percent = float3((float)(int16_t)p7);
obj.instance_matrix = combine_rotation_and_diagonal_scale(
    obj.rotation, obj.scale_percent * 0.01f);
```

Version 5 uses seven integers plus three floats (`0x005cfa74` format string)
for separate XYZ scale percentages. Versions 1/2 read six integers beginning
at +0x7c; version 3 reads seven beginning at +0x78. They retain constructor
scale defaults of 100. Thus applying v4's last-field rule to every version
would be wrong.

For this SCN, arrow percentages are 41, 49, 55, 42, and **100 for L A**.
Missing scale is a proven bug for the other arrows, but applying it does
**not** shrink the screenshot occluder. No invented 0.1 scale is supported.

### Actual category-1 selection path

`0x4703d0` reads trigger signed-word field +0xde and uses it as an index
into the scenario element vector (`0x46d9b0`). It runtime-casts the referenced
element to the geometry type, requires its category getter `0x46af40` to
return 1, then supplies FourCC, position, and rotation to `0x483290` ->
`0x482f70`. `0x470c98` reaches the same type-1 branch during trigger processing.

The version-5 trigger parser's argument list at `0x46e584–0x46e5e3` maps
parameter p12 to +0xde. In `skidpad_st1.scn`, Start has p12=13; the ordered
scenario's element 13 is `Arrow 1`. Subsequent waypoint links are 14,15,16,
-1,17; element 17 is **L A**. These are geometry links, distinct from the
waypoint sequence index currently used by the reconstruction.

`0x482f70` performs two concrete operations on the render-instance array:

```c
for each instance with flag_byte_at_0x34 != 0:
    if (instance.y > 8000) instance.y -= 10000;
    if (instance.y <= 8000) instance.y += 10000;
for each instance:
    if (instance.x == requested.x && instance.z == requested.z &&
        instance.fourcc == requested_fourcc && instance.flag34 != 0 &&
        instance.y > 8000)
        instance.y -= 10000;
```

The exact threshold and displacement constants are floats 8000 at `0x5b47d8`
and 10000 at `0x5b2764`. This is direct evidence for selecting one linked
special instance by moving others high above the course. It is not a guess
based on the screenshot. The flag byte itself is copied from the resolved
article instance metadata at `0x482f1e–0x482f26`; its CRP source field and
the complete initial-activation order still need tracing before a full fix.

Bounded hypotheses: (1) missing scale is confirmed, but L A=100 excludes it
as the cause of this arrow's size; (2) drawing all category-1 arrows permanently
ignores a confirmed trigger selection mechanism. Initial active arrow / exact
spawn / camera remain to be recovered; p2/p3/p4 meanings remain unresolved.
