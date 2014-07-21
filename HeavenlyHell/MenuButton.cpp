#include "MenuButton.h"
#include "LoaderParams.h"
#include "InputHandler.h"

namespace sdlEngine
{
	MenuButton::MenuButton() :
		SDLGameObject(),
		_callback(NULL),
		_released(true)
	{
	}//MenuButton
	//---------------------------------------------------------------------------

	void MenuButton::load(const LoaderParams* params)
	{
		SDLGameObject::load(params);
		_callbackID = params->getCallbackID();
		_currentFrame = MOUSE_OUT;
	}//load
	//---------------------------------------------------------------------------

	void MenuButton::draw()
	{
		SDLGameObject::draw();
	}//draw
	//---------------------------------------------------------------------------

	void MenuButton::update()
	{
		Vector2D* mousePos = TheInputHandler::Instance()->getMousePosition();

		if (mousePos->getX() < (_position.getX() + _width) &&
			mousePos->getX() > _position.getX() &&
			mousePos->getY() < (_position.getY() + _height) &&
			mousePos->getY() > _position.getY())
		{
			if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && _released)
			{
				_released = false;
				_currentFrame = CLICKED;

				if (_callback != NULL)
				{
					_callback();
				}//if
			}//if
			else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
			{
				_released = true;
				_currentFrame = MOUSE_OVER;
			}//else if
		}//if
		else
		{
			_currentFrame = MOUSE_OUT;
		}//else
	}//update
	//---------------------------------------------------------------------------

	void MenuButton::clean()
	{
		SDLGameObject::clean();
	}//clean
}