cmake_minimum_required(VERSION 3.20)
project(porsche_movie_setup_codec_release_654 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../651-resource-table-text-fallbacks-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../652-game-setup-movie/game_setup_movie_652.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../653-audio-stream-codec-release/audio_stream_codec_release_653.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../652-game-setup-movie"
  "${CMAKE_CURRENT_SOURCE_DIR}/../653-audio-stream-codec-release")
