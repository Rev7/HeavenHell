#include "AnimatedGraphic.h"
#include "LoaderParams.h"
#include "Tools.h"

namespace sdlEngine
{
	AnimatedGraphic::AnimatedGraphic(const LoaderParams* params, int animSpeed) :
		SDLGameObject(params),
		_animSpeed(animSpeed)
	{
	}//Player
	//--------------------------------------------------------------------------

	void AnimatedGraphic::draw()
	{
		SDLGameObject::draw();
	}//draw
	//--------------------------------------------------------------------------

	void AnimatedGraphic::update()
	{
		_currentFrame = int(((SDL_GetTicks() / (1000 / _animSpeed)) % _numFrames));
	}//update
	//--------------------------------------------------------------------------

	void AnimatedGraphic::clean()
	{
		SDLGameObject::clean();
	}//clean
}