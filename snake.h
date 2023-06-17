#ifndef SNAKE_H
#define SNAKE_H
#define ROWS 15
#define COLUMNS 44
#define LINE "******************************************\n"
#define IN_GAME 1
#define GAME_OVER 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*dircations*/
#define LEFT -1
#define RIGHT 1
#define UP 2
#define DOWN -2
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
/* New Start */

/**
 * struct position - place in x, y
 * @head: snake head
 * @tail: snake tail
 * @tall: snake tall
 */
typedef struct snake_node_s
{
	position_t position;
	int dircation;
	struct snake_node_s *next;
	struct snake_node_s *prev;
} snake_node_t;

void header(int points, int level);
void playing_area(char (*game_area)[COLUMNS], position_t food);
snake_node_t *initialize_game(char (*arr)[COLUMNS], position_t food);
void render_food(char (*game_area)[]);
void game_over();
void footer(int mode);
void move_forward(char (*game_area)[COLUMNS], snake_node_t *head, snake_node_t *tail);
#endif
