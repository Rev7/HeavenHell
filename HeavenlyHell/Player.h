#pragma once

#include "ShooterObject.h"
#include "GameObjectFactory.h"

namespace sdlEngine
{
	class Player : public ShooterObject
	{
	public:
		Player();
		virtual ~Player();

		virtual void update();

	private:
		void resurrect();
		void handleInput();
		void handleAnimation();

		bool _invulnerable;
		int _invulnerableTime;
		int _invulnerableCounter;
	};

	class PlayerCreator : public BaseCreator
	{
		GameObject* createGameObject() const
		{
			return new Player();
		}//createGameObject
	};
}