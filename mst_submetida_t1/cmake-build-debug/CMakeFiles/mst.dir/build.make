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
CMAKE_SOURCE_DIR = "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/mst.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mst.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mst.dir/flags.make

CMakeFiles/mst.dir/sources/main.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mst.dir/sources/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/main.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/main.cpp"

CMakeFiles/mst.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/main.cpp" > CMakeFiles/mst.dir/sources/main.cpp.i

CMakeFiles/mst.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/main.cpp" -o CMakeFiles/mst.dir/sources/main.cpp.s

CMakeFiles/mst.dir/sources/graph.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/graph.cpp.o: ../sources/graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mst.dir/sources/graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/graph.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/graph.cpp"

CMakeFiles/mst.dir/sources/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/graph.cpp" > CMakeFiles/mst.dir/sources/graph.cpp.i

CMakeFiles/mst.dir/sources/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/graph.cpp" -o CMakeFiles/mst.dir/sources/graph.cpp.s

CMakeFiles/mst.dir/sources/disjointset.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/disjointset.cpp.o: ../sources/disjointset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mst.dir/sources/disjointset.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/disjointset.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/disjointset.cpp"

CMakeFiles/mst.dir/sources/disjointset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/disjointset.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/disjointset.cpp" > CMakeFiles/mst.dir/sources/disjointset.cpp.i

CMakeFiles/mst.dir/sources/disjointset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/disjointset.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/disjointset.cpp" -o CMakeFiles/mst.dir/sources/disjointset.cpp.s

CMakeFiles/mst.dir/sources/arrayset.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/arrayset.cpp.o: ../sources/arrayset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mst.dir/sources/arrayset.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/arrayset.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/arrayset.cpp"

CMakeFiles/mst.dir/sources/arrayset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/arrayset.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/arrayset.cpp" > CMakeFiles/mst.dir/sources/arrayset.cpp.i

CMakeFiles/mst.dir/sources/arrayset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/arrayset.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/arrayset.cpp" -o CMakeFiles/mst.dir/sources/arrayset.cpp.s

CMakeFiles/mst.dir/sources/listset.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/listset.cpp.o: ../sources/listset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mst.dir/sources/listset.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/listset.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/listset.cpp"

CMakeFiles/mst.dir/sources/listset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/listset.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/listset.cpp" > CMakeFiles/mst.dir/sources/listset.cpp.i

CMakeFiles/mst.dir/sources/listset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/listset.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/listset.cpp" -o CMakeFiles/mst.dir/sources/listset.cpp.s

CMakeFiles/mst.dir/sources/unionfind.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/unionfind.cpp.o: ../sources/unionfind.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mst.dir/sources/unionfind.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/unionfind.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/unionfind.cpp"

CMakeFiles/mst.dir/sources/unionfind.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/unionfind.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/unionfind.cpp" > CMakeFiles/mst.dir/sources/unionfind.cpp.i

CMakeFiles/mst.dir/sources/unionfind.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/unionfind.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/unionfind.cpp" -o CMakeFiles/mst.dir/sources/unionfind.cpp.s

CMakeFiles/mst.dir/sources/fastunionfind.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/fastunionfind.cpp.o: ../sources/fastunionfind.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mst.dir/sources/fastunionfind.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/fastunionfind.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/fastunionfind.cpp"

CMakeFiles/mst.dir/sources/fastunionfind.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/fastunionfind.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/fastunionfind.cpp" > CMakeFiles/mst.dir/sources/fastunionfind.cpp.i

CMakeFiles/mst.dir/sources/fastunionfind.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/fastunionfind.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/fastunionfind.cpp" -o CMakeFiles/mst.dir/sources/fastunionfind.cpp.s

CMakeFiles/mst.dir/sources/heap.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/heap.cpp.o: ../sources/heap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/mst.dir/sources/heap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/heap.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/heap.cpp"

CMakeFiles/mst.dir/sources/heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/heap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/heap.cpp" > CMakeFiles/mst.dir/sources/heap.cpp.i

CMakeFiles/mst.dir/sources/heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/heap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/heap.cpp" -o CMakeFiles/mst.dir/sources/heap.cpp.s

CMakeFiles/mst.dir/sources/arrayheap.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/arrayheap.cpp.o: ../sources/arrayheap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/mst.dir/sources/arrayheap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/arrayheap.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/arrayheap.cpp"

CMakeFiles/mst.dir/sources/arrayheap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/arrayheap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/arrayheap.cpp" > CMakeFiles/mst.dir/sources/arrayheap.cpp.i

CMakeFiles/mst.dir/sources/arrayheap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/arrayheap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/arrayheap.cpp" -o CMakeFiles/mst.dir/sources/arrayheap.cpp.s

CMakeFiles/mst.dir/sources/binaryheap.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/binaryheap.cpp.o: ../sources/binaryheap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/mst.dir/sources/binaryheap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/binaryheap.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/binaryheap.cpp"

CMakeFiles/mst.dir/sources/binaryheap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/binaryheap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/binaryheap.cpp" > CMakeFiles/mst.dir/sources/binaryheap.cpp.i

CMakeFiles/mst.dir/sources/binaryheap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/binaryheap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/binaryheap.cpp" -o CMakeFiles/mst.dir/sources/binaryheap.cpp.s

CMakeFiles/mst.dir/sources/fibonacciheap.cpp.o: CMakeFiles/mst.dir/flags.make
CMakeFiles/mst.dir/sources/fibonacciheap.cpp.o: ../sources/fibonacciheap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/mst.dir/sources/fibonacciheap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mst.dir/sources/fibonacciheap.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/fibonacciheap.cpp"

CMakeFiles/mst.dir/sources/fibonacciheap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mst.dir/sources/fibonacciheap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/fibonacciheap.cpp" > CMakeFiles/mst.dir/sources/fibonacciheap.cpp.i

CMakeFiles/mst.dir/sources/fibonacciheap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mst.dir/sources/fibonacciheap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/sources/fibonacciheap.cpp" -o CMakeFiles/mst.dir/sources/fibonacciheap.cpp.s

# Object files for target mst
mst_OBJECTS = \
"CMakeFiles/mst.dir/sources/main.cpp.o" \
"CMakeFiles/mst.dir/sources/graph.cpp.o" \
"CMakeFiles/mst.dir/sources/disjointset.cpp.o" \
"CMakeFiles/mst.dir/sources/arrayset.cpp.o" \
"CMakeFiles/mst.dir/sources/listset.cpp.o" \
"CMakeFiles/mst.dir/sources/unionfind.cpp.o" \
"CMakeFiles/mst.dir/sources/fastunionfind.cpp.o" \
"CMakeFiles/mst.dir/sources/heap.cpp.o" \
"CMakeFiles/mst.dir/sources/arrayheap.cpp.o" \
"CMakeFiles/mst.dir/sources/binaryheap.cpp.o" \
"CMakeFiles/mst.dir/sources/fibonacciheap.cpp.o"

# External object files for target mst
mst_EXTERNAL_OBJECTS =

mst: CMakeFiles/mst.dir/sources/main.cpp.o
mst: CMakeFiles/mst.dir/sources/graph.cpp.o
mst: CMakeFiles/mst.dir/sources/disjointset.cpp.o
mst: CMakeFiles/mst.dir/sources/arrayset.cpp.o
mst: CMakeFiles/mst.dir/sources/listset.cpp.o
mst: CMakeFiles/mst.dir/sources/unionfind.cpp.o
mst: CMakeFiles/mst.dir/sources/fastunionfind.cpp.o
mst: CMakeFiles/mst.dir/sources/heap.cpp.o
mst: CMakeFiles/mst.dir/sources/arrayheap.cpp.o
mst: CMakeFiles/mst.dir/sources/binaryheap.cpp.o
mst: CMakeFiles/mst.dir/sources/fibonacciheap.cpp.o
mst: CMakeFiles/mst.dir/build.make
mst: CMakeFiles/mst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable mst"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mst.dir/build: mst

.PHONY : CMakeFiles/mst.dir/build

CMakeFiles/mst.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mst.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mst.dir/clean

CMakeFiles/mst.dir/depend:
	cd "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst_submetida_t1/cmake-build-debug/CMakeFiles/mst.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mst.dir/depend
