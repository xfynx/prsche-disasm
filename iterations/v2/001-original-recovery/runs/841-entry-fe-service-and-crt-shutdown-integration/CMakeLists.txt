cmake_minimum_required(VERSION 3.20)
project(porsche_integration_841 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../839-render-input-path-and-window-ops-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../835-entry-fe-service/entry_fe_service_835.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../838-crt-shutdown-and-env-closers/crt_shutdown_env_838.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../835-entry-fe-service"
  "${CMAKE_CURRENT_LIST_DIR}/../838-crt-shutdown-and-env-closers")
