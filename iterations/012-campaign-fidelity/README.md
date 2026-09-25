# 012-campaign-fidelity

В работе. Создана из 011 без прежних runs. Исправления соответствия карьер оригиналу,
старта Factory Driver, подвески и торможения/заднего хода. [Рабочий план](PLAN.md),
[checkpoint run 001](runs/001-fidelity-repair/README.md).

```powershell
./scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
./scripts/extract-fe-ui.ps1
./scripts/launch-viewer.ps1 -Iteration 012-campaign-fidelity -Mode desktop
```

Снимки 001–011 и local/game неизменны. 151 Rust-тест и 14 браузерных проверок прошли;
Windows/WASM release собраны. Визуальная приёмка открыта: стартовая камера 0M01 перекрыта
геометрией, UI ещё не 1:1, правила и точный spawn offset требуют проверки оригинала.
