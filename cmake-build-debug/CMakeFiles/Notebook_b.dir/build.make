# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/97252/Documents/GitHub/Notebook-b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/97252/Documents/GitHub/Notebook-b/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Notebook_b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Notebook_b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Notebook_b.dir/flags.make

CMakeFiles/Notebook_b.dir/main.cpp.o: CMakeFiles/Notebook_b.dir/flags.make
CMakeFiles/Notebook_b.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/97252/Documents/GitHub/Notebook-b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Notebook_b.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Notebook_b.dir/main.cpp.o -c /mnt/c/Users/97252/Documents/GitHub/Notebook-b/main.cpp

CMakeFiles/Notebook_b.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Notebook_b.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/97252/Documents/GitHub/Notebook-b/main.cpp > CMakeFiles/Notebook_b.dir/main.cpp.i

CMakeFiles/Notebook_b.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Notebook_b.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/97252/Documents/GitHub/Notebook-b/main.cpp -o CMakeFiles/Notebook_b.dir/main.cpp.s

CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.o: CMakeFiles/Notebook_b.dir/flags.make
CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.o: ../sources/Notebook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/97252/Documents/GitHub/Notebook-b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.o -c /mnt/c/Users/97252/Documents/GitHub/Notebook-b/sources/Notebook.cpp

CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/97252/Documents/GitHub/Notebook-b/sources/Notebook.cpp > CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.i

CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/97252/Documents/GitHub/Notebook-b/sources/Notebook.cpp -o CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.s

# Object files for target Notebook_b
Notebook_b_OBJECTS = \
"CMakeFiles/Notebook_b.dir/main.cpp.o" \
"CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.o"

# External object files for target Notebook_b
Notebook_b_EXTERNAL_OBJECTS =

Notebook_b: CMakeFiles/Notebook_b.dir/main.cpp.o
Notebook_b: CMakeFiles/Notebook_b.dir/sources/Notebook.cpp.o
Notebook_b: CMakeFiles/Notebook_b.dir/build.make
Notebook_b: CMakeFiles/Notebook_b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/97252/Documents/GitHub/Notebook-b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Notebook_b"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Notebook_b.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Notebook_b.dir/build: Notebook_b

.PHONY : CMakeFiles/Notebook_b.dir/build

CMakeFiles/Notebook_b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Notebook_b.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Notebook_b.dir/clean

CMakeFiles/Notebook_b.dir/depend:
	cd /mnt/c/Users/97252/Documents/GitHub/Notebook-b/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/97252/Documents/GitHub/Notebook-b /mnt/c/Users/97252/Documents/GitHub/Notebook-b /mnt/c/Users/97252/Documents/GitHub/Notebook-b/cmake-build-debug /mnt/c/Users/97252/Documents/GitHub/Notebook-b/cmake-build-debug /mnt/c/Users/97252/Documents/GitHub/Notebook-b/cmake-build-debug/CMakeFiles/Notebook_b.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Notebook_b.dir/depend

