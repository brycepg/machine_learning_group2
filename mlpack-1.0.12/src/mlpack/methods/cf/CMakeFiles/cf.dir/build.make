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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/azrathud/Downloads/mlpack-1.0.12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/azrathud/Downloads/mlpack-1.0.12

# Include any dependencies generated for this target.
include src/mlpack/methods/cf/CMakeFiles/cf.dir/depend.make

# Include the progress variables for this target.
include src/mlpack/methods/cf/CMakeFiles/cf.dir/progress.make

# Include the compile flags for this target's objects.
include src/mlpack/methods/cf/CMakeFiles/cf.dir/flags.make

src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o: src/mlpack/methods/cf/CMakeFiles/cf.dir/flags.make
src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o: src/mlpack/methods/cf/cf_main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/azrathud/Downloads/mlpack-1.0.12/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o"
	cd /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cf.dir/cf_main.cpp.o -c /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf/cf_main.cpp

src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cf.dir/cf_main.cpp.i"
	cd /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf/cf_main.cpp > CMakeFiles/cf.dir/cf_main.cpp.i

src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cf.dir/cf_main.cpp.s"
	cd /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf/cf_main.cpp -o CMakeFiles/cf.dir/cf_main.cpp.s

src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o.requires:
.PHONY : src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o.requires

src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o.provides: src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o.requires
	$(MAKE) -f src/mlpack/methods/cf/CMakeFiles/cf.dir/build.make src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o.provides.build
.PHONY : src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o.provides

src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o.provides.build: src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o

# Object files for target cf
cf_OBJECTS = \
"CMakeFiles/cf.dir/cf_main.cpp.o"

# External object files for target cf
cf_EXTERNAL_OBJECTS =

bin/cf: src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o
bin/cf: src/mlpack/methods/cf/CMakeFiles/cf.dir/build.make
bin/cf: lib/libmlpack.so.1.0
bin/cf: /usr/lib/libarmadillo.so
bin/cf: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
bin/cf: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
bin/cf: /usr/lib/x86_64-linux-gnu/libboost_random.so
bin/cf: /usr/lib/x86_64-linux-gnu/libxml2.so
bin/cf: src/mlpack/methods/cf/CMakeFiles/cf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../../bin/cf"
	cd /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/mlpack/methods/cf/CMakeFiles/cf.dir/build: bin/cf
.PHONY : src/mlpack/methods/cf/CMakeFiles/cf.dir/build

src/mlpack/methods/cf/CMakeFiles/cf.dir/requires: src/mlpack/methods/cf/CMakeFiles/cf.dir/cf_main.cpp.o.requires
.PHONY : src/mlpack/methods/cf/CMakeFiles/cf.dir/requires

src/mlpack/methods/cf/CMakeFiles/cf.dir/clean:
	cd /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf && $(CMAKE_COMMAND) -P CMakeFiles/cf.dir/cmake_clean.cmake
.PHONY : src/mlpack/methods/cf/CMakeFiles/cf.dir/clean

src/mlpack/methods/cf/CMakeFiles/cf.dir/depend:
	cd /home/azrathud/Downloads/mlpack-1.0.12 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/azrathud/Downloads/mlpack-1.0.12 /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf /home/azrathud/Downloads/mlpack-1.0.12 /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf /home/azrathud/Downloads/mlpack-1.0.12/src/mlpack/methods/cf/CMakeFiles/cf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/mlpack/methods/cf/CMakeFiles/cf.dir/depend

