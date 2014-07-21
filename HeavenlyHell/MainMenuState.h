#pragma once

#include "MenuState.h"
#include <vector>

namespace sdlEngine
{
	class GameObject;

	class MainMenuState : public MenuState
	{
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const { return _MenuID; }

	private:
		virtual void setCallbacks(const std::vector<Callback>& callbacks);

		static const std::string _MenuID;

		std::vector<GameObject*> _gameObjects;

		// callbacks
		static void _menuToPlay();
		static void _exitFromMenu();
	};
}