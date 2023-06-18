#include "snake.h"

/**
 * playing_area - print Game over
 */
void playing_area(char (*game_area)[COLUMNS], snake_t *snake)
{
	int i, j;

	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLUMNS; j++)
			printf("%c", game_area[i][j]);
}

/**
 * initialize_game_area - initialize game_area pointer with spaces
 *						  and create border
 * @game_area: 2D array pointer
 */
snake_t *initialize_game(char (*game_area)[COLUMNS], position_t food)
{
	int i, j;
	snake_t *snake;
	snake = malloc(sizeof(snake_t));
	if (snake == NULL)
	{
		perror("can't initialize a snake");
		exit(EXIT_FAILURE);
	}
	snake->head = malloc(sizeof(snake_node_t));
	if (snake->head == NULL)
	{
		free(snake);
		perror("can't initialize a head");
		exit(EXIT_FAILURE);
	}
	snake->tail = malloc(sizeof(snake_node_t));
	if (snake->tail == NULL)
	{
		free(snake);
		perror("can't initialize a tail");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < ROWS; i++)
		for (j = 0; j <= COLUMNS; j++)
		{
			if(j == COLUMNS - 1)
				game_area[i][j] = '\0';
			else if(j == COLUMNS - 2)
				game_area[i][j] = '\n';
			else if(j == 0 || j == COLUMNS - 3)
				game_area[i][j] = '*';
			else
				game_area[i][j] = ' ';
		}
	/*        #O      */
	snake->dircation = RIGHT;
	snake->head->next = snake->tail;
	snake->tail->prev = snake->head;
	snake->tail->next = NULL;
	snake->head->prev = NULL;
	snake->head->position.x = 4;
	snake->head->position.y = 15;
	snake->tail->position.x = 4;
	snake->tail->position.y = 14;
	game_area[snake->head->position.x][snake->head->position.y] = 'O';
	game_area[snake->tail->position.x][snake->tail->position.y] = '#';
	
	return (snake);
}
