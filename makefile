BUILD_DIR := ./bin
BUILD_DIR_LINUX ?= $(BUILD_DIR)/build_linux
BUILD_DIR_WINDOWS ?= $(BUILD_DIR)/build_windows

DOXYGEN := doxygen
DOXYGEN_DIR := Documentation

LINT_DIR := lintresults

all: 
	$(MAKE) -f linux.mk
	$(MAKE) -f windows.mk

linux:
	$(MAKE) -f linux.mk

windows:
	$(MAKE) -f windows.mk

lint:
	$(MAKE) -f lint.mk

doc:
	$(DOXYGEN) ttt_doxy
	
.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

cleanlint:
	$(RM) -r $(LINT_DIR)

cleandoc:
	$(RM) -r $(DOXYGEN_DIR)

help:
	@echo use "make [all|linux|windows|lint|doc|clean|cleanlint|cleandoc|help]" 
