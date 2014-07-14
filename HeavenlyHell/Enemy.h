#pragma once

#include "SDLGameObject.h"

namespace sdlEngine
{
	class Enemy : public SDLGameObject
	{
	public:
		Enemy(const LoaderParams* params);

		virtual void draw();
		virtual void update();
		virtual void clean();

	private:
		int _numFrames;
	};
}