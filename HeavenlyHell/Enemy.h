#pragma once

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

namespace sdlEngine
{
	class Enemy : public SDLGameObject
	{
	public:
		Enemy();

		virtual void load(const LoaderParams* params);
		virtual void draw();
		virtual void update();
		virtual void clean();
	};

	class EnemyCreator : public BaseCreator
	{
		GameObject* createGameObject() const
		{
			return new Enemy();
		}//createGameObject
	};
}