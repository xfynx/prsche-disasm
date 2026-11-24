cmake_minimum_required(VERSION 3.20)
project(porsche_integration_792 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../788-scene-render-sim-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../786-scene-flare-entries-resolve/scene_flare_resolve_786.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../789-render-font-convert-glyphs/render_font_convert_glyphs_789.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../790-sim-audio-queue-and-record-evict/sim_audio_queue_790.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../791-scene-sky-texture-create/scene_sky_texture_791.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../786-scene-flare-entries-resolve"
  "${CMAKE_CURRENT_LIST_DIR}/../789-render-font-convert-glyphs"
  "${CMAKE_CURRENT_LIST_DIR}/../790-sim-audio-queue-and-record-evict"
  "${CMAKE_CURRENT_LIST_DIR}/../791-scene-sky-texture-create")
