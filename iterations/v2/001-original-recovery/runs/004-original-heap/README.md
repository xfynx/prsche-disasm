# v2 Run 004 — собственный allocator оригинала на C++

2026-10-08. В `porsche_original.lib` восстановлены 11 функций создания heap,
выделения, освобождения, resize и служебных данных. Все 551 сравнение с
оригинальным x86 прошли: сверялась вся арена после каждой операции, returns
и внешние вызовы. Повторные 236 FE регрессий прошли после уточнения ABI free.
Всего в v2 — 21 проверенная ручная функция, 0 байтовых совпадений/модулей.
Игровой EXE и визуальная приёмка остаются открытыми.

Источник: Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Поиск: FE callees `0x531ca0/0x531f90/0x569640` → их callers/callees →
ссылки таблицы heaps `0x6b4f20` → constructor `0x5697f0`, wrapper `0x5aef80`.
Индекс — `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d`, исходные
инструкции/псевдо-C — `research/v2/binaries/Porsche.exe-ddd748fdbe6d`.

Новые C++ функции: `0x531c60`, `0x531ca0`, `0x531f90`, `0x5320b0`,
`0x5323e0`, `0x556620`, `0x556650`, `0x569640`, `0x5697f0`, `0x56e2c0`,
`0x5b0000`. [source-functions.jsonl](source-functions.jsonl),
[source-calls.jsonl](source-calls.jsonl),
[heap-table-references.jsonl](heap-table-references.jsonl).
Исходник — `source/recovered/Porsche.exe/heap.cpp`, объявления и layout —
`source/include/porsche/heap.hpp`.

Подтверждён механизм оригинала: 16-byte physical header, 64-byte heap control,
свободный кольцевой список и magic/flags. `0x10` выделяет с верхнего конца;
`0x20` выбирает самый большой подходящий блок. Split выполняется при остатке
строго больше `0x40`; free сливает физические свободные соседи и возвращает 1.
Resize сохраняет адрес, присоединяет соседний свободный блок, переносит
suffix/name и ограничивает запрос доступным местом; `-1` запрашивает максимум.
Нестандартные адреса split и изменения links сохранены по инструкциям,
без исправления предполагаемых ошибок оригинала. Default copy работает вперёд
по 4/2/1 байту, это не memmove при перекрытии.

Начальные значения globals проверены по PE: [globals.json](globals.json).
`0x5deb10` равен 1; остальные переключатели копирования равны 0.
Проверены quantum 4/8/16/32, выравнивание арены 16..256, направления и выбор
блока, нехватка памяти/повтор попытки, отрицательный/малый размер, точные
границы split, разные heap slots, фрагментация/порядки free, guard/name/suffix,
resize, endian helper, выравнивание/перекрытие default copy и routing всех
веток copy dispatch. Есть последовательность исходных FE запросов: stream
32 KiB с флагом 0x10, временный настоящий fe.txt, free файла и resize до 188.
Эта последовательность проверяет heap; исполнение FE parser с ним вместе
ещё не является частью этого результата.

[verification.json](verification.json) содержит 551 вход, хеши результатов,
SHA исходников и стенда. Сравнивается полная память после каждого шага,
включая заголовки/списки/пользовательские bytes/метаданные. Original x86
исполняется без изменения инструкций, cdecl stack/exit проверяется.
Фиксированная VA `0x03000000` служит только для сравнения указателей в стенде;
allocator принимает обычный адрес арены и не зависит от этой VA в библиотеке.

Внешние границы: `0x5322b0/0x5322c0/0x5321f0` — записанный lifecycle locks;
`0x5a0fbf` — только используемые `%s LOW/HIGH`, `0x53c290` — zero fill;
`0x5b0100/0x5b02c0/0x5b0480` — запись выбора SIMD target и fixture copy.
Эффекты этих оригинальных callees не восстановлены. Callback `0x69cb00`
проверен с записью и ответом 0 либо повтором один раз; его реальные producers
и эффекты остаются открытыми. Многопоточная работа не проверялась.

Декларация FE free уточнена: оригинал возвращает 1. Старые проверки не
переписаны; текущие SHA и 236 повторных случаев —
[fe-regression/verification.json](fe-regression/verification.json).
FE standalone probe сохраняет записывающие heap endpoints; в библиотеке
allocate/free/resize разрешаются в восстановленный heap object. Совместный
FE/heap/file прогон остаётся следующим этапом после восстановления IO.

Сборка MSVC 19.44.35229 / Win32: [toolchain.json](toolchain.json).
Это доступный современный compiler, исходный compiler/CRT/flags и exact
codegen всё ещё неизвестны. Оригинальные инструкции не входят в сборку.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/verify-v2-heap.py
py -3 scripts/research/verify-v2-fe-stream.py --report-dir iterations/v2/001-original-recovery/runs/004-original-heap/fe-regression
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
py -3 scripts/research/trace-v2-startup.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification --verification-output iterations/v2/001-original-recovery/runs/004-original-heap/corpus-verification.json
```

Следующий пакет — исходные файловые службы FE, группы handles и completion
callbacks: `0x59e040/0x533c20`, `0x568b90/0x568ae0/0x568b10`,
`0x567f70/0x567df0`. Затем совместный FE/heap/IO и binding startup `0x4b6a50`.
Владелец — координатор; стенд исполнителя heap_probe принят, поручений нет.
Текущий инвентарь: [corpus-verification.json](corpus-verification.json).
