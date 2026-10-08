# v2 Run 006 — исходные page wrappers и инициализация файлового устройства

2026-10-08. Добавлены 6 проверенных C++ функций: 0x56e5f0/0x56e640,
0x580630/0x580670/0x580680 и 0x568390. Все 474 native/x86 сравнения прошли;
89 совместных FE/heap/IO случаев повторены с реальными page wrappers.
Всего 56 проверенных ручных функций. Игрового EXE, полного scheduler/backend
и byte matches пока нет. Run005 сохранён в checkpoint 6e9f849.

Источник: Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Поиск индекса: operation_name 0x5684e0 → allocation/free 0x56e5f0/0x56e640
→ GetSystemInfo/VirtualAlloc/VirtualFree imports; operation_allocate 0x5682a0
→ startdevice 0x568390 → list constructors 0x580630/0x580680 →
default key 0x580670 и косвенный worker 0x568530.
Функции/вызовы: [source-functions.jsonl](source-functions.jsonl),
[source-calls.jsonl](source-calls.jsonl), [worker-index.json](worker-index.json).

В `file_pages.cpp` сохранена исходная арифметика: page size кешируется в
0x6a6418, `(size + page - 1)` сначала переполняется как 32-bit LEA, затем
выполняется signed IDIV и сохраняется младшее слово IMUL. Размер переписывается
до вызова VirtualAlloc(nullptr, size, 0x3000, 4). Free вызывает
VirtualFree(pointer, 0, 0x8000) и возвращает исходный EAX. Проверены ноль,
границы страницы, переход через INT_MAX/UINT_MAX, cached/uncached состояние,
возвращённые null/pointer и значения VirtualFree. Нестандартные page sizes
использованы только как синтетические входы арифметики.

В `file_device.cpp` восстановлены собственный lock списка (flags 2), общий
lock второго списка (flags 0), key по адресу node и startdevice. Последний
создаёт queued/completed списки, два события и отдельный lock, задаёт serial 1
и priority field 0xff, запускает worker, затем ждёт/reset событие и снимает
lock free-op pool. При отказе thread start сохранены исходная diagnostic
строка и line 0xb4. Проверены устройства 0/1/15/31, уже initialized,
успех/отказ/ненулевой return, повторный вызов и пользовательский/default key.

[verification.json](verification.json) сравнивает всю device/list арену,
page cache/size, returns и порядок вызовов. Code pointers нормализуются к
исходным VA; фиктивные globals/арена существуют только в device_probe.
Thread boundary поставляет лишь запись initialized=1, подтверждённую первой
инструкцией worker 0x56854b. Worker loop, реальные потоки, ожидание, события,
lock implementation и diagnostic effects здесь не исполняются.

[files-regression/verification.json](files-regression/verification.json)
повторяет 89 случаев Run005 с настоящими C++ 0x56e5f0/0x56e640. Записывающая
граница перенесена на сами Win32 imports; округление больше не подменяется
fixture allocator. Native и x86 получают одинаковый page size и контролируемую
нулевую память. Immediate worker, raw disk/archive, реальный OS lifetime,
ошибки/гонки VirtualAlloc и эффекты FE callbacks всё ещё открыты.
Регрессии 551 heap и 236 FE из Run005 остаются актуальны: их исходники/ABI
не изменялись, инвентарь проверил SHA зависимостей.

Manual index дополнен worker 0x568530..0x5688cc (925 байтов, два RET) и
key 0x580670..0x580674 (5 байтов). Все байты и диапазоны SHA-проверены;
worker пока только проиндексирован, в число восстановленных функций не входит.
Каталог: 36 587 automatic + 5 supplementary = 36 592 записей.
Jump table worker 0x5688d0, opcodes 0..10 и callback [operation+0x20]
сохранены как точка следующего восстановления, без догадок о backend.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/v2_manual_index.py
py -3 scripts/research/verify-v2-file-device.py
py -3 scripts/research/verify-v2-files.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
py -3 scripts/research/trace-v2-startup.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
```

MSVC 19.44.35229 / Win32: [toolchain.json](toolchain.json); исходный
compiler/CRT/flags не подтверждён. Следующий конкретный шаг: экспортировать
11 ячеек jump table 0x5688d0, проследить opcode consumers 0x568530 и
dispatch 0x568900; восстановить worker/control/completion по всем ветвям.
Затем thread trampoline 0x55f4f0, thread start 0x55f5f0, wait/events и
disk open/read/seek/close 0x5919a0/0x591df0/0x592140/0x592290.
Инициализация файловой системы и привязка к startup остаются открытыми.
Поручения исполнителей завершены; владелец остатка — координатор.
