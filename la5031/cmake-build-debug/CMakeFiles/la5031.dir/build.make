# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jason/Documents/GitHub/acm_practices/la5031

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jason/Documents/GitHub/acm_practices/la5031/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/la5031.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/la5031.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/la5031.dir/flags.make

CMakeFiles/la5031.dir/main.cpp.o: CMakeFiles/la5031.dir/flags.make
CMakeFiles/la5031.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jason/Documents/GitHub/acm_practices/la5031/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/la5031.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/la5031.dir/main.cpp.o -c /Users/jason/Documents/GitHub/acm_practices/la5031/main.cpp

CMakeFiles/la5031.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/la5031.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jason/Documents/GitHub/acm_practices/la5031/main.cpp > CMakeFiles/la5031.dir/main.cpp.i

CMakeFiles/la5031.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/la5031.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jason/Documents/GitHub/acm_practices/la5031/main.cpp -o CMakeFiles/la5031.dir/main.cpp.s

CMakeFiles/la5031.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/la5031.dir/main.cpp.o.requires

CMakeFiles/la5031.dir/main.cpp.o.provides: CMakeFiles/la5031.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/la5031.dir/build.make CMakeFiles/la5031.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/la5031.dir/main.cpp.o.provides

CMakeFiles/la5031.dir/main.cpp.o.provides.build: CMakeFiles/la5031.dir/main.cpp.o


# Object files for target la5031
la5031_OBJECTS = \
"CMakeFiles/la5031.dir/main.cpp.o"

# External object files for target la5031
la5031_EXTERNAL_OBJECTS =

la5031: CMakeFiles/la5031.dir/main.cpp.o
la5031: CMakeFiles/la5031.dir/build.make
la5031: CMakeFiles/la5031.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jason/Documents/GitHub/acm_practices/la5031/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable la5031"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/la5031.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/la5031.dir/build: la5031

.PHONY : CMakeFiles/la5031.dir/build

CMakeFiles/la5031.dir/requires: CMakeFiles/la5031.dir/main.cpp.o.requires

.PHONY : CMakeFiles/la5031.dir/requires

CMakeFiles/la5031.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/la5031.dir/cmake_clean.cmake
.PHONY : CMakeFiles/la5031.dir/clean

CMakeFiles/la5031.dir/depend:
	cd /Users/jason/Documents/GitHub/acm_practices/la5031/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jason/Documents/GitHub/acm_practices/la5031 /Users/jason/Documents/GitHub/acm_practices/la5031 /Users/jason/Documents/GitHub/acm_practices/la5031/cmake-build-debug /Users/jason/Documents/GitHub/acm_practices/la5031/cmake-build-debug /Users/jason/Documents/GitHub/acm_practices/la5031/cmake-build-debug/CMakeFiles/la5031.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/la5031.dir/depend
