cmake_minimum_required(VERSION 3.20)
project(porsche_integration_754 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../749-audio-schl-integration/CMakeLists.txt")

# Replace all compiled consumers of the old packed view with Run753 copies
# bound to Run688's canonical 0x90-byte records.
get_target_property(_entry_sources porsche_game_entry_bridges SOURCES)
list(FILTER _entry_sources EXCLUDE REGEX "494-render-resource-leaves/render_resource_494\\.cpp$")
list(FILTER _entry_sources EXCLUDE REGEX "676-startup-input-slot-and-math-leaves/startup_input_slot_math_676\\.cpp$")
list(FILTER _entry_sources EXCLUDE REGEX "680-input-ff-slot-and-render-leaves/input_ff_slot_render_680\\.cpp$")
set_property(TARGET porsche_game_entry_bridges PROPERTY SOURCES "${_entry_sources}")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../751-audio-voice-start/audio_voice_start_751.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../752-input-effect-cleanup/input_effect_cleanup_752.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../753-input-effect-record-unification/render_resource_494_record_unified_753.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../753-input-effect-record-unification/startup_input_slot_math_676_record_unified_753.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../753-input-effect-record-unification/input_ff_slot_render_680_record_unified_753.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/audio_voice_start_abi_bridge_754.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../751-audio-voice-start"
  "${CMAKE_CURRENT_LIST_DIR}/../752-input-effect-cleanup"
  "${CMAKE_CURRENT_LIST_DIR}/../753-input-effect-record-unification")
