cmake_minimum_required(VERSION 3.0.0)

project(particles)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CPM
file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

set(LIBS)

# SDL
CPMAddPackage("gh:libsdl-org/SDL#4c70aa3")
list(APPEND LIBS SDL3::SDL3)
add_executable(${PROJECT_NAME} src/main.cpp src/classes.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})

set(ENV{DISPLAY} :0.0)