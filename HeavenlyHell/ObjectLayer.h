#pragma once

#include "Layer.h"
#include <vector>

namespace sdlEngine
{
	class GameObject;

	class ObjectLayer : public Layer
	{
	public:
		ObjectLayer(void);
		~ObjectLayer(void);
		
		virtual void update();
		virtual void render();

		std::vector<GameObject*>* getGameObjects() { return &_gameObjects; }

	private:
		std::vector<GameObject*> _gameObjects;
	};
}