#include "Character.h"

namespace Model
{
	unsigned int Character::_id = 0;	// identifiant d'un personnage
	
	Character::Character(unsigned int tileIndex) 
	{
		_id = Character::_getId();
		_tileIndex = tileIndex;
	}
	//--------------------------------------------------------------------------
	
	Character::~Character(void) { }
	//--------------------------------------------------------------------------

}

/* TODO:
 - Implémenter le déplacement d'un perso
 - Modifier l'identification d'une case (x&y --> n)
 - Algorithme de plus court chemin
*/