# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/mtm/cmake-3.17.0-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/mtm/cmake-3.17.0-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maorben/mtm/ex1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maorben/mtm/build

# Include any dependencies generated for this target.
include CMakeFiles/amount_set_str.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/amount_set_str.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/amount_set_str.dir/flags.make

CMakeFiles/amount_set_str.dir/amount_set_str.c.o: CMakeFiles/amount_set_str.dir/flags.make
CMakeFiles/amount_set_str.dir/amount_set_str.c.o: /home/maorben/mtm/ex1/amount_set_str.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maorben/mtm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/amount_set_str.dir/amount_set_str.c.o"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/amount_set_str.dir/amount_set_str.c.o   -c /home/maorben/mtm/ex1/amount_set_str.c

CMakeFiles/amount_set_str.dir/amount_set_str.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/amount_set_str.dir/amount_set_str.c.i"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maorben/mtm/ex1/amount_set_str.c > CMakeFiles/amount_set_str.dir/amount_set_str.c.i

CMakeFiles/amount_set_str.dir/amount_set_str.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/amount_set_str.dir/amount_set_str.c.s"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maorben/mtm/ex1/amount_set_str.c -o CMakeFiles/amount_set_str.dir/amount_set_str.c.s

CMakeFiles/amount_set_str.dir/linkedList.c.o: CMakeFiles/amount_set_str.dir/flags.make
CMakeFiles/amount_set_str.dir/linkedList.c.o: /home/maorben/mtm/ex1/linkedList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maorben/mtm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/amount_set_str.dir/linkedList.c.o"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/amount_set_str.dir/linkedList.c.o   -c /home/maorben/mtm/ex1/linkedList.c

CMakeFiles/amount_set_str.dir/linkedList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/amount_set_str.dir/linkedList.c.i"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maorben/mtm/ex1/linkedList.c > CMakeFiles/amount_set_str.dir/linkedList.c.i

CMakeFiles/amount_set_str.dir/linkedList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/amount_set_str.dir/linkedList.c.s"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maorben/mtm/ex1/linkedList.c -o CMakeFiles/amount_set_str.dir/linkedList.c.s

CMakeFiles/amount_set_str.dir/tests.c.o: CMakeFiles/amount_set_str.dir/flags.make
CMakeFiles/amount_set_str.dir/tests.c.o: /home/maorben/mtm/ex1/tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maorben/mtm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/amount_set_str.dir/tests.c.o"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/amount_set_str.dir/tests.c.o   -c /home/maorben/mtm/ex1/tests.c

CMakeFiles/amount_set_str.dir/tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/amount_set_str.dir/tests.c.i"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maorben/mtm/ex1/tests.c > CMakeFiles/amount_set_str.dir/tests.c.i

CMakeFiles/amount_set_str.dir/tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/amount_set_str.dir/tests.c.s"
	/usr/local/bin/x86_64-unknown-linux-gnu-gcc-5.5.0 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maorben/mtm/ex1/tests.c -o CMakeFiles/amount_set_str.dir/tests.c.s

# Object files for target amount_set_str
amount_set_str_OBJECTS = \
"CMakeFiles/amount_set_str.dir/amount_set_str.c.o" \
"CMakeFiles/amount_set_str.dir/linkedList.c.o" \
"CMakeFiles/amount_set_str.dir/tests.c.o"

# External object files for target amount_set_str
amount_set_str_EXTERNAL_OBJECTS =

amount_set_str: CMakeFiles/amount_set_str.dir/amount_set_str.c.o
amount_set_str: CMakeFiles/amount_set_str.dir/linkedList.c.o
amount_set_str: CMakeFiles/amount_set_str.dir/tests.c.o
amount_set_str: CMakeFiles/amount_set_str.dir/build.make
amount_set_str: CMakeFiles/amount_set_str.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maorben/mtm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable amount_set_str"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/amount_set_str.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/amount_set_str.dir/build: amount_set_str

.PHONY : CMakeFiles/amount_set_str.dir/build

CMakeFiles/amount_set_str.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/amount_set_str.dir/cmake_clean.cmake
.PHONY : CMakeFiles/amount_set_str.dir/clean

CMakeFiles/amount_set_str.dir/depend:
	cd /home/maorben/mtm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maorben/mtm/ex1 /home/maorben/mtm/ex1 /home/maorben/mtm/build /home/maorben/mtm/build /home/maorben/mtm/build/CMakeFiles/amount_set_str.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/amount_set_str.dir/depend
