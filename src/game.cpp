#include "game.h"
#include "SDL.h"

Game::Game(int g_width, int g_height):
	user(g_width, g_height, program, Game::Blue),
	program(g_width, g_height, user, Game::Orange){}

// Run the game
void Game::Run(Input const &input, Graphics &graphics, int target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true; // Will be set to false if we close the window
  bool start = false;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    if (start) {
      input.Handle(running, user, program);
      Tick();
    } else {
      // Wait for a button press before starting the game.
      input.Start(running, start);
    }

    // Fill screen with the winner's color or continue rendering the game.
    if (!user.alive && !program.alive) {
      graphics.Fill(Draw);
		} else if (user.alive && !program.alive) {
      graphics.Fill(Blue);
		} else if (!user.alive && program.alive) {
      graphics.Fill(Orange);
		} else {
			graphics.Render(user, program);
		}

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
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
