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
CMAKE_SOURCE_DIR = /Users/jason/Documents/GitHub/acm_practices/vuk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jason/Documents/GitHub/acm_practices/vuk/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vuk.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vuk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vuk.dir/flags.make

CMakeFiles/vuk.dir/main.cpp.o: CMakeFiles/vuk.dir/flags.make
CMakeFiles/vuk.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jason/Documents/GitHub/acm_practices/vuk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vuk.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vuk.dir/main.cpp.o -c /Users/jason/Documents/GitHub/acm_practices/vuk/main.cpp

CMakeFiles/vuk.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vuk.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jason/Documents/GitHub/acm_practices/vuk/main.cpp > CMakeFiles/vuk.dir/main.cpp.i

CMakeFiles/vuk.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vuk.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jason/Documents/GitHub/acm_practices/vuk/main.cpp -o CMakeFiles/vuk.dir/main.cpp.s

CMakeFiles/vuk.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/vuk.dir/main.cpp.o.requires

CMakeFiles/vuk.dir/main.cpp.o.provides: CMakeFiles/vuk.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/vuk.dir/build.make CMakeFiles/vuk.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/vuk.dir/main.cpp.o.provides

CMakeFiles/vuk.dir/main.cpp.o.provides.build: CMakeFiles/vuk.dir/main.cpp.o


# Object files for target vuk
vuk_OBJECTS = \
"CMakeFiles/vuk.dir/main.cpp.o"

# External object files for target vuk
vuk_EXTERNAL_OBJECTS =

vuk: CMakeFiles/vuk.dir/main.cpp.o
vuk: CMakeFiles/vuk.dir/build.make
vuk: CMakeFiles/vuk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jason/Documents/GitHub/acm_practices/vuk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vuk"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vuk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vuk.dir/build: vuk

.PHONY : CMakeFiles/vuk.dir/build

CMakeFiles/vuk.dir/requires: CMakeFiles/vuk.dir/main.cpp.o.requires

.PHONY : CMakeFiles/vuk.dir/requires

CMakeFiles/vuk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vuk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vuk.dir/clean

CMakeFiles/vuk.dir/depend:
	cd /Users/jason/Documents/GitHub/acm_practices/vuk/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jason/Documents/GitHub/acm_practices/vuk /Users/jason/Documents/GitHub/acm_practices/vuk /Users/jason/Documents/GitHub/acm_practices/vuk/cmake-build-debug /Users/jason/Documents/GitHub/acm_practices/vuk/cmake-build-debug /Users/jason/Documents/GitHub/acm_practices/vuk/cmake-build-debug/CMakeFiles/vuk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vuk.dir/depend

