#include "ObjectLayer.h"
#include "GameObject.h"

namespace sdlEngine
{
	ObjectLayer::ObjectLayer(void)
	{
	}//ObjectLayer
	//--------------------------------------------------------------------------

	ObjectLayer::~ObjectLayer(void)
	{
	}//~ObjectLayer
	//--------------------------------------------------------------------------

	void ObjectLayer::update()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->update();
		}//for
	}//update
	//--------------------------------------------------------------------------

	void ObjectLayer::render()
	{
		for (unsigned int i = 0; i < _gameObjects.size(); ++i)
		{
			_gameObjects[i]->draw();
		}//for
	}//render
}