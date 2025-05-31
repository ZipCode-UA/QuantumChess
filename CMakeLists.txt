cmake_minimum_required(VERSION 3.30.0)
project(QuantumChess LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} "src/main/main.cpp")

# make target - 'run' - compiles and runs the produced binary
add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

file(GLOB Main "src/main/*.cpp")
target_sources(${PROJECT_NAME} PUBLIC ${Main})
target_include_directories(${PROJECT_NAME} PUBLIC include/main)

file(GLOB Pieces "src/pieces/*.cpp")
target_sources(${PROJECT_NAME} PUBLIC ${Pieces})
target_include_directories(${PROJECT_NAME} PUBLIC include/pieces)

target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
