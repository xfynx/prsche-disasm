cmake_minimum_required(VERSION 3.20)
project(porsche_render_window_codec_create_630 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../627-audio-init-diagnostic-abort-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../628-render-window-initialize/render_window_initialize_628.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../629-audio-stream-codec-create/audio_stream_codec_create_629.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../434-audio-canonical-bindings"
  "${CMAKE_CURRENT_SOURCE_DIR}/../435-audio-stop-voice"
  "${CMAKE_CURRENT_SOURCE_DIR}/../438-audio-pool-allocator"
  "${CMAKE_CURRENT_SOURCE_DIR}/../443-audio-device-capabilities"
  "${CMAKE_CURRENT_SOURCE_DIR}/../528-render-library-lifecycle"
  "${CMAKE_CURRENT_SOURCE_DIR}/../559-audio-stream-service"
  "${CMAKE_CURRENT_SOURCE_DIR}/../561-audio-stream-creation"
  "${CMAKE_CURRENT_SOURCE_DIR}/../628-render-window-initialize"
  "${CMAKE_CURRENT_SOURCE_DIR}/../629-audio-stream-codec-create")
