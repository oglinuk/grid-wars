#include "game.h"
#include "player.h"

Player::Player(int g_width, int g_height, Player const &e, int color):
	grid_width(g_width),
	grid_height(g_height),
	enemy(e)
{
	// Set starting position to a random x,y coordinate and direction
	bike_x = static_cast<float>(rand())/(static_cast<float>(RAND_MAX/grid_width));
	bike_y = static_cast<float>(rand())/(static_cast<float>(RAND_MAX/grid_height));
	direction = static_cast<Direction>(rand() % 4);
}

// Update players bike and trail
void Player::Update()
{
	// We first capture the bikes cell before updating
	SDL_Point prev_cell{
		static_cast<int>(bike_x),
		static_cast<int>(bike_y)
	};

	UpdateBike();

	// Capture the bikes cell after updating
	SDL_Point current_cell{
		static_cast<int>(bike_x),
		static_cast<int>(bike_y)
	};

	// Capture the (enemy) bikes current cell
	SDL_Point current_e_cell{
		static_cast<int>(enemy.bike_x),
		static_cast<int>(enemy.bike_y),
	};

	// Check for collision with enemies bike
	if (current_cell.x == current_e_cell.x && current_cell.y == current_e_cell.y) {
		alive = false;
	}

  //Check for collision with enemies trail
	for (auto const &t : enemy.trail) {
		if (current_cell.x == t.x && current_cell.y == t.y) {
			alive = false;
		}
	}

	// Check for collision with own trail
	for (auto const &t : trail) {
		if (current_cell.x == t.x && current_cell.y == t.y) {
			alive = false;
		}
	}

	// Update all of the trail vector items if the player bike has moved to a new cell
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

	// Wrap the player around to the beginning if going off of the screen
	bike_x = fmod(bike_x + grid_width, grid_width);
	bike_y = fmod(bike_y + grid_height, grid_height);
}

// Reset player
void Player::Reset()
{
	this->active_trail = false;
	this->alive = true;
	this->bike_x = static_cast<float>(rand())/(static_cast<float>(RAND_MAX/grid_width));
	this->bike_y = static_cast<float>(rand())/(static_cast<float>(RAND_MAX/grid_height));
	this->trail.clear();
	this->direction = randomDirection();
	this->speed = 0.1f;
}

// UpdateTrail adds/erases trail depending on active_trail
void Player::UpdateTrail(SDL_Point &c_cell, SDL_Point &p_cell)
{
	if (active_trail == true) {
		// Add length to trail by adding previous bike location to trail
		trail.push_back(p_cell);
		size++; // Increase size of player
		return;
	}

	// When the trail is switched off, let it fade slowly.
	if (!trail.empty()) {
		trail.erase(trail.begin());
		size--;
	}
}

// randomDirection returns a random Direction
Player::Direction Player::randomDirection()
{
	int l = static_cast<int>(Direction::last);
	return static_cast<Direction>(rand() % l);
}
