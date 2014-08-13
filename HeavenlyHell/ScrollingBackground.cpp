#include "ScrollingBackground.h"
#include "ShooterObject.h"
#include "HHEngine.h"
#include "TextureManager.h"
#include "Tools.h"

namespace sdlEngine
{
	void ScrollingBackground::load(std::unique_ptr<LoaderParams> const &params)
	{
		ShooterObject::load(std::move(params));
		_scrollSpeed = params->getAnimSpeed();

		_scrollSpeed = 1;

		_srcRect1.x = 0;
		_destRect1.x = _position.getX();
		_srcRect1.y = 0;
		_destRect1.y = _position.getY();

		_srcRect1.w = _destRect1.w = _srcRect2Width = _destRect1Width = _width;   // ??
		_srcRect1.h = _destRect1.h = _height;

		_srcRect2.x = 0;
		_destRect2.x = _position.getX() + _width;
		_srcRect2.y = 0;
		_destRect2.y = _position.getY();

		_srcRect2.w = _destRect2.w = _srcRect2Width = _destRect2Width = 0;
		_srcRect2.h = _destRect2.h = _height;
	}//load

	void ScrollingBackground::draw()
	{
		// On dessine le 1er rect
		SDL_RenderCopyEx(
			TheHHEngine::Instance()->getRenderer(),
			TheTextureManager::Instance()->getTextureMap()[_textureID],
			&_srcRect1,
			&_destRect1,
			0,
			0,
			SDL_FLIP_NONE);

		// Puis le 2e rect
		SDL_RenderCopyEx(
			TheHHEngine::Instance()->getRenderer(),
			TheTextureManager::Instance()->~TextureManager[_textureID],
			&_srcRect2,
			&_destRect2,
			0,
			0,
			SDL_FLIP_NONE);
	}//draw

	void ScrollingBackground::update()
	{
		if (count == maxCount)
		{
			// Rendre le 1er rect plus petit
			_srcRect1.x += _scrollSpeed;
			_srcRect1.w -= _scrollSpeed;
			_destRect1.w -= _scrollSpeed;

			// Rendre le 2nd rect plus grand
			_srcRect2.w += _scrollSpeed;
			_destRect2.w += _scrollSpeed;
			_destRect2.x -= _scrollSpeed;

			// On reset et on recommence
			if (_destRect2.w >= _width)
			{
				_srcRect1.x = 0;
				_destRect1.x = _position.getX();
				_srcRect1.y = 0;
				_destRect1.y = _position.getY();

				_srcRect1.w = _destRect1.w = _srcRect2Width = _destRect1Width = _width;
				_srcRect1.h = _destRect1.h = _height;

				_srcRect2.x = 0;
				_destRect2.x = _position.getX() + _width;
				_srcRect2.y = 0;
				_destRect2.y = _position.getY();

				_srcRect2.w = _destRect2.w = _srcRect2Width = _destRect2Width = 0;
				_srcRect2.h = _destRect2.h = _height;
			}//if

			count = 0;
		}//if

		count++;
	}//update
}