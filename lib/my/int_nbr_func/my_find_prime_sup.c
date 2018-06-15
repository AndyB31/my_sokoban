/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** find prime
*/

#include "../include/my.h"

int my_squarenbr(int nb)
{
	int root;
	int keep = nb;

	for (int i = 1 ; i <= nb / 2 ; i++) {
		if ((i * i) > 2147483647)
			return (0);
		if (nb == (i * i))
			return (i);
		root = nb - i*i;
		if (root < 0) {
			return (i);
		}
	}
	return (0);
}

int my_prime(int nb)
{
	int result = 1;
	int square = my_squarenbr(nb);
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

int my_find_prime_sup(int nb)
{
	int prime = my_prime(nb);

	if (prime == 1)
		return (nb);
	else
		my_find_prime_sup(nb + 1);
}
