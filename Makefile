CXX := g++
FLAGS := -Wall -Wextra --pedantic -Wno-pointer-arith
SRC := src/main.cpp
INCLUDE_DIR := -Iheaders
BUILD_DIR := build
EXECUTABLE_NAME := app
DEBUG_FLAG := -ggdb

build:
	${CXX} ${FLAGS} -o ${BUILD_DIR}/${EXECUTABLE_NAME} ${SRC} ${INCLUDE_DIR}

debug_build:
	${CXX} ${DEBUG_FLAG} ${FLAGS} -o ${BUILD_DIR}/${EXECUTABLE_NAME} ${SRC} ${INCLUDE_DIR}

debug_run:
	${CXX} ${DEBUG_FLAG} ${FLAGS} -o ${BUILD_DIR}/${EXECUTABLE_NAME} ${SRC} ${INCLUDE_DIR}
	${BUILD_DIR}/${EXECUTABLE_NAME}

run: build
	${BUILD_DIR}/${EXECUTABLE_NAME}
