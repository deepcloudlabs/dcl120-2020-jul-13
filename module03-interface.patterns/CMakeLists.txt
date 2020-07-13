cmake_minimum_required(VERSION 3.16)
project(module03_interface_patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(study-adapter adapter/study-adapter.cpp)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED OFF)
set(Boost_USE_STATIC_RUNTIME ON)

set(BOOST_ROOT "D:/DEVEL/stage/opt/boost_1_73_0")
set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}")
set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/stage/lib")
include_directories(${BOOST_INCLUDE_DIRS})
add_executable(study-adapter-with-caching adapter/study-adapter-with-caching.cpp)
target_link_libraries(study-adapter-with-caching ${BOOST_LIBRARY_DIRS})

add_executable(trading-api facade/trading-api.cpp)

