cmake_minimum_required(VERSION 3.20)
project(porsche_integration_833 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../829-rtti-crt-exit-and-diag-integration/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/../831-player-service-tables-and-callbacks/bindings.cmake")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../831-player-service-tables-and-callbacks/player_service_tables_831.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../832-entry-fe-call-00413960/entry_fe_call_832.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../831-player-service-tables-and-callbacks"
  "${CMAKE_CURRENT_LIST_DIR}/../832-entry-fe-call-00413960")
