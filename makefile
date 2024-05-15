include config.mk

create_docker_image:
ifeq (, $(shell which docker))
	$(error "No docker installed")
else
	docker build -t $(DOCKER_CONTAINER) .
endif

linux:
ifeq (, $(shell which docker))
	$(MAKE) -f linux.mk
else
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f linux.mk
endif

windows:
ifeq (, $(shell which docker))
	$(MAKE) -f windows.mk
else
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f windows.mk
endif

lint:
ifeq (, $(shell which docker))
	$(MAKE) -f lint.mk
else
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f lint.mk
endif

doc:
ifeq (, $(shell which docker))
	$(DOXYGEN) ttt_doxy
else
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(DOXYGEN) ttt_doxy
endif

run_linux:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(BUILD_DIR_LINUX)/$(TARGET_EXEC_LINUX)

all: linux windows

.PHONY: clean

clean_container:
ifeq (, $(shell which docker))
	$(error "No docker installed")
else
	docker image rm -f $(DOCKER_CONTAINER)
endif

clean:
ifeq (, $(shell which docker))
	$(RM) -r $(BUILD_DIR)
else
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(RM) -r $(BUILD_DIR)
endif

clean_lint:
ifeq (, $(shell which docker))
	$(RM) -r $(LINT_DIR)
else
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(RM) -r $(LINT_DIR)
endif

clean_doc:
ifeq (, $(shell which docker))
	$(RM) -r $(DOXYGEN_DIR)
else
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(RM) -r $(DOXYGEN_DIR)
endif

very_clean:clean clean_lint clean_doc clean_container

help:
	@echo use "make [all|linux|windows|run_linux|lint|doc|create_docker_image|clean|clean_lint|clean_doc|clean_container|very_clean|help]"
