#include "game.h"
#include "graphics.h"
#include "input.h"

int main(int argc, char *argv[])
{
  constexpr std::size_t kFramesPerSecond{120};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

  int s_width{1274};
  int s_height{720};
  int g_width{97};
  int g_height{54};

	// Set current time as seed for rng
	srand (static_cast<unsigned>(time(NULL)));

  Graphics graphics(s_width, s_height, g_width, g_height);
  Input input;
  Game game(g_width, g_height, input, graphics);

  game.Run(kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  
  return 0;
}
