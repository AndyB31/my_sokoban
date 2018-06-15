/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** display number
*/

#include "../include/my.h"

int my_put_unbr(unsigned int nb)
{
	unsigned int an = 0;
	for (int i = 9 ; i > -1 ; i--) {
		int p = power(i);
		unsigned int a = nb / p;
		nb = nb - a * p;
		if ((a != 0) || (an == 1) || (i == 0)) {
			an = 1;
			my_putchar(a + 48);
		}
	}
	return (0);
}
