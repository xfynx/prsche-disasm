# 0M01 start pose: source fields and contact adjustment (2026-09-27)

Bounded read-only audit of `0x410430` and its immediate source/transform
consumers in `local/game/nfs5.exe`, SHA-256
`c318af393d4c2b7071a820ca3d69e956bbd94769b6e5c2e3e49f498ecbc94906`.
No runtime changes; local/game was only read.

**Confirmed:** the original starts pose setup by copying the Start trigger's
SCN position into the car translation, and uses the second vector on the
trigger's last numeric line as the initial forward vector. A later contact
solver can change XYZ, followed by a computed Y correction. Thus the SCN
center is now a proven input to original start placement, but an exact final
body height or final rendered pose is not recovered by simply using that center.

## Entry and exact source fields

The already-proven reset path selects the first trigger with p0==2 when
RACE_TYPE==4. At `0x4108b0–0x4108b2` it calls `0x410430(car, trigger)`;
the linked-arrow selection happens afterward at `0x4108c2`.

For TRIGGER_ELEMENT version 5:

- Position is read into object +0x08/+0x0c/+0x10 by the argument setup
  `0x46e520–0x46e532`.
- The 3x3 SCN rotation is read separately into +0x14..+0x34 at
  `0x46e537–0x46e561`.
- The last numeric line uses format string `0x5cfd34`,
  `%d %f %f %f\t%d %f %f %f`, at `0x46e658–0x46e65e`.
  Its first integer/vector map to +0xe4 and +0xbc/+0xc0/+0xc4;
  its second integer/vector map to +0xe8 and +0xc8/+0xcc/+0xd0.

At `0x410442`, getter `0x46f0f0` copies exactly +0xc8/+0xcc/+0xd0
into a temporary vector. It does not check the accompanying +0xe8 integer,
nor rotate the vector through the SCN matrix.

At `0x410460`, virtual slot +0x38 resolves to `0x46be40`: the trigger's
constructor installs vtable `0x5b4554` at `0x46dbf9`, and that table's
slot +0x38 contains `0x46be40`. This getter copies object +8/+0xc/+0x10.
Instructions `0x410471`, `0x41047a`, and `0x410483` copy those three floats
directly into car +0x330/+0x334/+0x338.

The supplied 0M01 Start therefore contributes:

```text
position  = (-6.844955, 0.000000, 147.240662)  // source coordinates
direction = ( 0.000000, 0.000000, -1.000000)  // second last-line vector
last line = 0 0 0 0    2 0 0 -1
```

The initial getter path does not use the gate endpoints, gate depth/width,
the first last-line vector, or the SCN rotation matrix to offset or orient
this car. In particular there is no direct fixed forward/backward offset
between the position getter and its copy into the car.

## Orientation basis and support query

After copying position, `0x410486` and `0x41049a` call `0x473210(1)`
for the car's support-query state and four wheel-query states. Then
`0x4104a9` calls `0x49af70(car)`.

`0x49af70` is conditional: byte car+0x7f must be nonzero, +0x7d zero,
and +0x7c nonzero (`0x49af75–0x49af90`). On that branch it passes the
car translation to `0x474440` and `0x474060`; if car+0x11 is nonzero,
`0x49afc4` calls `0x499520`. The latter can refresh car+0x3e8 from
the support query's vector returned by `0x474420` (`0x499651–0x49966d`).
The query obtains that vector via the selected surface object's virtual
method +0x14 (`0x474342–0x474343`). This links the up-basis input to
surface-query state, rather than to the SCN rotation. Not all branch-state
initialization and surface implementations are recovered here.

Back in `0x410430`, the code:

1. Copies the source direction to car+0x37c at `0x4104c4–0x4104d4`.
2. Copies car+0x3e8 to car+0x370 at `0x4104dd–0x4104ee`.
3. Calls `0x532880(up, direction, right)` at `0x4104f1`, writing +0x364.
4. Calls `0x532880(right, up, direction)` at `0x4104f9`, rewriting +0x37c.
5. Calls matrix correction `0x4a4810` at `0x4104ff` on the nine floats
   starting at +0x364; copies the result to +0x3b8 and +0x490.

The cross-product wrapper `0x532880` calls `0x56e8f5`, whose direct
arithmetic proves output = first_vector cross second_vector. Matrix correction
`0x4a4810` performs four iterations (`0x4a4821`, `0x4a4a1a–0x4a4a1b`),
using transpose/product operations, identity at `0x5d1068`, and a polynomial
coefficient table at `0x5d1040`. Its precise normalization algorithm was not
reimplemented during this audit.

With an up vector (0,1,0), the 0M01 basis before matrix correction is
right=(-1,0,0), up=(0,1,0), forward=(0,0,-1). This is a conditional numeric
example, not a recovered value of the actual support normal on the original
first frame. The reconstruction's existing Z reflection maps the source
forward to (0,0,+1).

## Final placement is contact dependent

`0x41052a` calls `0x49ab60`, which calls `0x49ae30` to transform the car's
local points into world coordinates. In `0x49ae30`, dot products with the
orientation are added to +0x330/+0x334/+0x338 (`0x49ae66–0x49aea6`).
This independently confirms that +0x330 is the car translation, not just
an unused staging marker.

`0x410535` next calls `0x499a70(car, output_vector)`. This is a substantial
contact/placement routine, not a pure scalar getter:

- It starts from four transformed points at car+0x1dc, incorporates a
  vehicle parameter at [car+0x760]+0x120 and basis component car+0x374
  (`0x499adf–0x499b13`), then performs four surface queries.
- `0x49a873–0x49a8a4` writes **all three translation components**, adding
  computed corrections multiplied by float 0.03125 at `0x5b24b8`.
- It regenerates transformed points at `0x49a8ca`, then calls `0x49a900`
  at `0x49a8dd`.
- `0x49a900` computes point/plane dot products, selects ordered minima,
  and stores a scalar into car+0x424 at either `0x49aa4c` or `0x49ab41`.
  Which formula is used depends on car state; the complete physical meaning
  of the branch conditions and the returned scalar remains unproven.

The caller then stores the routine's float return into +0x41c and executes:

```c
car.position.y -= car.field424;  // 0x410540..0x41055f
car.field424 = 0;                // 0x410551
for (wheel : four_wheels) {
    wheel.field64 = 0;           // effective car+0x820, stride 0xc4
    wheel.field6c = 0;
    wheel.field80 = 0;
}
```

These writes prove a computed vertical correction, not a fixed ride-height
constant or a displacement along the source direction. The full contact
routine was followed only far enough to establish its inputs and side effects;
no exact numerical original post-reset height is claimed.

## Recovered setup pseudocode and implementation boundary

```c
setup_start_pose(car, trigger) {
    direction = trigger.vector_at_c8; // SCN last line, second vector
    car.position = trigger.position; // direct source center
    reset_support_queries(car);
    refresh_support_state_if_enabled(car); // 0x49af70
    car.forward = direction;
    car.up = car.vector_at_3e8;
    car.right = cross(car.up, car.forward);
    car.forward = cross(car.right, car.up);
    correct_matrix(car.basis);           // 0x4a4810
    copy_basis_to_secondary_states(car);
    transform_local_points(car);          // 0x49ab60 -> 0x49ae30
    car.field41c = resolve_contacts_and_adjust_xyz(car, &temporary_vector);
    car.position.y -= car.field424;
    car.field424 = 0;
    clear_three_fields_per_wheel(car);
}
```

The current parser already preserves the source position and correct second
vector, and track_loader uses them. This audit supports that source anchor
and heading. It does **not** establish equivalence of the reconstruction's
static support projection/rest-height calculation to the original contact
routine. Do not introduce an arbitrary longitudinal offset or copy the SCN
rotation as the car orientation to fix a camera view.

Chase-camera position, body/model origin alignment, exact support triangle,
wheel/vehicle parameters, and the numeric final start pose still require
separate evidence or original telemetry/capture. No camera code was audited.

## Verification and next narrow step

Direct local Capstone x86/32 disassembly, code offset = VA - 0x400000.
Check `0x410430..0x41057f`, `0x46f0f0..0x46f10e`, vtable entry
`0x5b458c`, `0x46be40..0x46be5b`, `0x46e520..0x46e65e`,
`0x56e8f5..0x56e939`, `0x49ae30..0x49aeba`, and
`0x49a81f..0x49a8f3`. For `0x499a70`, follow branch targets rather than
blindly linearly decoding through embedded data; the return is `0x49a8f3`.

Next: obtain original post-reset translation/basis/contact telemetry for
0M01 or recover the selected support plane and vehicle-point inputs of
`0x499a70`. Until then retain the proven center/direction inputs and label
the final contact/height calculation as reconstructed.
