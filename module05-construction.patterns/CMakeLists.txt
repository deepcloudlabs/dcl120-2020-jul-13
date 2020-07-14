cmake_minimum_required(VERSION 3.16)
project(module05_construction_patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(composite-person builder/composite-person.cpp builder/Person.h builder/Person.cpp builder/PersonAddressBuilder.h builder/PersonJobBuilder.h builder/PersonBuilder.h builder/PersonBuilder.cpp)
add_executable(factory-method factory-method/point.cpp)

add_executable(point factory-method/point.cpp)
add_executable(inner-factory abstract-factory/InnerFactory.cpp)
add_executable(factory-exercise abstract-factory/FactoryExercise.cpp)
add_executable(factory abstract-factory/Factory.cpp)
add_executable(abstract-factory abstract-factory/AbstractFactory.cpp)
add_executable(memento memento/memento.cpp)