# Run098 — startup integration and concrete game-link frontier

Интеграция093–103 после checkpoint090 /89f242b. Общая MSVC Win32 библиотека
содержит исходные intro/resource caller004dd600, progress/splash004a4a70,
input snapshot0055feb0, ordered startup004b67b0, release0056a490,
noop00516950, frame pump004b0d70 и service00427a60. MAD004dc850 остаётся
частичным header consumer: потоковый playback/audio/render loop не восстановлен.
Все функции привязаны к Porsche.exe SHA
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`;
точные адреса, original bytes и call/state oracles — в отчётах пакетов093–103.

Run102 впервые пытается связать настоящий игровой WinMain с canonical production
libraries без fixture definitions игровых служб. Исходная попытка:0 compile errors,
251 unresolved symbols/263 references. Она не создала рабочий EXE. Свежий результат
после включения101/103 сохраняется отдельно в `original-game-link/link-report.json`.
Неизвестные asset/driver/vtable/media services не подменяются заглушками.

Девять THRASH declarations исправлены на stdcall: исходные вызовы не очищают стек,
а render loader ищет decorated `_THRASH_*@N` exports. Это ABI correction,
не реализация драйвера и не доказательство отрисованного кадра.
Общие BSS roots65b32c/65b334/65b360 и movie service69ed0c имеют единственного
владельца; исходные producers путей ещё открыты. Начальные null следуют BSS.

Исправлена область compile proof: исторический090 собирал список TUs через
`rglob('*.vcxproj')`, захватив standalone094 project внутри build tree.
098 использует только `ALL_BUILD` → `ProjectReference` через `v2_build_graph.py`.
090 не переписывается. Также084 verifier теперь входит в manifest и self-pins;
его текущий differential proof повторён в `window-support/verification.json`.

Проверки и окончательные counts записываются в `acceptance.json`,
`compile-link-proof.json`, четыре `native-*-result.json` и `corpus-verification.json`.
Native window fixture доказывает создание/закрытие окна и join исходной цепочкой,
но не игровой кадр, полную графику, карьеры или визуальное соответствие.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/refresh-v2-proofs.py --report-root iterations/v2/001-original-recovery/runs/098-startup-integration/final-refresh --jobs 4 --update-registry
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
```

Следующий шаг — проверить alias/ABI candidates по реальной game-link диагностике,
затем восстанавливать достижимые недостающие consumers. Полный игровой запуск открыт.

Приёмка:221 full +6 partial;28 свежих отчётов/4934 сравнений. ALL_BUILD:94 projects/173 TUs;80 comparison/alias targets+4 native+3 link fixtures.
Свежий game-link:0 compile errors,256 unresolved symbols/276 references; рабочего EXE нет.
Шесть ранних uncommitted outputs после изменения common CMake заменены актуальными reports в final-refresh; старые refresh-plan/result сохраняют журнал раннего запуска.
