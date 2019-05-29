cmake_minimum_required(VERSION 3.14)
project(signal_poc)

set(CMAKE_CXX_STANDARD 98)

add_executable(signal_poc parent.cpp)

add_executable(child child.cpp)

