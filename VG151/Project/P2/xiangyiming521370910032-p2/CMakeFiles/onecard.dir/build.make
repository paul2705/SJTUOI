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
CMAKE_SOURCE_DIR = /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2

# Include any dependencies generated for this target.
include CMakeFiles/onecard.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/onecard.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/onecard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/onecard.dir/flags.make

CMakeFiles/onecard.dir/main.c.o: CMakeFiles/onecard.dir/flags.make
CMakeFiles/onecard.dir/main.c.o: main.c
CMakeFiles/onecard.dir/main.c.o: CMakeFiles/onecard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/onecard.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/onecard.dir/main.c.o -MF CMakeFiles/onecard.dir/main.c.o.d -o CMakeFiles/onecard.dir/main.c.o -c /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/main.c

CMakeFiles/onecard.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onecard.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/main.c > CMakeFiles/onecard.dir/main.c.i

CMakeFiles/onecard.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onecard.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/main.c -o CMakeFiles/onecard.dir/main.c.s

CMakeFiles/onecard.dir/cards.c.o: CMakeFiles/onecard.dir/flags.make
CMakeFiles/onecard.dir/cards.c.o: cards.c
CMakeFiles/onecard.dir/cards.c.o: CMakeFiles/onecard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/onecard.dir/cards.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/onecard.dir/cards.c.o -MF CMakeFiles/onecard.dir/cards.c.o.d -o CMakeFiles/onecard.dir/cards.c.o -c /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/cards.c

CMakeFiles/onecard.dir/cards.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onecard.dir/cards.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/cards.c > CMakeFiles/onecard.dir/cards.c.i

CMakeFiles/onecard.dir/cards.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onecard.dir/cards.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/cards.c -o CMakeFiles/onecard.dir/cards.c.s

CMakeFiles/onecard.dir/game.c.o: CMakeFiles/onecard.dir/flags.make
CMakeFiles/onecard.dir/game.c.o: game.c
CMakeFiles/onecard.dir/game.c.o: CMakeFiles/onecard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/onecard.dir/game.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/onecard.dir/game.c.o -MF CMakeFiles/onecard.dir/game.c.o.d -o CMakeFiles/onecard.dir/game.c.o -c /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/game.c

CMakeFiles/onecard.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onecard.dir/game.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/game.c > CMakeFiles/onecard.dir/game.c.i

CMakeFiles/onecard.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onecard.dir/game.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/game.c -o CMakeFiles/onecard.dir/game.c.s

CMakeFiles/onecard.dir/player.c.o: CMakeFiles/onecard.dir/flags.make
CMakeFiles/onecard.dir/player.c.o: player.c
CMakeFiles/onecard.dir/player.c.o: CMakeFiles/onecard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/onecard.dir/player.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/onecard.dir/player.c.o -MF CMakeFiles/onecard.dir/player.c.o.d -o CMakeFiles/onecard.dir/player.c.o -c /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/player.c

CMakeFiles/onecard.dir/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onecard.dir/player.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/player.c > CMakeFiles/onecard.dir/player.c.i

CMakeFiles/onecard.dir/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onecard.dir/player.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/player.c -o CMakeFiles/onecard.dir/player.c.s

CMakeFiles/onecard.dir/round.c.o: CMakeFiles/onecard.dir/flags.make
CMakeFiles/onecard.dir/round.c.o: round.c
CMakeFiles/onecard.dir/round.c.o: CMakeFiles/onecard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/onecard.dir/round.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/onecard.dir/round.c.o -MF CMakeFiles/onecard.dir/round.c.o.d -o CMakeFiles/onecard.dir/round.c.o -c /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/round.c

CMakeFiles/onecard.dir/round.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onecard.dir/round.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/round.c > CMakeFiles/onecard.dir/round.c.i

CMakeFiles/onecard.dir/round.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onecard.dir/round.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/round.c -o CMakeFiles/onecard.dir/round.c.s

# Object files for target onecard
onecard_OBJECTS = \
"CMakeFiles/onecard.dir/main.c.o" \
"CMakeFiles/onecard.dir/cards.c.o" \
"CMakeFiles/onecard.dir/game.c.o" \
"CMakeFiles/onecard.dir/player.c.o" \
"CMakeFiles/onecard.dir/round.c.o"

# External object files for target onecard
onecard_EXTERNAL_OBJECTS =

onecard: CMakeFiles/onecard.dir/main.c.o
onecard: CMakeFiles/onecard.dir/cards.c.o
onecard: CMakeFiles/onecard.dir/game.c.o
onecard: CMakeFiles/onecard.dir/player.c.o
onecard: CMakeFiles/onecard.dir/round.c.o
onecard: CMakeFiles/onecard.dir/build.make
onecard: CMakeFiles/onecard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable onecard"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/onecard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/onecard.dir/build: onecard
.PHONY : CMakeFiles/onecard.dir/build

CMakeFiles/onecard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/onecard.dir/cmake_clean.cmake
.PHONY : CMakeFiles/onecard.dir/clean

CMakeFiles/onecard.dir/depend:
	cd /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2 /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2 /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2 /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2 /Users/duanlingbo/Desktop/SJTUOI/github/SJTUOI/VG151/Project/P2/xiangyiming521370910032-p2/CMakeFiles/onecard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/onecard.dir/depend

