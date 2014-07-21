#include "TileLayer.h"

namespace sdlEngine
{
	TileLayer::TileLayer(int tileSize, const std::vector<Tileset>& tilesets) :
		_tileSize(tileSize),
		_tilesets(tilesets),
		_position(0.0f, 0.0f),
		_velocity(0.0f, 0.0f)
	{
	}//TileLayer
	//---------------------------------------------------------------------------

	void TileLayer::update()
	{

	}//update
	//---------------------------------------------------------------------------

	void TileLayer::render()
	{

	}//render
	//---------------------------------------------------------------------------

	Tileset TileLayer::getTilesetByID(int tileID)
	{
		Tileset tileset;

		return tileset;
	}//getTilesetByID
}