SRC_DIR = src
BUILD_DIR = build
EXEC_NAME = game.exe

EXEC = $(BUILD_DIR)/$(EXEC_NAME)

CC = g++ -std=c++17

CC_SDL = -lSDL2main -lSDL2 -lSDL2_ttf

SRC := $(wildcard $(SRC_DIR)/*.cpp)

all:
	$(CC) -Iinclude -Llib -o $(EXEC) ${SRC} -lmingw32 $(CC_SDL)
