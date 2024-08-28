# Object files
OBJS = $(wildcard src/*.cpp)

# Output executable
OBJ_NAME = cataurant.exe

# Compiler and linker flags
COMPILER_FLAGS = -std=c++17

# Information and icons
RESOURCES_SCRIPT = cataurant.rc
RESOURCES_FILE = cataurant.res

# Platform-specific settings
ifeq ($(OS),Windows_NT)
	LINKER_FLAGS = -static -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lpthread
    ifdef PROCESSOR_ARCHITEW6432
        # 32-bit process on 64-bit Windows (targeting 32-bit build)
		INCLUDE_DIR = -Iinclude/32bit
		LIB_DIR = -Llib/32bit
        compile:
	        windres $(RESOURCES_SCRIPT) -O coff -o $(RESOURCES_FILE)
	        g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(RESOURCES_FILE)
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            # 64-bit Windows
			INCLUDE_DIR = -Iinclude/64bit
			LIB_DIR = -Llib/64bit
            compile:
	            windres $(RESOURCES_SCRIPT) -O coff -o $(RESOURCES_FILE)
	            g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(RESOURCES_FILE)
        else
            # 32-bit Windows
            INCLUDE_DIR = -Iinclude/32bit
			LIB_DIR = -Llib/32bit
        	compile:
	        	windres $(RESOURCES_SCRIPT) -O coff -o $(RESOURCES_FILE)
	        	g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(RESOURCES_FILE)
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        # macOS
        INCLUDE_DIR = -I/opt/homebrew/include/SDL2
        LIB_DIR = -L/opt/homebrew/lib
        compile:
	        g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(OBJS) $(LIB_DIR) -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o $(OBJ_NAME)
    else
        # Linux
        INCLUDE_DIR = -I/usr/include/SDL2
        compile:
	        g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(OBJS) -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o $(OBJ_NAME)
    endif
endif
