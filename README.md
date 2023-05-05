<h1 align="center">🐈Cataurant🐈</h1>

[![Actions Status](https://github.com/dangtiendung1201/Cataurant/workflows/MacOS/badge.svg)](https://github.com/dangtiendung1201/Cataurant/actions)
[![Actions Status](https://github.com/dangtiendung1201/Cataurant/workflows/Windows/badge.svg)](https://github.com/dangtiendung1201/Cataurant/actions)
[![Actions Status](https://github.com/dangtiendung1201/Cataurant/workflows/Ubuntu/badge.svg)](https://github.com/dangtiendung1201/Cataurant/actions)

This is my own game project using `C`, `C++` and `SDL2 libraries` at University of Engineering and Technology, Vietnam National University.

# Table of Contents

- [Information](https://github.com/dangtiendung1201/Cataurant#information)
- [Idea](https://github.com/dangtiendung1201/Cataurant#idea)
- [Milestone](https://github.com/dangtiendung1201/Cataurant#milestone)
- [Prerequisites](https://github.com/dangtiendung1201/Cataurant#prerequisites)
- [Build](https://github.com/dangtiendung1201/Cataurant#bulid)
- [Gameplay](https://github.com/dangtiendung1201/Cataurant#gameplay)
- [Credits](https://github.com/dangtiendung1201/Cataurant#credits)
- [Notes](https://github.com/dangtiendung1201/Cataurant#notes)

## Information

**Name:**  Đặng Tiến Dũng <br />
**Student ID:** 22026523 <br />
**Class:** K67J <br />
**Email:** dangtiendung1201@gmail.com <br />
**Facebook:** fb.com/dangtiendung1201 <br />

## Idea

From mini-game called Comfy Cakes in Purple Place ([Info](https://en.wikipedia.org/wiki/Purble_Place "Infomation about the game"), [Demo](https://www.youtube.com/watch?v=TRxOvRQpPmg&pp=ygUXcHVyYmxlIHBsYWNlIHdpbmRvd3MgNyA%3D "Demo video")) included with Windows 7 operating systems, I create a new game with the same logic[^fn1]. Instead of a "conveyor belt" in the original game, I use a "deque" to manage "burger ingredients". "Requests" are shown as "customers", ... and many changes. Threfore, my game is just about 10% similar to the original game.

I chose this game because I want to challenge myself with a new game that requires a lot of thinking in design and implement. I also want to create a game that is not too simple and not too complicated, so that I can play it in my free time.

## Milestone

- [x] **08/03/2023:** Have ideas about the game.
- [x] **12/03/2023:** Initialize all SDL libraries + Implement and refactor some SDL utilities.
- [x] **14/03/2023:** Finish game menu.
- [x] **15/03/2023:** Add some features in menu.
- [x] **16/03/2023:** Show game background.
- [x] **17/03/2023:** Make first game character move.
- [x] **22/03/2023:** Make more game characters.
- [x] **25/03/2023:** Render more characters.
- [x] **06/04/2023:** Implement burger ingredients.
- [x] **06/04/2023:** Implement burger ingredients.
- [x] **08/04/2023:** Release [1.0 version](https://github.com/dangtiendung1201/Cataurant/releases/tag/v1.0).
- [x] **17/04/2023:** Realease [1.1 version](https://github.com/dangtiendung1201/Cataurant/releases/tag/v1.1).
- [x] **02/05/2023:** Release [1.2 version](https://github.com/dangtiendung1201/Cataurant/releases/tag/v1.2).

- [ ] **Ongoing:** Add Japanese, Russian and Vietnamse language using Unicode.
- [ ] **Future:** Play via LAN using SDL2_net library.
- [ ] **Future:** Using my own assets and change the LICENSE.
- [ ] **Future:** Using Emscripten to play game in browser.

## Prerequisites

All dependencies **(for Windows only)**[^fn2] are in [bin](https://github.com/dangtiendung1201/Cataurant/tree/main/bin), [include](https://github.com/dangtiendung1201/Cataurant/tree/main/include), [lib](https://github.com/dangtiendung1201/Cataurant/tree/main/lib) folders.
- `C`, `C++`
- `SDL2`, `SDL2 image`, `SDL2 mixer`, `SDL2 ttf`

## Build

$\color{red}{\textrm{Note: Because of the differences in coding environments, Makefile provided below could not work.}}$
$\color{red}{\textrm{In this case, please contact me via email/facebook above or compile it yourself}}$

**For Windows with 32 bit MinGW and equivalent**

- Clone the project
```
git clone https://github.com/dangtiendung1201/Cataurant.git
```
- Create a `Makefile` at the root directory
```
OBJS = $(wildcard src/*.cpp)
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

**For Windows with 64 bit MinGW and equivalent**

- Clone the project
```
git clone https://github.com/dangtiendung1201/Cataurant.git
```
- Create a `Makefile` at the root directory
```
OBJS = $(wildcard src/*.cpp)
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
- Create a `Makefile` at the root directory
```
OBJS = $(wildcard src/*.cpp)
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

**For Ubuntu and equivalent**

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
- Create a `Makefile` at the root directory
```
OBJS = $(wildcard src/*.cpp)
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

$\color{red}{\textrm{Note: For Windows only, please add bin to Environment variable}}$

After building the project successfully, please run it.
```
.\cataurant
```

## Gameplay

### Objective

Your objective in this game is to serve your customers as quickly as possible, while also feeding hungry cat (bottom-left corner) if you want. You have 3 lives, so try to serve as many customers as possible without making mistakes.

### Ingredients

There are 4 types of ingredients in the game: `Bread`, `Meat`, `Tomato`, `Lettuce`.

### Seller

You are the seller (Doraemon) who will serve the customers. You can move left and right to serve customers. You can also control the deque of ingredients by using up and down arrow keys.

### Customers

At the start of the game, customers will begin to appear at your stall with their requests. Each customer has a patience bar, which will decrease if you take too long to serve them. If a customer's patience bar runs out, they will leave and you will lose a life.

### Hungry Cat

Hungry cat will appear at the bottom-left corner of the screen. You can feed him if you want. He may give you some bonuses randomly (play the game to find out them) after being feed.

### Score

You will get score for each customer you serve. You will also get score for each customer you feed. The score will be displayed at the top-left corner of the screen.

### Lives

Lives will be displayed at the top-right corner of the screen. You will lose when you run out of lives.

### Controls

- `Left, Right arrow keys` to move the seller (Doraemon).
- `Up, Down arrow keys` to control the deque of ingredients.

### Screenshots

![Menu](https://user-images.githubusercontent.com/53939861/233418209-0ea2ed19-3e01-41aa-a4ef-b212aeefd884.jpg)
![Game](https://user-images.githubusercontent.com/53939861/233418243-7105a9cf-bb7d-4623-9ab3-20fc718566e4.jpg)
![Lose](https://user-images.githubusercontent.com/53939861/233418229-65c780b6-2514-418a-a2b0-6c8caba91d67.jpg)

### Demo

[Link](https://youtu.be/njkZdedeFJk "Youtube video").

## Credits

Special thanks to:
- All teachers in course `INT2215 1 - Advanced Programming` for their enthusiasm and knowledge.
- All my former Informatics teachers in `Thai Binh Gifted High School` and `Thai Binh National Olympiad in Informatics Team` for my knowledge in data structures and algorithms.
- [Lazy Foo' Productions](https://lazyfoo.net/tutorials/SDL/index.php) for their tutorials on SDL2.
- [SDL2](https://www.libsdl.org/) for their library.
- GitHub for powerful coding tools.

In this game, I used:
- [Menu background](https://www.freepik.com/free-vector/cat-lover-pattern-background-design_15080931.htm)
- [Customers' Texture](https://itch.io/c/1662943/cats-and-dogs).
- [Music](https://www.youtube.com/audiolibrary)
- [Sound effects](https://github.com/narakeet/examples)
- [Font Meows](https://www.dafont.com/meows.font)
- [Font Lovely kids](https://www.dafont.com/lovely-kids.font)

- [Hack MD](https://hackmd.io/) for writing this document and technical notes.
- [Canva](https://www.canva.com/) for creating images.
- [Draw.io](https://www.draw.io/) for creating diagrams.

## Notes

- Technical notes: [Link](https://hackmd.io/@uEzrlWylRnqO8b3pM_Yr2w/rkXPog6X2)

[^fn1]: Assembling a cake to match a given cake specification.
[^fn2]: Please use `sudo apt` in Ubuntu or `brew` in MacOS to install packages.
