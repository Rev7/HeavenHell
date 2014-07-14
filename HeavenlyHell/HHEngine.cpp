#include "HHEngine.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Player.h"
#include "LoaderParams.h"

using namespace tools;

namespace sdlEngine
{
	HHEngine* HHEngine::_instance = NULL;

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
			_mainWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
			if (_mainWindow != NULL)
			{
				// Fen�tre initialis�e
				std::cout << "Window creation success\n";

				// Initialisation du rendu
				_mainRenderer = SDL_CreateRenderer(_mainWindow, -1, 0);
				if (_mainRenderer != NULL)
				{
					// Rendu initialis�
					std::cout << "Renderer creation success\n";
					
					SDL_SetRenderDrawColor(_mainRenderer, 0, 0, 0, 0);

					// Chargement des textures
					if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", _mainRenderer))
					{
						std::cout << "### Texture load fail\n";
						return false;	// !!! !!! !!!
					}//if

					// Initialisation des Joysticks
					TheInputHandler::Instance()->initialiseJoysticks();

					// TEST : chargement d'un gameObject
					_player = new Player(new LoaderParams(100, 100, 128, 82, "animate"));
				}//if
				else
				{
					// Echec d'initialisation du rendu
					std::cout << "### Renderer init fail\n";
					Tools::logSDLError(std::cout, "SDL_CreateRenderer");
					return false;	// !!! !!! !!!
				}//else
			}
			else
			{
				// Echec d'initialisation de la fen�tre
				std::cout << "### Window init fail\n";
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
		std::cout << "Init success\n";
		_running = true;

		return true;
	}//init
	//---------------------------------------------------------------------------

	void HHEngine::render()
	{
		// Nettoyage du rendu
		SDL_RenderClear(_mainRenderer);

		// ...
		_player->draw();

		// Nouveau rendu
		SDL_RenderPresent(_mainRenderer);
	}//render
	//---------------------------------------------------------------------------

	void HHEngine::update()
	{
		_player->update();
	}//update
	//---------------------------------------------------------------------------

	void HHEngine::handleEvents()
	{
		TheInputHandler::Instance()->update();
	}//handleEvents
	//---------------------------------------------------------------------------

	void HHEngine::clean()
	{
		std::cout << "Cleaning game\n";

		TheInputHandler::Instance()->clean();

		SDL_DestroyWindow(_mainWindow);
		SDL_DestroyRenderer(_mainRenderer);
		SDL_Quit();
	}//clean
	//---------------------------------------------------------------------------

	void HHEngine::quit()
	{
		_running = false;
	}//quit
}