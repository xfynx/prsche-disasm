cmake_minimum_required(VERSION 3.20)
project(porsche_frame_begin_audio_consumed_624 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../621-network-destroy-consume-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../622-render-frame-begin-state/render_frame_begin_state_622.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../623-audio-stream-service-consumed/audio_stream_service_consumed_623.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../374-render-descriptor"
  "${CMAKE_CURRENT_SOURCE_DIR}/../434-audio-canonical-bindings"
  "${CMAKE_CURRENT_SOURCE_DIR}/../435-audio-stop-voice"
  "${CMAKE_CURRENT_SOURCE_DIR}/../438-audio-pool-allocator"
  "${CMAKE_CURRENT_SOURCE_DIR}/../443-audio-device-capabilities"
  "${CMAKE_CURRENT_SOURCE_DIR}/../527-render-state-flush"
  "${CMAKE_CURRENT_SOURCE_DIR}/../533-render-resource-factories"
  "${CMAKE_CURRENT_SOURCE_DIR}/../559-audio-stream-service"
  "${CMAKE_CURRENT_SOURCE_DIR}/../561-audio-stream-creation"
  "${CMAKE_CURRENT_SOURCE_DIR}/../622-render-frame-begin-state"
  "${CMAKE_CURRENT_SOURCE_DIR}/../623-audio-stream-service-consumed")
