BUILD_DIR ?= build

default: build

cmake:
    cd $(BUILD_DIR) && cmake ..

build: cmake
    cd $(BUILD_DIR) && make

clean: rm $(BUILD_DIR)/* -rf

.PHONY: cmake build clean
