#pragma once

#include <iostream>
#include "SDL2\SDL.h"

namespace Tools
{
	class HHTools
	{
	public:

		// Logger d'erreur SDL
		static void logSDLError(std::ostream &os, const std::string &msg)
		{
			os << "### ERROR " << msg.c_str() << ": " << SDL_GetError() << std::endl;
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



