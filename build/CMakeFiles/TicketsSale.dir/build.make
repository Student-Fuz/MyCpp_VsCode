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
include CMakeFiles/TicketsSale.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TicketsSale.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TicketsSale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TicketsSale.dir/flags.make

CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.obj: CMakeFiles/TicketsSale.dir/flags.make
CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.obj: D:/Code_Algorithm_Net/language/Cpp_vscode/processes_threads/synchronization/Threads/TicketsSale.cpp
CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.obj: CMakeFiles/TicketsSale.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Code_Algorithm_Net\language\Cpp_vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.obj"
	D:\IDE\Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.obj -MF CMakeFiles\TicketsSale.dir\processes_threads\synchronization\Threads\TicketsSale.cpp.obj.d -o CMakeFiles\TicketsSale.dir\processes_threads\synchronization\Threads\TicketsSale.cpp.obj -c D:\Code_Algorithm_Net\language\Cpp_vscode\processes_threads\synchronization\Threads\TicketsSale.cpp

CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.i"
	D:\IDE\Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code_Algorithm_Net\language\Cpp_vscode\processes_threads\synchronization\Threads\TicketsSale.cpp > CMakeFiles\TicketsSale.dir\processes_threads\synchronization\Threads\TicketsSale.cpp.i

CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.s"
	D:\IDE\Cpp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code_Algorithm_Net\language\Cpp_vscode\processes_threads\synchronization\Threads\TicketsSale.cpp -o CMakeFiles\TicketsSale.dir\processes_threads\synchronization\Threads\TicketsSale.cpp.s

# Object files for target TicketsSale
TicketsSale_OBJECTS = \
"CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.obj"

# External object files for target TicketsSale
TicketsSale_EXTERNAL_OBJECTS =

libTicketsSale.a: CMakeFiles/TicketsSale.dir/processes_threads/synchronization/Threads/TicketsSale.cpp.obj
libTicketsSale.a: CMakeFiles/TicketsSale.dir/build.make
libTicketsSale.a: CMakeFiles/TicketsSale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Code_Algorithm_Net\language\Cpp_vscode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTicketsSale.a"
	$(CMAKE_COMMAND) -P CMakeFiles\TicketsSale.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TicketsSale.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TicketsSale.dir/build: libTicketsSale.a
.PHONY : CMakeFiles/TicketsSale.dir/build

CMakeFiles/TicketsSale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TicketsSale.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TicketsSale.dir/clean

CMakeFiles/TicketsSale.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code_Algorithm_Net\language\Cpp_vscode D:\Code_Algorithm_Net\language\Cpp_vscode D:\Code_Algorithm_Net\language\Cpp_vscode\build D:\Code_Algorithm_Net\language\Cpp_vscode\build D:\Code_Algorithm_Net\language\Cpp_vscode\build\CMakeFiles\TicketsSale.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TicketsSale.dir/depend

