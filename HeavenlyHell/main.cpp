#include "HHEngine.h"
#include <Windows.h>

using namespace sdlEngine;
using namespace tools;

HHEngine* hhEngine = NULL;

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
	
	// Instanciation HHEngine
	hhEngine = new HHEngine();

	// Initialisation de la fenêtre principale
	hhEngine->init("Heavenly Hell", 100, 100, 640, 480, /*fullscreen=*/false);
	
	// Boucle principale
	while (hhEngine->isRunning())
	{
		hhEngine->handleEvents();
		hhEngine->update();
		hhEngine->render();

		SDL_Delay(10);
	}//while

	// Libération SDL
	hhEngine->clean();

	// Libération mémoire HHEngine
	//Tools::safeDelete(hhEngine);
	SAFE_DELETE(hhEngine);

	return 0;
}//main