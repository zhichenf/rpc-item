# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/fzc/rpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fzc/rpc/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mprpc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/mprpc.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mprpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mprpc.dir/flags.make

src/CMakeFiles/mprpc.dir/file_guard.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/file_guard.cc.o: ../src/file_guard.cc
src/CMakeFiles/mprpc.dir/file_guard.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mprpc.dir/file_guard.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/file_guard.cc.o -MF CMakeFiles/mprpc.dir/file_guard.cc.o.d -o CMakeFiles/mprpc.dir/file_guard.cc.o -c /home/fzc/rpc/src/file_guard.cc

src/CMakeFiles/mprpc.dir/file_guard.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/file_guard.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/file_guard.cc > CMakeFiles/mprpc.dir/file_guard.cc.i

src/CMakeFiles/mprpc.dir/file_guard.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/file_guard.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/file_guard.cc -o CMakeFiles/mprpc.dir/file_guard.cc.s

src/CMakeFiles/mprpc.dir/logger.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/logger.cc.o: ../src/logger.cc
src/CMakeFiles/mprpc.dir/logger.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/mprpc.dir/logger.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/logger.cc.o -MF CMakeFiles/mprpc.dir/logger.cc.o.d -o CMakeFiles/mprpc.dir/logger.cc.o -c /home/fzc/rpc/src/logger.cc

src/CMakeFiles/mprpc.dir/logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/logger.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/logger.cc > CMakeFiles/mprpc.dir/logger.cc.i

src/CMakeFiles/mprpc.dir/logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/logger.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/logger.cc -o CMakeFiles/mprpc.dir/logger.cc.s

src/CMakeFiles/mprpc.dir/mprpc_application.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/mprpc_application.cc.o: ../src/mprpc_application.cc
src/CMakeFiles/mprpc.dir/mprpc_application.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/mprpc.dir/mprpc_application.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/mprpc_application.cc.o -MF CMakeFiles/mprpc.dir/mprpc_application.cc.o.d -o CMakeFiles/mprpc.dir/mprpc_application.cc.o -c /home/fzc/rpc/src/mprpc_application.cc

src/CMakeFiles/mprpc.dir/mprpc_application.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/mprpc_application.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/mprpc_application.cc > CMakeFiles/mprpc.dir/mprpc_application.cc.i

src/CMakeFiles/mprpc.dir/mprpc_application.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/mprpc_application.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/mprpc_application.cc -o CMakeFiles/mprpc.dir/mprpc_application.cc.s

src/CMakeFiles/mprpc.dir/mprpc_channel.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/mprpc_channel.cc.o: ../src/mprpc_channel.cc
src/CMakeFiles/mprpc.dir/mprpc_channel.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/mprpc.dir/mprpc_channel.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/mprpc_channel.cc.o -MF CMakeFiles/mprpc.dir/mprpc_channel.cc.o.d -o CMakeFiles/mprpc.dir/mprpc_channel.cc.o -c /home/fzc/rpc/src/mprpc_channel.cc

src/CMakeFiles/mprpc.dir/mprpc_channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/mprpc_channel.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/mprpc_channel.cc > CMakeFiles/mprpc.dir/mprpc_channel.cc.i

src/CMakeFiles/mprpc.dir/mprpc_channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/mprpc_channel.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/mprpc_channel.cc -o CMakeFiles/mprpc.dir/mprpc_channel.cc.s

src/CMakeFiles/mprpc.dir/mprpc_configure.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/mprpc_configure.cc.o: ../src/mprpc_configure.cc
src/CMakeFiles/mprpc.dir/mprpc_configure.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/mprpc.dir/mprpc_configure.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/mprpc_configure.cc.o -MF CMakeFiles/mprpc.dir/mprpc_configure.cc.o.d -o CMakeFiles/mprpc.dir/mprpc_configure.cc.o -c /home/fzc/rpc/src/mprpc_configure.cc

src/CMakeFiles/mprpc.dir/mprpc_configure.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/mprpc_configure.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/mprpc_configure.cc > CMakeFiles/mprpc.dir/mprpc_configure.cc.i

src/CMakeFiles/mprpc.dir/mprpc_configure.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/mprpc_configure.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/mprpc_configure.cc -o CMakeFiles/mprpc.dir/mprpc_configure.cc.s

src/CMakeFiles/mprpc.dir/mprpc_controller.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/mprpc_controller.cc.o: ../src/mprpc_controller.cc
src/CMakeFiles/mprpc.dir/mprpc_controller.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/mprpc.dir/mprpc_controller.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/mprpc_controller.cc.o -MF CMakeFiles/mprpc.dir/mprpc_controller.cc.o.d -o CMakeFiles/mprpc.dir/mprpc_controller.cc.o -c /home/fzc/rpc/src/mprpc_controller.cc

src/CMakeFiles/mprpc.dir/mprpc_controller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/mprpc_controller.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/mprpc_controller.cc > CMakeFiles/mprpc.dir/mprpc_controller.cc.i

src/CMakeFiles/mprpc.dir/mprpc_controller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/mprpc_controller.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/mprpc_controller.cc -o CMakeFiles/mprpc.dir/mprpc_controller.cc.s

src/CMakeFiles/mprpc.dir/mprpc_provicer.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/mprpc_provicer.cc.o: ../src/mprpc_provicer.cc
src/CMakeFiles/mprpc.dir/mprpc_provicer.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/mprpc.dir/mprpc_provicer.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/mprpc_provicer.cc.o -MF CMakeFiles/mprpc.dir/mprpc_provicer.cc.o.d -o CMakeFiles/mprpc.dir/mprpc_provicer.cc.o -c /home/fzc/rpc/src/mprpc_provicer.cc

src/CMakeFiles/mprpc.dir/mprpc_provicer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/mprpc_provicer.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/mprpc_provicer.cc > CMakeFiles/mprpc.dir/mprpc_provicer.cc.i

src/CMakeFiles/mprpc.dir/mprpc_provicer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/mprpc_provicer.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/mprpc_provicer.cc -o CMakeFiles/mprpc.dir/mprpc_provicer.cc.s

src/CMakeFiles/mprpc.dir/rpcheader.pb.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/rpcheader.pb.cc.o: ../src/rpcheader.pb.cc
src/CMakeFiles/mprpc.dir/rpcheader.pb.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/mprpc.dir/rpcheader.pb.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/rpcheader.pb.cc.o -MF CMakeFiles/mprpc.dir/rpcheader.pb.cc.o.d -o CMakeFiles/mprpc.dir/rpcheader.pb.cc.o -c /home/fzc/rpc/src/rpcheader.pb.cc

src/CMakeFiles/mprpc.dir/rpcheader.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/rpcheader.pb.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/rpcheader.pb.cc > CMakeFiles/mprpc.dir/rpcheader.pb.cc.i

src/CMakeFiles/mprpc.dir/rpcheader.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/rpcheader.pb.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/rpcheader.pb.cc -o CMakeFiles/mprpc.dir/rpcheader.pb.cc.s

src/CMakeFiles/mprpc.dir/zookeeper_util.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/zookeeper_util.cc.o: ../src/zookeeper_util.cc
src/CMakeFiles/mprpc.dir/zookeeper_util.cc.o: src/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/mprpc.dir/zookeeper_util.cc.o"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mprpc.dir/zookeeper_util.cc.o -MF CMakeFiles/mprpc.dir/zookeeper_util.cc.o.d -o CMakeFiles/mprpc.dir/zookeeper_util.cc.o -c /home/fzc/rpc/src/zookeeper_util.cc

src/CMakeFiles/mprpc.dir/zookeeper_util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/zookeeper_util.cc.i"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzc/rpc/src/zookeeper_util.cc > CMakeFiles/mprpc.dir/zookeeper_util.cc.i

src/CMakeFiles/mprpc.dir/zookeeper_util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/zookeeper_util.cc.s"
	cd /home/fzc/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzc/rpc/src/zookeeper_util.cc -o CMakeFiles/mprpc.dir/zookeeper_util.cc.s

# Object files for target mprpc
mprpc_OBJECTS = \
"CMakeFiles/mprpc.dir/file_guard.cc.o" \
"CMakeFiles/mprpc.dir/logger.cc.o" \
"CMakeFiles/mprpc.dir/mprpc_application.cc.o" \
"CMakeFiles/mprpc.dir/mprpc_channel.cc.o" \
"CMakeFiles/mprpc.dir/mprpc_configure.cc.o" \
"CMakeFiles/mprpc.dir/mprpc_controller.cc.o" \
"CMakeFiles/mprpc.dir/mprpc_provicer.cc.o" \
"CMakeFiles/mprpc.dir/rpcheader.pb.cc.o" \
"CMakeFiles/mprpc.dir/zookeeper_util.cc.o"

# External object files for target mprpc
mprpc_EXTERNAL_OBJECTS =

../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/file_guard.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/logger.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/mprpc_application.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/mprpc_channel.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/mprpc_configure.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/mprpc_controller.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/mprpc_provicer.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/rpcheader.pb.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/zookeeper_util.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/build.make
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fzc/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library ../../lib/libmprpc.a"
	cd /home/fzc/rpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean_target.cmake
	cd /home/fzc/rpc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mprpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mprpc.dir/build: ../lib/libmprpc.a
.PHONY : src/CMakeFiles/mprpc.dir/build

src/CMakeFiles/mprpc.dir/clean:
	cd /home/fzc/rpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mprpc.dir/clean

src/CMakeFiles/mprpc.dir/depend:
	cd /home/fzc/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fzc/rpc /home/fzc/rpc/src /home/fzc/rpc/build /home/fzc/rpc/build/src /home/fzc/rpc/build/src/CMakeFiles/mprpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mprpc.dir/depend

