#include "audio.h"

Audio::Audio(){}
Audio::~Audio(){}

// Play path using loops
void Audio::Play(std::string path, int loops)
{
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		printf("SDL_Init failed: %s\n", Mix_GetError());
	}

	// Initialize SDL mixer
	// TODO: Replace with https://wiki.libsdl.org/SDL_OpenAudioDevice
	// 							frequency, format, channels, chunksize
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
		printf("Mix_OpenAudio failed: %s\n", Mix_GetError());
	}

	// Load the music
	this->music = Mix_LoadMUS(path.c_str());
	if (this->music == NULL) {
		printf("Music is NULL: %s\n", Mix_GetError());
	}

	// Play the music
	if (Mix_PlayMusic(music, loops) == -1) {
		printf("Mix_PlayMusic failed: %s\n", Mix_GetError());
	}
}
