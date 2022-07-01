cmake_minimum_required(VERSION 3.19)
project(Carshowrooms)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Carshowrooms
        include/admin.h
        include/customer.h
        include/garage.h
        include/showrooms.h
        src/admin.cpp
        src/customer.cpp
        src/garage.cpp
        src/showrooms.cpp
        main.cpp)
