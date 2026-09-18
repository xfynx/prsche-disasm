# Porsche Unleashed: текущая реализация

Актуальный согласованный проект: Rust + wgpu + winit, Windows/Linux/macOS
и браузерный WebAssembly/WebGPU-просмотрщик. [План](PLAN.md), [статус](STATUS.md),
[сборка](docs/building.md), [агенты и модели](docs/agents.md).

Полные снимки исходников находятся в `iterations/`. Все они читают одну общую
папку ресурсов `local/game`; ресурсы не копируются в итерации или сайт.
Дополнительные копии допускаются для изменяющих файлы экспериментов.

Текущий просмотрщик: [001-car-viewer](iterations/001-car-viewer/README.md).
Воспроизводимые визуальные проверки: [runs](iterations/001-car-viewer/runs/README.md).
Run010: проверены 44 модели с двух сторон; фары не перекрашиваются.
001 принята 2026-09-19 после ручной проверки браузера; тег `iteration-001`.
Далее — [002-track-viewer](docs/next-iteration.md).

Ниже сохранены ранее появившиеся заметки. Перечисленные в них адреса, названия
функций, версии и структура C++-проекта не подтверждены текущим исследованием;
при расхождениях следует пользоваться PLAN.md и STATUS.md.

---

# Need for Speed: Porsche Unleashed (NFS 5) Reverse Engineering Project

Reverse engineering and disassembly project for **Need for Speed: Porsche Unleashed** (PC, released 2000).

---

## 🎯 Objectives
- **Static Analysis**: Disassemble and decompile `Porsche.exe` (v3.5 / v3.52) using Ghidra / IDA Pro.
- **Dynamic Analysis**: Map runtime memory addresses, data structures, and function calls using x32dbg & Cheat Engine.
- **File Format Specification**: Document internal file structures (`.viv`, `.crp`, `.fsh`, `.carp`, `.tri`, `.pne`).
- **Decompilation / Reconstruction**: Reconstruct clean C/C++ header definitions, game logic, physics engine, and render pipeline.

---

## 📁 Repository Structure

```
porsche disasm/
├── bin/                 # Target executables & clean binaries (Porsche.exe v3.52)
├── docs/                # Reverse engineering notes & documentation
│   ├── file_formats.md  # Detailed specs for .viv, .crp, .carp, .fsh, etc.
│   └── memory_map.md    # Function entry points, global variables, and memory offsets
├── src/                 # Reconstructed C/C++ source code & data structure headers
│   └── nfs_types.h      # Core C data types and structures
├── tools/               # Helper scripts, Ghidra scripts, and conversion utilities
└── CMakeLists.txt       # Build system configuration for decompiled code / hooks
```

---

## 🛠 Recommended Tooling

| Category | Tool | Description |
|---|---|---|
| **Disassembler / Decompiler** | [Ghidra](https://ghidra-sre.org/) | Recommended for x86 32-bit decompilation and data structure analysis |
| **Alternative Disassembler** | IDA Pro / Binary Ninja | Alternative static analysis tools |
| **Debugger** | [x32dbg](https://x32dbg.com/) | 32-bit Windows debugger for dynamic analysis |
| **Memory Scanner** | [Cheat Engine](https://www.cheatengine.org/) | Runtime variable searching and pointer map generation |
| **PE Inspector** | PEview / CFF Explorer | Inspect PE headers, imports, sections, and DRM wrappers |

---

## ⚙ Executable Prerequisites

1. **Target Version**: `Porsche.exe` patched to **v3.5** or **v3.52** (English / Multi version).
2. **Unpacked Executable**: Ensure SafeDisc DRM wrapper is stripped (Executable base address: `0x00400000`).
3. **Compiler Target**: Microsoft Visual C++ 6.0 (MSVC 6.0 x86 32-bit, `cdecl` / `thiscall` calling conventions).

---

## 🚀 Quick Start Guide

### 1. Preparing `Porsche.exe` in Ghidra
1. Open Ghidra and create a new project.
2. Import `bin/Porsche.exe`.
3. Set Language to **x86:LE:32:Visual Studio:default** (32-bit Little Endian x86).
4. Run auto-analysis with standard options enabled.
5. Apply Visual Studio 6.0 Function ID (FID) signatures to auto-label CRT library routines.

### 2. Key Target Areas
- **Main Entry Point**: `WinMain` at startup.
- **File System**: Archives loading `.viv` files (`GIM_ReadFile`, `VIV_ExtractFile`).
- **Physics Engine**: Vehicle dynamics tick (`VehiclePhysics_Update`), `.carp` parsing.
- **Graphics Pipeline**: D3D7 / Glide rendering pipeline (`Render3D_DrawMesh`).
