# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/wuzm/muduo/my_muduo_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wuzm/muduo/my_muduo_2

# Include any dependencies generated for this target.
include src/CMakeFiles/MyMuduoLib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/MyMuduoLib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/MyMuduoLib.dir/flags.make

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o: src/Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/Buffer.cpp

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Buffer.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/Buffer.cpp > CMakeFiles/MyMuduoLib.dir/Buffer.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Buffer.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/Buffer.cpp -o CMakeFiles/MyMuduoLib.dir/Buffer.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o


src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o: src/Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Channel.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/Channel.cpp

src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Channel.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/Channel.cpp > CMakeFiles/MyMuduoLib.dir/Channel.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Channel.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/Channel.cpp -o CMakeFiles/MyMuduoLib.dir/Channel.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o


src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o: src/CommunicateChannel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/CommunicateChannel.cpp

src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/CommunicateChannel.cpp > CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.i

src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/CommunicateChannel.cpp -o CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.s

src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o


src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o: src/ConnectChannel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/ConnectChannel.cpp

src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/ConnectChannel.cpp > CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.i

src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/ConnectChannel.cpp -o CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.s

src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o


src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o: src/EpollPoller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/EpollPoller.cpp

src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/EpollPoller.cpp > CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.i

src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/EpollPoller.cpp -o CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.s

src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o


src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o: src/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/EventLoop.cpp

src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/EventLoop.cpp > CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.i

src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/EventLoop.cpp -o CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.s

src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o


src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o: src/EventLoopThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/EventLoopThread.cpp

src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/EventLoopThread.cpp > CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.i

src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/EventLoopThread.cpp -o CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.s

src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o


src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o: src/EventLoopThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/EventLoopThreadPool.cpp

src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/EventLoopThreadPool.cpp > CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.i

src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/EventLoopThreadPool.cpp -o CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.s

src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o


src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o: src/InetAddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/InetAddress.cpp

src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/InetAddress.cpp > CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.i

src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/InetAddress.cpp -o CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.s

src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o


src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o: src/ListenChannel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/ListenChannel.cpp

src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/ListenChannel.cpp > CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.i

src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/ListenChannel.cpp -o CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.s

src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o


src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o: src/Poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Poller.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/Poller.cpp

src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Poller.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/Poller.cpp > CMakeFiles/MyMuduoLib.dir/Poller.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Poller.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/Poller.cpp -o CMakeFiles/MyMuduoLib.dir/Poller.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o


src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o: src/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Socket.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/Socket.cpp

src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Socket.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/Socket.cpp > CMakeFiles/MyMuduoLib.dir/Socket.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Socket.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/Socket.cpp -o CMakeFiles/MyMuduoLib.dir/Socket.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o


src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o: src/TcpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/TcpClient.cpp

src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/TcpClient.cpp > CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.i

src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/TcpClient.cpp -o CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.s

src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o


src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o: src/TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/TcpServer.cpp

src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/TcpServer.cpp > CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.i

src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/TcpServer.cpp -o CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.s

src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o


src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o: src/CMakeFiles/MyMuduoLib.dir/flags.make
src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o: src/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o"
	cd /home/wuzm/muduo/my_muduo_2/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyMuduoLib.dir/Thread.cpp.o -c /home/wuzm/muduo/my_muduo_2/src/Thread.cpp

src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyMuduoLib.dir/Thread.cpp.i"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuzm/muduo/my_muduo_2/src/Thread.cpp > CMakeFiles/MyMuduoLib.dir/Thread.cpp.i

src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyMuduoLib.dir/Thread.cpp.s"
	cd /home/wuzm/muduo/my_muduo_2/src && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuzm/muduo/my_muduo_2/src/Thread.cpp -o CMakeFiles/MyMuduoLib.dir/Thread.cpp.s

src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o.requires:

.PHONY : src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o.requires

src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o.provides: src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MyMuduoLib.dir/build.make src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o.provides.build
.PHONY : src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o.provides

src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o.provides.build: src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o


# Object files for target MyMuduoLib
MyMuduoLib_OBJECTS = \
"CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Channel.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Poller.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Socket.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o" \
"CMakeFiles/MyMuduoLib.dir/Thread.cpp.o"

# External object files for target MyMuduoLib
MyMuduoLib_EXTERNAL_OBJECTS =

src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/build.make
src/libMyMuduolib.a: src/CMakeFiles/MyMuduoLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wuzm/muduo/my_muduo_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX static library libMyMuduolib.a"
	cd /home/wuzm/muduo/my_muduo_2/src && $(CMAKE_COMMAND) -P CMakeFiles/MyMuduoLib.dir/cmake_clean_target.cmake
	cd /home/wuzm/muduo/my_muduo_2/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyMuduoLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/MyMuduoLib.dir/build: src/libMyMuduolib.a

.PHONY : src/CMakeFiles/MyMuduoLib.dir/build

src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/Buffer.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/Channel.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/CommunicateChannel.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/ConnectChannel.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/EpollPoller.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/EventLoop.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/EventLoopThread.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/EventLoopThreadPool.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/InetAddress.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/ListenChannel.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/Poller.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/Socket.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/TcpClient.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/TcpServer.cpp.o.requires
src/CMakeFiles/MyMuduoLib.dir/requires: src/CMakeFiles/MyMuduoLib.dir/Thread.cpp.o.requires

.PHONY : src/CMakeFiles/MyMuduoLib.dir/requires

src/CMakeFiles/MyMuduoLib.dir/clean:
	cd /home/wuzm/muduo/my_muduo_2/src && $(CMAKE_COMMAND) -P CMakeFiles/MyMuduoLib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/MyMuduoLib.dir/clean

src/CMakeFiles/MyMuduoLib.dir/depend:
	cd /home/wuzm/muduo/my_muduo_2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wuzm/muduo/my_muduo_2 /home/wuzm/muduo/my_muduo_2/src /home/wuzm/muduo/my_muduo_2 /home/wuzm/muduo/my_muduo_2/src /home/wuzm/muduo/my_muduo_2/src/CMakeFiles/MyMuduoLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/MyMuduoLib.dir/depend

