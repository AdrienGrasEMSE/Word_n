# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build

# Include any dependencies generated for this target.
include external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/progress.make

# Include the compile flags for this target's objects.
include external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/flags.make

external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o: external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/flags.make
external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o: /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/external/Word_n_unitary/src/Word_n_unitary.cpp
external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o: external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o"
	cd /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/external/Word_n_unitary && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o -MF CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o.d -o CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o -c /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/external/Word_n_unitary/src/Word_n_unitary.cpp

external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.i"
	cd /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/external/Word_n_unitary && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/external/Word_n_unitary/src/Word_n_unitary.cpp > CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.i

external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.s"
	cd /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/external/Word_n_unitary && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/external/Word_n_unitary/src/Word_n_unitary.cpp -o CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.s

# Object files for target Word_n_unitary_lib
Word_n_unitary_lib_OBJECTS = \
"CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o"

# External object files for target Word_n_unitary_lib
Word_n_unitary_lib_EXTERNAL_OBJECTS =

external/Word_n_unitary/libWord_n_unitary_lib.so: external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/src/Word_n_unitary.cpp.o
external/Word_n_unitary/libWord_n_unitary_lib.so: external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/build.make
external/Word_n_unitary/libWord_n_unitary_lib.so: external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libWord_n_unitary_lib.so"
	cd /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/external/Word_n_unitary && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Word_n_unitary_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/build: external/Word_n_unitary/libWord_n_unitary_lib.so
.PHONY : external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/build

external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/clean:
	cd /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/external/Word_n_unitary && $(CMAKE_COMMAND) -P CMakeFiles/Word_n_unitary_lib.dir/cmake_clean.cmake
.PHONY : external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/clean

external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/depend:
	cd /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/external/Word_n_unitary /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/external/Word_n_unitary /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n/build/external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : external/Word_n_unitary/CMakeFiles/Word_n_unitary_lib.dir/depend

