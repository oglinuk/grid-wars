#include <iostream>
#include "game.h"
#include "graphics.h"

Graphics::Graphics(int s_width, int s_height, int g_width, int g_height):
	screen_width(s_width),
	screen_height(s_height),
	grid_width(g_width),
	grid_height(g_height)
{
  // Initialize SDL
	// https://wiki.libsdl.org/SDL_Init
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create window
	//https://wiki.libsdl.org/SDL_CreateWindow?highlight=%28bCategoryAPIb%29%7C%28SDLFunctionTemplate%29
  window = SDL_CreateWindow("Player Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);
  // Check if it was able to open up
  if (nullptr == window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
	// https://wiki.libsdl.org/SDL_CreateRenderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

	// Set font_path
	font_path = "../fonts/xolonium.ttf";
}

Graphics::~Graphics()
{
	// https://wiki.libsdl.org/SDL_DestroyWindow
  SDL_DestroyWindow(window);
	// https://wiki.libsdl.org/SDL_DestroyRenderer
	SDL_DestroyRenderer(renderer);
	// https://www.libsdl.org/projects/SDL_ttf/docs/SDL_ttf_18.html
	TTF_CloseFont(font);
	// https://wiki.libsdl.org/SDL_Quit
  SDL_Quit();
}

// Render the graphics to the window
void Graphics::Render(Player const &user, Player const &program)
{
  SDL_Rect cell;
  cell.w = screen_width / grid_width;
  cell.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(renderer);

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

  // Update screen
  SDL_RenderPresent(renderer);
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
	SDL_RenderPresent(renderer);
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
			SDL_RenderClear(renderer);
			break;

		case Game::Blue:
			msg = "User wins!";
			SDL_SetRenderDrawColor(renderer, 0x00, 0xEA, 0xFF, 0xFF);
			SDL_RenderClear(renderer);
			break;

		case Game::Orange:
			msg = "Program wins!";
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x67, 0x00, 0xFF);
			SDL_RenderClear(renderer);
			break;
	}

	RenderText(msg);
  SDL_RenderPresent(renderer);
}
