# Run 001: Factory Driver Campaign & Stunt Mechanics Acceptance

## Обзор и цель
Приёмка итерации `011-factory-driver`:
1. Полный перенос всех 34 миссий режима **Factory Driver (Заводской водитель)** из оригинальных файлов `FEData/Data/nfs5.fac` и языковой базы `FEData/Locale/festrings.csv`.
2. Детекторы трюков в реальном времени: занос на 180°, волчок на 360° с ручником, полицейский разворот (J-turn задним ходом), слалом вокруг конусов со штрафами (+2.0с) и контроль порога повреждений кузова.
3. Система карьерного роста пилота: от Кандидата (Applicant) до Мастера-пилота (Master Ace Driver) Porsche.
4. Наградные автомобили за ключевые этапы, автоматически начисляемые в гараж профиля (`'78 911 Turbo 3.3`, `'73 911 Carrera RS 2.7`, `'99 911 GT3 Factory Edition`).
5. Веб-интерфейс лестницы миссий с репликами шеф-инструктора Рольфа, фильтрами по уровням сложности (Tier 1–3) и карточками статуса (Пройдено / Доступно / Заблокировано).
6. **Устранение дефектов кампании и интерфейса**:
   - **Аутентичный интерфейс брифинга (NFS: Porsche Unleashed)**: тёмно-титановая стилизация, золотые акценты Porsche (`#d4af37`), блок шеф-инструктора Рольфа, карточка характеристик авто (мощность, масса, компоновка, привод), регламент и награда.
   - **Исправление ошибки покупки авто**: мягкая десериализация профиля с авто-дополнением `version: 1`, гарантирующая корректную покупку новых и подержанных авто без сбоев.
   - **Настоящие 3D-модели Porsche в сюжетных заданиях**: метод `set_car_model(...)` динамически загружает геометрию `.crp`, текстуры `.fsh` и физическую симуляцию заданного в миссии спорткара (Boxster, Carrera RS, 993, 996, GT3, 930 Turbo, 356) вместо коробчатой заглушки.
   - **Исправление трассы Canyon на старте Evolution**: фильтрация файлов `fedata/trackart`, гарантирующая загрузку правильных текстур трассы, привязка стартовой решётки к поверхности полотна `road_surface.query(..., 25.0, 50.0)` и выравнивание камеры вдоль касательной трассы.

---

## 1. Автоматизированные тесты (142 теста)
- `nfs_formats`: 35 тестов (включая каталоги `nfs5.fac`, `nfs5.car`, `nfs5.trn`, `nfs5.trk`, `nfs5.prt`).
- `nfs_assets`: 59 тестов + 4 calibration bench + 1 race integration + 1 track physics audit (все 15 трасс).
- `nfs_game`: 21 тест (включая 4 новых теста Factory Driver: детекторы 180°/360°, J-turn в реверсе, непрерывность всех 34 миссий, карьерный рост и награждение автомобилями).
- `porsche_viewer`: 21 тест (управление, физика 6 DOF, аркадный режим, инвариантность знака руля, барьеры).

Результат: **142 passed; 0 failed; 3 ignored (требуют Vulkan GPU)**.

### Линтеры и форматирование
- `cargo clippy --workspace --all-targets -- -D warnings`: **0 warnings**.
- `cargo fmt --check`: **чисто, без расхождений**.
- `node web/ui.test.mjs`: **все проверки интерфейса пройдены**.

---

## 2. Playwright Browser E2E Checks
Выполнена проверка через `verify-browser.cjs` (Chromium):
- `skidpad boot`: загрузка полигона Weissach Skid Pad.
- `sim left headingRight=-0.2531`: управление симулятора влево.
- `sim right headingRight=0.2160`: управление симулятора вправо.
- `arcade left headingRight=-0.2207`: управление аркады влево.
- `arcade right headingRight=0.2104`: управление аркады вправо.
- `drive + simultaneous throttle/steer; speed=63`: совместное ускорение и поворот.
- `Esc restores menu; H hides HUD`: горячие клавиши.
- `alps/car catalog switch; diagnostic panel`: переключение трасс/авто и диагностика.
- `focus release 1 -> -3`: сброс клавиш при потере фокуса.
- `dealership catalog and used market verified without errors`: автосалон и рынок б/у без ошибок.
- `canyon loaded and car grounded at y=109.3`: трасса Canyon загружена, машина на полотне дороги.
- `factory driver mission 0M01 briefing and authentic car model verified`: брифинг миссии с Рольфом и загрузка оригинальной 3D-модели Porsche.

Ошибки страницы и консоли: **0**.

Артефакты скриншотов:
- `web-menu.png`
- `web-drive.png`
- `web-sim-left.png`
- `web-sim-right.png`
- `web-arcade-left.png`
- `web-arcade-right.png`
- `web-hidden-hud.png`
- `web-alps.png`
- `web-car.png`
- `web-dealership.png`
- `web-canyon.png`
- `web-factory-ladder.png`
- `web-factory-briefing.png`
- `web-factory-mission-drive.png`

---

## 3. Нативный бинарник (Windows x86_64)
Скомпилирован release-бинарник `local/builds/011-factory-driver/windows/porsche-viewer.exe`.
Проверены инспекции:
- `native-car.png` (модель Porsche 356_1, 50 геометрических элементов).
- `native-track.png` (трасса skidpad, 180 частей, 6848 полигонов полотна дороги).

---

## Статус
Итерация `011-factory-driver` полностью завершена, верифицирована и готова к коммиту и тегированию.
