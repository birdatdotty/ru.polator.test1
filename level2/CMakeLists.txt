cmake_minimum_required(VERSION 3.5)

project(level2
    VERSION 0.1.1
    LANGUAGES CXX)

find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_subdirectory(Src)

add_executable(level2
    tst_level2.cpp
    Src)
add_test(NAME level2 COMMAND level2)

target_link_libraries(level2 PRIVATE Src Qt5::Test)

