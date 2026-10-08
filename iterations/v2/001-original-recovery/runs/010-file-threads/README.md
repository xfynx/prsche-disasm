# Run010 — thread registry/start/bootstrap и общие event wrappers

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Запросы индекса: `0055f2b0/0055f320/0055f3b0/0055f4f0/0055f560/0055f5f0/0055f730/0055f780/0055f7e0/0055f8b0`.
CALL, IAT, globals, семиячеечная таблица priority и body SHA — [thread-index.json](thread-index.json).
Trampoline 0x55f4f0..0x55f552 (99 bytes, RET4) добавлен в supplementary индекс;
проверяется модуль и SHA тела. Каталог: 36 587 automatic + 6 manual = 36 593.

10 C++ функций сравнивались на 94 случаях: полная arena/table, globals,
значимые возвраты и порядок OS/heap/callback calls. Сохранены page-rounded capacity,
низкое слово MUL в table init, serial wrap через ноль, signed slot bounds,
API evaluation order, suspended launch, handshake, copy payload и cached slot/serial.
[threads-unit/verification.json](threads-unit/verification.json) фиксирует зависимости.
Void init/unregister EAX нормализован; первоначальное handshake word до CreateThread
не определено в оригинале и исключено из наблюдения. Настоящая конкурентность,
shutdown и exit callback не проверены; Win32 endpoints записывают вызовы.

Event stubs общего FE/heap/IO стенда заменены восстановленными wrappers;
границы находятся на Win32 imports. 89 joint случаев прошли с настоящими worker,
wait и event consumers, всей ареной и промежуточными snapshots. Настоящий fe.txt:
23 records / 188 bytes. [files-regression/verification.json](files-regression/verification.json).
Thread start/identity в этом стенде пока recording boundaries; новый thread unit
проверяет их отдельно. Это не запуск игры или доказательство OS scheduler.

Всего 85 проверенных C++ функций, девять MSVC Win32 стендов собираются.
Registry ссылается на текущие SHA reports; старые runs сохранены. Checkpoint manifest
включает только принятые source dependencies, исключая незавершённую параллельную работу.

Проверки:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/verify-v2-file-threads.py
    py -3 scripts/research/verify-v2-files.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
    py -3 scripts/research/structure-v2.py
    py -3 scripts/research/trace-v2-startup.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification

Следом параллельные Run011 disk read/seek/close/info и Run012 FE callbacks,
далее thread shutdown/exit и общий thread binding. Игрового EXE/visual acceptance нет;
итерация открыта. local/game только читался.
