# Run015 — общий FE/heap/IO с исходными disk consumers

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Запросы индекса: `00591ce0/00591df0/00592140/00592290`, callers worker568530,
file frontend533bf0/533de0/533da0; source functions/calls записаны в run.

4 восстановленных disk consumers выполняются в общем native и original x86
стенде вместе с настоящими FE/heap/queues/worker/wait/events/page wrappers.
Границы read/seek/info/close сняты; recording перенесён на Win32 ReadFile,
SetFilePointer, SetLastError/GetLastError и CloseHandle. 89 случаев совпали
по всей арене heap/IO/physical records, buffer/stream/globals, возвратам,
порядку вызовов и состоянию при событиях. Настоящий fe.txt:23 records/188 bytes.
Source/table dependency hashes — verification.json.

Open/write/archive/routing/exists, thread identity/pump/creation, locks/CRT и
FE callback effects в этом общем стенде ещё recording boundaries. Реальная OS
конкурентность и чтение диска не доказаны. Unit disk mapped-view отдельно в Run011.

Checkpoint100: Run013 три DirectInput helpers полностью сверены на1026 случаях;
532e10 mode6 остаётся PARTIAL, вне счётчика100. Run014 пять lock/pool consumers
сверены на31 случае; bootstrap интеграция пока открыта. FE callback1320 unit
повторён с текущими build hashes в fe-callbacks-regression. 14 MSVC Win32 targets
собираются. Registry обновлён; старые runs сохранены. Игрового EXE нет.

Проверки:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/verify-v2-input-state.py
    py -3 scripts/research/verify-v2-heap-locks.py
    py -3 scripts/research/verify-v2-joint-disk.py
    py -3 scripts/research/verify-v2-fe-callbacks.py --report-dir iterations/v2/001-original-recovery/runs/015-joint-disk/fe-callbacks-regression
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
    py -3 scripts/research/structure-v2.py
    py -3 scripts/research/trace-v2-startup.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification

Следом physical open5919a0/591c50, input buffered consumers и настоящий
thread/lock bootstrap. Неизвестные ветки и службы остаются открытыми.
