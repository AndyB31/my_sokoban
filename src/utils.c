/*
** EPITECH PROJECT, 2017
** utils
** File description:
** utils for sokoban
*/

#include <stdlib.h>
#include "soko.h"

char **alloc_2d(int rows, int cols)
{
	char **res = malloc(sizeof(char *) * (rows + 1));

	if (res == NULL)
		exit(84);
	for (int i = 0; i < rows + 1; i++) {
		res[i] = malloc(sizeof(char) * (cols + 1));
		if (res[i] == NULL)
			exit(84);
		my_init(res[i], cols + 1);
	}
	return (res);
}

void check_player(map_t *MAP)
{
	int i = 0;
	int j = 0;

	MAP->nbr_X = 0;
	while (i < MAP->rows) {
		if (MAP->map[i][j] == 'P') {
			MAP->pos_P.x = i;
			MAP->pos_P.y = j;
			return;
		}
		j++;
		if (j >= MAP->cols) {
			i++;
			j = 0;
		}
	}
	exit (84);
}

void check_map(map_t *MAP)
{
	posi_t i = {.x = 0, .y = 0};
	int j = 0;
	char *test = "P OX#\n";

	while (i.x < MAP->rows) {
		while (test[j] && MAP->map[i.x][i.y] != test[j]) {
			j++;
		}
		if (test[j] == '\0' && MAP->map[i.x][i.y] != '\0') {
			free_all(MAP);
			exit(84);
		}
		j = 0;
		i.y++;
		if (i.y >= MAP->cols) {
			i.x++;
			i.y = 0;
		}
	}
}

void my_obj(map_t *MAP)
{
	check_map(MAP);
	check_case(MAP);
	check_goal(MAP);
	check_player(MAP);
}

int ui_manager(int ch, map_t *MAP)
{
	int tab[7] = {' ', KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,
		KEY_BACKSPACE, 0};
	void (*ptr[5])(map_t *) = {&restart, &move_up, &move_down,
		&move_left, &move_right};
	int i = 0;

	while (i < 7 && tab[i] != ch)
		i++;
	if (i >= 7)
		return (0);
	if (tab[i] == 0 || i == 5)
		return (1);
	(ptr[i])(MAP);
	return (0);
}