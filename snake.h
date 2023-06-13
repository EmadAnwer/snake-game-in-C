#ifndef SNAKE_H
#define SNAKE_H

#define LINE "******************************************\n"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void header(int points, int level);
void render_food(char (*game_area)[]);
void game_over();

#endif
