# Скрипты проекта и утилиты

В папке `scripts/` содержатся служебные скрипты для сборки, запуска, тестирования, создания итераций и реверс-инжиниринга оригинальных ресурсов Porsche Unleashed.

## Основные команды сборки и запуска

### `scripts/build.ps1`
Основной скрипт компиляции проекта.
- **Параметры**:
  - `-Iteration <string>`: имя итерации (по умолчанию `009-game-shell`, `010-evolution-career` и т.д.).
  - `-Config <debug|release>`: профиль сборки (по умолчанию `release`).
  - `-Target <all|native|windows|web>`: целевая платформа (по умолчанию `all`).
  - `-GameDir <string>`: путь к ресурсам (по умолчанию `local/game`).
- **Действие**:
  - Автоматически настраивает окружение через `tool-env.ps1`.
  - Собирает нативный бинарник `porsche-viewer.exe` в `local/builds/<iteration>/windows/`.
  - Собирает WASM-библиотеку `porsche_viewer.wasm`, копирует статический каталог `web/` в `local/builds/<iteration>/web/` и вызывает `wasm-bindgen` с генерацией пакета в `local/builds/<iteration>/web/package/`.
  - Генерирует лаунчеры `Launch-desktop.cmd`, `Launch-web.cmd`, `Launch-native.cmd`.

### `scripts/launch-viewer.ps1`
Универсальный лаунчер просмотрщика для текущей или заданной итерации.
- **Параметры**:
  - `-Iteration <string>`: имя снимка итерации.
  - `-Mode <desktop|web|native>`: режим запуска.
    - `desktop`: запуск локального веб-сервера `serve-web.py` и открытие отдельного окна браузера (Edge/Chrome) в режиме app.
    - `web`: запуск `serve-web.py` и открытие в браузере по умолчанию.
    - `native`: запуск нативного исполняемого файла `porsche-viewer.exe` с аргументами `--game-dir`.
  - `-GameDir <string>`: путь к ресурсам игры.
  - `-Port <int>`: порт веб-сервера (по умолчанию 8080).

### `scripts/tool-env.ps1`
Настройка переменных среды сборщика (PowerShell dot-sourcing: `. ./scripts/tool-env.ps1`).
- Подключает `$env:USERPROFILE/.cargo/bin` в `$env:PATH`.
- Находит и подключает локальные тулсеты в `local/tools` (`wasm-bindgen-cli 0.2.128`, Ninja, CMake, JDK, Ghidra).
- Автоматически входит в Microsoft Visual Studio Developer Shell (`Enter-VsDevShell -arch=x64`).

### `scripts/new-iteration.py`
Создание нового изолированного снимка следующей итерации.
- **Параметры**:
  - `--from <source_iteration>`: исходная завершённая итерация (например, `009-game-shell`).
  - `--name <new_iteration>`: новое имя в формате `NNN-name` (например, `010-evolution-career`).
- **Действие**:
  - Рекурсивно копирует дерево исходной итерации.
  - Исключает временные файлы, кэши компилятора (`target`, `.cargo-target`), историю запусков (`runs`) и `node_modules`.
  - Создаёт свежий `README.md` и папку `runs/` с чистым `README.md`.

### `scripts/serve-web.py`
Легковесный локальный сервер на Python для тестирования и запуска веб-версии.
- Обслуживает директорию сборки с защитой от кэширования (`Cache-Control: no-store`).
- Предоставляет безопасный доступ только для чтения к ресурсам `local/game` через маршрут `/game/` и API `/api/game-files`.
- Поддерживает MIME-типы для форматов игры: `.wasm`, `.crp`, `.fsh`, `.tpg`, `.edg`, `.jnc`, `.map`, `.scn`.

---

## Диагностические и инвентарные скрипты

### `scripts/check-environment.ps1`
Проверка готовности хост-системы:
- Проверяет наличие `cargo`, `rustc`, `node`, `python`, `git`.
- Проверяет версии компиляторов и наличие компонентов `clippy` и `rustfmt`.

### `scripts/prepare-game.py`
Валидация целостности игровых файлов `local/game`.
- Сверяет файлы игры с манифестом `docs/game-manifest.json` (SHA-256 хэши и размеры).

### `scripts/inventory-tracks.py`
Инвентарь и аудит всех 15 трасс игры:
- Проверяет наличие обязательных пар `.crp`, `.fsh`, файлов топологии (`.edg`, `.jnc`, `.map`) и сценариев (`.scn`).

### `scripts/validate-cars.ps1`
Пакетный валидатор моделей автомобилей:
- Проверяет 44 модели автомобилей в каталоге `local/game/Carmodel/` на корректность загрузки CRP, текстур FSH и топологии TPG.

### `scripts/inventory-pe.py`
Инвентарь секций исполняемого файла `nfs5.exe`:
- Парсит заголовки PE, экспорты, секции кода и данных для помощи в реверс-инжиниринге.

### `scripts/capture-game-modules.ps1`
Сбор информации о динамически загружаемых модулях и DLL оригинальной игры во время исполнения.

### `scripts/contact-sheet.ps1`
Генерация обзорных коллажей (contact sheets) из скриншотов рендеринга трасс и автомобилей для визуального сравнения.

---

## Автоматические тесты скриптов

- `scripts/test_iterations.py`: проверяет инварианты структуры папок итераций и работу `new-iteration.py`.
- `scripts/test_inventory_tracks.py`: юнит-тесты для инвентаризатора трасс.
- `scripts/test_track_cli.py`: тестирование командной строки CLI инвентаря.
