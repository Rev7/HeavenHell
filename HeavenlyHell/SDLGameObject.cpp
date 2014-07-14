#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "HHEngine.h"

namespace sdlEngine
{
	SDLGameObject::SDLGameObject(const LoaderParams* params) :
		GameObject(params),
		_position(params->getX(), params->getY()),
		_velocity(0, 0)
	{
		_width = params->getWidth();
		_height = params->getHeight();
		_textureID = params->getTextureID();

		_currentRow = 1;
		_currentFrame = 1;
	}//SDLGameObject
	//--------------------------------------------------------------------------

	void SDLGameObject::draw()
	{
		TheTextureManager::Instance()->drawFrame(_textureID, (int)_position.getX(), (int)_position.getY(), _width, _height, _currentRow, _currentFrame, TheHHEngine::Instance()->getRenderer());
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