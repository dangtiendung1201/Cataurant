OBJS = $(wildcard *.cpp)
OBJ_NAME = main.exe
COMPILER_FLAGS = -std=c++17 
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_net
INCLUDE_DIR = -Iinclude
LIB_DIR = -Llib

compile:
	g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)