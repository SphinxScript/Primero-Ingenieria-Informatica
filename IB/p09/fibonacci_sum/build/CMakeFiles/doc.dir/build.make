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
CMAKE_SOURCE_DIR = /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum/build

# Utility rule file for doc.

# Include the progress variables for this target.
include CMakeFiles/doc.dir/progress.make

CMakeFiles/doc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating API documentation with Doxygen"
	cd /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum/doc && /usr/bin/doxygen /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum/fibonacci.Doxyfile

doc: CMakeFiles/doc
doc: CMakeFiles/doc.dir/build.make

.PHONY : doc

# Rule to build all files generated by this target.
CMakeFiles/doc.dir/build: doc

.PHONY : CMakeFiles/doc.dir/build

CMakeFiles/doc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/doc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/doc.dir/clean

CMakeFiles/doc.dir/depend:
	cd /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum/build /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum/build /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/fibonacci_sum/build/CMakeFiles/doc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/doc.dir/depend

