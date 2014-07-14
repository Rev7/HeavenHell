#include "PlayState.h"
#include "Tools.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "HHEngine.h"
#include "Player.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PauseState.h"
#include "Enemy.h"
#include "GameOverState.h"

using namespace tools;

namespace sdlEngine
{
	const std::string PlayState::_PlayID = "PLAY";

	//--------------------------------------------------------------------------

	void PlayState::update()
	{
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		{
			TheHHEngine::Instance()->getStateMachine()->pushState(new PauseState());
		}//if
		
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->update();
		}//for

		if (checkCollision(dynamic_cast<SDLGameObject*>(_gameObjects[0]), dynamic_cast<SDLGameObject*>(_gameObjects[1])))
		{
			TheHHEngine::Instance()->getStateMachine()->pushState(new GameOverState());
		}//if
	}//update
	//--------------------------------------------------------------------------

	void PlayState::render()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->draw();
		}//for
	}//render
	//--------------------------------------------------------------------------

	bool PlayState::onEnter()
	{
		if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		if (!TheTextureManager::Instance()->load("assets/helicopter2.png", "helicopter2", TheHHEngine::Instance()->getRenderer()))
		{
			return false;	// !!! !!! !!!
		}//if

		GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, "helicopter", 5));
		GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2", 5));

		_gameObjects.push_back(player);
		_gameObjects.push_back(enemy);
		
		std::cout << "Entering PlayState\n";
		return true;
	}//onEnter
	//--------------------------------------------------------------------------

	bool PlayState::onExit()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->clean();
		}//for

		_gameObjects.clear();

		TheTextureManager::Instance()->clearFromTextureMap("helicopter");
		TheTextureManager::Instance()->clearFromTextureMap("helicopter2");

		std::cout << "Exiting PlayState\n";
		return true;
	}//onExit
	//--------------------------------------------------------------------------

	bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
	{
		float leftA, leftB;
		float rightA, rightB;
		float topA, topB;
		float bottomA, bottomB;

		leftA = p1->getPosition().getX();
		rightA = p1->getPosition().getX() + p1->getWidth();
		topA = p1->getPosition().getY();
		bottomA = p1->getPosition().getY() + p1->getHeight();

		leftB = p2->getPosition().getX();
		rightB = p2->getPosition().getX() + p2->getWidth();
		topB = p2->getPosition().getY();
		bottomB = p2->getPosition().getY() + p2->getHeight();

		if (bottomA <= topB) { return false; }
		if (topA >= bottomB) { return false; }
		if (rightA <= leftB) { return false; }
		if (leftA >= rightB) { return false; }

		return true;
	}//checkCollision
}