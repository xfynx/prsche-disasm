cmake_minimum_required(VERSION 3.20)
project(porsche_startup_modem_audio_433 LANGUAGES CXX)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../413-modem-completion-integration" entry-413)
target_sources(porsche_game_entry_bridges PRIVATE
    ../432-modem-configuration/modem_configuration.cpp
    ../434-audio-canonical-bindings/audio_backend_434.cpp
    ../434-audio-canonical-bindings/audio_voice_434.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../410-modem-caps-open"
    "${CMAKE_CURRENT_SOURCE_DIR}/../432-modem-configuration"
    "${CMAKE_CURRENT_SOURCE_DIR}/../434-audio-canonical-bindings")
