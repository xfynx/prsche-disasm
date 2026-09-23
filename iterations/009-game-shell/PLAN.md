# 009-game-shell: рабочий план

Завершена 2026-09-24. Статус: завершена, все критерии выполнены.
Снимки 001–008 и local/game неизменны. Runs: 001, 002.

## Цель и критерии

Общая игровая оболочка, профиль/сохранения и первые сквозные события Evolution
и Factory Driver. Полная постановка: [docs/next-iteration.md](../../docs/next-iteration.md).
Критерии: меню → профиль → событие → результат → запись → перезапуск → продолжение;
обе карьеры, native/web, регресс управления, сборки и визуальная приёмка.

## Задачи и результаты

- [x] T00: инверсия 6 DOF и регресс управления — завершено ([Run 001](runs/001-controls-regression/README.md)).
  Отрицательный угол для правого поворота при локальном -Z в `vehicle.rs`;
  исправлены физический и визуальный повороты колёс. 21 тест `porsche-viewer` зелёный.
- [x] T01: модель экранов и общая навигация — завершено.
  Машина экранов `Screen` (`MainMenu`, `ProfileSelect`, `ModeSelect`, `EventBriefing`,
  `Loading`, `Racing`, `Results`) в крейте [`crates/nfs-game`](crates/nfs-game).
  Идемпотентный переход к результатам, отмена загрузки.
- [x] T02: профиль, надёжное сохранение и восстановление — завершено.
  `PlayerProfile` с балансом (11 000 CR), гаражом ('50 356 Coupé Ferdinand),
  рангом испытателя и открытыми эпохами. Атомарное сохранение `.tmp` -> rename на диске,
  `localStorage` и экспорт/импорт JSON в Web.
- [x] T03: подтверждение правил событий и связей ресурсов — завершено.
  Исследованы структуры `nfs5.fac` и `nfs5.trn`, зафиксированы точные оффсеты и правила
  в [`research/first-events-evidence.md`](research/first-events-evidence.md).
  Расширен крейт `nfs-formats` парсерами `parse_tournaments` и `FactoryMissionTemplate`.
- [x] T04: первые сквозные события обеих карьер — завершено.
  Evolution 356 Challenge (2 этапа: Canyon и Monaco 1; 4 участника, взнос 2 000 CR, призовые 4 500 CR);
  Factory Driver 0M01 Applying Test (Skidpad, Porsche Boxster, лимит 32.0 с, реплика механика).
- [x] T05: базовый звук, интеграция и приёмка — завершено ([Run 002](runs/002-game-shell/README.md)).
  Native: WinMM аудио-сигналы отсчёта и результатов, F2/F3 быстрый выбор событий.
  Web: WebAudio синтезатор (обороты RPM, визг шин, сигналы отсчёта/финиша), модалы брифинга
  и результатов с баллоном реплики, профильная плашка в шапке.

## Подтверждённые факты

1. Структура `nfs5.fac` — 34 записи по 240 байт; миссия 0M01 имеет флаг типа 0x02, лимит времени 32.0 секунды на полигоне Skidpad.
2. Структура `nfs5.trn` — 35 турниров по 3392 байта; турнир 0 (356 Challenge) содержит 2 этапа (Canyon и Monaco 1), 4 участника, вступительный взнос 2 000 CR, приз 4 500 CR.
3. Сохранения игры (`XXDefXX.sav` vs `0xfynx.sav`) подтверждают стартовый капитал 11 000 CR и покупку начального '50 356 Coupé Ferdinand.

## Проверки

```powershell
. ./scripts/tool-env.ps1
cargo fmt --manifest-path iterations/009-game-shell/Cargo.toml --all -- --check
cargo test --locked --manifest-path iterations/009-game-shell/Cargo.toml --target-dir local/builds/009-game-shell/.cargo-target --workspace
cargo clippy --locked --manifest-path iterations/009-game-shell/Cargo.toml --target-dir local/builds/009-game-shell/.cargo-target --workspace --all-targets -- -D warnings
node iterations/009-game-shell/web/ui.test.mjs
./scripts/build.ps1 -Iteration 009-game-shell -Config release -Target all
node iterations/009-game-shell/web/verify-browser.cjs <playwright-core> auto iterations/009-game-shell/runs/002-game-shell
```

Все проверки пройдены (129 тестов Rust, 0 warnings clippy, clean fmt, browser regression 10/10).
Итерация закрыта. Следующий шаг: фиксация Git-тегом `iteration-009` и переход к `010-evolution-career`.
