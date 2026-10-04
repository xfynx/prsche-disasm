# Run 010 — выход из результата Factory Driver

2026-10-04. Пользователь прошёл первую миссию, но «Продолжить» зацикливало
экран результата. Предыдущие автоматические заезды Run 008 по-прежнему
не считаются успешным прохождением.

Причина в web/main.js: каждый кадр при terminal phase 4/5 открывал скрытое
окно заново. Обработка награды была одноразовой, показ окна — нет.
Теперь оба действия используют eventFinishedHandled, сбрасываемый при новой
нетерминальной фазе. Открытие брифинга не сбрасывает результат старого заезда.
«Продолжить» после Factory возвращает обновлённый список миссий.
Сброс клавишей R и кнопкой панели также разрешает новый результат.

## Индекс перед реализацией

Запросы:
```
py -3 scripts/research/query-binary-index.py --binary Porsche.exe --text 'nfs5.fac|FResult|FNext|Continue' --limit 8
py -3 scripts/research/query-binary-index.py --binary Porsche.exe --address 0x5103b0 --limit 6
py -3 scripts/research/query-binary-index.py --binary Porsche.exe --address 0x51aba0 --limit 5
```

Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
ID_CONTINUEBUTTON: строка 0x5dc98c, ссылка 0x5103b0; индекс не определил
содержащую функцию. nfs5.fac: строка 0x5dd364, ссылка 0x51abad внутри 0x51aba0;
вызывающая функция 0x4d3420 (call 0x4d36c8).
Это навигационные свидетельства ресурсов, а не доказательство оригинального
перехода меню. Правка устраняет воспроизводимый дефект нашего JS lifecycle;
правила прохождения/награды не меняются. Точное соответствие оригинальному
экрану после миссии остаётся отдельной визуальной проверкой.

Полная проверка перехода нашла следующий блокер: 1m01 ссылается на отсутствующий
boxster.sim. Каталог nfs5.car, zero-based record 60 (base 0x18240, size 1648):
строки spec/model/SIM начинаются на +0x4d/+0x7f/+0xb1 и содержат
1997Boxster25 / Boxster / Boxster25. Для уже выбранной модели Boxster ссылка
1m01 заменена на boxster25; другие миссии и правила не менялись.
Индекс: запрос `--text '^nfs5\.car$'`, строка 0x5dac84 → 0x4f3ba5
внутри 0x4f3a40; проверен также `--address 0x4f3a40 --limit 3`.
Связь model→SIM подтверждена ресурсом; это не доказательство назначения
автомобиля или остальных правил 1m01 в оригинале.

## Проверки

До правки UI regression: `AssertionError: Continue must stay dismissed on subsequent frames`.
После правки ui.test.mjs проходит: phase 4/5, 60 кадров после Continue,
новый брифинг, повтор клавишей R, кнопкой панели и кнопкой результата.
Web release собран; main.js в local/builds совпадает с исходником по SHA256.
Пять Factory Rust-тестов прошли, fmt чистый. Windows и WASM release собраны.
Chromium: реальный WASM evaluator сохраняет 0M01, Continue остаётся закрытым
при terminal phase, 1m01 разблокирована; её брифинг не открывает старый результат.
После полной загрузки 1m01 начинается новый заезд с исходной массой Boxster25.
Reload того же адреса сохраняет прогресс; phase 5 допускает выход и повтор.
0 page errors. Артефакты: browser/result-check.json, browser/ladder-after-reload.png.
Скриншот осмотрен: первая миссия пройдена, вторая доступна, третья заблокирована.
Первый запуск теста ожидал только enabled selector и опережал boot: исправлено
ожидание завершения загрузки. Проверка старта также ждёт финальный статус,
а не старую phase предыдущего viewer; это и выявило ошибочный SIM.

Команды из корня:
```powershell
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/012-campaign-fidelity/web/ui.test.mjs
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build.ps1 -Iteration 012-campaign-fidelity -Config release -Target all
& 'C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/node.exe' iterations/012-campaign-fidelity/web/verify-results.cjs C:/Users/steew/AppData/Local/ms-playwright-go/1.57.0/package iterations/012-campaign-fidelity/runs/010-result-continue/browser
```

Run завершён. Следующий шаг: игровая проверка 1m01 и отдельная правка
границ Quick Race, найденная предыдущим аудитом (в этом run не менялась).
Искусственный финиш в браузерном тесте проверяет переходы и сохранение,
но не доказывает проходимость трассы или соответствие оригиналу.
