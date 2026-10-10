# Run111 — formatter ABI, filesystem and clock-worker integration

После запушенного107/d663347 включены108 formatter entry005a0fbf,
109 resource leaf00561ba0,112 clockworker00565270 и113 dispatcher00568d50/
callback00561be0. Всего229 full +6 partial.
Original/native common probes:7/7,3/3,6/6,8/8 соответственно. Вместе со свежими
зависимыми reports:10 reports/4153 bounded original-x86 comparisons.

По исходным stack arguments связаны11 spellings005a0fbf с canonical variadic
entry: fixed-arity wrappers сохраняют порядок/типы слов; два variadic wrappers
передают исходный va-list. Сведения104 и исходные declarations/callers проверены.
Core005a4371 и cleanup005a4259 остаются внешними. Experimental subset114 не
подключён: альтернативный parser и синтетический unsupported return не заменяют
оригинальные state tables, float/locale/wide пути. Следующий exact parser —119.

Resource leaf и dispatcher/callback теперь связаны непосредственно, без
дублирующих bridges. Group005df770 имеет единственного raw-backed владельца:
исходные bytes64 00 00 00 под pinned Porsche SHA даютDWORD0x64.
Clockworker использует канонические tick6b7c40/rate5deb48 и точные callback/event
owners. Thread setup565030/55f420 ещё внешние; pending WM_CLOSE check не закрыт.

MSVC Win32 ALL_BUILD прошёл:100 projects/186 compiled TUs;
86 comparison/alias targets+4 nativeOS+3 nongUIlink fixtures.
verify-v2-native-fixtures.py выполнил все7 проверок и закрепил source/EXE hashes;
четыре OS fixtures создали/закрыли окно и завершили исходный поток.
Обнаруженный duplicate standalone project для native_window_chain исключён:
v2_build_graph теперь выбирает именованные common targets только из ALL_BUILD.

Настоящий game-link:0 compile errors,250 unresolved symbols/271 references
(после107 было260/282). Полного игрового EXE и запуска нет.
Планы включают архитектурную схему после полного восстановления и последующее
переписывание на Rust native/web. [Validation backlog](../../../../../docs/recovery-validation-backlog.md)
проверяется на каждом checkpoint и перед переходом к схеме/Rust; открытые пункты
не снимаются сборкой или bounded oracle.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
py -3 scripts/research/verify-v2-native-fixtures.py --report-root iterations/v2/001-original-recovery/runs/111-runtime-integration
py -3 scripts/research/refresh-v2-proofs.py --report-root iterations/v2/001-original-recovery/runs/111-runtime-integration --jobs 4 --update-registry
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
```

Следующий117: готовые115process exit/116install.txt producer и объединение пяти
path globals как views60pointer table.118timer setup и119original formatter в работе.
114/115/116/117/118/119 WIP не входят в этот checkpoint.
