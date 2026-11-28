cmake_minimum_required(VERSION 3.20)
project(porsche_integration_891 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../888-wide-locale-and-row-converter-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../885-scene-flare-ctor/scene_flare_ctor_885.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../890-splash-progress-driver-draw/render_driver_draw_890.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../885-scene-flare-ctor"
  "${CMAKE_CURRENT_LIST_DIR}/../890-splash-progress-driver-draw")
