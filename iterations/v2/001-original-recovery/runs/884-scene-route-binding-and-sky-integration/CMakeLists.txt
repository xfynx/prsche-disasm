cmake_minimum_required(VERSION 3.20)
project(porsche_integration_884 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../877-route-keyframes-and-emitter-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../874-scene-route-binding/scene_route_binding_874.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../878-sky-resource-nodes/scene_sky_878.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../879-flare-teardown/flare_teardown_879.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../880-sky-texture-reload/sky_texture_reload_880.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../882-flare-cleanup-slots/flare_cleanup_slots_882.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../883-scene-sky-cleanup/scene_sky_cleanup_883.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../874-scene-route-binding"
  "${CMAKE_CURRENT_LIST_DIR}/../878-sky-resource-nodes"
  "${CMAKE_CURRENT_LIST_DIR}/../879-flare-teardown"
  "${CMAKE_CURRENT_LIST_DIR}/../880-sky-texture-reload"
  "${CMAKE_CURRENT_LIST_DIR}/../882-flare-cleanup-slots"
  "${CMAKE_CURRENT_LIST_DIR}/../883-scene-sky-cleanup")
