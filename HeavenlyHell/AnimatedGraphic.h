#pragma once

#include "SDLGameObject.h"

namespace sdlEngine
{
	class AnimatedGraphic : public SDLGameObject
	{
	public:
		AnimatedGraphic(const LoaderParams* params, int animSpeed);

		virtual void draw();
		virtual void update();
		virtual void clean();

	private:
		int _animSpeed;
	};
}