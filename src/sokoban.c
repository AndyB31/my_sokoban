/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** a game like sokoban
*/

#include "my.h"
#include "soko.h"

void *my_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
		exit (84);
	return (ptr);
}

map_t *init_map(void)
{
	map_t *MAP = (map_t *)my_malloc(sizeof(map_t));

	MAP->pathname = NULL;
	MAP->head = NULL;
	MAP->ghead = NULL;
	MAP->map = NULL;
	return (MAP);
}

int my_print_map(char *pathname)
{
	int ret = 0;
	map_t *MAP = init_map();

	MAP->pathname = pathname;
	my_map(pathname, MAP);
	my_obj(MAP);
	initscr();
	keypad(stdscr, TRUE);
	display_map(MAP);
	ret = game_loop(MAP);
	free_all(MAP);
	return (ret);
}

void print_help(char *name)
{
	my_printf("USAGE\n\t%s map\nDESCRIPTION\n\tmap\t", name);
	my_printf("file representing the warehouse map, containing");
	my_printf(" ‘#’ for walls,\n\t\t‘P’ for the player, ‘X’ for boxes");
	my_printf(" and ‘O’ for storage locations.\n");
	exit(0);
}

int main(int ac, char **av)
{
	int ret = 0;

	if (ac == 2) {
		if (my_strcmp(av[1], "-h") == 0)
			print_help(av[0]);
		ret = my_print_map(av[1]);
		endwin();
	} else {
		my_printf("error : %d parrameters but need 1\n", ac - 1);
		return (84);
	}
	return (ret);
}
