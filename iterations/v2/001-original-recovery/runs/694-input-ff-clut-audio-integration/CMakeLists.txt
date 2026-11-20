cmake_minimum_required(VERSION 3.20)
project(porsche_integration_694 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../687-render-palette-leaves-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../688-frame-control-create-and-gain/input_ff_frame_control_688.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../689-render-clut16-and-keyed-8888-leaves/render_clut16_689.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../690-audio-probe-start-and-period-control/application_audio_probe_690.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../688-frame-control-create-and-gain"
  "${CMAKE_CURRENT_SOURCE_DIR}/../689-render-clut16-and-keyed-8888-leaves"
  "${CMAKE_CURRENT_SOURCE_DIR}/../690-audio-probe-start-and-period-control")
