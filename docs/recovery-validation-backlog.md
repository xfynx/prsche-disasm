# Отложенные проверки восстановления v2

Прямое требование пользователя 2026-10-10: возвращаться к пропущенным проверкам.
Координатор обновляет этот список при каждом checkpoint и проверяет его
перед архитектурной приёмкой/переносом на Rust; пункт закрывается только
со ссылкой на фактически выполненную проверку. Сборка, bounded differential oracle
и визуальное соответствие — отдельные результаты.

- [ ] Собрать игровой EXE и выполнить исходный startup с настоящими ресурсами.
  Блокер: Run126 game-link имеет250 unresolved symbols. Возврат: после устранения
  зависимостей; сначала запуск/выход, затем кадр, ввод, меню и режимы игры.
- [ ] Проверить закрытие через WM_CLOSE→GetMessage=0→исходный timer callback,
  включая producer времени006b7c40. Run086/098 проверяет другую исходную ветку
  cleanup message0x466→destroy→join. Возврат: после подключения исходного diagnostic callback/init и live timer-thread fixture. Run110 нашёл пропущенный
  worker00565270..533e (207B), исходный setup565030 передаёт его в55f420.
  Run112 worker восстановлен и интегрирован111 (6/6 oracle cases); setup/
  thread/timer packet118 интегрирован121: 9 cases, persistent28-byte ThreadRecord,
  live event/id loop retests. OS shutdown bindings125 проверены6 дочерними процессами.
  123 lifecycle(21 cases),127 wait(16) и130 stop→wait integration(3) приняты126.
  Живое расписание таймера и end-to-end WM_CLOSE ещё не выполнены.
- [ ] Проверить полный startup context004d1a90→004d3420→004d1ba0 внутри app_main.
  Review128/129: оригинал резервирует0x188 stack bytes, объект0x180 bytes передаётся
  в ECX; старый caller описывал лишь два DWORD и fixture скрывал это расхождение.
  Run129 исправляет caller/storage/ABI;4 span cases и15 main cases с реальными
  ctor/dtor прошли изолированно. Общая приёмка126 прошла: [15 composed main cases](../iterations/v2/001-original-recovery/runs/126-event-integration/application-main/verification.json) с реальными ctor/dtor.
  Возврат: после полного parser/context graph и live startup;
  полный004d3420 (8589B), vtable и его реальные зависимости остаются открытыми.
  Также открыть единственный owner/extent строки005e8e50: Run081 нашёл две
  раздельные модели пустой строки;129 использует существующий owner без новой догадки о размере.
- [ ] Проверить реальные DirectInput devices и caps/read paths со связанной
  оконной цепочкой. Run096 проверяет consumer0055feb0 с контролируемыми границами;
  native lifecycle fixture не подключает весь input graph. Возврат: после bindings.
- [ ] Выполнить THRASH driver dispatch, fullscreen transitions и настоящий кадр.
  stdcall declarations и успешные oracle checks не доказывают реальный драйвер.
  Возврат: после восстановления driver/service/vtable зависимостей game-link.
- [ ] Воспроизвести MAD stream/playback/audio/render loop целиком. Run094
  восстанавливает только header consumer; не использовать его как полную004dc850.
  Возврат: после восстановления stream/decoder/audio consumers.
- [ ] Сравнить producers путей0065b32c/334/360 и movie service0069ed0c с оригиналом.
  Текущие единые BSS owners не доказывают исходную инициализацию/валидные assets.
  Возврат: при восстановлении соответствующих startup producers. Run116
  нашёл startup_subsystem004b6ff0: install.txt→60pointer table65b2a0..65b38f.
  Run117: 9 component oracle cases и 7 composed checks подтвердили49 записей
  настоящего install.txt и пять shared table views. Реальный startup с assets
  ещё не выполнен; movie service0069ed0c остаётся открытым.
- [ ] Проверить длинные пути и исходные границы stack buffers у00427a60/0059dd00.
  Run103 oracle ограничен префиксами, помещающимися в100-byte local buffer;
  исходный overflow за пределами этих случаев не проверен. Возврат: вместе
  с path producers и контролируемым isolated original-x86 experiment.
- [ ] Подтвердить compiler/CRT/flags и байтовое совпадение там, где оно требуется.
  Run100 no-op семантически совпадает, но MSVC RET0 отличается от original RET.
  Ноль binary matches не скрывается за количеством recovered functions.
- [ ] Полная визуальная и игровая приёмка: оригинальные кадры/переходы,
  Quick Race, обе карьеры, физика/повреждения/ИИ/экономика/сохранения/звук.
  Возврат: после рабочего original baseline; текущие probes этого не доказывают.

- [ ] Восстановить полный original formatter: state tables005c19a8/c8,
  output helpers, float/wide/locale paths и runtime callback initialization.
  Experimental114 вынесен вlocal/experiments. Шесть exact helpers119 интегрированы121
  (11 cases); parser4371 isolated124:56 cases, root review pending.
  Cleanup4259 восстанавливается132; production formatter ещё не связан.
  Возврат: после полного parser/helper differential proof и связанного formatter entry.
  До подключения cleanup005a4259 сохранить полный 32-byte stack descriptor:
  wrapper005a0fbf выделяет0x20 байт (005a0fc2), а cleanup читает+0x10 до
  проверки flags и+0x18 в buffered ветке. Текущий16-byte prefix проверен
  только с записывающими границами; интеграция реального callee ещё не принята.

Владелец всех открытых пунктов — координатор. Состояние на checkpoint126:
ни один из пунктов выше не объявлен выполненным.
