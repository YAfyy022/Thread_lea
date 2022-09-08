cmake_minimum_required(VERSION 3.23)
project(Thread_lea)

set(CMAKE_CXX_STANDARD 11)

add_executable(Thread_lea thread_1.cpp lei_thread.cpp thread_2.cpp Thread_3.cpp Thread_4.cpp copyfunction.cpp message.cpp dynamic_memory.cpp)
