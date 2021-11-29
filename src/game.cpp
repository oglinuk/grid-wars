#include <chrono>
#include <SDL2/SDL.h>
#include <thread>
#include "audio.h"
#include "game.h"

Game::Game(int g_width, int g_height, Input &i, Graphics &g):
	user(g_width, g_height, program, Game::Blue),
	program(g_width, g_height, user, Game::Orange),
	input(i),
	graphics(g)
{
	this->intros = {"fintro.ogg", "mintro.ogg"};
	this->songs = {
		"salt-mines.ogg",
		"frontier.ogg",
		"disconscient.ogg",
		"ftl.ogg"
	};
}

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
	Audio audio;

	// Set random intro
	std::string intros_path = "./audio/clips/";
	intros_path.append(intros[rand() % intros.size()]);
	
	// Countdown before game starts
	audio.Play(intros_path, 0);
	graphics.Render(user, program);
	for (int i = 6; i > 0 ; i--) {
		printf("Game begins in %d ...\n", i);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	// Start random background music
	std::string music_path = "./audio/music/";
	music_path.append(songs[rand() % songs.size()]);
	printf("Now playing %s ...\n", music_path.c_str());

	// TODO: Create Audio::Queue and use
	audio.Play(music_path, -1);

  // Main game loop
  while (running) {
    frame_start = SDL_GetTicks();

    input.Handle(running, user, program);

    Tick();

		graphics.Render(user, program);

    if (!user.alive || !program.alive) {
			WinnerScreen();
			std::this_thread::sleep_for(std::chrono::seconds(4));
		}

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

// Reset players
void Game::Reset()
{
	user.Reset();
	program.Reset();
}
