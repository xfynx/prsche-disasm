cmake_minimum_required(VERSION 3.20)
project(porsche_integration_796 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../792-scene-render-sim-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../793-render-debug-font-create/render_debug_font_create_793.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../794-sim-audio-queue-teardown/sim_audio_queue_teardown_794.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../793-render-debug-font-create"
  "${CMAKE_CURRENT_LIST_DIR}/../794-sim-audio-queue-teardown")
