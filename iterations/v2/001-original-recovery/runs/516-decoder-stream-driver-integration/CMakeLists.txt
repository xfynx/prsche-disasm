cmake_minimum_required(VERSION 3.20)
project(porsche_stream_driver_516 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../514-surface-init-integration/CMakeLists.txt")
# Original distinct function identities must survive identical-code folding.
target_link_options(porsche_original_game_link PRIVATE /OPT:NOICF)
target_sources(porsche_game_entry_bridges PRIVATE
    ../513-audio-stream-worker-stop/audio_stream_worker_stop_513.cpp
    ../515-render-driver-constructors/render_driver_515.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/513-audio-stream-worker-stop"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/source/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/source/recovered/Porsche.exe"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/515-render-driver-constructors"
)
