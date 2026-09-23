# 009-game-shell

Статус: завершена. Тег `iteration-009`.
Цель: общая игровая оболочка, профиль игрока и надёжные сохранения, первые сквозные события карьер Evolution (356 Challenge) и Factory Driver (0M01 Applying Test), базовый звук и регресс управления.

## Выполнено

- Архитектурная машина экранов `Screen` и профиль `PlayerProfile` в независимом крейте `crates/nfs-game`.
- Атомарное сохранение профиля на диск (`.tmp` -> rename) и JSON-сериализация для Web `localStorage` / импорта / экспорта.
- Бинарный реверс структур турниров `nfs5.trn` и фабричных миссий `nfs5.fac` в `crates/nfs-formats` и `research/first-events-evidence.md`.
- Первые сквозные события обеих карьер: Evolution 356 Challenge (Canyon, Monaco 1) и Factory Driver 0M01 (Skidpad, Boxster, 32.0 с).
- Звуковая подсистема: WebAudio синтезатор (RPM двигателя, визг шин, сигналы отсчёта и финиша) и WinMM beeper для native.
- Полный регресс управления: исправление знака руля 6 DOF, 129 тестов Rust, UI-тесты и 10 проверок в Chromium WebGPU.

Подробные отчёты проверок:
- [Run 001: регресс управления после 008](runs/001-controls-regression/README.md)
- [Run 002: приёмка игровой оболочки, карьер и звука](runs/002-game-shell/README.md)
- [Рабочий план](PLAN.md)

## Запуск

```powershell
./scripts/build.ps1 -Iteration 009-game-shell -Config release -Target all
./scripts/launch-viewer.ps1 -Iteration 009-game-shell -Mode desktop
```

Web-версия доступна через `-Mode web` (порт по умолчанию 8080).
Клавиши:
- F: вход в заезд / режим орбиты
- C: переключение вида камеры
- M: переключение физики (6 DOF / Аркадный прототип)
- H: скрыть/показать HUD приборов
- F2 (Native) / кнопка Evolution (Web): первый турнир 356 Challenge
- F3 (Native) / кнопка Factory (Web): начальная миссия Factory Driver 0M01
