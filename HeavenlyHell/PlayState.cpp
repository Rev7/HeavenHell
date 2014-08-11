#include "PlayState.h"
#include "Tools.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "HHEngine.h"
#include "Player.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "StateParser.h"
#include "LevelParser.h"
#include "LoaderParams.h"

using namespace tools;

namespace sdlEngine
{
	const std::string PlayState::_PlayID = "PLAY";

	//--------------------------------------------------------------------------

	void PlayState::update()
	{
		_level->update();

		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->update();
		}//for
	}//update
	//--------------------------------------------------------------------------

	void PlayState::render()
	{
		TheTextureManager::Instance()->draw("playBackground", 0, 0, 1024, 768, TheHHEngine::Instance()->getRenderer());

		_level->render();

		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->draw();
		}//for
	}//render
	//--------------------------------------------------------------------------

	bool PlayState::onEnter()
	{
		LevelParser levelParser;
		_level = levelParser.parseLevel("assets/map3.tmx");
		
		TheTextureManager::Instance()->load("assets/playBackground.png", "playBackground", TheHHEngine::Instance()->getRenderer());
		TheTextureManager::Instance()->load("assets/verylittledevil.png", "littledevil", TheHHEngine::Instance()->getRenderer());

		GameObject* littledevil = TheGameObjectFactory::Instance()->create("Player");
		littledevil->load(new LoaderParams(100, 100, 64, 64, "littledevil", 1));

		_gameObjects.push_back(littledevil);

		std::cout << "Entering PlayState\n";
		return true;
	}//onEnter
	//--------------------------------------------------------------------------

	bool PlayState::onExit()
	{
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