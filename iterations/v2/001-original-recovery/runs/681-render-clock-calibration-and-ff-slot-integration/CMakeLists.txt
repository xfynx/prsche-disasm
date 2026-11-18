cmake_minimum_required(VERSION 3.20)
project(porsche_integration_681 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../678-input-slot-math-and-audio-cpu-leaves-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../679-render-clock-calibration-leaves/render_clock_calibration_679.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../680-input-ff-slot-and-render-leaves/input_ff_slot_render_680.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../679-render-clock-calibration-leaves"
  "${CMAKE_CURRENT_SOURCE_DIR}/../680-input-ff-slot-and-render-leaves")
