#pragma once

#include "GameState.h"
#include <vector>

namespace sdlEngine
{
	class MenuState : public GameState
	{
	protected:
		typedef void (*Callback)();
		virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

		std::vector<Callback> _callbacks;
	};
}