#include "GameStateMachine.h"
#include "GameState.h"

namespace sdlEngine
{
	void GameStateMachine::pushState(GameState* state)
	{
		_gameStates.push_back(state);
		_gameStates.back()->onEnter();
	}//pushState
	//---------------------------------------------------------------------------

	void GameStateMachine::changeState(GameState* state)
	{
		if (!_gameStates.empty())
		{
			if (_gameStates.back()->getStateID() == state->getStateID())
			{
				return;	// !!! !!! !!!
			}//if

			_gameStates.back()->onExit();
			_gameStates.pop_back();
		}//if

		state->onEnter();
		_gameStates.push_back(state);
	}//changeState
	//---------------------------------------------------------------------------

	void GameStateMachine::popState()
	{
		if (!_gameStates.empty())
		{
			_gameStates.back()->onExit();
			_gameStates.pop_back();
		}//if
	}//popState
	//---------------------------------------------------------------------------

	void GameStateMachine::update()
	{
		if (!_gameStates.empty())
		{
			_gameStates.back()->update();
		}//if
	}//update
	//---------------------------------------------------------------------------

	void GameStateMachine::render()
	{
		if (!_gameStates.empty())
		{
			_gameStates.back()->render();
		}//if
	}//render
	//---------------------------------------------------------------------------

	void GameStateMachine::clean()
	{
		if (!_gameStates.empty())
		{
			_gameStates.back()->onExit();

			delete _gameStates.back();
			_gameStates.clear();
		}
	}//clean
}