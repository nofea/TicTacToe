TARGET_EXEC_LINUX ?= tictactoe.out

BUILD_DIR_LINUX ?= ./bin/build_linux
SRC_DIRS ?= $(shell pwd)

SRCS := $(shell find $(SRC_DIRS) -type f -name "*.cpp")
OBJS_LINUX := $(SRCS:%=$(BUILD_DIR_LINUX)/%.o)
DEPS_LINUX := $(OBJS_LINUX:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP
OPTIMIZATION := -O3

# Linux Compiler
LCPP = g++ 

# General compiler flags
COMPILE_FLAGS = -std=c++17 -Wall -Wextra -g -Werror

# Space-separated pkg-config libraries used by this project
LIBS = -static-libgcc -static-libstdc++

# linux
$(BUILD_DIR_LINUX)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(LCPP) $(COMPILE_FLAGS) $(LIBS) $(CPPFLAGS) $(OPTIMIZATION) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR_LINUX)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@ $(LIBS)


$(BUILD_DIR_LINUX)/$(TARGET_EXEC_LINUX): $(OBJS_LINUX)
	$(LCPP) $(OBJS_LINUX) -o $@ $(LDFLAGS) $(LIBS)

	@echo Linux build completed successfully!

-include $(DEPS)

MKDIR_P ?= mkdir -p
