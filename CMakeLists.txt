cmake_minimum_required(VERSION 3.12)
project(CO2 C)

set(CMAKE_C_STANDARD 99)

add_executable(CO2 main.c co2/include/Object.h co2/include/utils.h co2/src/Object.c demo/Shape.c demo/Shape.h co2/include/all.h co2/src/allocate.c co2/include/allocate.h demo/Rectangle.c demo/Rectangle.h co2/include/allocate.h demo/Square.c demo/Square.h co2/src/utils.c demo/Circle.c demo/Circle.h)