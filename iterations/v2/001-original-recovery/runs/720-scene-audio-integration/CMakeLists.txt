cmake_minimum_required(VERSION 3.20)
project(porsche_integration_720 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../714-audio-group-decode-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../715-audio-group-process-reload/audio_group_process_reload_715.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../716-scene-stage-reset-ecx-tag/scene_stage_reset_716.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../717-audio-slot-configure/audio_slot_configure_717.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../718-audio-resource-slot/audio_resource_slot_718.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../719-audio-group-step/audio_group_step_719.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../715-audio-group-process-reload"
  "${CMAKE_CURRENT_SOURCE_DIR}/../716-scene-stage-reset-ecx-tag"
  "${CMAKE_CURRENT_SOURCE_DIR}/../717-audio-slot-configure"
  "${CMAKE_CURRENT_SOURCE_DIR}/../718-audio-resource-slot"
  "${CMAKE_CURRENT_SOURCE_DIR}/../719-audio-group-step")
