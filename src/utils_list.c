/*
** EPITECH PROJECT, 2017
** utils
** File description:
** utils for sokoban
*/

#include <stdlib.h>
#include "soko.h"

void add_case(map_t *MAP, int i, int j)
{
	case_t *current = my_malloc(sizeof(case_t));
	case_t *temp = MAP->head;

	current->pos.x = i;
	current->pos.y = j;
	current->next = NULL;
	if (MAP->head == NULL) {
		current->id = 1;
		MAP->head = current;
	} else {
		while (temp->next)
			temp = temp->next;
		current->id = temp->id + 1;
		temp->next = current;
	}
}

void check_case(map_t *MAP)
{
	int i = 0;
	int j = 0;

	MAP->nbr_X = 0;
	while (i < MAP->rows) {
		if (MAP->map[i][j] == 'X') {
			MAP->nbr_X += 1;
			add_case(MAP, i, j);
		}
		j++;
		if (j >= MAP->cols) {
			i++;
			j = 0;
		}
	}
	if (MAP->nbr_X < 1)
		exit (84);
}

void add_goal(map_t *MAP, int i, int j)
{
	goal_t *current = my_malloc(sizeof(goal_t));
	goal_t *temp = MAP->ghead;

	current->pos.x = i;
	current->pos.y = j;
	current->next = NULL;
	if (MAP->ghead == NULL) {
		current->id = 1;
		MAP->ghead = current;
	} else {
		while (temp->next)
			temp = temp->next;
		current->id = temp->id + 1;
		temp->next = current;
	}
}

void check_goal(map_t *MAP)
{
	int i = 0;
	int j = 0;

	MAP->nbr_X = 0;
	while (i < MAP->rows) {
		if (MAP->map[i][j] == 'O') {
			MAP->nbr_O += 1;
			add_goal(MAP, i, j);
		}
		j++;
		if (j >= MAP->cols) {
			i++;
			j = 0;
		}
	}
	if (MAP->nbr_O < 1)
		exit (84);
}