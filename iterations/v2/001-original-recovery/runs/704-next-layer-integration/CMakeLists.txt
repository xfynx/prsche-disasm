cmake_minimum_required(VERSION 3.20)
project(porsche_integration_704 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../699-unlocked-callers-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../700-scene-reset-leaf-chain/scene_stage_reset_700.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../701-view-teardown-route-family/view_teardown_route_family_701.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../702-entry-fe-scene-route-transfer-leaves/entry_fe_scene_leaves_702.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../703-audio-finalize-period-callback/audio_finalize_period_703.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../700-scene-reset-leaf-chain"
  "${CMAKE_CURRENT_SOURCE_DIR}/../701-view-teardown-route-family"
  "${CMAKE_CURRENT_SOURCE_DIR}/../702-entry-fe-scene-route-transfer-leaves"
  "${CMAKE_CURRENT_SOURCE_DIR}/../703-audio-finalize-period-callback")
