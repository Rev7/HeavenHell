#include "Enemy.h"
#include "Tools.h"

namespace sdlEngine
{
	Enemy::Enemy() :
		SDLGameObject()
	{
	}//Player
	//--------------------------------------------------------------------------

	void Enemy::load(const LoaderParams* params)
	{
		SDLGameObject::load(params);
		_velocity.setY(2.0f);
		_velocity.setX(0.001f);
	}//load
	//--------------------------------------------------------------------------

	void Enemy::draw()
	{
		SDLGameObject::draw();
	}//draw
	//--------------------------------------------------------------------------

	void Enemy::update()
	{
		_currentFrame = int(((SDL_GetTicks() / 100) % _numFrames));

		if (_position.getY() < 0)
		{
			_velocity.setY(2.0f);
		}//if
		else if (_position.getY() > 400)
		{
			_velocity.setY(-2.0f);
		}//else if

		SDLGameObject::update();
	}//update
	//--------------------------------------------------------------------------

	void Enemy::clean()
	{
		SDLGameObject::clean();
	}//clean
}