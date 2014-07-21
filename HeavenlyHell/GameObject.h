#pragma once

namespace sdlEngine
{
	class LoaderParams;

	class GameObject
	{
	public:
		virtual void load(const LoaderParams* params) = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;

	protected:
		GameObject() {}
		virtual ~GameObject() {}
	};
}