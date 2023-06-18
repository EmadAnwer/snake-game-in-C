#include "snake.h"

int main()
{
	char game_area[ROWS][COLUMNS];
	snake_t *snake;
	position_t food;
	int i, j;
	
	food.x = 4;
	food.y = 17;	
	snake = initialize_game(game_area, food);
	/*set food position*/
	game_area[food.x][food.y] = '$';
	while (1)
	{
		system("clear");
		header(1, 1);
		
		playing_area(game_area, snake);
		move_forward(game_area, snake);
		footer(IN_GAME);
		sleep(1);
	}
	return (0);
}
