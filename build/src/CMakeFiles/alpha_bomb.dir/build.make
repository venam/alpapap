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
include src/CMakeFiles/alpha_bomb.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/alpha_bomb.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/alpha_bomb.dir/flags.make

src/CMakeFiles/alpha_bomb.dir/spam.cpp.o: src/CMakeFiles/alpha_bomb.dir/flags.make
src/CMakeFiles/alpha_bomb.dir/spam.cpp.o: ../src/spam.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/raptor/alpha front end/alpapap/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/alpha_bomb.dir/spam.cpp.o"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/alpha_bomb.dir/spam.cpp.o -c "/home/raptor/alpha front end/alpapap/src/spam.cpp"

src/CMakeFiles/alpha_bomb.dir/spam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alpha_bomb.dir/spam.cpp.i"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/raptor/alpha front end/alpapap/src/spam.cpp" > CMakeFiles/alpha_bomb.dir/spam.cpp.i

src/CMakeFiles/alpha_bomb.dir/spam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alpha_bomb.dir/spam.cpp.s"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/raptor/alpha front end/alpapap/src/spam.cpp" -o CMakeFiles/alpha_bomb.dir/spam.cpp.s

src/CMakeFiles/alpha_bomb.dir/spam.cpp.o.requires:
.PHONY : src/CMakeFiles/alpha_bomb.dir/spam.cpp.o.requires

src/CMakeFiles/alpha_bomb.dir/spam.cpp.o.provides: src/CMakeFiles/alpha_bomb.dir/spam.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/alpha_bomb.dir/build.make src/CMakeFiles/alpha_bomb.dir/spam.cpp.o.provides.build
.PHONY : src/CMakeFiles/alpha_bomb.dir/spam.cpp.o.provides

src/CMakeFiles/alpha_bomb.dir/spam.cpp.o.provides.build: src/CMakeFiles/alpha_bomb.dir/spam.cpp.o

src/CMakeFiles/alpha_bomb.dir/gui.cpp.o: src/CMakeFiles/alpha_bomb.dir/flags.make
src/CMakeFiles/alpha_bomb.dir/gui.cpp.o: ../src/gui.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/raptor/alpha front end/alpapap/build/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/alpha_bomb.dir/gui.cpp.o"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/alpha_bomb.dir/gui.cpp.o -c "/home/raptor/alpha front end/alpapap/src/gui.cpp"

src/CMakeFiles/alpha_bomb.dir/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alpha_bomb.dir/gui.cpp.i"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/raptor/alpha front end/alpapap/src/gui.cpp" > CMakeFiles/alpha_bomb.dir/gui.cpp.i

src/CMakeFiles/alpha_bomb.dir/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alpha_bomb.dir/gui.cpp.s"
	cd "/home/raptor/alpha front end/alpapap/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/raptor/alpha front end/alpapap/src/gui.cpp" -o CMakeFiles/alpha_bomb.dir/gui.cpp.s

src/CMakeFiles/alpha_bomb.dir/gui.cpp.o.requires:
.PHONY : src/CMakeFiles/alpha_bomb.dir/gui.cpp.o.requires

src/CMakeFiles/alpha_bomb.dir/gui.cpp.o.provides: src/CMakeFiles/alpha_bomb.dir/gui.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/alpha_bomb.dir/build.make src/CMakeFiles/alpha_bomb.dir/gui.cpp.o.provides.build
.PHONY : src/CMakeFiles/alpha_bomb.dir/gui.cpp.o.provides

src/CMakeFiles/alpha_bomb.dir/gui.cpp.o.provides.build: src/CMakeFiles/alpha_bomb.dir/gui.cpp.o

# Object files for target alpha_bomb
alpha_bomb_OBJECTS = \
"CMakeFiles/alpha_bomb.dir/spam.cpp.o" \
"CMakeFiles/alpha_bomb.dir/gui.cpp.o"

# External object files for target alpha_bomb
alpha_bomb_EXTERNAL_OBJECTS =

../bin/alpha_bomb-1.0: src/CMakeFiles/alpha_bomb.dir/spam.cpp.o
../bin/alpha_bomb-1.0: src/CMakeFiles/alpha_bomb.dir/gui.cpp.o
../bin/alpha_bomb-1.0: src/CMakeFiles/alpha_bomb.dir/build.make
../bin/alpha_bomb-1.0: /usr/lib/libboost_system.so
../bin/alpha_bomb-1.0: /usr/lib/libboost_thread.so
../bin/alpha_bomb-1.0: /usr/lib/libcurl.so
../bin/alpha_bomb-1.0: ../lib/libSpamFunctions.a
../bin/alpha_bomb-1.0: src/CMakeFiles/alpha_bomb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/alpha_bomb"
	cd "/home/raptor/alpha front end/alpapap/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alpha_bomb.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/raptor/alpha front end/alpapap/build/src" && $(CMAKE_COMMAND) -E cmake_symlink_executable ../../bin/alpha_bomb-1.0 ../../bin/alpha_bomb

../bin/alpha_bomb: ../bin/alpha_bomb-1.0

# Rule to build all files generated by this target.
src/CMakeFiles/alpha_bomb.dir/build: ../bin/alpha_bomb
.PHONY : src/CMakeFiles/alpha_bomb.dir/build

src/CMakeFiles/alpha_bomb.dir/requires: src/CMakeFiles/alpha_bomb.dir/spam.cpp.o.requires
src/CMakeFiles/alpha_bomb.dir/requires: src/CMakeFiles/alpha_bomb.dir/gui.cpp.o.requires
.PHONY : src/CMakeFiles/alpha_bomb.dir/requires

src/CMakeFiles/alpha_bomb.dir/clean:
	cd "/home/raptor/alpha front end/alpapap/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/alpha_bomb.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/alpha_bomb.dir/clean

src/CMakeFiles/alpha_bomb.dir/depend:
	cd "/home/raptor/alpha front end/alpapap/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/raptor/alpha front end/alpapap" "/home/raptor/alpha front end/alpapap/src" "/home/raptor/alpha front end/alpapap/build" "/home/raptor/alpha front end/alpapap/build/src" "/home/raptor/alpha front end/alpapap/build/src/CMakeFiles/alpha_bomb.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/alpha_bomb.dir/depend

