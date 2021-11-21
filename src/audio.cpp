#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "audio.h"

void Audio::Play()
{
	SDL_Init(SDL_INIT_AUDIO);

	// Initialize SDL mixer
	// TODO: Replace with https://wiki.libsdl.org/SDL_OpenAudioDevice
	// 							frequency, format, channels, chunksize
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
		printf("Unable to open audio device: %s\n", Mix_GetError());
	}

	// Load the music
	// https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_55.html
	Mix_Music *music = Mix_LoadMUS("../music/salt-mines.ogg");
	if (music == NULL) {
		printf("Unable to load music file: %s\n", Mix_GetError());
	}

	// Play the music
	// https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_57.html
	if (Mix_PlayMusic(music, -1) == -1) {
		printf("Unable to play music file: %s\n", Mix_GetError());
	}
}
