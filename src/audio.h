#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Audio {
	public:
		Audio();
		~Audio();
		void Play(std::string path, int loops);

	private:
		Mix_Music *music;
};

#endif
