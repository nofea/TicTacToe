include config.mk

create_docker_image:
	docker build -t $(DOCKER_CONTAINER) .

linux:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f linux.mk

windows:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f windows.mk

lint:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f lint.mk

doc:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(DOXYGEN) ttt_doxy

run_linux:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(BUILD_DIR_LINUX)/$(TARGET_EXEC_LINUX)

all: linux windows

.PHONY: clean

clean_container:
	docker image rm -f $(DOCKER_CONTAINER)

clean:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(RM) -r $(BUILD_DIR)

clean_lint:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(RM) -r $(LINT_DIR)

clean_doc:
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(RM) -r $(DOXYGEN_DIR)

very_clean:clean clean_lint clean_doc clean_container

help:
	@echo use "make [all|linux|windows|run_linux|lint|doc|create_docker_image|clean|clean_lint|clean_doc|clean_container|very_clean|help]"
