cmake_minimum_required(VERSION 3.0.0)

project(particles VERSION 0.1.0 LANGUAGES C CXX)
set(SOURCES
    main.cpp
    classes.cpp
)
include_directories(.)
include_directories(SDL)

add_subdirectory("SDL")
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/SDL") # Add this line
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
add_executable(particles ${SOURCES})

target_link_libraries(particles PRIVATE SDL3::SDL3)

set_property(TARGET particles PROPERTY CXX_STANDARD 17)