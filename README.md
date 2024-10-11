# CrossesAndDots

## Build, test and generate code coverage with cmake 

### Switch the branch to see project with cmake

### 1. CMakeLists.txt 
```cmake
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

```

### 2. 
```bash 
mkdir build
```
### 3. 
```bash
cd build
```
### 4. 
```bash
cmake ..
```
or with detailed output:
```bash
cmake .. -DCMAKE_VERBOSE_MAKEFILE=ON
```
### 5. 
```bash
make
```
### 6. 
```bash
ctest
```
### 7. 
```bash
lcov --directory . --capture --output-file coverage.info --ignore-errors mismatch
```
### 8. 
```bash
lcov --remove coverage.info '/usr/*' --output-file coverage.info
```
### 9. 
```bash
lcov --list coverage.info
```
### 10. 
```bash
genhtml coverage.info --output-directory out
```
### 11. 
```bash
xdg-open out/index.html
```

## To execute CrossesAndDotsCppUnitTests tests from VS console do the following steps:

1. Open Developer Command Prompt for VS 2022
2. Change current directory to \repos\CrossesAndDots\x64\Debug
3. Run vstest.console.exe MicrosoftUnitTests.dll