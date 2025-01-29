cmake_minimum_required(VERSION 3.0.0)

project(particles)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp src/classes.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
