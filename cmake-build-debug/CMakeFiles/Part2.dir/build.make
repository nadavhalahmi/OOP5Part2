# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Part2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Part2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Part2.dir/flags.make

CMakeFiles/Part2.dir/Part2Examples.cpp.obj: CMakeFiles/Part2.dir/flags.make
CMakeFiles/Part2.dir/Part2Examples.cpp.obj: ../Part2Examples.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Part2.dir/Part2Examples.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Part2.dir\Part2Examples.cpp.obj -c "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\Part2Examples.cpp"

CMakeFiles/Part2.dir/Part2Examples.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part2.dir/Part2Examples.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\Part2Examples.cpp" > CMakeFiles\Part2.dir\Part2Examples.cpp.i

CMakeFiles/Part2.dir/Part2Examples.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part2.dir/Part2Examples.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\Part2Examples.cpp" -o CMakeFiles\Part2.dir\Part2Examples.cpp.s

CMakeFiles/Part2.dir/Part2Examples.cpp.obj.requires:

.PHONY : CMakeFiles/Part2.dir/Part2Examples.cpp.obj.requires

CMakeFiles/Part2.dir/Part2Examples.cpp.obj.provides: CMakeFiles/Part2.dir/Part2Examples.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Part2.dir\build.make CMakeFiles/Part2.dir/Part2Examples.cpp.obj.provides.build
.PHONY : CMakeFiles/Part2.dir/Part2Examples.cpp.obj.provides

CMakeFiles/Part2.dir/Part2Examples.cpp.obj.provides.build: CMakeFiles/Part2.dir/Part2Examples.cpp.obj


# Object files for target Part2
Part2_OBJECTS = \
"CMakeFiles/Part2.dir/Part2Examples.cpp.obj"

# External object files for target Part2
Part2_EXTERNAL_OBJECTS =

Part2.exe: CMakeFiles/Part2.dir/Part2Examples.cpp.obj
Part2.exe: CMakeFiles/Part2.dir/build.make
Part2.exe: CMakeFiles/Part2.dir/linklibs.rsp
Part2.exe: CMakeFiles/Part2.dir/objects1.rsp
Part2.exe: CMakeFiles/Part2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Part2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Part2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Part2.dir/build: Part2.exe

.PHONY : CMakeFiles/Part2.dir/build

CMakeFiles/Part2.dir/requires: CMakeFiles/Part2.dir/Part2Examples.cpp.obj.requires

.PHONY : CMakeFiles/Part2.dir/requires

CMakeFiles/Part2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Part2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Part2.dir/clean

CMakeFiles/Part2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2" "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2" "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\cmake-build-debug" "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\cmake-build-debug" "C:\Users\nadav\OneDrive - Technion\Simester D\OOP\HW5\Part2\cmake-build-debug\CMakeFiles\Part2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Part2.dir/depend

