#include "HHEngine.h"

using namespace tools;

namespace sdlEngine
{
	//---------------------------------------------------------------------------
	HHEngine::HHEngine(void):
		running(false),
		mainWindow(NULL),
		mainRenderer(NULL)
	{
	}//HHEngine
	//---------------------------------------------------------------------------

	HHEngine::~HHEngine(void)
	{
	}//~HHEngine
	//---------------------------------------------------------------------------

	bool HHEngine::init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)
	{
		// Initialisation SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "SDL init success\n";

			int flags = 0;
			if (fullScreen)
			{
				flags = SDL_WINDOW_FULLSCREEN;
			}//if

			// Initialisation de la fen�tre
			mainWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
			if (mainWindow != NULL)
			{
				// Fen�tre initialis�e
				std::cout << "window creation success\n";

				// Initialisation du rendu
				mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);
				if (mainRenderer != NULL)
				{
					// Rendu initialis�
					std::cout << "renderer creation success\n";
					
					SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 0);
				}//if
				else
				{
					// Echec d'initialisation du rendu
					std::cout << "### renderer init fail\n";
					Tools::logSDLError(std::cout, "SDL_CreateRenderer");
					return false;	// !!! !!! !!!
				}//else
			}
			else
			{
				// Echec d'initialisation de la fen�tre
				std::cout << "### window init fail\n";
				Tools::logSDLError(std::cout, "SDL_CreateWindow");
				return false;	// !!! !!! !!!
			}//else
		}//if
		else
		{
			// Echec d'initialisation SDL
			std::cout << "### SDL init fail\n";
			Tools::logSDLError(std::cout, "SDL_Init");
			return false;	// !!! !!! !!!
		}//else

		// Tout est initialis� correctement, d�marrage de la boucle principale
		std::cout << "init success\n";
		running = true;

		return true;

	}//init
	//--------------------------------------------------------------------------

	void HHEngine::render()
	{
		// Nettoyage du rendu
		SDL_RenderClear(mainRenderer);

		// Nouveau rendu
		SDL_RenderPresent(mainRenderer);
	}//render
	//-------------------------------------------------------------------------

	void HHEngine::handleEvents()
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			default:
				break;
			}//switch
		}//if
	}//handleEvents
	//-----------------------------------------------------------------------

	void HHEngine::clean()
	{
		std::cout << "cleaning game\n";

		SDL_DestroyWindow(mainWindow);
		SDL_DestroyRenderer(mainRenderer);
		SDL_Quit();
	}//clean
}