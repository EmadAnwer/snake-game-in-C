#include "snake.h"

/**
 * playing_area - print Game over
 */
void playing_area(char (*game_area)[COLUMNS], position_t food)
{
	int i, j;
	/*set food position*/
	game_area[food.x][food.y] = '$';

	for (i = 0; i < ROWS; i++)
			for (j = 0; j < COLUMNS; j++)
				printf("%c", game_area[i][j]);
}

/**
 * initialize_game_area - initialize game_area pointer with spaces
 *						  and create border
 * @game_area: 2D array pointer
 */
snake_node_t *initialize_game(char (*game_area)[COLUMNS], position_t food)
{
	int i, j;
	snake_node_t *head, *tail;

	head = malloc(sizeof(snake_node_t));
	if (head == NULL)
	{
		perror("can't initialize a snake node");
		exit(EXIT_FAILURE);
	}
	tail = malloc(sizeof(snake_node_t));
	if (tail == NULL)
	{
		free(head);
		perror("can't initialize a snake node");
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
	head->dircation = RIGHT;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
	head->prev = NULL;
	head->position.x = 4;
	head->position.y = 15;
	tail->position.x = 4;
	tail->position.y = 14;
	game_area[head->position.x][head->position.y] = 'O';
	game_area[tail->position.x][tail->position.y] = '#';
	

	return head;
}
