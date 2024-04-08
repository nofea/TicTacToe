include config.mk

create_docker_image:
	docker build -t $(DOCKER_CONTAINER) .

linux: create_docker_image
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f linux.mk

windows: create_docker_image
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f windows.mk

lint: create_docker_image
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(MAKE) -f lint.mk

doc: create_docker_image
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(DOXYGEN) ttt_doxy

run_linux: create_docker_image
	docker run --mount type=bind,source=.,target=/TicTacToe --rm $(DOCKER_CONTAINER) $(BUILD_DIR_LINUX)/$(TARGET_EXEC_LINUX)

all: linux windows

.PHONY: clean

clean_container:
	docker image rm -f $(DOCKER_CONTAINER)

clean:
	$(RM) -r $(BUILD_DIR)

clean_lint:
	$(RM) -r $(LINT_DIR)

clean_doc:
	$(RM) -r $(DOXYGEN_DIR)

very_clean:clean clean_lint clean_doc clean_container

help:
	@echo use "make [all|linux|windows|run_linux|lint|doc|create_docker_image|clean|clean_lint|clean_doc|clean_container|very_clean|help]"
