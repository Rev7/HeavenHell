#include "HHEngine.h"
#include "Tools.h"
#include <Windows.h>
#include <stdio.h>

using namespace SDLEngine;
using namespace Tools;

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

	// Initialisation de la fen�tre principale
	hhEngine->init("Chapter 1", 100, 100, 640, 480, /*fullscreen=*/false);
	
	// Boucle principale
	while (hhEngine->isRunning())
	{
		hhEngine->handleEvents();
		hhEngine->update();
		hhEngine->render();
	}//while

	// Lib�ration SDL
	hhEngine->clean();

	// Lib�ration m�moire HHEngine
	HHTools::safeDelete(hhEngine);

	return 0;
}//main