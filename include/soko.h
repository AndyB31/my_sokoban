/*
** EPITECH PROJECT, 2017
** soko.h
** File description:
** header sokoban
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

#ifndef SOKO
#define SOKO

//struct for the position of case
typedef struct case_pos {
	int id;
	posi_t pos;
	struct case_pos *next;
}case_t;

//struct for the position of goal
typedef struct goal_pos {
	int id;
	posi_t pos;
	struct goal_pos *next;
}goal_t;

//struct for the map with the position of player (pos_P)
typedef struct map_info {
	int rows;
	int cols;
	int nbr_O;
	int nbr_X;
	posi_t pos_P;
	char *pathname;
	struct case_pos *head;
	struct goal_pos *ghead;
	char **map;
}map_t;

void restart(map_t *MAP);
int game_loop(map_t *MAP);
int check_window(map_t *MAP);
void display_map(map_t *MAP);
void free_all(map_t *MAP);
void *my_malloc(size_t size);
int ui_manager(int ch, map_t *MAP);
void check_goal(map_t *MAP);
case_t *find_case(posi_t pos, case_t *head);
void move_down(map_t *MAP);
void move_right(map_t *MAP);
void move_left(map_t *MAP);
void move_up(map_t *MAP);
int my_print_map(char *pathname);
void check_case(map_t *MAP);
void my_obj(map_t *MAP);
void add_case(map_t *MAP, int i, int j);
void map_len(char *pathname, int *res_col, int *res_row);
char **alloc_2d(int, int);
void my_map(char *pathname, map_t *MAP);

#endif