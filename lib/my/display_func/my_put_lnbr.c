/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** display number
*/

#include "../include/my.h"

long power_long(int i)
{
	long res = 1;

	for (int a = 0; a < i; a++) {
		res = res * 10;
	}
	return (res);
}

int my_put_lnbr(long nb)
{
	long an = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = -1 * nb;
	}
	for (int i = 19 ; i > -1 ; i--) {
		long p = power_long(i);
		long a = nb / p;
		nb = nb - a * p;
		if ((a != 0) || (an == 1) || (i == 0)) {
			an = 1;
			my_putchar(a + 48);
		}
	}
	return (0);
}
