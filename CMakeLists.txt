cmake_minimum_required(VERSION 3.10)

project(StudentInfoSystem)

#Using c++17 for easier use

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory setup
include_directories(include)

#create executable file from sources
add_executable(sis-app src/main.cpp)

