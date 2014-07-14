#pragma once

#include "Tools.h"

namespace sdlEngine
{
	class Player;
	
	class HHEngine
	{
	public:
		static HHEngine* Instance()
		{
			if (NULL == _instance)
			{
				_instance = new HHEngine();
			}//if

			return _instance;
		}//Instance

		bool init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);

		void render();
		void update();
		void handleEvents();
		void clean();
		void quit();

		// Accesseurs
		bool running() const { return _running; }
		SDL_Renderer* getRenderer() const { return _mainRenderer; }
	
	private:
		HHEngine(void) {}
		~HHEngine(void) {}

		static HHEngine* _instance;

		SDL_Window* _mainWindow;
		SDL_Renderer* _mainRenderer;

		bool _running;

		Player* _player;
	};

	typedef HHEngine TheHHEngine;
}