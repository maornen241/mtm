# The first line states the minimum CMake version to use with this project
# and is requires by CMake.
cmake_minimum_required(VERSION 3.0.0)

# Set <PROJNAME> to be your project name. We set C here as the target language.
project(amount_set_str VERSION 0.1.0 LANGUAGES C)

# If you want to see "under the hood" of CMake, uncomment this:
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c99 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_C_FLAGS ${MTM_FLAGS_DEBUG})


# Add the names of your source files here
#set(C_FILES "<YOURFILENAMES>")

add_executable(amount_set_str_main amount_set_str_main.c amount_set_str.c amount_set_str_linkedList.c  amount_set_str_tests.c)