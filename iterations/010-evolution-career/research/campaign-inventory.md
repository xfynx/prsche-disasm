# Инвентарь ресурсов кампании и прогрессии

Область: read-only инвентаризация имён файлов и коротких текстовых заголовков в `local/game` (2026-09-23). Бинарные данные не распаковывались и не интерпретировались. Имя файла или UI-метка подтверждает наличие ресурса/ссылки, но не доказывает runtime-семантику.

Связь с общей картой: [docs/roadmap.md](../../../docs/roadmap.md). Следующий исследовательский этап: 006 — карта поведения оригинала и форматы игровых систем; этот инвентарь является входом для него.

## Подтверждённые факты файловой системы

- `local/game/FEData/Factory/`: 36 файлов `.fsh`, имена `0M01`..`0M12`, `1M01`..`1M12`, `2M01`..`2M12`; каждый размером 49 728 байт. Это набор изображений из трёх групп по двенадцать; смысл индексов не подтверждён.
- `local/game/FEData/Chron/`: 183 файла, включая `icons356.fsh`, `icons911.fsh`, `icons914.fsh`, `icons924.fsh`, `iconsRace.fsh` и множество `.fsh` с префиксами `MA/MB/MC/MD/ME/p*`. Имена указывают на представление хроники/истории, но не устанавливают граф прогрессии.
- `FEData/Layouts/`: 99 файлов. Релевантные layout: `GameSetup.lay`, `careerfirst.lay`, `factorydriver.lay`, `FactoryVictory.lay`, `levelvictory.lay`, `levelbadge.lay`, `QuickRace.lay`, `knockout.lay`, `locationsetup.lay`, `prerace.lay`, `firstlicense.lay`.
- `GameSetup.lay` содержит callbacks `SETTYPECAREERMODE` и `SETTYPEFACTORYDRIVER`, маршруты к destinations `chronicle` и `singleplayer`. `factorydriver.lay` использует room `ID_FACTORY`, callback list `ID_FACTORYCBL` и accessors `FactoryDriver.Car`/`zMergedList.Car`.
- `FactoryVictory.lay` ссылается на `FactoryDriverPrize`, `FDPrizeCars.Car`, callback `ACCEPTPRIZECAR`, затем destination `levelvictory`. `levelvictory.lay` читает `Factory.Data(NARRNAME)` и `Factory.Data(ENDOFLEVEL)`.
- `QuickRace.lay` предоставляет `Track1.Track`, `Game.NumOpponents` и `zMergedList.Car`; `knockout.lay` — `Game.NumKOOpponents` и маршрут к `locationsetup`. `locationsetup.lay` читает номер/имя трассы, круги, traffic, direction и record time knockout.
- `FEData/Locale/festrings.csv` содержит 70 строк с тегом `!tournamentnames`, включая Classic/Golden/Modern Tournament 1–6 и описания событий. Есть 33 строки с тегом `!factoryDriverText` и `title`: Applying Test, слаломы, доставки, Capture the Flag, повышения, командные гонки и Porsche Commercial.
- В locale help text присутствуют `Factory Driver`, `Play a quick race`, `Play a single race`, `Specify Tournaments or Club Events` и `Progress in the role as a Porsche Factory Driver`. Один popup сообщает, что после завершения Factory Driver для повторной игры нужен новый character.
- `GameData/Simulation/` содержит 88 `.sim`, 22 `.ais`, 6 `.csv`, а также `AI/TRAFCFG.DES`, `AI/TRAFCFG.DAT` и шесть `.BIN`. В `Simulation/CarData` есть гоночные варианты (`GT1race.sim`, `GT2race.sim`, `GT3race.sim`, `550Arace.sim`, `935race.sim`) и simulation-файлы серийных машин. Заголовки AI CSV явно описывают personality, scripts, spread и `Caravan Details, and Single Race Multipliers`.
- `GameData/Track/` содержит по 15 файлов `.map`, `.jnc`, `.env`, `.edg`, `.dtx`, а также соответствующие audio scene вроде `*_audio.scn`; это инвентарь входов трасс/runtime, а не доказательство назначений кампании.
- `local/game/savedata/` содержит `0xfynx.sav` (149 876 байт), `XXDefXX.sav` (147 684), `nfs5.trk` (17 880), `replay.rpl` (118 312), две пары HUD, `player.lst` (6 байт) и `pic16.fsh`. ASCII-скан обоих `.sav` выявляет повторяющиеся маркеры `Tournament`, `Player`, `Track`, `Car`; `nfs5.trk` — повторяющийся `Car`; offsets полей не установлены.
- `fe.txt` — key/value runtime-конфигурация. Наблюдаются `track_name=coastal`, `race_type=0`, `num_laps=1`, `numplayerracecars=1`, `numopponentracecars=0`, `tournament_mult=65536`, уровни аудио и поля transmission/upgrade/colour автомобиля. `properties.txt` называет channel `Need For Speed 5`.

## Гипотезы (требуют доказательства)

- Нумерация `FEData/Factory` может соответствовать уровням/миссиям Factory Driver; одинаковый размер и имена не доказывают порядок или правила открытия.
- `Factory.Data(ENDOFLEVEL)`, `FactoryDriverPrize` и `FDPrizeCars` вероятно участвуют в состоянии повышения/награды, но их хранение и переходы неизвестны.
- ASCII-маркеры `.sav` указывают на структурированные записи состояния кампании/заезда; порядок маркеров, версия, checksum и изменяемые поля не доказаны.
- `FEData/Chron` может обслуживать Chronicle timeline и исторический контент машин; префиксы ресурсов не доказывают связь с прогрессией кампании.

## Следующий исследовательский шаг 006

1. Зафиксировать SHA-256 и диапазоны байт для копий `0xfynx.sav`/`XXDefXX.sav` в `local/experiments`, затем сопоставить поля относительно маркеров через контролируемые различия сохранений.
2. Проследить FE callbacks/accessors (`SETTYPECAREERMODE`, `SETTYPEFACTORYDRIVER`, `Factory.Data`, `FactoryDriverPrize`) в EXE и связать их с offsets сохранений.
3. Найти источник данных для 70 tournament rows и 33 Factory Driver titles; подтвердить связи mission–track–car runtime-ссылками, а не именами.
4. После установления границ состояния декодировать только необходимые `Factory/*.fsh`, Chronicle и релевантные simulation/AI записи.
