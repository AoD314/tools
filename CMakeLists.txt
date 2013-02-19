cmake_minimum_required(VERSION 2.8.10)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(cmake/general.cmake)

set_solution("tools")

set_dependency("opencv" "webp")

add_subdirectory(matrix_image)

add_subdirectory(convert)