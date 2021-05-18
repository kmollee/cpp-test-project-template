set(TEST_BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${GMOCK_INCLUDE_DIRS}" "${GTEST_INCLUDE_DIRS}")
add_executable(${TEST_BINARY} ${TEST_SOURCES})
add_test(NAME ${TEST_BINARY} COMMAND ${TEST_BINARY})
target_link_libraries(${TEST_BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gmock gtest pthread)
add_custom_target(check
        COMMAND env CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND}
        DEPENDS ${TEST_BINARY})

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_test)