/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** free all
*/

#include "soko.h"

void free_2d(char **map)
{
	int i = 0;

	if (map == NULL)
		return;
	while (map[i])
		free(map[i++]);
	free(map);
}

void restart(map_t *MAP)
{
	int ret = 0;
	char *path = MAP->pathname;

	free_all(MAP);
	endwin();
	ret = my_print_map(path);
	endwin();
	exit (ret);
}

void free_goal(goal_t *list)
{
	if (list->next != NULL)
		free_goal(list->next);
	free(list);
}

void free_case(case_t *list)
{
	if (list->next != NULL)
		free_case(list->next);
	free(list);
}

void free_all(map_t *MAP)
{
	if (MAP == NULL)
		return;
	if (MAP->ghead)
		free_goal(MAP->ghead);
	if (MAP->head)
		free_case(MAP->head);
	free_2d(MAP->map);
	free(MAP);
}