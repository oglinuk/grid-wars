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
* `SDL2`
* `SDL2_mixer`
* `SDL2_ttf`

### Building for Linux

1. `mkdir build && cd build`
2. `cmake .. && make`
3. `./grid-wars`

## Program Structure

* Input: A class that handles all input events
* Game: Contains the main game loop (Input, Update, Render) and keeps track of the frame rate. It has two instances of the player class as attributes.
* Player: Handles the logic (position, movement and collision detection)
* Graphics: Handles all things graphics (window and renderer)
* Audio: Handles all things sound

## TODO

* [X] Add music
	* [X] Add multiple songs and play at random
* [X] Add a countdown at the start
* [ ] Change grid size to scale with resolution of window
* [ ] Add ai option

## Attribution

* "[TRON-CPP](https://github.com/eilerstim/TRON-CPP)" by [eilerstim](https://github.com/eilerstim) is licensed under [CC 4.0](https://creativecommons.org/licenses/by/4.0/) - foundation for game
* "[Salt Mines](https://soundcloud.com/dj-meizong/salt-mines)" by [Meizong](https://soundcloud.com/dj-meizong) is licensed under [CC 3.0](https://creativecommons.org/licenses/by/3.0/) - `music/salt-mines.ogg`
* "[Disconscient](https://soundcloud.com/gandjdnb/disconscient-full-version-drum-bass)" by [G&J](https://soundcloud.com/gandjdnb) is licensed under [CC 3.0](https://creativecommons.org/licenses/by/3.0/) - `music/disconscient.ogg`
* "[Frontier](https://soundcloud.com/argofox/doctor-vox-frontier)" by [Doctor Vox](https://open.spotify.com/artist/1NiqyCNYaJnuKVTMFlWYVx) is licensed under [CC 3.0](https://creativecommons.org/licenses/by/3.0/) - `music/frontier.ogg`
* "[Faster Than Light](https://soundcloud.com/extandnb/faster-than-light) by [Extan]( https://soundcloud.com/extandnb) is licensed under [CC 3.0](https://creativecommons.org/licenses/by/3.0/) - `music/ftl.ogg`

