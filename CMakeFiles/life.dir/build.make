# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure

# Include any dependencies generated for this target.
include CMakeFiles/life.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/life.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/life.dir/flags.make

CMakeFiles/life.dir/src/life.c.o: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/src/life.c.o: src/life.c
CMakeFiles/life.dir/src/life.c.o: CMakeFiles/life.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/life.dir/src/life.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/life.dir/src/life.c.o -MF CMakeFiles/life.dir/src/life.c.o.d -o CMakeFiles/life.dir/src/life.c.o -c /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/src/life.c

CMakeFiles/life.dir/src/life.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/life.dir/src/life.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/src/life.c > CMakeFiles/life.dir/src/life.c.i

CMakeFiles/life.dir/src/life.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/life.dir/src/life.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/src/life.c -o CMakeFiles/life.dir/src/life.c.s

CMakeFiles/life.dir/src/main.c.o: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/src/main.c.o: src/main.c
CMakeFiles/life.dir/src/main.c.o: CMakeFiles/life.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/life.dir/src/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/life.dir/src/main.c.o -MF CMakeFiles/life.dir/src/main.c.o.d -o CMakeFiles/life.dir/src/main.c.o -c /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/src/main.c

CMakeFiles/life.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/life.dir/src/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/src/main.c > CMakeFiles/life.dir/src/main.c.i

CMakeFiles/life.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/life.dir/src/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/src/main.c -o CMakeFiles/life.dir/src/main.c.s

# Object files for target life
life_OBJECTS = \
"CMakeFiles/life.dir/src/life.c.o" \
"CMakeFiles/life.dir/src/main.c.o"

# External object files for target life
life_EXTERNAL_OBJECTS =

life: CMakeFiles/life.dir/src/life.c.o
life: CMakeFiles/life.dir/src/main.c.o
life: CMakeFiles/life.dir/build.make
life: _deps/raylib-build/raylib/libraylib.a
life: CMakeFiles/life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable life"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/life.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/life.dir/build: life
.PHONY : CMakeFiles/life.dir/build

CMakeFiles/life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/life.dir/cmake_clean.cmake
.PHONY : CMakeFiles/life.dir/clean

CMakeFiles/life.dir/depend:
	cd /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure /Users/mvillafloran/Documents/GitHub/Projects/musical-adventure/CMakeFiles/life.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/life.dir/depend
