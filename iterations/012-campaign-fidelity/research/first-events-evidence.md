# Доказательная база первых событий карьер NFS 5

Дата: 2026-09-24. Снимок: `009-game-shell`.
Исследуемые компоненты: `local/game/FEData/Data/`, `local/game/FEData/Locale/festrings.csv`, `local/game/savedata/`.

## 1. Хеши и размеры исследуемых файлов

| Файл | Размер (байт) | SHA-256 |
|------|---------------|---------|
| `FEData/Data/nfs5.fac` | 8 160 | `cbe12353b8082ee5118a09f744697534e48a2cb4f337f3cc84924c5098939529` |
| `FEData/Data/nfs5.trn` | 118 720 | `120fc85a5f176444fc7a08e813936ace91a9d13388d2186f5c1f02b46d77cd58` |
| `FEData/Data/nfs5.car` | 179 632 | `f260608b7d471b84cae22576bc12053dc34fab7047394dc959f898612a75d591` |
| `FEData/Data/nfs5.trk` | 17 880 | `74b77d508c97b83748b9d11dd55805a457716633f71fda6f167006c234a4ff7b` |
| `savedata/XXDefXX.sav` | 147 684 | `be3080e441f1ac8ccda4bddc819a6355cd4578fcb22e80d1354c4b67241546ac` |
| `savedata/0xfynx.sav` | 149 876 | `d87a013af79956e362373583ebce78fcee67de046d63a3c8babcd0137eb81a0a` |

---

## 2. Factory Driver: Первое задание `0M01` («Applying Test»)

### 2.1. Запись в `nfs5.fac`
- Размер записи: 240 байт. Смещение `0x000` в `nfs5.fac`.
- Поле `0x00`: String ID `3001` (Брифинг Рольфа: «So, you want to be part of the Porsche Test Team... Take the Porsche Boxster behind me out to the Weissach Skid Pad and drive around the cones by following the arrows. You must avoid hitting the cones, however...»).
- Поле `0x20`: Лимит времени = **32 секунды** (`32` u32).
- Поле `0x40`: ASCII код миссии: `0M01\0`.
- Поле `0x58`: String ID `3005` (Pass HUD / Поздравление: «Hey there, welcome to the team. I’m Rolf and I'm the Test Driving Supervisor for the Porsche Test Team...»).
- Поле `0x64`: String ID `3010` (Fail HUD / Отказ: «I’m sorry, my young friend, but you just don’t have the skills we require. Come and see me again when you’ve got a bit more experience...»).
- Поле `0x72`: ID трассы: `13` (0x000d), соответствует `skidpad` в `nfs5.trk`.
- Автомобиль: `Porsche Boxster` (модель `boxster`, sim `boxster`, 2.5L).

### 2.2. Правила миссии
- **Условие победы (Pass)**: Финиш за время $\le 32.0$ с.
- **Условие поражения (Fail)**: Превышение лимита времени $> 32.0$ с.
- **Награда за успех**: Допуск в команду завода, разблокировка Класса 1 (Junior Test Driver) и следующей миссии `1m01` («Simple Slalom»).
- **Действие при провале**: Возможность повтора миссии. Награда не начисляется, прогресс не продвигается.

---

## 3. Evolution: Первый турнир «356 Challenge»

### 3.1. Структура `nfs5.trn`
- Всего записей: 35 турниров по **3 392 байта** ($35 \times 3392 = 118\,720$ байт).
- Первый турнир (смещение `0x000`): **Classic Tournament 1: 356 Challenge**.
  - `0x020`: String ID `2000` («356»).
  - `0x024`: String ID `2018` («356 Challenge»).
  - `0x028`: String ID `2036` («A challenge for the new driver. A quick tournament showcasing Porsche's flagship sports car: the 356.»).
  - `0x39c`: Количество этапов/гонок: **2 заезда**.
  - `0x3c8`: Вступительный взнос (Entry fee): **750 кредитов**.

### 3.2. Этапы турнира
- **Этап 1** (смещение `0x3a0`):
  - ID трассы: `14` (`canyon`).
  - Призовой фонд (места 1–8): **4500, 3500, 3000, 2500, 2000, 1500, 1000, 500** кредитов.
- **Этап 2** (смещение `0x444`):
  - ID трассы: `8` (`monaco1`).
  - Призовой фонд: **4500, 3500, 3000, 2500, 2000, 1500, 1000, 500** кредитов.

### 3.3. Допуск автомобилей и экономика
- Стартовый капитал нового профиля: **11 000 кредитов** (подтверждено `XXDefXX.sav`, секция `PlayerInfo`, offset `0x04`).
- Допустимые автомобили: Классическая линейка 356 (индексы `0..7` в `nfs5.car`, например `'50 356 1100 Coupé Ferdinand` со стоимостью 11 000 кредитов, как подтверждено в `0xfynx.sav`).
- Победа в гонке начисляет призовые 4500 кредитов игроку, увеличивая баланс счета и фиксируя победу в турнире.
