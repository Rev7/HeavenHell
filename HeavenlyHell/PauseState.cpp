#include "PauseState.h"
#include "HHEngine.h"
#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "StateParser.h"

namespace sdlEngine
{
	const std::string PauseState::_PauseID = "PAUSE";

	//--------------------------------------------------------------------------

	void PauseState::_pauseToMain()
	{
		TheHHEngine::Instance()->getStateMachine()->changeState(new MainMenuState());
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
		StateParser stateParser;
		stateParser.parseState("test.xml", _PauseID, &_gameObjects, &_textureIDList);

		_callbacks.push_back(0);
		_callbacks.push_back(_pauseToMain);
		_callbacks.push_back(_resumeToPlay);

		setCallbacks(_callbacks);

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

		for (unsigned int i = 0; i < _textureIDList.size(); ++i)
		{
			TheTextureManager::Instance()->clearFromTextureMap(_textureIDList[i]);
		}//for

		TheInputHandler::Instance()->reset();

		std::cout << "Exiting PauseState\n";
		return true;
	}//onExit
	//--------------------------------------------------------------------------

	void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
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
}