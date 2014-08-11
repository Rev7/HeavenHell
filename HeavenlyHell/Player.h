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

		Vector2D _gravity;
		Vector2D* _pTarget;
		Vector2D _target;
	};

	class PlayerCreator : public BaseCreator
	{
		GameObject* createGameObject() const
		{
			return new Player();
		}//createGameObject
	};
}