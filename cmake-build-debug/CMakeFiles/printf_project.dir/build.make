# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/johann/Documents/Computerscience/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/johann/Documents/Computerscience/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/johann/Work/printf_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johann/Work/printf_project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/printf_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/printf_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/printf_project.dir/flags.make

CMakeFiles/printf_project.dir/main.c.o: CMakeFiles/printf_project.dir/flags.make
CMakeFiles/printf_project.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johann/Work/printf_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/printf_project.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/printf_project.dir/main.c.o   -c /home/johann/Work/printf_project/main.c

CMakeFiles/printf_project.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/printf_project.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/johann/Work/printf_project/main.c > CMakeFiles/printf_project.dir/main.c.i

CMakeFiles/printf_project.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/printf_project.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/johann/Work/printf_project/main.c -o CMakeFiles/printf_project.dir/main.c.s

CMakeFiles/printf_project.dir/main.c.o.requires:

.PHONY : CMakeFiles/printf_project.dir/main.c.o.requires

CMakeFiles/printf_project.dir/main.c.o.provides: CMakeFiles/printf_project.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/printf_project.dir/build.make CMakeFiles/printf_project.dir/main.c.o.provides.build
.PHONY : CMakeFiles/printf_project.dir/main.c.o.provides

CMakeFiles/printf_project.dir/main.c.o.provides.build: CMakeFiles/printf_project.dir/main.c.o


# Object files for target printf_project
printf_project_OBJECTS = \
"CMakeFiles/printf_project.dir/main.c.o"

# External object files for target printf_project
printf_project_EXTERNAL_OBJECTS =

printf_project: CMakeFiles/printf_project.dir/main.c.o
printf_project: CMakeFiles/printf_project.dir/build.make
printf_project: CMakeFiles/printf_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johann/Work/printf_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable printf_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/printf_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/printf_project.dir/build: printf_project

.PHONY : CMakeFiles/printf_project.dir/build

CMakeFiles/printf_project.dir/requires: CMakeFiles/printf_project.dir/main.c.o.requires

.PHONY : CMakeFiles/printf_project.dir/requires

CMakeFiles/printf_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/printf_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/printf_project.dir/clean

CMakeFiles/printf_project.dir/depend:
	cd /home/johann/Work/printf_project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johann/Work/printf_project /home/johann/Work/printf_project /home/johann/Work/printf_project/cmake-build-debug /home/johann/Work/printf_project/cmake-build-debug /home/johann/Work/printf_project/cmake-build-debug/CMakeFiles/printf_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/printf_project.dir/depend

