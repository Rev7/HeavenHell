#include "Player.h"
#include "InputHandler.h"

namespace sdlEngine
{
	Player::Player() :
		SDLGameObject()
	{
		_pTarget = TheInputHandler::Instance()->getMousePosition();
		_target = *_pTarget;
		_gravity = _position + Vector2D(_width / 2, _height / 2);
	}//Player
	//--------------------------------------------------------------------------

	void Player::load(const LoaderParams* params)
	{
		SDLGameObject::load(params);
	}//load
	//--------------------------------------------------------------------------

	void Player::draw()
	{
		SDLGameObject::draw();
	}//draw
	//--------------------------------------------------------------------------

	void Player::update()
	{
		//_velocity.setX(0);
		//_velocity.setY(0);
		_velocity.setX(0.1);

		_velocity = (_target - _position) / 100;

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
		static bool bClicked = false;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && bClicked)
		{			
			_pTarget = TheInputHandler::Instance()->getMousePosition();
			_target = *_pTarget;

			//_velocity = (_target / 200);

			bClicked = false;
		}//if
		else if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			bClicked = true;
		}//else if
	}//handleInput
}