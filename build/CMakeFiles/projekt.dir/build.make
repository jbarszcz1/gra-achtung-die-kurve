# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\build

# Include any dependencies generated for this target.
include CMakeFiles/projekt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/projekt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/projekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projekt.dir/flags.make

CMakeFiles/projekt.dir/main.cpp.obj: CMakeFiles/projekt.dir/flags.make
CMakeFiles/projekt.dir/main.cpp.obj: CMakeFiles/projekt.dir/includes_CXX.rsp
CMakeFiles/projekt.dir/main.cpp.obj: C:/Users/jakub/PROI/projekt/gra_achtung_die_kurve/main.cpp
CMakeFiles/projekt.dir/main.cpp.obj: CMakeFiles/projekt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projekt.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projekt.dir/main.cpp.obj -MF CMakeFiles\projekt.dir\main.cpp.obj.d -o CMakeFiles\projekt.dir\main.cpp.obj -c C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\main.cpp

CMakeFiles/projekt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projekt.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\main.cpp > CMakeFiles\projekt.dir\main.cpp.i

CMakeFiles/projekt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projekt.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\main.cpp -o CMakeFiles\projekt.dir\main.cpp.s

CMakeFiles/projekt.dir/src/board.cpp.obj: CMakeFiles/projekt.dir/flags.make
CMakeFiles/projekt.dir/src/board.cpp.obj: CMakeFiles/projekt.dir/includes_CXX.rsp
CMakeFiles/projekt.dir/src/board.cpp.obj: C:/Users/jakub/PROI/projekt/gra_achtung_die_kurve/src/board.cpp
CMakeFiles/projekt.dir/src/board.cpp.obj: CMakeFiles/projekt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/projekt.dir/src/board.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projekt.dir/src/board.cpp.obj -MF CMakeFiles\projekt.dir\src\board.cpp.obj.d -o CMakeFiles\projekt.dir\src\board.cpp.obj -c C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\src\board.cpp

CMakeFiles/projekt.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projekt.dir/src/board.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\src\board.cpp > CMakeFiles\projekt.dir\src\board.cpp.i

CMakeFiles/projekt.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projekt.dir/src/board.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\src\board.cpp -o CMakeFiles\projekt.dir\src\board.cpp.s

CMakeFiles/projekt.dir/src/snake.cpp.obj: CMakeFiles/projekt.dir/flags.make
CMakeFiles/projekt.dir/src/snake.cpp.obj: CMakeFiles/projekt.dir/includes_CXX.rsp
CMakeFiles/projekt.dir/src/snake.cpp.obj: C:/Users/jakub/PROI/projekt/gra_achtung_die_kurve/src/snake.cpp
CMakeFiles/projekt.dir/src/snake.cpp.obj: CMakeFiles/projekt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/projekt.dir/src/snake.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projekt.dir/src/snake.cpp.obj -MF CMakeFiles\projekt.dir\src\snake.cpp.obj.d -o CMakeFiles\projekt.dir\src\snake.cpp.obj -c C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\src\snake.cpp

CMakeFiles/projekt.dir/src/snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projekt.dir/src/snake.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\src\snake.cpp > CMakeFiles\projekt.dir\src\snake.cpp.i

CMakeFiles/projekt.dir/src/snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projekt.dir/src/snake.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\src\snake.cpp -o CMakeFiles\projekt.dir\src\snake.cpp.s

# Object files for target projekt
projekt_OBJECTS = \
"CMakeFiles/projekt.dir/main.cpp.obj" \
"CMakeFiles/projekt.dir/src/board.cpp.obj" \
"CMakeFiles/projekt.dir/src/snake.cpp.obj"

# External object files for target projekt
projekt_EXTERNAL_OBJECTS =

projekt.exe: CMakeFiles/projekt.dir/main.cpp.obj
projekt.exe: CMakeFiles/projekt.dir/src/board.cpp.obj
projekt.exe: CMakeFiles/projekt.dir/src/snake.cpp.obj
projekt.exe: CMakeFiles/projekt.dir/build.make
projekt.exe: _deps/raylib-build/raylib/libraylib.a
projekt.exe: _deps/raylib-build/raylib/external/glfw/src/libglfw3.a
projekt.exe: CMakeFiles/projekt.dir/linkLibs.rsp
projekt.exe: CMakeFiles/projekt.dir/objects1.rsp
projekt.exe: CMakeFiles/projekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable projekt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\projekt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projekt.dir/build: projekt.exe
.PHONY : CMakeFiles/projekt.dir/build

CMakeFiles/projekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\projekt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/projekt.dir/clean

CMakeFiles/projekt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\build C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\build C:\Users\jakub\PROI\projekt\gra_achtung_die_kurve\build\CMakeFiles\projekt.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/projekt.dir/depend

