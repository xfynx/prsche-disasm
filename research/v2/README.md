# Полный корпус оригинала для v2

Автоматические полные листинги и псевдо-C каждого уникального модуля игры.
Входы только читаются из `local/game`, SHA проверяется при экспорте/инвентаре.
Ссылки и roadmap: [v2/001](../../iterations/v2/001-original-recovery/README.md).

`binaries/<filename>-<SHA-prefix>/` содержит `disassembly.asm`,
`functions.jsonl`, `defined-data.jsonl`, `unclassified-executable.jsonl`,
`listing.json`, затем `decompiled.c`, `decompile-status.jsonl`,
`decompilation.json`. Автоматический вывод не считается восстановленным
собираемым исходником. Исходные имена файлов и VA сохраняются.
Статусы ошибок/нераспознанных байтов обязательны; их наличие не скрывается.
Индекс вызывающих/вызываемых функций, строк/импортов и неразрешённых вызовов
для PE уже доступен в `research/binary-index`; он остаётся навигацией.
