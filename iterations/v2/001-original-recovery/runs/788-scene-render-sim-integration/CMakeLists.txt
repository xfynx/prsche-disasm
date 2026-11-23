cmake_minimum_required(VERSION 3.20)
project(porsche_integration_788 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../784-audio-voice-and-sim-teardown-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../781-scene-stage-constructor/scene_stage_constructor_781.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../782-render-calibrate-service/render_calibrate_service_782.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../785-sim-view-slot-cleanup/sim_view_slot_cleanup_785.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../787-render-font-destroy-and-prepare/render_font_destroy_787.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../781-scene-stage-constructor"
  "${CMAKE_CURRENT_LIST_DIR}/../782-render-calibrate-service"
  "${CMAKE_CURRENT_LIST_DIR}/../785-sim-view-slot-cleanup"
  "${CMAKE_CURRENT_LIST_DIR}/../787-render-font-destroy-and-prepare")
