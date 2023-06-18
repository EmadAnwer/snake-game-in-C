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
	int i, j, points = 0;
	pthread_t keyThread;

	enableRawMode();
	food = malloc(sizeof(position_t));
	food->x = 4;
	food->y = 20;

	snake = initialize_game(game_area);
	pthread_create(&keyThread, NULL, handleKeyPress, snake);
	while (1)
	{
		system("clear");
		header(points, 1);
		playing_area(game_area, snake, food);
		move_forward(game_area, snake, food, &points);
		footer(IN_GAME);
		usleep(300000);
	}
	pthread_join(keyThread, NULL);
	disableRawMode();
	return (0);
}
