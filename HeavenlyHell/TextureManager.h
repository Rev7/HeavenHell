#pragma once

#include "Tools.h"
#include <map>

namespace sdlEngine
{
	class TextureManager
	{
	public:
		static TextureManager* Instance()
		{
			if (NULL == _instance)
			{
				_instance = new TextureManager();
			}//if

			return _instance;
		}//Instance

		bool load(std::string fileName, std::string id, SDL_Renderer* renderer); 
		void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, double angle, int alpha, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer);
		void clearFromTextureMap(std::string id);

	private:
		TextureManager(void) {}
		~TextureManager(void) {}

		std::map<std::string, SDL_Texture*> _textureMap;
		static TextureManager* _instance;
	};

	typedef TextureManager TheTextureManager;
}


