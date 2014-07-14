#pragma once

#include <vector>

namespace sdlEngine
{
	class GameState;

	class GameStateMachine
	{
	public:
		void pushState(GameState* state);
		void changeState(GameState* state);
		void popState();

		void update();
		void render();
		void clean();

	private:
		std::vector<GameState*> _gameStates;
	};
}