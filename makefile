include config.mk

launch_container:
ifneq ($(shell docker image ls | grep $(DOCKER_CONTAINER) | cut -d' ' -f 1), $(DOCKER_CONTAINER))
	docker build -t $(DOCKER_CONTAINER) .
endif
	docker run -d $(DOCKER_CONTAINER) tail -f

all:
	$(MAKE) -f linux.mk
	$(MAKE) -f windows.mk

linux: launch_container
	$(MAKE) -f linux.mk

windows: launch_container
	$(MAKE) -f windows.mk

lint: launch_container
	$(MAKE) -f lint.mk

doc: launch_container
	$(DOXYGEN) ttt_doxy

.PHONY: clean

clean_docker_container:
	docker stop $(DOCKER_CONTAINER)
	docker image rm -f $(DOCKER_CONTAINER)

clean:
	$(RM) -r $(BUILD_DIR)

clean_lint:
	$(RM) -r $(LINT_DIR)

clean_doc:
	$(RM) -r $(DOXYGEN_DIR)

very_clean:clean clean_lint clean_doc clean_docker_container

help:
	@echo use "make [all|linux|windows|lint|doc|launch_container|clean|clean_lint|clean_doc|clean_docker_container|very_clean|help]"
