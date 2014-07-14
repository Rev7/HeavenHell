#include "GameOverState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "HHEngine.h"
#include "MenuButton.h"
#include "LoaderParams.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameStateMachine.h"
#include "AnimatedGraphic.h"

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
		if (!TheTextureManager::Instance()->load("assets/gameover.png", "gameovertext", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		if (!TheTextureManager::Instance()->load("assets/main.png", "mainbutton", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		if (!TheTextureManager::Instance()->load("assets/restart.png", "restartbutton", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "gameovertext", 2), 2);
		GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton", 3), _gameOverToMain);
		GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton", 3), _restartPlay);

		_gameObjects.push_back(gameOverText);
		_gameObjects.push_back(button1);
		_gameObjects.push_back(button2);

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

		TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
		TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
		TheTextureManager::Instance()->clearFromTextureMap("restartbutton");

		std::cout << "Exiting GameOverState\n";
		return true;
	}//onExit
	//--------------------------------------------------------------------------

	void GameOverState::_gameOverToMain()
	{
		TheHHEngine::Instance()->getStateMachine()->changeState(new MenuState());
	}//_gameOverToMain
	//--------------------------------------------------------------------------

	void GameOverState::_restartPlay()
	{
		TheHHEngine::Instance()->getStateMachine()->changeState(new PlayState());
	}//_restartPlay
}