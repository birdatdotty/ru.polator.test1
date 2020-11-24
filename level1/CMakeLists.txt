cmake_minimum_required(VERSION 3.5)

project(level1
    VERSION 0.1.1
    LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)
add_subdirectory(Src)

add_executable(level1
  main.cpp
  Src)

target_link_libraries(level1 Src Qt5::Core)
