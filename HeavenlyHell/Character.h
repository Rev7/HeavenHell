#pragma once

namespace Model
{
	class Character
	{
	public:
		Character(unsigned int x, unsigned int y);
		~Character(void);

		unsigned int getX() const { return _x; };
		unsigned int getY() const { return _y; };

		void setX(unsigned int x) { _x = x; };
		void setY(unsigned int y) { _y = y; };

	private:
		static unsigned int _id;

		// Fonction static retournant un identifiant unique
		static unsigned int _getId() { return _id++; }

		unsigned int _x;
		unsigned int _y;
	
	};
}