cmake_minimum_required(VERSION 3.12)
project(helperlib)

set(SOURCE fourier.h fourier.cpp 
            helper.h helper.cpp)
add_library(${PROJECT_NAME} ${SOURCE})

find_package(Boost REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})