# Grid Wars

Hello user,

welcome to the Grid. 

<img src="tron.gif"/>

The programs have noticed your arrival. That is why you will have to
prove yourself in the arena. It is only you, your Light Cycle and the
enemy.

Your light cycle is powered by pure liquid energy, it has two gears and
the light ribbons it produces can be toggled on or off at any time. Let
your enemy ride into them and you will win the game.

If you can overcome this challenge, the grid will light up in your color.

## Controls

### User

* Movement: `WASD`
* Light Ribbon: `E`
* Shift Gear: `Q`

### Program

* Movement: `IJKL`
* Light Ribbon: `O`
* Shift Gear: `U`

---

## Getting Started

### Dependencies

* `cmake`
* `make`
* `libsdl2-dev`
* `libsdl2-mixer-dev`

### Building for Linux

1. `mkdir build && cd build`
2. `cmake .. && make`
3. `./grid-wars`

## Program Structure

* Input: A class that handles all input events
* Game: Contains the main game loop (Input, Update, Render) and keeps track of the frame rate. It has two instances of the player class as attributes.
* Player: Handles the logic (position, movement and collision detection)
* Graphics: Handles all things graphics (window and renderer)
* Audio: Handles the music

## TODO

* [X] Add music
	* [ ] Add multiple songs and play at random
* [ ] Add a countdown at the start
* [ ] Change grid size to scale with resolution of window
* [ ] Add ai option

## Attribution

* "[TRON-CPP](https://github.com/eilerstim/TRON-CPP)" by [eilerstim](https://github.com/eilerstim) is licensed under [CC 4.0](https://creativecommons.org/licenses/by/4.0/) - foundation for game
* "[Salt Mines](https://soundcloud.com/argofox/meizong-salt-mines)" by [Argofox](https://soundcloud.com/argofox) is licensed under [CC 3.0](https://creativecommons.org/licenses/by/3.0/) - music
