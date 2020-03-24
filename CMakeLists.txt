cmake_minimum_required(VERSION 3.10)
project(NeuralNetworkC++)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src include)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
