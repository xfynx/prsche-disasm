# Current project status

Updated 2026-11-24. Active work: [v2 / 001-original-recovery](iterations/v2/001-original-recovery/PLAN.md).

## Recovered C/C++ game

[Run812](iterations/v2/001-original-recovery/runs/812-scene-table-load-integration/README.md)
compiles 468 TUs across eight projects (**78 unresolved names / 88
references**, no EXE), accepting Run810/003: `1,338` registry entries (`+6`),
`78` comparisons, `10` mutations, `0B` data/bss, `1,155` source pins; closes
`0044d270`, opens `0059f8f0`/`0044d380`/`005af040`.
Deferred proof-only: [Run807](iterations/v2/001-original-recovery/runs/807-render-color-pack/README.md) (`004/receipt.json` PASS; awaiting caller `00563160`/`005dec08`).

Historical: [Run809](iterations/v2/001-original-recovery/runs/809-scene-reset-and-input-caps-integration/README.md),
[Run808](iterations/v2/001-original-recovery/runs/808-scene-texture-and-render-query-integration/README.md)
& [Run804](iterations/v2/001-original-recovery/runs/804-render-mode-and-sim-startup-integration/README.md)
compiles 463 TUs across eight projects (**79 unresolved names / 89
references**, no EXE), accepting Runs797/798: `1,325` registry entries (`+14`),
`264` comparisons, `21` mutations, `8B .data` (`797`) + `175B` literals (`202B`
PE span) + `14B .bss` (`798`), `1,142` source pins. Two names close (`00538b30`,
`004affd0`) with zero new unresolved names.

Historical: [Run800](iterations/v2/001-original-recovery/runs/800-scene-route-and-texture-integration/README.md)
compiles 461 TUs across eight projects (**81 unresolved names / 91
references**, no EXE), accepting Runs795/799: `1,311` registry entries (`+4`),
`150` comparisons, `20` mutations, `276B .bss` (`795`) + `160B .data` (`799`),
`1,137` source pins. Two names close (`00475c80`, `0044d7e0`) and one opens
(`005557d0`).

Historical: [Run796](iterations/v2/001-original-recovery/runs/796-render-font-and-sim-queue-teardown-integration/README.md)
compiles 459 TUs across eight projects (**82 unresolved names / 92
references**, no EXE), accepting Runs793/794: `1,307` registry entries (`+12`),
`272` comparisons, `24` mutations, `264B` read-only data + `41B .bss`, `1,132`
source pins. Three names close (`0053c6c0`, `004afd30`, `004afe50`) with zero
new unresolved names.

Historical: [Run792](iterations/v2/001-original-recovery/runs/792-scene-render-sim-integration/README.md)
compiles 457 TUs across eight projects (**85 unresolved names / 94
references**, no EXE), accepting Runs786/789/790/791: `1,295` registry entries
(`+21`), `216` comparisons, `41` mutations, `2,148B .bss` (`786`+`790`) + `64B
.data` (`791`), `1,127` source pins. Three names close (`00452120`, `00594980`,
`004a8570`) and one opens (`0044d7e0`).

Historical: [Run788](iterations/v2/001-original-recovery/runs/788-scene-render-sim-integration/README.md)
build compiles 453 C++ translation units across eight projects. The shared
link reports **87 unresolved names / 96 references**. There is no game EXE.
The shared audit accepts Runs781/782/785/787 within their bounded domains:
12 new registry entries (`1,274` total), 228 original-x86 comparisons, 38
mutations, 25B `.bss` (`782`) + 4B `.rdata` `005bb708` + 7,093B `FNTF` font
payload `005dfd8c` (`787`), and 1,118 source pins. Four names close (`004522b0`,
`00536870`, `0053c8e0`, `004642f0`) and five typed boundaries open (`00452120`,
`0053c6c0`, `00594980`, `005dfb60`, `005dec08`).

Historical: [Run784](iterations/v2/001-original-recovery/runs/784-audio-voice-and-sim-teardown-integration/README.md)
build compiles 449 C++ translation units across eight projects. The shared
link reports **86 unresolved names / 94 references**. There is no game EXE.
The shared audit accepts Runs777/783 within their bounded domains: 7 new
registry entries (`1,262` total), 84 original-x86 comparisons, 24 mutations,
256B pitch table (`005e1d3c..005e1e3b`) + 1B `.bss` (`00656ab0`), and 1,109
source pins. Five names close (`00589f40`, `004a4760`, `004ae470`, `004b04d0`,
`004ad4d0`) with zero new unresolved names.

Historical: [Run780](iterations/v2/001-original-recovery/runs/780-audio-scene-render-integration/README.md)
build compiles 447 C++ translation units across eight projects. The shared
link reports **91 unresolved names / 99 references**. There is no game EXE.
The shared audit accepts Runs773/778/779 within their bounded domains: 8 new
registry entries (`1,255` total), 268 original-x86 comparisons, 36 mutations,
16B `.bss` (`773` + `779`) + 6B `.rdata` (`779`), and 1,104 source pins. Five
names close (`005898f0`, `0053f380`, `0053f980`, `00573030`, `004121b0`) and
two typed children open (`005a38c7`, `004123e0`).

Historical: [Run776](iterations/v2/001-original-recovery/runs/776-scene-blur-and-input-render-integration/README.md)
build compiles 444 C++ translation units across eight projects. The shared
link reports **94 unresolved names / 101 references**. There is no game EXE.
The shared audit accepts Runs774/775 within their bounded domains: 6 new
registry entries (`1,247` total), 242 original-x86 comparisons, 20 mutations,
0 new owned data bytes, and 1,097 source pins. Six names close (`00537a30`,
`00537a40`, `00537a70`, `00536470`, `005331a0`, `00465df0`) with zero new
unresolved names.

Historical: [Run761](iterations/v2/001-original-recovery/runs/761-audio-backend-range-canonical-state/README.md)
build compiles 442 C++ translation units across eight projects. The shared
link reports **100 unresolved names / 107 references**. There is no game EXE.
The shared audit passes with 1,092 source pins. Its native range proof covers
327,680 cases per optimization and detects three mutations. It closes both
device-limit symbols by reading canonical Run434 state directly. Four backend
functions and the input cleanup child remain unresolved; registry: 1,241.

Historical: [Run747](iterations/v2/001-original-recovery/runs/747-view-teardown-integration/README.md)
compiles 436 C++ translation units across eight projects. The shared link
reports **99 unresolved names / 106 references**. There is no game EXE yet.
Run746's five view teardown bodies pass the shared audit: 70 original-x86
comparisons, 11 mutations, 1,077 source pins, and 1,232 registry entries.
One name closes with zero new linker names. Run744 is native-proved but awaits
its unresolved audio parent; Run745 is tracing the render conversion parent.

Historical: [Run743](iterations/v2/001-original-recovery/runs/743-audio-render-scene-integration/README.md)
compiles 435 C++ translation units across eight projects. The shared link
reports **100 unresolved names / 107 references**. There is no game EXE yet.
The shared audit accepts Runs740/741/742 within their bounded domains: 10 new
registry entries (`1,227` total), 410 original-x86 comparisons, 37 mutations,
55B `.rdata` + 8B `.bss` (`Run741`), and 1,074 source pins. Three names close
(`00567060`, `00571630`, `0059f070`) and two typed children open (`00534b90`,
`00534d40`).

Historical: [Run739](iterations/v2/001-original-recovery/runs/739-scene-program-integration/README.md)
compiles 432 C++ translation units across eight projects (**101 unresolved names /
108 references**), accepting Runs736/737/738 plus the Run739 `00468440` param-4
ABI bridge: 6 new registry entries (`1,217` total), 478 original-x86 comparisons,
33 mutations, 0 new owned bytes, and 1,068 source pins. Two names close
(`00468240`, `004685e0`) and six typed children open (`0053f380`, `0053f980`,
`00537a70`, `00537a40`, `00537a30`, `00536470`).

Historical: [Run735](iterations/v2/001-original-recovery/runs/735-scene-audio-render-integration/README.md)
compiles 428 C++ translation units across eight projects (**97 unresolved names /
104 references**), accepting Runs732/733/734: 25 new registry entries (1,211
total), 4,836 original-x86 comparisons, 44 mutations, and 1,060 source pins.
Four names close; four typed children open.

Historical: [Run730](iterations/v2/001-original-recovery/runs/730-audio-copy-and-frame-control-integration/README.md)
verifies `728/005`, `729/002` and `731/002` (four registry
entries: `0058e310`, replaced `00412030` consumer, `00455830`, `004558b0`;
1,186 total), 14,610 original-x86 comparisons, 24 mutation controls, 1,053
source pins and 13 REA sessions. Six names close (`audio_resource_copy_0058e310`,
three Run400 `frame_control_*` globals, two `scene_stage_tree_ctor_*`
entries) with zero new unresolved names and 4B new readonly data (`005c1694`).

Historical: [Run727](iterations/v2/001-original-recovery/runs/727-input-and-scene-integration/README.md)
compiled 423 TUs (103 unresolved names / 110 references), verifying seven
registry entries (`00412cd0`, `00412e60`, `00532d30`, `00451490`, `005379f0`,
`00537a50`, partial `004552b0`), 8,312 comparisons and 24 mutations.

Historical: Run712 integrated 710/711 (five bodies, 392B; 658 cases / 26
mutations / 1,021 pins; 413 TUs). Run709 integrated 705-708 (nine bodies,
907B; 411 TUs).

Historical: Run698 integrated 691/692/693 (eight full bodies, 2,479B; 374
cases / 75 mutations / 991 pins; 400 TUs; FE main-loop `004152e0`
evidence-only).

Historical: Run694 integrated 688/689/690 (seven full bodies, 1,868B; 24,380
cases / 72 mutations / 984 pins; 397 TUs).

Historical: Run687 integrated eleven partial functions (903 code bytes: `00570260`..`00570540`
in `685/001` plus `005702a0`, `00570920`, `00570990`, `00570ff0`, `00571160` in
`686/002`) and zero owned `.data`/`.rdata`/`.bss`. Native comparisons pass 1060 measured
cases / 47 material controls at `/Od`/`/O2`. Canonical owners are reused. Shared audit
verifies 977 source pins; registry 1114 retains partial domains.

Run566 also compiles six partial callback/resource entries (384 comparisons/four
controls, exact98B readonly data) into an unreferenced archive member. This does
not close a reachable game dependency; real stream-start semantics remain open.

Run685 (`001`), Run686 (`002`), and Run687 (`001`) integration are accepted within their stated bounds.
Run569 remains unaccepted deferred
research. Later draft directories do not supersede accepted build metrics. Active
iteration remains v2/001; numbered runs are recovery packets within it.

Activation4ae010 keeps descriptor bytes22/23 uninitialized and remains partial.
Earlier constructor/metric domains and Run561's true two-live-slot stop remain
open. Partial bindings do not promote semantic parent dependencies. Runs547,
558 and supplemental537005 remain blocked and unaccepted; native AMD 3DNow,
real streams/live TLS, full startup and gameplay remain open. Metrics are not
a completion percentage; detailed bounds live in the run handoffs/backlog.

The composed stop/cleanup/pool chain remains verified after the owner repair through
[Run445](iterations/v2/001-original-recovery/runs/445-audio-owner-alias-regression/README.md).
Outer-group/decoder/removal execution passes bounded seeded and direct scenarios.
Real subscribers, broader parent composition, live APIs and full startup remain open.
Detailed evidence and the next work order live in the
[iteration PLAN](iterations/v2/001-original-recovery/PLAN.md).
Full startup, display, menus, careers and gameplay still need integration/acceptance.

## Other workstreams

The [Rust iteration 012 prototype](iterations/012-campaign-fidelity/README.md) is unfinished.
Compile candidates and x86 lowering tools are research;
they are separate from accepted game code.

The independent Open-Unleashed v0.1.4 Windows release was tested with our assets in an
isolated local folder: Quick Race, garage rendering and first Factory Driver mission
all exited successfully and produced screenshots. Quick Race advanced 1,280 ticks;
the mission smoke run failed its objective and does not prove career completion.
Native Computer Use returned `spawn EPERM`, so no interactive visual acceptance is
claimed. Original asset sizes/mtimes were unchanged. This is external-port evidence,
not a successful build or fidelity proof of our C++ reconstruction.

[PR #25](https://github.com/xfynx/prsche-disasm/pull/25) is integrated into the Rust
prototype, with collision-unit and FFN metric corrections and author attribution.
Its [intake review](docs/research/pr25-integration-review-2026-10-26.md) records the
build/test/browser evidence and unsupported speech-archive boundary. Its recorders
are available for C++ recovery; the C++ checkpoint above is unchanged.

[PR #26 intake](docs/research/pr26-integration-review-2026-10-29.md) adds recorded
keyboard, object and launch/barrier evidence, repairs damage writeback and keeps
unproved new compositions behind an experimental feature. It updates the Rust
prototype and research tools; the C++ checkpoint above is unchanged.

[Xerj source review](docs/research/xerj-evaluation-2026-10-26.md) is complete.
A bounded local retrieval trial could measure its value; no performance gain or
runtime/MCP integration has been verified here.

## Evidence and remaining checks

Use the [binary index](research/binary-index/README.md), [recovery runs](iterations/v2/001-original-recovery/runs/),
[validation backlog](docs/recovery-validation-backlog.md) and [roadmap](PLAN.md).
Older checkpoints remain in the iteration history and Git; this file describes current state.
