#pragma once

#include "MenuState.h"
#include <vector>

namespace sdlEngine
{
	class GameObject;
	
	class PauseState : public MenuState
	{
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const { return _PauseID; }

	private:
		virtual void setCallbacks(const std::vector<Callback>& callbacks);

		static const std::string _PauseID;

		std::vector<GameObject*> _gameObjects;

		// callbacks
		static void _pauseToMain();
		static void _resumeToPlay();
	};
}