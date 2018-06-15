/*
** EPITECH PROJECT, 2017
** hexa
** File description:
** print hexadecimal & pointer adress
*/

#include "../include/my.h"

char *int_to_octastr(unsigned long number, int len)
{
	char *res = malloc(sizeof(char) * (len * 2));
	int i = 0;

	if (number == 0)
		res[i] = 48;
	while (number != 0) {
		res[i] = number % 8 + 48;
		number = number / 8;
		i++;
	}
	while (i < len + 8)
		res[i++] = '\0';
	my_revstr(res);
	return (res);
}

void octaprint(unsigned long number)
{
	int len = longlen(number);
	char *str = int_to_octastr(number, len);

	my_putstr(str);
	free(str);
}
