cmake_minimum_required(VERSION 3.22)
project(diplomski_index_tuga)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -lz -ltbb")
set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES header.h type.h const.h embedding.h)

add_executable(diplomski_tuga index.cpp embedding.cpp)
