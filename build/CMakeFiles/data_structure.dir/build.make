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
include CMakeFiles/data_structure.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/data_structure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_structure.dir/flags.make

CMakeFiles/data_structure.dir/src/array_list.c.o: CMakeFiles/data_structure.dir/flags.make
CMakeFiles/data_structure.dir/src/array_list.c.o: ../src/array_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/doc/projects/c/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/data_structure.dir/src/array_list.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structure.dir/src/array_list.c.o   -c /Volumes/doc/projects/c/data_structure/src/array_list.c

CMakeFiles/data_structure.dir/src/array_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structure.dir/src/array_list.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Volumes/doc/projects/c/data_structure/src/array_list.c > CMakeFiles/data_structure.dir/src/array_list.c.i

CMakeFiles/data_structure.dir/src/array_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structure.dir/src/array_list.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Volumes/doc/projects/c/data_structure/src/array_list.c -o CMakeFiles/data_structure.dir/src/array_list.c.s

CMakeFiles/data_structure.dir/src/linked_list.c.o: CMakeFiles/data_structure.dir/flags.make
CMakeFiles/data_structure.dir/src/linked_list.c.o: ../src/linked_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/doc/projects/c/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/data_structure.dir/src/linked_list.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/data_structure.dir/src/linked_list.c.o   -c /Volumes/doc/projects/c/data_structure/src/linked_list.c

CMakeFiles/data_structure.dir/src/linked_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structure.dir/src/linked_list.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Volumes/doc/projects/c/data_structure/src/linked_list.c > CMakeFiles/data_structure.dir/src/linked_list.c.i

CMakeFiles/data_structure.dir/src/linked_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structure.dir/src/linked_list.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Volumes/doc/projects/c/data_structure/src/linked_list.c -o CMakeFiles/data_structure.dir/src/linked_list.c.s

# Object files for target data_structure
data_structure_OBJECTS = \
"CMakeFiles/data_structure.dir/src/array_list.c.o" \
"CMakeFiles/data_structure.dir/src/linked_list.c.o"

# External object files for target data_structure
data_structure_EXTERNAL_OBJECTS =

libdata_structure.a: CMakeFiles/data_structure.dir/src/array_list.c.o
libdata_structure.a: CMakeFiles/data_structure.dir/src/linked_list.c.o
libdata_structure.a: CMakeFiles/data_structure.dir/build.make
libdata_structure.a: CMakeFiles/data_structure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/doc/projects/c/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libdata_structure.a"
	$(CMAKE_COMMAND) -P CMakeFiles/data_structure.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_structure.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_structure.dir/build: libdata_structure.a

.PHONY : CMakeFiles/data_structure.dir/build

CMakeFiles/data_structure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data_structure.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data_structure.dir/clean

CMakeFiles/data_structure.dir/depend:
	cd /Volumes/doc/projects/c/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/doc/projects/c/data_structure /Volumes/doc/projects/c/data_structure /Volumes/doc/projects/c/data_structure/build /Volumes/doc/projects/c/data_structure/build /Volumes/doc/projects/c/data_structure/build/CMakeFiles/data_structure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data_structure.dir/depend

