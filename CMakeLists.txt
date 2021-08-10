cmake_minimum_required(VERSION 3.21)
project(Solitaire)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solitaire main.cpp Card.cpp Card.h)
target_link_libraries(Solitaire "/usr/lib/libraylib.so")