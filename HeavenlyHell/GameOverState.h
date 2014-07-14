#pragma once

#include "GameState.h"
#include <vector>

namespace sdlEngine
{
	class GameObject;

	class GameOverState : public GameState
	{
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const { return _GameOverID; }

	private:
		static const std::string _GameOverID;

		std::vector<GameObject*> _gameObjects;

		// callbacks
		static void _gameOverToMain();
		static void _restartPlay();
	};
}