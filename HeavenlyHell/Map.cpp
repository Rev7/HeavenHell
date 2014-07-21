#include "Map.h"
#include "Tile.h"

namespace Model{

	Map::Map(unsigned int rows, unsigned int cols)
	{			
		unsigned int row_count = (rows < MAX_ROWS) ? rows : MAX_ROWS;
		unsigned int col_count = (cols < MAX_COLS) ? cols : MAX_COLS;

		// Construction de la Map
		for (unsigned int i = 0; i < row_count; ++i)
		{
			std::vector<Tile> current_row = std::vector<Tile>();

			for (unsigned int j = 0; j < col_count; ++j) 
			{
				// Index de la tile
				unsigned int tileIndex = i * col_count + j;
				
				Tile cell = Tile(tileIndex);
				current_row.push_back(cell);
			}

			_tiles.push_back(current_row);

		}
	}
	//--------------------------------------------------------------------------

	Map::~Map(void) {}
	//--------------------------------------------------------------------------

}
