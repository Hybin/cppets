cmake_minimum_required(VERSION 3.0.0)
project(cppets VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(cppets src/cppets.cpp)
add_library(cppets_shared SHARED src/cppets.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
