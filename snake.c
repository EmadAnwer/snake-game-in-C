#include "snake.h"
/**
 * main - Entry point of the program
 *
 * Return: 0 on success, non-zero value on failure
 */
int main(void)
{
	char game_area[ROWS][COLUMNS];
	snake_t *snake;
	position_t *food;
	int i, j;

	food = malloc(sizeof(position_t));
	food->x = 4;
	food->y = 20;

	snake = initialize_game(game_area);
	while (1)
	{
		system("clear");
		header(1, 1);
		playing_area(game_area, snake, food);
		move_forward(game_area, snake, food);
		footer(IN_GAME);
		sleep(1);
	}
	return (0);
}
