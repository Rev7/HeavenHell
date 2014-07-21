#include "AnimatedGraphic.h"
#include "LoaderParams.h"
#include "Tools.h"

namespace sdlEngine
{
	AnimatedGraphic::AnimatedGraphic() : 
		SDLGameObject()
	{
	}//Player
	//--------------------------------------------------------------------------

	void AnimatedGraphic::load(const LoaderParams* params)
	{
		SDLGameObject::load(params);
		_animSpeed = params->getAnimSpeed();
	}//load
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