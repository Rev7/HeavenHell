#pragma once

#include "SDLGameObject.h"

namespace sdlEngine
{
	class LoaderParams;

	class MenuButton : public SDLGameObject
	{
	public:
		MenuButton(const LoaderParams* params, void(*callback)());

		virtual void draw();
		virtual void update();
		virtual void clean();

	private:
		enum button_state
		{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};

		void (*_callback)();
		bool _released;
	};
}