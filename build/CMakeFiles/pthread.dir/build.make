# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = D:\IDE\pkg\QT\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = D:\IDE\pkg\QT\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code_Algorithm_Net\language\Cpp_vscode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code_Algorithm_Net\language\Cpp_vscode\build

# Include any dependencies generated for this target.
include CMakeFiles/pthread.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pthread.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pthread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pthread.dir/flags.make

CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.obj: CMakeFiles/pthread.dir/flags.make
CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.obj: D:/Code_Algorithm_Net/language/Cpp_vscode/processes_threads/threads/pthread.cpp
CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.obj: CMakeFiles/pthread.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code_Algorithm_Net\language\Cpp_vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.obj"
	D:\IDE\Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.obj -MF CMakeFiles\pthread.dir\processes_threads\threads\pthread.cpp.obj.d -o CMakeFiles\pthread.dir\processes_threads\threads\pthread.cpp.obj -c D:\Code_Algorithm_Net\language\Cpp_vscode\processes_threads\threads\pthread.cpp

CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.i"
	D:\IDE\Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code_Algorithm_Net\language\Cpp_vscode\processes_threads\threads\pthread.cpp > CMakeFiles\pthread.dir\processes_threads\threads\pthread.cpp.i

CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.s"
	D:\IDE\Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code_Algorithm_Net\language\Cpp_vscode\processes_threads\threads\pthread.cpp -o CMakeFiles\pthread.dir\processes_threads\threads\pthread.cpp.s

# Object files for target pthread
pthread_OBJECTS = \
"CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.obj"

# External object files for target pthread
pthread_EXTERNAL_OBJECTS =

pthread.exe: CMakeFiles/pthread.dir/processes_threads/threads/pthread.cpp.obj
pthread.exe: CMakeFiles/pthread.dir/build.make
pthread.exe: CMakeFiles/pthread.dir/linkLibs.rsp
pthread.exe: CMakeFiles/pthread.dir/objects1.rsp
pthread.exe: CMakeFiles/pthread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Code_Algorithm_Net\language\Cpp_vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pthread.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pthread.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pthread.dir/build: pthread.exe
.PHONY : CMakeFiles/pthread.dir/build

CMakeFiles/pthread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pthread.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pthread.dir/clean

CMakeFiles/pthread.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code_Algorithm_Net\language\Cpp_vscode D:\Code_Algorithm_Net\language\Cpp_vscode D:\Code_Algorithm_Net\language\Cpp_vscode\build D:\Code_Algorithm_Net\language\Cpp_vscode\build D:\Code_Algorithm_Net\language\Cpp_vscode\build\CMakeFiles\pthread.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pthread.dir/depend

