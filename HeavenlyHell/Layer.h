#pragma once

namespace sdlEngine
{
	class Layer
	{
	public:
		virtual void update() = 0;
		virtual void render() = 0;

	protected:
		virtual ~Layer() {}
	};
}