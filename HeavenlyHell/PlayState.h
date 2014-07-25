#pragma once

#include "GameState.h"
#include <vector>

namespace sdlEngine
{
	class GameObject;
	class SDLGameObject;
	//class Level;

	class PlayState : public GameState
	{
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const { return _PlayID; }

		bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	private:
		static const std::string _PlayID;

		std::vector<GameObject*> _gameObjects;
		//* _level;
	};
}