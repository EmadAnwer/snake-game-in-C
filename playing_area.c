#include "snake.h"

/**
 * playing_area - print Game area
 * @game_area: 2D array pointer
 * @snake: snake pointer
 * @food: food pointer
 */
void playing_area(char (*game_area)[COLUMNS], snake_t *snake, position_t *food)
{
	snake_node_t *current;

	clean_playing_area_array(game_area);
	game_area[food->x][food->y] = '$';
	game_area[snake->head->position.x][snake->head->position.y] = 'O';
	current = snake->head->next;
	while (current)
	{
		game_area[current->position.x][current->position.y] = '#';
		current = current->next;
	}
	print_playing_area_array(game_area);

}

/**
 * initialize_game - initialize game_area pointer with spaces and create border
 *
 * @game_area: 2D array pointer
 * Return: snake pointer
 */
snake_t *initialize_game(char (*game_area)[COLUMNS])
{
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

	snake->direction = RIGHT;
	snake->head->next = snake->tail;
	snake->tail->prev = snake->head;
	snake->tail->next = NULL;
	snake->head->prev = NULL;
	snake->head->position.x = 4;
	snake->head->position.y = 15;
	snake->tail->position.x = 4;
	snake->tail->position.y = 14;

	return (snake);
}
/**
 * print_playing_area_array - print Game area
 * @game_area: 2D array pointer
 */
void print_playing_area_array(char (*game_area)[COLUMNS])
{
	int i, j;

	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLUMNS; j++)
			printf("%c", game_area[i][j]);
}
/**
 * clean_playing_area_array - assign game area array
 * @game_area: 2D array pointer
 */
void clean_playing_area_array(char (*game_area)[COLUMNS])
{
	int i, j;

	strcpy(game_area[0], LINE);
	for (i = 1; i < ROWS - 1; i++)
		for (j = 0; j <= COLUMNS; j++)
		{
			if (j == COLUMNS - 1)
				game_area[i][j] = '\0';
			else if (j == COLUMNS - 2)
				game_area[i][j] = '\n';
			else if (j == 0 || j == COLUMNS - 3)
				game_area[i][j] = '*';
			else
				game_area[i][j] = ' ';
		}
	strcpy(game_area[ROWS - 1], LINE);
}
