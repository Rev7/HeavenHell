#include "CollisionManager.h"
#include "Player.h"
#include "TileLayer.h"

namespace sdlEngine
{
	void CollisionManager::checkPlayerTileCollision(Player* player, const std::vector<TileLayer*> &collisionLayers)
	{
		for (std::vector<TileLayer*>::const_iterator it = collisionLayers.begin(); it != collisionLayers.end(); ++it)
		{
			TileLayer* tileLayer = (*it);
			std::vector<std::vector<int>> tiles = tileLayer->getTileIDs();

			Vector2D layerPos = tileLayer->getPosition();

			int x, y, tileColumn, tileRow, tileid = 0;

			x = layerPos.getX() / tileLayer->getTileSize();
			y = layerPos.getY() / tileLayer->getTileSize();

			if (player->getVelocity().getX() >= 0 || player->getVelocity().getY() >= 0)
			{
				tileColumn = ((player->getPosition().getX() + player->getWidth()) / tileLayer->getTileSize());
				tileRow = ((player->getPosition().getY() + player->getHeight()) / tileLayer->getTileSize());
				tileid = tiles[tileRow + y][tileColumn + x];
			}//if
			else if (player->getVelocity().getX() < 0 || player->getVelocity().getY() < 0)
			{
				tileColumn = player->getPosition().getX() / tileLayer->getTileSize();
				tileRow = player->getPosition().getY() / tileLayer->getTileSize();
				tileid = tiles[tileRow + y][tileColumn + x];
			}//else if

			if (tileid != 0)
			{
				player->collision();
			}//if
		}//for
	}//checkPlayerTileCollision
}