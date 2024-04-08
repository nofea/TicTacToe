# Use this makefile to collect all common variables

BUILD_DIR:=./bin
BUILD_DIR_LINUX?=$(BUILD_DIR)/build_linux
BUILD_DIR_WINDOWS?=$(BUILD_DIR)/build_windows

DOXYGEN:=doxygen
DOXYGEN_DIR:=Documentation

LINT_DIR:=lintresults

DOCKER_CONTAINER:=tic-tac-toe

TARGET_EXEC_LINUX?=tictactoe.out

TARGET_EXEC_WINDOWS?=tictactoe.exe
