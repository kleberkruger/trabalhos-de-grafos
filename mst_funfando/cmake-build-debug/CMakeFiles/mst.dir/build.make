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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/mst.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mst.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mst.dir/flags.make

CMakeFiles/mst.dir/sources/main.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mst.dir/sources/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/main.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/main.cpp"

CMakeFiles/mst.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/main.cpp" > CMakeFiles/mst.dir/sources/main.cpp.i

CMakeFiles/mst.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/main.cpp" -o CMakeFiles/mst.dir/sources/main.cpp.s

CMakeFiles/mst.dir/sources/disjoint_set.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/disjoint_set.cpp.o: ../sources/disjoint_set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mst.dir/sources/disjoint_set.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/disjoint_set.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/disjoint_set.cpp"

CMakeFiles/mst.dir/sources/disjoint_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/disjoint_set.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/disjoint_set.cpp" > CMakeFiles/mst.dir/sources/disjoint_set.cpp.i

CMakeFiles/mst.dir/sources/disjoint_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/disjoint_set.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/disjoint_set.cpp" -o CMakeFiles/mst.dir/sources/disjoint_set.cpp.s

CMakeFiles/mst.dir/sources/graph.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/graph.cpp.o: ../sources/graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mst.dir/sources/graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/graph.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/graph.cpp"

CMakeFiles/mst.dir/sources/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/graph.cpp" > CMakeFiles/mst.dir/sources/graph.cpp.i

CMakeFiles/mst.dir/sources/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/graph.cpp" -o CMakeFiles/mst.dir/sources/graph.cpp.s

CMakeFiles/mst.dir/sources/heap.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/heap.cpp.o: ../sources/heap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mst.dir/sources/heap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/heap.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/heap.cpp"

CMakeFiles/mst.dir/sources/heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/heap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/heap.cpp" > CMakeFiles/mst.dir/sources/heap.cpp.i

CMakeFiles/mst.dir/sources/heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/heap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/sources/heap.cpp" -o CMakeFiles/mst.dir/sources/heap.cpp.s

# Object files for target mst
mst_OBJECTS = \
"CMakeFiles/mst.dir/sources/main.cpp.o" \
"CMakeFiles/mst.dir/sources/disjoint_set.cpp.o" \
"CMakeFiles/mst.dir/sources/graph.cpp.o" \
"CMakeFiles/mst.dir/sources/heap.cpp.o"

# External object files for target mst
mst_EXTERNAL_OBJECTS =

mst: CMakeFiles/mst.dir/sources/main.cpp.o
mst: CMakeFiles/mst.dir/sources/disjoint_set.cpp.o
mst: CMakeFiles/mst.dir/sources/graph.cpp.o
mst: CMakeFiles/mst.dir/sources/heap.cpp.o
mst: CMakeFiles/mst.dir/build.make
mst: CMakeFiles/mst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable mst"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mst.dir/build: mst

.PHONY : CMakeFiles/mst.dir/build

CMakeFiles/mst.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mst.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mst.dir/clean

CMakeFiles/mst.dir/depend:
	cd "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst/cmake-build-debug/CMakeFiles/mst.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mst.dir/depend

