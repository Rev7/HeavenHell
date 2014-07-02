#include "HHEngine.h"
#include <iostream>

//---------------------------------------------------------------------------

HHEngine::HHEngine(void)
{
}//HHEngine

HHEngine::~HHEngine(void)
{
}//~HHEngine

//---------------------------------------------------------------------------

bool HHEngine::init(const char* p_szTitle, int p_iXpos, int p_iYpos, int p_iWidth, int p_iHeight, bool p_bFullScreen)
{
	// Initialisation SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";

		int l_iFlags = 0;
		if (p_bFullScreen)
		{
			l_iFlags = SDL_WINDOW_FULLSCREEN;
		}//if

		// Initialisation de la fenêtre
		m_pWindow = SDL_CreateWindow(p_szTitle, p_iXpos, p_iYpos, p_iWidth, p_iHeight, l_iFlags);
		if (m_pWindow != 0) 
		{
			// Fenêtre initialisée
			std::cout << "window creation success\n";

			// Initialisation du rendu
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) 
			{
				// Rendu initialisé
				std::cout << "renderer creation success\n";

				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}//if
			else
			{
				// Echec d'initialisation du rendu
				std::cout << "### renderer init fail\n";
				return false;	// !!! !!! !!!
			}//else
		}
		else
		{
			// Echec d'initialisation de la fenêtre
			std::cout << "### window init fail\n";
			return false;	// !!! !!! !!!
		}//else
	}//if
	else
	{
		// Echec d'initialisation SDL
		std::cout << "### SDL init fail\n";
		return false;	// !!! !!! !!!
	}//else

	// Tout est initialisé correctement, démarrage de la boucle principale
	std::cout << "init success\n";
	m_bRunning = true;

	return true;
	
}//init
//--------------------------------------------------------------------------

void HHEngine::render()
{
	// Nettoyage du rendu
	SDL_RenderClear(m_pRenderer);

	// Nouveau rendu
	SDL_RenderPresent(m_pRenderer);
}//render
//-------------------------------------------------------------------------

void HHEngine::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				m_bRunning = false;
				break;

			default:
				break;
		}//Switch
	}//if
}//handleEvents
//-----------------------------------------------------------------------

void HHEngine::clean()
{
	std::cout << "cleaning game\n";

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}//clean
