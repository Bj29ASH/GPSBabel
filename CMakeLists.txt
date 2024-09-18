cmake_minimum_required(VERSION 3.27)
project(GPSBabel VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(GPSBabel INTERFACE)

target_include_directories(GPSBabel
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/GPSBabel>
)

target_link_directories(GPSBabel
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib>
  $<INSTALL_INTERFACE:lib/GPSBabel>
)

target_link_libraries(GPSBabel
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/gpsbabel.lib>
  $<INSTALL_INTERFACE:gpsbabel.lib>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/shp.lib>
  $<INSTALL_INTERFACE:shp.lib>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/strptime.lib>
  $<INSTALL_INTERFACE:strptime.lib>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/z.lib>
  $<INSTALL_INTERFACE:z.lib>
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/GPSBabelConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/GPSBabelConfig.cmake"
  INSTALL_DESTINATION share/GPSBabel
)

install(TARGETS GPSBabel
  EXPORT GPSBabelTargets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

file(GLOB GPSBABEL_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

install(FILES ${GPSBABEL_HEADERS} DESTINATION include/GPSBabel)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/deprecated DESTINATION include/GPSBabel)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/gui DESTINATION include/GPSBabel)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/jeeps DESTINATION include/GPSBabel)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/mac DESTINATION include/GPSBabel)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/shapelib DESTINATION include/GPSBabel)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/src DESTINATION include/GPSBabel)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/strptime DESTINATION include/GPSBabel)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/zlib DESTINATION include/GPSBabel)

install(FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/gpsbabel.lib"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/shp.lib"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/strptime.lib"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/z.lib"
  DESTINATION lib/GPSBabel
)

install(
  EXPORT GPSBabelTargets
  DESTINATION share/GPSBabel
  NAMESPACE GPSBabel::
)

install(
  FILES
  "${CMAKE_CURRENT_BINARY_DIR}/GPSBabelConfig.cmake"
  DESTINATION share/GPSBabel
)