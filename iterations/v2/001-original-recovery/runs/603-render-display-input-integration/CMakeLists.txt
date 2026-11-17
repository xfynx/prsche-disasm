cmake_minimum_required(VERSION 3.20)
project(porsche_render_display_input_603 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../600-startup-clock-misc-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../601-render-display-apply/render_display_apply_601.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../602-render-input-route/render_input_route_602.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../601-render-display-apply"
  "${CMAKE_CURRENT_SOURCE_DIR}/../602-render-input-route")
