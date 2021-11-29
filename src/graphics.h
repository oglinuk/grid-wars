#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "player.h"

class Graphics {
	public:
		Graphics(int s_width, int s_height, int g_width, int g_height);
		~Graphics();

		void Render(Player const &user, Player const &program);
		void RenderText(std::string msg);
		void UpdateWindowTitle(int fps);
		void Fill(int winner);
		void Clear();
		void Display();
		int getGridWidth() { return grid_width; };
		int getGridHeight() { return grid_height; };

	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		TTF_Font *font;
		std::string font_path;

		int screen_width;
		int screen_height;
		int grid_width;
		int grid_height;
};

#endif
