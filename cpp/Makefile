BUILD_DIR ?= build

default: build

cmake:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..

build:
	cd $(BUILD_DIR) && make

clean: rm $(BUILD_DIR)/* -rf

.PHONY: cmake build clean
