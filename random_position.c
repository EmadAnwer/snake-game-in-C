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
void render_food(char (*game_area)[50])
{
	int random_x = random_position(0, 14), random_y = random_position(0,43);

	while (game_area[random_x][random_y] != ' ')
	{
		random_x = random_position(0, 14);
		random_y = random_position(0,43);
	}
	game_area[random_x][random_y] = '$';
}
