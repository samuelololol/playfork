cmake_minimum_required(VERSION 3.14)

project(signal_poc)

find_package(Boost REQUIRED COMPONENTS system filesystem thread serialization)

set(CMAKE_CXX_STANDARD 98)

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(signal_poc parent.cpp)

add_executable(child child.cpp)

target_link_libraries(child ${Boost_LIBRARIES})

