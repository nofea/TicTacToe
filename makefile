TARGET_EXEC ?= tictactoe.out

BUILD_DIR ?= ./build
SRC_DIRS ?= $(shell pwd)

SRCS := $(shell find $(SRC_DIRS) -type f -name "*.cpp")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

# General compiler flags
COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g

# Space-separated pkg-config libraries used by this project
LIBS = -lstdc++

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(COMPILE_FLAGS) $(LIBS) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p