cmake_minimum_required(VERSION 3.14)
project(oop_course2_semester2_lab3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
include_directories(Tests)
include_directories(files)
include_directories(Matrix)

add_executable(oop_course2_semester2_lab3 main.cpp
        Matrix/Matrix.h Matrix/Matrix.cpp
        Tests/GoogleTest.cpp)

target_link_libraries(oop_course2_semester2_lab3 gtest)