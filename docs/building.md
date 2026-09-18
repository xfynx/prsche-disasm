# Сборка viewer

Из корня репозитория выполните одну команду:

```powershell
./scripts/build.ps1
```

По умолчанию собирается `001-car-viewer` в конфигурации `release`. Windows executable записывается в `local/builds/001-car-viewer/windows/porsche-viewer.exe`. Web-пакет содержит статические файлы из `iterations/001-car-viewer/web` и файлы wasm-bindgen в `local/builds/001-car-viewer/web/package` (`viewer_impl.js`, `viewer_impl_bg.wasm` и сопутствующий `.d.ts`).

Параметры `-Iteration`, `-Config debug|release` и `-Target all|native|web` позволяют выбрать снимок, конфигурацию или часть сборки. Скрипт требует Rust `1.98.1` из `rust-toolchain.toml`, проверенный `Cargo.lock` в корне итерации и `wasm-bindgen-cli 0.2.128` на `PATH`; для нового снимка сначала создайте lock-файл командой `cargo generate-lockfile --manifest-path iterations/<iteration>/Cargo.toml`. Окружение можно подготовить через `./scripts/tool-env.ps1`.

Игровые файлы не копируются в результаты сборки. Все итерации используют общий `local/game`; путь можно явно указать параметром `-GameDir`, а при запуске передать viewer его штатный `--game-dir <path>`.
