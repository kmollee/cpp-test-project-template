cmake_minimum_required(VERSION 3.10)
project(sample)

set(CMAKE_CXX_STANDARD 17)


include_directories(src)
include_directories(include)
add_subdirectory(src)
#set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
add_subdirectory(lib/googletest)

enable_testing()
add_subdirectory(test)


