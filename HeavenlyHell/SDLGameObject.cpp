#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "HHEngine.h"

namespace sdlEngine
{
	SDLGameObject::SDLGameObject() :
		GameObject()
	{
	}//SDLGameObject
	//--------------------------------------------------------------------------

	void SDLGameObject::load(const LoaderParams* params)
	{
		_position = Vector2D((float)params->getX(), (float)params->getY());
		_velocity = Vector2D(0.0f, 0.0f);
		_acceleration = Vector2D(0.0f, 0.0f);
		
		_width = params->getWidth();
		_height = params->getHeight();
		_textureID = params->getTextureID();

		_currentRow = 1;
		_currentFrame = 1;

		_numFrames = params->getNumFrames();
	}//load
	//--------------------------------------------------------------------------

	void SDLGameObject::draw()
	{
		if (_velocity.getX() > 0)
		{
			TheTextureManager::Instance()->drawFrame(_textureID, (int)_position.getX(), (int)_position.getY(), _width, _height, _currentRow, _currentFrame, TheHHEngine::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
		}//if
		else
		{
			TheTextureManager::Instance()->drawFrame(_textureID, (int)_position.getX(), (int)_position.getY(), _width, _height, _currentRow, _currentFrame, TheHHEngine::Instance()->getRenderer());
		}//else
	}//draw
	//--------------------------------------------------------------------------

	void SDLGameObject::update()
	{
		_velocity += _acceleration;
		_position += _velocity;
	}//update
	//--------------------------------------------------------------------------
	
	void SDLGameObject::clean()
	{

	}//clean
}