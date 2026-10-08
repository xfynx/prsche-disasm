# Run 009 — исходные event/sleep consumers и IAT индекс

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Запросы индекса: `0055fb20..0055fce0`, `0055f740`; исходные CALL [IAT]
проверены в листинге и PE import descriptor. 15 C++ функций сверены с x86
на 249 случаях: raw возвраты Win32, автоматическое/ручное событие, signal/reset/
close, wait-any, нулевой/бесконечный/пересчитанный timeout и GetLastError/SleepEx.
Ranges и SHA — [events-unit/source-functions.jsonl](events-unit/source-functions.jsonl).

Сохранены исходные особенности: signed range check результата WaitForMultipleObjectsEx;
abandoned/timeout/failure не становятся handle; try/timed сравнивают выбранный
handle с входным, включая null input. Timeout: низкие 32 бита ticks*1000,
signed IDIV по timer_rate (default 100 при нуле), без clamp. Синтетические
ошибочные API результаты проверяют арифметику, не описывают реальные OS события.
IDIV overflow/trap и настоящий OS scheduler не приняты.

Signal/reset/sleep теперь возвращают исходный u32 EAX; single wait — HANDLE.
Сигнатуры старых recording probes исправлены без изменения их поведения.
Новые отчёты после изменения headers: device 474, worker 69, wait 87,
joint FE/heap/IO 89 сравнений прошли. Реальный fe.txt остаётся 23 records/188 bytes.
Event wrappers пока отдельно проверены и включены в библиотеку; общий стенд
ещё записывает их как границы. Следующий пакет перенесёт эти границы на Win32
imports и восстановит thread trampoline/start/identity/registry.

Исправлена ошибка статического импортного индекса: lookup OriginalFirstThunk
используется для чтения имён; адрес IAT вычисляется FirstThunk+index*4.
3751 адрес исправлен, все 4217 path/dll/symbol/order записи сохранены.
[import-iat.json](import-iat.json) содержит descriptor и подтверждённые CALL адреса.
Regression synthetic PE покрывает различные lookup/IAT, ordinal и OFT=0 fallback.
Ghidra и полный v2 корпус не переписывались; local/game только читался.

Проверки:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/verify-v2-file-events.py
    py -3 scripts/research/verify-v2-file-device.py
    py -3 scripts/research/verify-v2-file-worker.py
    py -3 scripts/research/verify-v2-file-wait.py
    py -3 scripts/research/verify-v2-files.py
    py -3 scripts/research/test_index_binaries.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts

Всего 75 проверенных ручных функций, восемь собираемых MSVC Win32 стендов.
Registry указывает новые reports; прежние runs сохранены. Win32 services,
потоки/конкурентность, disk/archive, CRT/SIMD и FE callbacks ещё открыты.
Игрового EXE/visual acceptance нет; итерация не закрыта.
