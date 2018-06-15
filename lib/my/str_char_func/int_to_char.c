/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** display number
*/

#include "../include/my.h"

static int power_ten(int i)
{
	int p = 1;
	for (int e = 0 ; e < i ; e++) {
		p = p * 10;
	}
	return (p);
}

char *int_to_char(int nb)
{
	int an = 0;
	int p;
	int a;
	int j = 0;
	char *res = malloc(sizeof(char) * 5);

	if (nb < 0) {
		nb = nb * -1;
		res[j++] = '-';
	}
	for (int i = 9 ; i > -1 ; i--) {
		p = power_ten(i);
		a = nb / p;
		nb = nb - a * p;
		if ((a != 0) || (my_strlen(res) != 0) || (i == 0)) {
			res[j++] = (a + 48);
		}
	}
	res[j] = '\0';
	return (res);
}
