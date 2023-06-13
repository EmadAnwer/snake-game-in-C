#ifndef SNAKE_H
#define SNAKE_H
#define ROWS 44
#define COLUMNS 15
#define LINE "******************************************\n"
#define IN_GAME 1
#define GAME_OVER 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/**
 * struct position - place in x, y
 * @x: x axis
 * @y: y axis
 */
typedef struct position
{
	int x;
	int y;
} position_t;


/**
 * struct position - place in x, y
 * @head: snake head
 * @tail: snake tail
 * @tall: snake tall
 */
typedef struct snake
{
	position_t head;
	position_t tail;
	position_t next_tail;
	int tall;
} snake_t;

void header(int points, int level);
void render_food(char (*game_area)[]);
void game_over();

void playing_area(char **game_area, snake_t snake, position_t food);
void initialize_game_area(char (*arr)[ROWS + 1]);
void footer(int mode);
#endif
