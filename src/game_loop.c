/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** game_loop
*/

#include "soko.h"

void display_map(map_t *MAP)
{
	posi_t pos;

	for (int i = 0; i < MAP->rows; i++) {
		pos.x = ((LINES - MAP->rows) / 2) + i;
		pos.y = (COLS - MAP->cols) / 2;
		mvprintw(pos.x, pos.y, MAP->map[i]);
	}
}

int check_o_end(map_t *MAP)
{
	goal_t *temp = MAP->ghead;
	int res = 1;

	while (temp) {
		if (MAP->map[temp->pos.x][temp->pos.y] == 'X')
			res *= 1;
		else if (MAP->map[temp->pos.x][temp->pos.y] == 'P')
			res *= 0;
		else {
			res *= 0;
			MAP->map[temp->pos.x][temp->pos.y] = 'O';
		}
		temp = temp->next;
	}
	return (res);
}

int case_is_blocked(int x, int y, char **map)
{
	int sum = 0;

	for (int i = -1; i < 2; i += 2)
		if (map[x + i][y] == '#')
			sum++;
	for (int i = -1; i < 2; i += 2)
		if (map[x][y + i] == '#')
			sum++;
	if (sum > 2)
		return (1);
	if (sum < 2)
		return (0);
	if (map[x + 1][y] == map[x - 1][y])
		return (0);
	if (map[x][y + 1] == map[x][y - 1])
		return (0);
	return (1);
}

int check_x_end(map_t *MAP)
{
	case_t *temp = MAP->head;
	int res = 1;

	while (temp) {
		if (case_is_blocked(temp->pos.x, temp->pos.y, MAP->map))
			res *= 1;
		else {
			res *= 0;
			MAP->map[temp->pos.x][temp->pos.y] = 'X';
		}
		temp = temp->next;
	}
	return (res);
}

int game_loop(map_t *MAP)
{
	int ch = 0;
	int x_end = 0;
	int ch_end = 0;
	int o_end = 0;
	int ret = 0;

	while (!ch_end && !o_end && !x_end) {
		refresh();
		ch = getch();
		ch_end = ui_manager(ch, MAP);
		mvprintw(0, 0, "");
		o_end = check_o_end(MAP);
		x_end = check_x_end(MAP);
		clear();
		if (!check_window(MAP))
			display_map(MAP);
	}
	ret = (o_end == 1) ? 0 : 1;
	return (ret);
}