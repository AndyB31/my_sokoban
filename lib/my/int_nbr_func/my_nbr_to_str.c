/*
** EPITECH PROJECT, 2018
** my_nbr_to_str
** File description:
** my_nbr_to_str
*/

#include "my.h"

static void init_tab(char *str, int size)
{
	for (int i = 0; i < size; i++) {
		str[i] = '\0';
	}
}

char *my_nbr_to_str(int nbr)
{
	int size = get_nb_size(nbr, 0) + 1;
	char *str = malloc((size + 1) * sizeof(char));
	int an = 0;
	int j = 0;
	int a = 0;

	init_tab(str, size + 1);
	if (nbr < 0) {
		nbr = nbr * -1;
		str[j++] = '-';
	}
	for (int i = size; i >= 0; i--) {
		a = nbr / my_compute_power_rec(10, i);
		nbr = nbr - a * my_compute_power_rec(10, i);
		if ((a != 0) || (an == 1) || (i == 0)) {
			an = 1;
			str[j++] = (a + 48);
		}
	}
	return (str);
}
