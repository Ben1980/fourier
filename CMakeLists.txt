cmake_minimum_required(VERSION 3.12)
project(fourier)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++17 -O3")

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(helperlib)