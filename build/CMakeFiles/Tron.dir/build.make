# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/workspace/Tron

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/workspace/Tron/build

# Include any dependencies generated for this target.
include CMakeFiles/Tron.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tron.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tron.dir/flags.make

CMakeFiles/Tron.dir/src/main.cpp.o: CMakeFiles/Tron.dir/flags.make
CMakeFiles/Tron.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/Tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tron.dir/src/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tron.dir/src/main.cpp.o -c /home/workspace/Tron/src/main.cpp

CMakeFiles/Tron.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tron.dir/src/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/Tron/src/main.cpp > CMakeFiles/Tron.dir/src/main.cpp.i

CMakeFiles/Tron.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tron.dir/src/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/Tron/src/main.cpp -o CMakeFiles/Tron.dir/src/main.cpp.s

CMakeFiles/Tron.dir/src/game.cpp.o: CMakeFiles/Tron.dir/flags.make
CMakeFiles/Tron.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/Tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tron.dir/src/game.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tron.dir/src/game.cpp.o -c /home/workspace/Tron/src/game.cpp

CMakeFiles/Tron.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tron.dir/src/game.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/Tron/src/game.cpp > CMakeFiles/Tron.dir/src/game.cpp.i

CMakeFiles/Tron.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tron.dir/src/game.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/Tron/src/game.cpp -o CMakeFiles/Tron.dir/src/game.cpp.s

CMakeFiles/Tron.dir/src/controller.cpp.o: CMakeFiles/Tron.dir/flags.make
CMakeFiles/Tron.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/Tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tron.dir/src/controller.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tron.dir/src/controller.cpp.o -c /home/workspace/Tron/src/controller.cpp

CMakeFiles/Tron.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tron.dir/src/controller.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/Tron/src/controller.cpp > CMakeFiles/Tron.dir/src/controller.cpp.i

CMakeFiles/Tron.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tron.dir/src/controller.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/Tron/src/controller.cpp -o CMakeFiles/Tron.dir/src/controller.cpp.s

CMakeFiles/Tron.dir/src/renderer.cpp.o: CMakeFiles/Tron.dir/flags.make
CMakeFiles/Tron.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/Tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tron.dir/src/renderer.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tron.dir/src/renderer.cpp.o -c /home/workspace/Tron/src/renderer.cpp

CMakeFiles/Tron.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tron.dir/src/renderer.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/Tron/src/renderer.cpp > CMakeFiles/Tron.dir/src/renderer.cpp.i

CMakeFiles/Tron.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tron.dir/src/renderer.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/Tron/src/renderer.cpp -o CMakeFiles/Tron.dir/src/renderer.cpp.s

CMakeFiles/Tron.dir/src/snake.cpp.o: CMakeFiles/Tron.dir/flags.make
CMakeFiles/Tron.dir/src/snake.cpp.o: ../src/snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/Tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Tron.dir/src/snake.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tron.dir/src/snake.cpp.o -c /home/workspace/Tron/src/snake.cpp

CMakeFiles/Tron.dir/src/snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tron.dir/src/snake.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/Tron/src/snake.cpp > CMakeFiles/Tron.dir/src/snake.cpp.i

CMakeFiles/Tron.dir/src/snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tron.dir/src/snake.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/Tron/src/snake.cpp -o CMakeFiles/Tron.dir/src/snake.cpp.s

# Object files for target Tron
Tron_OBJECTS = \
"CMakeFiles/Tron.dir/src/main.cpp.o" \
"CMakeFiles/Tron.dir/src/game.cpp.o" \
"CMakeFiles/Tron.dir/src/controller.cpp.o" \
"CMakeFiles/Tron.dir/src/renderer.cpp.o" \
"CMakeFiles/Tron.dir/src/snake.cpp.o"

# External object files for target Tron
Tron_EXTERNAL_OBJECTS =

Tron: CMakeFiles/Tron.dir/src/main.cpp.o
Tron: CMakeFiles/Tron.dir/src/game.cpp.o
Tron: CMakeFiles/Tron.dir/src/controller.cpp.o
Tron: CMakeFiles/Tron.dir/src/renderer.cpp.o
Tron: CMakeFiles/Tron.dir/src/snake.cpp.o
Tron: CMakeFiles/Tron.dir/build.make
Tron: CMakeFiles/Tron.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/workspace/Tron/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Tron"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tron.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tron.dir/build: Tron

.PHONY : CMakeFiles/Tron.dir/build

CMakeFiles/Tron.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tron.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tron.dir/clean

CMakeFiles/Tron.dir/depend:
	cd /home/workspace/Tron/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/workspace/Tron /home/workspace/Tron /home/workspace/Tron/build /home/workspace/Tron/build /home/workspace/Tron/build/CMakeFiles/Tron.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tron.dir/depend

