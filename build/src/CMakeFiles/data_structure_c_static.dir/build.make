# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/doc/projects/c/data_structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/doc/projects/c/data_structure/build

# Include any dependencies generated for this target.
include src/CMakeFiles/data_structure_c_static.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/data_structure_c_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/data_structure_c_static.dir/flags.make

src/CMakeFiles/data_structure_c_static.dir/array_list.c.o: src/CMakeFiles/data_structure_c_static.dir/flags.make
src/CMakeFiles/data_structure_c_static.dir/array_list.c.o: ../src/array_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/doc/projects/c/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/data_structure_c_static.dir/array_list.c.o"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structure_c_static.dir/array_list.c.o   -c /Volumes/doc/projects/c/data_structure/src/array_list.c

src/CMakeFiles/data_structure_c_static.dir/array_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structure_c_static.dir/array_list.c.i"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Volumes/doc/projects/c/data_structure/src/array_list.c > CMakeFiles/data_structure_c_static.dir/array_list.c.i

src/CMakeFiles/data_structure_c_static.dir/array_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structure_c_static.dir/array_list.c.s"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Volumes/doc/projects/c/data_structure/src/array_list.c -o CMakeFiles/data_structure_c_static.dir/array_list.c.s

src/CMakeFiles/data_structure_c_static.dir/common.c.o: src/CMakeFiles/data_structure_c_static.dir/flags.make
src/CMakeFiles/data_structure_c_static.dir/common.c.o: ../src/common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/doc/projects/c/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/data_structure_c_static.dir/common.c.o"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structure_c_static.dir/common.c.o   -c /Volumes/doc/projects/c/data_structure/src/common.c

src/CMakeFiles/data_structure_c_static.dir/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structure_c_static.dir/common.c.i"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Volumes/doc/projects/c/data_structure/src/common.c > CMakeFiles/data_structure_c_static.dir/common.c.i

src/CMakeFiles/data_structure_c_static.dir/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structure_c_static.dir/common.c.s"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Volumes/doc/projects/c/data_structure/src/common.c -o CMakeFiles/data_structure_c_static.dir/common.c.s

src/CMakeFiles/data_structure_c_static.dir/linked_list.c.o: src/CMakeFiles/data_structure_c_static.dir/flags.make
src/CMakeFiles/data_structure_c_static.dir/linked_list.c.o: ../src/linked_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/doc/projects/c/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/data_structure_c_static.dir/linked_list.c.o"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structure_c_static.dir/linked_list.c.o   -c /Volumes/doc/projects/c/data_structure/src/linked_list.c

src/CMakeFiles/data_structure_c_static.dir/linked_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structure_c_static.dir/linked_list.c.i"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Volumes/doc/projects/c/data_structure/src/linked_list.c > CMakeFiles/data_structure_c_static.dir/linked_list.c.i

src/CMakeFiles/data_structure_c_static.dir/linked_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structure_c_static.dir/linked_list.c.s"
	cd /Volumes/doc/projects/c/data_structure/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Volumes/doc/projects/c/data_structure/src/linked_list.c -o CMakeFiles/data_structure_c_static.dir/linked_list.c.s

# Object files for target data_structure_c_static
data_structure_c_static_OBJECTS = \
"CMakeFiles/data_structure_c_static.dir/array_list.c.o" \
"CMakeFiles/data_structure_c_static.dir/common.c.o" \
"CMakeFiles/data_structure_c_static.dir/linked_list.c.o"

# External object files for target data_structure_c_static
data_structure_c_static_EXTERNAL_OBJECTS =

src/libdata_structure_c.a: src/CMakeFiles/data_structure_c_static.dir/array_list.c.o
src/libdata_structure_c.a: src/CMakeFiles/data_structure_c_static.dir/common.c.o
src/libdata_structure_c.a: src/CMakeFiles/data_structure_c_static.dir/linked_list.c.o
src/libdata_structure_c.a: src/CMakeFiles/data_structure_c_static.dir/build.make
src/libdata_structure_c.a: src/CMakeFiles/data_structure_c_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/doc/projects/c/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libdata_structure_c.a"
	cd /Volumes/doc/projects/c/data_structure/build/src && $(CMAKE_COMMAND) -P CMakeFiles/data_structure_c_static.dir/cmake_clean_target.cmake
	cd /Volumes/doc/projects/c/data_structure/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_structure_c_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/data_structure_c_static.dir/build: src/libdata_structure_c.a

.PHONY : src/CMakeFiles/data_structure_c_static.dir/build

src/CMakeFiles/data_structure_c_static.dir/clean:
	cd /Volumes/doc/projects/c/data_structure/build/src && $(CMAKE_COMMAND) -P CMakeFiles/data_structure_c_static.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/data_structure_c_static.dir/clean

src/CMakeFiles/data_structure_c_static.dir/depend:
	cd /Volumes/doc/projects/c/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/doc/projects/c/data_structure /Volumes/doc/projects/c/data_structure/src /Volumes/doc/projects/c/data_structure/build /Volumes/doc/projects/c/data_structure/build/src /Volumes/doc/projects/c/data_structure/build/src/CMakeFiles/data_structure_c_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/data_structure_c_static.dir/depend
