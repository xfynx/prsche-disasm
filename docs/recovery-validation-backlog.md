# Отложенные проверки восстановления v2

Прямое требование пользователя 2026-10-10: возвращаться к пропущенным проверкам.
Координатор обновляет этот список при каждом checkpoint и проверяет его
перед архитектурной приёмкой/переносом на Rust; пункт закрывается только
со ссылкой на фактически выполненную проверку. Сборка, bounded differential oracle
и визуальное соответствие — отдельные результаты.

- [ ] Собрать игровой EXE и выполнить исходный startup с настоящими ресурсами.
  Блокер: Run117 game-link имеет248 unresolved symbols. Возврат: после устранения
  зависимостей; сначала запуск/выход, затем кадр, ввод, меню и режимы игры.
- [ ] Проверить закрытие через WM_CLOSE→GetMessage=0→исходный timer callback,
  включая producer времени006b7c40. Run086/098 проверяет другую исходную ветку
  cleanup message0x466→destroy→join. Возврат: после восстановления clock producer. Run110 нашёл пропущенный
  worker00565270..533e (207B), исходный setup565030 передаёт его в55f420.
  Run112 worker восстановлен и интегрирован111 (6/6 oracle cases); setup/
  thread/timer packet118 готов отдельно (9 cases, persistent ThreadRecord и loop retests),
  но ещё не принят в общей сборке. End-to-end проверка не выполнена.
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
  Experimental114 common subset не подключать как полный core;119 восстанавливает
  исходную цепочку. Возврат: после exact parser/helper differential proofs.
  До подключения cleanup005a4259 сохранить полный 32-byte stack descriptor:
  wrapper005a0fbf выделяет0x20 байт (005a0fc2), а cleanup читает+0x10 до
  проверки flags и+0x18 в buffered ветке. Текущий16-byte prefix проверен
  только с записывающими границами; интеграция реального callee ещё не принята.

Владелец всех открытых пунктов — координатор. Состояние на checkpoint117:
ни один из пунктов выше не объявлен выполненным.
