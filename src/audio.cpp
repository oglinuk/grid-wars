#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "audio.h"

void Audio::Play()
{
	SDL_Init(SDL_INIT_AUDIO);

	// Initialize SDL mixer
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	// Load the music
	Mix_Music *music = Mix_LoadMUS("../music/salt-mines.mp3");

	// Play the music
	Mix_PlayMusic(music, -1);
}
