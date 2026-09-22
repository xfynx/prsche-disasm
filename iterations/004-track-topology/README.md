# 004-track-topology

Статус: завершена и проверена (тег снимка: `iteration-004`).

Снимок создан из `iteration-003`. Игровые ресурсы читаются исключительно из общего read-only каталога `local/game` в корне репозитория.

## Цели и результаты итерации

1. **Топология трассы и дорожные сплайны**:
   - Восстановлены и специфицированы бинарные структуры соединений и развилок дорог (`.jnc`, 36 байт/запись) и границ дорожного полотна (`.edg`, 28 байт/запись), а также карты секций (`.map`).
   - Разработаны надёжные парсеры в `crates/nfs-formats/src/topology.rs`, валидирующие все 15 трасс игры без сбоев.
   - В `crates/nfs-assets/src/track_loader.rs` реализована сборка непрерывных полилиний границ (`TrackTopology`, `TopologyLine`).
   - В `crates/porsche-viewer` интегрирован конвейер рендеринга линий `TopologyRenderer` с защитой от z-fighting (`clip_pos.z - 0.0004 * clip_pos.w`) и хоткеем `T` / чекбоксом «3D Границы».
2. **Аркадная навигация по трассе на спорткаре (Arcade Car Navigation)**:
   - Стилизованная процедурная 3D-модель спорткара Porsche (`crates/porsche-viewer/src/car_mesh.rs`) с 6 вариантами заводских цветов (хоткей `P`).
   - Аркадная физика автомобиля (`crates/porsche-viewer/src/arcade.rs`): разгон, торможение, динамический угол поворота колёс, ручной тормоз с заносом (Space), расчёт передачи (`1..5`, `R`, `N`) и оборотов двигателя (шкала RPM).
   - Сэмплирование рельефа полотна (`sample_road_elevation_from_edges`): кузов автоматически отслеживает высоту дороги, продольный уклон (pitch) и виражи (roll), а также удерживается в границах дороги отскоком от кромок `.edg`.
   - Динамическая камера преследования от 3-го лица с плавной интерполяцией и сменой видов по клавише `C` (Chase / Bumper / Free).
   - Гоночный стеклянный HUD в браузере (спидометр в км/ч, тахометр, передача, подсказки управления). В нативном режиме статус выводится в заголовок окна.
3. **Автоподгрузка ресурсов из local/game в веб-версии**:
   - Локальный сервер `scripts/serve-web.py` безопасно отдаёт ресурсы `local/game` в режиме read-only (`/game/...`) и предоставляет список файлов через эндпоинт `/api/game-files`.
   - Веб-версия автоматически сканирует каталог, делая доступными все 15 трасс и 24 авто в один клик без ручного ввода/стирания, и сразу загружает `skidpad`.
   - Сохранена возможность загрузки внешних/пользовательских файлов («Папка игры», «Файлы») для переопределения с кнопкой быстрого сброса обратно к `local/game`.
4. **Сохранение исследовательских утилит**:
   - Все Python-скрипты реверса и зонды перенесены из `local/research/` в версионируемую директорию `scripts/research/`.

---

## 🚀 Инструкция по запуску

### 1. Веб-версия (Web / WebGPU)

1. **Собрать веб-пакет** (если ещё не собран):
   ```powershell
   . .\scripts\tool-env.ps1
   .\scripts\build.ps1 -Iteration 004-track-topology -Config release -Target web
   ```
2. **Запустить локальный сервер**:
   ```powershell
   py -3 scripts/serve-web.py --iteration 004-track-topology --port 8000
   ```
3. **Открыть в браузере**:
   Перейдите по адресу [http://127.0.0.1:8000/](http://127.0.0.1:8000/) в Google Chrome или Microsoft Edge (требуется поддержка WebGPU).
   - Трасса `skidpad` со спорткаром загрузится автоматически.
   - Переключайте трассы и авто через выпадающий список `Трасса` / `Авто`.
   - Нажмите **«Заезд (F)»** для включения аркадного вождения спорткара с гоночным HUD.

---

### 2. Десктоп-версия (Desktop / Native Windows)

1. **Собрать нативный бинарник** (если ещё не собран):
   ```powershell
   . .\scripts\tool-env.ps1
   .\scripts\build.ps1 -Iteration 004-track-topology -Config release -Target native
   ```
2. **Запуск просмотра трассы со спорткаром**:
   ```powershell
   # Запуск трека Skidpad
   .\local\builds\004-track-topology\windows\porsche-viewer.exe view --game-dir .\local\game --track skidpad

   # Запуск других трасс (alps, autobahn, canyon, castle, monaco1 и др.)
   .\local\builds\004-track-topology\windows\porsche-viewer.exe view --game-dir .\local\game --track alps
   ```
3. **Запуск просмотра автомобиля**:
   ```powershell
   # Запуск модели 356a (или 911, 930, 993, 996, boxster и др.)
   .\local\builds\004-track-topology\windows\porsche-viewer.exe view --game-dir .\local\game --car 356a
   ```
4. **Консольная инспекция ресурсов**:
   ```powershell
   .\local\builds\004-track-topology\windows\porsche-viewer.exe inspect --game-dir .\local\game --track skidpad
   ```

---

## 🎮 Управление и горячие клавиши

| Клавиша | Режим заезда на авто (`F`) | Режим свободной камеры / орбиты |
|---|---|---|
| `F` | Выход в режим орбиты | Вход в режим заезда на автомобиле |
| `W` / `▲` | Газ (ускорение) | Движение камеры вперёд |
| `S` / `▼` | Тормоз / Задний ход | Движение камеры назад |
| `A` / `D` | Поворот колёс влево / вправо | Смещение камеры влево / вправо |
| `Space` | Ручной тормоз (занос) | — |
| `C` | Смена вида: Сзади / Капот / Свободный | Смена цвета кузова авто (в режиме Car) |
| `P` | Смена цвета кузова авто | — |
| `R` | Возврат машины на дорожное полотно | Сброс камеры к исходной позиции |
| `T` | Включение / выключение 3D линий границ полотна | Включение / выключение 3D линий границ |
| `Shift` (удержание) | — | Ускорение перемещения камеры (x2.5) |
| `ЛКМ` + перемещение | Вращение камеры вокруг авто | Вращение камеры вокруг центра |
| `ПКМ` + перемещение | Панорамирование | Панорамирование |
| `Колёсико мыши` | Масштаб / дистанция камеры | Приближение / удаление |

---

## 🧪 Проверка и верификация

Все команды выполняются из корня репозитория:

```powershell
. .\scripts\tool-env.ps1

# Проверка форматирования
cargo fmt --manifest-path iterations/004-track-topology/Cargo.toml --all -- --check

# Статический анализ Clippy (0 предупреждений)
cargo clippy --manifest-path iterations/004-track-topology/Cargo.toml --target-dir local/builds/004-track-topology/.cargo-target --all-targets -- -D warnings

# Полный набор тестов (52 теста)
cargo test --manifest-path iterations/004-track-topology/Cargo.toml --target-dir local/builds/004-track-topology/.cargo-target

# Полная сборка релизных версий native + web
.\scripts\build.ps1 -Iteration 004-track-topology -Config release -Target all
```

Визуальные результаты приёмки сохранены в [`runs/001-topology-verification/README.md`](runs/001-topology-verification/README.md).
