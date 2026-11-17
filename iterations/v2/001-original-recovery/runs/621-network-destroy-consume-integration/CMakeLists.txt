cmake_minimum_required(VERSION 3.20)
project(porsche_network_destroy_consume_621 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../618-frame-surface-file-open-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../619-shutdown-network-destroy/shutdown_network_destroy_619.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../620-engine-service-consume-resource/engine_service_consume_resource_620.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../311-pr4-shutdown-helpers"
  "${CMAKE_CURRENT_SOURCE_DIR}/../619-shutdown-network-destroy"
  "${CMAKE_CURRENT_SOURCE_DIR}/../620-engine-service-consume-resource")
