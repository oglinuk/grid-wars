#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "graphics.h"
#include "input.h"
#include "player.h"

class Game {
	public:
		enum Type { Draw, Blue, Orange };

		Game(int g_width, int g_height, Input &i, Graphics &g);
		void Run(int target_frame_duration);

	private:
		Player user;
		Player program;
		Graphics graphics;
		Input input;
		std::vector<std::string> intros{"fintro.ogg", "mintro.ogg"};
		std::vector<std::string> songs{
			"salt-mines.ogg",
			"frontier.ogg",
			"disconscient.ogg",
			"ftl.ogg"
		};

		void Tick();
		void WinnerScreen();
		void Reset();
};

#endif
