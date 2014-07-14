#include "HHEngine.h"
#include "Tools.h"
#include <Windows.h>

using namespace sdlEngine;
using namespace tools;

const int FPS = 60;                     //!< fps cible
const int DELAY_TIME = 1000.0f / FPS;   //!< Intervalle en ms pour obtenir le fps cible

int main(int argc, char* argv[])
{
	// Activation console (pour DEBUG seulement) ---
	if (AllocConsole()) 
	{
		FILE* stream;
		freopen_s(&stream, "CON", "w", stdout);
		SetConsoleTitle("Debug Console");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}//if
	// ---

	Uint32 frameStart, frameTime;

	// Initialisation de la fenêtre principale
	if (TheHHEngine::Instance()->init("Heavenly Hell", 100, 100, 640, 480, /*fullscreen=*/false))
	{
		std::cout << "Game init success!\n";
		
		// Boucle principale
		while (TheHHEngine::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheHHEngine::Instance()->handleEvents();
			TheHHEngine::Instance()->update();
			TheHHEngine::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}//if
		}//while
	}//if
	else
	{
		std::cout << "### Game init failure - " << SDL_GetError() << "\n";
		return -1;
	}//else

	// Fermeture du jeu
	std::cout << "Game closing...\n";
	TheHHEngine::Instance()->clean();

	return 0;
}//main