BUILD_DIR_LINUX ?= ./build_linux
BUILD_DIR_WINDOWS ?= ./build_windows

all: 
	$(MAKE) -f linux.mk
	$(MAKE) -f windows.mk

linux:
	$(MAKE) -f linux.mk

windows:
	$(MAKE) -f windows.mk


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR_LINUX)
	$(RM) -r $(BUILD_DIR_WINDOWS)
