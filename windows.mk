TARGET_EXEC_WINDOWS ?= tictactoe.exe

BUILD_DIR_WINDOWS ?= ./bin/build_windows
SRC_DIRS ?= $(shell pwd)

SRCS := $(shell find $(SRC_DIRS) -type f -name "*.cpp")
OBJS_WINDOWS := $(SRCS:%=$(BUILD_DIR_WINDOWS)/%.o)
DEPS_WINDOWS := $(OBJS_WINDOWS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP


# Windows Cross Compiler
WINCPP = x86_64-w64-mingw32-g++

# General compiler flags
COMPILE_FLAGS = -std=c++17 -Wall -Wextra -g -Werror

# Space-separated pkg-config libraries used by this project
LIBS = -static-libgcc -static-libstdc++


# windows
$(BUILD_DIR_WINDOWS)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(WINCPP) $(COMPILE_FLAGS) $(LIBS) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR_WINDOWS)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@ $(LIBS)

$(BUILD_DIR_WINDOWS)/$(TARGET_EXEC_WINDOWS): $(OBJS_WINDOWS)
	$(WINCPP) $(OBJS_WINDOWS) -o $@ $(LDFLAGS) $(LIBS)

@echo Windows build completed successfully!

-include $(DEPS)

MKDIR_P ?= mkdir -p