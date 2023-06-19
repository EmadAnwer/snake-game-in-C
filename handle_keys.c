#include "snake.h"
/**
 * handleKeyPress - handel the keys to control the snake
 * @arg: void pointer that will point to the snake to change directions
 */
void* handleKeyPress(void* arg)
{
	snake_t *snake = (snake_t *)arg;

	while (1)
	{
		char input;
		if (read(STDIN_FILENO, &input, 1) == 1)
		{
			if (input == 'q')
			{
				break;
			}
			else if (input == 'w' && snake->direction != DOWN)
			{
				snake->direction = UP;
			}
			else if (input == 's' && snake->direction != UP)
			{
				snake->direction = DOWN;
			}
			else if (input == 'a' && snake->direction != RIGHT)
			{
				snake->direction = LEFT;
			}
			else if (input == 'd' && snake->direction != LEFT)
			{
				snake->direction = RIGHT;
			}
		}
	}
	return (NULL);
}
