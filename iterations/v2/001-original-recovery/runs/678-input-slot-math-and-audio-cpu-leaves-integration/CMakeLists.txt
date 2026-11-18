cmake_minimum_required(VERSION 3.20)
project(porsche_integration_678 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../675-render-loader-directx-and-depth-helpers-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../676-startup-input-slot-and-math-leaves/startup_input_slot_math_676.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../677-audio-bank-state-and-cpu-feature-leaves/audio_bank_cpu_leaves_677.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../676-startup-input-slot-and-math-leaves"
  "${CMAKE_CURRENT_SOURCE_DIR}/../677-audio-bank-state-and-cpu-feature-leaves")
