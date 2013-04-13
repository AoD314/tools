cmake_minimum_required(VERSION 2.8.6)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(cmake/general.cmake)

clear_dependency()
add_dependency("opencv")

add_subdirectory(matrix_image)
add_subdirectory(convert)

set_solution("tools")
