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

		_currentFrame = int(((SDL_GetTicks() / 100) % 6));

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
		if (TheInputHandler::Instance()->joysticksInitialised())
		{
			if (TheInputHandler::Instance()->getAxisX(0, 1) > 0 ||
				TheInputHandler::Instance()->getAxisX(0, 1) < 0)
			{
				_velocity.setX(2.0f * TheInputHandler::Instance()->getAxisX(0, 1));
			}//if

			if (TheInputHandler::Instance()->getAxisY(0, 1) > 0 ||
				TheInputHandler::Instance()->getAxisY(0, 1) < 0)
			{
				_velocity.setY(2.0f * TheInputHandler::Instance()->getAxisY(0, 1));
			}//if

			if (TheInputHandler::Instance()->getAxisX(0, 2) > 0 ||
				TheInputHandler::Instance()->getAxisX(0, 2) < 0)
			{
				_velocity.setX(2.0f * TheInputHandler::Instance()->getAxisX(0, 2));
			}//if

			if (TheInputHandler::Instance()->getAxisY(0, 2) > 0 ||
				TheInputHandler::Instance()->getAxisY(0, 2) < 0)
			{
				_velocity.setY(2.0f * TheInputHandler::Instance()->getAxisY(0, 2));
			}//if

			if (TheInputHandler::Instance()->getButtonState(0, 3))
			{
				_velocity.setX(2.0f);
			}//if
		}//if

		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			_velocity.setX(2.0f);
		}//if

		// Le gameObject suit la souris
		/*Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
		_velocity = (*vec - _position) / 100;*/

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		{
			_velocity.setX(2.0f);
		}//if

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		{
			_velocity.setX(-2.0f);
		}//if

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
		{
			_velocity.setY(-2.0f);
		}//if

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
		{
			_velocity.setY(2.0f);
		}//if
	}//handleInput
}