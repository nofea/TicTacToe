TARGET_EXEC_LINUX ?= tictactoe.out
TARGET_EXEC_WINDOWS ?= tictactoe.exe

BUILD_DIR_LINUX ?= ./build_linux
BUILD_DIR_WINDOWS ?= ./build_windows
SRC_DIRS ?= $(shell pwd)

SRCS := $(shell find $(SRC_DIRS) -type f -name "*.cpp")
OBJS_LINUX := $(SRCS:%=$(BUILD_DIR_LINUX)/%.o)
OBJS_WINDOWS := $(SRCS:%=$(BUILD_DIR_WINDOWS)/%.o)
DEPS_LINUX := $(OBJS_LINUX:.o=.d)
DEPS_WINDOWS := $(OBJS_WINDOWS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

# Linux Compiler
LCPP = g++ 

# Windows Cross Compiler
WINCPP = x86_64-w64-mingw32-g++

# General compiler flags
COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g

# Space-separated pkg-config libraries used by this project
LIBS = -static-libgcc -static-libstdc++

# linux

$(BUILD_DIR_LINUX)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(LCPP) $(COMPILE_FLAGS) $(LIBS) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR_LINUX)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@ $(LIBS)


$(BUILD_DIR_LINUX)/$(TARGET_EXEC_LINUX): $(OBJS_LINUX)
	$(LCPP) $(OBJS_LINUX) -o $@ $(LDFLAGS) $(LIBS)


# windows
$(BUILD_DIR_WINDOWS)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(WINCPP) $(COMPILE_FLAGS) $(LIBS) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR_WINDOWS)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@ $(LIBS)

$(BUILD_DIR_WINDOWS)/$(TARGET_EXEC_WINDOWS): $(OBJS_WINDOWS)
	$(WINCPP) $(OBJS_WINDOWS) -o $@ $(LDFLAGS) $(LIBS)


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR_LINUX)
	$(RM) -r $(BUILD_DIR_WINDOWS)

-include $(DEPS)

MKDIR_P ?= mkdir -p