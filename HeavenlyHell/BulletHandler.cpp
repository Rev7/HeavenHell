#include "BulletHandler.h"
#include "Bullet.h"
#include "LoaderParams.h"
#include <memory>

namespace sdlEngine
{
	void BulletHandler::addPlayerBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading)
	{
		PlayerBullet* playerBullet = new PlayerBullet();
		playerBullet->load(std::unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames)), heading);

		_playerBullets.push_back(playerBullet);
	}//addPlayerBullet

	void BulletHandler::addEnemyBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading)
	{
		EnemyBullet* enemyBullet = new EnemyBullet();
		enemyBullet->load(std::unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames)), heading);

		_enemyBullets.push_back(enemyBullet);
	}//addEnemyBullet
}