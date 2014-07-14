#include "PauseState.h"
#include "HHEngine.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "LoaderParams.h"
#include "InputHandler.h"

namespace sdlEngine
{
	const std::string PauseState::_PauseID = "PAUSE";

	//--------------------------------------------------------------------------

	void PauseState::_pauseToMain()
	{
		TheHHEngine::Instance()->getStateMachine()->changeState(new MenuState());
	}//_pauseToMain
	//--------------------------------------------------------------------------

	void PauseState::_resumeToPlay()
	{
		TheHHEngine::Instance()->getStateMachine()->popState();
	}//_resumeToPlay
	//--------------------------------------------------------------------------

	void PauseState::update()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->update();
		}//for
	}//update
	//--------------------------------------------------------------------------

	void PauseState::render()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->draw();
		}//for
	}//render
	//--------------------------------------------------------------------------

	bool PauseState::onEnter()
	{
		if (!TheTextureManager::Instance()->load("assets/resume.png", "resumebutton", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		if (!TheTextureManager::Instance()->load("assets/main.png", "mainbutton", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton", 3), _pauseToMain);
		GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton", 3), _resumeToPlay);

		_gameObjects.push_back(button1);
		_gameObjects.push_back(button2);

		std::cout << "Entering PauseState\n";
		return true;
	}//onEnter
	//--------------------------------------------------------------------------

	bool PauseState::onExit()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->clean();
		}//for

		_gameObjects.clear();

		TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
		TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

		TheInputHandler::Instance()->reset();

		std::cout << "Exiting PauseState\n";
		return true;
	}//onExit
}