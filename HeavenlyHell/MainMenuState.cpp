#include "MainMenuState.h"
#include "Tools.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "HHEngine.h"
#include "MenuButton.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "StateParser.h"

namespace sdlEngine
{
	const std::string MainMenuState::_MenuID = "MENU";

	//--------------------------------------------------------------------------

	void MainMenuState::update()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->update();
		}//for
	}//update
	//--------------------------------------------------------------------------

	void MainMenuState::render()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->draw();
		}//for
	}//render
	//--------------------------------------------------------------------------

	bool MainMenuState::onEnter()
	{
		StateParser stateParser;
		stateParser.parseState("test.xml", _MenuID, &_gameObjects, &_textureIDList);

		_callbacks.push_back(0);
		_callbacks.push_back(_menuToPlay);
		_callbacks.push_back(_exitFromMenu);

		setCallbacks(_callbacks);

		std::cout << "Entering MenuState\n";
		return true;
	}//onEnter
	//--------------------------------------------------------------------------

	bool MainMenuState::onExit()
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

		std::cout << "Exiting MenuState\n";
		return true;
	}//onExit
	//--------------------------------------------------------------------------

	void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
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

	void MainMenuState::_menuToPlay()
	{
		TheHHEngine::Instance()->getStateMachine()->changeState(new PlayState());
	}//_menuToPlay
	//--------------------------------------------------------------------------

	void MainMenuState::_exitFromMenu()
	{
		TheHHEngine::Instance()->quit();
	}//_exitFromMenu
}