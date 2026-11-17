# Run620 engine service consume resource (`00490420`, `0048cb50`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::network_item_add_packet_00490420` (`00490420..004904c9`, 170B, sha256 `2c42d1267e04151a57553731059aec27f6795d7dac1434c38a288e773ca31e7e`)
- `porsche::engine_service_consume_resource_0048cb50` (`0048cb50..0048ccb8`, 361B, sha256 `79dedd42e351df5b312758d6828d7e9bf7cf5c3792f0e375cce92dd1d8f2d1f9`)
- `porsche::data_packet_tag_005d072c` (`005d072c..005d0737`, 12B, `"CDataPacket\0"`, sha256 `71bd133fa049d775678a8b595a5e6e4a0b106519ebc858f937054633cd752d60`)

Reuses canonical declarations (`porsche/engine_service_427a60.hpp`, `porsche/startup_services.hpp`, `splash_network_queries_510.hpp`, `porsche/render_objects.hpp`, `porsche/fe_stream.hpp`, `porsche/heap.hpp`, `porsche/network_workers_members.hpp`).

## Verification

- Attempt `001` (`local/experiments/v2-engine-service-consume-resource-620/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/620-engine-service-consume-resource/native-config.json --attempt 001`
  - `/Od` and `/O2` both compiled cleanly (`/W4`) and printed `engine_service_consume_resource_original_x86_vs_cpp=PASS cases=25 events=128`, comparing relocated original x86 against C++ across direct `00490420` calls, `0048cb50` entry guards, `count <= 0` bypass, `+0x260` peer matching and `+0x0c` count update, `+0x264` deduplication, `render_allocate_0059ef90 -> nullptr`, `value == nullptr`, and mid-call `startup_network_00628c70` swap reloads.
  - Mutation controls (`wrong-entry-count-guard`, `wrong-item-count-increment`, `wrong-copy-value-guard`, `wrong-peer-id-match`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage and providers for `startup_network_00628c70`, `network_item_data_004903f0`, `render_allocate_0059ef90`, `allocate_00531ca0`, `heap_copy_dispatch_005323e0`, `network_member_end_00529050`, `network_member_copy_0050e140`, and `network_member_insert_004937f0`. Null `item` pointers, null `startup_network_00628c70` when `count <= 0`, null packet payloads in existing list nodes, `render_allocate_0059ef90` failure during `0048cb50` peer packet insertion, negative `count` with non-null `value`, and production CMake/registry integration remain open.
