#pragma once

#include "GameObject.h"
#include "Vector2D.h"
#include <string>

namespace sdlEngine
{
	class ShooterObject : public GameObject
	{
	public:
		virtual ~ShooterObject() {}

		virtual void load(std::unique_ptr<LoaderParams> const &params);
		virtual void draw();
		virtual void update();
		virtual void clean() {}
		virtual void collision() {}
		virtual std::string type() { return "SDLGameObject"; }

	protected:
		ShooterObject();

		void doDyingAnimation();

		int _bulletFiringSpeed;
		int _bulletCounter;

		int _moveSpeed;

		int _dyingTime;
		int _dyingCounter;

		bool _playedDeathSound;
	};
}