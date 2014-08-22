#pragma once

#include <vector>

namespace sdlEngine
{
	class Player;
	class GameObject;
	class TileLayer;

	class CollisionManager
	{
	public:
		CollisionManager(void) {}
		~CollisionManager(void) {}

		void checkPlayerEnemyBulletCollision(Player* player);
		void checkPlayerEnemyCollision(Player* player, const std::vector<GameObject*> &objects);
		void checkEnemyPlayerBulletCollision(const std::vector<GameObject*> &objects);
		void checkPlayerTileCollision(Player* player, const std::vector<TileLayer*> &collisionLayers);
	};
}