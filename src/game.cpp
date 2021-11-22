#include <chrono>
#include <iostream>
#include <SDL2/SDL.h>
#include <thread>
#include <vector>
#include "audio.h"
#include "game.h"

Game::Game(int g_width, int g_height, Input &i, Graphics &g):
	user(g_width, g_height, program, Game::Blue),
	program(g_width, g_height, user, Game::Orange),
	input(i),
	graphics(g){}

// Run the game
void Game::Run(int target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true; // Will be set to false if we close the window
  bool start = false;

	// Countdown before game starts
	std::string intros_path = "../audio/clips/";
	intros_path.append(intros[rand() % intros.size()]);
	
	Audio::Play(intros_path, 0);
	graphics.Render(user, program);
	for (int i = 6; i > 0 ; i--) {
		std::cout << "Games begin in " << i << " ...\n" << std::flush;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	// Start random background music
	std::string music_path = "../audio/music/";
	music_path.append(songs[rand() % songs.size()]);
	printf("Now playing %s ...\n", music_path.c_str());

	// TODO: Create Audio::Queue and use
	// https://wiki.libsdl.org/SDL_QueueAudio
	Audio::Play(music_path, -1);
  input.Start(running, start);

  // Main game loop
  while (running) {
    frame_start = SDL_GetTicks();

    input.Handle(running, user, program);

    Tick();
    if (!user.alive || !program.alive) {
			WinnerScreen();
			std::this_thread::sleep_for(std::chrono::seconds(4));
		}

		graphics.Render(user, program);

    frame_end = SDL_GetTicks();

    // Track of how long each loop through the input/update/render cycle takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      graphics.UpdateWindowTitle(frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

// Tick updates user and program if theyre both alive
void Game::Tick()
{
  // Do not update position if someone is not alive.
  if (!user.alive || !program.alive) {
    return;
	}

  user.Update();
  program.Update();
}

// WinnerScreen
void Game::WinnerScreen()
{
	if (user.alive && !program.alive) {
		graphics.Fill(Blue);
	} else if (!user.alive && program.alive) {
		graphics.Fill(Orange);
	} else {
		graphics.Fill(Draw);
	}

	Reset();
}

// Reset all attributes of each player
void Game::Reset()
{
  user.active_trail = false;
  user.alive = true;
  user.bike_x = 0.0;
  user.bike_y = static_cast<float>(user.getGridHeight() / 2);
  user.trail.clear();
  user.direction = Player::Direction::kRight;
  user.speed = 0.1f;

  program.active_trail = false;
  program.alive = true;
  program.bike_x = static_cast<float>(program.getGridWidth());
  program.bike_y = static_cast<float>(program.getGridHeight() / 2);
  program.trail.clear();
  program.direction = Player::Direction::kLeft;
  program.speed = 0.1f;
}
