# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /private/var/folders/zz/zyxvpxvq6csfxvn_n0000pt80005pk/T/AppTranslocation/26A1C8C1-97B2-4714-AA83-C9D427869A9B/d/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /private/var/folders/zz/zyxvpxvq6csfxvn_n0000pt80005pk/T/AppTranslocation/26A1C8C1-97B2-4714-AA83-C9D427869A9B/d/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/omykolai/NPuzzle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/omykolai/NPuzzle/Build

# Include any dependencies generated for this target.
include CMakeFiles/Tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tests.dir/flags.make

CMakeFiles/Tests.dir/Tests/Parser.cpp.o: CMakeFiles/Tests.dir/flags.make
CMakeFiles/Tests.dir/Tests/Parser.cpp.o: ../Tests/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omykolai/NPuzzle/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tests.dir/Tests/Parser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tests.dir/Tests/Parser.cpp.o -c /Users/omykolai/NPuzzle/Tests/Parser.cpp

CMakeFiles/Tests.dir/Tests/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/Tests/Parser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omykolai/NPuzzle/Tests/Parser.cpp > CMakeFiles/Tests.dir/Tests/Parser.cpp.i

CMakeFiles/Tests.dir/Tests/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/Tests/Parser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omykolai/NPuzzle/Tests/Parser.cpp -o CMakeFiles/Tests.dir/Tests/Parser.cpp.s

CMakeFiles/Tests.dir/Tests/main.cpp.o: CMakeFiles/Tests.dir/flags.make
CMakeFiles/Tests.dir/Tests/main.cpp.o: ../Tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omykolai/NPuzzle/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tests.dir/Tests/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tests.dir/Tests/main.cpp.o -c /Users/omykolai/NPuzzle/Tests/main.cpp

CMakeFiles/Tests.dir/Tests/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/Tests/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omykolai/NPuzzle/Tests/main.cpp > CMakeFiles/Tests.dir/Tests/main.cpp.i

CMakeFiles/Tests.dir/Tests/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/Tests/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omykolai/NPuzzle/Tests/main.cpp -o CMakeFiles/Tests.dir/Tests/main.cpp.s

# Object files for target Tests
Tests_OBJECTS = \
"CMakeFiles/Tests.dir/Tests/Parser.cpp.o" \
"CMakeFiles/Tests.dir/Tests/main.cpp.o"

# External object files for target Tests
Tests_EXTERNAL_OBJECTS =

Tests: CMakeFiles/Tests.dir/Tests/Parser.cpp.o
Tests: CMakeFiles/Tests.dir/Tests/main.cpp.o
Tests: CMakeFiles/Tests.dir/build.make
Tests: libNPuzzle.a
Tests: CMakeFiles/Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/omykolai/NPuzzle/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tests.dir/build: Tests

.PHONY : CMakeFiles/Tests.dir/build

CMakeFiles/Tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tests.dir/clean

CMakeFiles/Tests.dir/depend:
	cd /Users/omykolai/NPuzzle/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/omykolai/NPuzzle /Users/omykolai/NPuzzle /Users/omykolai/NPuzzle/Build /Users/omykolai/NPuzzle/Build /Users/omykolai/NPuzzle/Build/CMakeFiles/Tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tests.dir/depend
