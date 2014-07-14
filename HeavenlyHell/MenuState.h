#pragma once

#include "GameState.h"
#include <vector>

namespace sdlEngine
{
	class GameObject;

	class MenuState : public GameState
	{
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const { return _MenuID; }

	private:
		static const std::string _MenuID;

		std::vector<GameObject*> _gameObjects;

		// callbacks
		static void _menuToPlay();
		static void _exitFromMenu();
	};
}