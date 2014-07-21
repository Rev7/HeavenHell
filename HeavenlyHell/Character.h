#pragma once

namespace Model
{
	class Character
	{
	public:

		// Getters
		unsigned int getTileIndex() const { return _tileIndex; }

		// Déplacement du personnage
		void moveTo(unsigned int newIndex) { _tileIndex = newIndex; };

		Character(unsigned int n);
		~Character(void);

	private:
		// Identifiant unique du personnage
		static unsigned int _id;

		// Fonction static retournant un identifiant unique
		static unsigned int _getId() { return _id++; }

		// Index de la tile sur laquelle le personnage se trouve
		unsigned int _tileIndex;
	
	};
}