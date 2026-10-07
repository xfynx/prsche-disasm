# v2 Run 005 — файловая очередь оригинала и совместный FE/heap/IO

2026-10-08. В библиотеку добавлены 29 функций C++: 21 файловый consumer и
8 функций списков операций. Все 89 native/x86 сравнений прошли. Проверены
чтение блоками до 0x2000, EOF/short read, отказ чтения, группы и серийные IDs,
сортировка/поиск/удаление, основной/резервный путь и настоящий fe.txt через
восстановленные heap и файловые consumers. Повторные 551 heap и 236 FE
регрессий прошли в отдельных подпапках этого run. Всего 50 проверенных ручных
функций; игровой EXE и байтовое совпадение ещё не получены.

Источник: Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Запрос индекса: FE callees 0x59e040/0x533bf0/0x533de0/0x533da0 →
0x533b90/0x533c20 → requests 0x568aa0/0x568b10/0x568b90/0x568ae0 →
operation allocation/queue/status/completion/callback → списки 0x580730..0x580ec0.
Поиск Win32 imports привёл к disk open/read/seek/close, но их реализации
в этот перенос не входят: [backend-index.json](backend-index.json).

Три косвенные функции отсутствовали в automatic function catalog, хотя
инструкции уже были в листинге: 0x533cd0..0x533d6a, 0x567bf0..0x567c02,
0x5684c0..0x5684d9. Supplementary index
`research/binary-index/manual-functions.jsonl` хранит полные диапазоны,
file offsets, SHA тела и оригинального файла. Байты проверены по PE и
листингу; исходный корпус Run001 не изменён. Каталог теперь имеет 36 587
automatic + 3 supplementary = 36 590 записей; число инструкций прежнее.
Новый manual index не означает автоматическую декомпиляцию этих callbacks.

Исходники: `source/recovered/Porsche.exe/files.cpp`, `io_lists.cpp`;
layout — `source/include/porsche/files.hpp`. Подтверждены IoList 28 байтов,
FileOperation 48, FileDevice 112, PhysicalFile 32, FileReadState 36.
ID содержит device в младших 5 битах; serial увеличивается с маской 24 бита
и пропускает ноль. Ключ сортировки соединяет serial и byte group.
Запросы проходят queued/completed списки; completion возвращает op в pool.
Open возвращает bool в AL, read/close сохраняют исходные значения EAX.
Основной/резервный путь соединяется форматом `%s%s`, без добавления разделителя.
При отсутствии обоих путей выходной handle остаётся прежним.

[verification.json](verification.json) сравнивает returns, выходной buffer,
весь heap, устройства/операции/списки, копии имён, FE stream, global words
и порядок внешних вызовов. Поля code pointers приводятся к исходным VA;
ненулевой stack context read callback приводится к 0x02200200. Байты
неинициализированных полей 0xCC сохраняются. Native и x86 используют одинаковые
фиксированные арены только в стенде. Реальный fe.txt создаёт 23 записи и
188 байтов с терминатором. Это совместная проверка восстановленных компонентов,
а не игровой запуск или визуальная приёмка.

Стенд немедленно исполняет byte-file completion в границе event signal.
Thread worker 0x568530, startdevice 0x568390, wait 0x567f70, события,
диск/архивы и эффекты FE callbacks ещё не восстановлены. Функции
0x56e5f0/0x56e640 — исходные VirtualAlloc/VirtualFree wrappers, а в стенде
временно записываются через bump arena; их page-rounding семантика здесь
не проверена. Locks/CRT formatting/fill/diagnostics — тоже внешние границы.
Проверены обычные read/open/size/close операции, а не все archive opcodes,
fatal diagnostic paths, гонки потоков или изменение locale.

Начальные PE/BSS данные — [globals.json](globals.json). Null-name 0x5e8e50
исходно является zero-filled BSS байтом; дальнейшие FE runtime writers ещё
не перенесены. [source-functions.jsonl](source-functions.jsonl),
[source-calls.jsonl](source-calls.jsonl), [toolchain.json](toolchain.json)
сохраняют источник и фактический MSVC 19.44.35229 / Win32 toolchain.
Точный исходный compiler/CRT/flags не подтверждён.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/v2_manual_index.py
py -3 scripts/research/verify-v2-files.py
py -3 scripts/research/verify-v2-heap.py --report-dir iterations/v2/001-original-recovery/runs/005-original-files/heap-regression
py -3 scripts/research/verify-v2-fe-stream.py --report-dir iterations/v2/001-original-recovery/runs/005-original-files/fe-regression
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
py -3 scripts/research/trace-v2-startup.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
```

Следующий конкретный пакет: 0x56e5f0/0x56e640 → device init 0x568390
и worker 0x568530 → disk dispatch 0x5919a0/0x591df0/0x592140/0x592290,
archive 0x568900. Сначала дополнить индекс пропущенного worker и проследить
реальные caller/callee контракты. Затем заменить соответствующие границы
стенда и повторить совместный FE/heap/IO с исходным scheduler/backend.
Привязка к startup 0x4b6a50 и игровой цикл остаются дальнейшей задачей.
Исполнители завершили поручения; остаток принадлежит координатору.
