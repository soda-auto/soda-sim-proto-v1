cmake_minimum_required(VERSION 3.5)

if(NOT PROJECT_VERSION)
  set(PROJECT_VERSION 1.0.0.0)
endif()

project(generic-msgs VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(FULL_PROJECT_NAME soda-sim-proto-v1)

add_library(${PROJECT_NAME} STATIC
  src/lidarSerialization.cpp
  src/radarSerialization.cpp
  src/poseSerialization.cpp
  src/ultrasonicSerialization.cpp
)
add_library(SodaSimProtoV1::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>"
    "$<INSTALL_INTERFACE:include/>"
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    OUTPUT_NAME ${FULL_PROJECT_NAME}
    POSITION_INDEPENDENT_CODE TRUE
)

## Installation
install(TARGETS ${PROJECT_NAME}
  EXPORT soda-sim-proto-v1-targets
  ARCHIVE DESTINATION "lib" COMPONENT dev
)
install(DIRECTORY include/ DESTINATION include COMPONENT dev)

export(
  EXPORT      soda-sim-proto-v1-targets
  FILE        soda-sim-proto-v1-targets.cmake
  NAMESPACE   SodaSimProtoV1::
)
install(
  EXPORT      soda-sim-proto-v1-targets
  FILE        soda-sim-proto-v1-targets.cmake
  NAMESPACE   SodaSimProtoV1::
  DESTINATION lib/cmake/SodaSimProtoV1
  COMPONENT   dev
)

## Packaging
include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${PROJECT_SOURCE_DIR}/SodaSimProtoV1Config.cmake.in
  ${PROJECT_BINARY_DIR}/SodaSimProtoV1Config.cmake
  INSTALL_DESTINATION lib/cmake/SodaSimProtoV1
  INSTALL_DESTINATION lib/cmake/SodaSimProtoV1
)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/SodaSimProtoV1ConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(
  FILES
    ${PROJECT_BINARY_DIR}/SodaSimProtoV1Config.cmake
    ${PROJECT_BINARY_DIR}/SodaSimProtoV1ConfigVersion.cmake
  DESTINATION lib/cmake/SodaSimProtoV1
  COMPONENT dev
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(Version)
include(Packaging)

