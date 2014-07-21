#pragma once

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

namespace sdlEngine
{
	class AnimatedGraphic : public SDLGameObject
	{
	public:
		AnimatedGraphic();

		virtual void load(const LoaderParams* params);
		virtual void draw();
		virtual void update();
		virtual void clean();

	private:
		int _animSpeed;
	};

	class AnimatedGraphicCreator : public BaseCreator
	{
		GameObject* createGameObject() const
		{
			return new AnimatedGraphic();
		}//createGameObject
	};
}