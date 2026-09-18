# Run 001: variant filter

- Дата: 2026-09-17
- Автомобиль: `356b`
- Цель: проверить выбор статей `DoorOut`, `HoodOut`, `TrunkOut` и `*In`
  в parked-car сцене.
- Сборка: native debug через `cargo run`

## Команды

```powershell
. .\scripts\tool-env.ps1
cargo run --manifest-path .\iterations\001-car-viewer\Cargo.toml --locked `
  --bin porsche-viewer -- view `
  --game-dir .\local\game --car 356b `
  --screenshot .\iterations\001-car-viewer\runs\001-variant-filter\current-356b.png `
  --width 1280 --height 720
```

Для сравнения использовался предыдущий вариант с тем же размером кадра:

```text
closed-356b.png
```

## Наблюдение

Вариант с `DoorOut`/`HoodOut`/`TrunkOut` показывает открытые панели. Вариант
без них теряет соответствующие панели. Одного имени статьи недостаточно для
выбора закрытого состояния; следующий запуск должен сравнить `Base`, `tr` и
animation/state-поля.
