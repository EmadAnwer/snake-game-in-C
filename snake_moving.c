#include "snake.h"

/**
 * playing_area - print Game over
 */

void move_forward(char (*game_area)[COLUMNS], snake_t *snake, position_t *food)
{
	snake_node_t *current;

	current = snake->tail;
	while (current->prev)
	{
		current->position.x = current->prev->position.x;
		current->position.y = current->prev->position.y;
		current = current->prev;
	}
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
		increase_snake(game_area, snake);
		render_food(game_area, food);
	}
	

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
	new_snake->position.x = snake->tail->position.x;
	new_snake->position.y = snake->tail->position.y;
	new_snake->prev = snake->tail;
	snake->tail->next = new_snake;
	new_snake->next = NULL;
	
	snake->tail = new_snake;
}
