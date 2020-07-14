cmake_minimum_required(VERSION 3.16)
project(module04_responsibility_patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(singleton singleton/study-singleton.cpp)
add_executable(proxy proxy/study-proxy.cpp)
add_executable(observer observer/study-observer.cpp)