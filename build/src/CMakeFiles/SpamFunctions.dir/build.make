# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/raptor/alpha front end/alpapap"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/raptor/alpha front end/alpapap/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/SpamFunctions.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/SpamFunctions.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/SpamFunctions.dir/flags.make

src/CMakeFiles/SpamFunctions.dir/spam.cpp.o: src/CMakeFiles/SpamFunctions.dir/flags.make
src/CMakeFiles/SpamFunctions.dir/spam.cpp.o: ../src/spam.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/raptor/alpha front end/alpapap/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/SpamFunctions.dir/spam.cpp.o"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SpamFunctions.dir/spam.cpp.o -c "/home/raptor/alpha front end/alpapap/src/spam.cpp"

src/CMakeFiles/SpamFunctions.dir/spam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpamFunctions.dir/spam.cpp.i"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/raptor/alpha front end/alpapap/src/spam.cpp" > CMakeFiles/SpamFunctions.dir/spam.cpp.i

src/CMakeFiles/SpamFunctions.dir/spam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpamFunctions.dir/spam.cpp.s"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/raptor/alpha front end/alpapap/src/spam.cpp" -o CMakeFiles/SpamFunctions.dir/spam.cpp.s

src/CMakeFiles/SpamFunctions.dir/spam.cpp.o.requires:
.PHONY : src/CMakeFiles/SpamFunctions.dir/spam.cpp.o.requires

src/CMakeFiles/SpamFunctions.dir/spam.cpp.o.provides: src/CMakeFiles/SpamFunctions.dir/spam.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/SpamFunctions.dir/build.make src/CMakeFiles/SpamFunctions.dir/spam.cpp.o.provides.build
.PHONY : src/CMakeFiles/SpamFunctions.dir/spam.cpp.o.provides

src/CMakeFiles/SpamFunctions.dir/spam.cpp.o.provides.build: src/CMakeFiles/SpamFunctions.dir/spam.cpp.o

# Object files for target SpamFunctions
SpamFunctions_OBJECTS = \
"CMakeFiles/SpamFunctions.dir/spam.cpp.o"

# External object files for target SpamFunctions
SpamFunctions_EXTERNAL_OBJECTS =

../lib/libSpamFunctions.a: src/CMakeFiles/SpamFunctions.dir/spam.cpp.o
../lib/libSpamFunctions.a: src/CMakeFiles/SpamFunctions.dir/build.make
../lib/libSpamFunctions.a: src/CMakeFiles/SpamFunctions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libSpamFunctions.a"
	cd "/home/raptor/alpha front end/alpapap/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/SpamFunctions.dir/cmake_clean_target.cmake
	cd "/home/raptor/alpha front end/alpapap/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpamFunctions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/SpamFunctions.dir/build: ../lib/libSpamFunctions.a
.PHONY : src/CMakeFiles/SpamFunctions.dir/build

src/CMakeFiles/SpamFunctions.dir/requires: src/CMakeFiles/SpamFunctions.dir/spam.cpp.o.requires
.PHONY : src/CMakeFiles/SpamFunctions.dir/requires

src/CMakeFiles/SpamFunctions.dir/clean:
	cd "/home/raptor/alpha front end/alpapap/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/SpamFunctions.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/SpamFunctions.dir/clean

src/CMakeFiles/SpamFunctions.dir/depend:
	cd "/home/raptor/alpha front end/alpapap/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/raptor/alpha front end/alpapap" "/home/raptor/alpha front end/alpapap/src" "/home/raptor/alpha front end/alpapap/build" "/home/raptor/alpha front end/alpapap/build/src" "/home/raptor/alpha front end/alpapap/build/src/CMakeFiles/SpamFunctions.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/SpamFunctions.dir/depend
