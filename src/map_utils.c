/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** a game like sokoban
*/

#include "my.h"
#include "soko.h"

int check_window(map_t *MAP)
{
	posi_t pos;

	if (LINES < MAP->rows || COLS < MAP->cols) {
		pos.x = LINES / 2;
		pos.y = (COLS - 26) / 2;
		mvprintw(pos.x, pos.y, "The windows is too small!");
		return (1);
	}
	return (0);
}

int my_open(char *pathname)
{
	int fd = 0;

	if (pathname == NULL)
		exit(84);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		exit(84);
	return (fd);
}

void gretter_test(int *cols, int i)
{
	if (*cols < i)
		*cols = i;
}

void map_len(char *pathname, int *res_col, int *res_row)
{
	int fd = my_open(pathname);
	char tmp[2];
	int cols = 0;
	int rows = 1;
	int i = 0;

	while (read(fd, tmp, 1) != 0) {
		if (tmp[0] == '\n') {
			rows++;
			gretter_test(&cols, i);
			i = 0;
		}
		i++;
	}
	close(fd);
	*res_col = cols;
	*res_row = rows;
}

void my_map(char *pathname, map_t *MAP)
{
	int fd = open(pathname, O_RDONLY);
	char tmp[2];
	int i = 0;
	int j = 0;

	map_len(pathname, &MAP->cols, &MAP->rows);
	MAP->map = alloc_2d(MAP->rows, MAP->cols);
	while (read(fd, tmp, 1) != 0) {
		MAP->map[i][j] = tmp[0];
		j++;
		if (tmp[0] == '\n') {
			MAP->map[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	MAP->map[i + 1] = NULL;
	close(fd);
}