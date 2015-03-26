cmake_minimum_required(VERSION 2.8)

project(stringn)

file(GLOB SOURCES "stringn.c")
file(GLOB HEADERS "stringn.h")

add_library(stringn_shared SHARED "${SOURCES}")
add_library(stringn_static STATIC "${SOURCES}")
set_target_properties(
    stringn_shared
    PROPERTIES
    OUTPUT_NAME stringn
    SOVERSION 0
    VERSION 0.0.1
)
set_target_properties(
    stringn_static
    PROPERTIES
    OUTPUT_NAME stringn
)

include(GNUInstallDirs)
install(
    TARGETS stringn_shared stringn_static
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(
    FILES ${HEADERS}
    DESTINATION include
)
