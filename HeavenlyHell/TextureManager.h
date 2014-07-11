#pragma once

#include "Tools.h"

namespace sdlEngine
{
	class TextureManager
	{
	private:
		std::map<std::string, SDL_Texture*> textureMap;
		static TextureManager* instance;

		TextureManager(void) {}
		~TextureManager(void) {}

	public:
		static TextureManager* Instance()
		{
			if (NULL == instance)
			{
				instance = new TextureManager();
			}//if

			return instance;
		}//Instance

		bool load(std::string fileName, std::string id, SDL_Renderer* renderer); 
		void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	};

	typedef TextureManager TheTextureManager;
}


