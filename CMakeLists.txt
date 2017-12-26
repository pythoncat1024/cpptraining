cmake_minimum_required(VERSION 3.7)
project(cpp02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cxx Time.cxx Time.h)
add_executable(cpp02 ${SOURCE_FILES})