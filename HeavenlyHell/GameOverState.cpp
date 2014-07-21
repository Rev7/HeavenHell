#include "GameOverState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "HHEngine.h"
#include "MenuButton.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "GameStateMachine.h"
#include "AnimatedGraphic.h"
#include "StateParser.h"

namespace sdlEngine
{
	const std::string GameOverState::_GameOverID = "GAMEOVER";

	//--------------------------------------------------------------------------

	void GameOverState::update()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->update();
		}//for
	}//update
	//--------------------------------------------------------------------------

	void GameOverState::render()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->draw();
		}//for
	}//render
	//--------------------------------------------------------------------------

	bool GameOverState::onEnter()
	{
		StateParser stateParser;
		stateParser.parseState("test.xml", _GameOverID, &_gameObjects, &_textureIDList);

		_callbacks.push_back(0);
		_callbacks.push_back(_gameOverToMain);
		_callbacks.push_back(_restartPlay);

		setCallbacks(_callbacks);

		std::cout << "Entering GameOverState\n";
		return true;
	}//onEnter
	//--------------------------------------------------------------------------

	bool GameOverState::onExit()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->clean();
		}//for

		_gameObjects.clear();

		for (unsigned int i = 0; i < _textureIDList.size(); ++i)
		{
			TheTextureManager::Instance()->clearFromTextureMap(_textureIDList[i]);
		}//for

		std::cout << "Exiting GameOverState\n";
		return true;
	}//onExit
	//--------------------------------------------------------------------------

	void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			if (dynamic_cast<MenuButton*>(_gameObjects[i]))
			{
				MenuButton* button = dynamic_cast<MenuButton*>(_gameObjects[i]);
				button->setCallback(callbacks[button->getCallbackID()]);
			}//if
		}//for
	}//setCallbacks
	//--------------------------------------------------------------------------

	void GameOverState::_gameOverToMain()
	{
		TheHHEngine::Instance()->getStateMachine()->changeState(new MainMenuState());
	}//_gameOverToMain
	//--------------------------------------------------------------------------

	void GameOverState::_restartPlay()
	{
		TheHHEngine::Instance()->getStateMachine()->changeState(new PlayState());
	}//_restartPlay
}