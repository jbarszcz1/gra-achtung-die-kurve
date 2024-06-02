cmake_minimum_required(VERSION 3.20.0)
project(projekt VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include(FetchContent)

# Konfiguracja Raylib
set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)
include_directories(${raylib_SOURCE_DIR}/src)

# Konfiguracja GoogleTest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCE_FILES main.cpp src/board.cpp src/snake.cpp src/game.cpp src/game_state.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)


# Dodanie pliku wykonywalnego głównego projektu
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib m)

set(TEST_FILES tests/test_snake.cpp)

include_directories(tests)


# set(TEST_FILES
#     tests/test_snake.cpp
# )
# Dodanie pliku wykonywalnego testów
add_executable(${PROJECT_NAME}_tests ${TEST_FILES} src/snake.cpp)

# Linkowanie bibliotek do pliku wykonywalnego testów
target_link_libraries(${PROJECT_NAME}_tests gtest gtest_main raylib m)
