#pragma once

#include "GameState.h"
#include <vector>

namespace sdlEngine
{
	class GameObject;
	
	class PauseState : public GameState
	{
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const { return _PauseID; }

	private:
		static const std::string _PauseID;

		std::vector<GameObject*> _gameObjects;

		// callbacks
		static void _pauseToMain();
		static void _resumeToPlay();
	};
}