# Аудит старой логики на соответствие оригиналу

2026-10-04. Это список неподтверждённых реализаций 012, а не спецификация оригинала.
Проверяем исходные consumers и заменяем по доказательствам. Снимки 001–011 заморожены.

## Приоритет 012: физика и управляемость

- physics/suspension.rs::from_sim/update_surface_contact: SIM реальные, но
  множители/ограничения stiffness/damping/grip, разбиение 0.8/1.2 и силы восстановлены
  предположительно. Нужны потребители каждого исходного поля и порядок расчёта.
- physics/tire.rs::Tire::step: свои определения slip, линейная сила и friction
  ellipse; наличие grip в SIM не доказывает этот закон силы.
- physics/powertrain.rs::Powertrain::step: clutch/RPM coupling, inertia/friction,
  раздача момента — не подтверждённый перенос кода. Передачи/таблица момента
  из SIM не доказывают алгоритм их применения.
- physics/vehicle.rs::from_sim/step: mass*12 тормоза, area 1.95, downforce .15,
  угол руля 32°, 240 Hz и интеграция требуют исходного consumer.
- physics/rigid_body.rs::new/integrate: инерция коробки, damping .001/.05;
  physics/chassis.rs::resolve_chassis_ground: SKIN .002, recovery .12, friction .55,
  импульс и геометрия контакта не считаются оригинальными.
- race/collision.rs и renderer.rs::resolve_vehicle_contacts: круг/OBB и реакция
  предположительны. Обновление 2026-10-05: связь EDG с исходным contact response
  доказана, участок реакции проверен на x86; полный перенос остаётся открытым
  (original-collision/response.md).

## Приоритет 012: ИИ, миссии и UI

- race/ai.rs::AiProfile::from_ais/update_controls/step_kinematics: AIS прочитан,
  но преобразования в skill/lateral acceleration/reaction, lookahead и управление
  восстановлены предположительно. Состав участников также требует источника.
- nfs-game/factory_driver.rs::StuntDetector::update/evaluate_mission/catalog:
  yaw 2.7/5.8, reverse/speed gates, времена, штрафы, ограничения damage и часть
  метаданных заданы вручную. Проверять каждую миссию по её исходному consumer.
- web/main.js/index.html/style.css: успешная навигация не доказывает оригинальные
  LAY-комнаты, элементы, шрифты и переходы. Нужны эталонные кадры и события.

## Зависимости для 013: повреждения и рынок б/у

- renderer.rs::resolve_vehicle_contacts меняет позицию/скорость, но не damage.
- web/main.js::evaluateFactoryResult передаёт literal 0.0 в damage evaluator;
  ограничение CarDelivery не может сработать от физических ударов.
- nfs-game/profile.rs::GarageCar::apply_wear/repair_cost и
  parts.rs::InstalledPart::apply_wear/repair_cost используют свои ставки/пороги/
  доли цены. Производственных вызовов apply_wear аудит не обнаружил, только тест.
- Генератор б/у и связь цены/повреждений/ремонта также требуют реверса; готовый
  каталог предложений и процент condition не означают восстановленную систему.

Критерий исправления каждого пункта: module/SHA/VA + входы/поля/единицы →
вычисления → выходы, затем сравнение с оригиналом. Число собственных тестов
не закрывает пункт. Следующая конкретная цепочка: original-collision/README.md.
