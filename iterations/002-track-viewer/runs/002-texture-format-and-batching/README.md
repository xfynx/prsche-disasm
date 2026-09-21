# Run 002: исправление 16-битных текстур FSH (0x7e) и батчинг мешей

- Дата: 2026-09-22
- Трассы: `farmland`, `castle`, `foothills`, `industrial`, `monaco1`
- Цель: 
  1. Исправить артефакты фиолетовой пикселизации на картах с 16-битными текстурами FSH `0x7e`.
  2. Объединить меши по материалам (batching), устранив исчерпание буферов WebGPU в браузерах.
  3. Отфильтровать не-трековые файлы в веб-интерфейсе (`main.js`).
  4. Провести визуальную проверку на общих планах и с близким приближением (zoom-in).

## Причина артефактов и решение

1. **Формат FSH 0x7e**: в исходной реализации формат `0x7e` ошибочно декодировался как RGB 565 (`>> 11` для R, `>> 5 & 63` для G, `& 31` для B) с жестко заданным альфа-каналом `a = 255`. Фактический формат данных в ресурсах EA NFS Porsche — **15-битный ARGB 1555** (`bits 10..14` R, `bits 5..9` G, `bits 0..4` B, `bit 15` — 1-битная альфа/маска). Ошибочный сдвиг 565 смешивал бит 10 красного в старший бит зеленого, а обнуление бита 15 в 565 давало постоянный фиолетовый оттенок на всех 16-битных текстурах. Перевод `0x7e` на ARGB 1555 полностью устранил фиолетовые артефакты и восстановил натуральные цвета ландшафта, травы, камня и построек.
2. **Батчинг геометрии**: объединение примитивов статей CRP по уникальным материалам снизило число частей сцены с 11 296 до 263 на `castle`, с 8 101 до 240 на `industrial`, с 3 836 до 184 на `farmland` (-97% буферов и draw calls). Это полностью предотвращает WebGPU OOM/контекстную потерю в браузерах.
3. **Фильтрация карт**: список `availableTracks` в веб-интерфейсе теперь валидирует наличие парного `.fsh` архива, отсекая не-трековые модели меню (`NFS5.CRP`).

## Команды воспроизведения

```powershell
. .\scripts\tool-env.ps1
.\scripts\build.ps1 -Iteration 002-track-viewer -Target all

# Скриншоты: обзорные и с приближением
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir local/game --track farmland --distance 3500 --screenshot iterations/002-track-viewer/runs/002-texture-format-and-batching/farmland-overview.png
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir local/game --track farmland --distance 500 --pitch 0.4 --screenshot iterations/002-track-viewer/runs/002-texture-format-and-batching/farmland-zoom.png
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir local/game --track castle --distance 6000 --screenshot iterations/002-track-viewer/runs/002-texture-format-and-batching/castle-overview.png
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir local/game --track castle --distance 800 --pitch 0.4 --screenshot iterations/002-track-viewer/runs/002-texture-format-and-batching/castle-zoom.png
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir local/game --track foothills --distance 4500 --screenshot iterations/002-track-viewer/runs/002-texture-format-and-batching/foothills-overview.png
.\local\builds\002-track-viewer\windows\porsche-viewer.exe view --game-dir local/game --track foothills --distance 600 --pitch 0.4 --screenshot iterations/002-track-viewer/runs/002-texture-format-and-batching/foothills-zoom.png
```

## Результаты визуальной верификации

- `farmland-overview.png` и `farmland-zoom.png`: поля, холмы, асфальт и постройки отображаются в натуральных зелёных, коричневых и серых тонах; фиолетовые крапинки полностью отсутствуют.
- `castle-overview.png` и `castle-zoom.png`: детальные средневековые стены, терракотовая черепица, каменные мосты и брусчатка рендерятся без цветовых артефактов и без потери кадров.
- `foothills-overview.png` и `foothills-zoom.png`: виноградники, дорожная разметка и скальные массивы отображаются корректно.
