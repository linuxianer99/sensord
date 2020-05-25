cmake_minimum_required(VERSION 3.2)

#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

# set the project name
project(sensord C)

#include(CMakePrintHelpers)

# Enable ctest helpers
#enable_testing()

# add subdirectory
add_subdirectory(src)
#add_subdirectory(tests)
