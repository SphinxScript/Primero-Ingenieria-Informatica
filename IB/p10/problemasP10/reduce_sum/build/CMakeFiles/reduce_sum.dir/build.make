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
CMAKE_SOURCE_DIR = /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/build

# Include any dependencies generated for this target.
include CMakeFiles/reduce_sum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reduce_sum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reduce_sum.dir/flags.make

CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.o: CMakeFiles/reduce_sum.dir/flags.make
CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.o: ../src/reduce_sum.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.o -c /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/src/reduce_sum.cc

CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/src/reduce_sum.cc > CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.i

CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/src/reduce_sum.cc -o CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.s

CMakeFiles/reduce_sum.dir/src/main.cc.o: CMakeFiles/reduce_sum.dir/flags.make
CMakeFiles/reduce_sum.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/reduce_sum.dir/src/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reduce_sum.dir/src/main.cc.o -c /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/src/main.cc

CMakeFiles/reduce_sum.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reduce_sum.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/src/main.cc > CMakeFiles/reduce_sum.dir/src/main.cc.i

CMakeFiles/reduce_sum.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reduce_sum.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/src/main.cc -o CMakeFiles/reduce_sum.dir/src/main.cc.s

# Object files for target reduce_sum
reduce_sum_OBJECTS = \
"CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.o" \
"CMakeFiles/reduce_sum.dir/src/main.cc.o"

# External object files for target reduce_sum
reduce_sum_EXTERNAL_OBJECTS =

reduce_sum: CMakeFiles/reduce_sum.dir/src/reduce_sum.cc.o
reduce_sum: CMakeFiles/reduce_sum.dir/src/main.cc.o
reduce_sum: CMakeFiles/reduce_sum.dir/build.make
reduce_sum: CMakeFiles/reduce_sum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable reduce_sum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reduce_sum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reduce_sum.dir/build: reduce_sum

.PHONY : CMakeFiles/reduce_sum.dir/build

CMakeFiles/reduce_sum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reduce_sum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reduce_sum.dir/clean

CMakeFiles/reduce_sum.dir/depend:
	cd /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/build /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/build /home/usuario/IB/ib-2023-2024-p10-string-array-vector-alu0101643137/problemasP10/reduce_sum/build/CMakeFiles/reduce_sum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reduce_sum.dir/depend

