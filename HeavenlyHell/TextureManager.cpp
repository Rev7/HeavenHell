#include "TextureManager.h"

using namespace tools;

namespace textureManager
{
	TextureManager* TextureManager::instance = NULL;

	//---------------------------------------------------------------------------

	bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer)
	{
		/// \todo AJouter plugin SDL_Image
		SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
		if (NULL == tempSurface) 
		{
			std::cout << "### image load fail\n";
			Tools::logSDLError(std::cout, "IMG_Load");
			return false;  // !!! !!! !!!
		}//if

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);		
		if (NULL == texture)
		{
			std::cout << "### create texture from surface fail\n";
			Tools::logSDLError(std::cout, "SDL_CreateTextureFromSurface");
			SDL_FreeSurface(tempSurface);
			return false;  // !!! !!! !!!
		}//if
		SDL_FreeSurface(tempSurface);

		// Ajout de la texture à la map 
		textureMap[id] = texture;

		return true;

	}//load
	//---------------------------------------------------------------------------
	
	void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
	{
		SDL_Rect srcRect;
		SDL_Rect destRect;

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;
		destRect.x = x;
		destRect.y = y;

		if (SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip) != 0)
		{
			Tools::logSDLError(std::cout, "SDL_RenderCopyEx");
		}//if
	}//draw
	//---------------------------------------------------------------------------
	
	void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip)
	{
		SDL_Rect srcRect;
		SDL_Rect destRect;

		srcRect.x = width * currentFrame;
		srcRect.y = height * (currentRow - 1);
		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;
		destRect.x = x;
		destRect.y = y;

		if (SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip) != 0)
		{
			Tools::logSDLError(std::cout, "SDL_RenderCopyEx");
		}//if
	}//drawFrame
}