#include "snake.h"
/**
 * enableRawMode - enable non bloking mode
 */
void enableRawMode()
{
	struct termios raw;
	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
/**
 * disableRawMode - reset the termenal mode
 */
void disableRawMode()
{
	struct termios raw;
	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag |= ICANON | ECHO;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
