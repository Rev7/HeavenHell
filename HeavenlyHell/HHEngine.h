#pragma once

#include "Tools.h"
#include "TextureManager.h"

using namespace textureManager;

namespace sdlEngine
{
	class HHEngine
	{
	private:
		bool running;

		SDL_Window*   mainWindow;
		SDL_Renderer* mainRenderer;

	public:
		HHEngine(void);
		~HHEngine(void);

		bool init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);

		void render();
		void update() {}
		void handleEvents();
		void clean();

		// Accesseurs
		bool isRunning() { return running; }
	};
}