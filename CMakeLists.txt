cmake_minimum_required(VERSION 3.20.0)
project(projekt VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)

set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)




enable_testing()

set(
    SOURCE_FILES
    main.cpp
    src/board.cpp
    src/snake.cpp)


include_directories(src)
include_directories(headers)


add_executable(${PROJECT_NAME} ${SOURCE_FILES} )
target_link_libraries(${PROJECT_NAME} raylib)


set(TEST_FILES
    tests/test_snake.cpp
)

include_directories(tests)


add_executable(${PROJECT_NAME}_tests ${TEST_FILES} src/snake.cpp)
target_link_libraries(${PROJECT_NAME}_tests gtest gtest_main)


add_test(NAME SnakeTests COMMAND ${PROJECT_NAME}_tests)
