/*
** EPITECH PROJECT, 2017
** hexa
** File description:
** print hexadecimal & pointer adress
*/

#include "../include/my.h"

int longlen(unsigned long number)
{
	int count = 0;

	while (number != 0) {
		number = number / 10;
		count++;
	}
	return (count);
}

char *int_to_hexastr(unsigned long number, int len)
{
	char *res = malloc(sizeof(char) * (len + 1));
	int i = 0;

	if (number == 0)
		res[i] = 48;
	while (number != 0) {
		res[i] = number % 16 + 48;
		number = number / 16;
		if (res[i] > '9')
			res[i] = res[i] + 39;
		i++;
	}
	my_revstr(res);
	return (res);
}

void hexaprint(unsigned long number, char maj)
{
	int len = longlen(number);
	char *str = int_to_hexastr(number, len);

	if (maj == 'X')
		my_strupcase(str);
	my_putstr(str);
	free(str);
}
