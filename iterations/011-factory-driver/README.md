# 011-factory-driver

Статус: завершена. Тег `iteration-011`.
Цель: полная реализация сюжетного режима карьеры **Factory Driver (Заводской водитель)**: все 34 миссии из `nfs5.fac`, детекторы трюков (развороты 180° и 360°, J-turn в реверсе, слаломные конусы), карьерные ранги и наградные автомобили.

## Выполнено

- **Бинарный реверс Factory Driver**: исследованы и специфицированы 34 миссии из `nfs5.fac` и языковой базы `festrings.csv`. Документировано в `research/missions_catalog.md` и `research/factory-driver-evidence.md`.
- **Движок испытаний и трюков**: модуль `factory_driver.rs` в `crates/nfs-game`:
  - `StuntDetector`: мониторинг курсового угла, скольжения, перегрузок, обратного хода и столкновений с конусами (+2.0с штрафа).
  - Типы заданий: скоростной слалом, трюки на 360° и 180°, рекламный ролик Porsche (Gymkhana), доставка без повреждений кузова, дуэли против Билли, Фрэнка, Рольфа и Стефани (Аса).
- **Карьерная лестница и наградной гараж**:
  - Ранги: Кандидат (Applicant), Младший испытатель (Junior Test Driver), Тест-пилот (Test Driver), Старший тест-пилот (Senior Test Driver), Шеф-испытатель (Chief Test Driver), Мастер-пилот (Master Ace).
  - Наградные автомобили с заводским тюнингом: '78 911 Turbo 3.3, '73 911 Carrera RS 2.7, '99 911 GT3 Factory Edition.
- **Интерфейс**: модальное окно лестницы испытаний `#factoryMissionsModal` с репликами Рольфа, фильтрами Tier 1–3, отображением статусов и рекордов.
- **Интеграция и регресс**: 142 теста Rust passed, Clippy `-D warnings` чист, Rustfmt чист, Playwright Chromium E2E checks passed (0 errors), сборка release native и WASM.

Подробные отчёты проверок:
- [Run 001: приёмка режима Factory Driver](runs/001-factory-driver/README.md)
- [Рабочий план](PLAN.md)

## Запуск

```powershell
./scripts/build.ps1 -Iteration 011-factory-driver -Config release -Target all
./scripts/launch-viewer.ps1 -Iteration 011-factory-driver -Mode desktop
```

Web-версия доступна через `-Mode web` (порт по умолчанию 8080).
Клавиши:
- F: вход в заезд / режим орбиты
- C: переключение вида камеры
- M: переключение физики (6 DOF / Аркадный прототип)
- H: скрыть/показать HUD приборов
- Кнопка «🏭 Factory»: открывает лестницу миссий Заводского водителя.
