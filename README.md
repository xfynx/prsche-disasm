# Need for Speed: Porsche Unleashed / Porsche 2000

This project recovers the original PC game's Windows x86 code as C/C++. The target includes the original driving physics, damage, AI, Quick Race, Evolution and Factory Driver careers, used-car market, saves, menus, graphics and audio. The recovered game executable is still pending. [Current status](STATUS.md) | [Roadmap](PLAN.md)

## Build and contribute

Supply your own game files in read-only `local/game/`. From the repository root on Windows x64 with Visual Studio 2022 Build Tools (C++ x86/x64), Windows SDK, CMake and Python 3, build the Win32 recovery modules and verification programs:

```powershell
./scripts/build-v2.ps1
```

Build outputs go under `local/builds/v2/001-original-recovery/`. For toolchain setup, the shared game-link check and reference assets, see [building](docs/building.md) and [installation provenance](docs/game-build.md).

## Find code and evidence

- [Active iteration](iterations/v2/001-original-recovery/README.md) and [handoff](iterations/v2/001-original-recovery/PLAN.md) for the next recovery tasks.
- [Binary index](research/binary-index/README.md), [source registry](iterations/v2/001-original-recovery/source/recovered/functions.json), [recovery runs](iterations/v2/001-original-recovery/runs/) and [proof manifests](research/v2/proof-manifests/README.md) for addresses, owners and original comparisons.
- [Validation backlog](docs/recovery-validation-backlog.md) for open fidelity checks. The [Rust/WebGPU prototype](iterations/012-campaign-fidelity/README.md) is a separate, paused workstream.
- [Documentation](docs/README.md), [contributing](CONTRIBUTING.md) and [project rules](AGENTS.md). Include the module or resource identity, addresses, inputs, intermediate state and outputs when proposing an original-code change.

## License and game assets

Project-owned original contributions use the [MIT License](LICENSE), subject to
[LICENSING.md](LICENSING.md). Original game binaries, resources, reproduced game
material and third-party contributions are not automatically relicensed. You need
your own copy of the game. This is an unofficial project, unaffiliated with Electronic
Arts, Eden Games or Porsche AG.

## Related work and acknowledgements

Resource research has benefited from [Denis Auroux's CRP/FSH tools](https://auroux.free.fr/),
[OpenNFS / LibOpenNFS](https://github.com/OpenNFS/LibOpenNFS) and
[dima424658 / LibOpenNFS](https://github.com/dima424658/LibOpenNFS).
[Open-Unleashed](https://github.com/Second-Boot/Open-Unleashed) is a separate Rust
reimplementation; evaluating it does not establish original-game fidelity or change
this project's licensing scope.
