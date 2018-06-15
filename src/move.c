/*
** EPITECH PROJECT, 2017
** utils
** File description:
** utils for sokoban
*/

#include <stdlib.h>
#include "soko.h"

int move_player(posi_t pos, char **map, posi_t sens, posi_t size)
{
	if (map[pos.x][pos.y] == '#')
		return (1);
	if (map[pos.x][pos.y] == 'X') {
		if (map[pos.x + sens.x][pos.y + sens.y] == 'X')
			return (1);
		if (map[pos.x + sens.x][pos.y + sens.y] == '#')
			return (1);
		if (pos.y + sens.y < 0 || pos.x + sens.x < 0)
			return (1);
		if (pos.y + sens.y > size.y || pos.x + sens.x > size.x)
			return (1);
		map[pos.x + sens.x][pos.y + sens.y] = 'X';
	}
	map[pos.x][pos.y] = 'P';
	map[pos.x - sens.x][pos.y - sens.y] = ' ';
	return (0);
}

void move_up(map_t *MAP)
{
	posi_t sens = {.x = -1, .y = 0};
	posi_t pos = {.x = MAP->pos_P.x - 1, .y = MAP->pos_P.y};
	posi_t size = {.x = MAP->rows, .y = MAP->cols};
	case_t *case_new = NULL;

	if (MAP->pos_P.x - 1 < 0)
		return;
	if (move_player(pos, MAP->map, sens, size))
		return;
	case_new = find_case(pos, MAP->head);
	if (case_new != NULL)
		case_new->pos.x = pos.x - 1;
	MAP->pos_P = pos;
}

void move_down(map_t *MAP)
{
	posi_t sens = {.x = 1, .y = 0};
	posi_t pos = {.x = MAP->pos_P.x + 1, .y = MAP->pos_P.y};
	posi_t size = {.x = MAP->rows, .y = MAP->cols};
	case_t *case_new = NULL;

	if (MAP->pos_P.x + 1 < 0)
		return;
	if (move_player(pos, MAP->map, sens, size))
		return;
	case_new = find_case(pos, MAP->head);
	if (case_new != NULL)
		case_new->pos.x = pos.x + 1;
	MAP->pos_P = pos;
}

void move_right(map_t *MAP)
{
	posi_t sens = {.y = 1, .x = 0};
	posi_t pos = {.x = MAP->pos_P.x, .y = MAP->pos_P.y + 1};
	posi_t size = {.x = MAP->rows, .y = MAP->cols};
	case_t *case_new = NULL;

	if (MAP->pos_P.y + 1 < 0)
		return;
	if (move_player(pos, MAP->map, sens, size))
		return;
	case_new = find_case(pos, MAP->head);
	if (case_new != NULL)
		case_new->pos.y = pos.y + 1;
	MAP->pos_P = pos;
}

void move_left(map_t *MAP)
{
	posi_t sens = {.y = -1, .x = 0};
	posi_t pos = {.x = MAP->pos_P.x, .y = MAP->pos_P.y - 1};
	posi_t size = {.x = MAP->rows, .y = MAP->cols};
	case_t *case_new = NULL;

	if (MAP->pos_P.y - 1 < 0)
		return;
	if (move_player(pos, MAP->map, sens, size))
		return;
	case_new = find_case(pos, MAP->head);
	if (case_new != NULL)
		case_new->pos.y = pos.y - 1;
	MAP->pos_P = pos;
}