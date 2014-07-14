#pragma once

#include "Tools.h"
#include <vector>

namespace sdlEngine
{
	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	class Vector2D;

	class InputHandler
	{
	public:
		static InputHandler* Instance()
		{
			if (NULL == _instance)
			{
				_instance = new InputHandler();
			}//if

			return _instance;
		}//Instance

		void update();
		void clean();
		void reset();

		// Clavier
		bool isKeyDown(SDL_Scancode key) const;

		// Joysticks
		void initialiseJoysticks();
		int getAxisX(int joy, int stick) const;
		int getAxisY(int joy, int stick) const;
		bool joysticksInitialised() const { return _joysticksInitialised; }
		bool getButtonState(int joy, int buttonNumber) const { return _buttonStates[joy][buttonNumber]; }

		// Souris
		bool getMouseButtonState(int buttonNumber) const { return _mouseButtonStates[buttonNumber]; }
		Vector2D* getMousePosition() const { return _mousePosition; }

	private:
		InputHandler();
		~InputHandler();

		InputHandler(const InputHandler&);
		InputHandler& operator=(const InputHandler&);

		// Singleton
		static InputHandler* _instance;

		// Clavier
		const Uint8* _KeyStates;

		// Joysticks
		static const int _JoystickDeadZone = 10000;
		bool _joysticksInitialised;
		std::vector<SDL_Joystick*> _joysticks;
		std::vector<std::pair<Vector2D*, Vector2D*>> _joystickValues;
		std::vector<std::vector<bool>> _buttonStates;
		
		// Souris
		Vector2D* _mousePosition;
		std::vector<bool> _mouseButtonStates;

		// Evènements Clavier
		void onKeyDown();
		void onKeyUp();

		// Evènements Souris
		void onMouseMove(SDL_Event& event);
		void onMouseButtonDown(SDL_Event& event);
		void onMouseButtonUp(SDL_Event& event);

		// Evènements Joysticks
		void onJoystickAxisMove(SDL_Event& event);
		void onJoystickButtonDown(SDL_Event& event);
		void onJoystickButtonUp(SDL_Event& event);
	};

	typedef InputHandler TheInputHandler;
}