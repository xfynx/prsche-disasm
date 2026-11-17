cmake_minimum_required(VERSION 3.20)
project(porsche_frame_splash_588 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../584-driver-x87-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../585-frame-interface-release/frame_interface_release_585.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../587-splash-command-dispatch/splash_command_dispatch_587.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../585-frame-interface-release"
  "${CMAKE_CURRENT_SOURCE_DIR}/../587-splash-command-dispatch")
