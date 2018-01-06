cmake_minimum_required(VERSION 3.7)
project(cpp02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cxx Queue.cxx Queue.h Customer.cxx Customer.h Customer.cxx)
add_executable(cpp02 ${SOURCE_FILES})

#
#
#cmake_minimum_required(VERSION 3.7)
#project(t2)
#
#set(CMAKE_CXX_STANDARD 11)
#
#set(SOURCE_FILES main.cpp)
#add_executable(t2 ${SOURCE_FILES})