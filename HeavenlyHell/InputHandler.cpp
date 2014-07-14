#include "InputHandler.h"
#include "HHEngine.h"
#include "Vector2D.h"

using namespace tools;

namespace sdlEngine
{
	InputHandler* InputHandler::_instance = NULL;

	//--------------------------------------------------------------------------

	InputHandler::InputHandler() :
		_KeyStates(NULL),
		_joysticksInitialised(false),
		_mousePosition(new Vector2D(0, 0))
	{
		for (int i = 0; i < 3; ++i)
		{
			_mouseButtonStates.push_back(false);
		}//for
	}//InputHandler
	//--------------------------------------------------------------------------

	InputHandler::~InputHandler()
	{
		Tools::safeDelete(_mousePosition);

		_joystickValues.clear();
		_joysticks.clear();
		_buttonStates.clear();
		_mouseButtonStates.clear();
	}//~InputHandler
	//--------------------------------------------------------------------------

	void InputHandler::update()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					TheHHEngine::Instance()->quit();
					break;

				case SDL_JOYAXISMOTION:
					onJoystickAxisMove(event);
					break;

				case SDL_JOYBUTTONDOWN:
					onJoystickButtonDown(event);
					break;

				case SDL_JOYBUTTONUP:
					onJoystickButtonUp(event);
					break;

				case SDL_MOUSEMOTION:
					onMouseMove(event);
					break;

				case SDL_MOUSEBUTTONDOWN:
					onMouseButtonDown(event);
					break;

				case SDL_MOUSEBUTTONUP:
					onMouseButtonUp(event);
					break;

				case SDL_KEYDOWN:
					onKeyDown();
					break;

				case SDL_KEYUP:
					onKeyUp();
					break;

				default:
					break;
			}//switch
		}//while
	}//update
	//--------------------------------------------------------------------------

	void InputHandler::clean()
	{
		if (_joysticksInitialised)
		{
			for (int i = 0; i < SDL_NumJoysticks(); ++i)
			{
				SDL_JoystickClose(_joysticks[i]);
			}//for
		}//if
	}//clean
	//--------------------------------------------------------------------------

	void InputHandler::reset()
	{
		_mouseButtonStates[LEFT] = false;
		_mouseButtonStates[MIDDLE] = false;
		_mouseButtonStates[RIGHT] = false;
	}//reset
	//--------------------------------------------------------------------------

	void InputHandler::initialiseJoysticks()
	{
		if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
		{
			SDL_InitSubSystem(SDL_INIT_JOYSTICK);
		}//if

		if (SDL_NumJoysticks() > 0)
		{
			for (int i = 0; i < SDL_NumJoysticks(); ++i)
			{
				SDL_Joystick* joy = SDL_JoystickOpen(i);

				if (SDL_JoystickOpen(i))
				{
					_joysticks.push_back(joy);
					_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

					std::vector<bool> tempButtons;

					for (int j = 0; j < SDL_JoystickNumButtons(joy); ++j)
					{
						tempButtons.push_back(false);
					}//for

					_buttonStates.push_back(tempButtons);
				}//if
				else
				{
					std::cout << "### Joystick(" << i << " Open fail" << SDL_GetError() << "\n";
					Tools::logSDLError(std::cout, "SDL_JoystickOpen");
				}//else
			}//for

			SDL_JoystickEventState(SDL_ENABLE);
			_joysticksInitialised = true;

			std::cout << "Initialised " << _joysticks.size() << " joystick(s)\n";
		}//if
		else
		{
			_joysticksInitialised = false;
		}//else
	}//initialiseJoysticks
	//--------------------------------------------------------------------------

	int InputHandler::getAxisX(int joy, int stick) const
	{
		if (_joystickValues.size() > 0)
		{
			if (stick == 1)
			{
				return (int)_joystickValues[joy].first->getX();
			}
			else if (stick == 2)
			{
				return (int)_joystickValues[joy].second->getX();
			}//else if
		}//if

		return 0;
	}//getAxisX
	//--------------------------------------------------------------------------

	int InputHandler::getAxisY(int joy, int stick) const
	{
		if (_joystickValues.size() > 0)
		{
			if (stick == 1)
			{
				return (int)_joystickValues[joy].first->getY();
			}
			else if (stick == 2)
			{
				return (int)_joystickValues[joy].second->getY();
			}//else if
		}//if

		return 0;
	}//getAxisY
	//--------------------------------------------------------------------------

	bool InputHandler::isKeyDown(SDL_Scancode key) const
	{
		if (_KeyStates != 0)
		{
			if (_KeyStates[key] == 1)
			{
				return true;
			}//if
		}//if

		return false;
	}//isKeyDown
	//--------------------------------------------------------------------------
	
	void InputHandler::onKeyDown()
	{
		_KeyStates = SDL_GetKeyboardState(NULL);
	}//onKeyDown
	//--------------------------------------------------------------------------

	void InputHandler::onKeyUp()
	{
		_KeyStates = SDL_GetKeyboardState(NULL);
	}//onKeyUp
	//--------------------------------------------------------------------------
	
	void InputHandler::onMouseMove(SDL_Event& event)
	{
		_mousePosition->setX((float)event.motion.x);
		_mousePosition->setY((float)event.motion.y);
	}//onMouseMove
	//--------------------------------------------------------------------------

	void InputHandler::onMouseButtonDown(SDL_Event& event) 
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			_mouseButtonStates[LEFT] = true;
		}//if

		if (event.button.button == SDL_BUTTON_MIDDLE)
		{
			_mouseButtonStates[MIDDLE] = true;
		}//if

		if (event.button.button == SDL_BUTTON_RIGHT)
		{
			_mouseButtonStates[RIGHT] = true;
		}//if
	}//onMouseButtonDown
	//--------------------------------------------------------------------------

	void InputHandler::onMouseButtonUp(SDL_Event& event)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			_mouseButtonStates[LEFT] = false;
		}//if

		if (event.button.button == SDL_BUTTON_MIDDLE)
		{
			_mouseButtonStates[MIDDLE] = false;
		}//if

		if (event.button.button == SDL_BUTTON_RIGHT)
		{
			_mouseButtonStates[RIGHT] = false;
		}//if
	}//onMouseButtonUp
	//--------------------------------------------------------------------------

	void InputHandler::onJoystickAxisMove(SDL_Event& event)
	{
		int whichOne = event.jaxis.which;

		// stick gauche : gauche/droite
		if (event.jaxis.axis == 0)
		{
			if (event.jaxis.value > _JoystickDeadZone)
			{
				_joystickValues[whichOne].first->setX(1);
			}//if
			else if (event.jaxis.value < -_JoystickDeadZone)
			{
				_joystickValues[whichOne].first->setX(-1);
			}//else if
			else
			{
				_joystickValues[whichOne].first->setX(0);
			}//else
		}//if

		// stick gauche : haut/bas
		if (event.jaxis.axis == 1)
		{
			if (event.jaxis.value > _JoystickDeadZone)
			{
				_joystickValues[whichOne].first->setY(1);
			}//if
			else if (event.jaxis.value < -_JoystickDeadZone)
			{
				_joystickValues[whichOne].first->setY(-1);
			}//else if
			else
			{
				_joystickValues[whichOne].first->setY(0);
			}//else
		}//if

		// stick droit : gauche/droite
		if (event.jaxis.axis == 2)
		{
			if (event.jaxis.value > _JoystickDeadZone)
			{
				_joystickValues[whichOne].second->setX(1);
			}//if
			else if (event.jaxis.value < -_JoystickDeadZone)
			{
				_joystickValues[whichOne].second->setX(-1);
			}//else if
			else
			{
				_joystickValues[whichOne].second->setX(0);
			}//else
		}//if

		// stick droit : haut/bas
		if (event.jaxis.axis == 3)
		{
			if (event.jaxis.value > _JoystickDeadZone)
			{
				_joystickValues[whichOne].second->setY(1);
			}//if
			else if (event.jaxis.value < -_JoystickDeadZone)
			{
				_joystickValues[whichOne].second->setY(-1);
			}//else if
			else
			{
				_joystickValues[whichOne].second->setY(0);
			}//else
		}//if
	}//onJoystickAxisMove
	//--------------------------------------------------------------------------

	void InputHandler::onJoystickButtonDown(SDL_Event& event)
	{
		int whichOne = event.jaxis.which;
		_buttonStates[whichOne][event.jbutton.button] = true;
	}//onJoystickButtonDown
	//--------------------------------------------------------------------------

	void InputHandler::onJoystickButtonUp(SDL_Event& event)
	{
		int whichOne = event.jaxis.which;
		_buttonStates[whichOne][event.jbutton.button] = false;
	}//onJoystickButtonUp
}