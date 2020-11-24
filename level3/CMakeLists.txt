cmake_minimum_required(VERSION 3.14)

project(level3
    VERSION 0.1.2
    LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_subdirectory(Src)

add_executable(level3
  main.cpp
  QmlUser.cpp
  QmlUser.h
  QmlNetwork.cpp
  QmlNetwork.h

  Src
  qml.qrc)

target_compile_definitions(level3
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(level3
  PRIVATE Src Qt5::Core Qt5::Quick)
