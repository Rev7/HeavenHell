#pragma once

#include "Tools.h"
#include "SDL2\SDL_mixer.h"
#include <map>

namespace sdlEngine
{
	enum sound_type
	{
		SOUND_MUSIC = 0,
		SOUND_FX = 1
	};

	class SoundManager
	{
	public:
		static SoundManager* Instance()
		{
			if (NULL == _instance)
			{
				_instance = new SoundManager();
			}//if

			return _instance;
		}//Instance

		bool load(std::string fileName, std::string id, sound_type type);

		void playSound(std::string id, int loop);
		void playMusic(std::string id, int loop);

	private:
		static SoundManager* _instance;

		std::map<std::string, Mix_Chunk*> _sfxs;
		std::map<std::string, Mix_Music*> _music;

		SoundManager();
		~SoundManager();

		SoundManager(const SoundManager&);
		SoundManager &operator=(const SoundManager&);
	};

	typedef SoundManager TheSoundManager;
}