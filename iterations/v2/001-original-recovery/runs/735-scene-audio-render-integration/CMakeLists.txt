cmake_minimum_required(VERSION 3.20)
project(porsche_integration_735 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../730-audio-copy-and-frame-control-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../732-scene-noise-seed-reset/scene_noise_seed_732.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../733-audio-stream-service-tick/audio_stream_service_tick_733.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../734-render-fill/render_fill_734.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../732-scene-noise-seed-reset"
  "${CMAKE_CURRENT_SOURCE_DIR}/../733-audio-stream-service-tick"
  "${CMAKE_CURRENT_SOURCE_DIR}/../734-render-fill")
