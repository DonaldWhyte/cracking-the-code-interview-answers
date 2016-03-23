cmake_minimum_required(VERSION 2.8)

# Common Setup

# set build/artefact directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# use C++11
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_definitions(-std=gnu++0x)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions(-std=c++11)
endif()

# Individual Chapters
add_subdirectory(ch01-arraysstrings)
add_subdirectory(ch02-linkedlists)
add_subdirectory(ch03-stacksqueues)
add_subdirectory(ch04-treesgraphs)
add_subdirectory(ch05-bitmanip)
add_subdirectory(ch06-brainteasters)
add_subdirectory(ch07-mathsprob)
add_subdirectory(ch08-ood)
add_subdirectory(ch09-recursion)
add_subdirectory(ch10-scalabilitymemory)
add_subdirectory(ch11-sortingsearching)
add_subdirectory(ch12-testing)
add_subdirectory(ch13-cpp)
add_subdirectory(ch14-java)
add_subdirectory(ch15-databases)
add_subdirectory(ch16-theadslocks)
add_subdirectory(ch17-moderate)
add_subdirectory(ch18-hard)
