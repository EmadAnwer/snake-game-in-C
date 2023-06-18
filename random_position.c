#include "snake.h"
/**
 * random_position - get a random pos between min and max
 * @min: min point
 * @max: max point
 * Return: random position
 */
int random_position(int min, int max)
{
	srand(time(NULL));
	return min + rand() % (max - min + 1);
}
/**
 * render_food - get a random pos between min and max
 * @game_area: 2D array of the game
 */
void render_food(char (*game_area)[COLUMNS], position_t *food)
{
	int random_x = random_position(0, ROWS - 1), random_y = random_position(0,COLUMNS - 1);
	while (game_area[random_x][random_y] != ' ')
	{
		random_x = random_position(0, ROWS - 1);
		random_y = random_position(0, COLUMNS - 1);
	}
	food->x = random_x;
	food->y = random_y;
	game_area[food->x][random_y] = '$';
}
