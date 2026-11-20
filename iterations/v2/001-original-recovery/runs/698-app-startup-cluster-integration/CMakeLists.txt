cmake_minimum_required(VERSION 3.20)
project(porsche_integration_698 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../694-input-ff-clut-audio-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../691-app-sim-teardown-audio-unload/application_sim_teardown_691.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../692-entry-fe-loop-and-leaves/fe_entry_leaves_692.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../693-view-setup-teardown-scene-enter/application_view_lifecycle_693.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../691-app-sim-teardown-audio-unload"
  "${CMAKE_CURRENT_SOURCE_DIR}/../692-entry-fe-loop-and-leaves"
  "${CMAKE_CURRENT_SOURCE_DIR}/../693-view-setup-teardown-scene-enter")
