#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <vector>

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

 private:
  int grid_width;
  int grid_height;

  void UpdateBike();
  void UpdateTrail(SDL_Point &current_cell, SDL_Point &prev_cell);
};

#endif
