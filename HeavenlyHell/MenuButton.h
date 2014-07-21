#pragma once

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

namespace sdlEngine
{
	class LoaderParams;

	class MenuButton : public SDLGameObject
	{
	public:
		MenuButton();

		virtual void load(const LoaderParams* params);
		virtual void draw();
		virtual void update();
		virtual void clean();

		void setCallback(void(*callback)()) { _callback = callback; }
		int getCallbackID() const { return _callbackID; }

	private:
		enum button_state
		{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};

		int _callbackID;
		void (*_callback)();

		bool _released;
	};

	class MenuButtonCreator : public BaseCreator
	{
		GameObject* createGameObject() const
		{
			return new MenuButton();
		}//createGameObject
	};
}