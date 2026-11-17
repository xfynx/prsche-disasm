cmake_minimum_required(VERSION 3.20)
project(porsche_display_trees_release_stack_615 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../612-frame-send-sprite-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../613-render-display-member-trees/render_display_member_trees_613.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../614-splash-release-stack/splash_release_stack_614.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../613-render-display-member-trees"
  "${CMAKE_CURRENT_SOURCE_DIR}/../614-splash-release-stack")
