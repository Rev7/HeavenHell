#pragma once

#include <string>
#include <vector>

namespace sdlEngine
{
	class GameState
	{
	public:
		virtual void update() = 0;
		virtual void render() = 0;

		virtual bool onEnter() = 0;
		virtual bool onExit() = 0;

		virtual std::string getStateID() const = 0;

	protected:
		std::vector<std::string> _textureIDList;
	};
}