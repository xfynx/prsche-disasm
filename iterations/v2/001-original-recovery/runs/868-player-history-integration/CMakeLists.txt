cmake_minimum_required(VERSION 3.20)
project(porsche_integration_868 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../865-player-dispatch-and-extension-pool-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../867-player-history-reset/player_history_reset_867.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../867-player-history-reset")
