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

using namespace tools;

namespace sdlEngine
{
	const std::string PlayState::_PlayID = "PLAY";

	//--------------------------------------------------------------------------

	void PlayState::update()
	{

	}//update
	//--------------------------------------------------------------------------

	void PlayState::render()
	{

	}//render
	//--------------------------------------------------------------------------

	bool PlayState::onEnter()
	{
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