#pragma once

#include <string>
#include <vector>
#include "LevelParser.h"

namespace sdlEngine
{
	class Layer;

	struct Tileset
	{
		int firstGridID;
		int tileWidth;
		int tileHeight;
		int spacing;
		int margin;
		int width;
		int height;
		int numColumns;
		std::string name;
	};
	
	class Level
	{
	public:
		~Level();

		void update();
		void render();

		// Accesseurs
		std::vector<Tileset>* getTilesets() { return &_tilesets; }
		std::vector<Layer*>* getLayers() { return &_layers; }

	private:
		Level();

		friend class LevelParser;

		std::vector<Tileset> _tilesets;
		std::vector<Layer*> _layers;
	};
}