#pragma once

#include "ShooterObject.h"
#include <string>

namespace sdlEngine
{
	class Enemy : public ShooterObject
	{
	public:
		virtual std::string type() { return "Enemy"; }

	protected:
		Enemy() : ShooterObject() {}
		virtual ~Enemy() {}

		int _health;
	};
}