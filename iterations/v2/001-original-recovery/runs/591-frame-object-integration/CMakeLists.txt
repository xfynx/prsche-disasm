cmake_minimum_required(VERSION 3.20)
project(porsche_frame_object_591 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../588-frame-splash-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../589-frame-state-release/frame_state_release_589.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../590-game-setup-object-init/game_setup_object_init_590.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../589-frame-state-release"
  "${CMAKE_CURRENT_SOURCE_DIR}/../590-game-setup-object-init")
