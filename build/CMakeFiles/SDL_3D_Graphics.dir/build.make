# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/build

# Include any dependencies generated for this target.
include CMakeFiles/SDL_3D_Graphics.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDL_3D_Graphics.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL_3D_Graphics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL_3D_Graphics.dir/flags.make

CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o: CMakeFiles/SDL_3D_Graphics.dir/flags.make
CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o: /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/main.cpp
CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o: CMakeFiles/SDL_3D_Graphics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o -MF CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o.d -o CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o -c /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/main.cpp

CMakeFiles/SDL_3D_Graphics.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SDL_3D_Graphics.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/main.cpp > CMakeFiles/SDL_3D_Graphics.dir/main.cpp.i

CMakeFiles/SDL_3D_Graphics.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SDL_3D_Graphics.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/main.cpp -o CMakeFiles/SDL_3D_Graphics.dir/main.cpp.s

CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o: CMakeFiles/SDL_3D_Graphics.dir/flags.make
CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o: /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/coords.cpp
CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o: CMakeFiles/SDL_3D_Graphics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o -MF CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o.d -o CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o -c /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/coords.cpp

CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/coords.cpp > CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.i

CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/coords.cpp -o CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.s

# Object files for target SDL_3D_Graphics
SDL_3D_Graphics_OBJECTS = \
"CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o" \
"CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o"

# External object files for target SDL_3D_Graphics
SDL_3D_Graphics_EXTERNAL_OBJECTS =

SDL_3D_Graphics: CMakeFiles/SDL_3D_Graphics.dir/main.cpp.o
SDL_3D_Graphics: CMakeFiles/SDL_3D_Graphics.dir/coords.cpp.o
SDL_3D_Graphics: CMakeFiles/SDL_3D_Graphics.dir/build.make
SDL_3D_Graphics: /usr/lib/libSDL2main.a
SDL_3D_Graphics: /usr/lib/libSDL2-2.0.so.0.3000.3
SDL_3D_Graphics: CMakeFiles/SDL_3D_Graphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SDL_3D_Graphics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL_3D_Graphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL_3D_Graphics.dir/build: SDL_3D_Graphics
.PHONY : CMakeFiles/SDL_3D_Graphics.dir/build

CMakeFiles/SDL_3D_Graphics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL_3D_Graphics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL_3D_Graphics.dir/clean

CMakeFiles/SDL_3D_Graphics.dir/depend:
	cd /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/build /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/build /home/dawkstorm/VSCode_Projects/SDL_3D_Graphics/build/CMakeFiles/SDL_3D_Graphics.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SDL_3D_Graphics.dir/depend

