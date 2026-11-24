cmake_minimum_required(VERSION 3.20)
project(porsche_integration_804 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../800-scene-route-and-texture-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../797-render-driver-select-mode/render_driver_select_mode_797.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../798-sim-audio-startup-viv-load/sim_audio_startup_viv_load_798.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../797-render-driver-select-mode"
  "${CMAKE_CURRENT_LIST_DIR}/../798-sim-audio-startup-viv-load")
