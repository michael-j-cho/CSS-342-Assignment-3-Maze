# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/NETID/mikec87/C++/CSS342/ass3-maze

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/NETID/mikec87/C++/CSS342/ass3-maze

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/NETID/mikec87/C++/CSS342/ass3-maze/CMakeFiles /home/NETID/mikec87/C++/CSS342/ass3-maze//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/NETID/mikec87/C++/CSS342/ass3-maze/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ass3

# Build rule for target.
ass3: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ass3
.PHONY : ass3

# fast build rule for target.
ass3/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/build
.PHONY : ass3/fast

creature.o: creature.cpp.o

.PHONY : creature.o

# target to build an object file
creature.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/creature.cpp.o
.PHONY : creature.cpp.o

creature.i: creature.cpp.i

.PHONY : creature.i

# target to preprocess a source file
creature.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/creature.cpp.i
.PHONY : creature.cpp.i

creature.s: creature.cpp.s

.PHONY : creature.s

# target to generate assembly for a file
creature.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/creature.cpp.s
.PHONY : creature.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/main.cpp.s
.PHONY : main.cpp.s

maze.o: maze.cpp.o

.PHONY : maze.o

# target to build an object file
maze.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/maze.cpp.o
.PHONY : maze.cpp.o

maze.i: maze.cpp.i

.PHONY : maze.i

# target to preprocess a source file
maze.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/maze.cpp.i
.PHONY : maze.cpp.i

maze.s: maze.cpp.s

.PHONY : maze.s

# target to generate assembly for a file
maze.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ass3.dir/build.make CMakeFiles/ass3.dir/maze.cpp.s
.PHONY : maze.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... ass3"
	@echo "... creature.o"
	@echo "... creature.i"
	@echo "... creature.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... maze.o"
	@echo "... maze.i"
	@echo "... maze.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

