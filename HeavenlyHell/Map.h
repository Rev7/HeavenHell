#pragma once

#include <vector>

namespace Model
{
	class Tile;

	class Map
	{
	public:
		static const int MAX_ROWS = 10;
		static const int MAX_COLS = 10;
	
		Map(unsigned int rows, unsigned int cols);
		~Map(void);

	private:
		std::vector<std::vector<Tile>> _tiles;
	};
}
