# Run831: Player/service BSS tables, callback bridge, and network string alias

Owns zero-initialized `.bss` storage `application_player_object_table_005e8b34` (36B `005e8b34..005e8b57`), `application_player_setup_table_005e75a0` (5,400B `005e75a0..005e8ab7`), `frame_service_root_00628960` (4B `00628960..00628963`), and `resource_open_transform_006ad750` (4B `006ad750..006ad753`), plus `render_event_invoke_callback_005debec` (`00572983..00572988` 6B call-site adapter) and `bindings.{cmake,hpp,json}` aliasing `?network_group_text_005e8e50@porsche@@3PADA` to `files.cpp`'s `?file_null_name_005e8e50@porsche@@3PADA` (0 new unresolved symbols).
Native comparison `local/experiments/v2-player-service-tables-831/003/receipt.json` PASS (`3` cases / `8` events per `/Od` and `/O2`, `6/6` mutations killed).
REA `local/experiments/v2-player-service-tables-831-rea/001/receipt.json` + `validation.json` PASS (`6` dossiers, `0` repeated equal).
