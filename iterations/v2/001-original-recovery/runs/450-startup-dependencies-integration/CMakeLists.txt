cmake_minimum_required(VERSION 3.20)
project(porsche_startup_dependencies_450 LANGUAGES CXX)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../447-cpu-features-integration" entry-447)

# Historical nesting can exceed LINK's path limit. Keep the unchanged named
# import library under a stable short path; leave accepted run370 untouched.
foreach(link_property LINK_LIBRARIES INTERFACE_LINK_LIBRARIES)
    get_target_property(link_inputs porsche_game_entry_bridges ${link_property})
    set(short_inputs "")
    foreach(link_input IN LISTS link_inputs)
        if(link_input MATCHES "/original-dinput\\.lib$")
            file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/imports")
            configure_file("${link_input}"
                "${CMAKE_BINARY_DIR}/imports/original-dinput.lib" COPYONLY)
            list(APPEND short_inputs "${CMAKE_BINARY_DIR}/imports/original-dinput.lib")
        else()
            list(APPEND short_inputs "${link_input}")
        endif()
    endforeach()
    set_property(TARGET porsche_game_entry_bridges PROPERTY ${link_property} "${short_inputs}")
endforeach()
target_sources(porsche_game_entry_bridges PRIVATE
    ../448-audio-groups/audio_groups_448.cpp
    ../449-resource-path-iat/resource_iat_449.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../448-audio-groups")
target_link_options(porsche_original_game_link PRIVATE
    "/INCLUDE:_resource_path_iat_449_anchor")
