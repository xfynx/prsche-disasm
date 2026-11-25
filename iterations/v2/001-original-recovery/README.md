# Original source recovery

Start with the [active plan](PLAN.md) for open providers and the [current status](../../../STATUS.md) for measured coverage. The target is the original Windows x86 game, including Evolution and Factory Driver.

- [Reference inventory](reference/binaries.json) identifies binaries by SHA. The [corpus](../../../research/v2/README.md) contains assembly, automatic pseudo-C and analysis gaps.
- [Recovered source](source/) and [function registry](source/recovered/functions.json) identify C/C++ owners and their proof boundaries. Accepted run-owned sources also participate in the shared build.
- [Recovery runs](runs/) preserve the original comparisons, build manifests and handoffs. The [build instructions](../../../docs/building.md) describe the Windows toolchain.

The [iteration log through Run846](https://github.com/xfynx/prsche-disasm/blob/9bc538dcdaaa3915ac5d1e7e77dfd071d2056465/iterations/v2/001-original-recovery/README.md) retains the earlier subsystem notes and commands.
