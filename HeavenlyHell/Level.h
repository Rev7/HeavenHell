#pragma once

#include <string>
#include <vector>
#include "LevelParser.h"

namespace sdlEngine
{
	class Layer;
	class Player;

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
		std::vector<Layer*>* getCollisionLayers() { return &_collisionLayers; }
		Player* getPlayer() { return _player; }
		void setPlayer(Player* player) { _player = player; }

	private:
		Level();

		friend class LevelParser;

		std::vector<Tileset> _tilesets;
		std::vector<Layer*> _layers;
		std::vector<Layer*> _collisionLayers;

		Player* _player;
	};
}