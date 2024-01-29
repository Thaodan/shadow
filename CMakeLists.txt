cmake_minimum_required(VERSION 3.5)

set(LIBSHADOWUTILS_VERS 4.16.0)

project(libshadowutils
  LANGUAGES C
  VERSION ${LIBSHADOWUTILS_VERS})

include(GNUInstallDirs)

add_definitions(-D "\"_(Text)= Text\"")

# We want GNU extensions of libc
add_definitions(-D_GNU_SOURCE)

file(GLOB LIBSHADOWUTILS_SOURCES
  "${libshadowutils_SOURCE_DIR}/lib/getdef.c"
  "${libshadowutils_SOURCE_DIR}/lib/getlong.c"
  "${libshadowutils_SOURCE_DIR}/lib/getulong.c"
  "${libshadowutils_SOURCE_DIR}/lib/shadowlog.c"
  "${libshadowutils_SOURCE_DIR}/lib/atoi/a2i.c"
  "${libshadowutils_SOURCE_DIR}/lib/atoi/strtoi.c"
  "${libshadowutils_SOURCE_DIR}/lib/atoi/strtou_noneg.c"
  "${libshadowutils_SOURCE_DIR}/lib/atoi/str2i.c"
)

file(GLOB LIBSHADOWUTILS_HEADERS
  "${libshadowutils_SOURCE_DIR}/lib/getdef.h")
set(LIBSHADOWUTILS_DOC
  "README.libshadowutils")

# Shared library

add_library(shadowutils SHARED ${LIBSHADOWUTILS_SOURCES})
set_target_properties(shadowutils PROPERTIES
  VERSION ${LIBSHADOWUTILS_VERSION}
  SOVERSION ${LIBSHADOWUTILS_VERSION_SONAME})
target_include_directories(shadowutils
  PRIVATE
  ${libshadowutils_SOURCE_DIR}
  ${libshadowutils_SOURCE_DIR}/lib
  ${CMAKE_CURRENT_BINARY_DIR})

# Unit tests

enable_testing()
add_executable(test_getdef test_getdef.c)
target_link_libraries(test_getdef shadowutils)
add_test(test_getdef test_getdef)


# Installation

configure_file(${libshadowutils_SOURCE_DIR}/libshadowutils.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/libshadowutils.pc
  @ONLY)

# Taken from Autoconf
set(LIBSUBID_ABI_MAJOR 5)
set(LIBSUBID_ABI_MINOR 0)
set(LIBSUBID_ABI_MICRO 0)
set(LIBSUBID_ABI ${LIBSUBID_ABI_MAJOR}.${LIBSUBID_ABI_MINOR}.${LIBSUBID_ABI_MICRO})

configure_file(${libshadowutils_SOURCE_DIR}/libsubid/subid.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/libsubid/subid.h
  @ONLY)

install(TARGETS shadowutils
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${LIBSHADOWUTILS_HEADERS}
  DESTINATION include/libshadowutils)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libshadowutils.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
install(FILES ${LIBSHADOWUTILS_DOC}
  DESTINATION ${CMAKE_INSTALL_DOCDIR})
