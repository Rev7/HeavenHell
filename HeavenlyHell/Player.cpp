#include "Player.h"
#include "InputHandler.h"

namespace sdlEngine
{
	Player::Player(const LoaderParams* params) :
		SDLGameObject(params)
	{
	}//Player
	//--------------------------------------------------------------------------

	void Player::draw()
	{
		SDLGameObject::draw();
	}//draw
	//--------------------------------------------------------------------------

	void Player::update()
	{
		_velocity.setX(0);
		_velocity.setY(0);

		handleInput();

		_currentFrame = int(((SDL_GetTicks() / 100) % _numFrames));

		SDLGameObject::update();
	}//update
	//--------------------------------------------------------------------------

	void Player::clean()
	{
		SDLGameObject::clean();
	}//clean
	//--------------------------------------------------------------------------

	void Player::handleInput()
	{
		Vector2D* target = TheInputHandler::Instance()->getMousePosition();

		_velocity = *target - _position;
		_velocity /= 50;
	}//handleInput
}