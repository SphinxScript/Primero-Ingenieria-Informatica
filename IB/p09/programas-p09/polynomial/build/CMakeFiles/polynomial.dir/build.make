# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/build

# Include any dependencies generated for this target.
include CMakeFiles/polynomial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/polynomial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/polynomial.dir/flags.make

CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.o: CMakeFiles/polynomial.dir/flags.make
CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.o: ../src/evaluarpolinomio.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.o -c /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/src/evaluarpolinomio.cc

CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/src/evaluarpolinomio.cc > CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.i

CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/src/evaluarpolinomio.cc -o CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.s

CMakeFiles/polynomial.dir/src/main.cc.o: CMakeFiles/polynomial.dir/flags.make
CMakeFiles/polynomial.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/polynomial.dir/src/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polynomial.dir/src/main.cc.o -c /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/src/main.cc

CMakeFiles/polynomial.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polynomial.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/src/main.cc > CMakeFiles/polynomial.dir/src/main.cc.i

CMakeFiles/polynomial.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polynomial.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/src/main.cc -o CMakeFiles/polynomial.dir/src/main.cc.s

# Object files for target polynomial
polynomial_OBJECTS = \
"CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.o" \
"CMakeFiles/polynomial.dir/src/main.cc.o"

# External object files for target polynomial
polynomial_EXTERNAL_OBJECTS =

polynomial: CMakeFiles/polynomial.dir/src/evaluarpolinomio.cc.o
polynomial: CMakeFiles/polynomial.dir/src/main.cc.o
polynomial: CMakeFiles/polynomial.dir/build.make
polynomial: CMakeFiles/polynomial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable polynomial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/polynomial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/polynomial.dir/build: polynomial

.PHONY : CMakeFiles/polynomial.dir/build

CMakeFiles/polynomial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/polynomial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/polynomial.dir/clean

CMakeFiles/polynomial.dir/depend:
	cd /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/build /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/build /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/polynomial/build/CMakeFiles/polynomial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/polynomial.dir/depend

