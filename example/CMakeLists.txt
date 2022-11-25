cmake_minimum_required(VERSION 3.14)

project(Qt-Frameless-Window-DarkStyleExamples CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)
include(../cmake/link_qt.cmake)

if(PROJECT_IS_TOP_LEVEL)
  find_package(Qt-Frameless-Window-DarkStyle REQUIRED)
endif()

add_executable(Qt-Frameless-Window-DarkStyle-demo
  main.cpp
  mainwindow.cpp
  mainwindow.ui
)
target_link_libraries(Qt-Frameless-Window-DarkStyle-demo PRIVATE Qt-Frameless-Window-DarkStyle ${QT_LIBRARIES})
target_compile_features(Qt-Frameless-Window-DarkStyle-demo PRIVATE cxx_std_17)
