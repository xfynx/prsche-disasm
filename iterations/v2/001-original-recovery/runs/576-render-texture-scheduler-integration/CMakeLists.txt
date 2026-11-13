cmake_minimum_required(VERSION 3.20)
project(porsche_render_texture_scheduler_576 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../574-startup-lifecycle-integration/CMakeLists.txt")
# Draft: admit only after Run575's original comparison is accepted.
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../575-render-texture-scheduler/render_texture_scheduler_575.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../575-render-texture-scheduler/texture_process_575.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../575-render-texture-scheduler")
