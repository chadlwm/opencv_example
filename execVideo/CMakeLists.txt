cmake_minimum_required(VERSION 2.8)
project( Video )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( VideoCapture videoCapture.cpp )
add_executable( VideoWrite videoWrite.cpp )
target_link_libraries( VideoWrite ${OpenCV_LIBS} )
target_link_libraries( VideoCapture ${OpenCV_LIBS} )