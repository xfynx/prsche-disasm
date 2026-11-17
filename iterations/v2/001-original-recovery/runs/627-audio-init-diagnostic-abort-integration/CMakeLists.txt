cmake_minimum_required(VERSION 3.20)
project(porsche_audio_init_diagnostic_abort_627 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../624-frame-begin-audio-consumed-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../625-application-audio-probe-init/application_audio_init_625.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../626-diagnostic-abort-handler/diagnostic_abort_handler_626.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../345-diagnostic-devices"
  "${CMAKE_CURRENT_SOURCE_DIR}/../353-diagnostic-mono"
  "${CMAKE_CURRENT_SOURCE_DIR}/../457-startup-win32-bindings"
  "${CMAKE_CURRENT_SOURCE_DIR}/../549-render-diagnostic"
  "${CMAKE_CURRENT_SOURCE_DIR}/../625-application-audio-probe-init"
  "${CMAKE_CURRENT_SOURCE_DIR}/../626-diagnostic-abort-handler")
