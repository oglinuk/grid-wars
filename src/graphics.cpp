#include <iostream>
#include "game.h"
#include "graphics.h"

// Graphics constructor
Graphics::Graphics(int s_width, int s_height, int g_width, int g_height):
	screen_width(s_width),
	screen_height(s_height),
	grid_width(g_width),
	grid_height(g_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL_Init failed: %s ...\n", SDL_GetError());
  }

  // Create window
  this->window = SDL_CreateWindow("Player Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);
  if (this->window == NULL) {
		printf("Window is NULL: %s ...\n", SDL_GetError());
  }

  // Create renderer
  this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (this->renderer == NULL) {
		printf("Renderer is NULL: %s ...\n", SDL_GetError());
  }

	this->font_path = "./fonts/xolonium.ttf";
}

// Graphics deconstructor
Graphics::~Graphics()
{
  SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_CloseFont(font);
  SDL_Quit();
}

// Render the graphics to the window
void Graphics::Render(Player const &user, Player const &program)
{
  SDL_Rect cell;
  cell.w = screen_width / grid_width;
  cell.h = screen_height / grid_height;

  SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
	Clear();

  // Render user's trail
  SDL_SetRenderDrawColor(renderer, 0x26, 0xB4, 0xCA, 0xFF);
  for (SDL_Point const &point : user.trail) {
    cell.x = point.x * cell.w;
    cell.y = point.y * cell.h;
    SDL_RenderFillRect(renderer, &cell);
  }

  // Render program's trail
  // Different color for better head visibility
  SDL_SetRenderDrawColor(renderer, 0xDF, 0x74, 0x0C, 0x99);
  for (SDL_Point const &point : program.trail) {
    cell.x = point.x * cell.w;
    cell.y = point.y * cell.h;
    SDL_RenderFillRect(renderer, &cell);
  }
  
  // Render user's bike
  cell.x = static_cast<int>(user.bike_x) * cell.w;
  cell.y = static_cast<int>(user.bike_y) * cell.h;
  SDL_SetRenderDrawColor(renderer, 0x00, 0xEA, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &cell);

  // Render program's bike
  cell.x = static_cast<int>(program.bike_x) * cell.w;
  cell.y = static_cast<int>(program.bike_y) * cell.h;
  SDL_SetRenderDrawColor(renderer, 0xF7, 0x9D, 0x1E, 0xFF);
  SDL_RenderFillRect(renderer, &cell);

	Display();
}

// RenderText to window
void Graphics::RenderText(std::string msg)
{
	TTF_Init();

	font = TTF_OpenFont(font_path.c_str(), 50);
	if (font == NULL) {
		printf("Failed to open font %s ...\n", font_path.c_str());
		exit(1);
	}

	SDL_Color color = { 255, 255, 255 };
	SDL_Surface *surface = TTF_RenderText_Solid(font, msg.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	int w = 0;
	int h = 0;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	SDL_Rect rect = { screen_width/2, screen_height/2, w, h };

	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

// Print name and FPS counter to window title
void Graphics::UpdateWindowTitle(int fps) {
  std::string title{"Grid Wars: " + std::to_string(fps) + " FPS"};
  SDL_SetWindowTitle(window, title.c_str());
}

// Fill screen with the winner's color (white in case of a draw)
void Graphics::Fill(int winner) {
	std::string msg = "";

	switch (winner) {
		case Game::Draw:
			msg = "Draw!";
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			break;
		case Game::Blue:
			msg = "User wins!";
			SDL_SetRenderDrawColor(renderer, 0x00, 0xEA, 0xFF, 0xFF);
			break;
		case Game::Orange:
			msg = "Program wins!";
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x67, 0x00, 0xFF);
			break;
	}

	Clear();
	RenderText(msg);
	Display();
}

void Graphics::Clear()
{
	SDL_RenderClear(this->renderer);
}

void Graphics::Display()
{
  SDL_RenderPresent(this->renderer);
}
