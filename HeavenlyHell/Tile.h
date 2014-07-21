#pragma once

namespace Model
{
	class Tile
	{
	public:
		Tile(unsigned int index);
		~Tile(void);

		// Getters & Setters
		unsigned int getIndex() const { return _index; };
		void setIndex(unsigned int index) { _index = index; };

	private:
		unsigned int _index;
	};

}

