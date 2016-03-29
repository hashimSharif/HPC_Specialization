# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /host/Phd_Sem4/Research/GitLab/ALLVM/openmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build

# Utility rule file for libomp-test-instr.

# Include the progress variables for this target.
include runtime/src/CMakeFiles/libomp-test-instr.dir/progress.make

runtime/src/CMakeFiles/libomp-test-instr: runtime/src/test-instr/.success

runtime/src/test-instr/.success: runtime/src/libomp.so
runtime/src/test-instr/.success: ../runtime/tools/check-instruction-set.pl
	$(CMAKE_COMMAND) -E cmake_progress_report /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating test-instr/.success"
	cd /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/runtime/src && /usr/bin/cmake -E make_directory /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/runtime/src/test-instr
	cd /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/runtime/src && /usr/bin/perl /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/runtime/tools/check-instruction-set.pl --os=lin --arch=32e --show --mic-arch=knc /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/runtime/src/libomp.so
	cd /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/runtime/src && /usr/bin/cmake -E touch test-instr/.success

libomp-test-instr: runtime/src/CMakeFiles/libomp-test-instr
libomp-test-instr: runtime/src/test-instr/.success
libomp-test-instr: runtime/src/CMakeFiles/libomp-test-instr.dir/build.make
.PHONY : libomp-test-instr

# Rule to build all files generated by this target.
runtime/src/CMakeFiles/libomp-test-instr.dir/build: libomp-test-instr
.PHONY : runtime/src/CMakeFiles/libomp-test-instr.dir/build

runtime/src/CMakeFiles/libomp-test-instr.dir/clean:
	cd /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/runtime/src && $(CMAKE_COMMAND) -P CMakeFiles/libomp-test-instr.dir/cmake_clean.cmake
.PHONY : runtime/src/CMakeFiles/libomp-test-instr.dir/clean

runtime/src/CMakeFiles/libomp-test-instr.dir/depend:
	cd /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /host/Phd_Sem4/Research/GitLab/ALLVM/openmp /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/runtime/src /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/runtime/src /host/Phd_Sem4/Research/GitLab/ALLVM/openmp/build/runtime/src/CMakeFiles/libomp-test-instr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : runtime/src/CMakeFiles/libomp-test-instr.dir/depend

