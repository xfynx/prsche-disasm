cmake_minimum_required(VERSION 3.20)
project(porsche_audio_kernels_554 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../551-diagnostic-codec-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../552-audio-adpcm-kernel/audio_coded_kernel_552.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../553-audio-resampler-kernel/audio_resampler_kernel_553.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../553-audio-resampler-kernel/audio_random_553.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../552-audio-adpcm-kernel"
    "${CMAKE_CURRENT_SOURCE_DIR}/../553-audio-resampler-kernel")
target_link_options(porsche_original_game_link PRIVATE
    "/alternatename:?audio_adpcm_decode_0059a910@porsche@@YAXII@Z=?audio_coded_decode_0059a910@porsche@@YAXII@Z")
