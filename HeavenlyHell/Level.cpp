#include "Level.h"
#include "Layer.h"

namespace sdlEngine
{
	Level::Level()
	{
	}//Level
	//---------------------------------------------------------------------------

	Level::~Level()
	{
	}//~Level
	//---------------------------------------------------------------------------

	void Level::update()
	{
		for (unsigned int i = 0; i < _layers.size(); ++i)
		{
			_layers[i]->update();
		}//for
	}//update
	//---------------------------------------------------------------------------

	void Level::render()
	{
		for (unsigned int i = 0; i < _layers.size(); ++i)
		{
			_layers[i]->render();
		}//for
	}//render
}