cmake_minimum_required(VERSION 3.20)
project(porsche_context_prevideo_594 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../591-frame-object-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../592-context-base-destroy/context_base_destroy_592.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../593-render-display-prevideo/render_display_prevideo_593.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../592-context-base-destroy"
  "${CMAKE_CURRENT_SOURCE_DIR}/../593-render-display-prevideo")
