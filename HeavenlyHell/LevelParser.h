#pragma once

#include "tinyXML.h"
#include <vector>

namespace sdlEngine
{
	class Layer;
	class Level;
	struct Tileset;

	class LevelParser
	{
	public:
		LevelParser();
		~LevelParser();

		Level* parseLevel(const char* levelFile);

	private:
		void parseTilesets(TiXmlElement* tilesetRoot, std::vector<Tileset>* tilesets);
		void parseTileLayer(TiXmlElement* tileElement, std::vector<Layer*>* layers, const std::vector<Tileset>* tilesets);

		int _tileSize;
		int _width;
		int _height;
	};
}