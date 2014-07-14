#include "MenuState.h"
#include "Tools.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "HHEngine.h"
#include "MenuButton.h"
#include "LoaderParams.h"
#include "GameStateMachine.h"
#include "PlayState.h"

namespace sdlEngine
{
	const std::string MenuState::_MenuID = "MENU";

	//--------------------------------------------------------------------------

	void MenuState::update()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->update();
		}//for
	}//update
	//--------------------------------------------------------------------------

	void MenuState::render()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->draw();
		}//for
	}//render
	//--------------------------------------------------------------------------

	bool MenuState::onEnter()
	{
		if (!TheTextureManager::Instance()->load("assets/button.png", "playbutton", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		if (!TheTextureManager::Instance()->load("assets/exit.png", "exitbutton", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton", 3), _menuToPlay);
		GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton", 3), _exitFromMenu);

		_gameObjects.push_back(button1);
		_gameObjects.push_back(button2);

		std::cout << "Entering MenuState\n";
		return true;
	}//onEnter
	//--------------------------------------------------------------------------

	bool MenuState::onExit()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->clean();
		}//for

		_gameObjects.clear();

		TheTextureManager::Instance()->clearFromTextureMap("playbutton");
		TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

		std::cout << "Exiting MenuState\n";
		return true;
	}//onExit
	//--------------------------------------------------------------------------

	void MenuState::_menuToPlay()
	{
		TheHHEngine::Instance()->getStateMachine()->changeState(new PlayState());
	}//_menuToPlay
	//--------------------------------------------------------------------------

	void MenuState::_exitFromMenu()
	{
		TheHHEngine::Instance()->quit();
	}//_exitFromMenu
}