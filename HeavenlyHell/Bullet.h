#pragma once

#include "ShooterObject.h"
#include <string>
#include <memory>

namespace sdlEngine
{
	class LoaderParams;

	class PlayerBullet : public ShooterObject
	{
	public:
		PlayerBullet() : ShooterObject() {}
		virtual ~PlayerBullet() {}

		virtual std::string type() { return "PlayerBullet"; }

		virtual void load(std::unique_ptr<LoaderParams> params, Vector2D heading)
		{
			ShooterObject::load(std::move(params));
			_heading = heading;
		}//load

		virtual void draw()
		{
			ShooterObject::draw();
		}//draw

		virtual void collision()
		{
			_dead = true;
		}//collision

		virtual void update()
		{
			_velocity.setX(_heading.getX());
			_velocity.setY(_heading.getY());

			ShooterObject::update();
		}//update

		virtual void clean()
		{
			ShooterObject::clean();
		}//clean

	private:
		Vector2D _heading;
	};
}