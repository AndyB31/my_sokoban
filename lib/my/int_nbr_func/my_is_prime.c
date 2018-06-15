/*
** EPITECH PROJECT, 2017
** my is prime
** File description:
** find if nbr is prime
*/

#include "../include/my.h"

int my_square(int nb)
{
	int root;
	int keep = nb;

	for (int i = 1; i <= nb / 2; i++) {
		if (i * i > 2147483647)
			return (0);
		if (nb == i * i)
			return (i);
		root = nb - i * i;
		if (root < 0)
			root = root * -1;
		if (root < keep) {
		keep = root;
		} else
			return (i);
	}
	return (0);
}

int my_is_prime(int nb)
{
	int result = 1;
	int square = my_square(nb);
	int i = 5;

	if ((nb % 2 == 0) || (nb <= 1) || (nb % 3 == 0)) {
		result = 0;
	}
	if ((nb == 2) || (nb == 3)) {
		result = 1;
	}
	while (( i <= square) && (result = 1)) {
		if ((nb % i == 0) || (nb % i + 2 == 0)) {
			result = 0;
		} else {
			i = i + 6;
		}
	}
	return (result);
}
