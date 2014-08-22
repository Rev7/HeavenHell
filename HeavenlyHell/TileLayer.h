#pragma once

#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"
#include <vector>

namespace sdlEngine
{
	class TileLayer : public Layer
	{
	public:
		TileLayer(int tileSize, const std::vector<Tileset>& tilesets);
		virtual ~TileLayer() {}
		
		virtual void update();
		virtual void render();

		Tileset getTilesetByID(int tileID);

		int getTileSize() const { return _tileSize; }
		void setTileSize(int tileSize) { _tileSize = tileSize; }
		void setTileIDs(const std::vector<std::vector<int>>& data) { _tileIDs = data; }

	private:
		int _numColumns;
		int _numRows;
		int _tileSize;

		Vector2D _position;
		Vector2D _velocity;

		const std::vector<Tileset>& _tilesets;

		std::vector<std::vector<int>> _tileIDs;
	};
}