OBJS = $(wildcard *.cpp)
OBJ_NAME = cataurant.exe
RESOURCES_SCRIPT = cataurant.rc
RESOURCES_FILE = cataurant.res
COMPILER_FLAGS = -std=c++17 -static-libgcc -static-libstdc++
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_net
INCLUDE_DIR = -Iinclude
LIB_DIR = -Llib

compile:
	windres $(RESOURCES_SCRIPT) -O coff -o $(RESOURCES_FILE)
	g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(RESOURCES_FILE)