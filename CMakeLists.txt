cmake_minimum_required (VERSION 3.2)


set (CMAKE_CXX_STANDARD 11)

add_library(RandomGenerator STATIC RandomGenerator.cpp RandomGenerator.h)


add_executable(Example test.cpp )
target_Link_libraries(Example PRIVATE RandomGenerator)