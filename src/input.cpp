#include <SDL2/SDL.h>
#include "input.h"
#include "player.h"

// Start handling input
void Input::Start(bool &running, bool &start) const
{
  // Wait for a key to be pressed and then start the game.
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } 
    else if (e.type == SDL_KEYDOWN) {
      start = true;
    }
  }
}

// Handle inputs
void Input::Handle(bool &running, Player &user, Player &program) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } 
    else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_w:
          ChangeDirection(user, Player::Direction::kUp, Player::Direction::kDown);
          break;

        case SDLK_s:
          ChangeDirection(user, Player::Direction::kDown, Player::Direction::kUp);
          break;

        case SDLK_a:
          ChangeDirection(user, Player::Direction::kLeft, Player::Direction::kRight);
          break;

        case SDLK_d:
          ChangeDirection(user, Player::Direction::kRight, Player::Direction::kLeft);
          break;

        case SDLK_q:
          // Toggle between high and low speed
          user.speed == 0.1f ? user.speed = 0.2f : user.speed = 0.1f;
          break;

        case SDLK_e:
          // Activate and deactivate trail
          user.active_trail == false ? user.active_trail = true : user.active_trail = false;
          break;

        case SDLK_i:
          ChangeDirection(program, Player::Direction::kUp, Player::Direction::kDown);
          break;

        case SDLK_k:
          ChangeDirection(program, Player::Direction::kDown, Player::Direction::kUp);
          break;

        case SDLK_j:
          ChangeDirection(program, Player::Direction::kLeft, Player::Direction::kRight);
          break;

        case SDLK_l:
          ChangeDirection(program, Player::Direction::kRight, Player::Direction::kLeft);
          break;

        case SDLK_u:
          // Toggle between high and low speed
          program.speed == 0.1f ? program.speed = 0.2f : program.speed = 0.1f;
          break;

        case SDLK_o:
          // Activate and deactivate trail
          program.active_trail == false ? program.active_trail = true : program.active_trail = false;
          break;
      }
    }
  }
}

// TODO: Refactor to not rely on passing the opposite direction
// ChangeDirection of player
void Input::ChangeDirection(Player &player, Player::Direction input, Player::Direction opposite) const
{
  if (player.direction != opposite || player.size == 1) {
    player.direction = input;
	}
}
