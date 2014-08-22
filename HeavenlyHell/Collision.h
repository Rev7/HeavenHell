#pragma once

#include "Tools.h"

namespace sdlEngine
{
	class Collision
	{
	public:
		Collision(void) {}
		~Collision(void) {}

		const static int _buffer = 4;

		static bool RectRect(SDL_Rect* A, SDL_Rect* B)
		{
			int aHBuf = A->h / _buffer;
			int aWBuf = A->w / _buffer;

			int bHBuf = B->h / _buffer;
			int bWBuf = B->w / _buffer;

			// Partie inf de A plus basse que partie sup de B = pas de collision
			if ((A->y + A->h) - aHBuf <= B->y + bHBuf)
			{
				return false;
			}//if

			// Partie sup de A plus haute que partie inf de B = pas de collision
			if (A->y + aHBuf >= (B->y + B->h) - bHBuf)
			{
				return false;
			}//if

			// Partie droite de A éloignée de partie gauche de B = pas de collision
			if ((A->x + A->w) - aWBuf <= B->x + bWBuf)
			{
				return false;
			}//if

			// Partie gauche de A éloignée de partie droite de B = pas de collision
			if (A->x + aWBuf >= (B->x + B->w) - bWBuf)
			{
				return false;
			}//if

			return true;
		}//RectRect
	};
}