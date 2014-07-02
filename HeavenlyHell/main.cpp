#include "HHEngine.h"
#include <Windows.h>
#include <stdio.h>

HHEngine* g_HHEngine = NULL;

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
	
	g_HHEngine = new HHEngine();

	g_HHEngine->init("Chapter 1", 100, 100, 640, 480, false);
	
	while(g_HHEngine->running())
	{
		g_HHEngine->handleEvents();
		g_HHEngine->update();
		g_HHEngine->render();
	}//while

	g_HHEngine->clean();
	return 0;
}//main