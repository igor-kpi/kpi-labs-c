cmake_minimum_required(VERSION 3.17)
project(kpi_labs_c C)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")

file(GLOB src "src/*.h" "src/*.c")
add_executable(kpi_labs_c ${src})

add_executable(math_tasks src/bin/math_tasks.c)
add_executable(linked_list src/bin/linked_list.c)
