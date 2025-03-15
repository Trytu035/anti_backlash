cmake_minimum_required(VERSION 3.10.0)
project(my_project VERSION 0.1.0 LANGUAGES C)

file (GLOB_RECURSE my_project_SOURCES CONFIGURE_DEPENDS "src/*.c")

add_executable(my_project_executable ${my_project_SOURCES})
# add_executable(my_project_executable main.c)

