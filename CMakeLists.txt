cmake_minimum_required(VERSION 3.10)

project(CrossesAndDots VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    CrossesAndDots/Player.cpp
    CrossesAndDots/GameField.cpp
    CrossesAndDots/GameStateChecker.cpp
    )

set(HEADERS
    CrossesAndDots/GameField.h
    CrossesAndDots/GameStateChecker.h
    CrossesAndDots/ScenesBuilder.h
    )

add_library(CrossesAndDots ${SOURCES} ${HEADERS})
target_include_directories(CrossesAndDots PRIVATE CrossesAndDots)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

enable_testing()

add_executable(GameFieldTests CrossesAndDotsTests/GameFieldTests.cpp)
target_link_libraries(GameFieldTests PRIVATE CrossesAndDots ${GTEST_LIBRARIES} pthread)
add_test(NAME GameFieldTests COMMAND GameFieldTests)

add_executable(GameStateCheckerTests CrossesAndDotsTests/GameStateCheckerTests.cpp)
target_link_libraries(GameStateCheckerTests PRIVATE CrossesAndDots ${GTEST_LIBRARIES} pthread)
add_test(NAME GameStateCheckerTests COMMAND GameStateCheckerTests)

add_executable(ScenesBuilderTests CrossesAndDotsTests/ScenesBuilderTests.cpp)
target_link_libraries(ScenesBuilderTests PRIVATE CrossesAndDots ${GTEST_LIBRARIES} pthread)
add_test(NAME ScenesBuilderTests COMMAND ScenesBuilderTests)
