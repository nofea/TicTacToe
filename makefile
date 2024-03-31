include config.mk

create_container:
ifneq ($(shell docker image ls | grep $(DOCKER_CONTAINER) | cut -d' ' -f 1), $(DOCKER_CONTAINER))
	docker build -t $(DOCKER_CONTAINER) .
endif

all:
	$(MAKE) -f linux.mk
	$(MAKE) -f windows.mk

linux: create_container
	docker run -it --rm $(DOCKER_CONTAINER) $(MAKE) -f linux.mk
	

windows: create_container
	docker run -it --rm $(DOCKER_CONTAINER) $(MAKE) -f windows.mk

lint: create_container
	docker run -it --rm $(DOCKER_CONTAINER) $(MAKE) -f lint.mk

doc: create_container
	docker run -it --rm $(DOCKER_CONTAINER) $(DOXYGEN) ttt_doxy

run_linux: create_container
	docker run -it --rm $(DOCKER_CONTAINER) $(BUILD_DIR_LINUX)/$(TARGET_EXEC_LINUX)

.PHONY: clean

clean_container:
	docker stop $(DOCKER_CONTAINER)
	docker image rm -f $(DOCKER_CONTAINER)

clean:
	$(RM) -r $(BUILD_DIR)

clean_lint:
	$(RM) -r $(LINT_DIR)

clean_doc:
	$(RM) -r $(DOXYGEN_DIR)

very_clean:clean clean_lint clean_doc clean_container

help:
	@echo use "make [all|linux|windows|run_linux|lint|doc|create_container|clean|clean_lint|clean_doc|clean_container|very_clean|help]"
