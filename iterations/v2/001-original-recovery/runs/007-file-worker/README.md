# Run 007 — исходный файловый worker

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Запрос индекса: `00568530`, таблица `005688d0`, вызываемые `005806e0/005808f0`.
Supplementary worker index и весь список вызовов — [Run006](../006-file-device/worker-index.json).
11 ячеек dispatch с исходными bytes/SHA/VA — [dispatch.json](dispatch.json),
воспроизводимый экспорт: `py -3 scripts/research/index-v2-worker.py`.

В C++ восстановлены worker `00568530..005688cc`, prepend `005806e0..00580721`
и locked remove `005808f0..00580928`. Worker проверяет shutdown, возвращает
операцию в sorted queue при превышении group limit, исполняет opcode 0..10
или diagnostic default, ставит completion перед callback и событием.
Cancel bit2 обходит dispatch; callback получает -1. Иначе status расширяется
из знакового байта. Opcode1 только ставит status=1: физический close остаётся
в исходном consumer operation_complete, сохранённом в Run005.

Оригинальные особенности сохранены: seek failure с GetLastError=0 не
перезаписывает status; opcode9 с null buffer не меняет status; open mode
bit1 подавляет bits2/4, но сохраняет действие bits8/16/32. Инструкции
00568740..00568745 передают указатель результата info четвёртым аргументом.

Проверка: `powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1`
и `py -3 scripts/research/verify-v2-file-worker.py`. Native C++ сравнивается
с неизменёнными x86 инструкциями, включая полную арену, auxiliary list,
shutdown, порядок вызовов и снимки состояния на внешних границах.
Число случаев и hashes — [verification.json](verification.json).
Все шесть консольных стендов собираются MSVC Win32; инструмент — [toolchain.json](toolchain.json).

Backend/ошибки/события/блокировки — записывающие границы, остановка worker
делается через исходный shutdown global из event fixture. Реальные потоки,
OS scheduling, disk/archive, thread trampoline и wait ещё не восстановлены.
Старый общий files_probe пока содержит немедленную имитацию completion;
следующий пакет заменяет её настоящим worker и восстанавливает operation wait.
Игрового EXE и visual acceptance нет. Старые runs не изменены.
