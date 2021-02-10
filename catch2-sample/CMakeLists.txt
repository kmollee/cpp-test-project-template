cmake_minimum_required(VERSION 3.10)
project(sample)

set(CMAKE_CXX_STANDARD 17)


include_directories(src)
include_directories(include)

add_subdirectory(src)


######## Test #########
# enable testing

enable_testing()
add_subdirectory(test)
add_subdirectory(lib)
