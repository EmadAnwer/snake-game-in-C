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
			else if (input == '\033')  /*Escape key (27)*/ 
			{
				/*Read additional characters to capture the full escape sequence*/
				char sequence[2];
				if (read(STDIN_FILENO, sequence, 2) == 2)
				{
					if (sequence[0] == '[')
					{
						if (sequence[1] == 'A' && snake->direction != DOWN)  /*Up Arrow*/ 
						{
							snake->direction = UP;
						}
						else if (sequence[1] == 'B' && snake->direction != UP)  /*Down Arrow*/
						{
							snake->direction = DOWN;
						}
						else if (sequence[1] == 'D' && snake->direction != RIGHT)  /*Left Arrow*/
						{
							snake->direction = LEFT;
						}
						else if (sequence[1] == 'C' && snake->direction != LEFT)  /*Right Arrow*/ 
						{
							snake->direction = RIGHT;
						}
					}
				}
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
	return NULL;
}
