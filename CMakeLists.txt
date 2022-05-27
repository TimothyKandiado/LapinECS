cmake_minimum_required(VERSION 3.20)
project(LapinECS)

add_compile_definitions(DEBUG_ENABLED)
#add_compile_definitions(DEBUG_LOGGING_ENABLED)

add_subdirectory(Dependencies/raylib)
add_subdirectory(Dependencies/flecs)
add_subdirectory(Engine)

FILE(COPY Resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(Engine PUBLIC Dependencies/flecs/include)
target_include_directories(Engine PUBLIC Dependencies/raylib/src)


set(CMAKE_CXX_STANDARD 20)

add_executable(LapinECS main.cpp)

target_link_libraries(LapinECS Engine flecs_static raylib glfw)
