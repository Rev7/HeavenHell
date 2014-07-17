#include "Character.h"

namespace Model
{
	unsigned int Character::_id = 0;	// identifiant d'un personnage
	
	Character::Character(unsigned int x, unsigned int y) 
	{
		_id = Character::_getId();
		_x = x;
		_y = y;
	}
	//--------------------------------------------------------------------------
	
	Character::~Character(void) { }
	//--------------------------------------------------------------------------

}