# Сборка viewer

Из корня репозитория выполните одну команду:

```powershell
./scripts/build.ps1
```

По умолчанию собирается активная `009-game-shell` в конфигурации `release`.
Windows executable: `local/builds/009-game-shell/windows/porsche-viewer.exe`.
Web-пакет: `local/builds/009-game-shell/web`, статический UI плюс wasm-bindgen
в `package` (`viewer_impl.js`, `viewer_impl_bg.wasm` и сопутствующий `.d.ts`).

Запуск: `./scripts/launch-viewer.ps1 -Mode desktop|web|native` (выбрать одно значение).
Дополнительный desktop использует тот же web-пакет в отдельном окне Edge/Chrome;
нужны установленный браузер и Python для локального read-only сервера.
Helper слушает свободный loopback-порт, PID проверяется, логи каждого запуска
сохраняются в `local/builds/<iteration>/launcher/<id>`. Остановка сервера — Ctrl+C
в консоли launcher; закрытие окна браузера пока не останавливает сервер автоматически.
Native работает самостоятельно: без аргументов — каталог; `catalog --game-dir <path>`
выбирает другой источник; прежние `inspect/view` сохранены.

Параметры `-Iteration`, `-Config debug|release` и `-Target all|native|web` позволяют выбрать снимок, конфигурацию или часть сборки. Скрипт требует Rust `1.98.1` из `rust-toolchain.toml`, проверенный `Cargo.lock` в корне итерации и `wasm-bindgen-cli 0.2.128` на `PATH`; для нового снимка сначала создайте lock-файл командой `cargo generate-lockfile --manifest-path iterations/<iteration>/Cargo.toml`. Окружение можно подготовить через `./scripts/tool-env.ps1`.

Игровые файлы не копируются в результаты сборки. Все итерации используют общий `local/game`; путь можно явно указать параметром `-GameDir`, а при запуске передать viewer его штатный `--game-dir <path>`.
