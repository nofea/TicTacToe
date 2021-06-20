# linting oh linting...

LINT_BIN := cppcheck
LINT_DIR := ./lintresults
LINT_SUFFIX := cppcheck-lint

SRC_DIRS ?= $(shell pwd)
SRCS ?= $(shell find $(SRC_DIRS) -type f -name "*.cpp")

$(LINT_DIR):
	$(MKDIR_P) $(LINT_DIR)
	for src_file in $(SRCS); do \
		echo $$src_file; \
		$(LINT_BIN) --enable=all --language=c++ --template=vs -I $(SRC_DIRS) $$src_file 2> $(LINT_DIR)/$$(basename $$src_file).$(LINT_SUFFIX); \
	done
	
	@echo Linting completed successfully!

MKDIR_P ?= mkdir -p
