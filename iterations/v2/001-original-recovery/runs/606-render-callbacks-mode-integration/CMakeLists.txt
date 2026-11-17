cmake_minimum_required(VERSION 3.20)
project(porsche_render_callbacks_mode_606 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../603-render-display-input-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../604-render-initialize-callbacks/render_initialize_callbacks_604.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../605-render-driver-context-mode/render_driver_context_mode_605.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../604-render-initialize-callbacks"
  "${CMAKE_CURRENT_SOURCE_DIR}/../605-render-driver-context-mode")
