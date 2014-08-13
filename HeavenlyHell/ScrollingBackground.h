#pragma once

#include <memory>

namespace sdlEngine
{
	class LoaderParams;
	
	class ScrollingBackground : public ShooterObject
	{
	public:
		ScrollingBackground() : ShooterObject() {}
		virtual ~ScrollingBackground() {}

		virtual void load(std::unique_ptr<LoaderParams> const &params);
		virtual void draw();
		virtual void update();

	private:
		SDL_Rect _srcRect1;
		SDL_Rect _srcRect2;
		SDL_Rect _destRect1;
		SDL_Rect _destRect2;

		int _srcRect1Width;
		int _srcRect2Width;
		int _destRect1Width;
		int _destRect2Width;

		int _scrollSpeed;
	};
}