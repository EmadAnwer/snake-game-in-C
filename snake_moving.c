#include "snake.h"

/**
 * move_forward - move sanke step forword and check the step
 *				if food increase snake
 *				if border '*' game_over
 * @game_area: min point
 * @snake: snake pointer
 * @food: food pointer
 */
void move_forward(char (*game_area)[COLUMNS], snake_t *snake, position_t *food, int *points)
{
	snake_node_t *current;

	current = snake->tail;
	while (current->prev)
	{
		current->position.x = current->prev->position.x;
		current->position.y = current->prev->position.y;
		current = current->prev;
	}
	if (snake->direction == RIGHT)
		snake->head->position.y++;
	else if (snake->direction == LEFT)
		snake->head->position.y--;
	else if (snake->direction == UP)
		snake->head->position.x--;
	else if (snake->direction == DOWN)
		snake->head->position.x++;

	if (game_area[snake->head->position.x][snake->head->position.y] == '*' ||
			game_area[snake->head->position.x][snake->head->position.y] == '#')
	{
		footer(GAME_OVER);
		disableRawMode();
		exit(EXIT_SUCCESS);
	}
	else if (game_area[snake->head->position.x][snake->head->position.y] == '$')
	{
		increase_snake(game_area, snake, points);
		render_food(game_area, food);
	}
}
/**
 * increase_snake - add new node at the end of the snake
 * @game_area: 2D array of the game
 * @snake: snake pointer
 */
void increase_snake(char (*game_area)[COLUMNS], snake_t *snake, int *points)
{
	snake_node_t *new_snake;

	new_snake = malloc(sizeof(snake_node_t));
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

	(*points)++;
}
