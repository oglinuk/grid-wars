#include <iostream>
#include "audio.h"
#include "game.h"
#include "graphics.h"
#include "input.h"
#include "unistd.h"

int main(int argc, char *argv[])
{
  constexpr std::size_t kFramesPerSecond{120};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  int s_width{1274};
  int s_height{720};
  // Change grid size for a different "feel"
  int g_width{97};
  int g_height{54};

  // Initialize graphics object that creates a window
  Graphics graphics(s_width, s_height, g_width, g_height);
  Input input;
  Game game(g_width, g_height);

	Audio::Play();

  // The main game loop
  game.Run(input, graphics, kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  
  return 0;
}
