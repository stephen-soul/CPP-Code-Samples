# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /cygdrive/c/Users/Stephen/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Stephen/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TicTacToe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TicTacToe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TicTacToe.dir/flags.make

CMakeFiles/TicTacToe.dir/main.cpp.o: CMakeFiles/TicTacToe.dir/flags.make
CMakeFiles/TicTacToe.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TicTacToe.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TicTacToe.dir/main.cpp.o -c /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/main.cpp

CMakeFiles/TicTacToe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TicTacToe.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/main.cpp > CMakeFiles/TicTacToe.dir/main.cpp.i

CMakeFiles/TicTacToe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TicTacToe.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/main.cpp -o CMakeFiles/TicTacToe.dir/main.cpp.s

CMakeFiles/TicTacToe.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TicTacToe.dir/main.cpp.o.requires

CMakeFiles/TicTacToe.dir/main.cpp.o.provides: CMakeFiles/TicTacToe.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TicTacToe.dir/build.make CMakeFiles/TicTacToe.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TicTacToe.dir/main.cpp.o.provides

CMakeFiles/TicTacToe.dir/main.cpp.o.provides.build: CMakeFiles/TicTacToe.dir/main.cpp.o


CMakeFiles/TicTacToe.dir/Resources.cpp.o: CMakeFiles/TicTacToe.dir/flags.make
CMakeFiles/TicTacToe.dir/Resources.cpp.o: ../Resources.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TicTacToe.dir/Resources.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TicTacToe.dir/Resources.cpp.o -c /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/Resources.cpp

CMakeFiles/TicTacToe.dir/Resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TicTacToe.dir/Resources.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/Resources.cpp > CMakeFiles/TicTacToe.dir/Resources.cpp.i

CMakeFiles/TicTacToe.dir/Resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TicTacToe.dir/Resources.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/Resources.cpp -o CMakeFiles/TicTacToe.dir/Resources.cpp.s

CMakeFiles/TicTacToe.dir/Resources.cpp.o.requires:

.PHONY : CMakeFiles/TicTacToe.dir/Resources.cpp.o.requires

CMakeFiles/TicTacToe.dir/Resources.cpp.o.provides: CMakeFiles/TicTacToe.dir/Resources.cpp.o.requires
	$(MAKE) -f CMakeFiles/TicTacToe.dir/build.make CMakeFiles/TicTacToe.dir/Resources.cpp.o.provides.build
.PHONY : CMakeFiles/TicTacToe.dir/Resources.cpp.o.provides

CMakeFiles/TicTacToe.dir/Resources.cpp.o.provides.build: CMakeFiles/TicTacToe.dir/Resources.cpp.o


# Object files for target TicTacToe
TicTacToe_OBJECTS = \
"CMakeFiles/TicTacToe.dir/main.cpp.o" \
"CMakeFiles/TicTacToe.dir/Resources.cpp.o"

# External object files for target TicTacToe
TicTacToe_EXTERNAL_OBJECTS =

TicTacToe.exe: CMakeFiles/TicTacToe.dir/main.cpp.o
TicTacToe.exe: CMakeFiles/TicTacToe.dir/Resources.cpp.o
TicTacToe.exe: CMakeFiles/TicTacToe.dir/build.make
TicTacToe.exe: CMakeFiles/TicTacToe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TicTacToe.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TicTacToe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TicTacToe.dir/build: TicTacToe.exe

.PHONY : CMakeFiles/TicTacToe.dir/build

CMakeFiles/TicTacToe.dir/requires: CMakeFiles/TicTacToe.dir/main.cpp.o.requires
CMakeFiles/TicTacToe.dir/requires: CMakeFiles/TicTacToe.dir/Resources.cpp.o.requires

.PHONY : CMakeFiles/TicTacToe.dir/requires

CMakeFiles/TicTacToe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TicTacToe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TicTacToe.dir/clean

CMakeFiles/TicTacToe.dir/depend:
	cd /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/cmake-build-debug /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/cmake-build-debug /cygdrive/c/Users/Stephen/CLionProjects/cpp/TicTacToeCPP/cmake-build-debug/CMakeFiles/TicTacToe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TicTacToe.dir/depend

