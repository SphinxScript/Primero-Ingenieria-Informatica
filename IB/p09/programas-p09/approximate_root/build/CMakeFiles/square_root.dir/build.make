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
CMAKE_SOURCE_DIR = /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/build

# Include any dependencies generated for this target.
include CMakeFiles/square_root.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/square_root.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/square_root.dir/flags.make

CMakeFiles/square_root.dir/src/calcular_raiz.cc.o: CMakeFiles/square_root.dir/flags.make
CMakeFiles/square_root.dir/src/calcular_raiz.cc.o: ../src/calcular_raiz.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/square_root.dir/src/calcular_raiz.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/square_root.dir/src/calcular_raiz.cc.o -c /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/src/calcular_raiz.cc

CMakeFiles/square_root.dir/src/calcular_raiz.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/square_root.dir/src/calcular_raiz.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/src/calcular_raiz.cc > CMakeFiles/square_root.dir/src/calcular_raiz.cc.i

CMakeFiles/square_root.dir/src/calcular_raiz.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/square_root.dir/src/calcular_raiz.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/src/calcular_raiz.cc -o CMakeFiles/square_root.dir/src/calcular_raiz.cc.s

CMakeFiles/square_root.dir/src/main.cc.o: CMakeFiles/square_root.dir/flags.make
CMakeFiles/square_root.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/square_root.dir/src/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/square_root.dir/src/main.cc.o -c /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/src/main.cc

CMakeFiles/square_root.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/square_root.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/src/main.cc > CMakeFiles/square_root.dir/src/main.cc.i

CMakeFiles/square_root.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/square_root.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/src/main.cc -o CMakeFiles/square_root.dir/src/main.cc.s

# Object files for target square_root
square_root_OBJECTS = \
"CMakeFiles/square_root.dir/src/calcular_raiz.cc.o" \
"CMakeFiles/square_root.dir/src/main.cc.o"

# External object files for target square_root
square_root_EXTERNAL_OBJECTS =

square_root: CMakeFiles/square_root.dir/src/calcular_raiz.cc.o
square_root: CMakeFiles/square_root.dir/src/main.cc.o
square_root: CMakeFiles/square_root.dir/build.make
square_root: CMakeFiles/square_root.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable square_root"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/square_root.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/square_root.dir/build: square_root

.PHONY : CMakeFiles/square_root.dir/build

CMakeFiles/square_root.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/square_root.dir/cmake_clean.cmake
.PHONY : CMakeFiles/square_root.dir/clean

CMakeFiles/square_root.dir/depend:
	cd /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/build /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/build /home/usuario/IB/ib-2023-2024-p09-functions2-alu0101643137/programas-p09/approximate_root/build/CMakeFiles/square_root.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/square_root.dir/depend
