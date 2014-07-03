#pragma once

#include <iostream>
#include <string>
#include "SDL2\SDL.h"

namespace tools
{
	class Tools
	{
	public:

		// Logger d'erreur SDL
		static void logSDLError(std::ostream &os, const std::string &msg)
		{
			os << "### ERROR " << msg << ": " << SDL_GetError() << std::endl;
		}//logSDLError

		// Libération mémoire
		static void safeDelete(void* object)
		{
			if (NULL == object)
			{
				delete object;
				object = NULL;
			}//if
		}//safeDelete
	};
}



