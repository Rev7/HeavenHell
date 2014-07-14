#include "MenuButton.h"
#include "LoaderParams.h"
#include "InputHandler.h"

namespace sdlEngine
{
	MenuButton::MenuButton(const LoaderParams* params, void (*callback)()) :
		SDLGameObject(params),
		_callback(callback)
	{
		_currentFrame = MOUSE_OUT;
	}//MenuButton
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

				_callback();
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