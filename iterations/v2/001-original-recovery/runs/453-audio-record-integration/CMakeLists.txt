cmake_minimum_required(VERSION 3.20)
project(porsche_audio_records_453 LANGUAGES CXX)
# Both entry plans use sibling-relative sources. Include the accepted foundation
# in this directory to avoid another binary-path level before370 generates its
# named-import library;450 already keeps the final link path short.
include("${CMAKE_CURRENT_SOURCE_DIR}/../450-startup-dependencies-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
    ../451-audio-record-decoder/audio_record_decoder_451.cpp
    ../452-audio-record-resources/audio_record_resources_452.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../451-audio-record-decoder"
    "${CMAKE_CURRENT_SOURCE_DIR}/../452-audio-record-resources")
