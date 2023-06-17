#include "snake.h"

/**
 * playing_area - print Game over
 */

void move_forward(char (*game_area)[COLUMNS], snake_node_t *head, snake_node_t *tail)
{
	game_area[tail->position.x][tail->position.y] = ' ';
	tail->position.y = tail->prev->position.y;
	tail->position.x = tail->prev->position.x;
	game_area[head->position.x][head->position.y] = '#';
	if(head->dircation == RIGHT)
		head->position.y++;
	else if (head->dircation == LEFT)
		head->position.y--;
	else if (head->dircation == UP)
		head->position.x--;
	else if (head->dircation == DOWN)
		head->position.x++;
	game_area[head->position.x][head->position.y] = 'O';
	

	
	

}
