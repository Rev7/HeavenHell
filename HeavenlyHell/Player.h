#pragma once

#include "SDLGameObject.h"

namespace sdlEngine
{
	class Player : public SDLGameObject
	{
	public:
		Player(const LoaderParams* params);

		virtual void draw();
		virtual void update();
		virtual void clean();

	private:
		void handleInput();
	};
}