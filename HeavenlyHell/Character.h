#pragma once

namespace Model
{
	class Character
	{
	public:
		Character(void);
		~Character(void);

		unsigned int getX();
		unsigned int getY();

		void setX(unsigned int x);
		void setY(unsigned int y);

	private:
		unsigned int _x;
		unsigned int _y;
	};
}