#include "snake.h"

int main()
{
	char game_area[COLUMNS][ROWS + 1];
	int i, j;
	initialize_game_area(game_area);
	while (1)
	{
		system("clear");
		header(1, 1);
		for (i = 0; i < COLUMNS; i++)
			for (j = 0; j < ROWS; j++)
				printf("%c", game_area[i][j]);

		footer(IN_GAME);
		sleep(1);
	}
	return (0);
}
