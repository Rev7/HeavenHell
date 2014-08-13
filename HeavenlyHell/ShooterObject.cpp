#include "ShooterObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "HHEngine.h"

namespace sdlEngine
{
	ShooterObject::ShooterObject() :
		GameObject()
	{
	}//SDLGameObject
	//--------------------------------------------------------------------------

	void ShooterObject::load(std::unique_ptr<LoaderParams> const &params)
	{
	}//load
	//--------------------------------------------------------------------------

	void ShooterObject::draw()
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

	void ShooterObject::update()
	{
		_velocity += _acceleration;
		_position += _velocity;
	}//update
	//--------------------------------------------------------------------------

	void ShooterObject::doDyingAnimation()
	{
		scroll(TheHHEngine::Instance()->getScrollSpeed());

		_currentFrame = int(((SDL_GetTicks() / (1000 / 3)) % _numFrames));

		if (_dyingCounter == _dyingTime)
		{
			_dead = true;
		}//if
		_dyingCounter++;
	}//doDyingAnimation
}