# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/jewoo/CLionProjects/tinylang4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug

# Include any dependencies generated for this target.
include lib/Sema/CMakeFiles/tinylangSema.dir/depend.make

# Include the progress variables for this target.
include lib/Sema/CMakeFiles/tinylangSema.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Sema/CMakeFiles/tinylangSema.dir/flags.make

lib/Sema/CMakeFiles/tinylangSema.dir/Sema.cpp.o: lib/Sema/CMakeFiles/tinylangSema.dir/flags.make
lib/Sema/CMakeFiles/tinylangSema.dir/Sema.cpp.o: ../lib/Sema/Sema.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Sema/CMakeFiles/tinylangSema.dir/Sema.cpp.o"
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinylangSema.dir/Sema.cpp.o -c /mnt/c/Users/jewoo/CLionProjects/tinylang4/lib/Sema/Sema.cpp

lib/Sema/CMakeFiles/tinylangSema.dir/Sema.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinylangSema.dir/Sema.cpp.i"
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/jewoo/CLionProjects/tinylang4/lib/Sema/Sema.cpp > CMakeFiles/tinylangSema.dir/Sema.cpp.i

lib/Sema/CMakeFiles/tinylangSema.dir/Sema.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinylangSema.dir/Sema.cpp.s"
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/jewoo/CLionProjects/tinylang4/lib/Sema/Sema.cpp -o CMakeFiles/tinylangSema.dir/Sema.cpp.s

lib/Sema/CMakeFiles/tinylangSema.dir/Scope.cpp.o: lib/Sema/CMakeFiles/tinylangSema.dir/flags.make
lib/Sema/CMakeFiles/tinylangSema.dir/Scope.cpp.o: ../lib/Sema/Scope.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/Sema/CMakeFiles/tinylangSema.dir/Scope.cpp.o"
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinylangSema.dir/Scope.cpp.o -c /mnt/c/Users/jewoo/CLionProjects/tinylang4/lib/Sema/Scope.cpp

lib/Sema/CMakeFiles/tinylangSema.dir/Scope.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinylangSema.dir/Scope.cpp.i"
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/jewoo/CLionProjects/tinylang4/lib/Sema/Scope.cpp > CMakeFiles/tinylangSema.dir/Scope.cpp.i

lib/Sema/CMakeFiles/tinylangSema.dir/Scope.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinylangSema.dir/Scope.cpp.s"
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/jewoo/CLionProjects/tinylang4/lib/Sema/Scope.cpp -o CMakeFiles/tinylangSema.dir/Scope.cpp.s

# Object files for target tinylangSema
tinylangSema_OBJECTS = \
"CMakeFiles/tinylangSema.dir/Sema.cpp.o" \
"CMakeFiles/tinylangSema.dir/Scope.cpp.o"

# External object files for target tinylangSema
tinylangSema_EXTERNAL_OBJECTS =

lib/Sema/libtinylangSema.a: lib/Sema/CMakeFiles/tinylangSema.dir/Sema.cpp.o
lib/Sema/libtinylangSema.a: lib/Sema/CMakeFiles/tinylangSema.dir/Scope.cpp.o
lib/Sema/libtinylangSema.a: lib/Sema/CMakeFiles/tinylangSema.dir/build.make
lib/Sema/libtinylangSema.a: lib/Sema/CMakeFiles/tinylangSema.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtinylangSema.a"
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && $(CMAKE_COMMAND) -P CMakeFiles/tinylangSema.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tinylangSema.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Sema/CMakeFiles/tinylangSema.dir/build: lib/Sema/libtinylangSema.a

.PHONY : lib/Sema/CMakeFiles/tinylangSema.dir/build

lib/Sema/CMakeFiles/tinylangSema.dir/clean:
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema && $(CMAKE_COMMAND) -P CMakeFiles/tinylangSema.dir/cmake_clean.cmake
.PHONY : lib/Sema/CMakeFiles/tinylangSema.dir/clean

lib/Sema/CMakeFiles/tinylangSema.dir/depend:
	cd /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/jewoo/CLionProjects/tinylang4 /mnt/c/Users/jewoo/CLionProjects/tinylang4/lib/Sema /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema /mnt/c/Users/jewoo/CLionProjects/tinylang4/cmake-build-debug/lib/Sema/CMakeFiles/tinylangSema.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Sema/CMakeFiles/tinylangSema.dir/depend

