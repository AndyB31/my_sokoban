/*
** EPITECH PROJECT, 2017
** my get nbr
** File description:
** give number
*/

#include "../include/my.h"

int my_get_nbr(char const *str)
{
	int n = 0;
	int test = 0;
	int lock = 0;
	int neg = 1;
	int i = 0;

	while (i < my_strlen(str)) {
		if ((str[i] >= '0' && str[i] <= '9') && (lock == 0)) {
			n = n * 10;
			n = str[i] + n - 48;
			test = 1;
		} else if ((test == 1) && (str[i] != '-'))
			return (n * neg);
		if ((str[i] == '-') && (test == 0)) {
			neg = neg * -1;
			test = 1;
		}
		i++;
	}
	n = n * neg;
	return (n);
}
