# ifeq ($(OS),Windows_NT)
# OBJS = $(wildcard src/*.cpp)
# OBJ_NAME = cataurant.exe
# RESOURCES_SCRIPT = cataurant.rc
# RESOURCES_FILE = cataurant.res
# COMPILER_FLAGS = -std=c++17 -static-libgcc -static-libstdc++
# LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
# INCLUDE_DIR = -Iinclude/32bit
# LIB_DIR = -Llib/32bit
# compile:
# 	windres $(RESOURCES_SCRIPT) -O coff -o $(RESOURCES_FILE)
# 	g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(RESOURCES_FILE)
# else
# OBJS = $(wildcard src/*.cpp)
# OBJ_NAME = cataurant.exe
# COMPILER_FLAGS = -std=c++17 -Wall -g -lm
# LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
# compile:
# 	emcc -o index.html $(OBJS) $(COMPILER_FLAGS) -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --use-preload-plugins --preload-file assets -s  USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -s ALLOW_MEMORY_GROWTH=1
# endif

OBJS = $(wildcard src/*.cpp)
OBJ_NAME = cataurant.exe
COMPILER_FLAGS = -std=c++17 -Wall -g -lm
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
compile:
	emcc -o index.html $(OBJS) $(COMPILER_FLAGS) -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file assets --use-preload-plugins --preload-file assets/images/background.png -s  USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -s ALLOW_MEMORY_GROWTH=1
# emcc -o index.html src/button.cpp src/main.cpp src/res.cpp src/customer.cpp src/game.cpp src/dishes.cpp src/seller.cpp src/ui.cpp src/texture.cpp src/ultils.cpp src/hungrycat.cpp src/ingredients.cpp -Wall -g -lm -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file assets -s USE_SDL_MIXER=2 -s USE_SDL_TTF=2 -s ALLOW_MEMORY_GROWTH=1 -std=c++17 -Wno-c99-extensions -Wno-error
