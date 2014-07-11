#include "GameObject.h"
#include "TextureManager.h"

using namespace tools;

namespace sdlEngine
{
	void GameObject::load(int _x, int _y, int _width, int _height, std::string _textureID)
	{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		textureID = _textureID;

		currentRow = 1;
		currentFrame = 1;
	}//load

	void GameObject::draw(SDL_Renderer* renderer)
	{
		TheTextureManager::Instance()->drawFrame(textureID, x, y, width, height, currentRow, currentFrame, renderer);
	}//draw

	void GameObject::update()
	{
		x += 1;
	}//update
}