cmake_minimum_required(VERSION 3.5)

project(test)
add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest-main/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp DateTest.cpp HourTest.cpp ListTest.cpp)
add_executable(test ${TEST_SOURCE_FILES})

target_link_libraries(test gtest gtest_main core)


