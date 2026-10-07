# Восстановленные собираемые исходники

Решение пользователя: сразу C/C++, запуск игры допускается позже. Здесь
обычные исходники с исходными ABI/алгоритмами и привязкой к module/SHA/VA.

- `include/porsche`: проверенные объявления и ABI.
- `recovered/Porsche.exe/startup.cpp`: первый восстановленный переход
  `0x4b6710`, четыре аргумента stdcall; 175 native/x86 сравнений.
- `recovered/Porsche.exe/fe_stream.cpp`: девять cdecl функций чтения конфигурации,
  формирования и применения FE записей; 236 native/x86 сравнений.
- `recovered/Porsche.exe/fe_tables.inc`: типизированные данные из исходного PE,
  повторяемый экспорт `scripts/research/export-v2-fe-tables.py`.
- `recovered/Porsche.exe/heap.cpp`: 11 функций собственного heap и helpers;
  551 сравнение состояния арены после каждой операции. `include/porsche/heap.hpp`
  сохраняет исходный 16-байтовый header и 64-байтовый control block.
- `recovered/functions.json`: реестр ручных функций, зависимостей и свидетельств.
- `recovered/sources.cmake`: явный список исходников библиотеки `porsche_original`.
- `recovered/recovery_probe.cpp`: отдельный консольный стенд; записывающая
  замена пока не восстановленного `0x4b6a50` существует только здесь.
- `recovered/fe_stream_probe.cpp`: отдельный стенд FE; file/heap/callback
  записи и сравнение строк не добавляются в библиотеку оригинала.
- `recovered/heap_probe.cpp`: сравнение полного heap; фиксированная VA арены
  применяется только в стенде, внешние OS/CRT/SIMD вызовы записываются.
- `recovered/Porsche.exe/files.cpp`, `io_lists.cpp`: 29 функций запросов,
  очередей, completion и чтения блоками; layout в `include/porsche/files.hpp`.
- `recovered/files_probe.cpp`: 89 совместных FE/heap/IO сравнений с x86;
  immediate worker, disk/VirtualAlloc/OS endpoints находятся только в стенде.
- `catalog`: адресный каталог всех модулей и функций, байтовые диапазоны
  псевдо-C, пути данных/листингов/вызовов/импортов и статусы восстановления.

Автоматический Ghidra псевдо-C остаётся в `research/v2/binaries`; каталог
не добавляет его в сборку. Типы/сигнатуры Ghidra — материал для проверки.
Извлечь одну функцию для следующего переноса:

```powershell
py -3 scripts/research/structure-v2.py
py -3 scripts/research/structure-v2.py --extract Porsche.exe --address 0x59e040 --output local/experiments/v2-files/0059e040.c
```

`porsche_original.lib` содержит восстановленные объекты и ещё имеет
неразрешённые зависимости; это не готовая игра. 50 функций проверены в
зафиксированных границах стендов. Это не подтверждает UI, физику, main loop,
внешние OS/CRT/SIMD/disk/thread callees или байтовое совпадение EXE. Актуальные
совместные свидетельства и регрессии — runs/005-original-files;
Run 001–004 сохраняют состояние своих checkpoint. Три supplementary callbacks
без pseudo-C доступны через SHA-проверяемый manual index; каталог имеет
36 590 записей. Извлечение pseudo-C для этих трёх функций недоступно.
