cmake_minimum_required(VERSION 3.17)
project(kpi_labs_c C)

file(GLOB src "src/*.h" "src/*.c")
add_executable(kpi_labs_c ${src})

add_executable(math_tasks src/bin/math_tasks.c)
