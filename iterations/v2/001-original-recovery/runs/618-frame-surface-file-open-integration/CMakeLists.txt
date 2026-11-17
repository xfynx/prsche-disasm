cmake_minimum_required(VERSION 3.20)
project(porsche_frame_surface_file_open_618 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../615-display-trees-release-stack-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../616-frame-surface-setup/frame_surface_setup_616.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../617-file-backend-open/file_backend_open_617.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../616-frame-surface-setup"
  "${CMAKE_CURRENT_SOURCE_DIR}/../617-file-backend-open")
