# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Projects\Lab 6 - Binary Tree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Projects\Lab 6 - Binary Tree\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab_6___Binary_Tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_6___Binary_Tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_6___Binary_Tree.dir/flags.make

CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.obj: CMakeFiles/Lab_6___Binary_Tree.dir/flags.make
CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Projects\Lab 6 - Binary Tree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_6___Binary_Tree.dir\main.cpp.obj -c "D:\Projects\Lab 6 - Binary Tree\main.cpp"

CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Projects\Lab 6 - Binary Tree\main.cpp" > CMakeFiles\Lab_6___Binary_Tree.dir\main.cpp.i

CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Projects\Lab 6 - Binary Tree\main.cpp" -o CMakeFiles\Lab_6___Binary_Tree.dir\main.cpp.s

CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.obj: CMakeFiles/Lab_6___Binary_Tree.dir/flags.make
CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.obj: ../Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Projects\Lab 6 - Binary Tree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_6___Binary_Tree.dir\Tree.cpp.obj -c "D:\Projects\Lab 6 - Binary Tree\Tree.cpp"

CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Projects\Lab 6 - Binary Tree\Tree.cpp" > CMakeFiles\Lab_6___Binary_Tree.dir\Tree.cpp.i

CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Projects\Lab 6 - Binary Tree\Tree.cpp" -o CMakeFiles\Lab_6___Binary_Tree.dir\Tree.cpp.s

# Object files for target Lab_6___Binary_Tree
Lab_6___Binary_Tree_OBJECTS = \
"CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.obj" \
"CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.obj"

# External object files for target Lab_6___Binary_Tree
Lab_6___Binary_Tree_EXTERNAL_OBJECTS =

Lab_6___Binary_Tree.exe: CMakeFiles/Lab_6___Binary_Tree.dir/main.cpp.obj
Lab_6___Binary_Tree.exe: CMakeFiles/Lab_6___Binary_Tree.dir/Tree.cpp.obj
Lab_6___Binary_Tree.exe: CMakeFiles/Lab_6___Binary_Tree.dir/build.make
Lab_6___Binary_Tree.exe: CMakeFiles/Lab_6___Binary_Tree.dir/linklibs.rsp
Lab_6___Binary_Tree.exe: CMakeFiles/Lab_6___Binary_Tree.dir/objects1.rsp
Lab_6___Binary_Tree.exe: CMakeFiles/Lab_6___Binary_Tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Projects\Lab 6 - Binary Tree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab_6___Binary_Tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab_6___Binary_Tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_6___Binary_Tree.dir/build: Lab_6___Binary_Tree.exe

.PHONY : CMakeFiles/Lab_6___Binary_Tree.dir/build

CMakeFiles/Lab_6___Binary_Tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab_6___Binary_Tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab_6___Binary_Tree.dir/clean

CMakeFiles/Lab_6___Binary_Tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Projects\Lab 6 - Binary Tree" "D:\Projects\Lab 6 - Binary Tree" "D:\Projects\Lab 6 - Binary Tree\cmake-build-debug" "D:\Projects\Lab 6 - Binary Tree\cmake-build-debug" "D:\Projects\Lab 6 - Binary Tree\cmake-build-debug\CMakeFiles\Lab_6___Binary_Tree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab_6___Binary_Tree.dir/depend
