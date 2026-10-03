# Индекс оригинальных бинарников

Обновлено 2026-10-03. **Перед реализацией поведения ищем свидетельства здесь.**
Индексы — обычный текст под Git, доступный `rg` и всем исполнителям.
Правило закреплено в [AGENTS.md](../../AGENTS.md).

## Покрытие

[coverage.json](coverage.json) сопоставляет пути и SHA256 с результатами анализа.
В дереве игры 26 файлов: 25 PE-путей соответствуют 24 уникальным бинарникам,
все имеют Ghidra-индексы. Две копии `voodoo2z.dll` учтены как алиасы.
`clcd16.dll` — отдельный 16-битный NE-модуль, PE-анализ его не покрывает.

Без повторного подсчёта алиасов: **36 510 функций, 169 794 связей вызова,
1 274 749 ссылок, 33 414 распознанных строк**. Неразрешённых косвенных вызовов:
17 049. Это автоанализ, а не доказательство полного распознавания кода или
восстановления поведения. Есть также драйверы, сторонние патчи и установщики;
наличие файла не доказывает его использование игрой.

Для экспорта из сохранённой базы `analysis_completion` оставлен
`unknown-cached-export`; флаги тайм-аута сохранены отдельно. `status: indexed`
означает наличие навигационных данных, не 100% реверса.

## Поиск перед правкой

1. Найди ресурс, строку, импорт или известный адрес **в нужном модуле**.
2. Проверь ссылки, содержащую функцию, её вызывающие и вызываемые функции.
3. Прочитай нужные ветки дизассемблерного текста. Имя `FUN_*`, предположительная
   сигнатура и отдельное смещение не доказывают назначение функции/поля.
4. Сохрани в отчёте запрос, модуль/SHA256, адреса, доказательства и гипотезы.

```powershell
py -3 scripts/research/query-binary-index.py --binary Porsche.exe --text '\.scn|\.fac|\.sim' --limit 10
py -3 scripts/research/query-binary-index.py --binary nfs5.exe --address 0x49c922 --disassemble --limit 40
rg -n -i 'FStart|BStart' research/binary-index/ghidra -g strings.jsonl
rg -n '0046d600' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl
```

Адрес — VA, не file offset/RVA. Поиск сверяет хеш локального оригинала, если
он доступен; устаревший индекс отвергается. Дизассемблирование требует локальный
бинарник и Python `capstone`. Поиск по тексту работает и без оригинальных файлов.
Проверенные точки входа: `_FStart.scn` → Porsche.exe `0x46d600`;
nfs5.exe `0x49c922` находится внутри `0x49c6c0`. Семантика требует дальнейшей проверки.

## Состав

- `static/binaries.jsonl`: пути, хеши, секции, image base, импорты/экспорты.
- `static/strings.jsonl`: строки с file offset/RVA/VA; возможен шум.
- `static/imports.jsonl`, `resources.jsonl`: IAT и каталоги PE-ресурсов.
- `static/functions.jsonl`, `calls.jsonl`: предварительные кандидаты/декодирование.
- `ghidra/<имя>-<SHA-prefix>/functions.jsonl`: границы функций, сигнатуры и источник.
- `references.jsonl`, `calls.jsonl`: адреса источника/назначения и функции-владельцы.
- `strings.jsonl`, `symbols.jsonl`: распознанные строки и символы, включая импорты.
- `unresolved-calls.jsonl`: косвенные вызовы без определённой цели.
- `metadata.json`: хеш, архитектура, блоки памяти, счётчики и состояние анализа.

## Воспроизведение

```powershell
py -3 scripts/research/index-binaries.py --game local/game --out research/binary-index/static
./scripts/research/index-ghidra.ps1
py -3 scripts/research/summarize-binary-index.py
py -3 scripts/research/test_index_binaries.py
```

Первый скрипт возвращает ненулевой код при непокрытом NE-модуле, сохраняя все
PE-индексы и явную запись пропуска. Повторный экспорт без анализа:
`./scripts/research/index-ghidra.ps1 -ExportOnly`.
`-OnlyBinary ISSkin.dll` обрабатывает один модуль; полный запуск включает скрытые
файлы. Лимит анализа — 120 секунд на файл; проверяй сводку покрытия.

`local/game` только читается. База Ghidra остаётся в
`local/experiments/binary-index-ghidra`, временные логи — в `local/reports`.
Оригинальные бинарники/ресурсы и база Ghidra не входят в этот каталог.
История: [Run 009](../../iterations/012-campaign-fidelity/runs/009-binary-index/README.md).
