cmake_minimum_required(VERSION 3.20)
project(porsche_integration_776 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../761-audio-backend-range-canonical-state/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../774-scene-blur-state-commit/scene_blur_state_774.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../775-input-effect-slot-and-render-misc/input_effect_slot_render_misc_775.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../774-scene-blur-state-commit"
  "${CMAKE_CURRENT_LIST_DIR}/../775-input-effect-slot-and-render-misc")
