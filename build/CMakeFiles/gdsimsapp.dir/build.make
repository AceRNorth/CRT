# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/build

# Include any dependencies generated for this target.
include CMakeFiles/gdsimsapp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gdsimsapp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gdsimsapp.dir/flags.make

CMakeFiles/gdsimsapp.dir/src/main2.cpp.o: CMakeFiles/gdsimsapp.dir/flags.make
CMakeFiles/gdsimsapp.dir/src/main2.cpp.o: ../src/main2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gdsimsapp.dir/src/main2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gdsimsapp.dir/src/main2.cpp.o -c /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/src/main2.cpp

CMakeFiles/gdsimsapp.dir/src/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gdsimsapp.dir/src/main2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/src/main2.cpp > CMakeFiles/gdsimsapp.dir/src/main2.cpp.i

CMakeFiles/gdsimsapp.dir/src/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gdsimsapp.dir/src/main2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/src/main2.cpp -o CMakeFiles/gdsimsapp.dir/src/main2.cpp.s

# Object files for target gdsimsapp
gdsimsapp_OBJECTS = \
"CMakeFiles/gdsimsapp.dir/src/main2.cpp.o"

# External object files for target gdsimsapp
gdsimsapp_EXTERNAL_OBJECTS =

gdsimsapp: CMakeFiles/gdsimsapp.dir/src/main2.cpp.o
gdsimsapp: CMakeFiles/gdsimsapp.dir/build.make
gdsimsapp: libgdsimslib.a
gdsimsapp: CMakeFiles/gdsimsapp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gdsimsapp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gdsimsapp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gdsimsapp.dir/build: gdsimsapp

.PHONY : CMakeFiles/gdsimsapp.dir/build

CMakeFiles/gdsimsapp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gdsimsapp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gdsimsapp.dir/clean

CMakeFiles/gdsimsapp.dir/depend:
	cd /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/build /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/build /home/biology/zool0973/Dropbox/FieldTrials/CRT/CRTModel/build/CMakeFiles/gdsimsapp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gdsimsapp.dir/depend

