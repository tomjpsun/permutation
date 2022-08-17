cmake_minimum_required(VERSION 3.18)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(permutation C)

add_executable(permutation main.c stack.c bag.c)
