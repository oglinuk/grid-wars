#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"

class Player {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Player const &enemy;
  Direction direction;
  bool active_trail{false};
  bool alive{true};
  int size{1};
  float speed{0.1f};
  float bike_x;
  float bike_y;
  std::vector<SDL_Point> trail;

  Player(int g_width, int g_height, Player const &e, int color);
  void Update();
  int getGridWidth() {return grid_width;};
  int getGridHeight() {return grid_height;};

 private:
  int grid_width;
  int grid_height;

  void UpdateBike();
  void UpdateTrail(SDL_Point &current_cell, SDL_Point &prev_cell);
};

#endif
