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
CMAKE_SOURCE_DIR = /Users/jason/Documents/GitHub/acm_practices/magicalgcd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jason/Documents/GitHub/acm_practices/magicalgcd/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/magicalgcd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/magicalgcd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/magicalgcd.dir/flags.make

CMakeFiles/magicalgcd.dir/main.cpp.o: CMakeFiles/magicalgcd.dir/flags.make
CMakeFiles/magicalgcd.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jason/Documents/GitHub/acm_practices/magicalgcd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/magicalgcd.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/magicalgcd.dir/main.cpp.o -c /Users/jason/Documents/GitHub/acm_practices/magicalgcd/main.cpp

CMakeFiles/magicalgcd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/magicalgcd.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jason/Documents/GitHub/acm_practices/magicalgcd/main.cpp > CMakeFiles/magicalgcd.dir/main.cpp.i

CMakeFiles/magicalgcd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/magicalgcd.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jason/Documents/GitHub/acm_practices/magicalgcd/main.cpp -o CMakeFiles/magicalgcd.dir/main.cpp.s

CMakeFiles/magicalgcd.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/magicalgcd.dir/main.cpp.o.requires

CMakeFiles/magicalgcd.dir/main.cpp.o.provides: CMakeFiles/magicalgcd.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/magicalgcd.dir/build.make CMakeFiles/magicalgcd.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/magicalgcd.dir/main.cpp.o.provides

CMakeFiles/magicalgcd.dir/main.cpp.o.provides.build: CMakeFiles/magicalgcd.dir/main.cpp.o


# Object files for target magicalgcd
magicalgcd_OBJECTS = \
"CMakeFiles/magicalgcd.dir/main.cpp.o"

# External object files for target magicalgcd
magicalgcd_EXTERNAL_OBJECTS =

magicalgcd: CMakeFiles/magicalgcd.dir/main.cpp.o
magicalgcd: CMakeFiles/magicalgcd.dir/build.make
magicalgcd: CMakeFiles/magicalgcd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jason/Documents/GitHub/acm_practices/magicalgcd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable magicalgcd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/magicalgcd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/magicalgcd.dir/build: magicalgcd

.PHONY : CMakeFiles/magicalgcd.dir/build

CMakeFiles/magicalgcd.dir/requires: CMakeFiles/magicalgcd.dir/main.cpp.o.requires

.PHONY : CMakeFiles/magicalgcd.dir/requires

CMakeFiles/magicalgcd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/magicalgcd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/magicalgcd.dir/clean

CMakeFiles/magicalgcd.dir/depend:
	cd /Users/jason/Documents/GitHub/acm_practices/magicalgcd/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jason/Documents/GitHub/acm_practices/magicalgcd /Users/jason/Documents/GitHub/acm_practices/magicalgcd /Users/jason/Documents/GitHub/acm_practices/magicalgcd/cmake-build-debug /Users/jason/Documents/GitHub/acm_practices/magicalgcd/cmake-build-debug /Users/jason/Documents/GitHub/acm_practices/magicalgcd/cmake-build-debug/CMakeFiles/magicalgcd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/magicalgcd.dir/depend
