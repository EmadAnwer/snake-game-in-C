#include "snake.h"

/**
 * footer - print Game footer
 * @mode: game mode
 */
void footer(int mode)
{
	printf(LINE);
	if (mode == IN_GAME)
		printf("*                 In Game                *\n");
	else if (mode == GAME_OVER)
		printf("*                Game Over               *\n");
	printf(LINE);
}
