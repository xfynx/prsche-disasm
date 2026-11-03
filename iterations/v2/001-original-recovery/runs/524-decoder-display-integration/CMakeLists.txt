cmake_minimum_required(VERSION 3.20)
project(porsche_decoder_display_524 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../520-driver-start-capture-integration/CMakeLists.txt")

# Replace accepted owners in fresh sources; immutable originals remain excluded.
get_target_property(_entry_sources porsche_game_entry_bridges SOURCES)
foreach(_old_pattern "audio_mixer_configuration_486\\.cpp$" "render_descriptor\\.cpp$")
    list(LENGTH _entry_sources _before)
    list(FILTER _entry_sources EXCLUDE REGEX "${_old_pattern}")
    list(LENGTH _entry_sources _after)
    math(EXPR _removed "${_before}-${_after}")
    if(NOT _removed EQUAL 1)
        message(FATAL_ERROR "Expected exactly one replaced source: ${_old_pattern}; removed=${_removed}")
    endif()
endforeach()
set_property(TARGET porsche_game_entry_bridges PROPERTY SOURCES "${_entry_sources}")

target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../512-audio-nibble-decoders/audio_mixer_configuration_486.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../512-audio-nibble-decoders/audio_nibble_decoders_512.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../512-audio-nibble-decoders/nibble_memory_512.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../521-render-initialize/render_initialize_521.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../521-render-initialize/render_descriptor_view_521.cpp"
)

target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/401-device-table"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/374-render-descriptor"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/403-modem-enumeration"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/408-tapi-wrappers"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/411-modem-callback"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/412-tapi-lazy-wrappers"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/410-modem-caps-open"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/432-modem-configuration"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/434-audio-canonical-bindings"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/435-audio-stop-voice"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/436-audio-channel-shutdown"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/438-audio-pool-allocator"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/439-audio-voice-cleanup"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/442-audio-initialization"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/443-audio-device-capabilities"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/446-cpu-features"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/448-audio-groups"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/451-audio-record-decoder"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/452-audio-record-resources"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/455-audio-device-lifecycle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/457-startup-win32-bindings"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/458-audio-release-chain"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/460-audio-thread-worker"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/461-audio-filter-kernel"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/462-audio-directsound-initialize"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/463-audio-thread-mix"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/464-audio-probe-startup"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/466-audio-mixer-control"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/468-audio-fixed-vector"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/471-audio-property-apply"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/473-audio-sample-dispatch"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/475-audio-sample-processor"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/476-audio-sample-converter"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/477-file-stream-queries"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/478-audio-resource-controls"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/479-audio-mixer-ramp-stop"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/481-startup-gates"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/484-render-constructor-repair"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/485-network-callback-lifecycle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/486-audio-mixer-configuration"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/488-network-callback-drain"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/489-render-pixel-compare"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/492-audio-pcm-cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/493-audio-pcm-constructors"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/494-render-resource-leaves"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/495-application-audio-bank-cleanup"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/496-render-present-caller-repair"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/499-rooted-file-exists"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/498-audio-pcm-3dnow-cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/501-audio-pcm-stream-lookup"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/503-render-surface-construction"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/505-audio-stream-buffer-delivery"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/504-audio-coded-constructors"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/506-render-matrix-config"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/508-audio-stream-producer-lifecycle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/510-splash-network-queries"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/511-render-surface-init"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/382-rectangle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/513-audio-stream-worker-stop"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/source/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/source/recovered/Porsche.exe"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/515-render-driver-constructors"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/518-render-driver-start"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/519-audio-stream-capture-fill"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/512-audio-nibble-decoders"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/521-render-initialize"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../iterations/v2/001-original-recovery/runs/371-cursor-snapshot"
)
