if(PROJECT_IS_TOP_LEVEL)
    set(CMAKE_INSTALL_INCLUDEDIR include/Qt-Frameless-Window-DarkStyle CACHE PATH "")
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package Qt-Frameless-Window-DarkStyle)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT Qt-Frameless-Window-DarkStyle_Development
)

install(
    TARGETS Qt-Frameless-Window-DarkStyle
    EXPORT Qt-Frameless-Window-DarkStyleTargets
    RUNTIME #
    COMPONENT Qt-Frameless-Window-DarkStyle_Runtime
    LIBRARY #
    COMPONENT Qt-Frameless-Window-DarkStyle_Runtime
    NAMELINK_COMPONENT Qt-Frameless-Window-DarkStyle_Development
    ARCHIVE #
    COMPONENT Qt-Frameless-Window-DarkStyle_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    Qt-Frameless-Window-DarkStyle_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE PATH "CMake package config location relative to the install prefix"
)
mark_as_advanced(Qt-Frameless-Window-DarkStyle_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${Qt-Frameless-Window-DarkStyle_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT Qt-Frameless-Window-DarkStyle_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${Qt-Frameless-Window-DarkStyle_INSTALL_CMAKEDIR}"
    COMPONENT Qt-Frameless-Window-DarkStyle_Development
)

install(
    EXPORT Qt-Frameless-Window-DarkStyleTargets
    NAMESPACE Qt-Frameless-Window-DarkStyle::
    DESTINATION "${Qt-Frameless-Window-DarkStyle_INSTALL_CMAKEDIR}"
    COMPONENT Qt-Frameless-Window-DarkStyle_Development
)

if(PROJECT_IS_TOP_LEVEL)
    include(CPack)
endif()
