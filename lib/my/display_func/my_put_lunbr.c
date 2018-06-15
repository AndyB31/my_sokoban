/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** display number
*/

#include "../include/my.h"

unsigned long power_longu(int i)
{
	unsigned long res = 1;

	for (int a = 0; a < i; a++) {
		res = res * 10;
	}
	return (res);
}

int my_put_lunbr(unsigned long nb)
{
	unsigned long an = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = -1 * nb;
	}
	for (int i = 19 ; i > -1 ; i--) {
		unsigned long p = power_longu(i);
		unsigned long a = nb / p;
		nb = nb - a * p;
		if ((a != 0) || (an == 1) || (i == 0)) {
			an = 1;
			my_putchar(a + 48);
		}
	}
	return (0);
}
