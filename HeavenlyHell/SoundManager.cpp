#include "SoundManager.h"

namespace sdlEngine
{
	SoundManager* SoundManager::_instance = NULL;

	//---------------------------------------------------------------------------

	SoundManager::SoundManager(void)
	{
		Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
	}//SoundManager
	//---------------------------------------------------------------------------

	SoundManager::~SoundManager(void)
	{
		Mix_CloseAudio();
	}//~SoundManager
	//---------------------------------------------------------------------------

	bool SoundManager::load(std::string fileName, std::string id, sound_type type)
	{
		if (type == SOUND_MUSIC)
		{
			Mix_Music* music = Mix_LoadMUS(fileName.c_str());
			if (NULL == music)
			{
				std::cout << "### Could not load MUSIC: " << Mix_GetError() << std::endl;
				return false;	// !!! !!! !!!
			}//if

			_music[id] = music;
			return true;
		}//if
		else if (type == SOUND_FX)
		{
			Mix_Chunk* chunk = Mix_LoadWAV(fileName.c_str());
			if (NULL == chunk)
			{
				std::cout << "### Could not load SFX: " << Mix_GetError() << std::endl;
				return false;	// !!! !!! !!!
			}//if

			_sfxs[id] = chunk;
			return true;
		}//else if

		return false;
	}//load
	//---------------------------------------------------------------------------

	void SoundManager::playMusic(std::string id, int loop)
	{
		Mix_PlayMusic(_music[id], loop);
	}//playMusic
	//---------------------------------------------------------------------------

	void SoundManager::playSound(std::string id, int loop)
	{
		Mix_PlayChannel(-1, _sfxs[id], loop);
	}//playSound
}