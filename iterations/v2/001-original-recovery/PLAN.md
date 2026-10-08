# v2 / 001 — план восстановления исходного кода

Решение пользователя 2026-10-08: сохранить v1 как есть, получить полный
дизассемблированный/декомпилированный корпус и восстановить собираемый оригинал.
Владелец — координатор. Run 006 завершён: page wrappers, list/device startup
и общий FE/heap/IO сверены с x86. Поручения исполнителей приняты;
активных поручений нет. Игровой EXE и критерии всей итерации ещё открыты.

## Цель и готовность 001

Все бинарники `local/game` имеют SHA, архитектуру и отдельный каталог корпуса.
Все обнаруженные Ghidra инструкции и функции экспортированы. Каждая функция
проходит попытку декомпиляции с результатом/ошибкой. Непроанализированные
исполняемые байты и неразрешённые связи явно учтены. Результат воспроизводим
из неизменяемых входов. Число восстановленных/совпавших функций не смешивается
с числом автоматически экспортированных функций.

## Дальнейшие этапы v2

1. Полный корпус, данные, зависимости и список пропусков.
2. Определение семейства/версии компилятора, CRT, ключей, layout и ABI;
   первый обычный исходник компилируется с совпадением машинного кода.
3. Восстановление деклараций, глобальных данных, классов/vtables и модулей
   в полном графе программы. Ручной исходник остаётся привязан к SHA/VA.
4. Полная native Windows/x86 сборка с исходными карьерой, физикой, ИИ,
   экономикой, повреждениями, UI и звуком. Сверка функций/данных/модулей,
   реальная езда и прохождение. Неопределённая логика не заменяется заглушкой.
5. Современная платформенная адаптация после рабочего оригинального baseline;
   перенос native/web не меняет игровую семантику.

## Подтверждённое

- v1 checkpoint `dc6b9d8`, запушен; 012 не завершена.
- Прежний индекс: 26 путей, 25 уникальных хешей; 24 уникальных PE,
  36 510 функций, 2 825 280 инструкций. Один NE не покрыт PE-анализом.
- Ghidra 12.1.3 содержит NeLoader; его отдельный импорт возможен.
- Porsche.exe SHA ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39,
  PE linker 6.0, Visual C++ runtime строка VA 0x5c1e5c.
- SpaceRangersHD_decomp документирует recovered Delphi + whole-EXE SHA
  verification; это образец методики, не перенос его компилятора в Porsche.

## Гипотезы и неизвестное

MSVC-era происхождение вероятно; точный компилятор, CRT и параметры неизвестны.
Ghidra autoanalysis не гарантирует полноту границ, косвенных целей или типов.
Псевдо-C не собирается автоматически. Издательские модули/патчи/установщики
учитываются полностью, но их необходимость для игрового baseline ещё выясняется.

## Выполнено в Run 002

Run 001: полный корпус 24 PE + 1 NE, 36 587 функций / 2 827 310 инструкций;
36 583 псевдо-C, 4 failed/timeout, 5639 функций с предупреждениями,
3 199 385 unclassified executable bytes. Porsche.exe: 5772/5772 псевдо-C.

Выбор пользователя: сразу C/C++, первый запуск игры может быть позже.
Созданы source/include, source/recovered/<module>, полный адресный каталог
25 модулей / 36 587 функций и отдельная сборка porsche_original.lib/probe.
Переход 0x4b6710..0x4b67a4 восстановлен с четырьмя stdcall аргументами;
175 C++/x86 случаев совпали. Неизвестный 0x4b6a50 — записывающая граница только
в тестовом probe. 1 проверенная ручная функция, 0 байтовых совпадений/модулей.
Startup: четыре стадии, 3093 статически достижимые функции; косвенные
цели и пропуски открыты. Полный отчёт: runs/002-cpp-startup.

## Выполнено в Run 003

Найден реальный fe.txt (13 805 байтов), экспортированы
48 definitions / 144 values / 7 actions (с терминаторами), 53 имени машин,
42 исходных global words. C++ producer/file/arguments/dispatcher включён
в библиотеку; все 236 случаев совпали с оригинальным x86. Сравнены поток,
длины записей, глобальные поля, buffers, callbacks и порядок file/heap вызовов.
Реальный fe.txt даёт 23 записи / 47 слов с терминатором (188 байтов), аргументы
поверх него — 25 записей / 51 слово. Indexed/string/vector/action ветки
проверены отдельными таблицами только в памяти стенда; оригинальные таблицы
в библиотеке не заменялись. Нестандартная обработка # и empty-file ветка
сохранены по инструкциям оригинала.

Запрос индекса: FE_Data_Stream/fe.txt → callers/callees 0x4b6660/0x4b5ee0/
0x4b60d0 → assignment/token/value/action 0x4b5470/0x4b51e0/0x4b5250/0x4b5430
→ dispatch/record length 0x4b4b80/0x4b4cd0. Porsche.exe SHA указан выше.
Типизированные таблицы: 0x5d1e40/0x5d63a0/0x5cc5c8/0x5d61e8.
Свидетельства и команды: runs/003-fe-stream/README.md, verification.json,
tables.json, source-functions.jsonl, source-calls.jsonl.

Итого 10 проверенных ручных функций, 0 байтовых совпадений/целых модулей.
Неизвестные file/heap/callback callees остаются extern в библиотеке. Их
записывающие замены находятся только в fe_stream_probe; оригинальный CRT
compare исполнен в C locale, native стенд проверяет равенство ASCII строк.
Это не восстановление эффектов callbacks, VFS, allocator или смены locale.
Реальный игровой запуск и визуальная приёмка открыты.

## Выполнено в Run 004

Восстановлены 11 функций собственного heap: 0x5697f0 init,
0x531ca0 allocation, 0x531f90 free, 0x569640 resize;
helpers 0x531c60/0x5320b0/0x556620/0x556650/0x56e2c0/0x5323e0/0x5b0000.
Запрос индекса: FE allocation/free/resize → callers/callees → ссылки
таблицы 0x6b4f20 → constructor 0x5697f0 и startup wrapper 0x5aef80.
Исходные VA/ranges/calls, globals и toolchain сохранены в runs/004-original-heap.

Все 551 случай совпали с исходным x86: полная арена после каждого шага,
включая физические headers, свободные списки, payload, suffix/name/guard,
returns и внешние вызовы. Flag 0x10 выбирает верхний конец, 0x20 — самый
большой подходящий блок; граница split строго >0x40. Resize сохраняет pointer,
может ограничить рост доступным соседним пространством; -1 запрашивает максимум.
16-byte header / 64-byte control block подтверждены native/x86 сравнением.
005deb10 исходно равен 1, остальные copy flags равны 0 — проверены по PE данным.

Исправлен ABI free (возврат 1); 236 FE регрессий повторены в новом
runs/004-original-heap/fe-regression, реестр ссылается на новые SHA.
Run 001–003 сохранены как исторические. Итого 21 проверенная ручная функция.
В библиотеке FE allocator/free/resize теперь разрешаются в heap.cpp;
FE regression всё ещё использует свой записывающий heap. Совместное FE/heap/IO
исполнение ещё не проверено. CRT formatting/fill, OS locks, SIMD-copy targets
и allocation-failure callback проверены на записывающих границах, не восстановлены.

## Выполнено в Run 005

29 новых C++ функций файловых requests/queue/status/completion/chunk read
и списков операций сверены с x86 на 89 joint FE/heap/IO случаях.
551 heap и 236 FE регрессий сохранены в новых подпапках Run005.
Проверены byte group, serial wrap, сортировка с равными ключами, поиск/удаление,
EOF/short read/отказ, primary/fallback и настоящий fe.txt (23 записи/188 bytes).
Whole heap/device/operation/list/buffer/name/stream/global state и calls совпали.

3 missed callbacks 0x533cd0/0x567bf0/0x5684c0 добавлены в supplementary
SHA/body index: 36 587 automatic + 3 manual. Всего 50 проверенных ручных
функций, 0 byte matches/модулей. ABI bool open сравнивается по AL, read/close
по EAX. Source/VA/calls/layout/globals/toolchain и границы проверки —
runs/005-original-files/README.md и verification.json.

FE связан с реальными heap и IO frontend в joint probe. Worker выполняет
completion немедленно только в fixture: исходный scheduler ещё не восстановлен.
Disk/archive/VirtualAlloc wrappers, OS/CRT/SIMD и эффекты FE callbacks внешние.
Archive opcodes и fatal/concurrent/locale/runtime-null-name состояния не приняты.
Старые runs 001–004 сохранены; registry указывает актуальные Run005 SHA.

## Выполнено в Run 006

6 новых функций page wrappers/list constructors/default key/device init
сверены на 474 случаях с x86. 89 совместных FE/heap/IO случаев повторены
с настоящими page wrappers; recording allocation теперь на Win32 imports.
Signed page-rounding с LEA/IDIV/IMUL и EAX VirtualFree сохранены.
Всего 56 проверенных функций. Heap/FE standalone отчёты Run005 актуальны
по SHA; старые runs не изменены. Общий отчёт — runs/006-file-device.

Worker 0x568530..0x5688cc (925 bytes) и default key 0x580670..0x580674
добавлены в supplementary SHA/body index. Каталог: 36 587 automatic + 5.
Worker пока unrecovered, вне счётчика 56; OS/thread/event/lock/diagnostic
и raw disk/archive остаются границами. Fixture thread start поставляет лишь
исходную initialized=1 запись; выполнение worker loop и concurrency не принято.

## Выполнено в Run007 — worker и completion

Запрос индекса: `00568530`, таблица `005688d0`, consumers `005806e0/005808f0`.
SHA/11 targets/bytes — runs/007-file-worker/dispatch.json. Координатор владеет
file_worker.cpp, io_worker_lists.cpp, ABI, интеграцией и приёмкой.
worker_probe (worker, gpt-6-sol, medium) — native probe и x86 verifier.
Восстановлены C++ ветви 0..10, отмена, group gate, completion и callback.
69 differential случаев прошли, включая полную арену и промежуточные состояния.
3 новые функции приняты, всего 59. Все шесть MSVC Win32 стендов собираются.
OS/backend/event/lock пока записываемые границы; concurrency не доказана.

## Текущий шаг и передача

Владелец — координатор. Run007 задания завершены; незавершённых правок стенда нет.
Следующий пакет Run008: удалить ручную имитацию completion в files_probe,
подключить worker 0x568530 и восстановить operation wait 0x567f70.
Сравнить joint FE/heap/IO и реальные очереди с исходным x86; OS события,
thread ID/pump/sleep и disk APIs пока явные записываемые границы.
Далее event wrappers 0x55fb20..0x55fce0, thread trampoline/start 0x55f4f0/0x55f5f0,
disk open/read/seek/close 0x5919a0/0x591df0/0x592140/0x592290, archive 0x568900.
После них heap setup и startup binding 0x4b6a50.

Текущие проверки:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/index-v2-worker.py
    py -3 scripts/research/verify-v2-file-worker.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
    py -3 scripts/research/structure-v2.py
    py -3 scripts/research/trace-v2-startup.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification

Heap/FE/file/device SHA reports прежних runs остаются актуальны; история не меняется.
CRT/main-loop/render/audio/input, compiler/flags, четыре decompile errors и
unclassified bytes открыты. MSVC 19.44.35229 — измеренный современный инструмент,
не доказанный оригинальный compiler. local/game только читается.
Игровой EXE и visual acceptance отсутствуют; итерация не закрыта.
