#pragma once

#include "GameObject.h"
#include "Vector2D.h"
#include <string>

namespace sdlEngine
{
	class SDLGameObject : public GameObject
	{
	public:
		SDLGameObject(const LoaderParams* params);
		
		virtual void draw();
		virtual void update();
		virtual void clean();

		// Accesseurs
		Vector2D& getPosition() { return _position; }
		int getWidth() const { return _width; }
		int getHeight() const { return _height; }

	protected:
		Vector2D _position;
		Vector2D _velocity;
		Vector2D _acceleration;

		int _width;
		int _height;

		int _currentRow;
		int _currentFrame;

		std::string _textureID;

		int _numFrames;
	};
}