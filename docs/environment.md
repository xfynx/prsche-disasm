# Окружение разработки

Проверено на Windows x86-64, 2026-09-16. Все переносимые инструменты находятся
в `local/tools`, настройки PATH применяются только к текущему процессу через
`. ./scripts/tool-env.ps1`.

## Установленные версии

- Git 2.49.0.windows.1 (существовал).
- Python 3.12.10, запуск `py -3.12` (существовал; `python` был alias Microsoft Store).
- Rust/Cargo 1.98.1, rustfmt 1.9.0, Clippy 0.1.98; rustup пользовательский.
- Targets: x86_64-pc-windows-msvc и wasm32-unknown-unknown.
- MSVC 14.44.35207, Build Tools в local/tools/BuildTools.
- Windows SDK headers/libs 10.0.26100.0; installer 10.1.26100.7705,
  установлен в зарегистрированный `C:\Program Files (x86)\Windows Kits\10`.
- CMake 4.4.3, Ninja 1.13.2.
- Ghidra 12.1.3 PUBLIC, Temurin JDK 25.0.4.1+1.
- x64dbg snapshot 2026-05-27, x32 и x64 исполняемые файлы проверены.
- wasm-bindgen-cli 0.2.128 (версия совпадает с Rust crate).

## Источники

- https://rustup.rs/ (rustup-init.exe), https://static.rust-lang.org/
- https://aka.ms/vs/17/release/vs_BuildTools.exe
- https://github.com/Kitware/CMake/releases/tag/v4.4.3
- https://github.com/ninja-build/ninja/releases/tag/v1.13.2
- https://github.com/NationalSecurityAgency/ghidra/releases/tag/Ghidra_12.1.3_build
- https://github.com/adoptium/temurin25-binaries/releases/tag/jdk-25.0.4.1%2B1
- https://github.com/x64dbg/x64dbg/releases/tag/2026.05.27
- https://github.com/wasm-bindgen/wasm-bindgen/releases/tag/0.2.128

Скачанные архивы сохранены в local/tools/downloads. Ghidra, JDK и wasm-bindgen
проверены по SHA-256 официальных релизов; установщик SDK имеет действительную
подпись Microsoft. Полные значения можно получить Get-FileHash архивов.

## Установка и проверка

Rust закреплён rust-toolchain.toml каждой итерации. Rust установлен через
rustup-init с profile minimal; компоненты rustfmt/clippy и wasm32 добавлены rustup.
MSVC установлен штатным vs_BuildTools.exe на F:. Первая попытка полного набора
SDK не завершилась; повторная установила только DesktopCPPx64/DesktopCPPx86:

```text
winsdksetup.exe /features OptionId.DesktopCPPx64 OptionId.DesktopCPPx86 /quiet /norestart /ceip off
```

SDK потребовал существующий зарегистрированный каталог Windows Kits.
Повторная установка завершилась кодом 0. Отчёты установщика — local/tools/downloads.

Проверки:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/check-environment.ps1 -Smoke
. ./scripts/tool-env.ps1
cargo check --manifest-path iterations/001-car-viewer/Cargo.toml --target-dir local/builds/001-car-viewer/.cargo-target --locked
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/analyze-game.ps1
```

Проверка окружения и Rust smoke прошли. Bootstrap напечатал
`Porsche Unleashed bootstrap: windows x86_64`. Ghidra анализ запускается отдельно;
итог фиксируется в STATUS.md. Её пользовательские настройки/кэш требуют записи
в AppData, проекты и журналы сохраняются в local/.

## Ограничения

Наличие x32dbg/x64dbg проверено по файлам; интерактивная работа отладчика пока не
подтверждена. Сервис автоматизации native UI сообщил недоступность named pipe.
Это не мешает CLI, headless-анализу и генерации offscreen-изображений.
