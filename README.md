<h1 align="center">🐈Cataurant🐈</h1>

[![Actions Status](https://github.com/dangtiendung1201/TestAction/workflows/MacOS/badge.svg)](https://github.com/dangtiendung1201/TestAction/actions)
[![Actions Status](https://github.com/dangtiendung1201/TestAction/workflows/Windows/badge.svg)](https://github.com/dangtiendung1201/TestAction/actions)
[![Actions Status](https://github.com/dangtiendung1201/TestAction/workflows/Ubuntu/badge.svg)](https://github.com/dangtiendung1201/TestAction/actions)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/dangtiendung1201/Cataurant)](https://github.com/dangtiendung1201/Cataurant)

This is my own game project using `C`, `C++` and `SDL2 libraries` at University of Engineering and Technology, Vietnam National University.

# Table of Contents
- [Information](##Information)
- [Idea](##Idea)
- [Milestone](##Milestone)
- [Prerequisites](##Prerequisites)
- [Build](##Build)
- [Gameplay](##Gameplay)
- [Controls](##Controls)
- [Credits](##Credits)
- [Notes](##Notes)

## Information

**Name:**  Đặng Tiến Dũng
**Student ID:** 22026523
**Class:** K67J
**Email:** dangtiendung1201@gmail.com
**Facebook:** fb.com/dangtiendung1201

## Idea
From mini-game called Comfy Cakes in Purple Place ([Info](https://en.wikipedia.org/wiki/Purble_Place "Infomation about the game"), [Demo](https://www.youtube.com/watch?v=TRxOvRQpPmg&pp=ygUXcHVyYmxlIHBsYWNlIHdpbmRvd3MgNyA%3D)) included with Windows 7 operating systems, I create a new game with the same logic[^fn1]. Instead of a "conveyor belt" in the original game, I use a "deque" to manage "burger ingredients". "Requests" are shown as "customers", ... and many changes.

## Milestone
- [x] **08/03/2023:** Have ideas about the game.
- [x] **12/03/2023:** Initialize all SDL libraries + Implement and refactor some SDL utilities.
- [x] **14/03/2023:** Finish game menu.
- [x] **15/03/2023:** Add some features in menu.
- [x] **16/03/2023:** Show game background
- [x] **17/03/2023:** Make first game character move.
- [x] **22/03/2023:** Make more game characters
- [x] **25/03/2023:** Render more characters
- [x] **06/04/2023:** Implement burger ingredients.
- [x] **06/04/2023:** Implement burger ingredients.
- [x] **08/04/2023:** Release 1.0 version.
- [ ] **Before 14/04/2023:** Add "change language" features
- [ ] **Before 30/04/2023:** Finish the game

## Prerequisites
All dependencies **(for Windows only)**[^fn2] are in [bin](\null), [library](\null), [lib](\null)
- `C`, `C++`
- `SDL2`, `SDL2 image`, `SDL2 mixer`, `SDL2 ttf`
## Build
<span style="color:red">**Note:** Because of the differences in coding environments, `Makefile` provided below could not work. In this case, please contact me via email/facebook above or compile it yourself</span>
**For Windows with 32 bit MinGW**
- Clone the project
```
git clone https://github.com/dangtiendung1201/Cataurant.git
```
- Create a `Makefile` at **the same** folder with source code
```
OBJS = $(wildcard *.cpp)
OBJ_NAME = cataurant.exe
RESOURCES_SCRIPT = cataurant.rc
RESOURCES_FILE = cataurant.res
COMPILER_FLAGS = -std=c++17 -static-libgcc -static-libstdc++
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
INCLUDE_DIR = -Iinclude/32bit
LIB_DIR = -Llib/32bit

compile:
	windres $(RESOURCES_SCRIPT) -O coff -o $(RESOURCES_FILE)
	g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(RESOURCES_FILE)
```
- Compile by `Makefile`
```
make
```
**For Windows with 64 bit MinGW**
- Clone the project
```
git clone https://github.com/dangtiendung1201/Cataurant.git
```
- Create a `Makefile` at **the same** folder with source code
```
OBJS = $(wildcard *.cpp)
OBJ_NAME = cataurant.exe
RESOURCES_SCRIPT = cataurant.rc
RESOURCES_FILE = cataurant.res
COMPILER_FLAGS = -std=c++17 -static-libgcc -static-libstdc++
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
INCLUDE_DIR = -Iinclude/64bit
LIB_DIR = -Llib/64bit

compile:
	windres $(RESOURCES_SCRIPT) -O coff -o $(RESOURCES_FILE)
	g++ $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(RESOURCES_FILE)
```
- Compile by `Makefile`
```
make
```
**For MacOS**
- Clone the project
```
git clone https://github.com/dangtiendung1201/Cataurant.git
```
- Install dependencies
```
brew install sdl2
brew install sdl2_image
brew install sdl2_ttf
brew install sdl2_mixer
```
- Create a `Makefile` at **the same** folder with source code
```
OBJS = $(wildcard *.cpp)
OBJ_NAME = cataurant.exe
COMPILER_FLAGS = -std=c++17
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

compile:
	g++ $(COMPILER_FLAGS) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)
```
- Compile by `Makefile`
```
make
```
**For Ubuntu**
```
git clone https://github.com/dangtiendung1201/Cataurant.git
```
- Install dependencies
```
sudo apt-get update
sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev
sudo apt install libsdl2-ttf-dev
sudo apt install libsdl2-mixer-dev
```
- Create a `Makefile` at **the same** folder with source code
```
OBJS = $(wildcard *.cpp)
OBJ_NAME = cataurant.exe
COMPILER_FLAGS = -std=c++17 -static-libgcc -static-libstdc++
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

compile:
	g++ $(COMPILER_FLAGS) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)
```
- Compile by `Makefile`
```
make
```
## Run
After building the project successfully, please run it.
```
.\cataurant
```

## Gameplay

## Controls

## Credits

## Notes
- Diagram: [Link](/null)
- Technical notes: [Link](/null)

## References

[^fn1]: Assembling a cake to match a given cake specification.
[^fn2]: Please use `sudo apt` in Ubuntu or `brew` in MacOS to install packages.