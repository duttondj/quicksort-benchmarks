# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks

# Utility rule file for testquicksort_automoc.

# Include the progress variables for this target.
include CMakeFiles/testquicksort_automoc.dir/progress.make

CMakeFiles/testquicksort_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc and uic for target testquicksort"
	/usr/bin/cmake -E cmake_autogen /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks/CMakeFiles/testquicksort_automoc.dir/ Release

testquicksort_automoc: CMakeFiles/testquicksort_automoc
testquicksort_automoc: CMakeFiles/testquicksort_automoc.dir/build.make

.PHONY : testquicksort_automoc

# Rule to build all files generated by this target.
CMakeFiles/testquicksort_automoc.dir/build: testquicksort_automoc

.PHONY : CMakeFiles/testquicksort_automoc.dir/build

CMakeFiles/testquicksort_automoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testquicksort_automoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testquicksort_automoc.dir/clean

CMakeFiles/testquicksort_automoc.dir/depend:
	cd /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks /home/danny/Dropbox/Fall2015/SoftwareDesign/P3/quicksort-benchmarks/CMakeFiles/testquicksort_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testquicksort_automoc.dir/depend

