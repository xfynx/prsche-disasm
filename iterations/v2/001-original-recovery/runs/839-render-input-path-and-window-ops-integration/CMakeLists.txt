cmake_minimum_required(VERSION 3.20)
project(porsche_integration_839 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../836-rtti-cast-and-network-rtti-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../834-render-input-and-path-closers/render_input_path_834.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../837-window-worker-and-render-ops-leaves/window_render_ops_837.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../834-render-input-and-path-closers"
  "${CMAKE_CURRENT_LIST_DIR}/../837-window-worker-and-render-ops-leaves")
