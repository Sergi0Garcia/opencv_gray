cmake_minimum_required(VERSION 2.8)
project(opencv_gray)

find_package(OpenCV REQUIRED)

include_directories(
include
${OpenCV_INCLUDE_DIRS}
)

add_executable(
	gray
	src/main.cpp
	)

target_link_libraries(gray ${OpenCV_LIBS})