cmake_minimum_required(VERSION 2.8)
project( Video )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach( infileName ${APP_SOURCES} )
  message(STATUS "process ${infileName}" )
  STRING(REGEX REPLACE ".cpp\$" "" outfileName "${infileName}")
  message(STATUS "output ${outfileName}" )

  add_executable( ${outfileName} ${infileName} )
  target_link_libraries( ${outfileName} ${OpenCV_LIBS} )
endforeach( infileName ${APP_SOURCES} )