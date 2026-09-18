# Run 002: `In` panel variants

- Дата: 2026-09-17
- Автомобиль: `356b`
- Цель: проверить состояние кузова по `Base` flags и геометрии панелей.
- Результат: экспериментальная проверка `DoorIn`/`HoodIn`/`TrunkIn`;
  `DoorOut`/`HoodOut`/`TrunkOut` были исключены, но целостность кузова не
  подтверждена.

## Команда

```powershell
. .\scripts\tool-env.ps1
cargo run --manifest-path .\iterations\001-car-viewer\Cargo.toml --locked `
  --bin porsche-viewer -- view `
  --game-dir .\local\game --car 356b `
  --screenshot .\iterations\001-car-viewer\runs\002-in-variants\356b.png `
  --width 1280 --height 720
```

## Наблюдение

У `DoorOut`/`HoodOut`/`TrunkOut` `Base` flags начинаются с `0x1a`, а у
`DoorIn`/`HoodIn`/`TrunkIn` — с `0x1b`/`0x1e`. `tr` у этих статей содержит
перенос, но не поворот; открытое/закрытое положение уже запечено в вершинах.
На снимке с `*In` панели выглядят закрытыми, но последующие контрольные
запуски показали, что геометрия всё ещё развалена; этот результат не считается
исправлением.
