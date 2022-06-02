cmake_minimum_required(VERSION 3.22)
project(diplomski_tuga)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -lz -ltbb")
set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES header.h type.h const.h embedding.h ksw2.h)

add_executable(diplomski_tuga main.cpp reference.cpp embedding.cpp ksw2_extz2_sse.c)
