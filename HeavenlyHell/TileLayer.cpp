#include "TileLayer.h"
#include "HHEngine.h"
#include "TextureManager.h"

namespace sdlEngine
{
	TileLayer::TileLayer(int tileSize, const std::vector<Tileset>& tilesets) :
		_tileSize(tileSize),
		_tilesets(tilesets),
		_position(0.0f, 0.0f),
		_velocity(0.0f, 0.0f)
	{
		_numColumns = (TheHHEngine::Instance()->getGameWidth() / _tileSize);
		_numRows = (TheHHEngine::Instance()->getGameHeight() / _tileSize);
	}//TileLayer
	//---------------------------------------------------------------------------

	void TileLayer::update()
	{
		_position += _velocity;
	}//update
	//---------------------------------------------------------------------------

	void TileLayer::render()
	{
		int x, y, x2, y2 = 0;

		x = (_position.getX() / _tileSize);
		y = (_position.getY() / _tileSize);

		x2 = int(_position.getX()) % _tileSize;
		y2 = int(_position.getY()) % _tileSize;

		for (int i = 0; i < _numRows; ++i)
		{
			for (int j = 0; j < _numColumns; ++j)
			{
				int id = _tileIDs[i][j + x];

				if (id == 0)
				{
					continue;
				}//if

				Tileset tileset = getTilesetByID(id);

				id--;

				TheTextureManager::Instance()->drawTile(
					tileset.name,
					tileset.margin,
					tileset.spacing,
					(j * _tileSize) - x2,
					(i * _tileSize) - y2,
					_tileSize,
					_tileSize,
					(id - (tileset.firstGridID - 1)) / tileset.numColumns,
					(id - (tileset.firstGridID - 1)) % tileset.numColumns, 
					TheHHEngine::Instance()->getRenderer());
			}//for
		}//for
	}//render
	//---------------------------------------------------------------------------

	Tileset TileLayer::getTilesetByID(int tileID)
	{
		for (int i = 0; i < _tilesets.size(); ++i)
		{
			if (i + 1 <= _tilesets.size() - 1)
			{
				if (tileID >= _tilesets[i].firstGridID && 
					tileID < _tilesets[i + 1].firstGridID)
				{
					return _tilesets[i];
				}//if
			}//if
			else
			{
				return _tilesets[i];
			}//else
		}//for
		
		std::cout << "### Did not find tileset, returning empty tileset \n";

		Tileset tileset;
		return tileset;
	}//getTilesetByID
}