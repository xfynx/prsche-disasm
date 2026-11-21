cmake_minimum_required(VERSION 3.20)
project(porsche_integration_743 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../735-scene-audio-render-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../736-scene-blur-program-lifecycle/scene_blur_program_736.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../737-scene-pass-children/scene_pass_children_737.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../738-scene-blur-stage-child/scene_blur_stage_child_738.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../739-scene-program-integration/scene_blur_stage_abi_bridge_739.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../740-audio-stream-scdl-chunk/audio_stream_scdl_chunk_740.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../741-render-shape-transfer/render_shape_transfer_741.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../742-scene-stage-group-ctor/scene_stage_group_742.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../736-scene-blur-program-lifecycle"
  "${CMAKE_CURRENT_LIST_DIR}/../737-scene-pass-children"
  "${CMAKE_CURRENT_LIST_DIR}/../738-scene-blur-stage-child"
  "${CMAKE_CURRENT_LIST_DIR}/../739-scene-program-integration"
  "${CMAKE_CURRENT_LIST_DIR}/../740-audio-stream-scdl-chunk"
  "${CMAKE_CURRENT_LIST_DIR}/../741-render-shape-transfer"
  "${CMAKE_CURRENT_LIST_DIR}/../742-scene-stage-group-ctor")
