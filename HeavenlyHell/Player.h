#pragma once

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

namespace sdlEngine
{
	class Player : public SDLGameObject
	{
	public:
		Player();

		virtual void load(const LoaderParams* params);
		virtual void draw();
		virtual void update();
		virtual void clean();

	private:
		void handleInput();
	};

	class PlayerCreator : public BaseCreator
	{
		GameObject* createGameObject() const
		{
			return new Player();
		}//createGameObject
	};
}