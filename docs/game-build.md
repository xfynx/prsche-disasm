# Исходная сборка игры

## Проверенные факты

- Источник: установленный каталог, указанный пользователем. Из него только читаем.
- `local/game` — сверенная исходная копия; 1742 файла, 599126359 байт.
- Полный список, размеры и SHA-256: [game-manifest.json](game-manifest.json).
- `version.txt` содержит `3.5`.
- `nfs5.exe`: FileVersion `2019.06.21.027`, описание `Need For Speed: Porsche Unleashed Patch`.
- `dinput.dll`: Ultimate ASI Loader; `SilentPatchNFS90s.asi`: версия `1.0.1.0`.
- nfs5.ini указывает `ThrashDriver=opengl1`, `Language=english`.
- Основные EXE/DLL — PE32 x86; инвентаризация импортов: [pe-inventory.json](pe-inventory.json).
- `GameData/CarModel/356a.crp`, `.tpg`, `.clr`, `356aD.fsh`, `356aL.fsh` доступны.

## Воспроизведение

```powershell
py scripts/prepare-game.py --source 'C:\Program Files (x86)\by Decepticon\Need for Speed - Porsche Unleashed'
py scripts/inventory-pe.py
```

prepare-game отказывается перезаписывать существующую копию. Манифест отражает
состояние файлов при копировании. Состав установки может изменяться при её
отдельном запуске пользователем; это не изменяет уже сохранённый образец.

## Не установлено

Отсутствие модификаций игровых ресурсов не доказано. Номер 3.5 не идентифицирует
все патчи. Список статических импортов не равен списку реально загруженных DLL;
динамические модули фиксируются отдельно при запуске экспериментальной копии.
