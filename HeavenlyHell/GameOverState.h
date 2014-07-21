#pragma once

#include "MenuState.h"
#include <vector>

namespace sdlEngine
{
	class GameObject;

	class GameOverState : public MenuState
	{
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const { return _GameOverID; }

	private:
		virtual void setCallbacks(const std::vector<Callback>& callbacks);

		static const std::string _GameOverID;

		std::vector<GameObject*> _gameObjects;

		// callbacks
		static void _gameOverToMain();
		static void _restartPlay();
	};
}