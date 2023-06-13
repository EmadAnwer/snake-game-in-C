#include "snake.h"

/**
 * playing_area - print Game over
 */
void playing_area(char **game_area, snake_t snake, position_t food)
{
	/*set food position*/
	game_area[food.x][food.y] = '$';

}

/**
 * initialize_game_area - initialize game_area pointer with spaces
 *						  and create border
 * @game_area: 2D array pointer
 */
void initialize_game_area(char (*game_area)[ROWS + 1])
{
	int i, j;

	for (i = 0; i < COLUMNS; i++)
		for (j = 0; j <= ROWS; j++)
		{
			if(j == ROWS - 1)
				game_area[i][j] = '\0';
			else if(j == ROWS -2)
				game_area[i][j] = '\n';
			else if(j == 0 || j == ROWS -3)
				game_area[i][j] = '*';
			else
				game_area[i][j] = ' ';
		}
			
}
