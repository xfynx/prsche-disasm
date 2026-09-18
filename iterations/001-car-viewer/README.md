# 001-car-viewer

Статус: завершена и принята пользователем 2026-09-19. Тег: `iteration-001`.

Цель этой итерации — загрузить все 44 модели `CarModel` из общей
копии игры `local/game` и показать их в native-просмотрщике и в браузере.
Игровые файлы в эту папку не копируются.

## Требования

- Windows с установленным Rust toolchain из [`rust-toolchain.toml`](rust-toolchain.toml)
  (`1.98.1`, target `wasm32-unknown-unknown`).
- Для native-просмотрщика — Vulkan-драйвер.
- Для браузера — браузер с WebGPU, например актуальный Chrome или Edge.
- Подготовленная копия игры в `local/game` корня репозитория.

## Быстрый запуск native-просмотрщика

Команды выполняются из корня репозитория:

```powershell
. .\scripts\tool-env.ps1
. .\scripts\build.ps1 -Iteration 001-car-viewer -Config release -Target native
.\local\builds\001-car-viewer\windows\porsche-viewer.exe view --game-dir .\local\game --car 356a
```

Окно можно закрыть стандартным способом. Для второй кузовной версии используйте
`--car 356b`. Если путь к игре другой, замените значение `--game-dir`.

Проверка загрузки без открытия окна:

```powershell
.\local\builds\001-car-viewer\windows\porsche-viewer.exe inspect --game-dir .\local\game --car 356a
```

`inspect` также печатает список статей CRP, исключённых из parked-car сцены,
с причиной исключения. Это используется для проверки выбора закрытого кузова
перед визуальным запуском.

## Версионирование запусков

Визуальные проверки сохраняются в
[`runs/`](runs/README.md). Для каждого запуска создаётся новая папка с
последовательным номером, README с командой и PNG-снимками. Пример:

```powershell
.\local\builds\001-car-viewer\windows\porsche-viewer.exe view `
  --game-dir .\local\game --car 356b `
  --screenshot .\iterations\001-car-viewer\runs\002-next-check\356b.png `
  --width 1280 --height 720
```

Игровые файлы, бинарники и `target` в `runs` не копируются.

## Запуск браузерной версии

Сначала соберите WebAssembly-пакет:

```powershell
. .\scripts\tool-env.ps1
. .\scripts\build.ps1 -Iteration 001-car-viewer -Config release -Target web
py -3 .\scripts\serve-web.py --iteration 001-car-viewer --port 8000
```

Откройте <http://127.0.0.1:8000/> в браузере. Сайт не получает доступ к
`local/game` напрямую: нажмите **Папка игры** и выберите каталог игры
целиком. Можно выбрать только отдельные файлы, но для `356a`/`356b` нужны
соответствующие `.crp`, `.tpg` и общие FSH-ресурсы (`INTGLASS.FSH`,
`Shadow.fsh`, `Cabrio.fsh`). Выберите автомобиль в поле **Авто** и нажмите
**Загрузить**.

## Управление

- Зажать левую кнопку мыши и двигать мышь — вращение камеры.
- Колесо мыши — приближение и отдаление.
- `R` — сброс камеры.
- `C` — переключение цвета кузова между шестью тестовыми вариантами.
- Изменение размера окна браузера поддерживается автоматически.

Открытие дверей, капота и багажника пока не является готовой функцией viewer.
Loader выбирает согласованные Base/LOD и TPG style1, без фильтра In/Out по имени.
Текущее состояние и открытые дефекты — в [плане](PLAN.md).
Запуски [`002`](runs/002-in-variants/README.md) —
[`005`](runs/005-all-panels/README.md) показывают, что одного выбора по имени
недостаточно. Полноценное переключение по хоткею будет добавлено только после
сопоставления article-геометрии, `Base` и runtime-состояния.

## Проверки

```powershell
. .\scripts\tool-env.ps1
cargo test --manifest-path .\iterations\001-car-viewer\Cargo.toml --locked
cargo check --manifest-path .\iterations\001-car-viewer\Cargo.toml --target wasm32-unknown-unknown --locked --lib
```

Первый функциональный снимок. Тег: `iteration-001`. Исходные критерии
закрытия — визуальная проверка всех 44 моделей, native и браузерный smoke-тест,
успешные tests/build, без заглушек геометрии. [Run010](runs/010-material-depth/README.md):
44/44, 88 снимков осмотрены, 30 unit + 3 GPU tests, native/WASM готовы.
Браузер подтверждён пользователем 2026-09-19; закрытие разрешено.
Отдельный интерактивный native smoke не подтверждён (native проверен offscreen).
Все стили/LOD/повреждения и полный CLR не проверены. Это сохранённые ограничения.
