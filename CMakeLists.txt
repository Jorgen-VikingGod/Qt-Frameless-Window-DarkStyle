cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
  Qt-Frameless-Window-DarkStyle
  VERSION 0.1.0
  DESCRIPTION "simple MainWindow class implementation with frameless window and custom dark style. "
  HOMEPAGE_URL "https://example.com/"
  LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)
include(cmake/link_qt.cmake)

# NOTE -  Set to OFF to build static lib
qt5_add_resources(
  icon_res
  ${CMAKE_CURRENT_SOURCE_DIR}/source/framelesswindow.qrc
)

qt5_add_resources(
  style_res
  ${CMAKE_CURRENT_SOURCE_DIR}/source/darkstyle.qrc
)

set(BUILD_SHARED_LIBS ON)

# ---- Declare library ----
add_library(
  Qt-Frameless-Window-DarkStyle
  include/DarkStyle.h
  include/framelesswindow.h
  source/DarkStyle.cpp
  source/framelesswindow.cpp
  source/framelesswindow.ui
  source/windowdragger.cpp
  ${icon_res}
  ${style_res}
)
target_link_libraries(Qt-Frameless-Window-DarkStyle PRIVATE ${QT_LIBRARIES})

include(GenerateExportHeader)
generate_export_header(
  Qt-Frameless-Window-DarkStyle
  BASE_NAME Qt-Frameless-Window-DarkStyle
  EXPORT_FILE_NAME export/Qt-Frameless-Window-DarkStyle/Qt-Frameless-Window-DarkStyle_export.hpp
  CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(Qt-Frameless-Window-DarkStyle PUBLIC QT_FRAMELESS_WINDOW_DARKSTYLE_STATIC_DEFINE)
endif()

set_target_properties(
  Qt-Frameless-Window-DarkStyle PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN YES
  VERSION "${PROJECT_VERSION}"
  SOVERSION "${PROJECT_VERSION_MAJOR}"
  EXPORT_NAME Qt-Frameless-Window-DarkStyle
  OUTPUT_NAME Qt-Frameless-Window-DarkStyle
)

target_include_directories(
  Qt-Frameless-Window-DarkStyle ${warning_guard}
  PUBLIC
  "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
  "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)
target_include_directories(
  Qt-Frameless-Window-DarkStyle SYSTEM
  PUBLIC
  "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(Qt-Frameless-Window-DarkStyle PUBLIC cxx_std_17)

# ---- Install rules ----
if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----
add_subdirectory(example)
