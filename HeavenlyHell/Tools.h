#pragma once

#include <iostream>
#include <string>
#include "SDL2\SDL.h"

namespace tools
{
	class Tools
	{
	public:

		/// <summary>
		/// Logger d'erreur SDL
		/// </summary>
		/// <param name="os">Sortie standard</param>
		/// <param name="msg">Message</param>
		static void logSDLError(std::ostream &os, const std::string &msg)
		{
			os << "### ERROR " << msg << ": " << SDL_GetError() << std::endl;
		}//logSDLError

		//--------------------------------------------------------------------------

		/// <summary>
		/// Libération mémoire
		/// </summary>
		/// <param name="ptr">L'objet à libérer</param>
		template<typename T>
		static void safeDelete(T*& ptr)
		{
			if (ptr != NULL)
			{
				delete ptr;
				ptr = NULL;
			}//if			
		}//safeDelete

		//--------------------------------------------------------------------------

		/// <summary>
		/// Libération mémoire tableau
		/// </summary>
		/// <param name="ptr">L'objet tableau à libérer</param>
		template <typename T>
		static void safeDeleteArray(T*& ptr)
		{
			if (ptr != NULL)
			{
				delete[] ptr;
				ptr = NULL;
			}//if
		}//safeDeleteArray
	};
}