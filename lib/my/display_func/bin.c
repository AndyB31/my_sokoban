/*
** EPITECH PROJECT, 2017
** hexa
** File description:
** print hexadecimal & pointer adress
*/

#include "../include/my.h"

char *int_to_binstr(unsigned long number, int len)
{
	char *res = malloc(sizeof(char) * (len * 4));
	int i = 0;

	if (number == 0)
		res[i] = 48;
	while (number != 0) {
		res[i] = number % 2 + 48;
		number = number / 2;
		i++;
	}
	while (i < len * 4)
		res[i++] = '\0';
	my_revstr(res);
	return (res);
}

void binprint(unsigned long number)
{
	int len = longlen(number);
	char *str = int_to_binstr(number, len);

	my_putstr(str);
	free(str);
}
