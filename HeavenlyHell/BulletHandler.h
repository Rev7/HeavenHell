#pragma once

#include "Vector2D.h"
#include <string>
#include <vector>

namespace sdlEngine
{
	class BulletHandler
	{
	public:
		static BulletHandler* Instance()
		{
			if (NULL == _instance)
			{
				_instance = new BulletHandler();
			}//if

			return _instance;
		}//Instance

		void addPlayerBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading);
		void addEnemyBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading);

	private:
		BulletHandler(void) {}
		~BulletHandler(void) {}

		static BulletHandler* _instance;

		std::vector<PlayerBullet*> _playerBullets;
		std::vector<EnemyBullet*> _enemyBullets;
	};

	typedef BulletHandler TheBulletHandler;
}