#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "game.h"
#include "player.h"
#include "SDL.h"

class Graphics {
 public:
  Graphics(int s_width, int s_height, int g_width, int g_height);
  ~Graphics();

  void Render(Player const &user, Player const &program);
  void Fill(int winner);
  void UpdateWindowTitle(int fps);

 private:
  SDL_Window *window;
  SDL_Renderer *renderer;

  int screen_width;
  int screen_height;
  int grid_width;
  int grid_height;
};

#endif
