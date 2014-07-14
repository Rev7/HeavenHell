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
		/// Lib�ration m�moire
		/// </summary>
		/// <param name="ptr">L'objet � lib�rer</param>
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
		/// Lib�ration m�moire tableau
		/// </summary>
		/// <param name="ptr">L'objet tableau � lib�rer</param>
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