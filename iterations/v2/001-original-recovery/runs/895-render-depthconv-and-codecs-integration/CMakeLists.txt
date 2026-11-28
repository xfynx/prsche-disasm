cmake_minimum_required(VERSION 3.20)
project(porsche_integration_895 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../894-session-extension-service-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../893-render-depthconv-and-codecs/render_depthconv_codecs_893.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../893-render-depthconv-and-codecs")
