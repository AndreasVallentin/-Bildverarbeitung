cmake_minimum_required(VERSION 3.23)
project(uebung_2)

set(CMAKE_CXX_STANDARD 14)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(uebung_2 main.cpp)
target_link_libraries( uebung_2 ${OpenCV_LIBS} )