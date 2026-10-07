# v2 Run 003 — исходный FE поток на C++

2026-10-08. В библиотеку `porsche_original.lib` включён связный участок:
текстовые файлы и аргументы запуска → бинарные FE записи → применение записей.
Девять новых функций на C++, 236 сравнений с неизменёнными инструкциями
оригинала прошли. Вместе с Run 002 — десять проверенных ручных функций.
Игрового EXE, байтовых совпадений и восстановленных целых модулей пока нет.

Источник: Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Запросы индекса: `FE_Data_Stream`, `fe.txt`, вход `0x4b6660`, его callees и
consumers `0x4b4b80/0x4b4cd0`. Индекс:
`research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d`; полный корпус —
`research/v2/binaries/Porsche.exe-ddd748fdbe6d`.

Восстановлены `0x4b51e0` (токен), `0x4b5250` (значение), `0x4b5430` (действие),
`0x4b5470` (присваивание), `0x4b5ee0` (файл), `0x4b60d0` (аргументы),
`0x4b6660` (создание потока), `0x4b4b80` (применение), `0x4b4cd0` (длина).
Исходник: `source/recovered/Porsche.exe/fe_stream.cpp`; ABI: cdecl/x86.
Границы функций: [source-functions.jsonl](source-functions.jsonl);
исходные callers/callees: [source-calls.jsonl](source-calls.jsonl).

Типизированные таблицы экспортированы из PE с проверкой SHA: definitions
`0x5d1e40` (48), values `0x5d63a0` (144), actions `0x5cc5c8` (7), имена машин
`0x5d61e8` (53); количества включают терминаторы. Целевые поля — реальные
C++ глобальные слова с идентичностью исходного VA. Таблицы и исходные значения:
[tables.json](tables.json), `source/recovered/Porsche.exe/fe_tables.inc`.
Ресурсы: [resource-inventory.json](resource-inventory.json).

Настоящий `local/game/fe.txt`: 13 805 байтов, SHA256
`3b00d768c85bb26100a27adfd419b6c32fd1572e6ef5d7d29da2a9b4f250a8ec`.
Он создаёт 23 записи / 47 слов с терминатором (188 байтов); с проверяемыми
аргументами NUMCARS=8, numopponentracecars=7, FE=0 — 25 записей / 204 байта.
Неизвестные ключи игнорируются по исходной таблице. Необычная ветка `#`
изменяет один байт циклом, а не пропускает обычный комментарий; пустой файл
не закрывает handle. Обе особенности сохранены по дизассемблеру и replay.

Проверены числовой разбор/переполнение/143 именованные константы, вложенные
`@`/IMPORT, порядок аргументов, отсутствующие/пустые файлы, токены/усечения,
скалярные, строковые, векторные, индексные записи и действия. Дополнительные
таблицы X менялись только в памяти стендов для проверки общих веток формата,
которых нет среди имён исходной таблицы; в игровой исходник они не входят.

Сверялись поток и длины всех записей, globals, action state, целиком индексные
буферы, изменённые file buffers, порядок/аргументы file/heap/callback вызовов.
Стек cdecl проверялся при исполнении x86. [verification.json](verification.json)
содержит все входы, хеши результатов, SHA исходников и native probe.

Границы: IO `0x59e040/0x533de0/0x533bf0/0x533da0`, heap
`0x531ca0/0x531f90/0x569640`, callbacks `0x411b40/0x4119e0/0x411a80` записывают
вызовы только в стенде. Эти callees не восстановлены и остаются extern в
библиотеке. Оригинальный CRT compare `0x5ae3c0` исполнялся в C locale;
native стенд использует равенство ASCII без учёта регистра. Смена locale,
реальный heap/VFS и эффекты callbacks этим результатом не подтверждены.

Сборка: современный MSVC 19.44.35229, CMake Win32, C++17. Исходный compiler,
CRT, flags и точный codegen всё ещё неизвестны. Стенды отделены от библиотеки;
оригинальные инструкции используются только для сравнения и не входят в сборку.

```powershell
py -3 scripts/research/export-v2-fe-tables.py
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/verify-v2-fe-stream.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
py -3 scripts/research/trace-v2-startup.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification --verification-output iterations/v2/001-original-recovery/runs/003-fe-stream/corpus-verification.json
```

Следующий пакет: исходные heap/file службы и их инициализация, затем связь
с `0x4b6a50`. Начать с `0x531ca0` и layout/flags выделения FE stream.
Владелец — координатор, поручения исполнителям завершены. Run 001–002 сохраняют
исторические проверки; текущий полный инвентарь — [corpus-verification.json](corpus-verification.json).
