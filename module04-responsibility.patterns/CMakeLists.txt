cmake_minimum_required(VERSION 3.16)
project(module04_responsibility_patterns)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED OFF)
set(Boost_USE_STATIC_RUNTIME ON)

set(BOOST_ROOT "D:/DEVEL/stage/opt/boost_1_73_0")
set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}")
set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/stage/lib")
include_directories(${BOOST_INCLUDE_DIRS})

add_executable(chat mediator/chat.cpp mediator/person.h mediator/person.cpp  mediator/chatroom.h mediator/chatroom.cpp)
target_link_libraries(chat ${BOOST_LIBRARY_DIRS})
add_executable(soccer mediator/soccer.cpp)
target_link_libraries(soccer ${BOOST_LIBRARY_DIRS})

add_executable(singleton singleton/study-singleton.cpp)
add_executable(proxy proxy/study-proxy.cpp)
add_executable(observer observer/study-observer.cpp)
add_executable(chain-of-responsibility chain-of-responsibility/study-chain.cpp)

add_executable(object-caching flyweight/object-caching.cpp)
target_link_libraries(object-caching ${BOOST_LIBRARY_DIRS})