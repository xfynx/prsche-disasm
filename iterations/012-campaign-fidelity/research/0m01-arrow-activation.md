# 0M01 arrow metadata and initial hiding (2026-09-27)

Bounded read-only follow-up to `0m01-occlusion.md`. No runtime code changed.
The source of render-instance byte +0x34 is **animdefs.txt `triggerable`**,
not a CRP flag and not SCN geometry category 1. Initial scenario construction
explicitly hides all instances with this byte set. The reset path then selects
the first type-2 trigger's linked geometry when `RACE_TYPE == 4`; for 0M01
this is Arrow 1. The frontend assignment of that mode and the actual first
displayed frame have not been traced or captured.

## Inputs

- `local/game/nfs5.exe`, SHA-256
  `c318af393d4c2b7071a820ca3d69e956bbd94769b6e5c2e3e49f498ecbc94906`.
- `local/game/GameData/Track/animdefs.txt`, SHA-256
  `8fc17129cadd103ecb2e69484ffc040bee89f35afe64b1c7819a4778106f3ef4`.
- `animdefs.txt:492–497`: `SECTION:ANIM { tag=ARW1; collideType=0;
  triggerable=1; }`. ARW2, ARW3 and ARW4 also have `triggerable=1`
  at lines 504, 512 and 520. The file's own header states that these are
  property definitions for all tagged objects, not just animations.

## Proven metadata chain

1. `0x487833` pushes string VA `0x5d05ec`, `animdefs.txt`; `0x487839`
   pushes `%s%s` for the path formatter. `0x487847` creates the global
   definitions object, `0x48784c` loads it from `0x628ba0`, and `0x48785a`
   calls file loader `0x47eba0`.
2. Its `section:anim` dispatch reaches `0x47dcf0` via `0x47ecfc`.
   Definition records are 0x8c bytes. Constructor `0x47dd73` initializes
   byte +0x15 to zero.
3. At `0x47e69e` the parser retrieves that record; `0x47e6a9` adds 0x15;
   `0x47e6ae` pushes string VA `0x5d0288`, `triggerable`; `0x47e6b3`
   invokes `0x47d280`. That helper parses the integer and at
   `0x47d308–0x47d311` stores `parsed_integer != 0` into the supplied byte.
4. The CRP library builder `0x482970` reads Base payload +0x44 at
   `0x482bee` into library metadata +0x30 (the FourCC). At `0x482c2b`
   it loads that FourCC; `0x482c36` calls `0x47ed90` on definitions global
   `0x628ba0`. That function compares the requested tag to each record's
   first dword (`0x47edb6`). If no match exists it returns the first record
   (`0x47edcc–0x47edd4`); null definitions or zero requested tag return null.
5. If the lookup returns a record, `0x482c42` reads byte +0x15 and
   `0x482c45` stores it into library metadata +0x34. Library metadata stride
   is 0x38. Instance insertion `0x482ea0` copies library metadata +0x34
   to render-instance +0x34 at `0x482f1e–0x482f26`.

```c
definition.triggerable = parse_int("triggerable") != 0; // default false
library.tag = crp_base.tag_at_44;
definition = definitions.find_tag_or_first(library.tag);
if (definition) library.flag34 = definition.triggerable;
instance.flag34 = library.flag34;
```

Therefore a runtime reconstruction must distinguish the SCN category that
permits trigger selection from the animation-definition property that makes
an instance participate in the selection/hiding loop. They are separate
inputs, even though all arrows in this scenario satisfy both conditions.

## Proven construction order

The scenario geometry loop calls `0x483260` at `0x46d257` for each resolved
GEOM. After the loop, if at least one was processed, `0x46d274` pushes zero
and `0x46d276` calls `0x4832b0`.

`0x4832b0` calls an object virtual method and `0x482dd0`, then tests its
boolean argument. With the observed zero argument, `0x4832d5` calls
`0x483070`. Its loop `0x4830ae–0x48311e` traverses the render-instance
array at object +0x40, count +0x18, stride 0x38. For each flag34 != 0 it
performs the same height normalization used by the selection function:

```c
// Source world coordinates, finite ordinary course heights.
for (instance : render_instances) {
    if (!instance.flag34) continue;
    if (instance.y > 8000.0f) instance.y -= 10000.0f;
    if (instance.y <= 8000.0f) instance.y += 10000.0f;
}
```

Threshold and displacement are float constants at `0x5b47d8` and
`0x5b2764`. At the source arrows' y=0 this puts every arrow at y=10000.
This is executable evidence for initial hiding during construction, not
evidence that the first displayed driving frame has no active arrow.

`0x482f70`, previously documented in `0m01-occlusion.md`, first applies
the same hiding pass, then lowers any flagged instance matching the requested
X, Z and FourCC. It does not select by SCN element index directly; the trigger
consumer resolves the index to the requested geometry first. Multiple exact
matches could be lowered; uniqueness must not be assumed for arbitrary SCNs.

## Initial-selection follow-up: reset state proven

### Trigger type and negative-link behavior

In the version-5 TRIGGER reader, `0x46e5d8–0x46e5dc` pushes destination
object +0x7c as the first conversion target, then `0x46e5e3` invokes the
scanner. Thus **trigger p0 is the dword at +0x7c**. Getter `0x46af50`
returns precisely that dword (`0x46af50–0x46af53`). `0x46d290` scans its
trigger collection and returns the first whose getter matches the requested
value; `0x410899` passes 2. In `skidpad_st1.scn`, this is Start, whose p0=2
and p12=13 links the zero-based scene element Arrow 1.

Do not confuse this trigger field with geometry p0/category at +0x78.
The shared getter +0x7c means a trigger type for a trigger, and a FourCC
for a geometry object.

`0x4703d0` reads link as **signed 16-bit** at `0x4703d8`. A negative link
branches directly to return (`0x4703e2 -> 0x470452`) **before any hiding**.
A failed geometry runtime cast (`0x47040a–0x47040c`) or category != 1
(`0x470415–0x470418`) also returns without changing visibility. Therefore
an unlinked waypoint must preserve the previously selected arrow, not hide it.
Only a valid category-1 geometry link reaches the hiding/selection routine.

### Mode identity and scene loading

Global `0x6573ec` is named **RACE_TYPE** by the executable's configuration
table entry at `0x5d1ee8`: `{ 0x10, 0x6573ec, 0x5d3b68 }`, with the
last pointer naming string `RACE_TYPE`. This is distinct from FEGAME_TYPE
at `0x6573e8` (table token 0x30).

`0x4877eb–0x487804` checks RACE_TYPE==4 and invokes scenario loader
`0x46d330` with global `0x657c80`. The latter is named **SCENENUMBER**
by table entry `0x5d1f78` (token 0x1c, string `0x5d3ae4`). Other race
types take `0x46d600` instead. The corresponding reset gate at `0x4108a7`
checks that same RACE_TYPE==4 before using the Start trigger.

The config interpreter `0x4b4b80` resolves tokens through table `0x5d1e40`;
its scalar store is `0x4b4cc2–0x4b4cc5`. This accounts for the absence of
a direct `mov [0x6573ec],4` instruction. The Factory frontend producer of
the token/value pair was not located in this bounded audit. Two limited
approaches (direct global writers and static token/value pairs) did not
prove that producer, so that branch was stopped.

### Reset execution order

The following are consecutive calls in the reset path:

```text
0x4b6daf -> 0x471b60 -> 0x487e20
                          0x487e6e -> 0x482e50  hide flagged instances
0x4b6db4 -> 0x414eb0
              0x414f12 -> 0x4110a0  iterate initialized car objects
                  0x4110d7 / 0x41110b -> 0x410730
                      0x410899 -> 0x46d290(2)  first trigger p0 == 2
                      0x4108a7: require RACE_TYPE == 4
                      0x4108b2 -> 0x410430  start-pose setup
                      0x4108c2 -> 0x4703d0  select linked category-1 geom
```

`0x482e50` raises each flagged instance with y<=8000 by 10000, leaving
already-hidden instances high. Unlike the full normalize/hide loop, it
does not first subtract 10000. The later selector's normalization then
restores the requested matching instance to its course height.

For a successful reset with at least one initialized car, RACE_TYPE==4,
and the supplied 0M01 SCN, this proves the post-reset active target is
**Arrow 1, element 13**, while L A stays hidden. The selection occurs inside
initialization/reset, before any player movement or waypoint crossing is
required. Initial scene construction also hides the arrows independently
via `0x487884 -> 0x4879d0 -> 0x487abd -> 0x46d1d0`, as detailed above.

The exact first display callback and Factory frontend's mode assignment
remain outside this proof. This result supports the explicit scenario-reset
sequence under the identified conditions, not a claim of captured original
pixels or complete mission-rule fidelity.

### Later selector boundary

Two direct call sites for the trigger-linked selector `0x4703d0` were found:

- `0x4108c2`: after `0x46d290(2)` returns an element and global `0x6573ec`
  equals 4, the caller invokes `0x410430`, writes state +0xb58=1, then
  calls `0x4703d0` for that element. `0x46d290` matches getter `0x46af50`
  against its argument; it does not simply choose element index 2.
- `0x41627b`: a later path requires getter `0x46af50` to return zero,
  increments state +0xb58, calls `0x470460`, then `0x4703d0`.

The second call's full runtime conditions and the separate trigger-processing
selector at `0x470c98` still require an event-flow audit before claiming the
original waypoint progression has been reproduced. Spawn and chase-camera
semantics remain a separate task; observing the start-pose setup call does
not by itself prove an exact render/body pose in reconstructed coordinates.

## Reproduction and next step

Disassembled directly with local Python `capstone`, x86/32 mode, using
`VA - 0x400000` as the file offset in this EXE's code section. Recheck the
exact ranges `0x47e69e..0x47e6c3`, `0x482bc2..0x482c49`,
`0x46d200..0x46d281`, `0x4832b0..0x4832db`, and
`0x483070..0x483122`; source text is independently readable with
`rg -n -i 'triggerable|ARW[1-4]' local/game/GameData/Track/animdefs.txt`.

Additional ranges for the follow-up: `0x46e569..0x46e5e8`,
`0x46af40..0x46af54`, `0x46d290..0x46d2d4`, `0x4703d0..0x470456`,
`0x487e20..0x487e76`, `0x4b6da5..0x4b6dbe`, and
`0x414eb0..0x414f26`. Config table entries are raw little-endian dwords.

Next narrow audit: frontend production of RACE_TYPE=4/SCENENUMBER=1 for
0M01, or original startup capture; then trace later waypoint event dispatch.
No arbitrary scale or spawn offset is justified by this visibility evidence.
