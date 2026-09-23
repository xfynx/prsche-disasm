# 009-game-shell

Статус: в работе. Снимок 008-race-loop без прежних runs. Планируемый тег iteration-009.
Цель: общая оболочка, профиль/сохранения, первые события обеих карьер.
Первый шаг выполнен: исправлен руль 6 DOF и добавлен регресс управления после 008.
118 Rust-тестов, web input tests, fmt/clippy, native/WASM release и Chromium — passed.
[Артефакты проверки](runs/001-controls-regression/README.md).

[Рабочий план и проверки](PLAN.md). [Постановка](../../docs/next-iteration.md).

```powershell
./scripts/build.ps1 -Iteration 009-game-shell -Config release -Target all
./scripts/launch-viewer.ps1 -Iteration 009-game-shell -Mode desktop
```

Web/native доступны через -Mode web/native. local/game только читается.
Аркадный прототип и 6 DOF переключаются M; F — заезд, WASD/стрелки — управление.
Готовность исправления руля не означает готовность оболочки или карьер.
