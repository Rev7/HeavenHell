#pragma once

#include <iostream>
#include <string>
#include <map>
#include "SDL2\SDL.h"
#include "SDL2\SDL_image.h"

#define SAFE_DELETE(x)			{ if (x != NULL) { delete x; x = NULL; } }
#define SAFE_DELETE_ARRAY(x)	{ if (x != NULL) { delete[] x; x = NULL; } }

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
		//--------------------------------------------------------------------------

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