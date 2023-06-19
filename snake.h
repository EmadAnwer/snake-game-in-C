#ifndef SNAKE_H
#define SNAKE_H
#define ROWS 17
#define COLUMNS 44
#define LINE "******************************************\n"
#define IN_GAME 1
#define GAME_OVER 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <pthread.h>
#include <string.h>
/*directions*/
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

/**
 * struct snake_node_s - represent each node in snake
 * @position: snake head
 * @next: snake next node
 * @prev: snake prev node
 */
typedef struct snake_node_s
{
	position_t position;
	struct snake_node_s *next;
	struct snake_node_s *prev;
} snake_node_t;
/**
 * struct snake_s - represent snake
 * @dircation: snake dircation
 * @head: snake head node
 * @tail: snake tail node
 */
typedef struct snake_s
{
	int direction;
	snake_node_t *head;
	snake_node_t *tail;
} snake_t;
void print_playing_area_array(char (*game_area)[COLUMNS]);
void clean_playing_area_array(char (*game_area)[COLUMNS]);
void render_food(char (*game_area)[COLUMNS], position_t *food);
void header(int points, int level);
void playing_area(char (*game_area)[COLUMNS], snake_t *snake, position_t *food);
snake_t *initialize_game(char (*game_area)[COLUMNS]);
void increase_snake(char (*game_area)[COLUMNS], snake_t *snake, int *points);
void footer(int mode);
void move_forward(char (*game_area)[COLUMNS], snake_t *snake, position_t *food, int *points);
void free_snake(snake_t *snake);
/*---------termenal---------*/
void enableRawMode();
void disableRawMode();
/*---------keys---------*/
void* handleKeyPress(void* arg);
#endif
