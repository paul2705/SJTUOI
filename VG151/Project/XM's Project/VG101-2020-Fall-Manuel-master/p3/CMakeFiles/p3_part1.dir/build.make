# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3"

# Include any dependencies generated for this target.
include CMakeFiles/p3_part1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/p3_part1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/p3_part1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p3_part1.dir/flags.make

CMakeFiles/p3_part1.dir/part1.cpp.o: CMakeFiles/p3_part1.dir/flags.make
CMakeFiles/p3_part1.dir/part1.cpp.o: part1.cpp
CMakeFiles/p3_part1.dir/part1.cpp.o: CMakeFiles/p3_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p3_part1.dir/part1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/p3_part1.dir/part1.cpp.o -MF CMakeFiles/p3_part1.dir/part1.cpp.o.d -o CMakeFiles/p3_part1.dir/part1.cpp.o -c "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/part1.cpp"

CMakeFiles/p3_part1.dir/part1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p3_part1.dir/part1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/part1.cpp" > CMakeFiles/p3_part1.dir/part1.cpp.i

CMakeFiles/p3_part1.dir/part1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p3_part1.dir/part1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/part1.cpp" -o CMakeFiles/p3_part1.dir/part1.cpp.s

CMakeFiles/p3_part1.dir/basic.cpp.o: CMakeFiles/p3_part1.dir/flags.make
CMakeFiles/p3_part1.dir/basic.cpp.o: basic.cpp
CMakeFiles/p3_part1.dir/basic.cpp.o: CMakeFiles/p3_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/p3_part1.dir/basic.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/p3_part1.dir/basic.cpp.o -MF CMakeFiles/p3_part1.dir/basic.cpp.o.d -o CMakeFiles/p3_part1.dir/basic.cpp.o -c "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/basic.cpp"

CMakeFiles/p3_part1.dir/basic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p3_part1.dir/basic.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/basic.cpp" > CMakeFiles/p3_part1.dir/basic.cpp.i

CMakeFiles/p3_part1.dir/basic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p3_part1.dir/basic.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/basic.cpp" -o CMakeFiles/p3_part1.dir/basic.cpp.s

# Object files for target p3_part1
p3_part1_OBJECTS = \
"CMakeFiles/p3_part1.dir/part1.cpp.o" \
"CMakeFiles/p3_part1.dir/basic.cpp.o"

# External object files for target p3_part1
p3_part1_EXTERNAL_OBJECTS =

p3_part1: CMakeFiles/p3_part1.dir/part1.cpp.o
p3_part1: CMakeFiles/p3_part1.dir/basic.cpp.o
p3_part1: CMakeFiles/p3_part1.dir/build.make
p3_part1: CMakeFiles/p3_part1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable p3_part1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p3_part1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p3_part1.dir/build: p3_part1
.PHONY : CMakeFiles/p3_part1.dir/build

CMakeFiles/p3_part1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p3_part1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p3_part1.dir/clean

CMakeFiles/p3_part1.dir/depend:
	cd "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3" "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3" "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3" "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3" "/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/XM's Project/VG101-2020-Fall-Manuel-master/p3/CMakeFiles/p3_part1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/p3_part1.dir/depend

