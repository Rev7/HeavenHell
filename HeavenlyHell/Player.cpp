#include "Player.h"
#include "InputHandler.h"
#include "HHEngine.h"

namespace sdlEngine
{
	Player::Player() :
		ShooterObject()
	{
	}//Player
	//--------------------------------------------------------------------------

	void Player::update()
	{
		if (TheHHEngine::Instance()->getLevelComplete())
		{
			if (_position.getX() >= TheHHEngine::Instance()->getGameWidth())
			{
				TheHHEngine::Instance()->setCurrentLevel(TheHHEngine::Instance()->getCurrentLevel() + 1);
			}//if
			else
			{
				_velocity.setY(0);
				_velocity.setX(3);

				ShooterObject::update();

				handleAnimation();
			}//else
		}//if
		else
		{
			if (!_dying)
			{
				_velocity.setX(0);
				_velocity.setY(0);

				handleInput();

				ShooterObject::update();

				handleAnimation();
			}//if
			else
			{
				_curruntFrame = int(((SDL_GetTicks() / (100)) % _numFrames));

				if (_dyingCounter == _dyingTime)
				{
					resurrect();
				}//if

				_dyingCounter++;
			}//else
		}//else
	}//update
	//--------------------------------------------------------------------------

	void Player::resurrect()
	{
		TheHHEngine::Instance()->setPlayerLives(TheHHEngine::Instance()->getPlayerLives() - 1);

		_position.setX(10);
		_position.setY(200);
		_dying = false;

		_textureID = "player";

		_curruntFrame = 0;
		_numFrames = 5;
		_width = 101;
		_height = 46;

		_dyingCounter = 0;
		_invulnerable = true;
	}//resurrect
	//--------------------------------------------------------------------------

	void Player::handleInput()
	{

	}//handleInput
	//--------------------------------------------------------------------------

	void Player::handleAnimation()
	{
		if (_invulnerable)
		{
			if (_invulnerableCounter == _invulnerableTime)
			{
				_invulnerable = false;
				_invulnerableCounter = 0;
				_alpha = 255;
			}//if
			else
			{
				if (_alpha == 255)
				{
					_alpha = 0;
				}//if
				else
				{
					_alpha = 255;
				}//else
			}//else

			_invulnerableCounter++;
		}//if

		if (!_dead)
		{
			if (_velocity.getX() < 0)
			{
				_angle = -10.0;
			}//if
			else if (_velocity.getX() > 0)
			{
				_angle = 10.0;
			}//else if
			else
			{
				_angle = 0.0;
			}//else
		}//if

		_curruntFrame = int(((SDL_GetTicks() / (100)) % _numFrames));
	}//handleAnimation
}