cmake_minimum_required(VERSION 3.14)
project("matrix")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Основное приложение
add_executable(a.out main.cpp)
target_include_directories(a.out PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(tests tests/test_main.cpp)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

gtest_discover_tests(tests)

