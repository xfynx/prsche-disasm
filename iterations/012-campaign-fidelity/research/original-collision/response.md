# Vehicle response: source and executable check

2026-10-05. `Porsche.exe`, SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Addresses below belong to this module only. Full indexed instructions are in
`vehicle-0x494000.jsonl`, `vehicle-0x493e40.jsonl`, `vehicle-0x493dd0.jsonl`,
`vehicle-0x493f10.jsonl`, `vehicle-0x495020.jsonl`, `vehicle-0x4980d0.jsonl`.
Helper raw decodes and constants: [response-helpers.txt](response-helpers.txt).

The [query trace](contact-query.md) now connects loaded EDG objects to
`0x495020 -> 0x494000`. This closes the loader-to-vehicle gap; it does not yet
establish every rejection condition or all caller contracts.

## Confirmed response

`0x494000(car, normal, point, displacement, angular_flag)` copies 48 bytes of
query state from car+8. This is not a demonstrated transform matrix: its +0x28
is a cached geometry pointer, used by `0x474060`. Before response it queries
`point + displacement`; a zero low nibble of the resulting state word suppresses
position correction. Otherwise it copies displacement, then scales it by 1.05.
`0x532b20` returns vector length and does **not** normalize or modify its input;
this call's return is discarded. Normalization is a different helper, `0x5328d0`.

At `0x4940ae`, with the correction already prepared:

- `s = -dot(velocity, normal)` via `0x532910 -> 0x56e8d1`.
  If `s <= 0`, return zero without applying correction or state refresh.
- `0x4941f0..0x494234`: add `normal * (s * 1.1)` to velocity at car+0x33c.
  Factor 1.1 is the original float at `0x5b27a4`, not a fitted coefficient.
- `0x494289..0x494339`: add prepared correction to car position +0x330,
  and only its X/Z components to four point groups at +0x7f8 with stride 0xc4.
- If angular_flag is nonzero, call `0x493f10`, which can change car+0x38c.
  Its physical field binding remains open; the replay below disables this call.
- Always call `0x493e40` on the positive-s branch: multiply velocity by the
  immediate float `0x3f7f7cee` (~0.998), recompute projections on three car vectors
  and speed estimate `max(abs(vx),abs(vz)) + 0.25*min(abs(vx),abs(vz))`.
  Car byte +0x52c bit 4 additionally calls `0x493dd0`, replacing two projections
  and clearing six fields. This is verified without assigning a gameplay name
  to that mode.
- Returned magnitude is **not always 3*s**. Before velocity changes, if old
  car+0x35c times 0.125 is greater than s, it uses old speed times the float at
  `0x5b49b0` (~1/12); otherwise s. Return is absolute value of that value times 3.
  Both branches also select car+0x438 codes using global `0x628c88`; code meanings
  and complete mapping remain unverified.

Vector helpers confirmed from scalar x87 bytes: `0x532300` adds input vectors
through `0x56e660`; `0x532330` subtracts second from first through `0x56e6aa`;
`0x532360` scales XYZ; `0x532910` dots XYZ. The internal assembly helpers advance
EAX for their wrapper's array iteration. `0x516950` is a single `ret`.

`0x4980d0` invokes pair predicates/response `0x497b10` / `0x496860`, then
`0x495020` and `0x498de0` for both objects, with a bounded retry loop.
Those pair and secondary response functions still need their own contracts.

## Executable differential probe

```
py -3 -m pip install --target local/tools/python-unicorn unicorn==2.1.3 --index-url https://pypi.org/simple --disable-pip-version-check
py -3 scripts/research/replay-contact-response.py --output iterations/012-campaign-fidelity/runs/011-original-physics-audit/response-replay.json
```

64 cases passed against original instructions in Unicorn 2.1.3: head-on,
departing, stationary, tangent, glancing, 27 seeded oblique inputs, each with
both values of the alternate-state bit. Inputs, original outputs and module hash
are recorded in [response-replay.json](../../runs/011-original-physics-audit/response-replay.json).
Compared: velocity, position, projections, speed, returned magnitude, four point
groups and six reset fields. Tolerance: absolute/relative 2e-6.

The harness loads the hash-checked PE sections at their original addresses and
executes the original bytes from `0x4940ae` through their real callees and return.
There are no patched instructions or substituted calls. An instruction-address
guard and 10,000-instruction limit fail on unexpected execution. Only the return
capture trampoline is harness code. Geometry/correction and car state are
synthetic inputs; the angular callback is disabled. Surface-code selection runs
but its output is not included in the differential assertions.

This proves the bounded response formula against an x86 emulator, not native
hardware rounding, full contact generation, complete physics or driving fidelity.
It does not update the gameplay build. Next: recover angular callback +0x38c
binding, caller normal orientation/acceptance, then extend the original-code
replay before integrating the complete contact path.
