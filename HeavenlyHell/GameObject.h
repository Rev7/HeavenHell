#pragma once

#include "Tools.h"

namespace sdlEngine
{
	class GameObject
	{
	protected:
		std::string textureID;

		int currentFrame;
		int currentRow;

		int x;
		int y;

		int width;
		int height;

	public:
		void load(int _x, int _y, int _width, int _height, std::string _textureID);
		void draw(SDL_Renderer* renderer);
		void update();
		void clean();

	};
}