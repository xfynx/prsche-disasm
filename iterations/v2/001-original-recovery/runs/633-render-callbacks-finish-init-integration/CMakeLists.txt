cmake_minimum_required(VERSION 3.20)
project(porsche_render_callbacks_finish_init_633 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../630-render-window-codec-create-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../631-render-window-callbacks/render_window_callbacks_631.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../632-render-display-finish-init/render_display_finish_init_632.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../631-render-window-callbacks"
  "${CMAKE_CURRENT_SOURCE_DIR}/../632-render-display-finish-init")
