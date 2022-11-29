cmake_minimum_required(VERSION 3.23)
project(bannikov_v_mystring)

set(CMAKE_CXX_STANDARD 20)

add_executable(bannikov_v_mystring main.cpp mystd.h MyString.cpp)

add_subdirectory(MyStringTest)
