cmake_minimum_required(VERSION 3.19.2)
project(pipex)

set(CMAKE_C_STANDARD 99)



add_executable(pipex

        pipex.c
        check_arguments.c
        errors.c
        lib/libft.h
        )
target_link_libraries(pipex /Users/cstefany/Desktop/пипекс/lib/libft.a)
