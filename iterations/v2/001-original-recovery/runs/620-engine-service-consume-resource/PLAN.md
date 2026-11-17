# Run620 engine service consume resource

## Goal and criteria
- Recover original `00490420` (`network_item_add_packet_00490420`, 170B), `0048cb50` (`engine_service_consume_resource_0048cb50`, 361B), and `.rdata` tag `005d072c` (`"CDataPacket\0"`, 12B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse canonical declarations in `porsche/engine_service_427a60.hpp`, `porsche/startup_services.hpp`, `splash_network_queries_510.hpp`, `porsche/render_objects.hpp`, `porsche/fe_stream.hpp`, `porsche/heap.hpp`, and `porsche/network_workers_members.hpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes (`2c42d1267e04151a57553731059aec27f6795d7dac1434c38a288e773ca31e7e`, `79dedd42e351df5b312758d6828d7e9bf7cf5c3792f0e375cce92dd1d8f2d1f9`, `71bd133fa049d775678a8b595a5e6e4a0b106519ebc858f937054633cd752d60`), and cached REA (`local/experiments/v2-frontier-469-rea/001/function-0048cb50.json`, `local/experiments/v2-declarations-179/checkpoints/fe1853a85cc62e08f3311b3b93cdb7c1cfdb1d96f07886d323345308101aa57e/00490420.json`) confirm both bodies, calling conventions (`__thiscall` `RET 0Ch` for `00490420`, `__cdecl` `RET 0` for `0048cb50`), and all relocations.
- Attempt `001` (`local/experiments/v2-engine-service-consume-resource-620/001/receipt.json`) passed 25 cases (128 events) at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-entry-count-guard`, `wrong-item-count-increment`, `wrong-copy-value-guard`, `wrong-peer-id-match`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00490420`, `0048cb50`, and `data_packet_tag_005d072c`.
- Null `item` pointers, null `startup_network_00628c70` when `count <= 0`, null packet payloads in existing list nodes, `render_allocate_0059ef90` failure during `0048cb50` peer packet insertion, negative `count` with non-null `value`, and production integration remain open.
