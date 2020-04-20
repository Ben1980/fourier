cmake_minimum_required(VERSION 3.12)
project(helperlib)

set(SOURCE fourier.h fourier.cpp 
            helper.h helper.cpp)
add_library(${PROJECT_NAME} ${SOURCE})
