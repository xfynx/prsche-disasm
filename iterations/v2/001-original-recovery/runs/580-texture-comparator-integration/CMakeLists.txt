cmake_minimum_required(VERSION 3.20)
project(porsche_texture_comparator_580 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../578-texture-transfer-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../579-texture-format-comparator/render_format_comparator_579.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../579-texture-format-comparator/format_preferences_579.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../579-texture-format-comparator")
