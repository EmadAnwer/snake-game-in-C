#include "snake.h"

int main()
{
	char game_area[ROWS][COLUMNS];
	snake_node_t *head, *tail;
	position_t food;
	int i, j;
	food.x = 12;
	food.y = 15;
	
	
	head = initialize_game(game_area, food);
	tail = head->next;
	while (1)
	{
		system("clear");
		header(1, 1);
		playing_area(game_area, food);
		move_forward(game_area, head, tail);
		footer(IN_GAME);
		sleep(1);
	}
	return (0);
}
