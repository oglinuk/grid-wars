#include "game.h"
#include "player.h"

Player::Player(int g_width, int g_height, Player const &e, int color):
	grid_width(g_width),
	grid_height(g_height),
	enemy(e)
{
	if (color == Game::Blue) {
		// If it is a user, set coordinates to the left edge of the screen.
		bike_x = static_cast<float>(0);
		bike_y = static_cast<float>(grid_height / 2);
		direction = Direction::kRight;
	} else {
		// If it is a program, set coordinates to the right edge of the screen.
		bike_x = static_cast<float>(grid_width);
		bike_y = static_cast<float>(grid_height / 2);
		direction = Direction::kLeft;
	}
}

// Update players bike and trail
void Player::Update()
{
	// We first capture the head's cell before updating.
	SDL_Point prev_cell{
		static_cast<int>(bike_x),
		static_cast<int>(bike_y)
	};

	UpdateBike();

	// Capture the head's cell after updating.
	SDL_Point current_cell{
		static_cast<int>(bike_x),
		static_cast<int>(bike_y)
	};

	// Update all of the body vector items if the player head has moved to a new cell.
	if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
		UpdateTrail(current_cell, prev_cell);
	}
}

// UpdateBike direction
void Player::UpdateBike()
{
  switch (direction) {
    case Direction::kUp:
      bike_y -= speed;
      break;

    case Direction::kDown:
      bike_y += speed;
      break;

    case Direction::kLeft:
      bike_x -= speed;
      break;

    case Direction::kRight:
      bike_x += speed;
      break;
  }

  // Wrap the Player around to the beginning if going off of the screen
  bike_x = fmod(bike_x + grid_width, grid_width);
  bike_y = fmod(bike_y + grid_height, grid_height);
}

// UpdateTrail adds/erases trail depending on active_trail and checks if
// there has been a collision into a trail
void Player::UpdateTrail(SDL_Point &c_cell, SDL_Point &p_cell)
{
  if (active_trail == true) {
    // Add length to trail by adding previous head location to vector.
    trail.push_back(p_cell);
	} else {
    // When the trail is switched off, let it fade slowly.
    if (!trail.empty()) {
      trail.erase(trail.begin());
		}
  }

  //Check for collision with enemies trail
  for (auto const &t : enemy.trail) {
    if (c_cell.x == t.x && c_cell.y == t.y) {
      alive = false;
    }
  }

  // Check for collision with own trail
  for (auto const &t : trail) {
    if (c_cell.x == t.x && c_cell.y == t.y) {
      alive = false;
    }
  }
}
