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
CMAKE_COMMAND = "/Applications/CMake 2.8-12.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-12.app/Contents/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-12.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Milc1/Documents/EngineDevelopment/KonTiKi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build

# Include any dependencies generated for this target.
include CMakeFiles/kontiki.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kontiki.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kontiki.dir/flags.make

CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o: CMakeFiles/kontiki.dir/flags.make
CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o: ../Source/Core/Object.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o -c /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/Object.cpp

CMakeFiles/kontiki.dir/Source/Core/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kontiki.dir/Source/Core/Object.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/Object.cpp > CMakeFiles/kontiki.dir/Source/Core/Object.cpp.i

CMakeFiles/kontiki.dir/Source/Core/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kontiki.dir/Source/Core/Object.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/Object.cpp -o CMakeFiles/kontiki.dir/Source/Core/Object.cpp.s

CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o.requires:
.PHONY : CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o.requires

CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o.provides: CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o.requires
	$(MAKE) -f CMakeFiles/kontiki.dir/build.make CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o.provides.build
.PHONY : CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o.provides

CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o.provides.build: CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o

CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o: CMakeFiles/kontiki.dir/flags.make
CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o: ../Source/Core/GameObject.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o -c /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GameObject.cpp

CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GameObject.cpp > CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.i

CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GameObject.cpp -o CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.s

CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o.requires:
.PHONY : CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o.requires

CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o.provides: CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o.requires
	$(MAKE) -f CMakeFiles/kontiki.dir/build.make CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o.provides.build
.PHONY : CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o.provides

CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o.provides.build: CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o

CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o: CMakeFiles/kontiki.dir/flags.make
CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o: ../Source/Core/GameEngine.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o -c /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GameEngine.cpp

CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GameEngine.cpp > CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.i

CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GameEngine.cpp -o CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.s

CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o.requires:
.PHONY : CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o.requires

CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o.provides: CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o.requires
	$(MAKE) -f CMakeFiles/kontiki.dir/build.make CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o.provides.build
.PHONY : CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o.provides

CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o.provides.build: CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o

CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o: CMakeFiles/kontiki.dir/flags.make
CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o: ../Source/Core/Component.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o -c /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/Component.cpp

CMakeFiles/kontiki.dir/Source/Core/Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kontiki.dir/Source/Core/Component.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/Component.cpp > CMakeFiles/kontiki.dir/Source/Core/Component.cpp.i

CMakeFiles/kontiki.dir/Source/Core/Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kontiki.dir/Source/Core/Component.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/Component.cpp -o CMakeFiles/kontiki.dir/Source/Core/Component.cpp.s

CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o.requires:
.PHONY : CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o.requires

CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o.provides: CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o.requires
	$(MAKE) -f CMakeFiles/kontiki.dir/build.make CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o.provides.build
.PHONY : CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o.provides

CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o.provides.build: CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o

CMakeFiles/kontiki.dir/Source/Core/System.cpp.o: CMakeFiles/kontiki.dir/flags.make
CMakeFiles/kontiki.dir/Source/Core/System.cpp.o: ../Source/Core/System.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kontiki.dir/Source/Core/System.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kontiki.dir/Source/Core/System.cpp.o -c /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/System.cpp

CMakeFiles/kontiki.dir/Source/Core/System.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kontiki.dir/Source/Core/System.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/System.cpp > CMakeFiles/kontiki.dir/Source/Core/System.cpp.i

CMakeFiles/kontiki.dir/Source/Core/System.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kontiki.dir/Source/Core/System.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/System.cpp -o CMakeFiles/kontiki.dir/Source/Core/System.cpp.s

CMakeFiles/kontiki.dir/Source/Core/System.cpp.o.requires:
.PHONY : CMakeFiles/kontiki.dir/Source/Core/System.cpp.o.requires

CMakeFiles/kontiki.dir/Source/Core/System.cpp.o.provides: CMakeFiles/kontiki.dir/Source/Core/System.cpp.o.requires
	$(MAKE) -f CMakeFiles/kontiki.dir/build.make CMakeFiles/kontiki.dir/Source/Core/System.cpp.o.provides.build
.PHONY : CMakeFiles/kontiki.dir/Source/Core/System.cpp.o.provides

CMakeFiles/kontiki.dir/Source/Core/System.cpp.o.provides.build: CMakeFiles/kontiki.dir/Source/Core/System.cpp.o

CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o: CMakeFiles/kontiki.dir/flags.make
CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o: ../Source/Core/GraphicsSystem.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o -c /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GraphicsSystem.cpp

CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GraphicsSystem.cpp > CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.i

CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Milc1/Documents/EngineDevelopment/KonTiKi/Source/Core/GraphicsSystem.cpp -o CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.s

CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o.requires:
.PHONY : CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o.requires

CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o.provides: CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/kontiki.dir/build.make CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o.provides.build
.PHONY : CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o.provides

CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o.provides.build: CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o

# Object files for target kontiki
kontiki_OBJECTS = \
"CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o" \
"CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o" \
"CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o" \
"CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o" \
"CMakeFiles/kontiki.dir/Source/Core/System.cpp.o" \
"CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o"

# External object files for target kontiki
kontiki_EXTERNAL_OBJECTS =

libkontiki.a: CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o
libkontiki.a: CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o
libkontiki.a: CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o
libkontiki.a: CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o
libkontiki.a: CMakeFiles/kontiki.dir/Source/Core/System.cpp.o
libkontiki.a: CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o
libkontiki.a: CMakeFiles/kontiki.dir/build.make
libkontiki.a: CMakeFiles/kontiki.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libkontiki.a"
	$(CMAKE_COMMAND) -P CMakeFiles/kontiki.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kontiki.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kontiki.dir/build: libkontiki.a
.PHONY : CMakeFiles/kontiki.dir/build

CMakeFiles/kontiki.dir/requires: CMakeFiles/kontiki.dir/Source/Core/Object.cpp.o.requires
CMakeFiles/kontiki.dir/requires: CMakeFiles/kontiki.dir/Source/Core/GameObject.cpp.o.requires
CMakeFiles/kontiki.dir/requires: CMakeFiles/kontiki.dir/Source/Core/GameEngine.cpp.o.requires
CMakeFiles/kontiki.dir/requires: CMakeFiles/kontiki.dir/Source/Core/Component.cpp.o.requires
CMakeFiles/kontiki.dir/requires: CMakeFiles/kontiki.dir/Source/Core/System.cpp.o.requires
CMakeFiles/kontiki.dir/requires: CMakeFiles/kontiki.dir/Source/Core/GraphicsSystem.cpp.o.requires
.PHONY : CMakeFiles/kontiki.dir/requires

CMakeFiles/kontiki.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kontiki.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kontiki.dir/clean

CMakeFiles/kontiki.dir/depend:
	cd /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Milc1/Documents/EngineDevelopment/KonTiKi /Users/Milc1/Documents/EngineDevelopment/KonTiKi /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build /Users/Milc1/Documents/EngineDevelopment/KonTiKi/build/CMakeFiles/kontiki.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kontiki.dir/depend

