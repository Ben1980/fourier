cmake_minimum_required(VERSION 3.14)
project(lib)

set(SOURCE fourier.h dft.h cooleyTukey.h radixFour.h helper.h helper.cpp)
add_library(${PROJECT_NAME} ${SOURCE})

find_package(fmt CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt fmt::fmt-header-only doctest::doctest)