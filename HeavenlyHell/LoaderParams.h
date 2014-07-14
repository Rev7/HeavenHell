#pragma once

#include <string>

namespace sdlEngine
{
	class LoaderParams
	{
	public:
		LoaderParams(int x, int y, int width, int height, std::string textureID):
			_x(x), 
			_y(y),
			_width(width),
			_height(height),
			_textureID(textureID)
		{}//LoaderParams

		// Accesseurs
		int getX() const { return _x; }
		int getY() const { return _y; }
		int getWidth() const { return _width; }
		int getHeight() const { return _height; }
		std::string getTextureID() const { return _textureID; }

	private:
		int _x;
		int _y;

		int _width;
		int _height;

		std::string _textureID;
	};
}