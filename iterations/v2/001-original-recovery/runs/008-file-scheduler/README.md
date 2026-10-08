# Run 008 — worker/wait в общем стенде

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Поиск индекса: `00567f70`, вызовы `00567b80/00567af0/00580ea0/00580ec0`,
thread `0055f780`, pump/sleep `005366e0/0055f740`, события `0055fc60/0055fc40`.
Исходные ranges — [source-functions.jsonl](source-functions.jsonl), общий
call graph — [files-regression/source-calls.jsonl](files-regression/source-calls.jsonl).

`file_wait.cpp` восстанавливает `00567f70..0056804c`: -3 для id=0/неактивного
устройства; pending AND наличия операции; повторный поиск до завершения;
callback pump + sleep на исходной main-thread ветви либо wait/reset события.
При выборе события global devices читается повторно; исходный device для
find/lock сохраняется. 87 unit случаев совпали с x86, включая циклы,
битовые значения pending, null find, смену devices global и initialized.
Unit find/status/thread/pump/sleep/event — записываемые границы.

Ручные signal_device/append_completed и wait-stub удалены из files_probe.
В общем стенде выполняются настоящие C++ worker, wait, operation find/status,
FE stream, heap, очереди/completion/chunk read. 89 совместных случаев совпали
с оригинальными x86 инструкциями по всей heap/IO арене, операциям, именам,
буферам, FE записям, globals, вызовам и промежуточным event snapshots.
Настоящий fe.txt проверяется отдельным assertion: 23 записи / 188 байтов.

Original worker вызывается из event hook через возвратный trampoline; вложенных
emu_start нет. Native вызывает тот же worker синхронно. Остановка идёт через
исходный shutdown global из пустого wait fixture; после выхода fixture
восстанавливает initialized для следующего запроса. Это управляемый тест
цепочки consumers, не воспроизведение жизненного цикла настоящего OS thread.
Backend возвращает byte-file данные и явные LastError 0/2/5; backend/thread/
events/lock/CRT/SIMD и эффекты FE callbacks ещё не восстановлены.

Проверки:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/verify-v2-file-wait.py
    py -3 scripts/research/verify-v2-files.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts

Результаты: [unit verification](verification.json), [joint verification](files-regression/verification.json).
Новая функция одна; всего 60 проверенных ручных функций. Семь стендов
собираются MSVC Win32. Прежние runs не менялись; registry файловых функций
указывает на текущий joint report. Игрового EXE/visual acceptance пока нет.
Далее события и thread trampoline/start, disk/archive backend, startup binding.
