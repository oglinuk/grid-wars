#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "graphics.h"
#include "input.h"
#include "player.h"

class Game {
	public:
		enum Type { Draw, Blue, Orange };

		Game(int g_width, int g_height);
		void Run(Input const &input, Graphics &graphics, int target_frame_duration);

 private:
  Player user;
  Player program;

  void Tick();
};

#endif
