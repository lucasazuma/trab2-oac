# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/162/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/162/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lucas/unb/2020-02/oac/trab2-oac

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OAC.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/OAC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OAC.dir/flags.make

CMakeFiles/OAC.dir/main.c.o: CMakeFiles/OAC.dir/flags.make
CMakeFiles/OAC.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/OAC.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OAC.dir/main.c.o -c /home/lucas/unb/2020-02/oac/trab2-oac/main.c

CMakeFiles/OAC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OAC.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucas/unb/2020-02/oac/trab2-oac/main.c > CMakeFiles/OAC.dir/main.c.i

CMakeFiles/OAC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OAC.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucas/unb/2020-02/oac/trab2-oac/main.c -o CMakeFiles/OAC.dir/main.c.s

CMakeFiles/OAC.dir/memory.c.o: CMakeFiles/OAC.dir/flags.make
CMakeFiles/OAC.dir/memory.c.o: ../memory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OAC.dir/memory.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OAC.dir/memory.c.o -c /home/lucas/unb/2020-02/oac/trab2-oac/memory.c

CMakeFiles/OAC.dir/memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OAC.dir/memory.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucas/unb/2020-02/oac/trab2-oac/memory.c > CMakeFiles/OAC.dir/memory.c.i

CMakeFiles/OAC.dir/memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OAC.dir/memory.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucas/unb/2020-02/oac/trab2-oac/memory.c -o CMakeFiles/OAC.dir/memory.c.s

CMakeFiles/OAC.dir/validations.c.o: CMakeFiles/OAC.dir/flags.make
CMakeFiles/OAC.dir/validations.c.o: ../validations.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/OAC.dir/validations.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OAC.dir/validations.c.o -c /home/lucas/unb/2020-02/oac/trab2-oac/validations.c

CMakeFiles/OAC.dir/validations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OAC.dir/validations.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucas/unb/2020-02/oac/trab2-oac/validations.c > CMakeFiles/OAC.dir/validations.c.i

CMakeFiles/OAC.dir/validations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OAC.dir/validations.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucas/unb/2020-02/oac/trab2-oac/validations.c -o CMakeFiles/OAC.dir/validations.c.s

CMakeFiles/OAC.dir/binary.c.o: CMakeFiles/OAC.dir/flags.make
CMakeFiles/OAC.dir/binary.c.o: ../binary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/OAC.dir/binary.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OAC.dir/binary.c.o -c /home/lucas/unb/2020-02/oac/trab2-oac/binary.c

CMakeFiles/OAC.dir/binary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OAC.dir/binary.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucas/unb/2020-02/oac/trab2-oac/binary.c > CMakeFiles/OAC.dir/binary.c.i

CMakeFiles/OAC.dir/binary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OAC.dir/binary.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucas/unb/2020-02/oac/trab2-oac/binary.c -o CMakeFiles/OAC.dir/binary.c.s

CMakeFiles/OAC.dir/test.c.o: CMakeFiles/OAC.dir/flags.make
CMakeFiles/OAC.dir/test.c.o: ../test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/OAC.dir/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OAC.dir/test.c.o -c /home/lucas/unb/2020-02/oac/trab2-oac/test.c

CMakeFiles/OAC.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OAC.dir/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucas/unb/2020-02/oac/trab2-oac/test.c > CMakeFiles/OAC.dir/test.c.i

CMakeFiles/OAC.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OAC.dir/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucas/unb/2020-02/oac/trab2-oac/test.c -o CMakeFiles/OAC.dir/test.c.s

# Object files for target OAC
OAC_OBJECTS = \
"CMakeFiles/OAC.dir/main.c.o" \
"CMakeFiles/OAC.dir/memory.c.o" \
"CMakeFiles/OAC.dir/validations.c.o" \
"CMakeFiles/OAC.dir/binary.c.o" \
"CMakeFiles/OAC.dir/test.c.o"

# External object files for target OAC
OAC_EXTERNAL_OBJECTS =

OAC: CMakeFiles/OAC.dir/main.c.o
OAC: CMakeFiles/OAC.dir/memory.c.o
OAC: CMakeFiles/OAC.dir/validations.c.o
OAC: CMakeFiles/OAC.dir/binary.c.o
OAC: CMakeFiles/OAC.dir/test.c.o
OAC: CMakeFiles/OAC.dir/build.make
OAC: CMakeFiles/OAC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable OAC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OAC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OAC.dir/build: OAC
.PHONY : CMakeFiles/OAC.dir/build

CMakeFiles/OAC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OAC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OAC.dir/clean

CMakeFiles/OAC.dir/depend:
	cd /home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucas/unb/2020-02/oac/trab2-oac /home/lucas/unb/2020-02/oac/trab2-oac /home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug /home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug /home/lucas/unb/2020-02/oac/trab2-oac/cmake-build-debug/CMakeFiles/OAC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OAC.dir/depend

