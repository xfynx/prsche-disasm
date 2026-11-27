cmake_minimum_required(VERSION 3.20)
project(porsche_integration_873 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../868-player-history-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../869-selected-player-scene-reset/selected_player_scene_reset_869.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../870-world-list-reset/world_list_reset_870.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../871-scene-records-reset/scene_records_reset_871.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../872-world-row-reset/world_row_reset_872.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../869-selected-player-scene-reset"
  "${CMAKE_CURRENT_LIST_DIR}/../870-world-list-reset"
  "${CMAKE_CURRENT_LIST_DIR}/../871-scene-records-reset"
  "${CMAKE_CURRENT_LIST_DIR}/../872-world-row-reset")
