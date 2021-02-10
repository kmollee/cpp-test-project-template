cmake_minimum_required(VERSION 3.5)

project(catch2 LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include/)
