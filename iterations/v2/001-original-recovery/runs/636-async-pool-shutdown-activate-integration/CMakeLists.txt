cmake_minimum_required(VERSION 3.20)
project(porsche_async_pool_shutdown_activate_636 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../633-render-callbacks-finish-init-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../634-async-pool-shutdown/async_pool_shutdown_634.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../635-render-display-activate-callback/render_display_activate_callback_635.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../361-startup-device-pool"
  "${CMAKE_CURRENT_SOURCE_DIR}/../372-async-callbacks"
  "${CMAKE_CURRENT_SOURCE_DIR}/../570-startup-service-bindings"
  "${CMAKE_CURRENT_SOURCE_DIR}/../634-async-pool-shutdown"
  "${CMAKE_CURRENT_SOURCE_DIR}/../635-render-display-activate-callback")
