cmake_minimum_required(VERSION 3.20)
project(porsche_driver_start_capture_520 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../516-decoder-stream-driver-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/518-render-driver-start/render_driver_start_518.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/518-render-driver-start/platform_driver_start_518.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/519-audio-stream-capture-fill/audio_stream_capture_fill_519.cpp"
)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/518-render-driver-start"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/519-audio-stream-capture-fill"
)
