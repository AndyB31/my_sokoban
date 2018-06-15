/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** display number
*/

#include "../include/my.h"

int power(int i)
{
	int p = 1;
	for (int e = 0 ; e < i ; e++) {
		p = p * 10;
	}
	return (p);
}

int my_put_nbr(int nb)
{
	int an = 0;
	int p;
	int a;

	if (nb < 0) {
		nb = nb * -1;
		my_putchar('-');
	}
	for (int i = 9 ; i > -1 ; i--) {
		p = power(i);
		a = nb / p;
		nb = nb - a * p;
		if ((a != 0) || (an == 1) || (i == 0)) {
			an = 1;
			my_putchar(a + 48);
		}
	}
	return (0);
}
