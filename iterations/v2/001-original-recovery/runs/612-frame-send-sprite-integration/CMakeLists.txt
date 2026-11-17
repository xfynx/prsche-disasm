cmake_minimum_required(VERSION 3.20)
project(porsche_frame_send_sprite_612 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../609-frame-audio-ramp-volume-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../610-frame-audio-send-level/frame_audio_send_level_610.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../611-splash-sprite-horizflip/splash_sprite_horizflip_611.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../610-frame-audio-send-level"
  "${CMAKE_CURRENT_SOURCE_DIR}/../611-splash-sprite-horizflip")
