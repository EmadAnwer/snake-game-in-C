#include "snake.h"

/**
 * playing_area - print Game over
 */

void move_forward(char (*game_area)[COLUMNS], snake_t *snake)
{
	position_t food;
	position_t old_tail;
	snake_node_t new_node;

	old_tail.x = snake->tail->position.x;
	old_tail.y = snake->tail->position.y;
	game_area[old_tail.x][old_tail.y] = ' ';
	snake->tail->position.y = snake->tail->prev->position.y;
	snake->tail->position.x = snake->tail->prev->position.x;
	game_area[snake->head->position.x][snake->head->position.y] = '#';
	if(snake->dircation == RIGHT)
		snake->head->position.y++;
	else if (snake->dircation == LEFT)
		snake->head->position.y--;
	else if (snake->dircation == UP)
		snake->head->position.x--;
	else if (snake->dircation == DOWN)
		snake->head->position.x++;
	
	if(game_area[snake->head->position.x][snake->head->position.y] == '*')
	{
		footer(GAME_OVER);
		exit(EXIT_SUCCESS);
	}
	else if(game_area[snake->head->position.x][snake->head->position.y] == '$')
	{
		game_area[old_tail.x][old_tail.y] = '#';
		snake->tail->position.y = old_tail.y;
		snake->tail->position.x = old_tail.x;
		food.x = snake->head->position.x;
		food.y = snake->head->position.y;
		increase_snake(game_area, snake);
		render_food(game_area, food);
	}
	game_area[snake->head->position.x][snake->head->position.y] = 'O';
	
	
	
	

}

void increase_snake(char (*game_area)[COLUMNS], snake_t *snake)
{
	snake_node_t *new_snake;

	new_snake= malloc(sizeof(snake_node_t));
	if (new_snake == NULL)
	{
		/*TODO Free snake function*/
		free(snake);
		perror("can't initialize a head");
		exit(EXIT_FAILURE);
	}
	/*position level*/
	new_snake->position.x = snake->head->position.x;
	new_snake->position.y = snake->head->position.y;
	/*linked list level*/
	new_snake->next = snake->head;
	new_snake->prev = snake->head->prev;
	snake->head->prev = new_snake;

	/*ui level*/
	game_area[snake->tail->position.x][snake->tail->position.y] = '#';
}
